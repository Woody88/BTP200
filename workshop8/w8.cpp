#include <iostream>
#include "Phone.h"

const int MAX_NO = 20;

 int main() {
     int  n = 0, code, local;
     Phone phone[MAX_NO];

     std::cout << "Telephone List\n";
     std::cout << "==============\n";
     do {
         std::cout << "Area Code: ";
         std::cin >> code;
         if (code != 0) {
             std::cout << "Local No.: ";
             std::cin >> local;
             Phone temp(code, local);
             if (temp.isValid())
                 phone[n++] = temp;
         }
     } while (code != 0 && n < MAX_NO);
     std::cout << std::endl;

     for (int i = 0; i < n; i++) {
         phone[i].display();
         std::cout << std::endl;
     }
 }
