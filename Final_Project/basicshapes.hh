#ifndef _BASICSHAPES_HH
#define _BASICSHAPES_HH

#include "input.hh"

#include <iostream>
#include <fstream>
#include <string>
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
		file<<r<<' '<<g<<' '<<b<<" setrgbcolor \n";
	}

	void selectcolor()
	{
		cout << "1. Red \n"
		cout << "2. Green \n"
		cout << "3. Blue \n"
		cout << "4. Magenta \n"
		cout << "5. Yellow \n"
		cout << "6. Cyan \n"
		cout << "7. Gray \n"
		cout << "8. Black \n"
		cout << "9. White \n"
		cout << "Select your color \n";
		int clr;
		cin >> clr;
		switch(clr)
		{
		case 1 :
		setcolor(1, 0, 0);
		break;
		
		case 2 :
		setcolor(0, 1, 0);
		break;
					
		case 3 :
		setcolor(0, 0, 1);
		break;
					
		case 4 :
		setcolor(1, 0, 1);
		break;
					
		case 5 :
		setcolor(1, 1, 0);
		break;
		
		case 6 :
		setcolor(0, 1, 1);
		break;
		
		case 7 :
		setcolor(0, 0, 0);
		setgray(0.5);
		break;
					
		case 8 :
		setcolor(0, 0, 0);
		break;
			
		case 9 :
		setcolor(1, 1, 1);
		break;
		
		default :
		cout << "Invalid Choice! \n";
		}
	}

	void setgray(double n)
		{
			file << n << ' ' << "setgray \n";
		}

    	void drawLine(double x1, double y1, double x2, double y2)
	    	{
	   		//In this function we create a line from a certain point (x1,y1) upto another point (x2,y2).
	   		file<<x1<<' '<<y1<<' '<<"moveto \n";
	   		file<<x2<<' '<<y2<<' '<<"lineto \n";
	   		file<<"stroke \n";
	    	}

    	void polyline(int n)
    		{
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

    	void rect(double x, double y, double w, double h)
    	{
    		file<<x<<' '<< y <<" moveto \n";
    	 	file<<x+w<<' '<<y<<" lineto \n";
    		file<<x+w<<' '<<y+h<<" lineto \n";
    		file<<x<<' '<<y+h<<" lineto \n";
    		file<<"closepath \n";
    		file<<"stroke \n";
    	}

    	void fillrect(double x, double y, double w, double h)
    	{
    		file<<x<<' '<< y <<" moveto \n";
    		file<<x+w<<' '<<y<<" lineto \n";
    		file<<x+w<<' '<<y+h<<" lineto \n";
    		file<<x<<' '<<y+h<<" lineto \n";
    		file<<"closepath \n";
    		file<<"fill \n";
    	}

    	void circle(double x, double y, double r)
    	{
    	//In this function we draw a circle with (x,y) as the centre and radius r obtained from the user.
    		file << x << ' ' << y << ' ' << r << ' ' << "0" << ' ' << "360" << ' ' << "arc \n";
    		file<<"stroke \n";
    	}

    	void fillcircle(double x, double y, double r)
    	{
    	//In this function we draw and fill a circle with (x,y) as the center and radius r obtained from the user.
    		file << x << ' ' << y << ' ' << r << ' ' << "0" << ' ' << "360" << ' ' << "arc \n";
    		file<<"fill \n";
    	}

    	void triangle(double x1, double y1, double x2, double y2, double x3, double y3)
    	{
    		file<<x1<<' '<<y1<<" moveto \n";
    		file<<x2<<' '<<y2<<" lineto \n";
    		file<<x3<<' '<<y3<<" lineto \n";
    		file<<"closepath \n";
    		file<<"stroke \n";
    	}

    	void filltriangle(double x1, double y1, double x2, double y2, double x3, double y3)
    	{
    		file<<x1<<' '<<y1<<" moveto \n";
    		file<<x2<<' '<<y2<<" lineto \n";
    		file<<x3<<' '<<y3<<" lineto \n";
    		file<<"closepath \n";
    		file<<"fill \n";
    	}

    	void ellipse(double x, double y, double r1, double r2)
    	{
    		double x0, y0;
    		x0 = x;
    		y0 = y - r2 / 2;
    		file << "gsave \n";
    		file << x0 << ' ' << y0 << ' ' << "translate \n";
    		file << "0 0 moveto \n";
    		file << r1/2 << ' ' << '0' << ' ' << r1/2 << ' ' << r2 << ' ' << '0' << ' ' << r2 << ' ' << "rcurveto \n";
    		file << "180 rotate \n";
    		file << r1/2 << ' ' << '0' << ' ' << r1/2 << ' ' << r2 << ' ' << '0' << ' ' << r2 << ' ' << "rcurveto \n";
    		file << "closepath \n";
    		file << "stroke \n";
    		file << "grestore \n";
    	}

    	void fillellipse(double x, double y, double r1, double r2)
    	{
    		double x0, y0;
    		x0 = x;
    		y0 = y - r2 / 2;
    		file << "gsave \n";
    		file << x0 << ' ' << y0 << ' ' << "translate \n";
    		file << "0 0 moveto \n";
    		file << r1/2 << ' ' << '0' << ' ' << r1/2 << ' ' << r2 << ' ' << '0' << ' ' << r2 << ' ' << "rcurveto \n";
    		file << "180 rotate \n";
    		file << r1/2 << ' ' << '0' << ' ' << r1/2 << ' ' << r2 << ' ' << '0' << ' ' << r2 << ' ' << "rcurveto \n";
    		file << "closepath \n";
    		file << "fill \n";
    		file << "grestore \n";
    	}

    	void star(double x, double y, double s)
    	{
    		file << "gsave \n"
    		file << "/side { \n"
    		file << s << ' ' << "0 lineto \n"
    		file << "currentpoint translate \n"
    		file << "-144 rotate \n"
    		file << "} def \n"
    		file << "/star { \n"
    		file << "currentpoint translate \n"
    		file << "4 {side} repeat \n"
    		file << "closepath \n"
    		file << "} def \n"
    		file << x << ' ' << y << ' ' << "moveto \n"
    		file << "star \n"
    		file << "stroke \n"
    		file << "grestore \n";
    	}

    	void fillstar(double x, double y, double s)
    	{
    		file << "gsave \n";
    		file << "/side { \n"
    		file << s << ' ' << "0 lineto \n"
    		file << "currentpoint translate \n"
    		file << "-144 rotate \n"
    		file << "} def \n"
    		file << "/star { \n"
    		file << "currentpoint translate \n"
    		file << "4 {side} repeat \n"
    		file << "closepath \n"
    		file << "} def \n"
    		file << x << ' ' << y << ' ' << "moveto \n"
    		file << "star \n"
    		file << "fill \n"
    		file << "grestore \n";
    	}

    	void polygon(double x, double y, int n, double l)
    	{
    		double ang = 360 / n;
    		file << "gsave \n";
    		file << x << ' ' << y << ' ' << "translate \n"
    		file << "0 0 moveto \n"
    		file << n << " {" << l << " 0 lineto currentpoint translate " << ang << " rotate} repeat \n"
    		file << "closepath \n"
    		file << "stroke \n"
    		file << "grestore \n";
    	}

    	void fillpolygon(double x, double y, int n, double l)
    	{
    		double ang = 360 / n;
    		file << "gsave \n";
    		file << x << ' ' << y << ' ' << "translate \n"
    		file << "0 0 moveto \n"
    		file << n << " {" << l << " 0 lineto currentpoint translate " << ang << " rotate} repeat \n"
    		file << "closepath \n"
    		file << "fill \n"
    		file << "grestore \n";
    	}

	void closefile()
	{
		file.close();
	}
};

#endif
