#include "pch.h"
#include "CppUnitTest.h"
#include "../StringUnpacker/header.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestLateEvaluation
{
	TEST_CLASS(TestLateEvaluation)
	{
	public:
		
		TEST_METHOD(WithoutErrors)
		{
			// Входные данные
			std::string inputData = "A10B";

			// Эталонные выходные данные
			TermError expOutputData = TermError::Success;

			// Запуск тестируемой функции
			const auto outputData = LateEvaluation(inputData);

			// Сравнение полученных выходных данных с эталонными
			if (expOutputData != outputData) Assert::IsFalse; 
			else Assert::IsTrue;
		}

		TEST_METHOD(LastCharacterIsADigit)
		{
			// Входные данные
			std::string inputData = "A10B5";

			// Эталонные выходные данные
			TermError expOutputData = TermError::EndNumber;

			// Запуск тестируемой функции
			const auto outputData = LateEvaluation(inputData);

			// Сравнение полученных выходных данных с эталонными
			if (expOutputData != outputData) Assert::IsFalse;
			else Assert::IsTrue;
		}

		TEST_METHOD(ContainsLowercaseLetters)
		{
			// Входные данные
			std::string inputData = "A10B5ab";

			// Эталонные выходные данные
			TermError expOutputData = TermError::WrongSymbol;

			// Запуск тестируемой функции
			const auto outputData = LateEvaluation(inputData);

			// Сравнение полученных выходных данных с эталонными
			if (expOutputData != outputData) Assert::IsFalse;
			else Assert::IsTrue;
		}

		TEST_METHOD(ContainsNonAlphabeticCharacters)
		{
			// Входные данные
			std::string inputData = "A10B5;.";

			// Эталонные выходные данные
			TermError expOutputData = TermError::WrongRageOfString;

			// Запуск тестируемой функции
			const auto outputData = LateEvaluation(inputData);

			// Сравнение полученных выходных данных с эталонными
			if (expOutputData != outputData) Assert::IsFalse;
			else Assert::IsTrue;
		}
	};
}
