// Author : Rutuja Sawant
#ifndef _GRAPHICTEXT_HH
#define _GRAPHICTEXT_HH

#include <iostream>
#include <fstream>

using namespace std;

class GraphicText
{
private:
	ofstream logo;
 public:
	GraphicText(const char filename[])
	{
		logo.open(filename);
    	}

	void google()
	{
		logo<<"/Times-Roman findfont \n";
						logo<<"32"<<' '<<"scalefont \n";
						logo<<"setfont \n";
						logo<<"100"<<' '<<"20"<<' '<<"translate \n";
						logo<<"2"<<' '<<"1"<<' '<<"scale \n";
						logo<<"newpath \n";
						logo<<"0"<<' '<<"0"<<' '<<"moveto \n";
						logo<<"(G) true charpath \n";
						logo<<"2"<<' '<<"setlinewidth \n";
						logo<<"0"<<' '<<"0"<<' '<<"1"<<' '<<"setrgbcolor \n";
						logo<<"fill \n";

						logo<<"1"<<' '<<"0"<<' '<<"translate \n";
						logo<<"newpath \n";
						logo<<"20"<<' '<<"0"<<' '<<"moveto \n";
						logo<<"(o) true charpath \n";
						logo<<1<<' '<<"0"<<' '<<"0"<<' '<<"setrgbcolor \n";
						logo<<"fill \n";

						logo<<"1"<<' '<<"0"<<' '<<"translate \n";
						logo<<"newpath \n";
						logo<<"35"<<' '<<"0"<<' '<<"moveto \n";
						logo<<"(o) true charpath \n";
						logo<<"1"<<' '<<"1"<<' '<<"0"<<' '<<"setrgbcolor \n";
						logo<<"fill \n";

						logo<<"1"<<' '<<"0"<<' '<<"translate \n";
						logo<<"newpath \n";
						logo<<"50"<<' '<<"0"<<' '<<"moveto \n";
						logo<<"(g) true charpath \n";
						logo<<"0"<<' '<<"0"<<' '<<"1"<<' '<<"setrgbcolor \n";
						logo<<"fill \n";

						logo<<"1"<<' '<<"0"<<' '<<"translate \n";
						logo<<"newpath \n";
						logo<<"70"<<' '<<"0"<<' '<<"moveto \n";
						logo<<"(l) true charpath \n";
						logo<<"0"<<' '<<"1"<<' '<<"0"<<' '<<"setrgbcolor \n";
						logo<<"fill \n";

						logo<<"1"<<' '<<"0"<<' '<<"translate \n";
						logo<<"newpath \n";
						logo<<"80"<<' '<<"0"<<' '<<"moveto \n";
						logo<<"(e) true charpath \n";
						logo<<"1"<<' '<<"0"<<' '<<"0"<<' '<<"setrgbcolor \n";
						logo<<"fill \n";
	}

	void dell()
	{
		logo<<"300"<<' '<<"300"<<' '<<"200"<<' '<<"0"<<' '<<"360"<<' '<<"arc \n";
						logo<<"20 setlinewidth \n";
						logo<<"0"<<' '<<"1"<<' '<<"1"<<' '<<"setrgbcolor \n";
						logo<<"stroke \n";
						logo<<"/Times-Roman findfont \n";
						logo<<"40"<<' '<<"scalefont \n";
						logo<<"setfont \n";
						logo<<"200"<<' '<<"320"<<' '<<"translate \n";
						logo<<"2"<<' '<<"1"<<' '<<"scale \n";
						logo<<"newpath \n";
						logo<<"0"<<' '<<"0"<<' '<<"moveto \n";
						logo<<"(DELL) true charpath \n";
						logo<<"10"<<' '<<"setlinewidth \n";
						logo<<"0"<<' '<<"1"<<' '<<"1"<<' '<<"setrgbcolor \n";
						logo<<"fill \n";
	}

	void target()
	{
		logo<<"200"<<' '<<"200"<<' '<<"150"<<' '<<"0"<<' '<<"360"<<' '<<"arc \n";
						logo<<"1"<<' '<<"0"<<' '<<"0"<<' '<<"setrgbcolor \n";
						logo<<"fill \n";
						logo<<"200"<<' '<<"200"<<' '<<"100"<<' '<<"0"<<' '<<"360"<<' '<<"arc \n";
						logo<<"1"<<' '<<"1"<<' '<<"1"<<' '<<"setrgbcolor \n";
						logo<<"fill \n";
						logo<<"200"<<' '<<"200"<<' '<<"50"<<' '<<"0"<<' '<<"360"<<' '<<"arc \n";
						logo<<"1"<<' '<<"0"<<' '<<"0"<<' '<<"setrgbcolor \n";
						logo<<"fill \n";
						logo<<"/Times-Roman findfont \n";
						logo<<"25"<<' '<<"scalefont \n";
						logo<<"setfont \n";
						logo<<"100"<<' '<<"20"<<' '<<"translate \n";
						logo<<"2"<<' '<<"1"<<' '<<"scale \n";
						logo<<"newpath \n";
						logo<<"0"<<' '<<"0"<<' '<<"moveto \n";
						logo<<"(TARGET) true charpath \n";
						logo<<"5"<<' '<<"setlinewidth \n";
						logo<<"1"<<' '<<"0"<<' '<<"0"<<' '<<"setrgbcolor \n";
						logo<<"fill \n";
	}

