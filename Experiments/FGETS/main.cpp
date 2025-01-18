#include <iostream>
#include <stdio.h>
#define LENGTH 100
using namespace std;

int main()
{
    char buffer[LENGTH];
    cout << "Enter the Charecter input" << endl;
    fgets((char *)buffer, sizeof(buffer), stdin);

    cout << "BUFFER IS:" << buffer << endl;
}