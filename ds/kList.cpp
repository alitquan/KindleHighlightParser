#include "kList.h" 
#include <iostream>
#include <string> 

// create a new list that represent entries of a book
kList::kList(std::string title): head(new kNode(title)),tail(head),current(head){}

void kList::insertEnd(std::string _body, int _page, int _loc) {
    kNode* newNode = new kNode(_body, _page, _loc); 
    tail->setNext(newNode);
    tail = newNode; 
}

void kList::currentMove() {
    std::string _body = current->getBody(); 
    current = current ->getNext(); 
    std::cout << _body << std::endl; 
} 

void kList::traverseNode() {
    std::string HEADER = "======="; 
    std::string _output = current->getAll(); 
    current = current ->getNext(); 
    std::cout << HEADER << std::endl << _output << std::endl << std::endl; 
} 

kList::~kList() {
    kNode* current = head; 
    while (current != nullptr) {
        kNode* nextNode = current->getNext();
        delete current; 
        current = nextNode;
    } 
} 

