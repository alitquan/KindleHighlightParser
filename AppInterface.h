#ifndef APPINTERFACE_H
#define APPINTERFACE_H

#include "ds/kLot.h"
#include "ds/kList.h"
#include "ds/kNode.h"
#include <vector>  

class AppInterface {

    private: 
        std::vector<kLot*> collections; 
        kLot* currentLot;
        kList* currentList;


    public:
        void listLot();
        std::string getCurrentList();
        void addLot(kLot* new_lot);
        kLot* loadLot(std::string id);
        kList* loadList(std::string id);
        std::vector<kNode*> sortList(std::string id);

};
#endif 
