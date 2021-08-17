#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void compress(char *input, char *output) {
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
    printf("Usage: ./rle <input-text>\n");
    exit(0);
}

int main(int argc, char *argv[]) {

    if (argc <= 1 || strlen(argv[1]) <= 0)
        usage();
    
    char *input = argv[1];
    char *output = malloc(strlen(input));

    compress(input, output);
    
    printf("output: %s\n", output);
    free(output);
    return 0;
}