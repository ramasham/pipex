# 🔗 Pipex - Recreating Shell Pipelines

### 📝 Project Overview
Pipex is a 42 project that recreates the behavior of shell pipelines (|). It takes input from a file, processes it through a series of commands, and outputs the result to another file, just like in a Unix shell!
In a Unix shell, a pipeline allows the output of one command to be used as input for another.

    For example:
    cat infile | grep "42" | wc -l > outfile

### ⚙️ How It Works:
    Pipex takes four or more arguments: <br>
        ./pipex infile "cmd1" "cmd2" outfile ➡️ < infile cmd1 | cmd2 > outfile <br>

### 🔁 Process Flow:
    1️⃣ Read input from `infile` <br>
    2️⃣ Execute `cmd1`, passing its output through a pipe <br>
    3️⃣ Execute `cmd2`, taking input from the first command's output <br>
    4️⃣ Write the final output to `outfile`

### ✏️ Diagram Representation:
    [ infile ] → [ cmd1 ] → [ pipe ] → [ cmd2 ] → [ outfile ]

### 🛠️ System Calls Used
    - pipe() → Creates a communication channel between processes
    - fork() → Spawns child processes to execute commands
    - dup2() → Redirects input and output for commands
    - execve() →  Replaces process with command execution
