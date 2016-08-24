#include <iostream>
using namespace std;
#include "../OU1/Vertex.h"
#include "../OU1/Polygon.h"
#include "sortedvector.h"
#include "sortedvector.cpp"



int main(int argc, char *argv[])
{
    SortedVector<Polygon,10> polygons;
    SortedVector<int,6> ints;

    ints.add( 3 );
    ints.add( 1 );
    ints.add( 6 );

    Vertex varr[10];
    varr[0] = Vertex(0,0);
    varr[1] = Vertex(10,0);
    varr[2] = Vertex(5,2);
    varr[3] = Vertex(5,5);
    Polygon p1(varr, 4); //creating the polygon before appending it to the sortedlist.
    polygons.add(p1);
//    polygons.add(Polygon( varr, 4) );
    cout << (Polygon(varr,4)).area() << endl;

    varr[0] = Vertex(0,0);
    varr[1] = Vertex(25,8);
    varr[2] = Vertex(10,23);
    //polygons.add( Polygon( varr, 3) );
    Polygon p2(varr, 3); //creating the polygon before appending it to the sortedlist.
    polygons.add(p2);
    cout << (Polygon(varr,3)).area() << endl;
    varr[0] = Vertex(0,0);
    varr[1] = Vertex(5,0);
    varr[2] = Vertex(5,3);
    varr[3] = Vertex(4,8);
    varr[4] = Vertex(2,10);
    //polygons.add( Polygon( varr, 5) );
    Polygon p3(varr, 5); //creating the polygon before appending it to the sortedlist.
    polygons.add(p3);
    cout << (Polygon(varr,5)).area() << endl;
    polygons.print(cout);
    ints.print(cout);

    cout << "MEDIAN: " << ints.median() << endl;
    cout << "MEDIAN: " << polygons.median() << endl;
    ints.add( 4); // 1 3 4 6
    ints.add( 2); // 1 2 3 4 6
    ints.add( 5); // 1 2 3 4 5 6
    ints.removeLarger( 3 ); // 1 2 3
    cout << "MEDIAN: " << ints.median() << endl;
    return 1;
}
