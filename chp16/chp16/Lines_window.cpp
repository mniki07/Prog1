#include "Lines_window.h"

Lines_window::Lines_window(Point xy, int w, int h, const string& title)
    :Window{ xy,w,h,title },
    next_button{ Point{x_max() - 300,0}, 150, 40, "Next point",
        [](Address, Address pw) {reference_to<Lines_window>(pw).next(); } },
    quit_button{ Point{x_max() - 150,0}, 150, 40, "Quit",
        [](Address, Address pw) {reference_to<Lines_window>(pw).quit(); } },
   /* red_button{ Point{x_max() - 40,40},40,40,"red",
        [](Address, Address pw) {reference_to<Lines_window>(pw).red_pressed(); } },
    blue_button{ Point{x_max() - 40,80},40,40,"blue",
        [](Address, Address pw) {reference_to<Lines_window>(pw).blue_pressed(); } },
    black_button{ Point{x_max() - 40,120},40,40,"black",
       [](Address, Address pw) {reference_to<Lines_window>(pw).black_pressed(); } },*/
    color_menu{ Point{x_max() -70,40},70,20,Menu::vertical,"color" },
    style_menu{ Point{x_max() -70,60},70,20,Menu::vertical,"style" },
    menu_button{ Point{x_max() - 70,40},70,20 ,"Color",
    [](Address, Address pw) {reference_to<Lines_window>(pw).menu_pressed(); } }, 
    menu_button_sty{ Point{x_max() - 70,120},70,20 ,"Style",
    [](Address, Address pw) {reference_to<Lines_window>(pw).menu_pressed_sty(); } },
    next_x{ Point{300,0}, 50, 40, "next x:" },
    next_y{ Point{450,0}, 50, 40, "next y:" },
    xy_out{ Point{100,0}, 100, 40, "current (x,y):" }

{
    attach(next_button);
    attach(quit_button);
   /* attach(red_button);
    attach(blue_button);
    attach(black_button);*/
    attach(next_x);
    attach(next_y);
    attach(xy_out);

    color_menu.attach(new Button{ Point{0,0},0,0,"red",
        [](Address, Address pw) {reference_to<Lines_window>(pw).red_pressed(); } });
    color_menu.attach(new Button{ Point{0,0},0,0,"blue",
        [](Address, Address pw) {reference_to<Lines_window>(pw).blue_pressed(); } });
    color_menu.attach(new Button{ Point{0,0},0,0,"black",
        [](Address, Address pw) {reference_to<Lines_window>(pw).black_pressed(); } });
    attach(color_menu);
    color_menu.hide();
    attach(menu_button);
    style_menu.attach(new Button{ Point{0,0},0,0,"dash",
        [](Address, Address pw) {reference_to<Lines_window>(pw).dash(); } });
    style_menu.attach(new Button{ Point{0,0},0,0,"dot",
        [](Address, Address pw) {reference_to<Lines_window>(pw).dot(); } });
    style_menu.attach(new Button{ Point{0,0},0,0,"dashdotdot",
        [](Address, Address pw) {reference_to<Lines_window>(pw).dashdotdot(); } });
    attach(style_menu);
    style_menu.hide();
    attach(menu_button_sty);
    attach(lines);
}

void Lines_window::red_pressed()
{
     lines.set_color(Color::red);
     //csak ha van pop-up menu
     color_menu.hide();
     menu_button.show();
}
void Lines_window::blue_pressed()
{
     lines.set_color(Color::blue);
     //csak ha van pop-up menu
     color_menu.hide();
     menu_button.show();
}
void Lines_window::black_pressed()
{
     lines.set_color(Color::black);
     //csak ha van pop-up menu
     color_menu.hide();
     menu_button.show();
}
void Lines_window::dash() 
{
    lines.set_style(Line_style(Line_style::dash));
    style_menu.hide();
    menu_button_sty.show();
}
void Lines_window::dot() 
{
    lines.set_style(Line_style(Line_style::dot));
    style_menu.hide();
    menu_button_sty.show();
}
void Lines_window::dashdotdot() 
{
    lines.set_style(Line_style(Line_style::dashdotdot));
    style_menu.hide();
    menu_button_sty.show();
}

void Lines_window::hide_menu()
{
    color_menu.hide();
    menu_button.show(); 

}
void Lines_window::menu_pressed()
{
     menu_button.hide(); 
     color_menu.show(); 

}
void Lines_window::hide_menu_sty()
{
    style_menu.hide();
    menu_button_sty.show(); 

}
void Lines_window::menu_pressed_sty()
{
     menu_button_sty.hide();
     style_menu.show();

}

void Lines_window::quit()
{
    hide();
}

void Lines_window::next()
{
    int x = next_x.get_int();
    int y = next_y.get_int();

    lines.add(Point{ x,y });

    ostringstream ss;
    ss << '(' << x << ',' << y << ')';
    xy_out.put(ss.str());

    redraw();
}