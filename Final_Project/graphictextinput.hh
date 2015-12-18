#ifndef _GRAPHICTEXTINPUT_HH
#define _GRAPHICTEXTINPUT_HH

#include "graphictext.hh"

#include <iostream>
using namespace std;

void graphictextinput()
{
	GraphicText g("logo.ps");
	char x;
				cout<<"Enter which logo you want out of Google, DELL, Target, Mitsubishi, Adidas or Cisco \n";
				cout << "Enter g for Google, d for Dell, t, for Target, m for Mitsubishi, a for Adidas or c for cisco \n";
				cin>>x;
				switch(x)
				{
				case 'g':
					g.google();
					break;

				case 'd' :
					g.dell();
					break;

				case 't' :
					g.target();
					break;

				case 'm' :
					g.mitsubishi();
					break;

				case 'a' :
					g.adidas();
					break;

				case 'c' :
					g.cisco();
					break;
				}
				}

#endif

