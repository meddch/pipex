# Pipex

![Pipex Logo](pipex-logo.png)

Pipex is a 42 project that aims to replicate the functionality of the shell command pipeline (`|`) by implementing a simple version of it in C. The program takes in two file names and two shell commands as arguments and performs the same operations as the pipeline, redirecting the output of the first command as input to the second command.

## How to Use Pipex

To compile the Pipex program, run the following command:

```
make
```

This will generate an executable named `pipex`.

To execute Pipex, use the following syntax:

```
./pipex file1 cmd1 cmd2 file2
```

- `file1` is the input file to be used as input to `cmd1`.
- `cmd1` is the first shell command to be executed.
- `cmd2` is the second shell command to be executed.
- `file2` is the output file where the final result will be written.

Here's an example usage of Pipex:

```
./pipex infile "ls -l" "grep pipex" outfile
```

This will execute the command `ls -l` on the input file `infile`, and then execute `grep pipex` on the output of the previous command. The final result will be written to the output file `outfile`.

## How Pipex Works

Pipex works by creating two child processes, each responsible for executing one of the shell commands. The output of the first command is redirected to the input of the second command using pipes. The parent process handles the file redirection and waits for the child processes to finish.

Here's a high-level overview of the steps performed by Pipex:

1. Parse the command line arguments and validate them.
2. Create two pipes, one for communication between the first command and the parent process, and another for communication between the two commands.
3. Fork the first child process (`cmd1`) and set up the necessary file redirections.
4. In the parent process, fork the second child process (`cmd2`) and set up the necessary file redirections.
5. Close unnecessary pipe ends in the parent and child processes.
6. Execute the commands in the child processes using `execve`.
7. Wait for both child processes to finish.
8. Cleanup resources and exit.

## Learning Objectives

The Pipex project provides an opportunity to learn and practice various concepts, including:

- Process creation and management using `fork` and `execve`.
- File I/O redirection using `dup2`.
- Inter-process communication using pipes.
- Error handling and validation of command line arguments.
- Memory management and resource cleanup.

## Resources

Here are some resources that can be helpful for completing the Pipex project:

- [Unix Pipes](https://en.wikipedia.org/wiki/Pipeline_(Unix))
- [Forking](https://www.geeksforgeeks.org/fork-system-call/)
- [Execve](https://man7.org/linux/man-pages/man2/execve.2.html)
- [File I/O Redirection](https://www.geeksforgeeks.org/input-output-redirection-c/)
- [UNIX File Descriptors](https://www.geeksforgeeks.org/file-descriptor-in-unix/)
- [Processes and Pipes in C](https://www.geeksforgeeks.org/pipe-system-call/)

Good luck with your Pipex project! Happy coding!
