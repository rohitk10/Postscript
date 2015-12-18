#ifndef _BASICSHAPES_HH
#define _BASICSHAPES_HH

#include "input.hh"

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class basicshapes
{
 private:
	ofstream file;
 public:
	basicshapes(const char filename[])
	{
		file.open(filename);
    	}

        // this function sets red, green and blue color 

	void setcolor(double r, double g, double b)
		{
			file<<r<<' '<<g<<' '<<b<<" setrgbcolor \n";
		}

        //this function sets color out of 9 choices based on user input

	void selectcolor()
		{
			        cout << "1. Red \n"
					     << "2. Green \n"
						 << "3. Blue \n"
						 << "4. Magenta \n"
						 << "5. Yellow \n"
						 << "6. Cyan \n"
						 << "7. Gray \n"
						 << "8. Black \n"
						 << "9. White \n"
						 << "Select your color \n";
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

                //this function draws multiple number of lines connected to each other using starting and ending point of every line as user input
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
                //a function to draw the outline of a rectangle using starting point, ending point, width and height as user input
    		    file<<x<<' '<< y <<" moveto \n";
    			file<<x+w<<' '<<y<<" lineto \n";
    			file<<x+w<<' '<<y+h<<" lineto \n";
    			file<<x<<' '<<y+h<<" lineto \n";
    			file<<"closepath \n";
    			file<<"stroke \n";
    		}

    	void fillrect(double x, double y, double w, double h)
    		{
                ////a function to draw the outline of a rectangle using starting point, ending point, width and height as user input
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
    				//function to draw a triangle using coordinates of 3 vertices taken as user input
    				file<<x1<<' '<<y1<<" moveto \n";
    				file<<x2<<' '<<y2<<" lineto \n";
    				file<<x3<<' '<<y3<<" lineto \n";
    				file<<"closepath \n";
    				file<<"stroke \n";
    			}

    			void filltriangle(double x1, double y1, double x2, double y2, double x3, double y3)
    				{
    					//function to draw a triangle and fill it with a desired color
    					file<<x1<<' '<<y1<<" moveto \n";
    					file<<x2<<' '<<y2<<" lineto \n";
    					file<<x3<<' '<<y3<<" lineto \n";
    					file<<"closepath \n";
    					file<<"fill \n";
    				}

    			void ellipse(double x, double y, double r1, double r2)
    				{
    					//function to draw an ellipse usinf coordinates of center, horizontal and vertical radii as user input
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
    						//function to draw an ellipse and fill it with a desired color
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
    						//function to draw a 5 sided star using starting coordinates and side length as user input
    						file << "gsave \n"
    						     << "/side { \n"
    						     << s << ' ' << "0 lineto \n"
    						     << "currentpoint translate \n"
    						     << "-144 rotate \n"
    						     << "} def \n"
    						     << "/star { \n"
    						     << "currentpoint translate \n"
    						     << "4 {side} repeat \n"
    						     << "closepath \n"
    						     << "} def \n"
    						     << x << ' ' << y << ' ' << "moveto \n"
    						     << "star \n"
    						     << "stroke \n"
    						     << "grestore \n";
    					}

    					void fillstar(double x, double y, double s)
    						{
    							//function to draw a star and fill it with a desired color
    						    file << "gsave \n";
    							file << "/side { \n"
    							     << s << ' ' << "0 lineto \n"
    							     << "currentpoint translate \n"
    							     << "-144 rotate \n"
    							     << "} def \n"
    							     << "/star { \n"
    							     << "currentpoint translate \n"
    							     << "4 {side} repeat \n"
    							     << "closepath \n"
    							     << "} def \n"
    							     << x << ' ' << y << ' ' << "moveto \n"
    							     << "star \n"
    							     << "fill \n"
    								 << "grestore \n";
    						}

    					void polygon(double x, double y, int n, double l)
    						{
    							// function to draw an n sided polygon taking number of sides as user input
    							double ang = 360 / n;
    							file << "gsave \n";
    							file << x << ' ' << y << ' ' << "translate \n"
    								 << "0 0 moveto \n"
    								 << n << " {" << l << " 0 lineto currentpoint translate " << ang << " rotate} repeat \n"
    								 << "closepath \n"
    								 << "stroke \n"
    								 << "grestore \n";
    						}

    						void fillpolygon(double x, double y, int n, double l)
    							{
    								//function to draw a polygon and fill it with a desired color
    								double ang = 360 / n;
    								file << "gsave \n";
    								file << x << ' ' << y << ' ' << "translate \n"
    									 << "0 0 moveto \n"
    									 << n << " {" << l << " 0 lineto currentpoint translate " << ang << " rotate} repeat \n"
    									 << "closepath \n"
    									 << "fill \n"
    									 << "grestore \n";
    							}

	    	void closefile()
	{
		file.close();
	}
};

#endif
