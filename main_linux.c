#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define DEFAULT_OUTPUT "data.log"
#define BUFFER_SIZE_BLOCK 4096
#define BUFFER_SIZE_LINE 8192


int process_by_char(FILE *in_file, FILE *out_file);
int process_by_line(FILE *in_file, FILE *out_file);
int process_by_block(FILE *in_file, FILE *out_file);
void print_output_file_content(const char *filename, FILE *out_file);

int main(int argc, char *argv[]) {
    if (argc < 4 || argc > 5) {
        fprintf(stderr, "Błąd: Niepoprawna liczba argumentów!\n");
        fprintf(stderr, "Użycie: %s <mode> <in1> <in2> [out]\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *mode = argv[1];
    char *in1_name = argv[2];
    char *in2_name = argv[3];
    char *out_name = (argc == 5) ? argv[4] : DEFAULT_OUTPUT;

    FILE *in1 = NULL, *in2 = NULL, *out = NULL;

    if (strcmp(mode, "3") == 0) {
        in1 = fopen(in1_name, "rb");
        in2 = fopen(in2_name, "rb");
        out = fopen(out_name, "a+b"); 
    } else {
        in1 = fopen(in1_name, "r");
        in2 = fopen(in2_name, "r");
        out = fopen(out_name, "a+");  
    }

    if (!in1 || !in2 || !out) {
        fprintf(stderr, "Błąd otwarcia strumieni!\n");
        perror("fopen");
        if (in1) fclose(in1);
        if (in2) fclose(in2);
        if (out) fclose(out);
        return EXIT_FAILURE;
    }

    int status = EXIT_SUCCESS;

    if (strcmp(mode, "1") == 0) {
        status = process_by_char(in1, out);
    } else if (strcmp(mode, "2") == 0) {
        status = process_by_line(in1, out);
    } else if (strcmp(mode, "3") == 0) {
        status = process_by_block(in1, out);
    } else {
        fprintf(stderr, "Nieznany tryb: %s\n", mode);
        fclose(in1); fclose(in2); fclose(out);
        return EXIT_FAILURE;
    }

    if (status != EXIT_SUCCESS) {
        fclose(in1); fclose(in2); fclose(out);
        return EXIT_FAILURE;
    }

    if (strcmp(mode, "1") == 0) {
        status = process_by_char(in2, out);
    } else if (strcmp(mode, "2") == 0) {
        status = process_by_line(in2, out);
    } else if (strcmp(mode, "3") == 0) {
        status = process_by_block(in2, out);
    }

    if (status != EXIT_SUCCESS) {
        fclose(in1); fclose(in2); fclose(out);
        return EXIT_FAILURE;
    }


    rewind(in1);
    printf("%s: ", in1_name);
    int c;
    while ((c = fgetc(in1)) != EOF) fputc(c, stdout);
    printf("\n");

    rewind(in2);
    printf("%s: ", in2_name);
    while ((c = fgetc(in2)) != EOF) fputc(c, stdout);
    printf("\n");

    print_output_file_content(out_name, out);

    fcloseall();

    return EXIT_SUCCESS;
}

int process_by_char(FILE *in_file, FILE *out_file) {
    int c;
    while ((c = fgetc(in_file)) != EOF) {
        fputc(c, out_file);
    }
    if (ferror(in_file) || ferror(out_file)) return EXIT_FAILURE;
    if (!feof(in_file)) return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

int process_by_line(FILE *in_file, FILE *out_file) {
    char buf[BUFFER_SIZE_LINE];
    while (fgets(buf, sizeof(buf), in_file) != NULL) {
        fputs(buf, out_file); 
    }
    if (ferror(in_file) || ferror(out_file)) return EXIT_FAILURE;
    if (!feof(in_file)) return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

int process_by_block(FILE *in_file, FILE *out_file) {
    char buf[BUFFER_SIZE_BLOCK];
    size_t bytes_read;
    while ((bytes_read = fread(buf, sizeof(char), BUFFER_SIZE_BLOCK, in_file)) > 0) {
        fwrite(buf, sizeof(char), bytes_read, out_file);
    }
    if (ferror(in_file) || ferror(out_file)) return EXIT_FAILURE;
    if (!feof(in_file)) return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

void print_output_file_content(const char *filename, FILE *out_file) {
    int c;
    rewind(out_file);
    printf("%s: ", filename);
    while ((c = fgetc(out_file)) != EOF) {
        fputc(c, stdout);
    }
    printf("\n");
}