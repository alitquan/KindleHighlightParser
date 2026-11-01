#include "kNode.h"
#include <string> 
// creates a new node with a title and sets it at root 
kNode::kNode(std::string _title):title(_title),root(true){}  


kNode::kNode() {
    body = "";
    type = "";
    page = "";
    type = "";
    loc = "";
    timeIndex = 0;
    timestamp = "";
    next = nullptr;
}

const std::string kNode::toString() {
    std::string retString;
    retString += "===kNode START===+"; 
    retString += "\n";
    retString += "Type: ";
    retString += type; 
    retString += "\n";
    retString += "Body: ";
    retString += body; 
    retString += "\n";
    retString += "Page: ";
    retString += page; 
    retString += "\n";
    retString += "Loc: ";
    retString += loc; 
    retString += "\n";
    retString += "Time Index: ";
    retString += std::to_string(timeIndex);
    retString += "\n";
    retString += "Timestamp: ";
    retString += timestamp; 
    retString += "\n";
    std::cout << "===kNode END ===+"; 
    return retString;
}

// need to integrate time
kNode::kNode(std::string _body, std::string _type, std::string _page, std::string _loc, int _timeIndex, std::string _timestamp) { 
    body = _body;
    type = _type;
    page = _page;
    loc  = _loc;
    timeIndex = _timeIndex;
    timestamp = _timestamp;
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

std::string kNode::getTitle() const {
    return title; 
} 

std::string kNode::getAll() const {
    std::string retString; 

    if (!title.empty()) {
        retString += title;
        retString += "\n";
    } 
    retString+=("PG " + page);
    retString+="  --- Loc ";
    retString+= loc; 
    retString+=("\n\n" + body);
    return retString; 
} 

