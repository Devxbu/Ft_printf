_This project has been created as part of the 42 curriculum by buranli._

# ft_printf

## Description

The goal of this project is to reimplement the standard C library function `printf`. `ft_printf` mimics the behavior of the original `printf` for a specific set of conversions. This project provides a deep understanding of variadic functions in C (`stdarg.h`) and structured output formatting.

It compiles into a static library `libftprintf.a`, which can be linked to other projects to use the `ft_printf` function.

Supported conversions:

- `%c`: Prints a single character.
- `%s`: Prints a string (as defined by the common C convention).
- `%p`: The `void *` pointer argument has to be printed in hexadecimal format.
- `%d`: Prints a decimal (base 10) number.
- `%i`: Prints an integer in base 10.
- `%u`: Prints an unsigned decimal (base 10) number.
- `%x`: Prints a number in hexadecimal (base 16) lowercase format.
- `%X`: Prints a number in hexadecimal (base 16) uppercase format.
- `%%`: Prints a percent sign.

## Instructions

### Compilation

To compile the library, run:

```bash
make
```

This will generate `libftprintf.a` at the root of the repository.

Other available Make commands:

- `make clean`: Removes object files.
- `make fclean`: Removes object files and the library.
- `make re`: Recompiles everything from scratch.

### Usage

1. Include the header in your C file:

   ```c
   #include "ft_printf.h"
   ```

2. Compile your code with the library:

   ```bash
   cc main.c libftprintf.a -o my_program
   ```

3. Run your program:
   ```bash
   ./my_program
   ```

## Resources

### References

- [C Library - <stdarg.h>](https://en.cppreference.com/w/c/variadic): Documentation for variable arguments handling.
- [printf man page](https://man7.org/linux/man-pages/man3/printf.3.html): Detailed behavior of the original function.

### AI Usage

AI assistance was used in this project for:

- **Understanding Variadic Functions**: AI explained the mechanism of `va_start`, `va_arg`, and `va_end` to correctly retrieve arguments from the stack.
- **Debugging Edge Cases**: AI helped identify potential issues with pointer printing (handling NULL pointers) and hexadecimal conversion logic.
- **Documentation**: AI assisted in structuring and drafting this README to meet specific formatting requirements.

## Algorithm and Data Structure

The implementation relies on a straightforward procedural algorithm without complex data structures, primarily utilizing the stack for argument passing via `stdarg.h`.

### Core Logic (Dispatcher)

The main function `ft_printf` iterates through the format string character by character.

1. **Normal Characters**: If the current character is not a `%`, it is written directly to the standard output using `write(1, ...)`, and the total character count is incremented.
2. **Format Specifiers**: If a `%` is encountered, the function inspects the _next_ character to determine the type of argument to retrieve. A dispatcher function `handle_format` is called.

### Variadic Argument Handling

The function uses `va_list` to access the variable arguments passed to the function.

- `va_start` initializes the list.
- `handle_format` calls `va_arg` with the appropriate type (e.g., `int` for `%d`, `char *` for `%s`, `unsigned int` for `%x`) to retrieve the next value from the stack. Note: `char` and `short` are promoted to `int` when passed through `...`.

### Helper Functions & Recursion

The valid output formatting is handled by specialized helper functions:

- `put_char`, `put_str`: Handle basic character and string output.
- `put_hex`, `put_signed`, `put_unsigned`: These functions use **recursion** to print numbers.
  - **Base Logic**: To print a number in any base (10 or 16), the function recursively calls itself with `n / base` until `n < base`, at which point it prints the digit (converting to ASCII). This ensures digits are printed in the correct order (most significant to least significant) without needing a temporary buffer.

### Return Value

The function maintains a running count (`total`) of all characters written to output. This `total` is returned at the end, complying with the standard `printf` return value behavior.
