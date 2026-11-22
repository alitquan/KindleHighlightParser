#include "AppInterface.h"
#include "ds/kLot.h"
#include <string>

void AppInterface::addLot(kLot* new_lot) {
    collections.push_back(new_lot);
} 

void AppInterface::listLot() {
    for (kLot* lot: collections) {
        lot->listData();
    }
} 

std::string AppInterface::getCurrentList() {
    return currentList->returnTitle(); 
} 

kList* AppInterface::loadList(std::string targetList) {
    currentList = currentLot->getList(targetList);
    return currentList;
}

kLot* AppInterface::loadLot(std::string id) {
    kLot* retVal;
    for (kLot* lot: collections) {
        if (lot->checkID(id)) {
            retVal = lot;
            return retVal;
        }
    }
    return retVal;
} 


