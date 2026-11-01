#ifndef K_LIST_H
#define K_LIST_H

#include "kNode.h"

class kList {
    private:
        kNode* head;
        kNode* tail;
        kNode* current;
    
    public: 
        // create the root node of the book's annotation list
        kList(const std::string title);
        // create a node based on the arguments and insert at the end of the list 
        void insertEnd(std::string _body, std::string _type, std::string _page, std::string _loc, int timeIndex, std::string timestamp);
        std::string returnTitle();
        void currentMove();
        void traverseNode();
        void printContents();
        ~kList();
};
#endif 
