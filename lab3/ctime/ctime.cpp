#include<iostream>
#include"ctime.h"
using namespace std;

istream& operator>>(istream& is, CTime& t) { 
        is >> t.hours>>t.minutes;
        return is;
    }

ostream& operator<<(ostream& os,const CTime& t){ //too many parameters??
    os << "\nBegin Output Function\n";
    if (t.minutes < 10 && t.minutes >= 0) {
            os<< "2-Args Constructor: "<<t.hours<<":0"<<t.minutes<<endl;
        }
        else {
            os <<"Current time is: \t"<<t.hours<<":"<<t.minutes<<"\n\n";
        }
    os << "End Output Function\n";
    return os;
}
CTime::CTime(){
        this->hours = 0;
        this->minutes = 0;
        cout << "Default Constructor: "<<hours<<":"<<minutes<<endl;
    }
CTime::CTime(int ihr, int imn){
        this->hours = ihr; 
        this->minutes = imn;
        if (this->minutes < 10 && this->minutes >= 0) {
            cout << "2-Args Constructor: "<<hours<<":0"<<minutes<<endl;
        }
        else {
            cout << "2-Args Constructor: "<<hours<<":"<<minutes<<endl;
        }

    }
CTime::~CTime() {
        cout << "Destructor: " <<hours<<":"<<minutes<<endl;
    }

CTime CTime::operator - (CTime& other) {
        CTime time;
        time.minutes = this->minutes - other.minutes;
        if (time.minutes < 0) {
            time.hours = -1; //starting the hours before. 
            time.minutes = 60+time.minutes; //adding negative minutes to 60 subtracts
        }
        time.hours -= this->hours - other.hours;
        return time;
    }
CTime CTime::operator + (CTime& other) {
        CTime time;
        time.minutes = this->minutes + other.minutes;
        if (time.minutes >= 60) {
            time.hours = 1;
            time.minutes = time.minutes%60;
        }
        time.hours += this->hours + other.hours;
        return time;
    }
void CTime::input_time(int h, int m) {
    this->hours = h;
    this->minutes = m;
}
void CTime::printTime(){
    if (this->minutes < 10) {
            cout << "2-Args Constructor: "<<this->hours<<":0"<<this->minutes<<endl;
        }
        else {
            cout << "2-Args Constructor: "<<this->hours<<":"<<this->minutes<<endl;
        }
}
void CTime::setHours(int h){
    this->hours = h;
}
void CTime::setMinutes(int m){
    this->minutes = m;
}
int CTime::getHours(){
    return this->hours;
}
int CTime::getMinutes(){
    return this->minutes;
}