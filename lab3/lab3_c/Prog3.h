#include <iostream>
#include <malloc.h>
#ifndef _CIRCLE_H_
#define _CIRCLE_H_
#include "gtest/gtest.h"
#define SIZEMASS 5
#define SIZEWORD 10
namespace Prog3{
	class Massive{
		private:
			int sizemass=SIZEMASS;
			int sizeword=SIZEWORD;
			int realsize;
			char** mass;
		public:
			Massive & operator =(Massive &st);
			Massive & operator ==(const Massive &st);
			Massive(Massive &&st);
			void setsize(int size) {sizemass=size;}
			~Massive(){ for(int i=0;i<sizemass;i++) delete[] mass[i]; delete[] mass;}
			void memory();
			char** newmass();
			Massive(): realsize(0) {memory();}
			explicit Massive(char* word);
			Massive(int size,char** words);
			void operator +=(char* word);
			//std::ostream & Output(std::ostream &) const;
			int Getsize() const{return sizemass;}
			int Getrealsize() const{return realsize;}
			int operator ()(char* word) const;
			const char* operator[](int i) const { return mass[i];}
			void Getmass(char symbol) const;
			void operator()() const;
			friend std::ostream & operator <<(std::ostream &s, const Massive &st);
			void operator()(const Massive &st);
	};
	int Methods();
	void Vibor();
	void Empty_Constructor();
	void Init_Constructor_Word();
	void Init_Constructor_Mass();
	template <class T>
	int getNum(T &a)
	{
		std::cin >> a;
		if (!std::cin.good())
		return -1;
		return 1;
	}
}
#endif
