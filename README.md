
# File I/O Benchmarking Project

C programming project that merges the contents of two input files into an output file using different standard functions from `stdio.h`. 

## Features

1. **Three I/O Modes:**
   - Character mode (`fgetc` / `fputc`)
   - Line mode (`fgets` / `fputs`)
   - Block/Byte mode (`fread` / `fwrite`)
2. **Argument Handling:** Accepts either 3 or 4 arguments. If the 4th argument is missing, it defaults to saving the data in `data.log`.
3. **Safe File Handling:** Automatically creates the output file if it doesn't exist, or appends to it if it does, using `feof()` and `ferror()` for robust error detection.

### Compilation:
```bash
# Linux-specific version
gcc -Wall main_linux.c -o program_linux

# Cross-platform version
gcc -Wall main_portable.c -o program_portable