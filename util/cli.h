#ifndef CLI_H
#define CLI_H
#include <iostream> 
#include <fstream>
#include <string> 
#include "../AppInterface.h"

class cli {
    

    private:
        AppInterface* interface;
        void helpCli();

    public:
        cli(AppInterface* target); 
        int runcli();

};
#endif

