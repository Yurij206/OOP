#include <stdio.h>
#include <string.h>
#include "Prog3.h"
#include <string.h>
#define SIZECLASS 10
namespace Prog3
{
	Massive* Mass=new Massive[SIZECLASS];
	int count = 0;
	int num = 0;
	Massive::Massive(char* word)
	{
		memory();
		strcpy(mass[0],word);
		realsize=1;
	}
	Massive & Massive::operator ==(const Massive &st)//перегруженный оператор присваивания
	{
		if(this != &st)
		{
			realsize=st.realsize;
			sizeword=SIZEWORD;
			for(int i=0; i<sizemass;i++) delete[] mass[i];
			delete[] mass;
			sizemass=st.sizemass;
			memory();
			for(int i=0;i<sizemass;i++) strcpy(mass[i],st.mass[i]);
		}
		return *this;
	}
	Massive & Massive::operator =(Massive &st)//перегруженный оператор перемещения
	{
		int buf=st.sizemass;
		st.sizemass=sizemass;
		sizemass=buf;
		buf=st.realsize;
		st.realsize=realsize;
		realsize=buf;
		char** m;
		m=mass;
		mass=st.mass;
		st.mass=m;
		return *this;
	}
	Massive::Massive(Massive &&st): realsize(st.realsize), sizemass(st.sizemass), sizeword(st.sizeword), mass(st.mass) //перемещающий конструктор
	{
		st.mass=nullptr;
	}
	void Massive::operator +=(char* word)
	{
		if(realsize==sizemass)
		{
			sizemass++;
			mass=newmass();
		}
		strcpy(mass[realsize],word);
		realsize++;
	}
	char** Massive::newmass()
	{
		char** m=new char*[sizemass];
		for(int i=0;i<sizemass;i++)
		{
			m[i]=new char[sizeword];
		}
		for(int i=0;i<(sizemass-1);i++)
		{
			strcpy(m[i],mass[i]);
			delete[] mass[i];
		}
		delete[] mass;
		return m;
	}
	void Massive::operator ()(const Massive &st)//копирующий конструктор
	{	
		realsize=0;
		for(int i=0;i<st.realsize;i++)
			*this+=st.mass[i];
	}
	std::ostream & operator <<(std::ostream &s, const Massive &st)
	{
		for(int i=0;i<st.realsize;i++)
			s<<st.mass[i]<<std::endl;
		return s;
	}
	
