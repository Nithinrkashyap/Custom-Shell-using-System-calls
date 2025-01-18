#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

int main()
{
    char MY_VARIABLE[] = "CUSTOM_VARIABLE";
    const char *value = "Hi c++";

    if (setenv((char *)MY_VARIABLE, value, 0) != 0)
        perror("Error in setting env variable");

    cout << getenv(MY_VARIABLE) << endl;
}