#include <iostream> 
#include <fstream>
#include <string> 
#include <vector>
#include "cli.h"


// constants
std::string helpList = "    - ";

cli::cli(AppInterface* target) {
    interface = target;
}

//helpers 
std::vector<std::string> tokenize (std::string cli_input) {
    int current = 0;
    int counter = 0;
    std::vector<char> word_buffer; 
    std::vector<std::string> retVal;
    bool quote = false; 

    for (int i = 0; i < cli_input.length(); i++) {
        char _char = cli_input[i]; 

        if (_char == '"') {
            quote = !quote;
            continue;
        }

        if (quote == false && (_char == ' ' || _char == '\n')) { 

            if (!word_buffer.empty()) { 
                std::string token;

                for (int j = 0; j < word_buffer.size(); j++) {
                    token += word_buffer[j];
                }
                retVal.push_back(token); 
                word_buffer.clear();
            }
        } 

        else {
            word_buffer.push_back(_char);
        } 
    } 


    if (!word_buffer.empty()) {
        std::string token;

        for (int j = 0; j < word_buffer.size(); j++) {
            token += word_buffer[j];
        }

        retVal.push_back(token);
    }

    // debugging 
    for (int token= 0; token < retVal.size(); token++) {
        std::cout <<token<< std::endl;
        std::cout << retVal [token]<< std::endl;
    }
    return retVal;
}

int cli::runcli() {
    std::string command;
    while (true) {
        std::cout << "KINDLE #> ";

        if (!std::getline(std::cin, command)) {
            break;
        }

        std::vector<std::string> tokens = tokenize(command);

        if (tokens.empty()) {
            continue;
        } 

        std::string root_command = tokens[0];


        if (command == "exit") {
            break;
        }
        if (root_command == "list") {
            if (tokens.size() < 2 ) {
                std::cout <<"available options: " << std::endl; 
                std::cout << helpList << "lot" << std::endl;
                std::cout << helpList << "lots" << std::endl;
                std::cout << helpList << "list" << std::endl;
            }
            else {
                std::string firstArg = tokens[1];
                if (firstArg == "lot" || firstArg == "lots") {
                    interface->listLot();
                }
                else if (firstArg == "list") {
                    std::cout << "Gettin current list: " << std::endl;
                    std::cout << (interface->getCurrentList()) << std::endl;
                }
                else {
                    std::cout << "see runcli -- firstArg == list" << std::endl; 

                } 


            }
        }
        if (root_command == "set") { 
            if (tokens.size() < 2 ){
                std::cout <<"available options: " << std::endl; 
                std::cout << helpList << "lot" << std::endl;
                std::cout << helpList << "lots" << std::endl;
                std::cout << helpList << "list" << std::endl;
            }
            else {
                std::string firstArg = tokens[1];
                if (firstArg == "list") {
                    if (tokens.size() < 3 ){
                        std::cout <<"You need more args " << std::endl; 
                        continue;
                        
                    }
                    std::string selectedList = tokens[2];
                    interface->loadList(selectedList);
                }
            }
        } 
        if (command == "help" || command == "?") {
            helpCli();
        } 

    }

    return 0;
}


void cli::helpCli() {
    std::cout << "\n========= AVAILABLE COMMANDS ===========\n";
    std::cout <<"  help | ?   : show help commands\n\n\n"; 
}
