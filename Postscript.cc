// Authors: Rutuja Sawant, Rohit Kulkarni

#include <iostream>
#include <fstream>
using namespace std;

class Postscript
{
 private:
	ofstream file;
 public:
	Postscript(const char filename[])
	{
		file.open(filename);
    	}

    	void line()
    	{
   		//In this function we create a line from a certain point (x1,y1) upto another point (x2,y2).
    	}

    	void triangle()
    	{
    		//In this function we create an outline of a triangle by joining three co-ordinates (x1,y1), (x2,y2) and (x3,y3).
    	}

    	void filltriangle()
    	{
    		//The fuction filltriangle is used to create a triangle by joining three points and fill it with a desired color..
    	}

    	void rect()
    	{
    		//In the rect function we create an outline of a rectangle using an x and y coordinate, width and height.
    	}

    	void fillrect()
    	{
    		//fillrect is used to create a rectangle using coordinates, width and height, and fill it with a esired color.
    	}

    	void circle()
    	{
    		//In this function we draw a circle with (x,y) as the centre and radius r obtained from the user.
    	}

    	void fillcircle()
    	{
    		//The function fillcircle is used to create a circle and fill it with a desired color.
    	}

    	void polyline()
    	{
    		// The polyline function is used to create a continous line having two or more line segments. The number of segments n is obtained from the user.
    	}

    	void grid()
    	{
    		//In this function we create a network of lines that cross each other to form multiple squares or rectangles.
    	}

    	void shadedgrid()
    	{
    		//shadegrid function is used to fill colour inside the grid.
    	}

    	void text()
    	{
    		//In the text function, we write various texts including company names and logos. Examples - Google, Dell, Adidas etc.
    	}

    	void filltext()
    	{
    		//This function is used to give color to texts.
    	}

    	void lgraph()
    	{
    		//lgraph function is use to create line graphs to represent census.
    	}

    	void bgraph()
    	{
    		//The function bgraph is used to create bar graphs to represent census or company statistics.
    	}
    };

    int main()
    {}
