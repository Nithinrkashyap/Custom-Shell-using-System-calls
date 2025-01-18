// Shell programming in c using fork() and execvp() system calls
//! IN this shell programing  main concept is That main process is MYshell and
//! child process is the command that we are executing but we need t0 fork() the Myshell process
//! to create a child process and then we need to execute the command
//! in the child process using execvp() system call
//! And we should not replace the command process with main process(MYshell) process
#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <fcntl.h>
#include <sys/types.h>
#include <bits/stdc++.h>
#include <sys/wait.h>
#include <sys/stat.h>
#define CMD_LENGTH 1024
using namespace std;
void tokenize(char *command_user, char **arguments, char *delimeter)
{
    char *Command_tokens_delimetrized = (char *)strtok((char *)command_user, (char *)delimeter);
    int iterations = 0;
    while (Command_tokens_delimetrized != NULL)
    {
        arguments[iterations] = Command_tokens_delimetrized;
        // cout << arguments[iterations] << endl;
        Command_tokens_delimetrized = strtok(NULL, delimeter);
        iterations++;
    }
    arguments[iterations] = NULL;
}

int main(int argc, char **argv)
{
    char command_user[CMD_LENGTH];
    char *arguments[CMD_LENGTH];

    while (true)
    {
        cout << "$NITHIN SHELL ";
        fgets((char *)command_user, sizeof(command_user), stdin);
        //* Printing the buffer command_user
        // cout << "BUFFER IS:" << command_user << endl;

        //& Know my task is to tokenize this command_user into tokens(args)
        tokenize(command_user, arguments, " \t\n");
        // cout << "1st arguments: " << arguments[0] << endl;
        if (strcmp(arguments[0], "cd") == 0)
        {
            if (arguments[1] == "")
            {
                perror("Path not mentioned");
            }

            else
            {
                if (chdir(arguments[1]) != 0)
                    perror("Failed to change the directory");
            }
            continue;
        }
        //? Create a child process using fork()
        pid_t pid = fork();
        switch (pid)
        {
        // error
        case -1:
            perror("Failed to fork ");
            exit(0);
        //* when it is a  child case in the child process execute the command from the user input use execvp to replace the child process
        case 0:
            // this is child process
            // cout << "I am child process executing the command" << endl;
            if (execvp(arguments[0], arguments) == -1)
            {
                perror("Error in executing the command");
            }
            break;

        default:
            int status;
            //! It waits for the child process to get terminated
            waitpid(pid, &status, 0);
            // cout << "Executes the command successfully" << endl;
        }
    }
}