#include "pch.h"
#include "CppUnitTest.h"
#include "../StringUnpacker/header.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestDivideString
{
	TEST_CLASS(TestDivideString)
	{
	public:
		
		TEST_METHOD(StringLessThanLimit)
		{
			// Входные данные
			std::string inputDataStr = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA";
			int inputDataNumber = 40;

			// Эталонные выходные данные
			std::vector<std::string> expOutputData;
			expOutputData.emplace_back("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"); 

			// Запуск тестируемой функции
			std::vector<std::string> outputData = DivideString(inputDataStr, inputDataNumber);

			// Сравнение полученных выходных данных с эталонными
			for (int i = 0; i < expOutputData.size(); i++)
			{
				Assert::AreEqual(expOutputData[i], outputData[i]);
			}
		}

		TEST_METHOD(StringLengthIsEqualToTheLimit)
		{
			// Входные данные
			std::string inputDataStr = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA";
			int inputDataNumber = 40;

			// Эталонные выходные данные
			std::vector<std::string> expOutputData;
			expOutputData.emplace_back("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");

			// Запуск тестируемой функции
			std::vector<std::string> outputData = DivideString(inputDataStr, inputDataNumber);

			// Сравнение полученных выходных данных с эталонными
			for (int i = 0; i < expOutputData.size(); i++)
			{
				Assert::AreEqual(expOutputData[i], outputData[i]);
			}
		}

		TEST_METHOD(StringIsAMultipleOfTheLimit)
		{
			// Входные данные
			std::string inputDataStr = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAABBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC";
			int inputDataNumber = 40;

			// Эталонные выходные данные
			std::vector<std::string> expOutputData;
			expOutputData.emplace_back("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");
			expOutputData.emplace_back("BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB");
			expOutputData.emplace_back("CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC");

			// Запуск тестируемой функции
			std::vector<std::string> outputData = DivideString(inputDataStr, inputDataNumber);

			// Сравнение полученных выходных данных с эталонными
			for (int i = 0; i < expOutputData.size(); i++)
			{
				Assert::AreEqual(expOutputData[i], outputData[i]);
			}
		}
		TEST_METHOD(StringIsNotAMultipleOfTheLimit)
		{
			// Входные данные
			std::string inputDataStr = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAABBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCZZZZZZZZZZZZZZZZZZZZZZZ";
			int inputDataNumber = 40;

			// Эталонные выходные данные
			std::vector<std::string> expOutputData;
			expOutputData.emplace_back("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");
			expOutputData.emplace_back("BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB");
			expOutputData.emplace_back("CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC");
			expOutputData.emplace_back("ZZZZZZZZZZZZZZZZZZZZZZZ");

			// Запуск тестируемой функции
			std::vector<std::string> outputData = DivideString(inputDataStr, inputDataNumber);

			// Сравнение полученных выходных данных с эталонными
			for (int i = 0; i < expOutputData.size(); i++)
			{
				Assert::AreEqual(expOutputData[i], outputData[i]);
			}
		}

		TEST_METHOD(IncorrectLimit)
		{
			// Входные данные
			std::string inputDataStr = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA";
			int inputDataNumber = -42;

			// Эталонные выходные данные
			std::vector<std::string> expOutputData;

			// Запуск тестируемой функции
			std::vector<std::string> outputData = DivideString(inputDataStr, inputDataNumber);

			// Сравнение полученных выходных данных с эталонными
			for (int i = 0; i < expOutputData.size(); i++)
			{
				Assert::AreEqual(expOutputData[i], outputData[i]);
			}
		}

		TEST_METHOD(EmptyString)
		{
			// Входные данные
			std::string inputDataStr = "";
			int inputDataNumber = 40;

			// Эталонные выходные данные
			std::vector<std::string> expOutputData;

			// Запуск тестируемой функции
			std::vector<std::string> outputData = DivideString(inputDataStr, inputDataNumber);

			// Сравнение полученных выходных данных с эталонными
			for (int i = 0; i < expOutputData.size(); i++)
			{
				Assert::AreEqual(expOutputData[i], outputData[i]);
			}
		}
	};
}
