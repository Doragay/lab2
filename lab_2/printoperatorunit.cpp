#include "printoperatorunit.h"

std::string CppPrintUnit::Compile(unsigned int level) const
{
    return GenerateShift(level) + "printf( \"" + m_text + "\" );\n";
}


std::string CsPrintUnit::Compile(unsigned int level) const
{
    return GenerateShift(level) + "Console.WriteLine( \"" + m_text + "\" );\n";
}



std::string JavaPrintUnit::Compile(unsigned int level) const
{
    return GenerateShift(level) + "System.out.println( \"" + m_text + "\" );\n";
}


