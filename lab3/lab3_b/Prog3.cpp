#include <stdio.h>
#include <string.h>
#include "Prog3.h"
#include <string.h>
#define SIZECLASS 10
namespace Prog3
{
	Massive Mass[SIZECLASS];
	int count = 0;
	int num = 0;
	Massive::Massive(char* word)
	{
		strcpy(mass[0],word);
		realsize=1;
	}
	void Massive::operator +=(char* word)
	{
		if(Getsize()==SIZEMASS)
		{
			throw std::runtime_error("Массив уже полностью заполнен.");
		}
		strcpy(mass[realsize],word);
		realsize++;
	}
	void Massive::operator ()(const Massive &st)
	{
		//std::cout<<"Копирование работает"<<std::endl;
		this->realsize=st.realsize;
		for(int i=0;i<st.realsize;i++)
			strcpy(this->mass[i],st.mass[i]);
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
	Massive::Massive(int size,char words[][100])
	{
		for(int i=0;i<size;i++)
			strcpy(mass[i], words[i]);
		realsize=size;
	}
	int  Massive::operator ()(char* word)
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
		char m[realsize][SIZEWORD];
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
	}
	void Massive::operator()()
	{
		for(int i=0;i<realsize;i++)
		{
			for(int j=i;j<realsize;j++)
			{
				if(strcmp(mass[i],mass[j])>0)
				{
					char buf[SIZEWORD];
					strcpy(buf,mass[i]);
					strcpy(mass[i],mass[j]);
					strcpy(mass[j],buf);
				}
			}
		}
	}
	void Empty_Constructor()
	{
		Massive m;
		Mass[count](m);
		num=count;
		count++;
		int quit;
		do {
			quit = Methods();
		} while (!quit);
	}
	void Init_Constructor_Word()
	{
		int n;
		char word[100];
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
		} while (size < 1 || size > SIZEMASS);
		char words[size][100];
		for(int i=0;i<size;i++)
		{
			pr="";
			int n;
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
				for(int j=0;j<i;j++)
				{
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
		num=count;
		count++;
		int quit;
		do {
			quit = Methods();
		} while (!quit);
	}
	void QUIT()
	{
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
		if(Mass[num].Getsize()==SIZEMASS)
		{
			throw std::runtime_error("Массив уже полностью заполнен.");
			return 0;
		}
		int n;
		char word[100];
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
		} while (n!=1);
		if(Mass[num](word)!=-1)
		{
			std::cout<<"Это слово уже есть в массиве"<<std::endl;
			return 0;
		}
		Mass[num]+=word;
		return 0;
	}
	int Find_Word()
	{
		int n;
		char word[100];
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
		} while (number < 1 || Mass[num].Getsize() < number);
		number--;
		std::cout<<Mass[num][number]<<std::endl;
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
		} while (rc < 1 || rc > N+1);
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
	void Vibor()
	{
		while(count<SIZECLASS){
			int rc = dialog(msgs, NMsgs);
			rc--;
			fptr[rc]();
		}
		std::cout<<"Thats all, bye."<<std::endl;
	}	
}
