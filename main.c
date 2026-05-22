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

        
    char *mode = argv[1];
    char *in1_name = argv[2];
    char *in2_name = argv[3];
    char *out_name = (argc == 5) ? argv[4] : DEFAULT_OUTPUT;

    FILE *in1 = NULL;
    FILE *in2 = NULL;
    FILE *out = NULL;



    return EXIT_SUCCESS;
}