#include "kList.h"
#include <iostream>


void test1() { 
    std::cout << "starting ";
    kList test("Rondillingham");
    test.insertEnd("too good too fast",100,50); 
    test.insertEnd("vamanos wey",120,43);
    test.traverseNode(); 
    test.traverseNode();
    test.traverseNode();
}

int main(){
    test1();
    return 0;
} 









