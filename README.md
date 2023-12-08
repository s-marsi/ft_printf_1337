# <span style="font-size: 50px;font-weight: 600; color: red;margin-left: 42%;"> PRINTF</span>

## Table of Contents
- [Subject](#subject)
- [Description](#description)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Installation](#installation)
- [Usage](#usage)

## Subject :
<ol style="margin-left: 15px;">
  <li style="font-size: 20px; font-weight: 600; color: red;">
     <a href="https://cdn.intra.42.fr/pdf/pdf/106616/en.subject.pdf" target="_blank" style="color: red; font-size: 15.5px; font-weight: 300; margin-left: 10px;"> subject.pdf </a>
  </li>
</ol>

## Description :
- Welcome to my printf project! This GitHub repository features my custom printf function in C, designed for easy formatting and printing of various data types. Dive into the code to explore format specifiers like %d, %s, %c, and more.
    

## Getting Started
### Prerequisites
- To use this project, you need a C compiler (e.g., GCC) and the make utility installed on your system.

### Installation
1. Clone the repository:
    ```bash
    git clone https://github.com/s-marsi/ft_printf.git ft_printf.c
    cd ft_printf.c
    ```
2. Compile the library:
    ```bash
    make all  # This will generate the libftprintf.a library file.
    make clean      # This will remove object files.
    ```

<ol style="margin-left: 15px;">
  <li style="font-size: 20px; font-weight: 600;">
    Usage :
    <ul>
      <li>To use the libftprint library in your C project, include the header file in your source code and link against the compiled library.</li>
      <li>#include "ft_printf.h"</li>
      <li>Compile your program with the libftprint.a library:</li>
      <li>
        <code>
          cc main.c libftprint.a
        </code>
      </li>
    </ul>
  </li>
</ol>
