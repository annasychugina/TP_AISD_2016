/* Copyright (C) 2016 Sychugina Anna ���-12 */
//7_2. ������ �� ����������.
//� ������� IT-����� ���� ������ ���� ������������ �������. �������� ������������ ��������� ������ � �������� �������� ������ � �����. ���� ������ ���������� ������������ ���������� ������, ������� ����� ���� �������������.
//����� ������ ? 100000.
//������ ������� ������:
//���� �������� ������ ���� ����� ����� � ������ � ����� ������.
//������ �������� ������:
//����� ������ ��������� ����������� ����� � ������������ ����� ������.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct request_time
{
    int start; //������ ������
    int finish; //����� ������

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
    int start; //������ ������
    int finish; //����� ������

    while (!cin.eof())
    {
        cin >> start; //������ ������
        cin >> finish; //����� ������
        request.push_back(request_time(start, finish));
    }
}

int MaxNumber_request(vector<request_time> &request)
{

    //����������
    std::sort(request.begin(), request.end(), request_time_comparator);

    int k = 0, count_of_request = 1;


    for (size_t i = 1; i < request.size(); ++i)
    {
        if (request[i].start >= request[k].finish)
        {
            ++count_of_request;
            k = i; //����� ��������� ��������� ������
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