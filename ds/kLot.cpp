#include "kList.h"
#include "kLot.h"


kLot::kLot(std::string title) {
    id = title;
} 

bool kLot::addList(std::string title) {

    for (kList* book_list : klists) {
        if (book_list->returnTitle() == title) {
            std::cout << "Title Already Exists" << std::endl;
            return false; 
        } 
    } 

    kList* new_list = new kList(title);
    klists.push_back(new_list);
    numTitles++;

    return true;
}

// diagnostic
void kLot::printTitles() { 
    std::cout << std::endl; 
    std::cout << "----getBooks()---" << std::endl; 
    std::cout << "----count()--->" << numTitles << std::endl; 
    for (kList* book_list : klists) {
        std::cout << "getBooks(): " << book_list->returnTitle() << std::endl; 
    }
    std::cout << std::endl; 
} 

void kLot::printLists() {
    for (kList* book_list : klists) {
        book_list->printContents();
    }
} 

kLot::~kLot() {
    for (kList* book_list : klists) {
        delete book_list;
    }
}

