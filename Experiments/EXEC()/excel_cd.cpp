#include <iostream>
#include <unistd.h>
#include <cstdlib>

using namespace std;

int main()
{
    const char *absolutepath = "/bin/bash";
    const char *directory = "/Users/nithinrkashyap/Desktop/Shell_programming_using_fork/Experiments";
    string command = "cd " + string(directory) + " && exec bash";
    if (execl(absolutepath, "bash", "-c", command.c_str(), NULL) == -1)
        perror("error");
}