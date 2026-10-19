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
    return true;

}


kLot::~kLot() {
    for (kList* book_list : klists) {
        delete book_list;
    }
}

