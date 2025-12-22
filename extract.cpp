#include <iostream> 
#include <fstream>
#include <string> 

int createFile(std::string filename) { 
    std::cout << "This is my name: " << filename << std::endl;
    std::ofstream MyFile(filename);
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
    std::string line;;
    std::ifstream MyReadFile(filename);

    while (getline(MyReadFile, line)) {
        if (line.compare(linebreak)==0) {
            std::cout << lineNumber << " -- Line Detected -- " << std::endl; 
            std::cout << lineNumber << "  " << line << std::endl;
            lineNumber = 0;
        }
        else {
            lineNumber++;
        }

        // acquire the title here 
        if (lineNumber == TITLE) {
            std::cout << "TITLE :" << line << std::endl;  
        } 
        // acquire the title here 
        if (lineNumber == META) {
            std::cout << "META:" << line << std::endl;  
        } 
        // std::cout << line << std::endl; 
    } 
    return 0;
} 

int test1() {
    createFile("shawndaty.txt");
    readFile("shawndaty.txt"); 
    return 0;
}

int test2() {
    readFile("sample.txt");
    return 0;

} 

int main() {
    test2();
}
