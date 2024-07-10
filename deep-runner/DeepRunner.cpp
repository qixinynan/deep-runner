#include <iostream>

#include "nan/log.h"
#include "nan/nanapp.h"

int main(int argc, char **argv) {
	LOG_INFO("Hello World");
	NanApp app;
	app.CreateWindow("Nan Application", 800, 640);
	app.Run();
	return 0;
}
