#include "GUI.h"

using namespace Graph_lib;

struct Lines_window : Graph_lib::Window {
	Lines_window(Point xy, int w, int h, const string& title);
	Open_polyline lines;
	Menu color_menu;
	Menu style_menu;
	
	

	bool wait_for_button();

private:
	Button next_button;
	Button quit_button;
	/*Button red_button;
	Button blue_button;
	Button black_button;*/
	Button menu_button;
	Button menu_button_sty;

	In_box next_x;
	In_box next_y;

	Out_box xy_out;

	void next();
	void quit();
	void red_pressed();
	void blue_pressed() ; 
	void black_pressed();
	void hide_menu();
	void menu_pressed();
	void dash();
	void dot();
	void dashdotdot();
	void hide_menu_sty();
	void menu_pressed_sty();

};