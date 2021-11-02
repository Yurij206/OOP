#include "Prog3.h"
#include <assert.h>
TEST(ConhoidaConstructor, DeafultConstructor)
{
	Prog3::Massive a1;
	ASSERT_EQ(0, a1.Getrealsize());
	
}
TEST(MassiveConstructor, InitWithWordConstructors)
{
	char word1[SIZEWORD]="qwerty";
	Prog3::Massive a3(word1);
	ASSERT_EQ(1, a3.Getrealsize());
	ASSERT_STREQ(word1, a3[0]);
	char word2[SIZEWORD]="asdfg";
	Prog3::Massive a4(word2);
	ASSERT_EQ(1, a4.Getrealsize());
	ASSERT_STREQ(word2,a4[0]);
}
TEST(ConhoidaConstructor, InitWithWordsConstructors)
{
	int N=6;
	char m[N][SIZEWORD]={"qwerty","asdfg","zxcvb","werty","ertyu","fgh"};
	char** mass=new char*[N];
	for(int i=0;i<N;i++)
	{
		mass[i]=m[i];
	}
	Prog3::Massive a5(6,mass);
	ASSERT_EQ(6, a5.Getrealsize());
	for(int i=0;i<N;i++)
	ASSERT_STREQ(mass[i],a5[i]);
	delete[] mass;
}
TEST(MassiveGetters, Getrealsize)
{
	Prog3::Massive c1;
	ASSERT_EQ(0,c1.Getrealsize());
	int N=5;
	char m[N][SIZEWORD]={"qwerty","asdfg","zxcvb","werty","ertyu"};
		char** mass=new char*[N];
	for(int i=0;i<N;i++)
	{
		mass[i]=m[i];
	}
	Prog3::Massive a5(N,mass);
	ASSERT_EQ(N, a5.Getrealsize());
	char word[SIZEWORD]="qwerty";
	Prog3::Massive a3(word);
	ASSERT_EQ(1, a3.Getrealsize());
	char word1[SIZEWORD]="asdfg";
	a3+=word1;
	ASSERT_STREQ(word1, a3[1]);
	ASSERT_EQ(2,a3.Getrealsize());
	ASSERT_EQ(5,a3.Getsize());
	delete[] mass;
}
TEST(MassiveGetters, Getsize)
{
	Prog3::Massive c1;
	ASSERT_EQ(5,c1.Getsize());
	int N=5;
	char m[N][SIZEWORD]={"qwerty","asdfg","zxcvb","werty","ertyu"};
	char** mass=new char*[N];
	for(int i=0;i<N;i++)
	{
		mass[i]=m[i];
	}
	Prog3::Massive a5(N,mass);
	ASSERT_EQ(SIZEMASS, a5.Getsize());
	char word[SIZEWORD]="qwery";
	a5+=word;
	ASSERT_EQ(6, a5.Getsize());
	Prog3::Massive a3(word);
	ASSERT_EQ(5, a3.Getsize());
	char word1[SIZEWORD]="asdfg";
	a3+=word1;
	ASSERT_STREQ(word1, a3[1]);
	ASSERT_EQ(5,a3.Getsize());
	delete[] mass;
}
TEST(MassiveGetters, Getmass)
{
	int N=3;
	char m[N][SIZEWORD]={"qwerty","asdfg","zxcvb"};
	char** mass=new char*[N];
	for(int i=0;i<N;i++)
	{
		mass[i]=m[i];
	}
	Prog3::Massive a5(3,mass);
	ASSERT_EQ(5,a5.Getsize());
	ASSERT_EQ(3, a5.Getrealsize());
	for(int i=0;i<N;i++)
	ASSERT_STREQ(mass[i], a5[i]);
	ASSERT_EQ(3,a5.Getrealsize());
	delete[] mass;
}
TEST(MassiveMethods, AddWord)
{
	Prog3::Massive c1;
	ASSERT_EQ(0,c1.Getrealsize());
	char word[SIZEWORD]="qwerty";
	c1+=word;
	ASSERT_STREQ(word, c1[0]);
	ASSERT_EQ(1,c1.Getrealsize());
	ASSERT_EQ(5,c1.Getsize());
	int N=10;
	char m[N][SIZEWORD]={"qwert","asdfg","zxcvb","qwe","wer","ert","rty","tyu","yui","uio"};
		char** mass=new char*[N];
	for(int i=0;i<N;i++)
	{
	mass[i]=m[i];
	}
	Prog3::Massive c2(N,mass);
	c2+=word;
	ASSERT_EQ(11,c2.Getrealsize());
	ASSERT_EQ(11,c2.Getsize());
	ASSERT_STREQ(c2[10],word);
	delete[] mass;
}
TEST(MassiveMethods, Findindexword)
{
	int N=10;
	char m[N][SIZEWORD]={"qwerty","asdfg","zxcvb","qwe","wer","ert","rty","tyu","yui","uio"};
	char** mass=new char*[N];
	for(int i=0;i<N;i++)
	{
		mass[i]=m[i];
	};
	Prog3::Massive c1(N,mass);
	ASSERT_EQ(0,c1(mass[0]));
	ASSERT_EQ(1,c1(mass[1]));
	ASSERT_EQ(2,c1(mass[2]));
	ASSERT_EQ(3,c1(mass[3]));
	ASSERT_EQ(4,c1(mass[4]));
	ASSERT_EQ(5,c1(mass[5]));
	ASSERT_EQ(6,c1(mass[6]));
	ASSERT_EQ(7,c1(mass[7]));
	ASSERT_EQ(8,c1(mass[8]));
	ASSERT_EQ(9,c1(mass[9]));
	char word[SIZEWORD]="qweasd";
	ASSERT_EQ(-1,c1(word));
	delete[] mass;
}
TEST(MassiveMethods, Findwordwithindex)
{
	int N=10;
	char m[N][SIZEWORD]={"qwerty","asdfg","zxcvb","qwe","wer","ert","rty","tyu","yui","uio"};
	char** mass=new char*[N];
	for(int i=0;i<N;i++)
	{
		mass[i]=m[i];
	}
	Prog3::Massive c1(N,mass);
	ASSERT_STREQ(mass[0],c1[0]);
	ASSERT_STREQ(mass[1],c1[1]);
	ASSERT_STREQ(mass[2],c1[2]);
	ASSERT_STREQ(mass[3],c1[3]);
	ASSERT_STREQ(mass[4],c1[4]);
	ASSERT_STREQ(mass[5],c1[5]);
	ASSERT_STREQ(mass[6],c1[6]);
	ASSERT_STREQ(mass[7],c1[7]);
	ASSERT_STREQ(mass[8],c1[8]);
	ASSERT_STREQ(mass[9],c1[9]);
	delete[] mass;
}
TEST(MassiveMethods, Sort)
{
	int N=10;
	char m[N][SIZEWORD]={"qwerty","asdfg","zxcvb","qwe","wer","ert","rty","tyu","yui","uio"};
	char** mass=new char*[N];
	for(int i=0;i<N;i++)
	{
		mass[i]=m[i];
	};
	Prog3::Massive c1(N,mass);
	c1();
	ASSERT_STREQ(mass[1],c1[0]);
	ASSERT_STREQ(mass[5],c1[1]);
	ASSERT_STREQ(mass[3],c1[2]);
	ASSERT_STREQ(mass[0],c1[3]);
	ASSERT_STREQ(mass[6],c1[4]);
	ASSERT_STREQ(mass[7],c1[5]);
	ASSERT_STREQ(mass[9],c1[6]);
	ASSERT_STREQ(mass[4],c1[7]);
	ASSERT_STREQ(mass[8],c1[8]);
	ASSERT_STREQ(mass[2],c1[9]);
	delete[] mass;
}
TEST(MassiveMethods, Copy)
{
	int N=10;
	char m[N][SIZEWORD]={"qwerty","asdfg","zxcvb","qwe","wer","ert","rty","tyu","yui","uio"};
	char** mass=new char*[N];
	for(int i=0;i<N;i++)
	{
		mass[i]=m[i];
	};
	Prog3::Massive c1(N,mass);
	Prog3::Massive c2;
	c2(c1);
	ASSERT_EQ(c2.Getrealsize(),c1.Getrealsize());
	for(int i=0;i<c1.Getsize();i++)
	ASSERT_STREQ(c2[i],c1[i]);
	delete[] mass;
}
TEST(MassiveMethods, Setsize)
{
	Prog3::Massive c1;
	c1.setsize(5);
	ASSERT_EQ(5,c1.Getsize());
}
TEST(MassiveMethods, EQ)
{
	int N=10;
	char m[N][SIZEWORD]={"qwert","asdfg","zxcvb","qwe","wer","ert","rty","tyu","yui","uio"};
	char** mass=new char*[N];
	for(int i=0;i<N;i++)
	{
			mass[i]=m[i];
	}
	Prog3::Massive c1(N,mass);
	int N1=3;
	char m1[N1][SIZEWORD]={"qwerty","asdfg","zxcvb"};
	char** mass1=new char*[N1];
	for(int i=0;i<N1;i++)
	{
		mass1[i]=m1[i];
	}
	Prog3::Massive c2(N1,mass);
	c2==c1;
	ASSERT_EQ(c2.Getrealsize(),c1.Getrealsize());
	ASSERT_EQ(c2.Getsize(),c1.Getsize());
	for(int i=0;i<c1.Getsize();i++)
	ASSERT_STREQ(c2[i],c1[i]);
	delete[] mass;
	delete[] mass1;
}
TEST(MassiveMethods, Perem)
{
	int N=10;
	char m[N][SIZEWORD]={"qwert","asdfg","zxcvb","qwe","wer","ert","rty","tyu","yui","uio"};
	char** mass=new char*[N];
	for(int i=0;i<N;i++)
	{
		mass[i]=m[i];
	}
	Prog3::Massive c1(N,mass);
	int N1=3;
	char m1[N1][SIZEWORD]={"qwerty","asdfg","zxcvb"};
	char** mass1=new char*[N1];
	for(int i=0;i<N1;i++)
	{
		mass1[i]=m1[i];
	}
	Prog3::Massive c2(N1,mass1);
	c2=c1;
	ASSERT_EQ(c2.Getrealsize(),N);
	ASSERT_EQ(c2.Getsize(),N);
	ASSERT_EQ(c1.Getrealsize(),N1);
	ASSERT_EQ(c1.Getsize(),5);
	for(int i=0;i<c1.Getsize();i++)
	{
		ASSERT_STREQ(c1[i],m1[i]);
		ASSERT_STREQ(c2[i],m[i]);
		delete[] mass;
		delete[] mass1;
	}
}
int main(int argc, char * argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
