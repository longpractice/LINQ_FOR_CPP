// linq_cpp.cpp : Defines the entry point for the console application.
//
#include "LINQ.h"
#include <vector>
#include <iostream>

inline void Assert(bool ok, std::string why = "")
{
	if (!ok)
		throw std::runtime_error(why);
}


int main()
{
	//test Where
	{
		std::vector<int> myVec{ 1,2,3,4,5 };
		std::vector<int> myOddVec = Where(myVec, [](int i) {return i % 2 == 1; });
		Assert(myOddVec == std::vector<int>{1, 3, 5});
		std::cout << "Where() tested." << std::endl;
	}

	//test OrderBy()
	{
		std::vector<int> myVec{ 1,3,4,2,2 };
		std::vector<int> myNegativeFloatVec = OrderBy(myVec, [](int i) {return float(-i); });
		Assert(myNegativeFloatVec == std::vector<int>{4, 3, 2, 2, 1});
		std::cout << "OrderBy() tested." << std::endl;

	}

	//test OrderByDescending()
	{
		std::vector<int> myVec{ 1,3,4,2,2 };
		std::vector<int> myNegativeFloatVec = OrderByDescending(myVec, [](int i) {return float(-i); });
		Assert(myNegativeFloatVec == std::vector<int>{1, 2, 2, 3, 4});
		std::cout << "OrderByDescending() tested." << std::endl;

	}

	//test Select()
	{
		std::vector<int> myVec{ 1,3,4,2,2 };
		auto myInvFloatVec = Select(myVec, [](int i) {return (float)(1.0f / i); });
		Assert(myInvFloatVec == std::vector<float>{1.0f/1, 1.0f/3, 1.0f/4, 1.0f/2, 1.0f/2});
		std::cout << "Select() tested." << std::endl;
	}


	//test Contains()
	{
		std::vector<int> myVec{ 1,3,4,2,2 };
		Assert(Contains(myVec, 4));
		Assert(!Contains(myVec, 5));
		//this is a special case of string
		std::string father = "Happy birthday.";
		Assert(Contains(father, "Happy"));
		Assert(!Contains(father, "Ha.."));
		std::cout << "Contains() tested." << std::endl;
	}

	//test All()
	{
		std::vector<int> myVec{ 1,3,4,2,2 };
		Assert(All(myVec, [](int i) {return i > 0; }));
		Assert(!All(myVec, [](int i) {return i > 1; }));

		std::cout << "All() tested." << std::endl;
	}


	//test None()
	{
		std::vector<int> myVec{ 1,3,4,2,2 };
		Assert(None(myVec, [](int i) {return i < 0; }));
		Assert(!None(myVec, [](int i) {return i > 1; }));
		Assert(!None(myVec, [](int i) {return i < 2; }));

		std::cout << "None() tested." << std::endl;
	}


	//test Mean()
	{
		std::vector<int> myVec{ 1,3,4,2,2 };
		auto intMean = Mean<int>(myVec);
		Assert(intMean == 2);
		auto doubleMeanImplicitType = Mean(myVec);
		Assert(doubleMeanImplicitType== 2.4);
		auto doubleMeanWithExplicitType = Mean(myVec);
		Assert(doubleMeanWithExplicitType == 2.4);
		std::cout << "Mean() tested." << std::endl;
	}



	//test Variant()
	{
		std::vector<int> myVec{ 1,3,4,2,2 };
		auto variant = Variant(myVec);
		double mean = double(1 + 3 + 4 + 2 + 2) / 5;
		auto sqr = [](double x) {return x*x; };
		double variant_benchmark = (sqr(1 - mean) + sqr(3 - mean) + sqr(4 - mean) + sqr(2 - mean) + sqr(2 - mean)) / 5;
		Assert(variant == variant_benchmark);
		std::cout << "Variant() tested." << std::endl;
	}


	//test Standard_Deviation()
	{
		std::vector<int> myVec{ 1,3,4,2,2 };
		double mean = double(1 + 3 + 4 + 2 + 2) / 5;
		auto sqr = [](double x) {return x*x; };
		double std_benchmark = sqrt((sqr(1 - mean) + sqr(3 - mean) + sqr(4 - mean) + sqr(2 - mean) + sqr(2 - mean)) / 5);
		double std_result = Standard_Deviation(myVec);
		Assert(std_result == std_benchmark);
		std::cout << "Standard_Deviation() tested." << std::endl;
	}








	std::cout << "All test passed!" << std::endl;
	return 0;
}