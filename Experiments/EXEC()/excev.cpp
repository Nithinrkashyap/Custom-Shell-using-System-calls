#include <unistd.h>
#include <cstdlib>
#include <iostream>

using namespace std;
int main()
{
    const char *absolutepath = "/bin/ls";
    const char *args[] = {"ls", NULL};
    if (execv(absolutepath, (char **)args) == -1)
        perror("error");
    return 0;
}