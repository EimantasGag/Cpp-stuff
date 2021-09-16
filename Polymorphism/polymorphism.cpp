#include <iostream>

using namespace std;

struct Shape{

    //reikia prideti virtual jeigu sia base klase naudosi in polymorphic way
    virtual ~Shape(){
        cout << "Shape destructor is called" << endl;
    }

    void rotate(){
        cout << "Shape is rotating";
    }
};

struct Triangle : Shape{
    int corners = 3;

    ~Triangle(){
        cout << "Triangle destructor is called" << endl;
    }

    int getCorners(){
        return corners;
    }
};

int main(){
    Shape* triangle = new Triangle();
    //triangle.getCorners() NEVEIKIA!
    delete triangle;
}