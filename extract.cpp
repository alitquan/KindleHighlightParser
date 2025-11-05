#include <iostream> 
#include <fstream>
#include <string> 

int createFile(std::string filename) { 
    std::string createdFile = filename + ".txt";
    std::cout << "This is my name: " << filename << std::endl;
    std::ofstream MyFile(createdFile);
    MyFile << "naruto singh";
    MyFile.close();
    return 0;
} 

int readFile(std::string filename) {
    std::string textfile = filename + ".txt";
    std::string line;;
    std::ifstream MyReadFile(textfile);

    while (getline(MyReadFile, line)) {
        std::cout << line << std::endl; 
    } 
    return 0;
} 


int main() {
    createFile("shawndaty");
    readFile("toBeRead"); 
}
