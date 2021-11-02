#include "Prog3.h"
#include <assert.h>
TEST(ConhoidaConstructor, DeafultConstructor)
{
	Prog3::Massive a1;
	ASSERT_EQ(0, a1.Getsize());
}
TEST(MassiveConstructor, InitWithWordConstructors)
{
	char word1[SIZEWORD]="qwerty";
	Prog3::Massive a3(word1);
	ASSERT_EQ(1, a3.Getsize());
	ASSERT_STREQ(word1, a3[0]);
	char word2[SIZEWORD]="asdfg";
	Prog3::Massive a4(word2);
	ASSERT_EQ(1, a4.Getsize());
	ASSERT_STREQ(word2,a4[0]);
}
TEST(ConhoidaConstructor, InitWithWordsConstructors)
{
	char mass[SIZEMASS][100]={"qwerty","asdfg","zxcvb"};
	int N=3;
	Prog3::Massive a5(3,mass);
	ASSERT_EQ(3, a5.Getsize());
	for(int i=0;i<N;i++)
	{
		ASSERT_STREQ(mass[i],a5[i]);
	}
}
TEST(MassiveGetters, Getsize)
{
	Prog3::Massive c1;
	ASSERT_EQ(0,c1.Getsize());
	char mass[SIZEMASS][100]={"qwerty","asdfg","zxcvb"};
	int N=3;
	Prog3::Massive a5(3,mass);
	ASSERT_EQ(3, a5.Getsize());
	char word[SIZEWORD]="qwerty";
	Prog3::Massive a3(word);
	ASSERT_EQ(1, a3.Getsize());
	char word1[SIZEWORD]="asdfg";
	a3+=word1;
	ASSERT_STREQ(word1, a3[1]);
	ASSERT_EQ(2,a3.Getsize());
}
TEST(MassiveGetters, Getmass)
{
	char mass[SIZEMASS][100]={"qwerty","asdfg","zxcvb"};
	int N=3;
	Prog3::Massive a5(3,mass);
	ASSERT_EQ(3, a5.Getsize());
	for(int i=0;i<N;i++)
	{
		ASSERT_STREQ(mass[i], a5[i]);
	}
	ASSERT_EQ(3,a5.Getsize());
}
TEST(MassiveMethods, AddWord)
{
	Prog3::Massive c1;
	ASSERT_EQ(0,c1.Getsize());
	char word[SIZEMASS]="qwerty";
	c1+=word;
	ASSERT_STREQ(word, c1[0]);
	ASSERT_EQ(1,c1.Getsize());
	char mass[SIZEMASS][100]={"qwert","asdfg","zxcvb","qwe","wer","ert","rty","tyu","yui","uio"};
	int N=10;
	Prog3::Massive c2(10,mass);
	ASSERT_ANY_THROW(c2+=word);
}
TEST(MassiveMethods, Findindexword)
{
	char mass[SIZEMASS][100]={"qwerty","asdfg","zxcvb","qwe","wer","ert","rty","tyu","yui","uio"};
	int N=10;
	Prog3::Massive c1(10,mass);
	for(int i=0;i<N;i++)
	{
		ASSERT_EQ(i,c1(mass[i]));
	}
	char word[SIZEWORD]="qweasd";
	ASSERT_EQ(-1,c1(word));
}
TEST(MassiveMethods, Findwordwithindex)
{
	char mass[SIZEMASS][100]={"qwerty","asdfg","zxcvb","qwe","wer","ert","rty","tyu","yui","uio"};
	int N=10;
	Prog3::Massive c1(10,mass);
	for(int i=0;i<N;i++)
	{
		ASSERT_STREQ(mass[i],c1[i]);
	}
}
TEST(MassiveMethods, Sort)
{
	char mass[SIZEMASS][100]={"qwerty","asdfg","zxcvb","qwe","wer","ert","rty","tyu","yui","uio"};
	int N=10;
	Prog3::Massive c1(10,mass);
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
}
TEST(MassiveMethods, Copy)
{
	char mass[SIZEMASS][100]={"qwerty","asdfg","zxcvb","qwe","wer","ert","rty","tyu","yui","uio"};
	int N=10;
	Prog3::Massive c1(10,mass);
	Prog3::Massive c2;
	c2(c1);
	ASSERT_EQ(c2.Getsize(),c1.Getsize());
	for(int i=0;i<N;i++)
	{
		ASSERT_STREQ(c2[i],c1[i]);
	}
}
int main(int argc, char * argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
