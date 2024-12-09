#include <stdio.h>

int main() {
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    int total = 0;

    FILE *file = fopen("day4-2022-test.txt", "r");
    char line[256];

    if (file == NULL) {
        printf("Error file not found\n");
        return 1;
    }

    while (fgets(line, sizeof(line), file)) {
        sscanf(line, "%d-%d,%d-%d", &a, &b, &c, &d);

        //printf("a: %d, b: %d\n", a, b);
        //printf("c: %d, d: %d\n", c, d);

        if(a <= c && b >= d) {
            total += 1;
        } else if(a >= c && b <= d) {
            total += 1;
        }

        printf("Total: %d\n", total);
    }

    fclose(file);

    //printf("Total: %d\n", total);
    return 0;
}