	void mitsubishi()
	{
		logo<<"300"<<' '<<"300"<<' '<<"moveto \n";
						logo<<"50"<<' '<<"-50"<<' '<<"rlineto \n";
						logo<<"-50"<<' '<<"-50"<<' '<<"rlineto \n";
						logo<<"-50"<<' '<<"50"<<' '<<"rlineto \n";
						logo<<"closepath \n";
						logo<<"1 0 0 setrgbcolor \n";
						logo<<"fill \n";

						logo<<"300"<<' '<<"200"<<' '<<"moveto \n";
						logo<<"-100"<<' '<<"0"<<' '<<"rlineto \n";
						logo<<"-50"<<' '<<"-50"<<' '<<"rlineto \n";
						logo<<"100"<<' '<<"0"<<' '<<"rlineto \n";
						logo<<"closepath \n";
						logo<<"1 0 0 setrgbcolor \n";
						logo<<"fill \n";

						logo<<"300"<<' '<<"200"<<' '<<"moveto \n";
						logo<<"100"<<' '<<"0"<<' '<<"rlineto \n";
						logo<<"50"<<' '<<"-50"<<' '<<"rlineto \n";
						logo<<"-100"<<' '<<"0"<<' '<<"rlineto \n";
						logo<<"closepath \n";
						logo<<"1 0 0 setrgbcolor \n";
						logo<<"fill \n";

						logo<<"/Times-Roman findfont \n";
						logo<<"20"<<' '<<"scalefont \n";
						logo<<"setfont \n";
						logo<<"200"<<' '<<"100"<<' '<<"translate \n";
						logo<<"2"<<' '<<"1"<<' '<<"scale \n";
						logo<<"newpath \n";
						logo<<"0"<<' '<<"0"<<' '<<"moveto \n";
						logo<<"(MITSUBISHI) true charpath \n";
						logo<<"0 0 0 setrgbcolor \n";
						logo<<"fill \n";
	}

	void adidas()
	{
		logo<<"0"<<' '<<"300"<<' '<<"moveto \n";
						logo<<"100"<<' '<<"30"<<' '<<"rlineto \n";
						logo<<"50"<<' '<<"-180"<<' '<<"rlineto \n";
						logo<<"-100"<<' '<<"0"<<' '<<"rlineto \n";
						logo<<"closepath \n";
						logo<<"fill \n";

						logo<<"180"<<' '<<"400"<<' '<<"moveto \n";
						logo<<"100"<<' '<<"30"<<' '<<"rlineto \n";
						logo<<"70"<<' '<<"-280"<<' '<<"rlineto \n";
						logo<<"-100"<<' '<<"0"<<' '<<"rlineto \n";
						logo<<"closepath \n";
						logo<<"fill \n";

						logo<<"400"<<' '<<"500"<<' '<<"moveto \n";
						logo<<"100"<<' '<<"30"<<' '<<"rlineto \n";
						logo<<"50"<<' '<<"-380"<<' '<<"rlineto \n";
						logo<<"-100"<<' '<<"0"<<' '<<"rlineto \n";
						logo<<"closepath \n";
						logo<<"fill \n";

						logo<<"/Times-Roman findfont \n";
						logo<<"40"<<' '<<"scalefont \n";
						logo<<"setfont \n";
						logo<<"200"<<' '<<"100"<<' '<<"translate \n";
						logo<<"2"<<' '<<"1"<<' '<<"scale \n";
						logo<<"newpath \n";
						logo<<"0"<<' '<<"0"<<' '<<"moveto \n";
						logo<<"(adidas) true charpath \n";
						logo<<"10"<<' '<<"setlinewidth \n";
						logo<<"fill \n";
	}

	void cisco()
	{
		logo<<50<<' '<<300<<' '<<"moveto \n";
									logo<<0<<' '<<100<<' '<<"rlineto \n";
									logo<<100<<' '<<300<<' '<<"moveto \n";
									logo<<0<<' '<<150<<' '<<"rlineto \n";
									logo<<150<<' '<<250<<' '<<"moveto \n";
									logo<<0<<' '<<250<<' '<<"rlineto \n";
									logo<<200<<' '<<300<<' '<<"moveto \n";
									logo<<0<<' '<<150<<' '<<"rlineto \n";
									logo<<150<<' '<<300<<' '<<"moveto \n";
									logo<<0<<' '<<100<<' '<<"rlineto \n";
									logo<<300<<' '<<300<<' '<<"moveto \n";
									logo<<0<<' '<<150<<' '<<"rlineto \n";
									logo<<350<<' '<<250<<' '<<"moveto \n";
									logo<<0<<' '<<250<<' '<<"rlineto \n";
									logo<<400<<' '<<300<<' '<<"moveto \n";
									logo<<0<<' '<<150<<' '<<"rlineto \n";
									logo<<450<<' '<<300<<' '<<"moveto \n";
									logo<<0<<' '<<100<<' '<<"rlineto \n";
									logo<<1<<' '<<"setlinecap \n";
									logo<<0<<' '<<0<<' '<<1<<' '<<"setrgbcolor \n";
									logo<<"fill \n";

									logo<<"/Times-Roman findfont \n";
									logo<<70<<' '<<"scalefont \n";
									logo<<"setfont \n";
									logo<<40<<' '<<100<<' '<<"translate \n";
									logo<<2<<' '<<1<<' '<<"scale \n";
									logo<<"newpath \n";
									logo<<0<<' '<<0<<' '<<"moveto \n";
									logo<<"(CISCO) true charpath \n";
									logo<<20<<' '<<"setlinewidh \n";
									logo<<1<<' '<<0<<' '<<0<<' '<<"setrgbcolor \n";
									logo<<"fill \n";
	}

	void closefile()
							{
								logo.close();
							}
};

#endif

