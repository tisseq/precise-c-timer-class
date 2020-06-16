#include "HRTimer.h"
#include <Windows.h>      //do uzycia funkcji Sleep();



int main() {


	HRTimer t;
	t.start();
	Sleep(3000);
	t.stop();
	std::cout << t;

	//std::cout << t.toMicroSeconds() << std::endl;
	//std:: cout << t.toMilliSeconds() << std::endl;
	//std::cout << t.toSeconds() << std::endl;


	//system("pause");
	return 0;
}


