#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1024

void diff_encode(char *input, char *output) {
    for (int i = 0; i < strlen(input); i++) {
        if (i == 0) {
            output[0] = input[0];
        } else if (input[0] == input[i]) {
            output[i] = input[i];
        }else {
            char diff = input[0]-input[i]; 
            output[i] = diff;
        }
    }

    output[strlen(input)] = '\0';
}

void diff_decode(char *input, char *output) {
    for (int i = 0; i < strlen(input); i++) {
        if (i == 0) {
            output[0] = input[0];
        } else if (input[0] == input[i]) {
            output[i] = input[i];
        } else {
            output[i] = input[0]-input[i];
            printf("%d ", output[i]);
        }
    }

    output[strlen(input)] = '\0';
}



void decode(char *input, char *output) {
    int out_i = 0;

    for (int i = 0; input[i]; i += 2) {
        char num = input[i+1] - '0';
        for (int j = 0; j < num; j++) {
            output[out_i] += input[i];
            out_i++;
        }
    }
}

void encode(char *input, char *output) {
    int length = strlen(input);

    int count = 0;
    int out_i = 0;

    for (int i = 0; input[i]; i++) {
        count = 1;
        output[out_i] = input[i];

        while(input[i]==input[i+1]) {
            count++;
            i++;
        }

        output[out_i+1] = (count + '0');
        out_i += 2;
    }
}

void usage() {
    printf("Usage: ./rle <option> <input-text>\nOption: \n\t-e = encode mode\n\t-d = decode mode \n");
    exit(0);
}

int main(int argc, char *argv[]) {

    char *test = "test";
    char out[MAX_SIZE];
    char out2[MAX_SIZE];

    if (argc <= 1 || strlen(argv[1]) < 2)
        usage();

    char *input = argv[2];
    char *output = malloc(MAX_SIZE);

    if (!strcmp(argv[1],"-c")) {
        encode(input, output);
    } else if (!strcmp(argv[1],"-d")) {
        decode(input, output);
    } else if (!strcmp(argv[1],"-cdl")) {
        
    } else if (!strcmp(argv[1],"-ddl")) {

    } else {
        printf("Failed: option is invalid.\n");
        exit(0);
    }

    printf("output: %s\n", output);
    return 0;
}