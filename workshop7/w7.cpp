// Workshop 7 - Price List
 // w7.cpp
#include <iostream>
#include "Item.h"

 const int MAX_NO = 10;

 int main() {
     int n = 0;
     int price = 0;
     bool quit = false;
     Item item[MAX_NO];

     std::cout << "Price List\n";
     std::cout << "==========\n";
     do {
         std::cin >> item[n];
         if (item[n].empty()){
             quit = true;
         }    
         else{
             n++;
         }
     } while (!quit && n < MAX_NO);
     std::cout << std::endl;
     if (!item[0].empty()) item[0] = 45.33;

     std::cout << "  Number     Price\n";
     std::cout << "------------------\n";


     for (int i = 0; i < n; i++)
         std::cout << item[i] << std::endl;
 }