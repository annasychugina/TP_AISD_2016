/* Copyright (C) 2016 Sychugina Anna АПО-12 */
//7_2. Заявки на переговоры.
//В большой IT-фирме есть только одна переговорная комната. Желающие посовещаться заполняют заявки с желаемым временем начала и конца. Ваша задача определить максимальное количество заявок, которое может быть удовлетворено.
//Число заявок ? 100000.
//Формат входных данных:
//Вход содержит только пары целых чисел — начала и концы заявок.
//Формат выходных данных:
//Выход должен содержать натуральное число — максимальное число заявок.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct request_time
{
    int start; //начало заявки
    int finish; //конец заявки

    request_time(int _start, int _finish) : start(_start), finish(_finish)
    {
    }
};

bool request_time_comparator(request_time i, request_time k)
{
    return i.finish < k.finish;
}

void input_data(vector<request_time> &request)
{
    int start; //начало заявки
    int finish; //конец заявки

    while (!cin.eof())
    {
        cin >> start; //начало заявки
        cin >> finish; //конец заявки
        request.push_back(request_time(start, finish));
    }
}

int MaxNumber_request(vector<request_time> &request)
{

    //сортировка
    std::sort(request.begin(), request.end(), request_time_comparator);

    int k = 0, count_of_request = 1;


    for (size_t i = 1; i < request.size(); ++i)
    {
        if (request[i].start >= request[k].finish)
        {
            ++count_of_request;
            k = i; //номер последней выбранной заявки
        }
    }

    return count_of_request;
}

int main()
{
    vector<request_time> request;
    input_data(request); //

    cout << MaxNumber_request(request);
    return 0;
}