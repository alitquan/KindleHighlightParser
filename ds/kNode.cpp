#include "kNode.h"
#include <string> 
// creates a new node with a title and sets it at root 
kNode::kNode(std::string _title):title(_title),root(true){}  

// need to integrate time
kNode::kNode(std::string _body, int _page, int _loc) { 
    body = _body;
    page = _page;
    loc  = _loc;
    next = nullptr; 
    root = false;
} 

void kNode::setNext(kNode* _next) {
    next = _next; 
}

kNode* kNode::getNext() {
    return next; 
} 

std::string kNode::getBody() const {
    return body;
}

std::string kNode::getAll() const {
    std::string retString; 

    if (!title.empty()) {
        retString += title;
        retString += "\n";
    } 
    retString+=("PG " + std::to_string(page));
    retString+="  --- Loc ";
    retString+= std::to_string(loc); 
    retString+=("\n\n" + body);
    return retString; 
} 

