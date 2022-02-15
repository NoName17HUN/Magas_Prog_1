#include "Simple_window.h"
#include "Simple_window.cpp"
#include "Graph.h"
#include "Graph.cpp"
#include "Window.h"
#include "Window.cpp"

int main ()
{
try {   //1
Point tl (100,100);
Simple_window win (tl, 600, 900, "Canvas");
win.wait_for_button();

Axis ya (Axis::y, Point{100,300}, 280, 10, "y axis");
ya.set_color(Color::dark_green); // choose a color
ya.label.set_color(Color::dark_red); // choose a color for the text
win.attach(ya);
win.set_label("Canvas #3");
win.wait_for_button(); 

Function sine (sin,0,100,Point{20,150},1000,50,50); 
win.attach(sine);
win.set_label("Canvas #4");
win.wait_for_button();

sine.set_color(Color::red);

Polygon poly;
poly.add(Point{300,200});
poly.add(Point{350,100});
poly.add(Point{400,200});
poly.set_color(Color::green);
win.attach(poly);
win.set_label("Canvas #5");
win.wait_for_button();

Rectangle r (Point{200,400}, 100, 50); // top left corner, width, height
win.attach(r);
win.set_label("Canvas #6");
win.wait_for_button();

r.add(Point{100,50});
r.add(Point{200,50});
r.add(Point{200,100});
r.add(Point{100,100});
win.attach(r);

r.set_fill_color(Color::blue); // color the inside of the rectangle
poly.set_style(Line_style(Line_style::dash,6));
poly_rect.set_style(Line_style(Line_style::dotted,4));
poly_rect.set_fill_color(Color::green);
win.set_label("Canvas #7");

Text t (Point{150,150}, "This looks horrendous, as it should!");
win.attach(t);
win.set_label("Canvas #8");

t.set_font(Font::times_bold);
t.set_font_size(20);
win.set_label("Canvas #9");

Image ii (Point{200,50),"shrek.jpeg"); 
win.attach(ii);
win.set_label("Canvas #10");
//EXIT OUT CONFIRMATION
win.wait_for_button();
} //1
}
catch(exception& e) {
	//I don't want to write it rn, but it -should- work without one
return 1;
}
catch(...) {
	//I don't want to write it rn, but it -should- work without one
return 2;
}


