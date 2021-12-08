#include "pch.h"
#include "CppUnitTest.h"
#include "../StringUnpacker/header.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestStringProcessing
{
	TEST_CLASS(TestStringProcessing)
	{
	public:
		
		TEST_METHOD(SingleCharacter)
		{
			// Входные данные
			std::string inputData = "A";

			// Эталонные выходные данные
			std::string expOutputData = "A";

			// Запуск тестируемой функции
			std::string outputData = StringProcessing(inputData);

			// Сравнение полученных выходных данных с эталонными
			Assert::AreEqual(expOutputData, outputData);
		}

		TEST_METHOD(MultipleSingleCharacters)
		{
			// Входные данные
			std::string inputData = "ABC";

			// Эталонные выходные данные
			std::string expOutputData = "ABC";

			// Запуск тестируемой функции
			std::string outputData = StringProcessing(inputData);

			// Сравнение полученных выходных данных с эталонными
			Assert::AreEqual(expOutputData, outputData);
		}

		TEST_METHOD(OneRepeatingCharacter)
		{
			// Входные данные
			std::string inputData = "10A";

			// Эталонные выходные данные
			std::string expOutputData = "AAAAAAAAAA";

			// Запуск тестируемой функции
			std::string outputData = StringProcessing(inputData);

			// Сравнение полученных выходных данных с эталонными
			Assert::AreEqual(expOutputData, outputData);
		}

		TEST_METHOD(MultipleRepeatingCharacters)
		{
			// Входные данные
			std::string inputData = "10A5B2C";

			// Эталонные выходные данные
			std::string expOutputData = "AAAAAAAAAABBBBBCC";

			// Запуск тестируемой функции
			std::string outputData = StringProcessing(inputData);

			// Сравнение полученных выходных данных с эталонными
			Assert::AreEqual(expOutputData, outputData);
		}

		TEST_METHOD(MixedString)
		{
			// Входные данные
			std::string inputData = "10AS5BZY2CX";

			// Эталонные выходные данные
			std::string expOutputData = "AAAAAAAAAASBBBBBZYCCX";

			// Запуск тестируемой функции
			std::string outputData = StringProcessing(inputData);

			// Сравнение полученных выходных данных с эталонными
			Assert::AreEqual(expOutputData, outputData);
		}

		TEST_METHOD(EmptyString)
		{
			// Входные данные
			std::string inputData = "";

			// Эталонные выходные данные
			std::string expOutputData = "A";

			// Запуск тестируемой функции
			auto func = [inputData] { StringProcessing(inputData); };

			// Сравнение полученных выходных данных с эталонными
			Assert::ExpectException<std::invalid_argument>(func);
		}

		TEST_METHOD(TooLongLine)
		{
			// Входные данные
			std::string inputData = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA";

			// Эталонные выходные данные
			std::string expOutputData = "A";

			// Запуск тестируемой функции
			auto func = [inputData] { StringProcessing(inputData); };

			// Сравнение полученных выходных данных с эталонными
			Assert::ExpectException<std::invalid_argument>(func);
		}

		TEST_METHOD(UnresolvedCharactersInTheString)
		{
			// Входные данные
			std::string inputData = "AbC";

			// Эталонные выходные данные
			std::string expOutputData = "A";

			// Запуск тестируемой функции
			auto func = [inputData] { StringProcessing(inputData); };

			// Сравнение полученных выходных данных с эталонными
			Assert::ExpectException<std::invalid_argument>(func);
		}

		TEST_METHOD(LineAtTheEndContainsANumber)
		{
			// Входные данные
			std::string inputData = "ABC10";

			// Эталонные выходные данные
			std::string expOutputData = "A";

			// Запуск тестируемой функции
			auto func = [inputData] { StringProcessing(inputData); };

			// Сравнение полученных выходных данных с эталонными
			Assert::ExpectException<std::invalid_argument>(func);
		}

		TEST_METHOD(NumberOfRepetitionsOfACharacterIsTooSmall)
		{
			// Входные данные
			std::string inputData = "1A";

			// Эталонные выходные данные
			std::string expOutputData = "A";

			// Запуск тестируемой функции
			auto func = [inputData] { StringProcessing(inputData); };

			// Сравнение полученных выходных данных с эталонными
			Assert::ExpectException<std::invalid_argument>(func);
		}

		TEST_METHOD(NumberOfRepetitionsOfACharacterIsTooHigh)
		{
			// Входные данные
			std::string inputData = "100A";

			// Эталонные выходные данные
			std::string expOutputData = "A";

			// Запуск тестируемой функции
			auto func = [inputData] { StringProcessing(inputData); };

			// Сравнение полученных выходных данных с эталонными
			Assert::ExpectException<std::invalid_argument>(func);
		}

	};
}
