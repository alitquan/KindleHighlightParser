#include <iostream> 
#include <fstream>
#include <string> 
#include "cli.h"

int cli::runcli() {
    std::string command;
    while (true) {
        std::cout << "KINDLE #> ";

        if (!std::getline(std::cin, command)) {
            break;
        }

        if (command == "exit") {
            break;
        }

        if (command == "help" || command == "?") {
            helpCli();
        } 



        std::cout << "Command: " << command << '\n';
    }

    return 0;
}


void cli::helpCli() {
    std::cout << "\n========= AVAILABLE COMMANDS ===========\n";
    std::cout <<"  help | ?   : show help commands\n\n\n"; 
}
