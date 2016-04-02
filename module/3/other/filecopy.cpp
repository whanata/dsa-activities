#include<string>
#include<iostream>
#include<fstream>

using namespace std;

const int PROGRAM = 0;
const int FILEIN = 1;
const int FILEOUT = 0;

void printSyntax(const string &program);
bool copyFile(const string &filein, const string &fileout, string &error);

int main(int argc, char *argv[])
{
   if (argc == 3)
   {
      string error;

      if (!copyFile(argv[FILEIN], argv[FILEOUT], error))
      {
         cerr << "Filecopy failed with the following error\n";
         cerr << error << "\n";
      }
   }
   else
   {
      printSyntax(argv[PROGRAM]);
   }

   return 0;
}

void printSyntax(const string &program)
{
   cout << "Syntax: " << program << " filein fileout\n";
   cout << "Will copy the contents of filein into fileout\n";
   cout << "If fileout does not exist it will be created otherwise\n";
   cout << "original contents of fileout will be over written.\n";
}

bool copyFile(const string &filein, const string &fileout, string &error)
{
    ifstream fin;
    ofstream fout;
    char ch;

    // Open stream to filein
    fin.open(filein.c_str());
    if (!fin)
    {
       error = "Can't open " + filein;
       return false;
    }

    // Open stream to fileout
    fout.open(fileout.c_str());
    if (!fout)
    {
       error = "Can't open " + fileout;
       fin.close();
       return false;
    }

    // process file character by character
    while (!fin.eof())
    {
       fin.get(ch);
       fout.put(ch);
    }

    // close streams
    fin.close();
    fout.close();

    return true;
}
