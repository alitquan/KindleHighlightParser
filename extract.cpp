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
        // acquire the metadata here 
        if (lineNumber == META) {
            std::cout << "META:" << line << std::endl;  

            // is the extract a highlight, bookmark, or note ? 
            std::string type_marker = "- Your "; 
            auto type_marker_start = line.find(type_marker);
            std::string type_temp = line.substr(type_marker_start+ type_marker.length());
            std::string extractType  = type_temp.substr(0,type_temp.find(" ")); 
            std::cout << "META -- Note Type: " << extractType << std::endl;



            // extract the page number range 
            std::string page_marker = "";
            auto pos = line.find("page ");
            if (pos != std::string::npos) {
                page_marker = "page ";
            } else {
                pos = line.find("location ");
                if (pos != std::string::npos) {
                    page_marker = "location ";
                }
            }

            auto pgNumber = line.find(page_marker);

            if (pgNumber != std::string::npos) {
                pgNumber += page_marker.length();

                auto pageEnd = line.find(" |", pgNumber);
                std::string page = line.substr(pgNumber, pageEnd - pgNumber);

                std::cout << page << '\n';
                std::cout << "META -- DETECTED PAGE NUMBER         : " << page<< std::endl;
            }


            auto pgDate   = line.find("Added on"); 
            auto date= line.substr(pgDate + dateMarker.size());
            std::cout << "META -- DETECTED DATE        : " << date << std::endl;

            // sample output: Monday, September 15, 2025 8:25:58 PM
            auto _token1 = date.rfind(" ");
            auto am_pm = date.substr(_token1);
            auto _token2 = date.substr(0,_token1).rfind(" "); 
            auto time_dhs = date.substr(_token2); 
            std::cout << "META -- AM/PM : " << am_pm << std::endl; 
            std::cout << "META -- HMS   : " << time_dhs << std::endl; 

            // acquire the date
        } 
        // acquire the body here 
        if (lineNumber >= BODY) {
            std::cout << "BODY:" << line << std::endl;  
        } 
        // std::cout << line << std::endl; 
        //
        //
        // create the node using the kVariables
        //
        //
        //
        //
        //
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
