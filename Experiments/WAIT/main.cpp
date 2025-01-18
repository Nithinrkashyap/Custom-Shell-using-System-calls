#include <stdio.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <iostream>
#include <unistd.h>
using namespace std;

int main(int argc, char **argv)
{

    int fd;
    int exitval = 10;
    int exitstatus;
    fd = open(argv[1], O_RDWR | O_CREAT | O_TRUNC, 0644);
    if (fd == -1)
    {
        perror("open");
        exit(EXIT_FAILURE);
    }
    write(fd, "Original process writes\n", 24);
    switch (fork())
    {
    case 0:
        write(fd, "Child writes\n", 13);
        close(fd);
        cout << "CHILD: Terminates with exit value " << exitval << endl;
        exit(exitval);

    default:
        wait(&exitstatus);
        write(fd, "Parent writes\n", 14);
        close(fd); // Close the file descriptor in the parent process
        cout << "PARENT : Terminates with exit value" << WEXITSTATUS(exitstatus) << endl;
        exit(20);
    }
}
