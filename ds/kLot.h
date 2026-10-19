#ifndef K_LOT_H
#define K_LOT_H
#include <string>
#include <vector> 
#include "kList.h" 
#include "kNode.h" 
class kList;
class kNode;

class kLot {

    private:
        // maybe have to change this
        std::vector<kList*> klists;
        // maybe could be timestamp
        std::string id;

        // useful for debugging 
        int numTitles = 0;

    public:
        // tbd 
        void loadData();

        // adding a list with passages for each book. Ideally should be done alphabetically
        bool addList(std::string); 
        // getting the output of quotes for each book
        void traverseList(int); 
        // helper method -- find index of kLot that contains a list for the specified book
        // first do linear then binary. Make binary a different method
        void locateList(std::string); 
        void printTitles();
        void printLists();
        kLot(std::string title);
        ~kLot();

};

#endif
