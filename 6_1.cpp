/*
 * author: Sychugina Anna
 * group: ���-12
 ���� N �������. ��������� ���������� ����� ����������� �������� ����� ��������� �� ���� �������
��������. �� ���� �������� ���������� ������� N.������� ����� ��������� ������� �� N �������.
6_1.?������� ��������. ?������ ����������� ���� �������� ������ ���� �� ������ ������������.
N ? 200.
 * 
 */

#include <iostream>
#define MAX_AMOUNT 200

long long number_of_pyramids(const int N, const int K, long long** temp_calculation)
{
    long long res = 0;

    if (temp_calculation[N][K] != -1)
        return temp_calculation[N][K];

    //���������� �������
    for (int i = N - K; i < N; i++)
    {
        res += number_of_pyramids(i, std::min(i, N - i), temp_calculation);
    }


    temp_calculation[N][K] = res; //���-�� �������

    return res;
}

int main()
{

    int N = 0;
    std::cin>>N; //���� N

    //��������� ������
    long long** table = new long long* [N + 1];

    for (int i = 0; i <= N; i++)
    {
        table[i] = new long long[N + 1];

        //��������� -1
        for (int j = 0; j <= N; j++)
        {
            table[i][j] = -1;
        }
    }
    //������ ���������� �������: ������� � 0-������, 0-�������
    for (int i = 0; i <= N; i++)
    {
        table[i][0] = 1;
        table[0][i] = 1;
    }

    //�����
    std::cout << number_of_pyramids(N, N, table);

    //������������ ������
    for (int i = 0; i <= N; i++)
    {
        delete [] table[i];
    }
    delete [] table;
    return 0;
}