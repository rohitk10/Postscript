// Authors: Rutuja Sawant, Rohit Kulkarni

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

	void setgray(double n)
	{
		file << n << ' ' << "setgray \n";
	}

	void line(double x1, double y1, double x2, double y2)
    {
	   	//In this function we create a line from a certain point (x1,y1) upto another point (x2,y2).
	   	file<<x1<<' '<<y1<<' '<<"moveto \n";
	   	file<<x2<<' '<<y2<<' '<<"lineto \n";
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

	void rect(double x, double y, double w, double h)
	{
	    file<<x<<' '<< y <<" moveto \n";
		file<<x+w<<' '<<y<<" lineto \n";
		file<<x+w<<' '<<y+h<<" lineto \n";
		file<<x<<' '<<y+h<<" lineto \n";
		file<<"closepath \n";
		file<<"stroke \n";
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
		file << "/side { \n"
		file<< s << ' ' << "0 lineto \n"
		file<< "currentpoint translate \n"
		file<< "-144 rotate \n"
		file<< "} def \n"
		file<< "/star { \n"
		file<< "currentpoint translate \n"
		file<< "4 {side} repeat \n"
		file<< "closepath \n"
		file<< "} def \n"
		file<< x << ' ' << y << ' ' << "moveto \n"
		file<< "star \n"
	    file<< "stroke \n"
		file<< "grestore \n";
	}

	void fillstar(double x, double y, double s)
	{
		file << "gsave \n";
		file << "/side { \n"
		file<< s << ' ' << "0 lineto \n"
		file<< "currentpoint translate \n"
		file<< "-144 rotate \n"
		file<< "} def \n"
		file<< "/star { \n"
		file<< "currentpoint translate \n"
		file<< "4 {side} repeat \n"
		file<< "closepath \n"
		file<< "} def \n"
		file<< x << ' ' << y << ' ' << "moveto \n"
		file<< "star \n"
		file<< "fill \n"
		file<< "grestore \n";
	}

	void polygon(double x, double y, int n, double l)
	{
		double ang = 360 / n;
		file << "gsave \n";
		file << x << ' ' << y << ' ' << "translate \n"
		file<< "0 0 moveto \n"
		file<< n << " {" << l << " 0 lineto currentpoint translate " << ang << " rotate} repeat \n"
		file<< "closepath \n"
		file<< "stroke \n"
		file<< "grestore \n";
	}

	void fillpolygon(double x, double y, int n, double l)
	{
		double ang = 360 / n;
		file<< "gsave \n";
		file << x << ' ' << y << ' ' << "translate \n"
		file<< "0 0 moveto \n"
		file<< n << " {" << l << " 0 lineto currentpoint translate " << ang << " rotate} repeat \n"
		file<< "closepath \n"
		file<< "fill \n"
		file<< "grestore \n";
	}
	
	void selectcolor()
		// a function that allows the user to select a color out of 9 choices
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
	}void selectcolor()
	{
		file<< "1. Red \n"
		file<< "2. Green \n"
		file<< "3. Blue \n"
		file<< "4. Magenta \n"
		file<< "5. Yellow \n"
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

	void linegraph1(int n, string title, string hl, string v1)
	{	
		file << "30 30 moveto \n";
		file<< "550 30 lineto \n";
		file<< "30 30 moveto \n";
		file<< "30 550 lineto \n";
		file<< "stroke \n";
		file<< "/Helvetica findfont \n";
		file<< "40 scalefont setfont \n";
		file<< "200 550 moveto \n";
		file<< "(" << title << ") show \n";
		file<< "/Helvetica findfont \n";
		file<< "15 scalefont setfont \n";
		file<< "250 5 moveto \n";
		file<< "(" << hl << ") show \n";
		file<< "gsave \n";
		file<< "14 250 moveto \n";
		file<< "90 rotate \n";
		file<< "(" << vl << ") show \n";
		file<< "grestore \n";
		file<< "/Helvetica findfont \n";
		file<< "8 scalefont \n"
		file<< "setfont \n";


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

	void linegraph2(int n, string title, string hl, string v1)
	{
		file << "30 30 moveto \n";
		file<< "550 30 lineto \n";
		file<< "30 30 moveto \n";
		file<< "30 550 lineto \n";
		file<< "stroke \n";
		file<< "/Helvetica findfont \n";
		file<< "40 scalefont setfont \n";
		file<< "200 550 moveto \n";
		file<< "(" << title << ") show \n";
		file<< "/Helvetica findfont \n";
		file<< "15 scalefont setfont \n";
		file<< "250 5 moveto \n";
		file<< "(" << hl << ") show \n";
		file<< "gsave \n";
		file<< "14 250 moveto \n";
		file<< "90 rotate \n";
		file<< "(" << vl << ") show \n";
		file<< "grestore \n";
		file<< "/Helvetica findfont \n";
		file<< "8 scalefont";
		file<< "setfont \n";

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
		
		double a[2*(n + 1)];
		cout << "Enter the coordinates of the polyline one by one \n";
		for(int j = 0; j < 2*(n + 1); j++)
		{
		cin >> a[j];
		}

		file << a[0] << ' ' << a[1] << ' ' << "moveto \n";
		for(int j = 2; j < 2*(n + 1); j = j + 2)
		{
			file << a[j] << ' ' << a[j+1] << ' ' << "lineto \n";
		}
			file << "stroke";
	}
    	
    	void bargraph1(string title, string hl, string vl, int hn, double intervalv, string label[], double b1[])
	{
		file<< "30 30 moveto \n"
		file<< "550 30 lineto \n"
		file<< "30 30 moveto \n"
		file<< "30 550 lineto \n"
		file<< "stroke \n"
		file<< "/Helvetica findfont \n"
		file<< "40 scalefont setfont \n"
		file<< "200 550 moveto \n"
		file<< "(" << title << ") show \n"
		file<< "/Helvetica findfont \n"
		file<< "15 scalefont setfont \n"
		file<< "250 5 moveto \n"
		file<< "(" << hl << ") show \n"
		file<< "gsave \n"
		file<< "14 250 moveto \n"
		file<< "90 rotate \n"
		file<< "(" << vl << ") show \n"
		file<< "grestore \n"
		file<< "/Helvetica findfont \n"
		file<< "8 scalefont setfont \n";
					
		for(int i = 0; i < hn; i++)
		{
			file << 30+((i+1)*intervalh) << " 22 moveto \n"
			file<< "(" << label[i] << ")" << " show \n";
		}
		for(int i = 0; i < hn; i++)
		{
		file << 30+((i+1)*intervalh) << " 30 5 " << b1[i] * intervalv << " rectfill \n";
		}
		for(int i = 0; i < hn; i++)
		{
		file << "gsave \n"
		file<< "28 " << (b1[i] * intervalv) + 25<< " moveto \n"
		file<< "90 rotate \n"
		file<< "(" << b1[i]<< ") show \n"
		file<< "grestore \n";
		}

	}

	void bargraph2(string title, string hl, string vl, int hn, double intervalh, double intervalv, string label[], double b1[], double b2[])
	{
		file << "30 30 moveto \n"
		file<< "550 30 lineto \n"
		file<< "30 30 moveto \n"
		file<< "30 550 lineto \n"
		file<< "stroke \n"
		file<< "/Helvetica findfont \n"
		file<< "40 scalefont setfont \n"
		file<< "200 550 moveto \n"
		file<< "(" << title << ") show \n"
		file<< "/Helvetica findfont \n"
		file<< "15 scalefont setfont \n"
		file<< "250 5 moveto \n"
		file<< "(" << hl << ") show \n"
		file<< "gsave \n"
		file<< "14 250 moveto \n"
		file<< "90 rotate \n"
		file<< "(" << vl << ") show \n"
		file<< "grestore \n"
		file<< "/Helvetica findfont \n"
		file<< "8 scalefont setfont \n";
		file<<for(int i = 0; i < hn; i++)
		{
			file << 30+((i+1)*intervalh) << " 22 moveto \n"
			file<< "(" << label[i] << ")" << " show \n";
		}
		file<< "1 0 0 setrgbcolor \n";
		for(int i = 0; i < hn; i++)
		{
			file<< 30+((i+1)*intervalh) << " 30 5 " << b1[i] * intervalv << " rectfill \n";
		}
		file<< "0 0 1 setrgbcolor \n";
		for(int i = 0; i < hn; i++)
		{
			file<< 30+((i+1)*intervalh) + 5 << " 30 5 " << b2[i] * intervalv << " rectfill \n";
		}
		file<< "1 0 0 setrgbcolor \n";
		for(int i = 0; i < hn; i++)
		{
			file<< "gsave \n"
			file<< "28 " << (b1[i] * intervalv) + 25<< " moveto \n"
			file<< "90 rotate \n"
			file<< "(" << b1[i] << ") show \n"
			file<< "grestore \n";
		}
		file << "0 0 1 setrgbcolor \n";
		for(int i = 0; i < hn; i++)
		{
			file<< "gsave \n"
			file<< "28 " << (b2[i] * intervalv) + 25<< " moveto \n"
			file<< "90 rotate \n"
			file<< "(" << b2[i] << ") show \n"
			file<< "grestore \n";
		}

	}
    	
    	void graphictext()
	{
		// This function includes logos.
		char x;
		cout<<"Enter which logo you want out of Google, DELL, Target, Mitsubishi, Adidas or Cisco \n";
		cout << "Enter g for Google, d for Dell, t, for Target, m for Mitsubishi, a for Adidas or c for cisco \n";
		cin>>x;
		//string logo = "x";
		
		switch(x)
		{
			case 'g' :
			file<<"/Times-Roman findfont \n";
			file<<"32"<<' '<<"scalefont \n";
			file<<"setfont \n";
			file<<"100"<<' '<<"20"<<' '<<"translate \n";
			file<<"2"<<' '<<"1"<<' '<<"scale \n";
			file<<"newpath \n";
			file<<"0"<<' '<<"0"<<' '<<"moveto \n";
			file<<"(G) true charpath \n";
			file<<"2"<<' '<<"setlinewidth \n";
			file<<"0"<<' '<<"0"<<' '<<"1"<<' '<<"setrgbcolor \n";
			file<<"fill \n";
			
			file<<"1"<<' '<<"0"<<' '<<"translate \n";
			file<<"newpath \n";
			file<<"20"<<' '<<"0"<<' '<<"moveto \n";
			file<<"(o) true charpath \n";
			file<<1<<' '<<"0"<<' '<<"0"<<' '<<"setrgbcolor \n";
			file<<"fill \n";
			
			file<<"1"<<' '<<"0"<<' '<<"translate \n";
			file<<"newpath \n";
			file<<"30"<<' '<<"0"<<' '<<"moveto \n";
			file<<"(o) true charpath \n";
			file<<"1"<<' '<<"1"<<' '<<"0"<<' '<<"setrgbcolor \n";
			file<<"fill \n";
			
			file<<"1"<<' '<<"0"<<' '<<"translate \n";
			file<<"newpath \n";
			file<<"50"<<' '<<"0"<<' '<<"moveto \n";
			file<<"(g) true charpath \n";
			file<<"0"<<' '<<"0"<<' '<<"1"<<' '<<"setrgbcolor \n";
			file<<"fill \n";
			
			file<<"1"<<' '<<"0"<<' '<<"translate \n";
			file<<"newpath \n";
			file<<"80"<<' '<<"0"<<' '<<"moveto \n";
			file<<"(l) true charpath \n";
			file<<"0"<<' '<<"1"<<' '<<"0"<<' '<<"setrgbcolor \n";
			file<<"fill \n";
			
			file<<"1"<<' '<<"0"<<' '<<"translate \n";
			file<<"newpath \n";
			file<<"90"<<' '<<"0"<<' '<<"moveto \n";
			file<<"(e) true charpath \n";
			file<<"1"<<' '<<"0"<<' '<<"0"<<' '<<"setrgbcolor \n";
			file<<"fill \n";
			
			
			break;
			
			case 'd' :
			file<<"300"<<' '<<"300"<<' '<<"220"<<' '<<"0"<<' '<<"360"<<' '<<"arc \n";
			file<<"stroke \n";
			file<<"/Times-Roman findfont \n";
			file<<"40"<<' '<<"scalefont \n";
			file<<"setfont \n";
			file<<"240"<<' '<<"300"<<' '<<"translate \n";
			file<<"2"<<' '<<"1"<<' '<<"scale \n";
			file<<"newpath \n";
			file<<"0"<<' '<<"0"<<' '<<"moveto \n";
			file<<"(D) true charpath \n";
			file<<"2"<<' '<<"setlinewidth \n";
			file<<"0"<<' '<<"1"<<' '<<"1"<<' '<<"setrgbcolor \n";
			file<<"fill \n";
			
			
			break;
			
			case 't' :
			file<<"200"<<' '<<"200"<<' '<<"150"<<' '<<"0"<<' '<<"360"<<' '<<"arc \n";
			file<<"1"<<' '<<"0"<<' '<<"0"<<' '<<"setrgbcolor \n";
			file<<"fill \n";
			file<<"200"<<' '<<"200"<<' '<<"100"<<' '<<"0"<<' '<<"360"<<' '<<"arc \n";
			file<<"1"<<' '<<"1"<<' '<<"1"<<' '<<"setrgbcolor \n";
			file<<"fill \n";
			file<<"200"<<' '<<"200"<<' '<<"50"<<' '<<"0"<<' '<<"360"<<' '<<"arc \n";
			file<<"1"<<' '<<"0"<<' '<<"0"<<' '<<"setrgbcolor \n";
			file<<"fill \n";
			file<<"/Times-Roman findfont \n";
			file<<"25"<<' '<<"scalefont \n";
			file<<"setfont \n";
			file<<"100"<<' '<<"20"<<' '<<"translate \n";
			file<<"2"<<' '<<"1"<<' '<<"scale \n";
			file<<"newpath \n";
			file<<"0"<<' '<<"0"<<' '<<"moveto \n";
			file<<"(TARGET) true charpath \n";
			file<<"5"<<' '<<"setlinewidth \n";
			file<<"1"<<' '<<"0"<<' '<<"0"<<' '<<"setrgbcolor \n";
			file<<"fill \n";
		
			break;
			
			case 'm' :
			file<<"300"<<' '<<"300"<<' '<<"moveto \n";
			file<<"50"<<' '<<"-50"<<' '<<"rlineto \n";
			file<<"-50"<<' '<<"-50"<<' '<<"rlineto \n";
			file<<"-50"<<' '<<"50"<<' '<<"rlineto \n";
			file<<"closepath \n";
			
			file<<"300"<<' '<<"200"<<' '<<"moveto \n";
			file<<"-100"<<' '<<"0"<<' '<<"rlineto \n";
			file<<"-50"<<' '<<"-50"<<' '<<"rlineto \n";
			file<<"100"<<' '<<"0"<<' '<<"rlineto \n";
			file<<"closepath \n";
			
			file<<"300"<<' '<<"200"<<' '<<"moveto \n";
			file<<"100"<<' '<<"0"<<' '<<"rlineto \n";
			file<<"50"<<' '<<"-50"<<' '<<"rlineto \n";
			file<<"-100"<<' '<<"0"<<' '<<"rlineto \n";
			file<<"closepath \n";
			
			file<<"/Times-Roman findfont \n";
			file<<"20"<<' '<<"scalefont \n";
			file<<"setfont \n";
			file<<"200"<<' '<<"100"<<' '<<"translate \n";
			file<<"2"<<' '<<"1"<<' '<<"scale \n";
			file<<"newpath \n";
			file<<"0"<<' '<<"0"<<' '<<"moveto \n";
			file<<"(MITSUBISHI) true charpath \n";
			file<<"fill \n";
			
			break;
			
			case 'a' :
			file<<"0"<<' '<<"300"<<' '<<"moveto \n";
			file<<"100"<<' '<<"30"<<' '<<"rlineto \n";
			file<<"50"<<' '<<"-180"<<' '<<"rlineto \n";
			file<<"-100"<<' '<<"0"<<' '<<"rlineto \n";
			file<<"closepath \n";
			
			file<<"180"<<' '<<"400"<<' '<<"moveto \n";
			file<<"100"<<' '<<"30"<<' '<<"rlineto \n";
			file<<"70"<<' '<<"-280"<<' '<<"rlineto \n";
			file<<"-100"<<' '<<"0"<<' '<<"rlineto \n";
			file<<"closepath \n";
			
			file<<"400"<<' '<<"500"<<' '<<"moveto \n";
			file<<"100"<<' '<<"30"<<' '<<"rlineto \n";
			file<<"50"<<' '<<"-180"<<' '<<"rlineto \n";
			file<<"-100"<<' '<<"0"<<' '<<"rlineto \n";
			file<<"closepath \n";
			
			file<<"/Times-Roman findfont \n";
			file<<"40"<<' '<<"scalefont \n";
			file<<"setfont \n";
			file<<"200"<<' '<<"100"<<' '<<"translate \n";
			file<<"2"<<' '<<"1"<<' '<<"scale \n";
			file<<"newpath \n";
			file<<"0"<<' '<<"0"<<' '<<"moveto \n";
			file<<"(adidas) true charpath \n";
			file<<"10"<<' '<<"setlinewidth \n";
			file<<"fill \n";
			break;
			
			case 'c':
			file<<50<<' '<<300<<' '<<"moveto";
			file<<0<<' '<<100<<' '<<"rlineto";
			file<<100<<' '<<300<<' '<<"moveto";
			file<<0<<' '<<150<<' '<<"rlineto";
			file<<150<<' '<<250<<' '<<"moveto";
			file<<0<<' '<<250<<' '<<"rlineto";
			file<<200<<' '<<300<<' '<<"moveto";
			file<<0<<' '<<150<<' '<<"rlineto";
			file<<150<<' '<<300<<' '<<"moveto";
			file<<0<<' '<<100<<' '<<"rlineto";
			file<<300<<' '<<300<<' '<<"moveto";
			file<<0<<' '<<150<<' '<<"rlineto";
			file<<350<<' '<<250<<' '<<"moveto";
			file<<0<<' '<<250<<' '<<"rlineto";
			file<<400<<' '<<300<<' '<<"moveto";
			file<<0<<' '<<150<<' '<<"rlineto";
			file<<450<<' '<<300<<' '<<"moveto";
			file<<0<<' '<<100<<' '<<"rlineto";
			file<<1<<' '<<"setlinecap";
			file<<0<<' '<<0<<' '<<1<<' '<<"setrgbcolor";
			file<<"fill";
			
			file<<"/Times-Roman findfont";
			file<<70<<' '<<"scalefont";
			file<<"setfont";
			file<<40<<' '<<100<<' '<<"translate";
			file<<2<<' '<<1<<' '<<"scale";
			file<<"newpath";
			file<<0<<' '<<0<<' '<<"moveto";
			file<<"(CISCO) true charpath";
			file<<20<<' '<<"setlinewidh";
			file<<1<<' '<<0<<' '<<0<<' '<<"setrgbcolor";
			file<<"fill";
			
			break;		
			
		}
	}

    	void closefile()
	{
		file.close();
	}

				
    	};

    int main()
    {
    	int input = 1; // Integer variable to store user's choice
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
		double x1, y1, x2, y2;// coordinated of starting and ending point of line
		cout << "Enter the coordinates of the starting point \n";
		cin >> x1;
		cin >> y1;
		cout << "Enter the coordinates of the ending point \n";
		cin >> x2;
		cin >> y2;
		p.line(x1,y1,x2,y2);
		break;

	case 2 :
		double x, y, w, h; // Double variables to store starting coordinates of rectangle, its width and height
		cout << " Enter starting coordinates \n";
		cin >> x;
		cin >> y;
		cout << "Enter width and height \n";
		cin >> w;
		cin >> h;
		p.rect(x, y, w, h);
		break;

	case 3 :
		double xc, yc, r; // Double variables to store coordinates of center of circle and its radius
		cout << "Enter the coordinates of the center \n";
		cin >> xc;
		cin >> yc;
		cout << "Enter the radius of the circle \n";
		cin >> r;
		p.circle(xc, yc, r);
		break;

	case 4 :
		cout << "Enter number of lines \n";
		int n; // Integer variable to store number of lines
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
			double x3, y3; // double variables to store coordinates of vertices
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
			double r1, r2; // Double variables to store horizontal and vertical radii
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
			double s; // Double variable to store length of a side in the star
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
			double l; // Double variable to store length of a side in the polygon
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
			int rows, cols; // Integer variables to store number of rows and columns in the grid
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
			
			case 18 :
			string title, hl, vl; // string variables to store title of graph and labels on horizontal and vertical axes
			int hn; // integer variable to store number of values to plot
			cout << "Enter Graph Title \n";
			//getline(cin, title);
			cin >> title;
			cout << "Enter Horizontal axis label and Vertical axis label \n";
			//getline(cin, hl);
			//getline(cin, vl);
			cin >> hl;
			cin >> vl;
			cout << "Enter number of bars (1 or 2) \n";
			cin >> n;
			switch(n)
			{
			case 1 :
			{
				cout << "Enter number of values on horizontal axis \n";
				cin >> hn;
				double b1[hn];//double array to store plot values on horizontal axis 
				string label[hn];//string array to store bar labels on horizontal axis
				double intervalh;// double variable to store gap between 2 values on x axis
				intervalh = 500 / hn;
				for(int i = 0; i < hn; i ++)
				{
					cout << "Enter label " << i+1 << '\n';
					cin >> label[i];
					cout << "Enter value " << i+1 << '\n';
					cin >> b1[i];
				}
				double max;//double variable to store max value so that the graph does not exceed beyond screen space
				max = b1[0];
				for(int i = 0; i < hn-1; i++)
				{
					if(b1[i+1] > max)
					{
						max = b1[i+1];
					}
				}
				double intervalv;//double variable to store gap between 2 values on y axis
				intervalv = 500/max;
				p.bargraph1(title, hl, vl, hn, intervalh, intervalv, label, b1);
				break;
			}

			case 2 :
			{
				cout << "Enter number of values on horizontal axis \n";
				cin >> hn;
				double b1[hn];
				string label[hn];
				double intervalh;
				intervalh = 500 / hn;
				double b2[hn];
				for(int i = 0; i < hn; i ++)
				{
					cout << "Enter label " << i+1 << '\n';
					cin >> label[i];
				}
				for(int i = 0; i < hn; i ++)
				{
					cout << "Enter value " << i+1 << " for Bar 1 " << '\n';
					cin >> b1[i];
					cout << "Enter value " << i+1 << " for Bar 2 " << '\n';
					cin >> b2[i];
				}
				double max;
				max = b1[0];
				for(int i = 0; i < hn-1; i++)
				{
					if(b1[i+1] > max)
					{
						max = b1[i+1];
					}
					if(b2[i+1] > max)
					{
						max = b2[i+1];
					}
				}
				double intervalv;
				intervalv = 500 / max;
				p.bargraph2(title, hl, vl, hn, intervalh, intervalv, label, b1, b2);
				break;
			}
			}
			break;
	}

		}

	p.closefile();
}
    
