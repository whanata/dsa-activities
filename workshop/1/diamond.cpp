#include <iostream>
#include <string>

using namespace std;

int getSize();
char getOutput(string question);
void printDiamond(int size, char border, char fill);
char getCorrectChar(int middle, int row, char border, char fill);

int getSize()
{
    bool wrong;
    string output;
    int outputNum;
    string question = "Please enter size: ";

    do
    {
        wrong = false;

        std::cout << question;
        std::cin >> output;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<streamsize>::max(), '\n');

        try
        {
            outputNum = std::stoi(output);
        } 
        catch (invalid_argument)
        {
            wrong = true;
            std::cout << "Please input only an integer.\n";
            continue;
        }

        if (outputNum <= 0)
        {
            wrong = true;
            std::cout << "Please input number above 0.\n";
        }
        else if (outputNum % 2 == 0)
        {
            wrong = true;
            std::cout << "Please input an odd number.\n";
        }

    } while (wrong);

    return outputNum;
}

char getOutput(string question)
{
    char output;

    std::cout << question;
    output = std::cin.get();
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<streamsize>::max(), '\n');

    return output;
}

char getCorrectChar(int middle, int column, int row, char border, char fill)
{
    int leastBorderValue = middle - row;
    int highestBorderValue = middle + row;
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

void printDiamond(int size, char border, char fill)
{
    int middle = size / 2;
    int firstHalfSize = middle;
    int secondHalfSize = middle - 1;

    for (int row = 0; row < firstHalfSize; row++)
    {
        for (int column = 0; column < size; column++)
        {
            cout << getCorrectChar(middle, column, row, border, fill);
        }
        cout << "\n";
    }

    for (int row = secondHalfSize; row >= 0; row--)
    {
        for (int column = 0; column < size; column++)
        {
            cout << getCorrectChar(middle, column, row, border, fill);
        }
        cout << "\n";
    }

}

int main(int argc, char *argv[]) 
{
    int size = getSize();
    char border = getOutput("Please enter border: ");
    char fill = getOutput("Please enter fill: ");
    // int size = 15;
    // char border = '#';
    // char fill = '+';

    printDiamond(size, border, fill);

    return 0;
}