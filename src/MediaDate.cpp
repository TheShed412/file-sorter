#include "MediaDate.hpp"
#include "StringUtils.hpp"
#include <iostream> 
#include <sstream>

MediaDate::MediaDate(){}

MediaDate::MediaDate(string dateString) {
    vector<string> dateAndTimeStrs = splitOnDelimeter(dateString, " ");
    vector<string> dateValues = splitOnDelimeter(dateAndTimeStrs.at(1), "-");
    vector<string> timeValues = splitOnDelimeter(dateAndTimeStrs.at(2), ":");
    this->dateString = dateValues.at(0) + "_" + dateValues.at(1) + "_" + dateValues.at(2) + "_";

    vector<int> dateParts;
    for (string datePartStr : dateValues) {
        stringstream partStream(datePartStr);
        int datePartInt;
        partStream >> datePartInt;
        dateParts.push_back(datePartInt); 
    }
    vector<int> timeParts;
    for (string timePartStr : timeValues) {
        stringstream partStream(timePartStr);
        int timePartInt;
        partStream >> timePartInt;
        timeParts.push_back(timePartInt); 
    }
    
    year    = dateParts.at(0);
    month   = dateParts.at(1);
    day     = dateParts.at(2);

    hour    = timeParts.at(0);
    min     = timeParts.at(1);
    sec     = timeParts.at(2);
}

int MediaDate::GetDay() {
    return day;
}

int MediaDate::GetMonth() {
    return month;
}

int MediaDate::GetYear() {
    return year;
}

int MediaDate::GetHour() {
    return hour;
}

int MediaDate::GetMinutes() {
    return min;
}

int MediaDate::GetSeconds() {
    return sec;
}

string MediaDate::GetDateString() {
    return dateString;
}

