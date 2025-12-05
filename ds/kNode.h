#ifndef K_NODE_H
#define K_NODE_H
#include <iostream>
#include <ctime>
#include <string> 

class kNode { 
    private: 
        kNode* next = nullptr; 
    public: 
        std::string title; 
        bool root; 
        int page;
        int loc; 
        std::string body;
        std::tm tm{}; 

    // creates a new node with a title and sets it at root 
    kNode(const std::string _title);
    // need to integrate time
    kNode(const std::string _body, int _page, int _loc);
    // set which node is the next node 
    void setNext(kNode* _next);
    // return the next node 
    kNode* getNext();
    // return the passage from within the node
    std::string getBody() const;
    // return entire thing
    std::string getAll() const; 
};
#endif
