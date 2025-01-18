#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <cstdio>
#include <iostream>
using namespace std;

int main()
{

    pid_t pid;
    cout << "Parent process and its parents :" << getpid() << " " << getppid() << endl;
    if ((pid = fork()) > 0)
        exit(0);
    else if (pid == 0)
    {
        sleep(1);
        cout << "Child adopted by init process: " << getpid() << " " << getppid() << endl;
    }
}
