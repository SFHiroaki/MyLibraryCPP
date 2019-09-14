//
//  Vector2.hpp
//
//  Created by Neko on 2019/09/07.
//

#ifndef Vector2_hpp
#define Vector2_hpp
#include <string>
#include <cmath>
using namespace std;

class Vector2{
public:
    double x;
    double y;
    Vector2(double a = 0.0,double b = 0.0) :x(a),y(b) {}
    
    Vector2 operator + (const Vector2 &A);
    Vector2 operator - (const Vector2 &A);
    Vector2 operator * (const int &A);
    template<typename T> Vector2 operator * (const T &A);
    template<typename T> Vector2 operator / (const T &A);  
    double size();
    string ToString();
    bool IsVertical(Vector2 vector);
    bool IsParallel(Vector2 vector);
    Vector2 Unit();
};

Vector2 Vector2::operator+(const Vector2 &A){
    Vector2 C;
    C.x=x+A.x;
    C.y=y+A.y;
    return C;
}

Vector2 Vector2::operator - (const Vector2 &A){
    Vector2 C;
    C.x=x-A.x;
    C.y=y-A.y;
    return C;
}

template<typename T> Vector2 Vector2::operator*(const T &A){
    Vector2 C;
    C.x=A*x;
    C.y=A*y;
    return  C;
}
template<typename T> Vector2 Vector2::operator/(const T &A){
    Vector2 C;
    C.x=x/A;
    C.y=y/A;
    return C;
}

bool Vector2::IsVertical(Vector2 vector){
    if(x*vector.x+y*vector.y==0){
        return true;
    }else{
        return false;
    }
}
bool Vector2::IsParallel(Vector2 vector){
    if(y/x==vector.y/vector.x){
        return true;
    }else{
        return false;
    }
}
double Vector2::size(){
    return sqrt(x*x + y*y);
}
Vector2 Vector2::Unit(){
    Vector2 v(x,y);
    return v/size();
}
string Vector2::ToString(){
    string S;
    S="("+to_string(x)+", "+to_string(y)+")";
    return  S;
}
#endif /* Vector2_hpp */
