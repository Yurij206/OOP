#include <iostream>
#include <malloc.h>
#ifndef _CIRCLE_H_
#define _CIRCLE_H_
#include "gtest/gtest.h"
#define SIZEMASS 10
#define SIZEWORD 10
namespace Prog3{
	class Massive{
		private:
			static const int sizemass=SIZEMASS;
			static const int sizeword=SIZEWORD;
			int realsize;
			char mass[sizemass][sizeword];
		public:
			Massive(): realsize(0) {}
			explicit Massive(char word[]);
			 Massive(int size,char words[][100]);
			void operator +=(char* word);
			//std::ostream & Output(std::ostream &) const;
			int Getsize() const{return realsize;}
			int operator ()(char* word);
			const char* operator[](int i) const { return mass[i];}
			void Getmass(char symbol) const;
			void operator()();
			friend std::ostream & operator <<(std::ostream &s, const Massive &st);
			void operator ()(const Massive &st);
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
