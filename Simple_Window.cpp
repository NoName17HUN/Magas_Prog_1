#include "Simple_window.h"

int main ()
try
{
Point tl {100,100};
Simple_window lin {tl, 600, 400, "Canvas"};
lin.wait_for_button();
}
catch(exception& e) {
// some error reporting
return 1;
}
catch(...) {
// some more error reporting
return 2;
}


