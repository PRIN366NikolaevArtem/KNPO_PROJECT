/*! \mainpage StringUnpacker
 *
 * Программа StringUnpacker предназначена для распаковки строки, которая была запакована парой значений: 
 * количеством повторений символа и самим символом. Программа может быть применена при разработке проектов, 
 * связанных с обработкой строк. 
 * \author Николаев А.Д. ПрИн-266
 */

#include "header.hpp"

#include <filesystem>


/*! 
    \brief Проверка файла на корректность
    \param[in] argc количество аргументов командной строки
    \param[in] argv аргументы командной строки
    \param[in|out] str упакованная строка

    \return код ошибки
*/
int PreExecuteCheck(int argc, char **argv, std::string &str)
{
    /// Если входной файл не указан в аргументах командной строки
    if (argc <= 1)
    {
        /// Вывести сообщение об ошибке и завершить работу программы
        std::cerr << "Program's argument is empty.\nEnter name of a file that contains string" << std::endl;
        return 1;
    }

    std::ifstream filename{ argv[1] };

    /// Если входной файл невозможно открыть
    if (!filename.is_open())
    {
        /// Вывести сообщение об ошибке и завершить работу программы
        std::cerr << "File Was Not Opened!" << std::endl;
        return 1;
    }

    /// Считать строку из файла
    filename >> str;

    return 0;
}


 /*! 
     \brief Обеспечить считывание из файла, вывод в консоль ошибок, если они есть, запись ответа в выходной файл, вызов главной функции, решающей задачу
    
     \return код завершения программы
 */
int main(const int argc, char** argv)
{
    std::string str;

    /// Если обнаружена ошибка
    if (PreExecuteCheck(argc, argv, str))
        /// Завершить работу программы
        return 1;
    try
    {
        /// Распаковать строку
        const std::string rawData = StringProcessing(str);
        /// Разбить распакованную строку на массив строк по длине 40 символов
        const auto containerOfStrs = DivideString(rawData, 40);

        using namespace std::filesystem;
        path resultName{argv[1]};
        resultName.replace_filename("unpacked_" + resultName.filename().string());

        /// Записать массив строк в выходной файл
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
