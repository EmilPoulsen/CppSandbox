#include <iostream>
#include <fstream>
#include <list>
#include <iterator>
#include <algorithm>
#include "shapeptr.h"
#include <vector>
#include "../OU3/vertex.h"
#include "../OU3/polygon.h"
#include "../OU3/shape.h"
#include "../OU3/circle.h"
#include "../OU3/rectangle.h"
#include "../OU3/point.h"
#include "shapefunctors.h"
using namespace std;

int main(int argc, char *argv[])
{

    vector<ShapePtr> shapevec;
    Vertex varr[] = { Vertex(0,0), Vertex(10,0), Vertex(5,2), Vertex(5,5) };
    // Här antar jag att ShapePtr har en konstruktor som tar en parameter av
    // typen "Shape *" och att just denna konstruktor _inte_ gör djupkopiering
    // Andra konstruktorer ska göra djupkopiering.

     shapevec.push_back( ShapePtr(new Polygon(1, 4, varr, 4 )) );
     shapevec.push_back( ShapePtr(new Circle(5, 5, 4)) );
    shapevec.push_back( ShapePtr(new Rectangle(4, 10, 2, 4)) );
    shapevec.push_back( ShapePtr(new Point(6,7,1)) );

    string file = "bbb.txt";//"‪C:\\cpp\\aaa.txt";
    ofstream os(file); //os("fil.dat");

    //////printing to console
    //std::ostream_iterator<ShapePtr> out_it (std::cout,"\n");
    //std::copy ( shapevec.begin(), shapevec.end(), out_it );
    //////
    ostream_iterator<const ShapePtr> shapeout(os,"\n");
    copy( shapevec.begin(), shapevec.end(), shapeout);
    os.close();

    ifstream is(file);//ifstream is("fil.dat");
    istream_iterator<ShapePtr> shapein(is), endofshapein;

    list<ShapePtr> shapelist(shapein, endofshapein );

    for (list<ShapePtr>::iterator it = shapelist.begin();
    it != shapelist.end(); it++)
    cout << *it << endl;

    ////////////////////////////////////////////////////////
    /////// TEST CODE FOR SORTING FUNCTORS//////////////////
    ////////////////////////////////////////////////////////
    //cout << "start of sorting stuff" << endl;
    //std::sort(shapevec.begin(), shapevec.end(), SortByAreaKey());
    //std::sort(shapevec.begin(), shapevec.end(), SortByXkey());
    //std::sort(shapevec.begin(), shapevec.end(), SortByYkey());
    for (int i = 0; i < shapevec.size(); ++i) {
        ///
        //cout << shapevec[i].getArea() << endl;
        //cout << shapevec[i].getX() << endl;
        //cout << shapevec[i].getY() << endl;
    }
    //cout << "end of sorting stuff" << endl;
    /////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////

    shapevec.insert( shapevec.end(), shapelist.begin(), shapelist.end() );
    //position - Position in the vector where the new elements are inserted.
    //terators specifying a range of elements. Copies of the elements in the
    //range [first,last) are inserted at position (in the same order).

    shapevec.erase(remove_if( shapevec.begin(), shapevec.end(),
            CloseTo( Vertex(6,7))),
            shapevec.end());


    ostream_iterator<const ShapePtr> shapecout(cout,"\n");
    cout << "size of shapevec: " << shapevec.size() << endl;

    cerr << "counter from numshapes: " << ShapePtr::numshapes << endl; // numshapes är ett statiskt attribut
                        // som håller reda på antalet objekt genom
                        // inkrement i konstruktorer och
                        // dekrement i destruktorn

    copy( shapevec.begin(), shapevec.end(), shapecout);
    return 0;
}
