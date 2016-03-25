/*
 *
 * author: Sychugina Anna
 * group: ���-12
 * task: 2_3. ���� ��� ������ ������������ ������� ����� ����� A[0..n) � B[0..m) � ����� k. 
 * ����� ���������� ����� ��� �������� (i, j), ��� A[i] + B[j] = k. 
 * n, m ? 100000.
 * ����� ������ O(n + m).
 * 
 */

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define STD_ERROR_MSG printf("[error]")
#define MAX_CNT 100000



//���������� ��-�� ��� ��������

int FindIndex(int*a, int*b, int i, int m, int n, int k) {

    int j = 0;
    int res = 0;
    int _a = 0;


    //������ � �������� �������� � �����,� ������ A � ������.
    for (i = m - 1; i >= 0; i--) {

        _a = k - b[i];
        while (j < n && a[j] < _a) ++j;
        if (j == n) break;
        //���� ����� ���� ��������� ����� ���, ��� ������� ((b[i]+a[j])==k) , ����������� �������.
        if (_a == a[j]) ++res;

    }
    return res;
}

int main(void) {

    int n = 0;

    //���� n
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

    // ���� ������� � �� ������ �������� 
    for (i = 0; i < n; i++)

        if (scanf("%d", &a[i]) != 1) {
            STD_ERROR_MSG;
            free(a);
            return (EXIT_SUCCESS);
        }

    int m = 0;

    //B��� m
    if (scanf("%d", &m) != 1) {
        STD_ERROR_MSG;
        return (EXIT_SUCCESS);
    }
    if (m < 1 || m > MAX_CNT) {
        STD_ERROR_MSG;
        return (EXIT_SUCCESS);
    }

    int *b = (int*) malloc(m * sizeof (int));

    // ���� ������� b �� ������ ��������
    for (i = 0; i < m; i++)

        if (scanf("%d", &b[i]) != 1) {
            STD_ERROR_MSG;
            free(b);
            return (EXIT_SUCCESS);
        }

    int k = 0;

    //���� k
    if (scanf("%d", &k) != 1) {
        STD_ERROR_MSG;
        free(a);
        free(b);
        return (EXIT_SUCCESS);
    }

    //����� ���������� ��� ��������
    printf("%d", FindIndex(a, b, i, m, n, k));

    //������������ ������
    free(a);
    free(b);
    return (EXIT_SUCCESS);
}
