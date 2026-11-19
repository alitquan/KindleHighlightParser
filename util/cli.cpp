#include <iostream> 
#include <fstream>
#include <string> 
#include <vector>
#include "cli.h"

//helpers 
std::vector<std::string> tokenize (std::string cli_input) {
    std::cout << "Debugging -- tokenize()" << std::endl; 

    int current = 0;
    int counter = 0;
    std::vector<char> word_buffer; 
    std::vector<std::string> retVal;

    for (int i = 0; i < cli_input.length(); i++) {
        char _char = cli_input[i]; 
        if (_char == ' ' || _char == '\n') { 
            std::string token;

            for (int j = 0; j < word_buffer.size(); j++) {
                token += word_buffer[j];
            }
            retVal.push_back(token); 
            word_buffer.clear();
        } 

        else {
            word_buffer.push_back(_char);
        } 
    } 
    for (int token= 0; token < retVal.size(); token++) {
        std::cout <<token<< std::endl;
        std::cout << retVal [token]<< std::endl;
    }

    if (!word_buffer.empty()) {
        std::string token;

        for (int j = 0; j < word_buffer.size(); j++) {
            token += word_buffer[j];
        }

        retVal.push_back(token);
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

        std::string actual_command = tokens[0];


        if (command == "exit") {
            break;
        }
        if (actual_command == "list") {
            std::cout << "LIST command input";
            if (tokens.size() < 2 ) {
                std::cout <<"available options: " << std::endl; 
                std::cout << "lot" << std::endl;
                std::cout << "lots" << std::endl;
            }
        }
        if (command == "help" || command == "?") {
            helpCli();
        } 

        tokenize(command);
    }

    return 0;
}


void cli::helpCli() {
    std::cout << "\n========= AVAILABLE COMMANDS ===========\n";
    std::cout <<"  help | ?   : show help commands\n\n\n"; 
}
