#include <iostream>
using namespace std;
#include "shapelist.h"
#include "vertex.h"
#include "polygon.h"
#include "rectangle.h"
#include "circle.h"
#include "point.h"

using namespace std;

int main(int argc, char *argv[])
{

    ShapeList list;
    Vertex varr[] = { Vertex(0,0), Vertex(10,0),
    Vertex(5,2), Vertex(5,5) };
    Polygon pol( 1, 4, varr, 4 );
    list.add(pol);
    Rectangle rec( 4, 10, 2, 4);
    list.add(rec);
    Circle cir( 5,5, 3);
    list.add(cir);
    Point pt( 6, 7, 1 );
    list.add(pt);
    list.print();
//    cout << " Totalyta: " << list.area() << endl;
//    ShapeList list2(list);
//    list2.print();
//    cout << " Totalyta: " << list2.area() << endl;
//    list.remove( Vertex(5,5) );
//    list.print();
//    cout << " Totalyta: " << list.area() << endl;
//    list2.print();
//    cout << " Totalyta: " << list2.area() << endl;
        cout << " Hello world " << endl;
    return 0;
}
