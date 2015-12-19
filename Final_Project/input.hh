/* Author : Rohit Kulkarni
   Description : This is the first parent class that displays the menu
                 to the user. It is inherited by three other child classes
                 namely basicshapes, graph and graphictext.
*/                 
#ifndef _INPUT_HH
#define _INPUT_HH

#include "basicshapes.hh"
#include "bargraphinput.hh"
#include "linegraphinput.hh"
#include "graphictextinput.hh"

#include <iostream>
using namespace std;


class Postscript {

public:
void input()
{
	int input = 1;
	basicshapes p("image.ps");
	
	//while loop runs continuously until user enters zero
	while(input > 0)
	{
	                    cout << "1.  Line \n"
	                 	 << "2.  Polyline \n"
				 << "3.  Rectangle \n"
				 << "4.  Fill Rectangle \n"
			         << "5.  Circle \n"
				 << "6.  Fill Circle \n"
				 << "7.  Triangle \n"
				 << "8.  Fill Triangle \n"
				 << "9.  Ellipse \n"
				 << "10. Fill Ellipse \n"
				 << "11. Star \n"
				 << "12. Fill Star \n"
				 << "13. Polygon \n"
				 << "14. Fill Polygon \n"
				 << "15. Grid \n"
				 << "16. Shaded Grid \n"
				 << "17. Bar Graph \n"
				 << "18. Line Graph \n"
				 << "19. Graphic Text \n"
				 << "0.  Exit \n \n"
			     << "ENTER CHOICE \n";
	        cin >> input;
	        switch(input)
	        {
	           case 1 :
	           {
	           	//line
	        	double x1, y1, x2, y2;//double variables to store coordinates of starting and ending point of line
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
	           	//polyline
	        	   cout << "Enter number of lines \n";
	        	   		int n;//int variable to store number of lines
	        	   		cin >> n;
	        	   		p.polyline(n);
	        	   		break;
	           }

	           case 3 :
	           //rectangle
	           {
	        	   double x, y, w, h;//double variables to store starting coordinates, width and height
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
	           //fillrect
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
	           //circle
	           {
	        	   double xc, yc, r;///double variables to store coordinates of center and radius
	        	   		cout << "Enter the coordinates of the center \n";
	        	   		cin >> xc;
	        	   		cin >> yc;
	        	   		cout << "Enter the radius of the circle \n";
	        	   		cin >> r;
	        	   		p.circle(xc, yc, r);
	        	   		break;
	           }

	           case 6 :
	           //fill circle
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
	           //triangle
	           {
	        	   cout << "Enter the coordinates of the three vertices \n";
	        	   			double x1, y1, x2, y2, x3, y3;///double variables to store coordinates of 3 vertices
	        	   			cin >> x1
	        	   			    >> y1
	        	   				>> x2
	        	   				>> y2
	        	   				>> x3
	        	   				>> y3;
	        	   			p.triangle(x1, y1, x2, y2, x3, y3);
	        	   			break;
	           }

	           case 8 :
	           //fill triangle
	           {
	        	   cout << "Enter the coordinates of the three vertices \n";
	        	   double x1, y1, x2, y2, x3, y3;
	        	   						cin >> x1
	        	   						    >> y1
	        	   							>> x2
	        	   							>> y2
	        	   							>> x3
	        	   							>> y3;
	        	   						p.selectcolor();
	        	   						p.filltriangle(x1, y1, x2, y2, x3, y3);
	        	   						break;
	           }

	           case 9 :
	           //ellipse
	           {
	        	   double xc, yc;//double variables to store coordinates of center
	        	   cout << "Enter the coordinates of the center of the ellipse \n";
	        	   			cin >> xc;
	        	   			cin >> yc;
	        	   			cout << "Enter horizontal and vertical radii \n";
	        	   			double r1, r2;//double variables to store horizontal and vertical radii
	        	   			cin >> r1;
	        	   			cin >> r2;
	        	   			p.ellipse(xc, yc, r1, r2);
	        	   			break;
	           }

	           case 10 :
	           //fillellipse
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
	           //star
	           {
	        	   double x, y, s;//double variables to store coordinates of center and length of a side
	        	   			cout << "Enter the coordinates of the starting point \n";
	        	   			cin >> x;
	        	   			cin >> y;
	        	   			cout << "Enter the length of a side \n";
	        	   			cin >> s;
	        	   			p.star(x, y, s);
	        	   			break;
	           }

	           case 12 :
	           //fill star
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
	           //polygon
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
	           ///fill polygon
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
	           //grid
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
	           //shaded grid
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
	           //bar graph
	           {
	        	   bar_input();
	        	   break;
	           }

	           case 18 :
	           //line graph
	           {
	        	   line_input();
	        	   break;
	           }

	           case 19 :
	           //graphic text
	           {
	        	   graphictextinput();
	        	   break;
	           }

	        }
	}
}
};

#endif
