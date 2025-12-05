#include "kList.h"
#include <iostream>


int main(){
    std::cout << "starting ";
    kList test("Rondillingham");
    test.insertEnd("too good too fast",100,50); 
    test.insertEnd("vamanos wey",120,43);
    test.traverseNode(); 
    test.traverseNode();
    test.traverseNode();
    return 0;
} 









