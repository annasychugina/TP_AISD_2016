/*
 *
 * author: Sychugina Anna
 * group: АПО-12
 * task: 5_4.  Вычисление выражения.
 * Дано выражение в инфиксной записи. Вычислить его, используя перевод выражения в постфиксную запись. Выражение не содержит отрицительных чисел.
 *Количество операций ? 100.
 *Формат входных данных. Строка, состоящая их символов “0123456789-+*()/
 * Гарантируется, что входное выражение корректно, нет деления на 0, вычислимо в целых числах. Деление целочисленное.
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 500

int N;
char buf[MAX_LEN]; //инфиксна¤ запись
char out_expr[MAX_LEN]; //постфиксна¤ запись в обратном пор¤дке
int len_out_expr;

struct Lexema {
    char *p;
    int n;

    Lexema() {
        p = NULL;
        n = 0;
    }

    Lexema(char *p1, int n1) {
        this->p = p1;
        this->n = n1;
    }

    void print() {
        for (int i = 0; i < n; i++) {
            printf("%c", p[i]);
        }
        printf("\n");
    }
};

struct Elements_number {
    char op; //op = +-*/ or space => number
    int x;

    Elements_number() {
        op = ' ';
        x = 0;
    }

    Elements_number(char op1) {
        this->op = op1;
        this->x = 0;
    }

    Elements_number(int x1) {
        this->x = x1;
        this->op = ' ';
    }

};

Lexema lexemes[MAX_LEN];

Elements_number elems[MAX_LEN];

class Stack {
public:
    void push(Elements_number x);
    Elements_number pop();
    bool empty();
    bool full();

    Stack(int size1);
    ~Stack();
private:
    Elements_number *data;
    int size;
    int top; //top elem number

};

void Stack::push(Elements_number x) {
    if (!full())
        this->data[++top] = x;
    else
        throw "Attempt push into full  stack";
}

Elements_number Stack::pop() {
    if (!empty())
        return this->data[top--];
    else
        throw "Attempt pop from empty stack";
}

bool Stack::empty() {
    return top == -1;
}

bool Stack::full() {
    return top == size - 1;
}

Stack::Stack(int size1) {
    this->size = size1;
    this->data = new Elements_number[size];
    this->top = -1;
}

Stack::~Stack() {
    if (data)
        delete[] data;
    data = NULL;
}

int ToNumber(char *a, int n) {
    int x = 0;
    int d;
    int deg10 = 1;

    for (int i = n - 1; i >= 0; i--) {
        d = a[i] - '0';
        x += d * deg10;
        deg10 *= 10;
    }
    return x;
}

//разбиение строки — на лексемы (после каждой лексемы ставитс¤ '\0'); 
//рез-т массив Elem *lexemes; явный результат - кол-во элементов в elems

int Split(char *s, int n, Lexema *lexemes) {
    s[n - 1] = '\0';

    int j = 0; //elems

    char *w;

    if ((w = strtok(s, " ")) != NULL) {
        lexemes[j++] = Lexema(w, strlen(w));
    }
    while ((w = strtok(NULL, " ")) != NULL) {
        lexemes[j++] = Lexema(w, strlen(w));
    }

    return j;
}
//вычисление выражения

int Count_PostfixedExpr(Elements_number *elems, int nElems, Stack &st) {
    char c;
    Elements_number e1, e0;

    for (int i = nElems - 1; i >= 0; i--) {
        Elements_number e = elems[i];

        c = e.op;

        switch (c) {
            case '+':
                e1 = st.pop();
                e0 = st.pop();
                st.push(Elements_number(e0.x + e1.x));
                break;
            case '-':
                e1 = st.pop();
                e0 = st.pop();
                st.push(Elements_number(e1.x - e0.x));
                break;
            case '*':
                e1 = st.pop();
                e0 = st.pop();
                st.push(Elements_number(e0.x * e1.x));
                break;
            case '/':
                e1 = st.pop();
                e0 = st.pop();
                st.push(Elements_number(e1.x / e0.x));
                break;
            default:
                st.push(e);
                break;
        }
    }

    return st.pop().x;
}
//удаление  скобок

bool delete_external_brackets(char *&expr, int &n) {
    if (expr[0] != '(')
        return false;
    int i, level = 1;
    for (i = 1; i < n && level != 0; i++) {
        if (expr[i] == '(')
            level++;
        else if (expr[i] == ')')
            level--;
    }

    if (i == n) //удаляем внешние скобки
    {
        expr += 1;
        n -= 2;
        return true;
    } else
        return false;
}

//вывод от конца к началу

void output(char c) //вывод операции
{
    out_expr[len_out_expr++] = c;
    out_expr[len_out_expr++] = ' ';
}

void output(char *a, int n) //вывод числа
{
    int i;
    for (i = 0; i < n; i++)
        out_expr[len_out_expr++] = a[i];
    out_expr[len_out_expr++] = ' ';
}

void Postfix_note(char *expr, int n) //поз операции самого нижнего уровн¤ и самого нижнего приорите
{
    while (delete_external_brackets(expr, n));

    int i;
    char c;
    int level = 0;

    //приоритет = 1 (+,-), 2 (*, /)

    int pos_1 = -1; //поз последней операции самого нижнего уровн¤ и приоритета 1 (+,-),
    int pos_2 = -1; //поз последней операции самого нижнего уровн¤ и приоритета 2 (*, /)

    //ищем операцию уровн¤ 0 наименьшего приоритета => вывод операции и рекурсивные вызовы дл¤ операндов
    for (i = 0; i < n;) {
        c = expr[i];
        switch (c) {
            case '(': level++;
                i++;
                break;
            case ')': level--;
                i++;
                break;
            case '+':
            case '-':
            case '*':
            case '/':
                if (level == 0) {
                    if (c == '+' || c == '-')
                        pos_1 = i;
                    else
                        pos_2 = i;
                }
                i++;
                break;
            default: //цифра - начало числа
                for (; i < n && strchr("1234567890", expr[i]) != NULL; i++);
                break;

        }
    }
    int pos;

    if (pos_1 != -1) //+, -
    {
        pos = pos_1;
        output(expr[pos]);
        Postfix_note(expr, pos);
        Postfix_note(expr + (pos + 1), n - (pos + 1));
    } else if (pos_2 != -1) //*, /
    {
        pos = pos_2;
        output(expr[pos]);
        Postfix_note(expr, pos);
        Postfix_note(expr + (pos + 1), n - (pos + 1));
    } else if (strchr("1234567890", expr[0]) != NULL) {
        output(expr, n);
    } else {
        printf("[error]");
    }

}

Elements_number * Findelems(int nLexemes, Lexema *lexemes) {
    for (int i = 0; i < nLexemes; i++) {
        if (strchr("+-*/", lexemes[i].p[0]) != NULL)
            elems[i] = Elements_number(lexemes[i].p[0]);
        else
            elems[i] = Elements_number(ToNumber(lexemes[i].p, lexemes[i].n));

    }
    return elems;

}

int main() {

    //Ввод данных
    scanf("%s", buf);

    //N
    N = strlen(buf);

    Postfix_note(buf, N); //--> out_expr

    out_expr[len_out_expr - 1] = '\0';

    //Makes lexemes
    int nLexemes = Split(out_expr, len_out_expr, lexemes);

    Stack st(100);

    //Вывод результата
    printf("%d", Count_PostfixedExpr(Findelems(nLexemes, lexemes), nLexemes, st));
    return 0;
}
