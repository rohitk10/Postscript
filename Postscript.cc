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
    	
    	void setcolor(double r, double g, double b)
	{
		file << r << ' ' << g << ' ' << b <<" setrgbcolor \n";
	}
	
	void setgray(double n)
	{
		file << n << ' ' << "setgray \n";
	}

    	void line(double x1, double y1, double x2, double y2)
    	{
   		//In this function we create a line from a certain point (x1,y1) upto another point (x2,y2).
   		file<<x1<<' '<<y1<<' '<<"moveto \n";
   		file<<x2<<' '<<y2<<' '<<"lineto \n";
   		file<<"stroke";
    	}

    	void triangle(double x1, double y1, double x2, double y2, double x3, double y3)
    	{
    		//In this function we create an outline of a triangle by joining three co-ordinates (x1,y1), (x2,y2) and (x3,y3).
    		file << x1 << ' ' << y1 << ' ' << "moveto \n";
    		file << x2 << ' ' << y2 << ' ' << "lineto \n";
    		file << x3 << ' ' << y3 << ' ' << "lineto \n";
    		file << "closepath \n";
    		file << "stroke";
    	}

    	void filltriangle(double x1, double y1, double x2, double y2, double x3, double y3)
    	{
    		//The fuction filltriangle is used to create a triangle by joining three points and filling it with any desired color.
        	file << x1 << ' ' << y1 << ' ' << "moveto \n";
    		file << x2 << ' ' << y2 << ' ' << "lineto \n";
    		file << x3 << ' ' << y3 << ' ' << "lineto \n";
    		file << "closepath \n";
    		file << "fill";
    		
    	}

    	void rect(double x, double y, double w, double h)
    	{
    		//In the rect function we create an outline of a rectangle using parameters like x and y coordinate, width and height.
	file<<x<<' '<<y<<' '<<"moveto"<</n;
	file<<x<<' '<<h<<' '<<"moveto"<</n;
	file<<w<<' '<<h<<' '<<"moveto"<</n;
	file<<"closepath"<</n;
	file<<"stroke"<</n;
	file<<"} def"<</n;
	file<<100<<' '<<200<<' '<<"translate"<</n;
	file<<10<<' '<<"setlinewidth"<<' '<<1<<' '<<"setlinejoin"<</n;
	file<<"Rect";
    	}

    	void fillrect(double x, double y, double w, double h)
    	{
    		//fillrect is used to create a rectangle using coordinates, width and height, and filling it with any desired color.
    	file << x << ' ' << y <<" moveto \n";
	file << x+w << ' ' << y <<" lineto \n";
	file << x+w << ' ' << y+h <<" lineto \n";
	file << x << ' ' << y+h <<" lineto \n";
	file << "closepath \n";
	file <<"fill \n";
    		
    	}

    	void circle(double x, double y, double r)
    	{
    		//In this function we draw a circle with (x,y) as the centre and radius r obtained from the user.
    		file << x << ' ' << y << ' ' << r << ' ' << "0" << ' ' << "360" << ' ' << "arc \n";
    		file<<"stroke";
    	}

    	void fillcircle(double x, double y, double r)
    	{
    		//The function fillcircle is used to create a circle and fill it with a desired color.
    		file << x << ' ' << y << ' ' << r << ' ' << "0" << ' ' << "360" << ' ' << "arc \n";
    		file<<"fill";
    
    	}
    	
    	void ellipse(double x, double y, double r1, double r2)
	{
		// This function is used to create an outline of an ellipse at center (x,y) with horizontal and vertical radii r1 and r2 respectively.
		double x0, y0;
		x0 = x;
		y0 = y - r2 / 2;
		file << x0 << ' ' << y0 << ' ' << "translate \n";
		file << "0 0 moveto \n";
		file << r1/2 << ' ' << '0' << ' ' << r1/2 << ' ' << r2 << ' ' << '0' << ' ' << r2 << ' ' << "rcurveto \n";
		file << "180 rotate \n";
		file << r1/2 << ' ' << '0' << ' ' << r1/2 << ' ' << r2 << ' ' << '0' << ' ' << r2 << ' ' << "rcurveto \n";
		file << "stroke \n";
	}
	
	void fillellipse(double x, double y, double r1, double r2)
	{
		// This function is used to create an ellipse at center (x,y) with horizontal and vertical radii r1 and r2 respectively and fill it with a desired color.
		double x0, y0;
		x0 = x;
		y0 = y - r2 / 2;
		file << x0 << ' ' << y0 << ' ' << "translate \n";
		file << "0 0 moveto \n";
		file << r1/2 << ' ' << '0' << ' ' << r1/2 << ' ' << r2 << ' ' << '0' << ' ' << r2 << ' ' << "rcurveto \n";
		file << "180 rotate \n";
		file << r1/2 << ' ' << '0' << ' ' << r1/2 << ' ' << r2 << ' ' << '0' << ' ' << r2 << ' ' << "rcurveto \n";
		file << "fill \n";
	}

    	void polyline()
    	{
    		// The polyline function is used to create a continous line having two or more line segments. The number of segments n is obtained from the user.
    	double arr[2*(n + 1)];
	cout << "Enter the coordinates of the polyline one by one \n";
	for(int i = 0; i < 2*(n + 1); i++)
	{
		cin >> arr[i];
	}

	file << arr[0] << ' ' << arr[1] << ' ' << "moveto \n";
	for(int i = 2; i < 2*(n + 1); i = i + 2)
	{
		file << arr[i] << ' ' << arr[i+1] << ' ' << "lineto \n";
	}
	file << "stroke";
    		
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
    	
    	void graphictext()
	{
		// This function includes logos.
		char x;
		cout<<"Enter which logo you want out of Google, DELL, Target"
		cin>>x;
		string logo = "x";
		
		switch(logo)
		{
			case "Google" :
			file<<"/Times-Roman findfont"<<\n;
			file<<32<<' '<<"scalefont"<<\n;
			file<<"setfont"\n;
			file<<100<<' '<<20<<' '<<"translate"\n;
			file<<2<<' '<<1<<' '<<"scale"\n;
			file<<"newpath";
			file<<0<<' '<<0<<' '<<"moveto"\n;
			file<<"(G) true charpath"\n;
			file<<2<<' '<<"setlinewidth"\n;
			file<<0<<' '<<0<<' '<<1<<' '<<"setrgbcolor"\n;
			file<<"fill"\n;
			
			file<<1<<' '<<0<<' '<<"translate"\n;
			file<<"newpath"\n;
			file<<20<<' '<<0<<' '<<"moveto"\n;
			file<<"(o) true charpath";
			file<<1<<' '<<0<<' '<<0<<' '<<"setrgbcolor"\n;
			file<<"fill"\n;
			
			file<<1<<' '<<0<<' '<<"translate"\n;
			file<<"newpath"\n;
			file<<30<<' '<<0<<' '<<"moveto"\n;
			file<<"(o) true charpath";
			file<<1<<' '<<1<<' '<<0<<' '<<"setrgbcolor"\n;
			file<<"fill"\n;
			
			file<<1<<' '<<0<<' '<<"translate"\n;
			file<<"newpath"\n;
			file<<50<<' '<<0<<' '<<"moveto"\n;
			file<<"(g) true charpath";
			file<<0<<' '<<0<<' '<<1<<' '<<"setrgbcolor"\n;
			file<<"fill"\n;
			
			file<<1<<' '<<0<<' '<<"translate"\n;
			file<<"newpath"\n;
			file<<80<<' '<<0<<' '<<"moveto"\n;
			file<<"(l) true charpath";
			file<<0<<' '<<1<' '<<0<<' '<<"setrgbcolor"\n;
			file<<"fill"\n;
			
			file<<1<<' '<<0<<' '<<"translate"\n;
			file<<"newpath"\n;
			file<<90<<' '<<0<<' '<<"moveto"\n;
			file<<"(e) true charpath";
			file<<1<<' '<<0<<' '<<0<<' '<<"setrgbcolor"\n;
			file<<"fill"\n;
			
			
			break;
			
			case "DELL" :
			
			break;
			
			case "Target" :
			
			break;
		}
	}

    	void lgraph()
    	{
    		//lgraph function is use to create line graphs to represent census.
    		30 30 moveto
		550 30 lineto
		30 30 moveto
		30 550 lineto
		stroke
		Helvetica findfont
		40 scalefont setfont
		200 550 moveto
		(title) true charpath
		Helvetica findfont
		15 scalefont setfont
		250 5 moveto
		(h1) true charpath
		gsave
		14 250 moveto
		90 rotate
		(v1) true charpath
		grestore
		Helvetica findfont
		8 scalefont setfont
		
    		double arr[2*(n + 1)];
		file<< "Enter the coordinates of the polyline one by one \n";
		for(int i = 0; i < 2*(n + 1); i++)
		{
			cin >> arr[i];
		}

		file << arr[0] << ' ' << arr[1] << ' ' << "moveto \n";
		for(int i = 2; i < 2*(n + 1); i = i + 2)
		{
			file << arr[i] << ' ' << arr[i+1] << ' ' << "lineto \n";
		}
		file << "stroke";
    		break;
    			
    		case "B" :
    		double arr[2*(n + 1)];
		cout << "Enter the coordinates of the polyline one by one \n";
		for(int i = 0; i < 2*(n + 1); i++)
		{
			cin >> arr[i];
		}

		file << arr[0] << ' ' << arr[1] << ' ' << "moveto \n";
		for(int i = 2; i < 2*(n + 1); i = i + 2)
		{
			file << arr[i] << ' ' << arr[i+1] << ' ' << "lineto \n";
		}
		file << "stroke";
    		break;
    		}
    	}

    	void bgraph()
    	{
    		//The function bgraph is used to create bar graphs to represent census or company statistics.
    	}
    };

    int main()
    {}
