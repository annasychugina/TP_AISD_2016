/*
 *
 * author: Sychugina Anna
 * group: ���-12
 * task: 3_2.  ��� ������ ����� ����� �[0..n-1]. ��������, ��� �� ��������� [0, m] �������� ������� 
 * ������ ����������, � �� ��������� [m, n-1] ������ �������.
 * ����� m �� O(log m).
 * 
 */

#include <stdlib.h>
#include <stdio.h>

int Findposition(int *a, int n, int k) {

    int m = 0;

    if (a[0] < a[1] && a[n - 2] > a[n - 1]) { //�������� �� �������� � �����������
        m = 1;
        while (m < n && a[m - 1] < a[m])
            m *= 2;
        k = m / 2;
        if (m >= n) m = n - 1; //������������� ������
        while (k > 0) {
            if (!(a[m - 1] < a[m] && a[m] > a[m + 1])) { //���� ����� �������
                if (a[m - 1] > a[m]) //���� ���������� � ������ �����
                    m -= k;
                else {
                    m += k; //  ���� ��������� � ����� �����
                    if (m >= n) m = n - 1; //������������� ������
                }
            }
            k /= 2; // ������� �������������
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

    //���� n
    scanf("%d", &n);

    int *a = (int*) malloc(n * sizeof (int));

    int k = 0;

    //���� ��������� ������� �
    for (k = 0; k < n; k++)
        scanf("%d", &a[k]);

    //����� m
    printf("%d", Findposition(a, n, k));

    //������������ ������
    free(a);
    return 0;
}

