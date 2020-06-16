////////////////////////////////////////////////////
//
//	Nazwa klasy:
//	HRTimer
//
//	Opis:
//	Klasa posiada metody ktore pozwalaja liczyc czas wykonywania funkcji
//
//	Autor:
//	Marcin Skawinski
//
//	Data:
//	13.01.2019
//
////////////////////////////////////////////////////



#if !defined (HRTimer_h)
#define HRTimer_h

#include <iostream>
#include <chrono>


class HRTimer
{
public:
	HRTimer();                                                                                                          //konstruktor bezparametrowy klasy HRTimer
	HRTimer(const std::chrono::steady_clock::time_point & sta, const std::chrono::steady_clock::time_point & sto);      //konstruktor parametrowy klasy HRTimer
	HRTimer(const HRTimer & copy);                                                                                      //konstruktor kopiujacy klasy HRTimer
	~HRTimer();                                                                                                         //destruktor klasy HRTimer

	HRTimer & operator=(const HRTimer & e);                                     //przeciazony operator = dla klasy HRTimer
	friend std::ostream & operator << (std::ostream & a, const HRTimer & b);    //przeciazony operator << dla klasy HRTimer [wyswietla czas wykonywania funkcji w ns]

	void start();                                                               //metoda startujaca licznik aby policzyc czas wykonywania funkcji
	void stop();                                                                //metoda zatrzymujaca licznik aby policzyc czas wykonywania funkcji


	std::chrono::steady_clock::time_point getStart() const;                     //metoda zwracajaca czas startu dla obliczen
	std::chrono::steady_clock::time_point getStop() const;                      //metoda zwracajaca czas stopu dla obliczen

	long long toMicroSeconds();                                                 //metoda konwertujaca nanosekundy do mikrosekund
	long long toSeconds();                                                      //metoda konwertujaca nanosekundy do sekund
	long long toMilliSeconds();                                                 //metoda konwertujaca nanosekundy do milisekund


protected:
	std::chrono::steady_clock::time_point sta;                                  //zmienna przechowujaca moment rozpoczecia liczenia czasu
	std::chrono::steady_clock::time_point sto;                                  //zmienna przechowujaca moment zakonczenia liczenia czasu
};

#endif