	/*std::ostream & Massive::Output(std::ostream &s) const
	{
		for(int i=0;i<realsize;i++)
		s<<mass[i]<<std::endl;
		return s;
	}*/
	Massive::Massive(int size,char** words)
	{
		if(size>SIZEMASS)setsize(size);
		memory();
		for(int i=0;i<size;i++)
			strcpy(mass[i], words[i]);
		realsize=size;
	}
	int  Massive::operator ()(char* word) const
	{
		for(int i=0;i<realsize;i++)
		{
			if(strcmp(mass[i],word)==0) 
				return i;
		}
		return -1;
	}
	void Massive::Getmass(char symbol) const
	{
		char** m=new char*[sizemass];
		for(int k=0;k<sizemass;k++)
			m[k]=new char[sizeword];
		int j=0;
		std::cout<<"Массив слов начинающихся на "<<symbol<<": "<<std::endl;
		for(int i=0;i<realsize;i++)
			if(mass[i][0]==symbol)
			{
				strcpy(m[j],mass[i]);
				std::cout<<m[j]<<std::endl;
				j++;
			}
		if(j==0) std::cout<<"Слов, начинающихся на данную букву нет."<<std::endl;
		for(int i=0;i<sizemass;i++)
			delete[] m[i];
		delete[] m;
	}
	void Massive::operator()() const
	{
		char* buf=new char[SIZEWORD];;
		for(int i=0;i<realsize;i++)
		{
			for(int j=i;j<realsize;j++)
			{
				if(strcmp(mass[i],mass[j])>0)
				{
					strcpy(buf,mass[i]);
					strcpy(mass[i],mass[j]);
					strcpy(mass[j],buf);
				}
			}
		}
	delete[] buf;
	}
	void Empty_Constructor()
	{
		Massive m;
		Mass[count](m);
		num=count;
		count++;
		int quit;
		do 
		{
			quit = Methods();
		} while (!quit);
	}
	void Init_Constructor_Word()
	{
		int n;
		char* word=new char[100];
		const char* pr="";
		do{
			n=1;
			std::cout << pr << std::endl;
			std::cout << "Enter" << " --> ";
			if (getNum(word) < 0)
			{
				pr = "You are wrong; repeat please!";
				n=0;
				std::cin.clear();
				std::cin.ignore();
			}
			if(strlen(word)>SIZEWORD)
			{
				pr = "Too large word, repeat please!";
				n=0;
				std::cin.clear();
				std::cin.ignore();
			}
		} while (n!=1);	
		Massive m(word);
		delete[] word;
		Mass[count](m);
		num=count;
		count++;
		int quit;
		do {
			quit = Methods();
		} while (!quit);
	}
	void Init_Constructor_Mass()
	{
		const char* pr = "";
		int size;
		do{
			std::cout << pr << std::endl;
			std::cout <<"Введите колличество слов: ";
			pr = "You are wrong; repeat please!";
			if (getNum(size) < 0)
			{
				size=0;
				std::cin.clear();
				std::cin.ignore();
			}
		} while (size < 1);
		char** words=new char*[size];
		int i;
		for(i=0;i<size;i++)
		{
			pr="";
			int n;
			words[i]=new char[100];
			do{
				n=1;
				std::cout << pr << std::endl;
				std::cout << "Введите слово: ";
				if (getNum(words[i]) < 0)
				{
					pr = "You are wrong; repeat please!";
					n=0;
					std::cin.clear();
					std::cin.ignore();
				}
				if(strlen(words[i])>SIZEWORD)
				{
					pr = "Too large word, repeat please!";
					n=0;
					std::cin.clear();
					std::cin.ignore();
				}
				for(int j=0;j<i;j++){
					if(strcmp(words[i],words[j])==0)
					{
						pr="Это слово уже есть в массиве";
						n=0;
						std::cin.clear();
						std::cin.ignore();
					}
				}
			} while (n!=1);	
		} 
		Massive m(size,words);
		Mass[count](m);
		for(int k=0;k<size;k++){
			delete[] words[k];
		}
		delete[] words;
		num=count;
		count++;
		int quit;
		do {
			quit = Methods();
		} while (!quit);
	}
	void QUIT(){
		count=SIZECLASS;
	}
	int Quit_Or_Next()
	{
		return 1;
	}
	int Perehod()
	{
		const char* pr = "";
		do{
			std::cout << pr << std::endl;
			std::cout <<"Введите номер экземпляра класса:"<<std::endl;
			pr = "You are wrong; repeat please!";
			if (getNum(num) < 0)
			{
				num=0;
				std::cin.clear();
				std::cin.ignore();
			}
		} while (num < 1 ||  count+1 <= num);
		num--;
		return 0;
	}
	int Input_Word()
	{
		int n;
		char* word=new char[100];
		const char *pr="";
		do{
			n=1;
			std::cout << pr << std::endl;
			std::cout << "Введите слово" << " --> ";
			if (getNum(word) < 0)
			{
				pr = "You are wrong; repeat please!";
				n=0;
				std::cin.clear();
				std::cin.ignore();
			}
			if(strlen(word)>SIZEWORD)
			{
				pr = "Too large word, repeat please!";
				n=0;
				std::cin.clear();
				std::cin.ignore();
			}
			if(Mass[num](word)!=-1)
			{
				std::cout<<"Это слово уже есть в массиве"<<std::endl;
				n=0;
				std::cin.clear();
				std::cin.ignore();
			}
		} while (n!=1);
		Mass[num]+=word;
		delete[] word;
		return 0;
	}
	int Find_Word()
	{
		int n;
		char* word=new char[100];
		const char* pr="";
		do{
			n=1;
			std::cout << pr << std::endl;
			std::cout << "Введите слово" << " --> ";
			if (getNum(word) < 0)
			{
				pr = "You are wrong; repeat please!";
				n=0;
				std::cin.clear();
				std::cin.ignore();
			}
			if(strlen(word)>SIZEWORD)
			{
				pr = "Too large word, repeat please!";
				n=0;
				std::cin.clear();
				std::cin.ignore();
			}
		} while (n!=1);
		int d=Mass[num](word);
		delete[] word;
		if(d==-1) std::cout<<"В данном массиве нет такого слова."<<std::endl;
		else std::cout<<"Данное слово в массиве находится на "<<d+1<<" месте."<<std::endl;
		return 0;
	}
	int Output_Word()
	{
		std::cout<<Mass[num];
		return 0;
	}
	int Output_Word_With_Index()
	{
		int number;
		const char* pr = "";
		do{
			std::cout << pr << std::endl;
			std::cout <<"Введите номер слова в массиве:"<<std::endl;
			pr = "You are wrong; repeat please!";
			if (getNum(number) < 0)
			{
				number=0;
				std::cin.clear();
				std::cin.ignore();
			}
		} while (number < 1 || Mass[num].Getrealsize() < number);
		std::cout<<Mass[num][number-1]<<std::endl;
		return 0;
	}
	int New_Mass()
	{
		int n;
		char symbol;
		const char* pr="";
		do{
			n=1;
			std::cout << pr << std::endl;
			std::cout << "Введите букву для поиска слов" << " --> ";
			if (getNum(symbol) < 0)
			{
				pr = "You are wrong; repeat please!";
				n=0;
				std::cin.clear();
				std::cin.ignore();
			}
		} while (n!=1);
		Mass[num].Getmass(symbol);
		return 0;
	}
	int Alphavit()
	{
		//Mass[num]==(Mass[num-1]);
		//Mass[num]=(Mass[num-1]);
		Mass[num]();
		return 0;
	}
	void (*fptr[])() = {QUIT, Empty_Constructor,Init_Constructor_Word,Init_Constructor_Mass};
	const char *msgs[] = {"1. Выход", "2. Cоздать пустой конструктор", "3. Создать экземпляр класса с инициализацией одним словом" , "4. Создать экземпляр класса с инициализацией количеством слов и словами из массива строковых констант"};
	const int NMsgs = sizeof(msgs) / sizeof(msgs[0]);
	int (*fptr1[])() = {Quit_Or_Next, Perehod,Input_Word,Find_Word,Output_Word,Output_Word_With_Index,New_Mass,Alphavit};
	const char *msgs1[] = {"1. Выход или переход к выбору конструктора", "2. Переход к другому конструктору", "3. Добавить слово" , "4. Поиск слова","5. Вывод массива","6. Поиск слова по индексу","7. Создать массив слов, начинающихся на данную букву","8. Расстановка слов в алфавитном порядке"};
	const int NMsgs1 = sizeof(msgs1) / sizeof(msgs1[0]);
	int dialog(const char *msgs[], int N)
	{
		const char *pr = "";
		int rc;
		int i;
		do {
			std::cout << pr << std::endl;
			pr = "You are wrong; repeat please!";
			for (i = 0; i < N; ++i)
			{
				std::cout<<msgs[i]<<std::endl;
			}
			std::cout<<("Make your choice:  --> ");
			if (getNum(rc) < 0)
			{
				rc=0;
				std::cin.clear();
				std::cin.ignore();
			}
		} while (rc < 1 || rc > N);
		return rc;
	}
	int Methods()
	{
		int rc;
		rc=dialog(msgs1, NMsgs1);
		rc--;
		int h=fptr1[rc]();
		if(h==1) return 1;
		return 0;
	
	}
	void Massive::memory()
	{
		mass=new char*[sizemass];
		for(int i=0;i<sizemass;i++)
			mass[i]=new char[sizeword];
	}
	void Vibor(){
		while(count<SIZECLASS)
		{
			int rc = dialog(msgs, NMsgs);
			rc--;
			fptr[rc]();
		}
		delete[] Mass;
		std::cout<<"Thats all, bye."<<std::endl;
	}	
}
