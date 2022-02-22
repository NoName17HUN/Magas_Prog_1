/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images` -std=c++11
*/
#include "Simple_window.h"
#include "Graph.h"

double one(double) { return 1; }

double square(double x) { return x*x; }

int main()
{
int max_width = 800;
int max_height = 1000;
Simple_window win {Point{100, 100},	max_width, max_height, "Graphics classes"};


int x_size =800;
int y_size = 800;
int x_grid = 100;
int y_grid = 100;
Lines grid;
for (int x=x_grid; x<x_size; x+=x_grid)
grid.add(Point{x,0},Point{x,y_size});
for (int y = y_grid; y<y_size; y+=y_grid)
grid.add(Point{0,y},Point{x_size,y});

Line l(Point{000,800}, Point{800,800});
win.attach(l);
win.attach(grid);


win.wait_for_button();
/*x_grid=100;
y_grid=125
Lines grid;
for (int x=x_grid; x<x_size; x+=x_grid)
grid.add(Point{x,0},Point{x,y_size});
for (int y = y_grid; y<y_size; y+=y_grid)
grid.add(Point{0,y},Point{x_size,y});
*/

//EXIT OUT CONFIRMATION
win.wait_for_button();
return 0;
}
 //1

