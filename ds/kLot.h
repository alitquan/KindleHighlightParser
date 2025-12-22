#ifndef K_LOT_H
#define K_LOT_H
#include <string>

class kList;
class kNode;

class kLot {

    private:
        // maybe have to change this
        kList* head=nullptr; 

    public:
        // adding a list with passages for each book. Ideally should be done alphabetically
        void addList(std::string); 
        // getting the output of quotes for each book
        void traverseList(int); 
        // helper method -- find index of kLot that contains a list for the specified book
        // first do linear then binary. Make binary a different method
        void locateList(std::string); 



    kLot(std::string title);


};

#endif
