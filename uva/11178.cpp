/*************************************************************************
	> File Name: UVA11178.cpp
	> Author: jusonalien
	> Mail: jusonalien@qq.com
	> Created Time: 2014年11月20日 星期四 16时29分59秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;
struct Point{
    double x,y;
    Point(double x = 0,double y = 0):x(x),y(y) {  }
};
typedef Point Vector;
Vector operator + (Vector A,Vector B) {
    return Vector(A.x + B.x,A.y + B.y);
}
Vector operator - (Vector A,Vector B) {
    return Vector(A.x - B.x,A.y - B.y);
}
Vector operator * (Vector A,double p) {
    return Vector(A.x*p,A.y*p);
}
double Cross(Vector A,Vector B) {
    return A.x * B.y - A.y * B.x;
}
Point GetLineIntersection(Point P,Vector v,Point Q,Vector w) {
    Vector u = P - Q;
    double t =  Cross(w,u) / Cross(v,w);
    return P + v*t;
}
Vector Rotate(Vector A,double rad) {
    return Vector(A.x*cos(rad) - A.y*sin(rad),A.x*sin(rad) + A.y*cos(rad));
}
double Dot(Vector A,Vector B) {return A.x*B.x + A.y*B.y;}
double Lenght(Vector A) {
    return sqrt(Dot(A,A));
}
double Angle(Vector A,Vector B) {
    return acos(Dot(A,B) / Lenght(A) / Lenght(B));
}
Point read_point() {
    Point A;
    scanf("%lf%lf",&A.x,&A.y);
    return A;
}

Point getD(Point A,Point B,Point C) {
    Vector v1 = C - B;
    double a1 = Angle(A - B,v1);
    v1 = Rotate(v1,a1/3);

    Vector  v2 = B - C;
    double a2 = Angle(A - C,v2);
    v2 = Rotate(v2,-a2/3);

    return GetLineIntersection(B,v1,C,v2);
}

int main() {
    //freopen("in.txt","r",stdin);
    int t;
    Point A,B,C,D,E,F,G;
    scanf("%d",&t);
    while(t--) {
        A  = read_point();
        B  = read_point();
        C  = read_point();
        D  = getD(A,B,C); 
        E  = getD(B,C,A);
        F  = getD(C,A,B);
        printf("%.6lf %.6lf %.6lf %.6lf %.6lf %.6lf\n",D.x,D.y,E.x,E.y,F.x,F.y);
   }
    return 0;
}
