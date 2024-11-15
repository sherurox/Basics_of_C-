/*

Entry Controlled loop

  do while



        Syntax:
         do
         {
            code;
         }
         while(condition);


*/


#include <iostream>
using namespace std;

int main() {
    // Exit controlled loop using 'do-while' loop
    int i = 1;
    do {
        cout <<i<< " Hello, World!" << endl;
        i++;
    } while (i <= 10);
    return 0;
}
