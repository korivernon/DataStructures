#ifndef ctime_H
#define ctime_H

using namespace std;

class CTime {
    int hours;
    int minutes;
 public:
    CTime();
    CTime(int ihr, int imn);
    ~CTime();
    void input_time(int h, int m);
    void printTime();
    void setHours(int h);
    void setMinutes(int m);
    int getHours();
    int getMinutes();

    CTime operator - (CTime& other);
    CTime operator + (CTime& other);

    friend ostream& operator<<(ostream& os,const CTime& t);
    friend istream& operator>>(istream& is, CTime& t);
};
#endif