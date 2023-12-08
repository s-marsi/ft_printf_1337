
# <span style="color: red;">FT_PRINTF</span>(1337)

## Table of Contents
- [Subject](#subject)
- [Description](#description)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Installation](#installation)
- [Usage](#usage)

## Subject :

- <a href="https://cdn.intra.42.fr/pdf/pdf/106616/en.subject.pdf" target="_blank" style="color: red; font-size: 15.5px; font-weight: 300; margin-left: 10px;"> subject.pdf </a>


## Description :
- Welcome to my printf project! This GitHub repository features my custom printf function in C, designed for easy formatting and printing of various data types. Dive into the code to explore format specifiers like %d, %s, %c, and more.
    

## Getting Started
### Prerequisites
- To use this library, you need a C compiler (e.g., GCC) and the make utility installed on your system.

### Installation
1. Clone the repository:
    ```bash
    https://github.com/s-marsi/ft_printf.git  ft_printf
    cd ft_printf
    ```
2. Compile the library:
    ```bash
    make all        # This will generate the libftprintf.a library file.
    make clean      # This will remove object files.
    ```
## Usage :
- To use the libftprintf library in your C project, include the header file in your source code and link against the compiled library.</li>
  ```bash
  #include "ft_printf.h"</li>
   ```
- Compile your program with the libft.a library:
  ```bash
  cc main.c libftprintf.a
   ```
