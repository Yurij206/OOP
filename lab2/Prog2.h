#ifndef _CIRCLE_H_
#define _CIRCLE_H_
#include "gtest/gtest.h"
#include <math.h>
namespace Prog2
{
	class Conhoida{
		private:
		double a,l;
		public:
		Conhoida(double length = 1);
		explicit Conhoida(double a,double length=1);
		Conhoida& setL(double l0);
		Conhoida& setA(double a0) {a=a0; return*this;}
		double getA() const { return a;}
		double getL() const{ return l;}
		double findy(double x) const;
		double findr(double f) const;
		void findrkr() const;
		double Square() const;
		void Pereg() const;
	};
	int Vibor();
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

