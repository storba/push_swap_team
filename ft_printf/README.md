*This project has been created as part of the 42 curriculum by svpanfil.*

# ft_printf

## Description

`ft_printf` is a C library that reimplements the standard `printf` function from scratch, without using any formatted output functions from the standard library. The goal is to deeply understand variadic functions, type-safe argument handling, and number-to-string conversion algorithms.

The library is compiled into a static archive (`libftprintf.a`) that can be linked against any C project as a drop-in replacement for `printf`. It parses a format string character by character, dispatches each `%` conversion specifier to a dedicated handler, and returns the total number of characters written — exactly as the real `printf` does.

### Supported conversions

| Specifier | Output |
|-----------|--------|
| `%c`      | Single character |
| `%s`      | String (prints `(null)` for NULL pointers) |
| `%d`      | Signed decimal integer |
| `%i`      | Signed decimal integer (identical to `%d`) |
| `%u`      | Unsigned decimal integer |
| `%x`      | Unsigned hexadecimal integer — lowercase |
| `%X`      | Unsigned hexadecimal integer — uppercase |
| `%p`      | Pointer address in `0x…` notation (prints `(nil)` for NULL) |
| `%%`      | Literal percent sign |

---

## Instructions

### Requirements

- A C compiler: `cc` (clang or gcc)
- GNU `make`
- POSIX-compatible system (Linux or macOS)

### Compilation

Clone the repository and run `make` at the root:

```bash
git clone <repo-url> ft_printf
cd ft_printf
make
```

This produces the static library `libftprintf.a` in the current directory.

### Linking against your project

Copy or symlink `libftprintf.a` and `ft_printf.h` into your project, then compile with:

```bash
cc -Wall -Wextra -Werror your_file.c libftprintf.a -o your_program
```

Include the header in your source:

```c
#include "ft_printf.h"
```

### Makefile targets

| Target   | Effect |
|----------|--------|
| `make` / `make all` | Build `libftprintf.a` |
| `make clean`        | Remove object files (`.o`) |
| `make fclean`       | Remove object files and `libftprintf.a` |
| `make re`           | Full rebuild (`fclean` + `all`) |

---

## Usage Examples

```c
#include "ft_printf.h"

int main(void)
{
    int n = -42;
    unsigned int u = 255;
    char *s = "hello";
    int *p = &n;

    ft_printf("char:    %c\n", 'A');
    ft_printf("string:  %s\n", s);
    ft_printf("int:     %d\n", n);
    ft_printf("uint:    %u\n", u);
    ft_printf("hex low: %x\n", u);   // ff
    ft_printf("hex upp: %X\n", u);   // FF
    ft_printf("pointer: %p\n", p);   // 0x…
    ft_printf("percent: 100%%\n");
    return (0);
}
```

---

## Algorithm and Data Structure

### Format string parsing

`ft_printf` walks the format string one byte at a time using a `while (*str)` loop. Regular characters are written directly to stdout via `write(1, str, 1)`. When a `%` is encountered, the pointer advances by one and the next character is passed to `ft_switch`, a static dispatcher that maps it to the correct handler. The design is intentionally flat: no lookup tables, no state machine beyond the single `%` check — keeping the control flow simple and auditable.

### Variadic arguments — `va_list`

All type-polymorphism is handled with the C standard `<stdarg.h>` mechanism. A single `va_list` is opened at the start of `ft_printf`, passed **by pointer** to every handler so that `va_arg` advances the same internal cursor throughout the call, and closed with `va_end` before returning. Passing `va_list *` (rather than copying it by value) is essential: it ensures that consuming one argument correctly moves the cursor forward for all subsequent arguments.

### Recursive base conversion — `ft_putnbr_base`

All numeric output is ultimately routed through one function:

```c
void ft_putnbr_base(unsigned long n, char *base, int base_count, int *count);
```

The algorithm is a **tail-recursive digit extraction**:

1. If `n >= base_count`, recurse with `n / base_count` (most-significant digits first).
2. On the way back up the call stack, emit `base[n % base_count]`.

This naturally produces digits in the correct most-significant-to-least-significant order without requiring a temporary buffer or reversal step. The same function handles decimal (`base_count = 10`), lowercase hex (`"0123456789abcdef"`, `base_count = 16`), uppercase hex (`"0123456789ABCDEF"`), and pointer addresses (`unsigned long`, base 16), eliminating code duplication across all numeric types.

### Return value — output character count

Every handler receives a `int *count` pointer and increments it by the return value of each `write` call. `ft_printf` returns this accumulated count, matching the POSIX contract. If an unrecognised specifier is encountered, `count` is set to `-1` and the function returns `-1`, signalling an error to the caller.

### Signed integer handling

Negative integers are handled by extracting the absolute value as an `unsigned int` (avoiding undefined behaviour with `INT_MIN`), writing a `"-"` prefix, and then passing the unsigned value through the same recursive path used for positive numbers.

---

## Resources

### References

- [C Standard — `printf` specification (cppreference.com)](https://en.cppreference.com/w/c/io/fprintf)
- [Linux `man 3 printf`](https://man7.org/linux/man-pages/man3/printf.3.html)
- [GNU libc manual — Formatted Output](https://www.gnu.org/software/libc/manual/html_node/Formatted-Output.html)
- [C Standard — `<stdarg.h>` variadic functions](https://en.cppreference.com/w/c/variadic)
- [The C Programming Language — Kernighan & Ritchie, 2nd ed., §7.3 (Variable-Length Argument Lists)](https://www.goodreads.com/book/show/515601.The_C_Programming_Language)
- [42 project subject — ft_printf]

### AI usage

AI (Cursor / Claude) was used during this project in the following ways:

- **Documentation and README** — generating and structuring this README, including the algorithm explanation section.
- **Debugging** — asking targeted questions about edge cases (e.g. `INT_MIN` handling, NULL pointer behaviour for `%s` and `%p`) and understanding why passing `va_list` by pointer is necessary.
- **Code review** — checking whether the recursive `ft_putnbr_base` approach correctly handles `n = 0` and all base sizes.

AI was **not** used to write the actual implementation source files; all C code was written by hand to meet the learning objectives of the project.
