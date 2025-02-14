# 🖨️ ft_printf – printf implementation

This version of `ft_printf` extends the basic implementation by supporting additional formatting flags.

## 🚀 Features
- Supports `%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X`
- Bonus: Handles flags `-`, `0`, `(space)`, `#`, `.`, `+`
- Implements variable argument handling with `stdarg.h`

## 🛠 Installation & Compilation

Compile the library:

```sh
make
```

This will generate libftprintf.a, a static library that can be used in your C projects.

To compile a C file using libftprintf.a, use:
```c
gcc your_file.c -L. -lftprintf -o your_program
```
Or explicitly link:
```c
gcc your_file.c libftprintf.a -I./ -o your_program
```

## 📜 Usage Example
```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Number: %+d | Hex: %#x | Width: %10s\n", 42, 255, "Text");
    return 0;
}
```

## 🏆 Learning Outcomes
✅ Understanding width, precision, and padding

✅ Implementing format flag logic

✅ Mastering formatted output in C
