#include "pch.h"
#include "CppUnitTest.h"
#include "..\Lab1_map\Map.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lab1maptests
{
	TEST_CLASS(Lab1maptests)
	{
	public:
		
		TEST_METHOD(Insert)
		{
			Map<int, int> map;
			map.insert(3, 17);
			map.insert(13, 2);
			map.insert(7, 13);
			map.insert(0, 10);
			Assert::IsTrue(map.mapSize()==4);
			Assert::IsTrue(map.find(3)->value == 17);
			Assert::IsTrue(map.find(13)->value == 2);
			Assert::IsTrue(map.find(7)->value == 13);
			Assert::IsTrue(map.find(0)->value == 10);
		}

		TEST_METHOD(Remove)
		{
			Map<int, int> map;
			map.insert(3, 17);
			map.insert(13, 2);
			map.insert(7, 13);
			map.insert(0, 10);
			map.remove(3);
			Assert::IsTrue(map.mapSize() == 3);
			Assert::IsTrue(map.find(7)->value == 13);
			Assert::IsTrue(map.find(13)->value == 2);
			Assert::IsTrue(map.find(0)->value == 10);

		}
		
		TEST_METHOD(Find)
		{
			Map<int, int> map;
			map.insert(3, 17);
			map.insert(13, 2);
			map.insert(7, 13);
			map.insert(0, 10);
			map.insert(4, 12);
			Assert::IsTrue(map.find(7)->value == 13);
			Assert::IsTrue(map.find(13)->value == 2);
			Assert::IsTrue(map.find(0)->value == 10);
			Assert::IsTrue(map.find(4)->value == 12);
			Assert::IsTrue(map.find(3)->value == 17);
		}

		TEST_METHOD(Clear)
		{
			Map<int, int> map;
			map.insert(3, 17);
			map.insert(13, 2);
			map.insert(7, 13);
			map.insert(0, 10);
			map.insert(4, 12);
			map.clear();
			Assert::IsTrue(map.mapSize() == 0);
		}

		TEST_METHOD(GetKeys)
		{
			Map<int, int> map;
			map.insert(1, 10);
			map.insert(2, 20);
			map.insert(3, 30);
			map.insert(4, 40);
			map.insert(5, 50);
			map.insert(6, 60);
		
			List<int> keys = map.get_keys();
			Assert::IsTrue(keys.at(0) == 2);
			Assert::IsTrue(keys.at(1) == 1);
			Assert::IsTrue(keys.at(2) == 4);
			Assert::IsTrue(keys.at(3) == 3);
			Assert::IsTrue(keys.at(4) == 5);
			Assert::IsTrue(keys.at(5) == 6);
		}

		TEST_METHOD(GetValues)
		{
			Map<int, int> map;
			map.insert(1, 10);
			map.insert(2, 20);
			map.insert(3, 30);
			map.insert(4, 40);
			map.insert(5, 50);
			map.insert(6, 60);

			List<int> values = map.get_values();
			Assert::IsTrue(values.at(0) == 20);
			Assert::IsTrue(values.at(1) == 10);
			Assert::IsTrue(values.at(2) == 40);
			Assert::IsTrue(values.at(3) == 30);
			Assert::IsTrue(values.at(4) == 50);
			Assert::IsTrue(values.at(5) == 60);
		}
	};
}
