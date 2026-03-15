*This project has been created as part of the 42 curriculum by wihumeau*.

## Description

Pipex has two main goals:
*Learn how to executer a shell program inside a c program, using a child process.
*Learn how to use a pipe to transfert data from a first child process to a second child process of the same parent.

With bonuses you can go even further by implementing the code to execute as many shell programme as wished by the user connecting still connecting it with pipes.


## Instructions

Humoristicly the main goals of the project are not the hardest part

Basicly pipex is a C programm implemented to reproduce the behavior of the shell commande: 
[< file1 cmd1 | cmd2 > file2]

Meaning:
* reading in an infile, executing the shell cmd, using a pipe to connect to another cmd.
* reading in the pipe, executing the 2nd shell cmd, writing the final output in the outfile.
* returning the same exit code.
* No leaks, free and close everything.

Here is the basic test:
[./pipex file1 cmd1 cmd2 file2]
You also have some test implmented in the Makefile.

Valgrind flags: valgrind --leak-check=full --errors-for-leak-kinds=all


## Ressources

I been looking for man page and description of the differents autorised fonctions on Youtube and ohter wedsites. I have used claude IA to verify my understanding of the fonctions, and i have asked my peers about the project in general and their implementation choices.

* [Man pages website](http://manpagesfr.free.fr/man/man2/execve.2.html)
* [youtube pipex playlist](https://www.youtube.com/watch?v=QD9YKSg3wCc&list=PLK4FY1IoDcHG-jUt93Cl7n7XLQDZ0q7Tv)


## Choice

My pipex is strictly mandatory. I have done many version of that project so the parsing structures organistion and the execution course where not my first choice but it is know clearer, and will be easier to implement in the bonuses version for minnishell project.
I have two sturcture type, general data and the command related data. And i have chosen to do all redirections in the child process.