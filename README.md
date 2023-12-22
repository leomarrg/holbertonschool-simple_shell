Simple Shell
This is a simple shell implementation in C that provides a basic command-line interface, allowing users to execute commands.

Compilation
Compile the simple shell using the following command:

bash
Copy code
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
Testing
Interactive Mode
Run the compiled shell in interactive mode:

bash
Copy code
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
Non-Interactive Mode
Run the shell in non-interactive mode by providing commands through pipes or input redirection:

bash
Copy code
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
File Structure
simple_shell.c: Main program that handles user input and command execution.
exeCmd.c: Function for executing commands.
functions.c: Utility functions, including signal handling and prompt display.
runExe.c: Function for handling the execution of commands using execve.
shell.h: Header file containing function declarations and necessary includes.
Contributing
Contributions are welcome! Feel free to open issues and pull requests to enhance the functionality of the simple shell.

License
This project is licensed under the MIT License - see the LICENSE file for details.
