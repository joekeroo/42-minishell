# 42-minishell

In this project, we will be creating a simple working version of bash. **No** thanks to this project, we'll be able to travel back in time and come back to problems people faced when `Windows` didn't exists.

## About

- The program will constantly read input from the user.
- Tokenizing and parsing input given by the user and executes them.
- These are what we have to handle in our `minishell`:

|   Requirements    |                           Description                           |
| :---------------: | :-------------------------------------------------------------: |
| A working history |           saves all previous inputs given by the user           |
|    Executables    | executes the right executables based on `PATH` using `execve()` |
|     Built-ins     |              `echo, pwd, export, unset, env, exit`              |
|   ENV Expansion   |                          `''` and `""`                          |
|   Redirections    |                         `<, <<, >, >>`                          |
|      Piping       |                              `\|`                               |
|      Signals      |                    `ctrl+D, ctrl+C, ctrl+\`                     |

## Installation & Usage

- GNU make (v3.81)
- GCC (v4.2.1)
- lib32readline8

### Building the program

1. Download/Clone this repository

```bash
git clone https://github.com/joekeroo/42-minishell.git minishell
```

2. `cd` into the root directory and run `make`

```bash
cd minishell && make
```

### Compilation

- `make` - compiles the program into `minishell`
- `make clean` - removes all `.o` files
- `make fclean` - clean and removes `minishell`
- `make re` - fclean and recompiles

### Run the Program

```bash
./minishell
```
