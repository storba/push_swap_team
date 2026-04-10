*This project has been created as part of the 42 curriculum by svpanfil <svpanfil@student.codam.nl>* 

---

## Description

**libft** is the first project of the 42/Codam curriculum. The goal is to build a personal C library from scratch, re-implementing a selection of standard C library functions along with additional utility functions that will be reused throughout future projects.

The library covers four main areas:

- **Character checks & conversions** — `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`, `ft_toupper`, `ft_tolower`
- **Memory manipulation** — `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`, `ft_calloc`
- **String manipulation** — `ft_strlen`, `ft_strlcpy`, `ft_strlcat`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr`, `ft_strdup`, `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`, `ft_strmapi`, `ft_striteri`
- **Conversions & output** — `ft_atoi`, `ft_itoa`, `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`
- **Linked list utilities** — `ft_lstnew`, `ft_lstadd_front`, `ft_lstadd_back`, `ft_lstsize`, `ft_lstlast`, `ft_lstdelone`, `ft_lstclear`, `ft_lstiter`, `ft_lstmap`

### Function reference

| Function | Signature | Description |
|---|---|---|
| `ft_isalpha` | `int ft_isalpha(int c)` | Returns non-zero if `c` is an alphabetic character |
| `ft_isdigit` | `int ft_isdigit(int c)` | Returns non-zero if `c` is a decimal digit |
| `ft_isalnum` | `int ft_isalnum(int c)` | Returns non-zero if `c` is alphanumeric |
| `ft_isascii` | `int ft_isascii(int c)` | Returns non-zero if `c` is a 7-bit ASCII character |
| `ft_isprint` | `int ft_isprint(int c)` | Returns non-zero if `c` is a printable character |
| `ft_toupper` | `int ft_toupper(int c)` | Converts a lowercase letter to uppercase |
| `ft_tolower` | `int ft_tolower(int c)` | Converts an uppercase letter to lowercase |
| `ft_strlen` | `size_t ft_strlen(const char *s)` | Returns the length of the string `s` |
| `ft_memset` | `void *ft_memset(void *b, int c, size_t len)` | Fills `len` bytes of `b` with byte value `c` |
| `ft_bzero` | `void ft_bzero(void *s, size_t n)` | Writes `n` zero bytes to `s` |
| `ft_memcpy` | `void *ft_memcpy(void *dst, const void *src, size_t n)` | Copies `n` bytes from `src` to `dst` (no overlap) |
| `ft_memmove` | `void *ft_memmove(void *dst, const void *src, size_t len)` | Copies `len` bytes from `src` to `dst` (overlap-safe) |
| `ft_memchr` | `void *ft_memchr(const void *s, int c, size_t n)` | Locates first occurrence of `c` in the first `n` bytes of `s` |
| `ft_memcmp` | `int ft_memcmp(const void *s1, const void *s2, size_t n)` | Compares first `n` bytes of `s1` and `s2` |
| `ft_calloc` | `void *ft_calloc(size_t count, size_t size)` | Allocates zero-initialized memory for `count` elements |
| `ft_strlcpy` | `size_t ft_strlcpy(char *dst, const char *src, size_t size)` | Size-bounded string copy; NUL-terminates result |
| `ft_strlcat` | `size_t ft_strlcat(char *dst, const char *src, size_t size)` | Size-bounded string concatenation; NUL-terminates result |
| `ft_strchr` | `char *ft_strchr(const char *s, int c)` | Locates first occurrence of `c` in `s` |
| `ft_strrchr` | `char *ft_strrchr(const char *s, int c)` | Locates last occurrence of `c` in `s` |
| `ft_strncmp` | `int ft_strncmp(const char *s1, const char *s2, size_t n)` | Compares up to `n` bytes of two strings |
| `ft_strnstr` | `char *ft_strnstr(const char *haystack, const char *needle, size_t len)` | Locates `needle` in `haystack` within `len` bytes |
| `ft_strdup` | `char *ft_strdup(const char *s1)` | Returns a malloc'd copy of `s1` |
| `ft_substr` | `char *ft_substr(char const *s, unsigned int start, size_t len)` | Allocates a substring of `s` starting at `start` with max length `len` |
| `ft_strjoin` | `char *ft_strjoin(char const *s1, char const *s2)` | Allocates a new string that is the concatenation of `s1` and `s2` |
| `ft_strtrim` | `char *ft_strtrim(char const *s1, char const *set)` | Allocates a copy of `s1` with leading/trailing characters in `set` removed |
| `ft_split` | `char **ft_split(char const *s, char c)` | Splits `s` by delimiter `c` into a NULL-terminated array of strings |
| `ft_strmapi` | `char *ft_strmapi(char const *s, char (*f)(unsigned int, char))` | Applies `f` to each character of `s` and returns the resulting string |
| `ft_striteri` | `void ft_striteri(char *s, void (*f)(unsigned int, char*))` | Applies `f` to each character of `s` in-place, passing the index |
| `ft_atoi` | `int ft_atoi(const char *str)` | Converts the initial portion of `str` to an `int` |
| `ft_itoa` | `char *ft_itoa(int n)` | Allocates a string representation of integer `n` |
| `ft_putchar_fd` | `void ft_putchar_fd(char c, int fd)` | Writes character `c` to file descriptor `fd` |
| `ft_putstr_fd` | `void ft_putstr_fd(char *s, int fd)` | Writes string `s` to file descriptor `fd` |
| `ft_putendl_fd` | `void ft_putendl_fd(char *s, int fd)` | Writes string `s` followed by a newline to `fd` |
| `ft_putnbr_fd` | `void ft_putnbr_fd(int n, int fd)` | Writes integer `n` to file descriptor `fd` |
| `ft_lstnew` | `t_list *ft_lstnew(void *content)` | Allocates and returns a new list node |
| `ft_lstadd_front` | `void ft_lstadd_front(t_list **lst, t_list *new)` | Adds `new` at the beginning of the list |
| `ft_lstadd_back` | `void ft_lstadd_back(t_list **lst, t_list *new)` | Adds `new` at the end of the list |
| `ft_lstsize` | `int ft_lstsize(t_list *lst)` | Returns the number of nodes in the list |
| `ft_lstlast` | `t_list *ft_lstlast(t_list *lst)` | Returns the last node of the list |
| `ft_lstdelone` | `void ft_lstdelone(t_list *lst, void (*del)(void *))` | Frees a single node using `del` on its content |
| `ft_lstclear` | `void ft_lstclear(t_list **lst, void (*del)(void *))` | Deletes and frees the entire list |
| `ft_lstiter` | `void ft_lstiter(t_list *lst, void (*f)(void *))` | Iterates the list and applies `f` to each node's content |
| `ft_lstmap` | `t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))` | Creates a new list by applying `f` to each node's content |

---

## Instructions

### Compilation

```bash
# Build the static library (libft.a)
make

# Remove object files
make clean

# Remove object files and the library
make fclean

# Rebuild from scratch
make re
```

### Using the library in your project

```bash
# Compile your project and link against libft
cc -Wall -Wextra -Werror main.c -L. -lft -o my_program
```

Include the header in your source files:

```c
#include "libft.h"
```

---

## Resources

### Documentation & references

- [C Standard Library reference — cppreference.com](https://en.cppreference.com/w/c)
- [The C Programming Language (K&R)](https://en.wikipedia.org/wiki/The_C_Programming_Language)
- [man pages online — Linux man-pages project](https://man7.org/linux/man-pages/)
- [42 Norm — coding standard enforced throughout the curriculum](https://github.com/42School/norminette)

### AI usage

AI (Claude via Cursor) was used during this project for:

- **README authoring** — generating and formatting the README structure to meet the 42 curriculum requirements.
- **Debugging assistance** — asking questions about edge-case behaviour (e.g. `ft_strlcat` return value when `dst` is longer than `size`, `ft_memmove` overlap semantics).
- **Understanding concepts** — clarifying how certain libc functions behave according to their man pages.

No AI was used to write or generate any `.c` source file or the `libft.h` header.
