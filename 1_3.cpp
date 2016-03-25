/*   Copyright (C) 2016 Sychugina Anna */
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define STD_ERROR_MSG printf("[error]")

int nod(int a, int b) {
    while (a != 0 && b != 0)
        if (a > b) a %= b;
        else b %= a;
    return (a + b);
}

int main(void) {
    char *line = NULL;
    size_t size = 0;
    ssize_t bytes = getline(&line, &size, stdin);

    if (line == NULL) {
        STD_ERROR_MSG;
        return 0;
    }

    if (bytes == -1) {
        // read error
        free(line);
        STD_ERROR_MSG;
        return 0;
    }
    int a, b, c, d;
    if (sscanf(line, "%d %d %d %d", &a, &b, &c, &d) != 4) {
        // read error
        free(line);
        STD_ERROR_MSG;
        return 0;
    }
    free(line);
    if (b == 0 || d == 0) {
        STD_ERROR_MSG;
        return 0;

    }


    a = a * d + c * b, b = b * d;

    int cd = nod(abs(a), abs(b));
    printf("%d %d", a / cd, b / cd);


    return 0;
}

