#include "kList.h" 
#include <iostream>
#include <string> 

// create a new list that represent entries of a book
kList::kList(std::string _title): 
    head(new kNode(_title)),
    tail(head),
    current(head){
        title = _title;
    }

// void kList::insertEnd(std::string _body, std::string _type, std::string _page, std::string _loc, int _timeIndex, std::string _timestamp) {
//     kNode* newNode = new kNode(_body, _page, _type, _loc, _timeIndex, _timestamp); 
//     tail->setNext(newNode);
//     tail = newNode; 
// }
void kList::insertEnd(
    std::string _body,
    std::string _type,
    std::string _page,
    std::string _loc,
    int _timeIndex,
    std::string _timestamp
) {
    std::cout << "\n=== INSERT DEBUG ===" << std::endl;
    std::cout << "List address: " << this << std::endl;
    std::cout << "Old tail: " << tail << std::endl;
    std::cout << "Body: " << _body << std::endl;

    kNode* newNode = new kNode(
        _body, _type, _page, _loc, _timeIndex, _timestamp
    );

    std::cout << "New node: " << newNode << std::endl;

    tail->setNext(newNode);
    tail = newNode;

    std::cout << "Updated tail: " << tail << std::endl;
    std::cout << "=== INSERT COMPLETE ===\n" << std::endl;
}

void kList::currentMove() {
    std::string _body = current->getBody(); 
    current = current ->getNext(); 
    std::cout << _body << std::endl; 
} 

void kList::traverseNode() {
    if (current == nullptr) {
        return;
    }
    std::string HEADER = "======="; 
    std::string _output = current->getAll(); 
    current = current ->getNext(); 
    std::cout << HEADER << std::endl << _output << std::endl << std::endl; 
} 

void kList::printContents(){ 
    std::cout << "\n=== TRAVERSAL DEBUG ===" << std::endl;
    std::cout << "List address: " << this << std::endl;
    std::cout << "Head: " << head << std::endl;
    std::cout << "Tail: " << tail << std::endl;

    kNode* temp = head;
    int index = 0;

    while (temp != nullptr) {
        std::cout << "\nNODE " << index << std::endl;
        std::cout << "Address: " << temp << std::endl;
        std::cout << "Next: " << temp->getNext() << std::endl;
        std::cout << "Contents:\n" << temp->toString() << std::endl;

        temp = temp->getNext();
        index++;
    }

    std::cout << "\nTOTAL NODES: " << index << std::endl;
    std::cout << "=== TRAVERSAL COMPLETE ===" << std::endl;
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

