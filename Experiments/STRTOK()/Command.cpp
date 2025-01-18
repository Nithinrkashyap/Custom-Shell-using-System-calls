#include <iostream>
#include <cstring>
#define MAX_LENGTH 100

using namespace std;

int main(int argc, char **argv)
{

    char command[] = "cd.....!!!@ -l ?? 'user/lib/sys'";
    const char *delimeter = " .?!@";
    char *token = strtok((char *)command, (char *)delimeter);

    char *args[MAX_LENGTH];
    int i = 0;
    while (token != NULL)
    {
        args[i] = token;
        cout << args[i] << endl;
        token = strtok(NULL, delimeter);
        i++;
    }
    args[i] = NULL;
}