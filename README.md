📖 About

Pipex is a project from the 42 Core Curriculum designed to strengthen your understanding of:

Processes

Pipes

File descriptors

Input/Output redirections

Command execution using execve

The goal is to reproduce the behavior of the shell command:

< file1 cmd1 | cmd2 > file2

🛠️ Features

✅ Executes two commands in sequence
✅ Uses pipes to transfer data between processes
✅ Handles input and output redirections
✅ Error management for commands, files, and paths
✅ Clean and modular C code structure

⚙️ How It Works

For the following command:

< file1 cmd1 | cmd2 > file2


Open file1 and redirect it to cmd1's stdin

Create a pipe to connect cmd1's output to cmd2's input

Execute cmd1 in a child process using execve()

Execute cmd2 in another child process

Redirect final output to file2

All of this is done using C system calls like fork(), pipe(), dup2(), and execve().

🚀 Usage
1️⃣ Compile
make

2️⃣ Run
./pipex file1 "cmd1" "cmd2" file2


Example:

./pipex infile "ls -l" "wc -l" outfile


Equivalent to:

< infile ls -l | wc -l > outfile

📚 Allowed Functions

open, close, read, write

malloc, free, perror, strerror

access, dup, dup2, execve

fork, pipe, wait, waitpid

exit
