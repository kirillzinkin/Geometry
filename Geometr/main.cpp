#include "Point.h"
#include "Line.h"
#include "Triangle.h"
#include "Circle.h"
#include "Quadrilateral.h"
#include "Sphere.h"
#include "Ellipse.h"
#include "Container.h"
#define Add(x) Add(x, #x)
#define SetA(t) SetA()[t]
#define SetB(t) SetB()[t]
#define SetC(t) SetC()[t]
#define SetD(t) SetD()[t]
using namespace std;


int main()
{
    Point<int> Dot(2);
    Dot.SetA(0) = 1; Dot.SetA(1) = 2;
    cout << Dot << endl;
    Point<int> Dot2(Dot);
    Line<int> Vec(2);
    Vec.SetA(0) = 0; Vec.SetA(1) = 0;
    Vec.SetB(0) = 3; Vec.SetB(1) = -4;
    cout << Vec << endl;
    Line<int> Vec2(Vec);
    Circle<int> Cc(2);
    Cc.SetA(0) = 0; Cc.SetA(1) = 0;
    Cc.SetB(0) = 3; Cc.SetB(1) = -4;
    cout << Cc << endl;
    Triangle<int> Tri(2);
    Tri.SetA(0) = 0; Tri.SetA(1) = 0;
    Tri.SetB(0) = 0; Tri.SetB(1) = 2;
    Tri.SetC(0) = 3; Tri.SetC(1) = 0;
    cout << Tri << endl;
    Quadrilateral<int> Sq(2);
    Sq.SetA(0) = 0; Sq.SetA(1) = 0;
    Sq.SetB(0) = 0; Sq.SetB(1) = 2;
    Sq.SetC(0) = 2; Sq.SetC(1) = 2;
    Sq.SetD(0) = 2; Sq.SetD(1) = 0;
    cout << Sq << endl;
    Quadrilateral<int> Sk(Sq);
    Container Box;
    Box.Add(Dot);
    Box.Add(Sq);
    Box.Add(Tri);
    Box.ShowAll();
    cout << endl;
    Box.Show(0);
    Box.Remove(1);
    Box.ShowAll();
    cout << endl;
    Sphere<int> Sph(3);
    Sph.SetA(0) = 0; Sph.SetA(1) = 0; Sph.SetA(2) = 0;
    Sph.SetB(0) = 5; Sph.SetB(1) = 5; Sph.SetB(2) = 0;
    cout << Sph << endl;
    Ellipse<int> El(2);
    El.SetA(0) = 5; El.SetA(1) = 5;
    El.SetB(0) = 2; El.SetB(1) = 2;
    El.SetC(0) = 0; El.SetC(1) = 0;
    cout << El << endl;
	return 0;
}
