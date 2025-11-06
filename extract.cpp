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
    int lineNumber = 0;
    // offset variables (assume that line break is index 0) 
    int TITLE = 1; 
    int META  = 2; 
    int BODY  = 4; 
    // 3 is missing since 3rd line after line break is typically empty space

    std::string linebreak = "==========";
    std::string textfile = filename + ".txt";
    std::string line;;
    std::ifstream MyReadFile(textfile);

    while (getline(MyReadFile, line)) {
        if (line.compare(linebreak)) {
            std::cout << "Line Detected" << endl; 
        }
        std::cout << line << std::endl; 
    } 
    return 0;
} 


int main() {
    createFile("shawndaty");
    readFile("shawndaty"); 
}
