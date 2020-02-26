//circle.cpp
#include<iostream>
using namespace std;

class Point {
private:
    int x;
    int y;
public:
    Point(){
        x = 0;
        y = 0;
    };

    Point(int xx, int yy){
        x = xx;
        y = yy;
    }
    ~Point();
    virtual void display();
};

Point::~Point(){
    cout << "destructing" << "(" << x << "," << y << ")"<<endl; 
}
virtual void Point::display(){
    cout << "(" << x << "," << y << ")"<<endl; 
}
//finish babyboyyy
class ColorPoint: public Point {
    private:
        int color = c;
    public:
        ColorPoint(int xx, int yy, int zz){
            color = zz;
        }
        virtual void display();
        ColorPoint(const Point & pt) : Point(pt);
        ColorPoint& operator=(const ColorPoint& other);
};
ColorPoint::ColorPoint(const Point & pt) {
    this->color = pt.color;
}

virtual void ColorPoint::display() {
    Point::display();
    cout<< color <<endl;
}

ColorPoint::ColorPoint& operator=(const ColorPoint& other){
    color = other.color;
    return (*this)
}

class Circle {
    private:
        Point center;
        int radius;
    public:
        Circle(int xx, int yy, int r){
            Point center(xx,yy);
            int radius = r;
        }
        ~Circle();
        display();
        Circle& operator=(const Circle & pt);
        Circle(const Circle & other);
};

Circle::display(){
    cout << "Circle Center: " << center.display() << endl; 
    // cout << "Circle Center: " << this-> display() << endl;  changed methods to virtual.. would this be correct, and just use this object and display?
    cout << "Circle Radius: " << radius << end;
}
Circle::Circle& operator=(const Circle & pt){
    center = pt.center;
    radius = pt.radius;
    return *this;
}
Circle::Circle(const Circle & other){
     this->center = other.center;
     this->radius = other.radius;
     return *this;
}
Circle::~Circle(){
    cout << "destructing circle with center: " << this->display();
}
int main() {
    Point t1;
    
    Point t2(4,5);
    t2.display();
}