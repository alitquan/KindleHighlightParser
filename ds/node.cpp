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
    kNode(std::string _title):title(_title),root(true){}  

    // need to integrate time
    kNode(std::string _body, int _page, int _loc) { 
        body = _body;
        page = _page;
        loc  = _loc;
        next = nullptr; 
        root = false;
    } 

    void setNext(kNode* _next) {
        next = _next; 
    }

    kNode* getNext() {
        return next; 
    } 

    std::string getBody() {
        return body;
    }
};


class kList {
    private:
        kNode* head;
        kNode* tail;
        kNode* current;
    
    public: 
        // create a new list that represent entries of a book
        kList(std::string title): head(new kNode(title)),tail(head),current(head){}

        void insertEnd(std::string _body, int _page, int _loc) {
            kNode* newNode = new kNode(_body, _page, _loc); 
            tail->setNext(newNode);
            tail = newNode; 
        }
        
        void currentMove() {
            std::string _body = current->getBody(); 
            current = current ->getNext(); 
            std::cout << _body; 
        } 


        ~kList() {
            kNode* current = head; 
            while (current != nullptr) {
                kNode* nextNode = current->getNext();
                delete current; 
                current = nextNode;
            } 
        } 

};


int main(){
    std::cout << "starting ";
    kList test("Rondillingham");
    test.insertEnd("too good too fast",100,50); 
    test.currentMove(); 
    test.currentMove();
    return 0;
} 









