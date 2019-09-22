#ifndef MED_DATE
#define MED_DATE

#include <string>

using namespace std;

class MediaDate {
    private:
        string dateString;
        int sec;
        int min;
        int hour;
        int day;
        int month;
        int year;
    public:
        MediaDate();
        MediaDate(string dateString);
        int GetSeconds();
        int GetMinutes();
        int GetDay();
        int GetMonth();
        int GetYear();
        int GetHour();
        string GetDateString();
};

#endif