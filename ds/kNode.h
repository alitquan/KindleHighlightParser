#ifndef K_NODE_H
#define K_NODE_H
#include <iostream>
#include <ctime>
#include <string> 

class kNode { 
    private: 
        kNode* next = nullptr; 
    public: 
        std::string title, timestamp, page, loc; 
        bool root; 
        // maybe add page range string representation function
        int pageEnd;
        int timeIndex; 

        std::string body;
        std::tm tm{}; 

    kNode();
    // creates a new node with a title and sets it at root 
    kNode(const std::string _title);

    const std::string toString();

    // need to integrate time
    kNode(const std::string _body, std::string _page, std::string _loc, int timeIndex, std::string timestamp);
    // set which node is the next node 
    void setNext(kNode* _next);
    // return the next node 
    kNode* getNext();
    // return the passage from within the node
    std::string getBody() const;
    // return the title of the book
    std::string getTitle() const; 
    // return entire thing
    std::string getAll() const; 
};
#endif
