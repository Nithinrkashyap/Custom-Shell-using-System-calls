#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <cstring>
using namespace std;
int main()
{

    char *arguments[] = {"ls", NULL};

    cout << "Parent Process started " << endl;
    cout << "Parent process pid:" << getpid() << endl;
    pid_t pid = fork();
    if (pid < 0)
    {
        perror("failed");
        exit(0);
    }
    else if (pid == 0)
    {
        std::cout << "Child: Running execvp to execute 'ls' \n";
        if (execvp("ls", arguments) == -1)
        {
            perror("execvp failed");
            return 1;
        }

        // This will never be executed if execvp is successful
        std::cout << "Child: This line will not be printed\n";
    }
    else
    {

        int status;
        cout << "Pid :" << getpid() << endl;
        waitpid(pid, &status, 0);
        cout << "ls command gets executed successfully " << "\n";
    }

    std::cout << "Parent: Program finished\n";
    return 0;
}