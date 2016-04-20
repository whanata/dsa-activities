#include <iostream>

const int NUMDISK = 3;

class peg
{
   private:
      int disks[NUMDISK];
      int numDisks;

      void pushDisk(int diskVal)
      {
         disks[numDisks] = diskVal;
         numDisks++;
      }

      int popDisk()
      {
         numDisks--;
         return disks[numDisks];
      }
      
   public:
      peg(bool fill)
      {
         if (fill)
         {
            for (int i=0; i<NUMDISK; i++) disks[i] = NUMDISK-i;
            numDisks = NUMDISK;
         }
         else
         {
            numDisks = 0;
         }
      }

      void printDisks()
      {
         std::cout << '#';
         for (int i=0; i<numDisks; i++) std::cout << disks[i];
         std::cout << '\n';
      }

      void moveTopDisk(peg* &destPeg)
      {
         int diskVal = popDisk();
         destPeg->pushDisk(diskVal);
      }
};

class towers
{
   private:
      peg *pegA, *pegB, *pegC;

      void solveTowers(int num, peg* &sourcePeg, peg* &destPeg, peg* &sparePeg)
      {
         if (num > 0)
         {
            // move the first num-1 disks from source peg to spare peg
            solveTowers(num - 1, sourcePeg, sparePeg, destPeg);
            // move final disk from source peg to destination peg
            sourcePeg->moveTopDisk(destPeg);
            // print the results after the move
            printTowers();
            // move top num-1 disks from spare peg to destination peg
            solveTowers(num - 1, sparePeg, destPeg, sourcePeg);
         }
      }

   public:
      towers()
      {
         pegA = new peg(true);
         pegB = new peg(false);
         pegC = new peg(false);
      }

      void printTowers()
      {
         pegA->printDisks();
         pegB->printDisks();
         pegC->printDisks();
         std::cout << '\n';
      }

      void solveTowers()
      {
         solveTowers(NUMDISK, pegA, pegC, pegB);
      }
};

int main()
{
   towers hanoi;

   hanoi.printTowers();
   hanoi.solveTowers();

   return 0;
}
