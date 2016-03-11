#include <string.h> 
   
const int STRINGSIZE = 20; 

const char* getSubString(int index, const char *string); 

const char* getSubString(int index, const char *string) 
{ 
   // Line 10. will NOT compile this line 
   string[0] = 'x'; 
   
   // Line 12. will compile this line 
   return &string[index]; 
} 

int main() 
{ 
   char string[STRINGSIZE]; 
   const char* cptr; 
   
   strcpy(string, "something"); 
   
   // Line 24. will compile this line 
   cptr = getSubString(4, string); 
   
   // Line 27. will NOT compile this line 
   cptr[4] = 'k'; 
   
   return 0; 
} 