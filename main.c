#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if defined(__linux__)
    #include <limits.h>
    #define IS_LINUX 1
#else
    #define IS_LINUX 0
#endif

#define DEFAULT_OUTPUT "data.log"
#define BUFFER_SIZE_LINE 2048
#define BUFFER_SIZE_BLOCK 4096


int process_by_char(FILE *in_file, FILE *out_screen, FILE *out_file) {
    return EXIT_SUCCESS;
}


int process_by_line(FILE *in_file, FILE *out_screen, FILE *out_file) {
    return EXIT_SUCCESS;
}


int process_by_block(FILE *in_file, FILE *out_screen, FILE *out_file) {
    return EXIT_SUCCESS;
}


void print_output_file_content(const char *filename, FILE *out_file) {
}

int main(int argc, char *argv[]) {
    if (argc < 4 || argc > 5) {
            fprintf(stderr, "Błąd: Niepoprawna liczba argumentów!\n");
            return EXIT_FAILURE;
        }




    return EXIT_SUCCESS;
}