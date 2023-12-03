# 42sh 🖥️

Welcome to  **42sh**.

A comprehensive project aimed at building a fully-functional UNIX shell.

This project takes a deep dive into shell environment management, command parsing, and execution.

## Language and Tools 🛠️

![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)

- **Language:** C
- **Compilation:** Via Makefile, including `re`, `clean`, and `fclean` rules.
- **Binary Name:** 42sh


## Project Overview 🔎

The `42sh` project challenges you to create a UNIX shell that not only covers fundamental functionalities but also extends to advanced features.

### Features

- Command parsing and execution with handling of spaces and tabs.
- Management of the `$PATH` and environment.
- Error handling and return value processing.
- Redirections: `<`, `>`, `<<`, `>>`.
- Pipes: `|`.
- Builtins: `cd`, `echo`, `exit`, `setenv`, `unsetenv`.
- Separators: `;`, `&&`, `||`.
- Inhibitors: `\`.
- Globbing: `*`, `?`, `[`, `]`.
- Job control: `&`, `fg`.
- Backticks: `` ` ``.
- Grouping commands with parentheses: `(`, `)`.
- Management of local and environmental variables.
- Special variables (e.g., `term`, `precmd`).
- Command history: `!`.
- Aliases and line editing features (multiline support, dynamic rebinding, auto-completion).
- Scripting capabilities.

### Usage Example

```
∼> ./42sh
42sh> cd ; </etc/hosts od -c | grep xx | wc >> /tmp/z -l ; cd - && echo “OK”
1
```

## Installation and Usage 💾

1. Clone the repository.
2. Compile the program using the provided Makefile.
3. Run the shell using: `./42sh`.
4. For detailed guidelines, refer to `42sh.pdf`.

## License ⚖️

This project is released under the MIT License. See `LICENSE` for more details.
