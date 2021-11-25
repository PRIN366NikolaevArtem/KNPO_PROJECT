/*! \mainpage StringUnpacker
 *
 * ��������� StringUnpacker ������������� ��� ���������� ������, ������� ���� ���������� ����� ��������: 
 * ����������� ���������� ������� � ����� ��������. ��������� ����� ���� ��������� ��� ���������� ��������, 
 * ��������� � ���������� �����. 
 * \author �������� �.�. ����-266
 */

#include "header.hpp"

#include <filesystem>


/*! 
    \brief �������� ����� �� ������������
    \param[in] argc ���������� ���������� ��������� ������
    \param[in] argv ��������� ��������� ������
    \param[in|out] str ����������� ������

    \return ��� ������
*/
int PreExecuteCheck(int argc, char **argv, std::string &str)
{
    /// ���� ������� ���� �� ������ � ���������� ��������� ������
    if (argc <= 1)
    {
        /// ������� ��������� �� ������ � ��������� ������ ���������
        std::cerr << "Program's argument is empty.\nEnter name of a file that contains string" << std::endl;
        return 1;
    }

    std::ifstream filename{ argv[1] };

    /// ���� ������� ���� ���������� �������
    if (!filename.is_open())
    {
        /// ������� ��������� �� ������ � ��������� ������ ���������
        std::cerr << "File Was Not Opened!" << std::endl;
        return 1;
    }

    /// ������� ������ �� �����
    filename >> str;

    return 0;
}


 /*! 
     \brief ���������� ���������� �� �����, ����� � ������� ������, ���� ��� ����, ������ ������ � �������� ����, ����� ������� �������, �������� ������
    
     \return ��� ���������� ���������
 */
int main(const int argc, char** argv)
{
    std::string str;

    /// ���� ���������� ������
    if (PreExecuteCheck(argc, argv, str))
        /// ��������� ������ ���������
        return 1;
    try
    {
        /// ����������� ������
        const std::string rawData = StringProcessing(str);
        /// ������� ������������� ������ �� ������ ����� �� ����� 40 ��������
        const auto containerOfStrs = DivideString(rawData, 40);

        using namespace std::filesystem;
        path resultName{argv[1]};
        resultName.replace_filename("unpacked_" + resultName.filename().string());

        /// �������� ������ ����� � �������� ����
        std::ofstream resultFile{resultName};
        for (const auto& str : containerOfStrs)
        {
            resultFile << str << std::endl;
        }
    }
    catch (std::exception& exception)
    {
        std::cerr << exception.what() << std::endl;
        return 1;
    }
}
