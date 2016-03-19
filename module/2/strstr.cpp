#include <iostream>

using namespace std;

int main() 
{
    char string[] = "elephant";
    int index;

    char *found = strstr(string, "han");
    cout << found << "|" << string << "\n";
    if (found == NULL)
    {
        index = -1;
    }
    else
    {
        index = found - string;
    }
    cout << found << " - " << string << " = " << index;
    return 0;
}