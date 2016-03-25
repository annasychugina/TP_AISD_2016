/*
 * author: Sychugina Anna
 * group: АПО-12
 Дано N кубиков. Требуется определить каким количеством способов можно выстроить из этих кубиков
пирамиду. На вход подается количество кубиков N.Вывести число различных пирамид из N кубиков.
6_1.?Высокая пирамида. ?Каждый вышележащий слой пирамиды должен быть не больше нижележащего.
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

    //Заполнение таблицы
    for (int i = N - K; i < N; i++)
    {
        res += number_of_pyramids(i, std::min(i, N - i), temp_calculation);
    }


    temp_calculation[N][K] = res; //кол-во пирамид

    return res;
}

int main()
{

    int N = 0;
    std::cin>>N; //ввод N

    //Выделение памяти
    long long** table = new long long* [N + 1];

    for (int i = 0; i <= N; i++)
    {
        table[i] = new long long[N + 1];

        //заполняем -1
        for (int j = 0; j <= N; j++)
        {
            table[i][j] = -1;
        }
    }
    //Начало заполнения таблицы: единицы в 0-строке, 0-столбце
    for (int i = 0; i <= N; i++)
    {
        table[i][0] = 1;
        table[0][i] = 1;
    }

    //Вывод
    std::cout << number_of_pyramids(N, N, table);

    //Освобождение памяти
    for (int i = 0; i <= N; i++)
    {
        delete [] table[i];
    }
    delete [] table;
    return 0;
}