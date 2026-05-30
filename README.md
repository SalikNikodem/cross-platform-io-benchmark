
# File I/O Benchmarking Project

C programming project designed to sequentially process and merge the contents of two input files into a single output file using different standard buffering methods from stdio.h. It provides an empirical performance analysis between standard ISO C functions and native Linux environment optimizations.

## Features

1. Three I/O Modes:
Mode 1 (Character): Copies data byte-by-byte using fgetc / fputc. 
Mode 2 (Line): Copies text data line-by-line using fgets / fputs.
Mode 3 (Block/Byte): Copies binary data in chunks using fread / fwrite.  

2. Argument Handling: Accepts either 3 or 4 arguments. If the 4th argument is missing, it defaults to saving the data in `data.log`.

3. Safe File Handling: Automatically creates the output file if it doesn't exist, or appends to it if it does, using `feof()` and `ferror()` for robust error detection.

4. Output Printing: After merging, the program safely rewinds and prints the contents of all files to standard output (stdout) without reopening file streams via fopen.

## Implementations

Cross-Platform Version (main.c): Written in strict ISO C99 standard for ultimate portability across Linux, macOS, and Windows. Uses static buffer boundaries (2048 bytes for line mode and 4096 bytes for block mode).

Linux-Optimized Version (main_linux.c): Leverages POSIX and GNU C library specific features. Dynamically sizes line buffers using the native kernel limit LINE_MAX from <limits.h> and minimizes resource management overhead via structural execution of fcloseall(). 

### Compilation:

```bash
# Linux-specific version
gcc -Wall main_linux.c -o program_linux

# Cross-platform version
gcc -Wall main_portable.c -o program_portable
```

## Automated Benchmarking

The project contains a benchmark.sh automated test suite shell script that runs a series of 10 sequential time measurements for each program mode. It isolates core disk I/O metrics by suppressing normal application output via standard stream redirection.

```bash
dd if=/dev/urandom of=big_file1.bin bs=1M count=50
dd if=/dev/urandom of=big_file2.bin bs=1M count=50
```
```bash
chmod +x benchmark.sh
./benchmark.sh program_linux 3
./benchmark.sh program_portable 3
```