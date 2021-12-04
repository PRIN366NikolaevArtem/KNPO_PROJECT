#include "pch.h"
#include "CppUnitTest.h"
#include "../StringUnpacker/header.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestDivideStringToChars
{
	TEST_CLASS(TestDivideStringToChars)
	{
	public:
		
		TEST_METHOD(SingleCharacter)
		{
			// Входные данные
			std::string inputData = "A";

			// Эталонные выходные данные
			std::vector<Unit> expOutputData;
			expOutputData.push_back({1, 'A'});

			// Запуск тестируемой функции
			std::vector<Unit> outputData = DivideStringToChars(inputData);

			// Сравнение полученных выходных данных с эталонными
			for (int i = 0; i < expOutputData.size(); i++)
			{
				Assert::AreEqual(expOutputData[i].quantityCurrent, outputData[i].quantityCurrent);
				Assert::AreEqual(expOutputData[i].Char, outputData[i].Char);
			}
		}

		TEST_METHOD(OneRepeatingCharacter)
		{
			// Входные данные
			std::string inputData = "10A";

			// Эталонные выходные данные
			std::vector<Unit> expOutputData;
			expOutputData.push_back({ 10, 'A' });

			// Запуск тестируемой функции
			std::vector<Unit> outputData = DivideStringToChars(inputData);

			// Сравнение полученных выходных данных с эталонными
			for (int i = 0; i < expOutputData.size(); i++)
			{
				Assert::AreEqual(expOutputData[i].quantityCurrent, outputData[i].quantityCurrent);
				Assert::AreEqual(expOutputData[i].Char, outputData[i].Char);
			}
		}

		TEST_METHOD(MultipleSingleCharacters)
		{
			// Входные данные
			std::string inputData = "ABCD";

			// Эталонные выходные данные
			std::vector<Unit> expOutputData;
			expOutputData.push_back({ 1, 'A' });
			expOutputData.push_back({ 1, 'B' });
			expOutputData.push_back({ 1, 'C' });
			expOutputData.push_back({ 1, 'D' });

			// Запуск тестируемой функции
			std::vector<Unit> outputData = DivideStringToChars(inputData);

			// Сравнение полученных выходных данных с эталонными
			for (int i = 0; i < expOutputData.size(); i++)
			{
				Assert::AreEqual(expOutputData[i].quantityCurrent, outputData[i].quantityCurrent);
				Assert::AreEqual(expOutputData[i].Char, outputData[i].Char);
			}
		}

		TEST_METHOD(MultipleRepeatingCharacters)
		{
			// Входные данные
			std::string inputData = "10A20B30C40D";

			// Эталонные выходные данные
			std::vector<Unit> expOutputData;
			expOutputData.push_back({ 10, 'A' });
			expOutputData.push_back({ 20, 'B' });
			expOutputData.push_back({ 30, 'C' });
			expOutputData.push_back({ 40, 'D' });

			// Запуск тестируемой функции
			std::vector<Unit> outputData = DivideStringToChars(inputData);

			// Сравнение полученных выходных данных с эталонными
			for (int i = 0; i < expOutputData.size(); i++)
			{
				Assert::AreEqual(expOutputData[i].quantityCurrent, outputData[i].quantityCurrent);
				Assert::AreEqual(expOutputData[i].Char, outputData[i].Char);
			}
		}

		TEST_METHOD(MixedCharacters)
		{
			// Входные данные
			std::string inputData = "A20BC40D";

			// Эталонные выходные данные
			std::vector<Unit> expOutputData;
			expOutputData.push_back({ 1, 'A' });
			expOutputData.push_back({ 20, 'B' });
			expOutputData.push_back({ 1, 'C' });
			expOutputData.push_back({ 40, 'D' });

			// Запуск тестируемой функции
			std::vector<Unit> outputData = DivideStringToChars(inputData);

			// Сравнение полученных выходных данных с эталонными
			for (int i = 0; i < expOutputData.size(); i++)
			{
				Assert::AreEqual(expOutputData[i].quantityCurrent, outputData[i].quantityCurrent);
				Assert::AreEqual(expOutputData[i].Char, outputData[i].Char);
			}
		}
	};
}
