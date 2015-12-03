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
	    file<<x<<' '<< y <<" moveto \n";
		file<<x+w<<' '<<y<<" lineto \n";
		file<<x+w<<' '<<y+h<<" lineto \n";
		file<<x<<' '<<y+h<<" lineto \n";
		file<<"closepath \n";
		file<<"stroke \n";
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
    		file<<"stroke \n";
    	}

    	void fillcircle(double x, double y, double r)
    	{
    		//The function fillcircle is used to create a circle and fill it with a desired color.
    		file << x << ' ' << y << ' ' << r << ' ' << "0" << ' ' << "360" << ' ' << "arc \n";
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
	
	void star(double x, double y, double s)
	{
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
			double ang = 360 / n;
			file << "gsave \n";
			file << x << ' ' << y << ' ' << "translate \n"
				 << "0 0 moveto \n"
				 << n << " {" << l << " 0 lineto currentpoint translate " << ang << " rotate} repeat \n"
				 << "closepath \n"
				 << "fill \n"
				 << "grestore \n";
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
    {
    	int input = 1;
	Postscript p("image.ps");
	while(input > 0)
	{
	cout << "1.  Line \n"
	     << "2.  Rectangle \n"
	     << "3.  Circle \n"
	     << "4.  Polyline \n"
		 << "5.  Set Color \n"
		 << "6.  Fill Rectangle \n"
		 << "7.  Triangle \n"
		 << "8.  Fill Circle \n"
		 << "9.  Fill Triangle \n"
		 << "10. Ellipse \n"
		 << "11. Fill Ellipse \n"
		 << "12. Star \n"
		 << "13. Fill Star \n"
		 << "14. Polygon \n"
		 << "15. Fill Polygon \n"
		 << "16. Grid \n"
		 << "17. Shaded Grid \n"
		 << "18. Bar Graph \n"
		 << "0. Exit \n \n"
	     << "ENTER CHOICE \n";
	cin >> input;
	switch(input)
	{
	case 1 :
		double x1, y1, x2, y2;
		cout << "Enter the coordinates of the starting point \n";
		cin >> x1;
		cin >> y1;
		cout << "Enter the coordinates of the ending point \n";
		cin >> x2;
		cin >> y2;
		p.line(x1,y1,x2,y2);
		break;

	case 2 :
		double x, y, w, h;
		cout << " Enter starting coordinates \n";
		cin >> x;
		cin >> y;
		cout << "Enter width and height \n";
		cin >> w;
		cin >> h;
		p.rect(x, y, w, h);
		break;

	case 3 :
		double xc, yc, r;
		cout << "Enter the coordinates of the center \n";
		cin >> xc;
		cin >> yc;
		cout << "Enter the radius of the circle \n";
		cin >> r;
		p.circle(xc, yc, r);
		break;

	case 4 :
		cout << "Enter number of lines \n";
		int n;
		cin >> n;
		p.polyline(n);
		break;

	case 5 :
		p.selectcolor();
		break;

		case 6 :
			//double x, y, w, h;
					cout << " Enter starting coordinates \n";
					cin >> x;
					cin >> y;
					cout << "Enter width and height \n";
					cin >> w;
					cin >> h;
					p.selectcolor();
					p.fillrect(x, y, w, h);
					break;

		case 7 :
			cout << "Enter the coordinates of the three vertices \n";
			double x3, y3;
			cin >> x1
			    >> y1
				>> x2
				>> y2
				>> x3
				>> y3;
			p.triangle(x1, y1, x2, y2, x3, y3);
			break;

		case 8 :
			cout << "Enter the coordinates of the center \n";
					cin >> xc;
					cin >> yc;
					cout << "Enter the radius of the circle \n";
					cin >> r;
					p.selectcolor();
					p.fillcircle(xc, yc, r);
					break;

		case 9 :
			cout << "Enter the coordinates of the three vertices \n";
						//double x3, y3;
						cin >> x1
						    >> y1
							>> x2
							>> y2
							>> x3
							>> y3;
						p.selectcolor();
						p.filltriangle(x1, y1, x2, y2, x3, y3);
						break;

		case 10 :
			cout << "Enter the coordinates of the center of the ellipse \n";
			cin >> xc;
			cin >> yc;
			cout << "Enter horizontal and vertical radii \n";
			double r1, r2;
			cin >> r1;
			cin >> r2;
			p.ellipse(xc, yc, r1, r2);
			break;

		case 11 :
			cout << "Enter the coordinates of the center of the ellipse \n";
						cin >> xc;
						cin >> yc;
						cout << "Enter horizontal and vertical radii \n";
						cin >> r1;
						cin >> r2;
						p.selectcolor();
						p.fillellipse(xc, yc, r1, r2);
						break;

		case 12 :
			double s;
			cout << "Enter the coordinates of the starting point \n";
			cin >> x;
			cin >> y;
			cout << "Enter the length of a side \n";
			cin >> s;
			p.star(x, y, s);
			break;

		case 13 :
			cout << "Enter the coordinates of the starting point \n";
						cin >> x;
						cin >> y;
						cout << "Enter the length of a side \n";
						cin >> s;
						p.selectcolor();
						p.fillstar(x, y, s);
						break;

		case 14 :
			cout << "Enter number of sides \n";
			cin >> n;
			cout << "Enter length of each side \n";
			double l;
			cin >> l;
			cout << "Enter coordinates of starting point \n";
			cin >> x;
			cin >> y;
			p.polygon(x, y, n, l);
			break;

		case 15 :
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

		case 16 :
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

		case 17 :
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

		}

	p.closefile();
}
    
