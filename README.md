# Minishell

*This project was created as part of the 42 curriculum by manmarqu, aluther-.*

## Description

Minishell is a simple shell implementation in C, inspired by bash. The goal of the project is to understand how shells work internally — process creation, file descriptor management, signal handling, and command parsing.

The shell supports:
- Interactive prompt with command history
- Command execution via `PATH`, relative and absolute paths
- Single and double quotes
- Environment variable expansion (`$VAR`, `$?`)
- Redirections: `<`, `>`, `>>`, `<<` (heredoc)
- Pipes `|`
- Signal handling: `Ctrl-C`, `Ctrl-D`, `Ctrl-\`
- Built-in commands: `echo`, `cd`, `pwd`, `export`, `unset`, `env`, `exit`

## Instructions

**Compile:**
```bash
make
```

**Run:**
```bash
./minishell
```

**Clean:**
```bash
make clean   # removes object files
make fclean  # removes object files and binary
make re      # full recompile
```

**Requirements:** `gcc`, `make`, `readline` library.

On Ubuntu/Debian:
```bash
sudo apt install libreadline-dev
```

## Resources

### Official documentation
- [Bash manual](https://www.gnu.org/software/bash/manual/bash.html)
- [Unix signals — signal(7)](https://man7.org/linux/man-pages/man7/signal.7.html)
- [fork(2) man page](https://man7.org/linux/man-pages/man2/fork.2.html)
- [execve(2) man page](https://man7.org/linux/man-pages/man2/execve.2.html)
- [pipe(2) man page](https://man7.org/linux/man-pages/man2/pipe.2.html)
- [waitpid(2) man page](https://man7.org/linux/man-pages/man2/waitpid.2.html)
- [readline documentation](https://tiswww.case.edu/php/chet/readline/rltop.html)
- [sigaction(2) man page](https://man7.org/linux/man-pages/man2/sigaction.2.html)

### Videos
- [pipe, fork, dup, exec explained](https://www.youtube.com/watch?v=pO1wuN3hJZ4) — how `cmd1 | cmd2` works under the hood
- [fork and execvp tutorial in C](https://www.youtube.com/watch?v=O1UOWScmqxg) — practical walkthrough of process creation

### Articles and guides
- [42 Minishell guide — Medium](https://medium.com/@laamirimarouane8/42-minishell-guide-53600f49742b) — comprehensive guide covering parsing, execution, signals and builtins
- [Building a mini-bash — Medium](https://m4nnb3ll.medium.com/minishell-building-a-mini-bash-a-42-project-b55a10598218) — 42 student walkthrough of the full project
- [Building a Shell in C: fork, pipes and file descriptors — Medium](https://meerthika.medium.com/building-a-shell-in-c-understanding-fork-pipes-and-file-descriptors-fc030ca7549d) — deep dive into execution internals
- [Fork, exec and process control — YoLinux](http://www.yolinux.com/TUTORIALS/ForkExecProcesses.html) — detailed reference on fork/exec/wait with examples
- [Writing a simple shell in C — linuxvox](https://linuxvox.com/blog/writing-a-simple-shell-in-c-using-fork-execvp/) — step by step tutorial

### AI usage
AI tools were used for verification and cross-checking of signal handling logic and data structure design. All code was written, reviewed and understood by the authors.
