#include <iostream>
#include <unistd.h>
#include <cstdlib>
#define PATHLENGTH 100
using namespace std;

int main()
{
    cout << "Orginal process gets executed its pid and ppid" << getpid() << " " << getppid << endl;

    const char *absolutePATH = "/bin/ls";
    const char *directory = "/Users/nithinrkashyap/Desktop/Shell programming using fork() /Experiments/";
    if (execl(absolutePATH, "cd", directory, (char *)NULL) != -1)
    {
        cout << "execl gets executed its pid and ppid" << getpid() << " " << getppid << endl;
        // perror("error in execution of ls command");
        // exit(EXIT_FAILURE);
    }
    else
    {
        perror("error in execution of cd command");
    }
    cout << "This line does'nt execute" << endl;
}
