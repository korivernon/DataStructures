#include<iostream>
#include"ctime.h"

int main() {
    std::cout << "Start of the main function:"<<std::endl;

    CTime t1;
    CTime t2(2, 25);
    t1.input_time(5,10);
    t1.printTime();
    t1.setHours(7);
    t1.setMinutes(50);
    t1.getHours();
    t1.getMinutes();
    std::cout <<"Printing Time: \t";
    t1.printTime();
    std::cout <<t1;

    std::cin>>t1;

    CTime t3 = t1 + t2;
    CTime t4 = t2 - t1;
    
    std::cout << "Cumulated time: "<<t3;
    std::cout << "Time difference: "<<t4;

    std::cout << "End of the main function:"<<std::endl;

    CTime t5(3,4);

    CTime ctarr[5] = {t1,t2,t3,t4,t5};

    for(int i=0;i<5;i++) {
        std::cout << "~~~~~~~ctarr["<<i+1<<"]" << ctarr[i];
    }
}