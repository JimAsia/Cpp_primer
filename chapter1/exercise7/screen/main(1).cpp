#include "screen.h"

using std::cout;

int main()
{
	Screen myScreen(5, 5, 'X');
	myScreen.move(4, 0).set('#').display(cout);
	cout << '\n';
	myScreen.display(cout);
	cout << '\n';
	
	Window_mgr w;
	w.clear(0);
	myScreen.display(cout);
	return 0;
}

