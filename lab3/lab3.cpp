#include <iostream>
#include <vector>
using namespace std;

class CTime {
    int hours;
    int minutes;
 public:
    CTime(){
        this->hours = 0;
        this->minutes = 0;
        cout << "Default Constructor: "<<hours<<":"<<minutes<<endl;
    }
    CTime(int ihr, int imn){
        this->hours = ihr; 
        this->minutes = imn;
        if (this->minutes < 10 && this->minutes >= 0) {
            cout << "2-Args Constructor: "<<hours<<":0"<<minutes<<endl;
        }
        else {
            cout << "2-Args Constructor: "<<hours<<":"<<minutes<<endl;
        }

    }
    ~CTime() {
        cout << "Destructor: " <<hours<<":"<<minutes<<endl;
    }
    void input_time(int h, int m);
    void printTime();
    void setHours(int h);
    void setMinutes(int m);
    int getHours();
    int getMinutes();

    CTime operator - (CTime& other) {
        CTime time;
        time.minutes = this->minutes - other.minutes;
        if (time.minutes < 0) {
            time.hours = -1; //starting the hours before. 
            time.minutes = 60+time.minutes; //adding negative minutes to 60 subtracts
        }
        time.hours -= this->hours - other.hours;
        return time;
    }

    CTime operator + (CTime& other) {
        CTime time;
        time.minutes = this->minutes + other.minutes;
        if (time.minutes >= 60) {
            time.hours = 1;
            time.minutes = time.minutes%60;
        }
        time.hours += this->hours + other.hours;
        return time;
    }
    friend ostream& operator<<(ostream& os,const CTime& t);
    
    friend istream& operator>>(istream& is, CTime& t);
    
    
};

istream& operator>>(istream& is, CTime& t) { 
        is >> t.hours;
        is >> t.minutes;
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

int main() {
    cout << "Start of the main function:"<<endl;

    CTime t1;
    CTime t2(2, 25);
    t1.input_time(5,10);
    t1.printTime();
    t1.setHours(7);
    t1.setMinutes(50);
    t1.getHours();
    t1.getMinutes();
    cout <<"Printing Time: \t";
    t1.printTime();
    cout <<t1;

    cin>>t1;

    CTime t3 = t1 + t2;
    CTime t4 = t2 - t1;
    
    cout << "Cumulated time: "<<t3;
    cout << "Time difference: "<<t4;

    cout << "End of the main function:"<<endl;

    CTime t5(3,4);

    CTime ctarr[5] = {t1,t2,t3,t4,t5};

    for(int i=0;i<5;i++) {
        cout << "~~~~~~~ctarr["<<i+1<<"]" << ctarr[i];
    }
}