#include "header.hpp"

    ExceptionError::ExceptionError(const TermError code) : ExceptionError(ErrorManager(code))
    {
    }

    std::string ExceptionError::ErrorManager(const TermError code)
    {
        switch (code)
        {
        case TermError::Success:
            return "No Error";
        case TermError::WrongSymbol:
            return "Input data is not correct. Allowed only upper case Latin letters and digits!";
        case TermError::EndNumber:
            return "Input data is not correct. Digit at the end is not allowed!";
        case TermError::WrongRageOfString:
            return "Input data is not correct. Range of Data is exceeded. Allowed range of [1; 80]";
        case TermError::WrongRepeat:
            return "Input data is not correct. Number of repetition out of range [2; 99]!";
        default:;
        }

        return "";
    }



/*! 
    \brief Проверить содержимое строки на корректность
    \param[in] inputData входная строка

    \return код ошибки
*/
TermError LateEvaluation(const std::string_view inputData)
{
    const auto isUpperCaseLetter = [](const char symbol) { return std::isalpha(symbol) && std::isupper(symbol); };
    const bool AllowedSymb = std::all_of(
        inputData.begin(),
        inputData.end(),
        [=](const char symbol) { return isUpperCaseLetter(symbol) || std::isdigit(symbol); }
    );

    /// Вернуть код ошибки типа "некорректный символ", если найден символ, который не является заглавной латинской буквой или цифрой
    if (!AllowedSymb)
        return TermError::WrongSymbol;

    /// Вернуть код ошибки типа "последняя цифра", если последний символ является цифрой
    if (const bool numberAtEnd = std::isdigit(inputData.back()); numberAtEnd)
        return TermError::EndNumber;

    /// Вернуть код без ошибки
    return TermError::Success;
}

/*! 
    \brief Разбить распакованную строку на массив строк по заданной длине 
    \param[in] inputData распакованная строка
    \param[in] border ограничитель длины строки

    \return массив строк по заданной длине 
*/
std::vector<std::string> DivideString(const std::string_view inputData, const int border)
{
    /// Вернуть пустой массив, если лимит меньше либо равен 0
    if (border <= 0)
    {
        return {};
    }

    const auto entireBorderAmount = inputData.size() / border;
    const auto lastBorderAmount = inputData.size() % border;

    /// Создать результирующий массив строк
    std::vector<std::string> result;
    result.reserve(entireBorderAmount + 1);

    /// Для каждой группы символов, длина которой равна лимиту
    for (int index = 0; index < entireBorderAmount; ++index)
    {
        /// Создать строку из текущей группы символов
        const auto buffer = inputData.substr(border * index, border);

        /// /Добавить строку в результирующий массив
        result.emplace_back(buffer);
    }

    /// Добавить группу символов в результирующий массив, если она находится конце  строки и ее длина меньше лимита
    if (lastBorderAmount > 0)
    {
        const auto lastBuffer = inputData.substr(inputData.size() - lastBorderAmount, lastBorderAmount);
        result.emplace_back(lastBuffer);
    }

    /// Вернуть результирующий массив
    return result;
}
