#include <iostream>

#include "vector.h"

using namespace std;

void needConst(const vectorspc::vector<int> &intvec)
{
   cout << intvec[0] << "\n";
}

void dontNeedConst(vectorspc::vector <int> &intvec)
{
   intvec[0] = 10;
}

int main()
{
   vectorspc::vector<int> intvec;

   intvec.push_back(1);

   dontNeedConst(intvec);
   needConst(intvec);

   return 0;
}
