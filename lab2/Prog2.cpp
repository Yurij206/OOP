#include <stdio.h>
#include <string.h>
#include "Prog2.h"
namespace Prog2 {
	Conhoida::Conhoida(double length)
	{
		a=0;
		if (length <= 0)
		throw std::logic_error("invalid length");
		l = length;
	}
	Conhoida::Conhoida(double a0,double length)
	{
		a=a0;
		if (length < 0)
		throw std::logic_error("invalid length");
		l = length;
	}
	Conhoida& Conhoida::setL(double l0)
	{
		if (l0 < 0)
		throw std::logic_error("invalid length");
		l = l0;
		return *this;
	}
	double Conhoida::findy(double x) const
	{
		if(x==a) throw std::runtime_error("illegal argument x");
		double dy=(l*l*x*x/((x-a)*(x-a))-x*x);
		if(dy<0) throw std::runtime_error("illegal argument x");
		dy=sqrt(dy);
		return dy;
	}
	double Conhoida::findr(double f) const
	{
		double r=(a/cos(f))+l;
		return r;
	}
	void Conhoida::findrkr() const
	{
		int N,i=0;
		double buf;
		if(a==l || a==-l) N=1;
		else{
			if(a==0 || a>l) N=2;
			else N=3;
		}
		buf=(l+a)*(l+a)/l;
		if(buf!=0 && i<N){
			std::cout << "Радиус кривизны точки "<<i<<" --> "<<buf<<std::endl;
			i++;
		}
		buf=(l-a)*(l-a)/l;
		if(buf!=0 && i<N){
			std::cout << "Радиус кривизны точки "<<i<<" --> "<<buf<<std::endl;
			i++;
		}
		buf=sqrt(l*l-a*a)*l/2*a;
		if(buf!=0 && i<N) std::cout << "Радиус кривизны точки "<<i<<" --> "<<buf<<std::endl;
	} 
	double Conhoida::Square() const
	{
		double s=0;
		if(l>a && a!=0) s=(a*sqrt(l*l-a*a))-(2*a*l*log((l+sqrt(l*l-a*a))/a))+(l*l*acos(a/l));
		return s;
	}
	void Conhoida::Pereg() const
	{
		if(l/a>1) std::cout<<"Точка перегиба --> "<<2.35*a<<std::endl;
		if(l/a==1){
			std::cout<<"Точка перегиба 1 --> "<<sqrt(3)*a<<std::endl;
			std::cout<<"Точка перегиба 2 --> "<<0<<std::endl;
			std::cout<<"Точка перегиба 3 --> "<<-sqrt(3)*a<<std::endl;
		}
		if(l/a<1){
			std::cout<<"Точка перегиба 1 --> "<<1.38*a<<std::endl;
			std::cout<<"Точка перегиба 2 --> "<<0.57*a<<std::endl;
			std::cout<<"Точка перегиба 3 --> "<<-1.9*a<<std::endl;
	}
	}
	int Vibor(){
	const char *pr = "";
	int number;
	do{
		std::cout << pr << std::endl;
		std::cout <<"Выберете конструктор:"<<std::endl;
		std::cout <<"1 - Пустой"<<std::endl;
		std::cout <<"2 - Инициализирующий"<<std::endl;
		std::cout <<"3 - Выход"<<std::endl;
		std::cout << "Enter" << " --> ";
		pr = "You are wrong; repeat please!";
		if (getNum(number) < 0){
		number=0;
		std::cin.clear();
		std::cin.ignore();
		}
	} while (number < 1 || number > 4);
	switch(number){
		case 1:
		{
		Conhoida c;
		int i;
		pr="";
		do{
			std::cout << pr << std::endl;
			std::cout <<"Выберете:"<<std::endl;
			std::cout <<"1 - Оставить пустой конструктор"<<std::endl;
			std::cout <<"2 - Ввести данные для конхоиды"<<std::endl;
			std::cout << "Enter" << " --> ";
			pr = "You are wrong; repeat please!";
			if (getNum(i) < 0){
			i=0;
			std::cin.clear();
			std::cin.ignore();
			}
		} while (i!=2 && i!=1);
		int k=1;
		if(i==1){
			
			double x;
			pr="";
		do{
			std::cout << pr << std::endl;
			std::cout << "Введите координату х(double) для поиска y" << " --> ";
			pr = "You are wrong; repeat please!";
			if (getNum(x) < 0){
			k=0;
			std::cin.clear();
			std::cin.ignore();
			}
		} while (k==0);
			std::cout<<"y="<<c.findy(x)<<std::endl;
			double f;
			pr="";
			k=1;
			do{
			std::cout << pr << std::endl;
			std::cout << "Введите угол f(double) для поиска расстояния от центра до точки в полярных координатах" << " --> ";
			pr = "You are wrong; repeat please!";
			if (getNum(x) < 0){
			k=0;
			std::cin.clear();
			std::cin.ignore();
			}
		} while (k==0);
			std::cout<<"p="<<c.findr(f)<<std::endl;
			c.findrkr();
			std::cout << "Площадь петли --> "<<c.Square()<<std::endl;
			std::cout << "Точки перегиба : "<<std::endl;
			c.Pereg();
			return 0;
		}
		if(i==2){
			std::cout << "Введите данные для кохоиды:"<<std::endl;
			double a1;
			
			pr="";
			do{
			k=1;
			std::cout << pr << std::endl;
			std::cout << "Введите a" << " --> ";
			pr = "You are wrong; repeat please!";
			if (getNum(a1) < 0){
			k=0;
			std::cin.clear();
			std::cin.ignore();
			}
		} while (k==0);
			double l1;
			pr="";
			
			do{
			k=1;
			std::cout << pr << std::endl;
			std::cout << "Введите l" << " --> ";
			pr = "You are wrong; repeat please!";
			if (getNum(l1) < 0){
			k=0;
			std::cin.clear();
			std::cin.ignore();
			}
		} while (k==0);
			c.setA(a1);
			c.setL(l1);
			double x;
			pr="";
			
			do{
			k=1;
			std::cout << pr << std::endl;
			std::cout << "Введите координату х(double) для поиска y" << " --> ";
			pr = "You are wrong; repeat please!";
			if (getNum(x) < 0){
			k=0;
			std::cin.clear();
			std::cin.ignore();
			}
		} while (k==0);
			std::cout<<"y="<<c.findy(x)<<std::endl;
			double f;
			
			pr="";
			
			do{
			k=1;
			std::cout << pr << std::endl;
			std::cout << "Введите угол f(double) для поиска расстояния от центра до точки в полярных координатах" << " --> ";
			pr = "You are wrong; repeat please!";
			if (getNum(x) < 0){
			k=0;
			std::cin.clear();
			std::cin.ignore();
			}
		} while (k==0);
			std::cout<<"p="<<c.findr(f)<<std::endl;
			c.findrkr();
			std::cout << "Площадь петли"<<" --> "<<c.Square()<<std::endl;
			std::cout << "Точки перегиба : "<<std::endl;
			c.Pereg();
			return 0;
		}
		}
		case 2:
		{
			int k;
			std::cout << "Введите данные для кохоиды:"<<std::endl;
			double a1;
			
			pr="";
			do{
			k=1;
			std::cout << pr << std::endl;
			std::cout << "Введите a" << " --> ";
			pr = "You are wrong; repeat please!";
			if (getNum(a1) < 0){
			k=0;
			std::cin.clear();
			std::cin.ignore();
			}
		} while (k==0);
			double l1;
			pr="";
			
			do{
			k=1;
			std::cout << pr << std::endl;
			std::cout << "Введите l" << " --> ";
			pr = "You are wrong; repeat please!";
			if (getNum(l1) < 0){
			k=0;
			std::cin.clear();
			std::cin.ignore();
			}
		} while (k==0);
			Conhoida c(a1,l1);
			c.setA(a1);
			c.setL(l1);
			double x;
			pr="";
			std::cout<<l1+a1;
			do{
			k=1;
			std::cout << pr << std::endl;
			std::cout << "Введите координату х(double) для поиска y" << " --> ";
			pr = "You are wrong; repeat please!";
			if (getNum(x) < 0){
			k=0;
			std::cin.clear();
			std::cin.ignore();
			}
		
		} while (k==0 || x>(l1+a1) || x<-l1+a1);
			std::cout<<"y="<<c.findy(x)<<std::endl;
			double f;
			
			pr="";
			
			do{
			k=1;
			std::cout << pr << std::endl;
			std::cout << "Введите угол f(double) для поиска расстояния от центра до точки в полярных координатах" << " --> ";
			pr = "You are wrong; repeat please!";
			if (getNum(x) < 0){
			k=0;
			std::cin.clear();
			std::cin.ignore();
			}
		} while (k==0);
			std::cout<<"p="<<c.findr(f)<<std::endl;
			c.findrkr();
			std::cout << "Площадь петли"<<" --> "<<c.Square()<<std::endl;
			std::cout << "Точки перегиба : "<<std::endl;
			c.Pereg();
			return 0;
		}
		case 3:
		{
			return 1;
		}
	}
	return 0;
	}
}
