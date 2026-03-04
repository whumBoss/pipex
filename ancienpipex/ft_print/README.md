*This project has been created as part of the 42 curriculum by wihumeau*.

## Description

The purpuse of this project is to code a duplicate of the fonction printf named ft_printf. Fonction which is commonly used in c programming, allowing programs to easely write/print characters, digits and most kind of variables.


## Instructions

* ft_printf required prototype is:
`int		ft_printf(const char *, ...);`

* The original printf uses `%` combined with a character as flags; to identify the type variable that has to be writen. So my duplicated should be implemented with the same flags `cspdiuxX%`. And it should have the same writen result.

* Printf also has a return value. The number of characters writen. If printf does it, so does ft_printf!
The only exception my fonction doesn't have to reproduce is the buffer management.

* The makefile should compile libftprintf.a using `ar` command, at the root of the git repository. 


## Ressources

To understand the fonction before coding, i would usely sollicit my peers. However i have be using AI and web ressources to learn about hexadecimal and convert it.

* [Bases convert](https://wims.univ-cotedazur.fr/wims/fr_tool~number~baseconv.fr.html)  to convert decimal in hexa and vice-versa.
* [NotebookLM](https://notebooklm.google/) to generate audio course and explanations about hexadecimal and why is it usufull in progamming.


## Choice

Concerning my choice of implementation for this project, i went with common variables fonctions because this is the solution i was the most familiar with. But this project could aslo be done with linked list.