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


///����� ��������� ������ ���������
enum struct TermError
{

    Success, ///< ��� ������
    
    WrongSymbol, ///< ������: ������������� ������ � ������
    
    EndNumber, ///< ������: � ������ ��������� ������ � �����
    
    WrongRageOfString, ///< ������: ������ ������ ��� ������������ ���������
    
    WrongRepeat ///< ������: ����� ���������� ����� ��� ������������ ���������
};

/*!
    \brief ��������� ������
*/
struct Unit
{
    /// ���������� ���������� �������
    int quantityCurrent;
    /// ������������� �����
    char Char; 
};

/*!
    \brief �������� ��������� ���� ������� �� ���������

    \param[in] 1hs ������ ������
    \param[in] 2hs ������ ������

    \return ��������� ��������
*/
inline bool operator==(const Unit lhs, const Unit rhs)
{
    return lhs.quantityCurrent == rhs.quantityCurrent && lhs.Char == rhs.Char;
}

/*!
    \brief ��������� ���������������� ����������
*/
struct ExceptionError final : std::invalid_argument
{
    using std::invalid_argument::invalid_argument;
    explicit ExceptionError(const TermError code);
private:
    static std::string ErrorManager(const TermError code);
};

/*! 
    \brief ����������� ������
    \param[in] inputData ������� ������

    \return ������������� ������
*/
std::string StringProcessing(std::string_view str);

/*! 
    \brief ��������� ������ �� ������
    \param[in] inputData ������� ������

    \return ������ �������
*/
std::vector<Unit> DivideStringToChars(std::string_view str);

/*! 
    \brief ��������� ���������� ������ �� ������������
    \param[in] inputData ������� ������

    \return ��� ������
*/
TermError LateEvaluation(std::string_view str);

/*! 
    \brief ������� ������������� ������ �� ������ ����� �� �������� �����
    \param[in] inputData ������������� ������
    \param[in] border ������������ ����� ������

    \return ������ ����� �� �������� �����
*/
std::vector<std::string> DivideString(std::string_view str, int border);

/*!
    \brief �������� ����� �� ������������
    \param[in] argc ���������� ���������� ��������� ������
    \param[in] argv ��������� ��������� ������
    \param[in|out] str ����������� ������

    \return ��� ������
*/
int PreExecuteCheck(int argc, char** argv, std::string& str);

/*! 
    \brief ������������ ������ � �������� ��� � ������
    \param[in|out] currentIterator ������ �� ������� ������, �� ������� ����������� ��������
    \param[in|out] inputData ������ �� ������� ������, �� ������� ����������� ��������
    \param[in|out] arrayOfCharacters ������ �� ������� ������, �� ������� ����������� ��������

    \return ������� ������, �� ������� ����������� ��������
*/
auto FillUnitArray(std::string_view::const_iterator& currentIterator, const std::string_view& inputData, std::vector<Unit>& arrayOfCharacters);