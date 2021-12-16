#pragma once
#include <string>
#include <vector>
#include <string_view>

#include <algorithm>
#include <charconv>
#include <stdexcept>
#include <functional>

#include <fstream>
#include <iostream> 

/*!
    \brief Структура для обработки ошибок
*/
enum struct TermError
{
    Success, /// нет ошибки
    WrongSymbol, /// ошибка: неразрешенный символ в строке
    EndNumber, /// ошибка: в строке последний символ – цифра
    WrongRageOfString, /// ошибка: размер строки вне разрешенного диапазона
    WrongRepeat /// ошибка: число повторений буквы вне разрешенного диапазона
};

/*!
    \brief Структура модуль
*/
struct Unit
{
    int quantityCurrent; /// количество повторений символа
    char Char; /// повторяющаяся буква
};

inline bool operator==(const Unit lhs, const Unit rhs)
{
    return lhs.quantityCurrent == rhs.quantityCurrent && lhs.Char == rhs.Char;
}

struct ExceptionError final : std::invalid_argument
{
    using std::invalid_argument::invalid_argument;
    explicit ExceptionError(const TermError code);
private:
    static std::string ErrorManager(const TermError code);
};

/*! Распаковать строку.
    \param[in] inputData входная строка

    return распакованная строка
*/
std::string StringProcessing(std::string_view str);

/*! Разделить строку на модули
    \param[in] inputData входная строка

    return массив модулей
*/
std::vector<Unit> DivideStringToChars(std::string_view str);

/*! Проверить содержимое строки на корректность
    \param[in] inputData входная строка

    return код ошибки
*/
TermError LateEvaluation(std::string_view str);

/*! Разбить распакованную строку на массив строк по заданной длине
    \param[in] inputData распакованная строка
    \param[in] border ограничитель длины строки

    return массив строк по заданной длине
*/
std::vector<std::string> DivideString(std::string_view str, int border);


int PreExecuteCheck(int argc, char** argv, std::string& str);

/*! Сформировать модуль и записать его в массив
    \param[in|out] currentIterator ссылка на текущий символ, на котором остановился итератор
    \param[in|out] inputData ссылка на текущий символ, на котором остановился итератор
    \param[in|out] arrayOfCharacters ссылка на текущий символ, на котором остановился итератор

    return текущий символ, на котором остановился итератор
*/
auto FillUnitArray(std::string_view::const_iterator& currentIterator, const std::string_view& inputData, std::vector<Unit>& arrayOfCharacters);