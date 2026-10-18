#include "kUtil.h"
#include <iostream> 
#include <string> 
#include <algorithm>
constexpr int BASE_YEAR = 2015;
constexpr int MINUTES_PER_YEAR = 535680;
constexpr int MINUTES_PER_HOUR = 60;
constexpr int MINUTES_PER_DAY = 1440;

// std::string rmDayFromDate() {
//     const char* current = str.data();
//     std::string copy = str;

//     while (*current != ' ') {
//         current++;
//     }
    
//     std::string retVal = copy.erase(0, current - str.data() + 1);
//     std::cout << "This is removed: " << retVal << std::endl;
//     return retVal;
// }

std::string rmDayFromDate(const std::string& str) {
    const char* current = str.data();
    std::string copy = str;

    // remove
    std::cout << "rmDayFromDate Base:" << str << std::endl;

    while (*current != '\0' && *current != ' ') {
        //std::cout << "rmDayFromDate: " << *current; 
        current++;
    }

    if (*current == ' ') {
        copy.erase(0, current - str.data() + 1);
    }

    std::cout << "This is removed: " << copy << std::endl;

    return copy;
}


// September 15, 2025 8:25:58 PM
int dateToIndex(const std::string& date) {
    const char* dateChar = date.data();

    std::string month = "";
    std::string day   = ""; 
    std::string year = ""; 

    int month_val = 0;
    int day_val = 0; 
    int year_val = 0; 

    // get month 
    while (*dateChar != '\0' && *dateChar != ' ') {
        month += *dateChar;
        dateChar++; 
    }

    if (month == "January") {
        month_val = 1;
    } else if (month == "February") {
        month_val = 2;
    } else if (month == "March") {
        month_val = 3;
    } else if (month == "April") {
        month_val = 4;
    } else if (month == "May") {
        month_val = 5;
    } else if (month == "June") {
        month_val = 6;
    } else if (month == "July") {
        month_val = 7;
    } else if (month == "August") {
        month_val = 8;
    } else if (month == "September") {
        month_val = 9;
    } else if (month == "October") {
        month_val = 10;
    } else if (month == "November") {
        month_val = 11;
    } else if (month == "December") {
        month_val = 12;
    } else {
        return -1;
    }

    // Skip the space after the month
    if (*dateChar == ' ') {
        dateChar++;
    }

    // Extract the day
    while (*dateChar != '\0' && *dateChar != ',') {
        day += *dateChar;
        dateChar++;
    }

    day_val = std::stoi(day);

    // Skip the comma and space after the day  
    if (*dateChar == ',') {
        dateChar++;
    }
    if (*dateChar == ' ') {
        dateChar++;
    }

    // Extract the day
    while (*dateChar != '\0' && *dateChar != ',') {
        year+= *dateChar;
        dateChar++;
    }
    year_val = std::stoi(year);


    auto token1 = date.rfind(' ');
    auto am_pm = date.substr(token1 + 1);

    auto token2 = date.rfind(' ', token1 - 1);
    auto time_dhs = date.substr(token2 + 1, token1 - token2 - 1);



    // index encoding 
    int mdy_index = MINUTES_PER_YEAR * (year_val - BASE_YEAR); 
    mdy_index += (month_val * MINUTES_PER_DAY * 31); 
    mdy_index += (day_val * MINUTES_PER_DAY); 
    int index = mdy_index; 

    if (am_pm == "PM") {
        index += MINUTES_PER_DAY / 2;
        std::cout <<"kUtil -- PM detected" << std::endl;
    }
    else { 
        std::cout <<"kUtil -- AM detected" << std::endl;
    } 

    // end goal: 8:28:30 --> 82830
    std::string time = date.substr(token2 + 1, token1 - token2 - 1);
    // Remove colons
    time.erase(std::remove(time.begin(), time.end(), ':'), time.end());
    // Convert to integer
    int time_val = std::stoi(time);
    index += time_val;


    return index;  
}


    












