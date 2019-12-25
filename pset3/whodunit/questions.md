# Questions

## What's `stdint.h`?

stdint.h is the header file of a C library that is used to define bit lengths of integers used in the program, independent of the CPU on which the program is being run on. The header file gives a program increased portability, as stdint.h ensures that an integer's value remains the same in a program regardless of what kind of the CPU the program is running on, therefore allowing the program to run correctly on several different types of platforms.

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

A uint8_t is an unsigned 8-bit integer, a uint16_t is an unsigned 16-bit integer, a int32_t is a signed 32-bit integer, and a uint32_t is an unsigned 32-bit integer. These data types specify the width of the integers being used in the program, ensuring that the data type of an integer remains the same across different platforms. For example, due to differences in the byte-values of data types in different systems, a specific byte-width may be an intger in one system, but a long in another system; the data types mentioned above avoid such a problem, by maintaining the data type, regardless of the CPU, through specifying the bit-length of the integers.

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

Byte: 1
DWORD: 4
LONG: 4
WORD: 2

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

In hexadecimal, the first two bytes of any BMP file must be 0x4d and 0x42.

## What's the difference between `bfSize` and `biSize`?

bfSize defines the size, in bytes, of the bitmap file, whereas biSize defines the number of bytes required by the structure.

## What does it mean if `biHeight` is negative?

If biHeight is negative, the bitmap is top-down and its origin is the upper-left corner.

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

biBitCount

## Why might `fopen` return `NULL` in `copy.c`?

If the file is not found, fopen would return NULL.

## Why is the third argument to `fread` always `1` in our code?

The third argument is always 1, because is specifies that the program needs to read the input file one element at a time (block-by-block).

## What value does `copy.c` assign to `padding` if `bi.biWidth` is `3`?

3 (RGB_TRIPLE size) * 3(bi.biWidth) = 9 + 3 (padding) = 12 (multiple of 4)

Padding = 3

## What does `fseek` do?

The function fseek moves the program file position indicator to the value pointed at by the offset value inputed to the function.

## What is `SEEK_CUR`?
SEEK_CUR is an input for fseek that moves the file position indicator relative to the current position in the file.
