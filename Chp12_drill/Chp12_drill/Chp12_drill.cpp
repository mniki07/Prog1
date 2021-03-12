#include "Graph.h"
#include "Simple_window.h"
#include "std_lib_facilities.h"

using namespace Graph_lib;
int main()
{
	Point tl{ 100,100 };
	Simple_window win{tl, 600,400, "My window"};
	
	win.wait_for_button();
	Axis xa{ Axis::x, Point{20,300},280,10, "x axis" };
	xa.set_color(Color::dark_green);
	xa.label.set_color(Color::blue);
	win.attach(xa);
	win.set_label("My window #2");
	win.wait_for_button();

	Axis ya{ Axis::y, Point{20,300}, 280, 10, "y axis" };
	ya.set_color(Color::cyan);
	ya.label.set_color(Color::dark_red);
	win.attach(ya);
	win.set_label("My window #3");
	win.wait_for_button();

	
	Function sine{ sin, 0, 100,Point{20,150}, 1000,50,50 };
	win.attach(sine);
	win.set_label("My window #4");
	win.wait_for_button();

	sine.set_color(Color::magenta);

	Graph_lib::Polygon poly;
	poly.add(Point{ 300,200 });
	poly.add(Point{ 350,100 });
	poly.add(Point{ 400,200 });
	win.wait_for_button();

	poly.set_color(Color::red);
	poly.set_style(Line_style::dash);
	win.attach(poly);
	win.set_label("My window #5");
	win.wait_for_button();


	Graph_lib::Rectangle r{ Point{200,200},100,50 };
	win.attach(r);
	win.set_label("My window #6");
	win.wait_for_button();



	Closed_polyline poly_rect;
	poly_rect.add(Point{ 100,50 });
	poly_rect.add(Point{ 200,50 });
	poly_rect.add(Point{ 200,100 });
	poly_rect.add(Point{ 100,100 });
	poly_rect.add(Point{ 50,90});
	win.attach(poly_rect);
	win.wait_for_button();
	poly_rect.add(Point{ 50,75 });
	


	r.set_fill_color(Color::dark_cyan);
	poly.set_style(Line_style(Line_style::dash, 4));
	poly_rect.set_style(Line_style(Line_style::dash, 2));
	poly_rect.set_fill_color(Color::green);
	win.set_label("My window #7");
	win.wait_for_button();


	Text t{ Point{150,150}, "Hello, graphical world!" };
	win.attach(t);
	win.set_label("My window #8");

	t.set_font(Font::helvetica);
	t.set_font_size(20);
	win.set_label("My window #9");
	win.wait_for_button();


	Image ii{ Point(10,10), "image.jpg" };
	win.attach(ii);
	win.set_label("My window #10");

	ii.move(50,50);
	win.set_label("My window #11");
	win.wait_for_button();

	Circle c{ Point{100,200},50 };
	Graph_lib::Ellipse e{ Point{100,200}, 75,25 };
	e.set_color(Color::dark_red);
	Graph_lib::Mark m{ Point{100,200},'x' };
	ostringstream oss;
	oss << "screen size: " << x_max() << "*" << y_max()
		<< "; window size: " << win.x_max() << "*" << win.y_max();
	Text sizes{ Point{150,20},oss.str() };
	Image cal{ Point{10,10},"pc.gif" }; 
	cal.set_mask(Point{ 50,50 }, 300,300); 
	win.attach(c);
	win.attach(m);
	win.attach(e);
	win.attach(sizes);
	win.attach(cal);
	win.set_label("My window #12");
	win.wait_for_button();

}
