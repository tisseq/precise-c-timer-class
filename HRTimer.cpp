#include "HRTimer.h"



HRTimer::HRTimer() :
        sta{}
,       sto{}
{
}



HRTimer::HRTimer(const std::chrono::steady_clock::time_point & sta, const std::chrono::steady_clock::time_point & sto) :
        sta{ sta }
,       sto{ sto }
{
}



HRTimer::HRTimer(const HRTimer & c) :
        sta{ c.sta }
,       sto{c.sto}
{
}



HRTimer::~HRTimer()
{
}




void HRTimer::start() {
	 sta = std::chrono::high_resolution_clock::now();
}



void HRTimer::stop() {
	sto = std::chrono::high_resolution_clock::now();
}




std::ostream & operator << (std::ostream & a, const HRTimer & b) {

	a << std::chrono::duration_cast<std::chrono::nanoseconds>(b.getStop() - b.getStart()).count() << " ns\n";
	return a;
}



HRTimer & HRTimer :: operator=(const HRTimer & e) {

	if (this != &e) {
		sta = e.sta;
		sto = e.sto;
	}

	return *this;
}



std::chrono::steady_clock::time_point HRTimer::getStart() const {
	return this->sta;
}



std::chrono::steady_clock::time_point HRTimer::getStop() const {
	return this->sto;
}


long long HRTimer::toMicroSeconds() {
	return std::chrono::duration_cast <std::chrono::microseconds>(sto - sta).count();
}


long long HRTimer::toSeconds() {
	return std::chrono::duration_cast <std::chrono::seconds>(sto - sta).count();
}


long long HRTimer::toMilliSeconds() {
	return std::chrono::duration_cast< std::chrono::milliseconds>(sto - sta).count();
}
