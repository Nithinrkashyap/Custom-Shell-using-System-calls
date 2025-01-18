#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

using namespace std;

int main()
{

    char *env_path = getenv("path");
    if (env_path == NULL)
        perror("Problem in path");

    else
        cout << env_path << endl;
}