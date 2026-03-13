# CHANGES

## 1. Project Structure Refactor

### Before (`nvpipex`)
- Main files were spread at root level:
- `main.c`, `pipex.h`, `parsing/`, `free/`, `exec/`, `ft_print/`

### After (`nvpipextim`)
- Code is organized by role:
- `src/` contains implementation files (`main`, `parsing`, `exec`, `utils`)
- `includes/` contains headers and local dependency headers (`pipex.h`, `ft_print/`)

### Why this is better
- Clearer separation between headers and implementation.
- Easier to navigate when the project grows.
- Helps maintain a clean architecture (sources vs interfaces).

## 2. Header Location and Content Updates

### Location change
- `pipex.h` moved from project root to `includes/pipex.h`.

### API/struct changes
- In `t_cmd`:
- `cmd` was renamed to `args`
- `fdinput` and `fdoutput` changed from `char` to `int`

### Why this is better
- `args` is clearer for future `execve` usage.
- File descriptors are integers in POSIX (`open`, `dup2`, `close`), so `int` is the correct type.

## 3. Parsing Uses the New Command Field

### What changed
- In parsing logic, assignments switched from:
- `pipex->cmdX.cmd`
- to:
- `pipex->cmdX.args`

### Why this is better
- Keeps the code aligned with the updated struct field names.
- Reduces confusion when connecting parsing to execution later.

## 4. Debug Output Is Now Centralized

### Before
- `main.c` printed each part of the struct manually with repeated loops.

### After
- Dedicated helper functions are used:
- `ft_arg_print`
- `ft_cmd_print`
- `ft_matrix_print`

### Why this is better
- Less duplicated code.
- Easier to change formatting in one place.
- `main.c` stays shorter and easier to read.

## 5. Utility Code Grouped in `src/utils`

### What changed
- `free.c` was moved into `src/utils/free.c`.
- `output.c` was added in `src/utils/output.c`.
- `utils.c` exists as a placeholder for future helpers.

### Why this is better
- Utility behavior is grouped together.
- Core logic files remain focused on parsing/execution flow.

## 6. Makefile Modernization

### What changed
- Source files are grouped by subdirectory variables.
- `addprefix` is used to compose full source paths.
- Object files are generated into `objs/`.
- Dependency files (`.d`) are auto-generated with `-MMD -MP`.
- `clean` removes `objs/`.
- `fclean` removes `objs/` and the final binary.

### Why this is better
- Build artifacts no longer pollute source directories.
- Header changes trigger proper incremental rebuilds.
- Cleanup behavior is predictable and complete.

## 7. Behavior Status (Current State)

### Implemented now
- Parsing and path lookup scaffolding are present.
- Debug inspection output is available.
- Build system is ready for incremental development.

### Still to complete
- Real execution pipeline behavior in `exec` (fork/pipe/dup2/execve/waitpid).
- Full error handling and memory/file-descriptor cleanup paths.

This transition is mostly a **codebase organization upgrade** plus a few **important type/field fixes**.
The project is now in a better state to continue implementing the real `pipex` execution flow safely and clearly.

## 8. `ft_printf` Adjustments Needed by `ft_matrix_print`

### Context
- In `nvpipextim`, debug output moved into helpers like `ft_matrix_print`.
- `ft_matrix_print` prints multiple values in one call:
- `ft_printf("[%s[%d] = %s]\n", type, i, matrix[i]);`

### What changed (vs `nvpipex`)
- `ft_specificator` now receives a pointer to the variadic state:
- from `int ft_specificator(char *s, va_list list, int i);`
- to `int ft_specificator(char *s, va_list *list, int i);`
- In `ft_printf`, call changed from `ft_specificator(s, list, i)` to `ft_specificator(s, &list, i)`.
- Inside `ft_specificator`, all reads became `va_arg(*list, ...)`.
- `va_end(list)` is now called before returning from `ft_printf`.

### Why we did this
- The parser in `ft_printf` must consume arguments from one shared `va_list` state, in the exact order of `%` specifiers.
- Passing `va_list` by value can be fragile depending on platform/ABI and can cause bad argument progression when several specifiers are used in one `ft_printf` call.
- Passing `va_list` by pointer guarantees `ft_specificator` advances the same state owned by `ft_printf`.
- This makes calls used by `ft_matrix_print` reliable (`%s`, `%d`, `%s` in one format string), and avoids mismatched outputs or undefined behavior.
- `va_end` was added to properly close the variadic handling lifecycle.

## BRAVOOOOO

T'as fait le plus gros au niveau du parsing.
Il va manquer l'initialisation du path pour tes commandes, potentiellement revoir ta fonction isolatepath pour éviter d'avoir 2 splits a l'intérieur.

Petite explication pour mon parsing :

	On utilise le machine state

	C'est le vrai fonctionnement de comment le shell traite les lignes qu'on lui donne en entrée . 
	Plutot que de diviser mot par mot en fonction de séparateur, il va traiter la ligne caractere par caractere en fonction de l'état dans lequel il est, et qui sera lui meme défini par les caracteres qui le font changer d'état comme les espaces, " ou ', pour savoir quand s'arrete et quand commence le nouveau "mot".

	Par exemple : 
		ec"ho" coucou est considéré comme : echo coucou

	C'est un peu la les limites d'utiliser split. Certains utilisent un split modifié avec des flags, mais pour comprendre la suite du fonctionnement du shell ca devient plus hard. Dans tous les cas, et c'est ce que m'ont dit certaines personnes quand je les corrigeais, te prends pas la tete a faire un parsing parfait pour pipex, la vraie valeur du projet est sur comprendre l'exécution via les redirections ( |, < ou > ) et les forks

Comme dit aussi j'ai du changer ton printf pour gérer certains cas ou j'imprimais plusieurs variables dans le meme ft_printf(), je n'ai pas revu ce que donne la norme dessus par contre donc attention a ca. J'ai l'impression que les pointeurs et leur utilisation ont encore quelques petits secrets a te partager. 

L'exec reste a faire mais pour le moment ca me parait good. Encore une fois si t'as des galeres ou que t'as des questions, hésite pas. CA VA LE FAIRE 💪
