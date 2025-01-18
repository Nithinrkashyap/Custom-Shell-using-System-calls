#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char str[] = "Hello ,c++ .... welcome, ......!!!!";
    const char *delimeter = " .,!";
    char *tokenizing_delimeter = strtok((char *)str, (char *)delimeter); // delemiter
    //& strtok() returns 1st token in a char array
    cout << tokenizing_delimeter << endl;

    //[token1,token2,....]
    cout << "TOKENS:" << endl;
    while (tokenizing_delimeter != NULL)
    {
        cout << tokenizing_delimeter << endl;
        tokenizing_delimeter = strtok(NULL, delimeter);
    }
}