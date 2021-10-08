#include "Prog2.h"
TEST(ConhoidaConstructor, DeafultConstructor)
{
	Prog2::Conhoida a1;
	ASSERT_EQ(0, a1.getA());
	ASSERT_EQ(1, a1.getL());
}
TEST(ConhoidaConstructor, InitConstructors)
{
	Prog2::Conhoida a3(2, 8);
	ASSERT_EQ(2, a3.getA());
	ASSERT_EQ(8, a3.getL());
	Prog2::Conhoida a4(-4, 3);
	ASSERT_EQ(-4, a4.getA());
	ASSERT_EQ(3, a4.getL());
}
TEST(ConhoidaMethods, Setters)
{
	Prog2::Conhoida c1;
	double a1=1;
	c1.setA(a1);
	ASSERT_EQ(1, c1.getA());
	Prog2::Conhoida c2;
	double a2=-3;
	c2.setA(a2);
	ASSERT_EQ(-3, c2.getA());
	c2.setL(2);
	ASSERT_EQ(2, c2.getL());
	ASSERT_ANY_THROW(c2.setL(-2));
}
TEST(ConhoidaMethods, Parameters)
{
	Prog2::Conhoida a1;
	const double PI = 3.14159,err = 0.00001;
	ASSERT_EQ(0, a1.findy(-1));
	ASSERT_EQ(0, a1.findy(1));
	ASSERT_ANY_THROW(a1.findy(-25));
	ASSERT_EQ(1, a1.findr(PI/4));
	ASSERT_NEAR(1, a1.findr(PI/4), err);
	ASSERT_EQ(0, a1.Square());
	Prog2::Conhoida a2(5, 7);
	ASSERT_NEAR(14.07106, a2.findr(PI/4),err);
	ASSERT_NEAR(1.436140, a2.findy(1),err);
	ASSERT_ANY_THROW(a2.findy(-10));
	ASSERT_NEAR(1.78834, a2.Square(),err);
	ASSERT_ANY_THROW(Prog2::Conhoida a2(5, -7));
}
int main(int argc, char * argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
