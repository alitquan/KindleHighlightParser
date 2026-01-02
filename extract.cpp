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
    std::string pageMarker= "page";
    std::string dateMarker= "Added on";
    std::string line;
    std::string kTitle, kPage, kBody, kLoc; 
    // need kDate 
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
            kTitle = line; 
        } 
        // acquire the title here 
        if (lineNumber == META) {
            std::cout << "META:" << line << std::endl;  
            auto pgNumber = line.find("page"); 

            // adding 5 because 'page' takes up 4 chars. There is also white space before page number
            // "page 65" 
            pgNumber += 5;

            std::cout << "META -- DETECTED PAGE NUMBER         : " << pgNumber << std::endl;
            std::cout << "META -- DETECTED PAGE NUMBER (charAt): " << line[pgNumber]<< std::endl;



            auto pgDate   = line.find("Added on"); 
            std::cout << "META -- DETECTED DATE        : " << pgDate << std::endl;

            // search through the line for page numbers and locations
            // loc might be available for non=pdfs
            // acquire the page number
            std::string pgSubString = line.substr(pgNumber,pgDate); 
            int pgNumberEnd = line.find(" ");
            std::cout << "Page substring: " << pgSubString << std::endl;
            int pgNum      = std::stoi(pgSubString.substr(0,pgNumberEnd+1));
            std::cout << "Page number: " << pgNum << std::endl;
            
            // acquire the date
        } 
        // acquire the body here 
        if (lineNumber == BODY) {
            std::cout << "BODY:" << line << std::endl;  
        } 
        // std::cout << line << std::endl; 
        //
        //
        // create the node using the kVariables
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
