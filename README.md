
# Printf


Welcome to Printf! A personal reimplementation of the well-known `printf` function from the standard C library. If you're in need of a reliable and versatile printing function for your next C project, you're in the right spot!

📖 Contents
- [Features](#features)
- [Usage](#usage)
- [Requirements & Installation](#requirements--installation)
- [Contact & Support](#contact--support)

## 🚀 Features

- **Flexible Formatting**: Supports common format specifiers such as `%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X` and `%%`.
- **Consistent Output**: Ensures reliable and predictable results in line with the standard `printf` behavior.
- **Efficient Code**: Optimized for performance without sacrificing readability or expandability.

## 🔧 Usage

**Compilation**: 

1. First, compile the required libraries:

```bash
make
```

This will produce the necessary library files, including `libftprintf.a`.

2. Compile your program with the `ft_printf` function:

```bash
gcc your_file.c -o your_program_name -L. -lftprintf
```

**Include**:
Just include the `ft_printf.h` header in your C project:

```c
#include "ft_printf.h"
```

## 📦 Requirements & Installation

- GCC or another C compiler.
- `make` utility.
- Git (optional).

```bash
# Clone the repository
git clone https://github.com/Pablo-Palma/printf.git

# Navigate to the directory
cd printf

# Compile the library
make

# Compile your project with ft_printf
gcc your_project_file.c -o desired_output_name -L. -lftprintf
```

## 📞 Contact & Support

Any questions, suggestions, or potential contributions? Don't hesitate to reach out!

- **GitHub**: [Pablo-Palma](https://github.com/Pablo-Palma)
- **Email**: pablopalmappr@gmail.com

Happy coding! 👩‍💻👨‍💻
