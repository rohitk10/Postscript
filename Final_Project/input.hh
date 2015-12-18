#ifndef _INPUT_HH
#define _INPUT_HH

#include "basicshapes.hh"
#include "bargraphinput.hh"
#include "linegraphinput.hh"
#include "graphictextinput.hh"

#include <iostream>
using namespace std;



void input()
{
	int input = 1;
	Postscript p("image.ps");
	while(input > 0)
	{
	        cout << "1.  Line \n"
	        cout << "2.  Polyline \n"
		cout << "3.  Rectangle \n"
		cout << "4.  Fill Rectangle \n"
		cout << "5.  Circle \n"
		cout << "6.  Fill Circle \n"
		cout << "7.  Triangle \n"
		cout << "8.  Fill Triangle \n"
		cout << "9.  Ellipse \n"
		cout << "10. Fill Ellipse \n"
		cout << "11. Star \n"
		cout << "12. Fill Star \n"
		cout << "13. Polygon \n"
		cout << "14. Fill Polygon \n"
		cout << "15. Grid \n"
		cout << "16. Shaded Grid \n"
		cout << "17. Bar Graph \n"
		cout << "18. Line Graph \n"
		cout << "19. Graphic Text \n"
		cout << "20. Set Color \n"
		cout << "0.  Exit \n \n"
		cout << "ENTER CHOICE \n";
	        cin >> input;
	        
	        switch(input)
	        {
	           case 1 :
	           {
	        	double x1, y1, x2, y2;
	        	cout << "Enter the coordinates of the starting point \n";
	        	cin >> x1;
	        	cin >> y1;
	        	cout << "Enter the coordinates of the ending point \n";
	        	cin >> x2;
	        	cin >> y2;
	        	p.drawLine(x1,y1,x2,y2);
	        	break;
	           }

	           case 2 :
	           {
	        	   cout << "Enter number of lines \n";
	        	   int n;
	        	   cin >> n;
	        	   p.polyline(n);
	        	   break;
	           }

	           case 3 :
	           {
	        	   double x, y, w, h;
	        	   cout << " Enter starting coordinates \n";
	        	   cin >> x;
	        	   cin >> y;
	        	   cout << "Enter width and height \n";
	        	   cin >> w;
	        	   cin >> h;
	        	   p.rect(x, y, w, h);
	        	   break;
	           }

	           case 4 :
	           {
	        	   double x, y, w, h;
	        	   cout << " Enter starting coordinates \n";
	        	   cin >> x;
	        	   cin >> y;
	        	   cout << "Enter width and height \n";
	        	   cin >> w;
	        	   cin >> h;
	        	   p.selectcolor();
	        	   p.fillrect(x, y, w, h);
	        	   break;
	           }

	           case 5 :
	           {
	        	   double xc, yc, r;
	        	   cout << "Enter the coordinates of the center \n";
	        	   cin >> xc;
	        	   cin >> yc;
	        	   cout << "Enter the radius of the circle \n";
	        	   cin >> r;
	        	   p.circle(xc, yc, r);
	        	   break;
	           }

	           case 6 :
	           {
	        	   double xc, yc, r;
	        	   cout << "Enter the coordinates of the center \n";
	        	   cin >> xc;
	        	   cin >> yc;
	        	   cout << "Enter the radius of the circle \n";
	        	   cin >> r;
	        	   p.selectcolor();
	        	   p.fillcircle(xc, yc, r);
	        	   break;
	           }

	           case 7 :
	           {
	        	   cout << "Enter the coordinates of the three vertices \n";
	        	   double x1, y1, x2, y2, x3, y3;
	        	   cin >> x1
	        	   cout >> y1
	        	   cout >> x2
	        	   cout >> y2
	        	   cout >> x3
	        	   cout >> y3;
	        	   p.triangle(x1, y1, x2, y2, x3, y3);
	        	   break;
	           }

	           case 8 :
	           {
	        	   cout << "Enter the coordinates of the three vertices \n";
	        	   double x1, y1, x2, y2, x3, y3;
	        	   cin >> x1
	        	   cout >> y1
	        	   cout >> x2
	        	   cout >> y2
	        	   cout >> x3
	        	   cout >> y3;
	        	   p.selectcolor();
	        	   p.filltriangle(x1, y1, x2, y2, x3, y3);
	        	   break;
	           }

	           case 9 :
	           {
	        	   double xc, yc;
	        	   cout << "Enter the coordinates of the center of the ellipse \n";
	        	   cin >> xc;
	        	   cin >> yc;
	        	   cout << "Enter horizontal and vertical radii \n";
	        	   double r1, r2;
	        	   cin >> r1;
	        	   cin >> r2;
	        	   p.ellipse(xc, yc, r1, r2);
	        	   break;
	           }

	           case 10 :
	           {
	        	   double xc, yc, r1, r2;
	        	   cout << "Enter the coordinates of the center of the ellipse \n";
	        	   cin >> xc;
	        	   cin >> yc;
	        	   cout << "Enter horizontal and vertical radii \n";
	        	   cin >> r1;
	        	   cin >> r2;
	        	   p.selectcolor();
	        	   p.fillellipse(xc, yc, r1, r2);
	        	   break;
	           }

	           case 11:
	           {
	        	   double x, y, s;
	        	   cout << "Enter the coordinates of the starting point \n";
	        	   cin >> x;
	        	   cin >> y;
	        	   cout << "Enter the length of a side \n";
	        	   cin >> s;
	        	   p.star(x, y, s);
	        	   break;
	           }

	           case 12 :
	           {
	        	   double x, y, s;
	        	   cout << "Enter the coordinates of the starting point \n";
	        	   cin >> x;
	        	   cin >> y;
	        	   cout << "Enter the length of a side \n";
	        	   cin >> s;
	        	   p.selectcolor();
	        	   p.fillstar(x, y, s);
	        	   break;
	           }

	           case 13 :
	           {
	        	   int n;
	        	   double x, y, l;
	        	   cout << "Enter number of sides \n";
	        	   cin >> n;
	        	   cout << "Enter length of each side \n";
	        	   cin >> l;
	        	   cout << "Enter coordinates of starting point \n";
	        	   cin >> x;
	        	   cin >> y;
	        	   p.polygon(x, y, n, l);
	        	   break;
	           }

	           case 14 :
	           {
	        	   int n;
	        	   double x, y, l;
	        	   cout << "Enter number of sides \n";
	        	   cin >> n;
	        	   cout << "Enter length of each side \n";
	        	   cin >> l;
	        	   cout << "Enter coordinates of starting point \n";
	        	   cin >> x;
	        	   cin >> y;
	        	   p.selectcolor();
	        	   p.fillpolygon(x, y, n, l);
	        	   break;
	           }

	           case 15 :
	           {
	        	   double x, y, h, w;
	        	   int rows, cols;
	        	   cout << "Enter starting position of grid \n";
	        	   cin >> x;
	        	   cin >> y;
	        	   cout << "Enter number of rows and columns \n";
	        	   cin >> rows;
	        	   cin >> cols;
	        	   cout << "Enter height of rows and width of columns \n";
	        	   cin >> h;
	        	   cin >> w;
	        	   
	        	   for(int i = x; i < x+(cols*w); i = i+w)
	        	   {
	        	   	for(int j = y; j < y+(rows*h); j = j+h)
	        	   	{
	        	   		p.rect(i, j, w, h);
	        	   	}
	        	  }
	       //p.rect(x, y, x + (cols*w), y + (rows*h));
	        	   break;
	           }

	           case 16 :
	           {
	        	   double x, y, h, w;
	        	   int rows, cols;
	        	   cout << "Enter starting position of grid \n";
	        	   cin >> x;
	        	   cin >> y;
	        	   cout << "Enter number of rows and columns \n";
	        	   cin >> rows;
	        	   cin >> cols;
	        	   cout << "Enter height of rows and width of columns \n";
	        	   cin >> h;
	        	   cin >> w;
	        	   cout << "Select Background color \n";
	        	   p.selectcolor();
	        	   p.fillrect(x, y, (cols*w), (rows*h));
	        	   cout << "Select grid color \n";
	        	   p.selectcolor();
	        	   for(int i = x; i < x+(cols*w); i = i+w)
	        	   {
	        	   	for(int j = y; j < y+(rows*h); j = j+h)
	        	   	{
	        	   		p.rect(i, j, w, h);
	        	   	}
	        	   }
	        	  break;
	           }

	           case 17 :
	           {
	        	   bar_input();
	        	   break;
	           }

	           case 18 :
	           {
	        	   line_input();
	        	   break;
	           }

	           case 19 :
	           {
	        	   graphictextinput();
	        	   break;
	           }
	        }
	}
}


#endif
