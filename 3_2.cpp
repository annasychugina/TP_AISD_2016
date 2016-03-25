/*
 *
 * author: Sychugina Anna
 * group: АПО-12
 * task: 3_2.  Дан массив целых чисел А[0..n-1]. Известно, что на интервале [0, m] значения массива 
 * строго возрастают, а на интервале [m, n-1] строго убывают.
 * Найти m за O(log m).
 * 
 */

#include <stdlib.h>
#include <stdio.h>

int Findposition(int *a, int n, int k) {

    int m = 0;

    if (a[0] < a[1] && a[n - 2] > a[n - 1]) { //проверка на убывание и возрастание
        m = 1;
        while (m < n && a[m - 1] < a[m])
            m *= 2;
        k = m / 2;
        if (m >= n) m = n - 1; //корректировка границ
        while (k > 0) {
            if (!(a[m - 1] < a[m] && a[m] > a[m + 1])) { //если нашли элемент
                if (a[m - 1] > a[m]) //если находиимся в правой части
                    m -= k;
                else {
                    m += k; //  если находимся в левой части
                    if (m >= n) m = n - 1; //корректировка границ
                }
            }
            k /= 2; // сужение полуинтервала
        }
    } else {
        if (a[0] > a[1])
            m = 0;
        else
            m = n - 1;
    }
    return m;
}

int main() {

    int n = 0;

    //Ввод n
    scanf("%d", &n);

    int *a = (int*) malloc(n * sizeof (int));

    int k = 0;

    //Ввод элементов массива а
    for (k = 0; k < n; k++)
        scanf("%d", &a[k]);

    //Вывод m
    printf("%d", Findposition(a, n, k));

    //Освобождение памяти
    free(a);
    return 0;
}

