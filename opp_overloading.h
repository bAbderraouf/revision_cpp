#pragma once
    
#include <iostream>

// class definition :

class Point{
    private :
    int x, y;
    
    public : 
    Point(int x=0, int y=0) {
        this->x = x;
        this->y = y;
        // constructor
    }
    
    // getters 
    int get_x() const{
        return this->x;
    }
    int get_y() const{
        return this->y;
    }
    
    //---------------------------------------------------
    // operators

    // addition
    Point operator+(const Point & other) const {
        return Point(x + other.x , y+ other.y ); // une clase du mm type peut acceder aux membres privés
    }
        
    // soustraction
    Point operator-(const Point & other) const {
        return Point(x - other.x , y- other.y ); 
    }
    
    // pproduit scalaire element par element
    Point operator*(const Point & other) const {
        return Point(x * other.x , y* other.y ); 
    }
    
    // comparaison ==
    bool operator==(const Point & other) const {
        return (x == other.x && y==other.y ); 
    }
    
    // Incrémentation préfixée ++p
    Point& operator++() {
        ++x; ++y;
        return *this;
    }

    // in case we want to declare << opeartor here we should use frien std::ostream&
        
};


// affichage << operator
std::ostream& operator<<(std::ostream & co , const Point &p ) {
    co << "(" << p.get_x() << ", "<< p.get_y() << ").";
    return co;
}