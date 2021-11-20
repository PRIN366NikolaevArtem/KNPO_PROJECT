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
    \brief ��������� ���������� ������ �� ������������
    \param[in] inputData ������� ������

    \return ��� ������
*/
TermError LateEvaluation(const std::string_view inputData)
{
    const auto isUpperCaseLetter = [](const char symbol) { return std::isalpha(symbol) && std::isupper(symbol); };
    const bool AllowedSymb = std::all_of(
        inputData.begin(),
        inputData.end(),
        [=](const char symbol) { return isUpperCaseLetter(symbol) || std::isdigit(symbol); }
    );

    /// ������� ��� ������ ���� "������������ ������", ���� ������ ������, ������� �� �������� ��������� ��������� ������ ��� ������
    if (!AllowedSymb)
        return TermError::WrongSymbol;

    /// ������� ��� ������ ���� "��������� �����", ���� ��������� ������ �������� ������
    if (const bool numberAtEnd = std::isdigit(inputData.back()); numberAtEnd)
        return TermError::EndNumber;

    /// ������� ��� ��� ������
    return TermError::Success;
}

/*! 
    \brief ������� ������������� ������ �� ������ ����� �� �������� ����� 
    \param[in] inputData ������������� ������
    \param[in] border ������������ ����� ������

    \return ������ ����� �� �������� ����� 
*/
std::vector<std::string> DivideString(const std::string_view inputData, const int border)
{
    /// ������� ������ ������, ���� ����� ������ ���� ����� 0
    if (border <= 0)
    {
        return {};
    }

    const auto entireBorderAmount = inputData.size() / border;
    const auto lastBorderAmount = inputData.size() % border;

    /// ������� �������������� ������ �����
    std::vector<std::string> result;
    result.reserve(entireBorderAmount + 1);

    /// ��� ������ ������ ��������, ����� ������� ����� ������
    for (int index = 0; index < entireBorderAmount; ++index)
    {
        /// ������� ������ �� ������� ������ ��������
        const auto buffer = inputData.substr(border * index, border);

        /// /�������� ������ � �������������� ������
        result.emplace_back(buffer);
    }

    /// �������� ������ �������� � �������������� ������, ���� ��� ��������� �����  ������ � �� ����� ������ ������
    if (lastBorderAmount > 0)
    {
        const auto lastBuffer = inputData.substr(inputData.size() - lastBorderAmount, lastBorderAmount);
        result.emplace_back(lastBuffer);
    }

    /// ������� �������������� ������
    return result;
}
