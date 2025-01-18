#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <fcntl.h>
#include <sys/types.h>
#include <bits/stdc++.h>
#include <sys/wait.h>
#include <sys/stat.h>
using namespace std;

int main()
{
    char currdir[1024 + 1];
    cout << "pwd: " << getcwd(currdir, 1024 + 1) << endl;
    cout << currdir << endl;
    if (chdir("/Users/nithinrkashyap/Desktop/Shell_programming_using_fork/Experiments/") != 0)
        perror("error in changing the dirctory");
    cout << "pwd: " << getcwd(currdir, 1024 + 1) << endl;
    cout << currdir << endl;

    char *args[] = {"pwd", NULL};

    pid_t pid = fork();
    if (pid < 0)
        perror("error");
    else if (pid == 0)
    {
        cout << "Child process is executing the command" << endl;
        if (execvp("pwd", args) == -1)
            perror("error in executing pwd");
    }
    else
    {
        int status;
        waitpid(pid, &status, 0);
        cout << "Executes the command successfully" << endl;
    }
}