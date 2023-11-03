# 0x16. C - Simple Shell

## This is a group project which aims in creating a simple shell

## Auth: @vicksonian & @CharityZawadi

# Resources

### Read or watch:

 -  Unix shell
 -  Thompson shell
 -  Ken Thompson 

# Requirements
## General

    Allowed editors: vi, vim, emacs
    All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89
    All your files should end with a new line
    A README.md file, at the root of the folder of the project is mandatory
    Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
    Your shell should not have any memory leaks
    No more than 5 functions per file
    All your header files should be include guarded
    Use system calls only when you need to (why?)
    Write a README with the description of your project
    You should have an AUTHORS file at the root of your repository, listing all individuals having contributed content to the repository. Format, see Docker

# More Info
## Output

    Unless specified otherwise, your program must have the exact same output as sh (/bin/sh) as well as the exact same error output.
    The only difference is when you print an error, the name of the program must be equivalent to your argv[0] (See below)

### Example of error with sh:

$ echo "qwerty" | /bin/sh
/bin/sh: 1: qwerty: not found
$ echo "qwerty" | /bin/../bin/sh
/bin/../bin/sh: 1: qwerty: not found
$

### Same error with your program hsh:

$ echo "qwerty" | ./hsh
./hsh: 1: qwerty: not found
$ echo "qwerty" | ./././hsh
./././hsh: 1: qwerty: not found
$

### List of allowed functions and system calls

- [x]    access (man 2 access)
- [x]    chdir (man 2 chdir)
- [x]    close (man 2 close)
- [x]    closedir (man 3 closedir)
- [x]    execve (man 2 execve)
- [x]    exit (man 3 exit)
- [x]    _exit (man 2 _exit)
- [x]    fflush (man 3 fflush)
- [x]    fork (man 2 fork)
- [x]    free (man 3 free)
- [x]    getcwd (man 3 getcwd)
- [x]    getline (man 3 getline)
- [x]    getpid (man 2 getpid)
- [x]    isatty (man 3 isatty)
- [x]    kill (man 2 kill)
- [x]    malloc (man 3 malloc)
- [x]    open (man 2 open)
- [x]    opendir (man 3 opendir)
- [x]    perror (man 3 perror)
- [x]    read (man 2 read)
- [x]    readdir (man 3 readdir)
- [x]    signal (man 2 signal)
- [x]    stat (__xstat) (man 2 stat)
- [x]    lstat (__lxstat) (man 2 lstat)
- [x]    fstat (__fxstat) (man 2 fstat)
- [x]    strtok (man 3 strtok)
- [x]    wait (man 2 wait)
- [x]    waitpid (man 2 waitpid)
- [x]    wait3 (man 2 wait3)
- [x]    wait4 (man 2 wait4)
- [x]    write (man 2 write)

#### Compilation

Your shell will be compiled this way:

##### gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

### Testing

Your shell should work like this in interactive mode:

$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$

But also in non-interactive mode:

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

### Checks

The Checker will be released at the end of the project (1-2 days before the deadline). We strongly encourage the entire class to work together to create a suite of checks covering both regular tests and edge cases for each task. See task 8. Test suite.
