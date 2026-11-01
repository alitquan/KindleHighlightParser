#include "kList.h" 
#include <iostream>
#include <string> 

// create a new list that represent entries of a book
kList::kList(std::string title): head(new kNode(title)),tail(head),current(head){}

void kList::insertEnd(std::string _body, std::string _type, std::string _page, std::string _loc, int _timeIndex, std::string _timestamp) {
    kNode* newNode = new kNode(_body, _page, _type, _loc, _timeIndex, _timestamp); 
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

void kList::printContents(){ 
    std::cout << "----kList::printContents()----" << std::endl;
    std::cout << "-----current book: " << returnTitle() << std::endl;
    kNode* temp = head;
    while(temp != nullptr) {
        std::cout << std::endl;
        std::cout << temp->getAll() << std::endl; 
        std::cout << std::endl;
        temp = temp->getNext();
    }
    std::cout << "----kList::printContents() DONE ----" << std::endl;

} 

std::string kList::returnTitle() {
    return head->getTitle();
}

kList::~kList() {
    kNode* current = head; 
    while (current != nullptr) {
        kNode* nextNode = current->getNext();
        delete current; 
        current = nextNode;
    } 
} 

