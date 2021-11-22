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
    \brief Распаковать строку
	\param[in] inputData входная строка
	
	\return распакованная строка
*/
std::string StringProcessing(const std::string_view inputData)
{
    /// Выдать ошибку, если размер строки не соответствует разрешенному диапазону
    if (inputData.empty() || inputData.size() > 80)
        throw ExceptionError{TermError::WrongRageOfString};

    /// Выдать ошибку, если содержимое строки не корректно
    if (const auto numbErr = LateEvaluation(inputData);
        numbErr != TermError::Success)
        throw ExceptionError{numbErr};

    /// Разделить строку на модули...
    const std::vector<Unit> arrayOfCharacters = DivideStringToChars(inputData);

    /// Перевести модули в распакованную строку...
    int quantityCom = 0;
    for (const auto [quantityCurrent, _] : arrayOfCharacters)
        quantityCom += quantityCurrent;

    // Создать строку, в которую будут распакованы модули
    std::string unpackedString;
    unpackedString.reserve(quantityCom);

    /// Для каждого модуля
    for (const auto [quantityCurrent, Char] : arrayOfCharacters)
        // Добавить к строке символ, содержащийся в модуле в количестве, которое указано в модуле
        unpackedString += std::string(quantityCurrent, Char);

    /// Вернуть распакованную строку
    return unpackedString;
}

/*! 
    \brief Сформировать модуль и записать его в массив
    \param[in|out] currentIterator ссылка на текущий символ, на котором остановился итератор
    \param[in|out] inputData ссылка на текущий символ, на котором остановился итератор
    \param[in|out] arrayOfCharacters ссылка на текущий символ, на котором остановился итератор

    \return текущий символ, на котором остановился итератор
*/
auto FillUnitArray(std::string_view::const_iterator &currentIterator, const std::string_view& inputData, std::vector<Unit> &arrayOfCharacters)
{
    /// Начало числа повторений – текущий символ
    const auto beginIt = currentIterator;

    /// Найти первый нецифровой символ – это запоследний символ числа повторений, а также повторяемая буква
    const auto endIt = std::find_if(currentIterator, inputData.end(), std::not_fn(std::isdigit));

    /// Конвертировать строку с числом повторением в число
    const std::string_view currentStr = inputData.substr(beginIt - inputData.begin(), endIt - inputData.begin());
    int quantity = 0;
    std::from_chars(currentStr.data(), currentStr.data() + currentStr.size(), quantity);

    /// Если число повторений не входит в разрешенный диапазон – выдать ошибку
    if (quantity < 2 || quantity > 99)
        throw ExceptionError{ TermError::WrongRepeat };

    /// Добавить в массив модуль с вычисленным числом повторений и повторяемой буквой
    arrayOfCharacters.push_back({ quantity, *endIt });

    /// Считать текущим символом следующий символ после повторяемой буквы
    return endIt;
}

/*! 
    \brief Разделить строку на модули
    \param[in] inputData входная строка

    \return массив модулей
*/
std::vector<Unit> DivideStringToChars(const std::string_view inputData)
{
    /// Создать массив, в который будем сохранять модули
    std::vector<Unit> arrayOfCharacters;

    /// Для каждого символа строки
    for (auto currentIterator = inputData.begin(); currentIterator != inputData.end(); ++currentIterator)
    {
        /// Если текущий символ – буква
        if (std::isalpha(*currentIterator))
        {
            /// Добавить в массив модуль с текущим символом и количеством символов равным 1
            arrayOfCharacters.push_back({1, *currentIterator});

            /// Перейти к следующей итерации
            continue;
        }
        
        /// Сформировать модуль и записать его в массив
        currentIterator = FillUnitArray(currentIterator, inputData, arrayOfCharacters);
    }

    /// Вернуть получившийся массив модулей
    return arrayOfCharacters;
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
