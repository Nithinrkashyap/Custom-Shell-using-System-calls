#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <cstdio>
#include <iostream>
#define PATH_LENGTH 1024
using namespace std;
int main()
{
    char newdir[PATH_LENGTH + 1];
    getcwd(newdir, PATH_LENGTH + 1);
    int x = 100;

    cout << "Before fork Current directory :" << newdir << endl;
    pid_t pid = fork();
    switch (pid)
    {
    case -1:
        perror("error in fork");
        exit(0);

    case 0:
        cout << "CHILD ---INHERITED VALUE x is: " << x << endl;
        x = 200;
        cout << "CHILD ---INHERITED VALUE cahnges  x is: " << x << endl;
        cout << "CHILD ---INHERITED VALUE  PATH: " << getenv("PATH") << endl;
        setenv("PATH", ".", 1);
        cout << "New child path " << getenv("PATH") << endl;
        if (chdir("/sys") != -1)
            getcwd(newdir, PATH_LENGTH + 1);
        cout << "New current directory for child path : " << newdir << endl;
        cout << "CHILD ---INHERITED VALUE  PATH: " << getenv("PATH") << endl;
        exit(0);
    default:
        cout << "Parent --- is sleeping for 1sec" << endl;
        sleep(1);
        cout << "Parent----  Value  of x  when chld changes is: " << x << endl;
        cout << "Parent----  Current directory :" << newdir << endl;
        cout << "Parent---- value of the path " << getenv("PATH") << endl;
    }
    cout << "Finally" << endl;
}