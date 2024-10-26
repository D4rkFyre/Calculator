#include "App.h"
#include "Window.h"


bool App::OnInit() {
	window = new Window();
	window->Show();
	return true;
}