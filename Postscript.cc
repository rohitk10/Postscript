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
   	//In this function we create lines from a certain (x,y) position and length of the line depends on user input.
    	}

    	void triangle()
    	{
    		//
    	}

    	void filltriangle()
    	{
    		//
    	}

    	void rect()
    	{
    		//
    	}

    	void fillrect()
    	{
    		//
    	}

    	void circle()
    	{
    		//
    	}

    	void fillcircle()
    	{
    		//
    	}

    	void polyline()
    	{
    		//
    	}

    	void grid()
    	{
    		//
    	}

    	void shadedgrid()
    	{
    		//
    	}

    	void text()
    	{
    		//
    	}

    	void filltext()
    	{
    		//
    	}

    	void lgraph()
    	{
    		//
    	}

    	void bgraph()
    	{
    		//
    	}
    };

    int main()
    {}
