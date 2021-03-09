#include <iostream>
#include "Graph.h"
#include "Simple_window.h"

int main()
{
	Simple_window win{ Point(100,100), 800,1000,"Window" };
	win.wait_for_button();
	int x_size = 800; 
	int y_size = 800;
	int x_grid = 100;
	int y_grid = 100;
	Lines grid;
	for (int x = x_grid; x <= x_size; x += x_grid)
		grid.add(Point{ x,0 }, Point{ x,y_size });
	for (int y = y_grid; y <= y_size; y += y_grid)
		grid.add(Point{ 0,y }, Point{ x_size,y });
	grid.set_color(Color::black);
	win.attach(grid);
	win.wait_for_button();
	Vector_ref<Graph_lib::Rectangle> vr;
	for (int j = 0; j < 8; ++j)
	{
			vr.push_back(new Graph_lib::Rectangle{ Point{j * 100,j * 100},100,100 });
			vr[vr.size()-1].set_fill_color(Color::red);
			win.attach(vr[vr.size()-1]);
	}
	win.wait_for_button();
	Image kep{ Point{0,200},"letöltés.jpeg" };
	Image kep1{ Point{0,400},"letöltés.jpeg" };
	Image kep2{ Point{0,600},"letöltés.jpeg" };
	win.attach(kep1);
	win.attach(kep);
	win.attach(kep2);
	win.wait_for_button();
	Image mozg{ Point{0,0},"cpp.jpg" };
	win.attach(mozg);
	win.wait_for_button();
	int k=0;
	for (int i = 1; i < 64; i++)
	{
		k++;
		if (k%8==0)
		{
			mozg.move(-800,100);
		}
		mozg.move(100, 0);
		win.wait_for_button();
	}

}
