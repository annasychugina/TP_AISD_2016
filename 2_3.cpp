/*
 *
 * author: Sychugina Anna
 * group: АПО-12
 * task: 2_3. Даны два строго возрастающих массива целых чисел A[0..n) и B[0..m) и число k. 
 * Найти количество таких пар индексов (i, j), что A[i] + B[j] = k. 
 * n, m ? 100000.
 * Время работы O(n + m).
 * 
 */

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define STD_ERROR_MSG printf("[error]")
#define MAX_CNT 100000



//Нахождение ко-ва пар индексов

int FindIndex(int*a, int*b, int i, int m, int n, int k) {

    int j = 0;
    int res = 0;
    int _a = 0;


    //Массив В начинаем обходить с конца,а массив A с начала.
    for (i = m - 1; i >= 0; i--) {

        _a = k - b[i];
        while (j < n && a[j] < _a) ++j;
        if (j == n) break;
        //Если нашли пару элементов среди них, для которой ((b[i]+a[j])==k) , увеличиваем счетчик.
        if (_a == a[j]) ++res;

    }
    return res;
}

int main(void) {

    int n = 0;

    //Ввод n
    if (scanf("%d", &n) != 1) {
        STD_ERROR_MSG;
        return (EXIT_SUCCESS);
    }
    if (n < 1 || n > MAX_CNT) {
        STD_ERROR_MSG;
        return (EXIT_SUCCESS);
    }

    int *a = (int*) malloc(n * sizeof (int));

    int i = 0;

    // Ввод массива а по одному элементу 
    for (i = 0; i < n; i++)

        if (scanf("%d", &a[i]) != 1) {
            STD_ERROR_MSG;
            free(a);
            return (EXIT_SUCCESS);
        }

    int m = 0;

    //Bвод m
    if (scanf("%d", &m) != 1) {
        STD_ERROR_MSG;
        return (EXIT_SUCCESS);
    }
    if (m < 1 || m > MAX_CNT) {
        STD_ERROR_MSG;
        return (EXIT_SUCCESS);
    }

    int *b = (int*) malloc(m * sizeof (int));

    // Ввод массива b по одному элементу
    for (i = 0; i < m; i++)

        if (scanf("%d", &b[i]) != 1) {
            STD_ERROR_MSG;
            free(b);
            return (EXIT_SUCCESS);
        }

    int k = 0;

    //ввод k
    if (scanf("%d", &k) != 1) {
        STD_ERROR_MSG;
        free(a);
        free(b);
        return (EXIT_SUCCESS);
    }

    //Вывод количества пар индексов
    printf("%d", FindIndex(a, b, i, m, n, k));

    //Освобождение памяти
    free(a);
    free(b);
    return (EXIT_SUCCESS);
}
