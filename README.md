# MiniShell in C

## 📌 Project Overview

MiniShell is a command-line shell developed using C programming on Linux. The main purpose of this project is to understand how a shell receives user commands, identifies the type of command, and executes it using Linux system calls.

The project focuses on process creation, command execution, signal handling, and communication between processes. It is being developed step by step to understand how a basic Linux shell works internally.

## 🎯 Objectives

- Understand how a shell reads and processes user input.
- Learn process creation and execution using `fork()` and `execvp()`.
- Implement built-in commands and execute external Linux commands.
- Understand process synchronization using `waitpid()`.
- Explore signal handling, pipes, and input/output redirection.

## 🛠️ Technologies Used

- **Programming Language:** C
- **Operating System:** Linux
- **Compiler:** GCC
- **Concepts:** Linux system calls, process management, signals, file descriptors, and inter-process communication (IPC).

## ⚙️ Planned Features

- Customizable command prompt using `PS1`
- User input handling and command parsing
- Built-in commands such as `cd`, `pwd`, `echo`, and `exit`
- Execution of external Linux commands
- Process creation using `fork()` and `execvp()`
- Child process synchronization using `waitpid()`
- Signal handling for `SIGINT` and `SIGTSTP`
- Input and output redirection
- Pipe implementation
- Background process and job control

## 🚀 Compilation and Execution

Clone the repository:

```bash
git clone https://github.com/YOUR_USERNAME/MiniShell-Linux.git
```

Navigate to the project directory:

```bash
cd MiniShell-Linux
```

Compile the source code:

```bash
gcc minishell.c -o minishell
```

Run the program:

```bash
./minishell
```

Replace `YOUR_USERNAME` with your GitHub username.

## 📚 Key Learnings

- Understanding how Linux creates and executes processes.
- Learning how parent and child processes interact.
- Exploring the role of system calls in command execution.
- Understanding how signals control process behavior.
- Learning how pipes and file descriptors support inter-process communication.

## 👩‍💻 Author

**Roopa Sree Thoti**

This project is part of my learning journey in C programming and Linux system programming.
