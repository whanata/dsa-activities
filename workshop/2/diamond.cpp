#include <iostream>
#include <string.h>
#include <ctype.h>

using namespace std;

bool checkSize(string output);
bool checkOutput(string errMsg, string output);
void printDiamond(int size, char border, char fill);
char getCorrectChar(int middle, int row, char border, char fill, char size);
void intializeDiamonArray(char *diamondArray[], int size);
void checkArgument(int argCount, char *argVariables[]);
void print2dArray(char *diamondArray[]);

bool checkSize(char *output)
{
    int outputNum;
    string sizeErrorMsg = "Size Error: ";

    try
    {
        outputNum = stoi(output);
    } 
    catch (invalid_argument)
    {
        cout << sizeErrorMsg << "Please input only an integer.\n";
        return false;
    }

    if (outputNum <= 0)
    {
        cout << sizeErrorMsg << "Please input number above 0.\n";
        return false;
    }
    else if (outputNum % 2 == 0)
    {
        cout << sizeErrorMsg << "Please input an odd number.\n";
        return false;
    }

    return true;
}

bool checkOutput(string errMsg, char *output)
{
    if (strlen(output) != 1)
    {
        cout << errMsg << " Please input one character." << "\n";
        return false;
    }

    return true;
}

char getCorrectChar(int middle, int column, int row, char border, char fill, char size = 0)
{
    int leastBorderValue = middle - row;
    int highestBorderValue = middle + row;

    if (size != 0) 
    {
        highestBorderValue = middle - row + size - 1;
        leastBorderValue = middle + row - size + 1;
    }

    if (column == highestBorderValue || column == leastBorderValue)
    {
        return border;
    }
    else if (column < highestBorderValue && column > leastBorderValue)
    {
        return fill;
    }
    else
    {
        return ' ';
    }
}

void intializeDiamonArray(char *diamondArray[], int size)
{
    for (int row = 0; row < size; row++)
    {
        diamondArray[row] = new char[size];
    }
}

void print2dArray(char *diamondArray[], int size)
{
    for (int row = 0; row < size; row++)
    {
        for (int column = 0; column < size; column++)
        {
            cout << diamondArray[row][column];
        }
        cout << "\n";
    }
}

void printDiamond(int size, char border, char fill)
{
    int middle = size / 2;
    char **diamondArray = new char *[size];

    intializeDiamonArray(diamondArray, size);

    for (int row = 0; row < middle; row++)
    {
        for (int column = 0; column < size; column++)
        {
            diamondArray[row][column] = getCorrectChar(middle, column, row, border, fill);
        }
    }

    for (int row = middle; row < size; row++)
    {
        for (int column = 0; column < size; column++)
        {
            diamondArray[row][column] = getCorrectChar(middle, column, row, border, fill, size);
        }
    }

    print2dArray(diamondArray, size);
}

void checkArgument(int argCount, char *argVariables[])
{
    bool correctArguments = false; 

    if (argCount == 4) 
    {
        if (checkSize(argVariables[1]) && checkOutput("Border Error:", argVariables[2]) && checkOutput("Fill Error:", argVariables[3]))
        {
            correctArguments = true;
        }
    }
    else
    {
        cout << "Only allowed 3 arguments\n";
    }

    if (correctArguments == false)
    {
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char *argv[]) 
{
    checkArgument(argc, argv);
    int size = stoi(argv[1]);
    char border = argv[2][0];
    char fill = argv[3][0];

    printDiamond(size, border, fill);

    return 0;
}