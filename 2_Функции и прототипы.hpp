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
    \brief ��������� ��� ��������� ������
*/
enum struct TermError
{
    Success, /// ��� ������
    WrongSymbol, /// ������: ������������� ������ � ������
    EndNumber, /// ������: � ������ ��������� ������ � �����
    WrongRageOfString, /// ������: ������ ������ ��� ������������ ���������
    WrongRepeat /// ������: ����� ���������� ����� ��� ������������ ���������
};

/*!
    \brief ��������� ������
*/
struct Unit
{
    int quantityCurrent; /// ���������� ���������� �������
    char Char; /// ������������� �����
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

/*! ����������� ������.
    \param[in] inputData ������� ������

    return ������������� ������
*/
std::string StringProcessing(std::string_view str);

/*! ��������� ������ �� ������
    \param[in] inputData ������� ������

    return ������ �������
*/
std::vector<Unit> DivideStringToChars(std::string_view str);

/*! ��������� ���������� ������ �� ������������
    \param[in] inputData ������� ������

    return ��� ������
*/
TermError LateEvaluation(std::string_view str);

/*! ������� ������������� ������ �� ������ ����� �� �������� �����
    \param[in] inputData ������������� ������
    \param[in] border ������������ ����� ������

    return ������ ����� �� �������� �����
*/
std::vector<std::string> DivideString(std::string_view str, int border);


int PreExecuteCheck(int argc, char** argv, std::string& str);

/*! ������������ ������ � �������� ��� � ������
    \param[in|out] currentIterator ������ �� ������� ������, �� ������� ����������� ��������
    \param[in|out] inputData ������ �� ������� ������, �� ������� ����������� ��������
    \param[in|out] arrayOfCharacters ������ �� ������� ������, �� ������� ����������� ��������

    return ������� ������, �� ������� ����������� ��������
*/
auto FillUnitArray(std::string_view::const_iterator& currentIterator, const std::string_view& inputData, std::vector<Unit>& arrayOfCharacters);