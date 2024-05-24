
#include "methodunit.h"
std::string CppMethodUnit::Compile( unsigned int level ) const
{
    std::string result = GenerateShift( level );
    if( m_flags & STATIC )//проверка флага
    {
        result += "static ";
    }
    else if( m_flags & VIRTUAL )
    {
        result += "virtual ";
    }
    result += m_returnType + " ";//добавляем тип к переменной
    result += m_name + "()";

    if( m_flags & CONST ) {
        result += " const";
    }
    result += " {\n";
    for( const auto& b : m_body )//проходимся по каждому элементу вектора
    {
        result += b->Compile( level + 1 ); //компилируем каждый элемент
    }
    result += GenerateShift( level ) + "}\n";
    return result;
}

std::string CsMethodUnit::Compile( unsigned int level ) const
{
    std::string result = GenerateShift( level );
    if( m_flags & STATIC )
    {
        result += "static ";
    }
    else if( m_flags & VIRTUAL )
    {
        result += "virtual ";
    }
    else if( m_flags & ABSTARCT )
    {
        result += "abstract ";
    }
    else if( m_flags & EXTERN )
    {
        result += "extern ";
    }
    result += m_returnType + " ";
    result += m_name + "()";

    result += "\n"+GenerateShift( level )+"{\n";
    for( const auto& b : m_body )
    {
        result += b->Compile( level + 1 );
    }
    result +=  GenerateShift( level ) + "}\n";
    return result;
}

std::string JavaMethodUnit::Compile( unsigned int level ) const
{
    std::string result = GenerateShift( level );
    if( m_flags & STATIC )
    {
        result += "static ";
    }
    else if( m_flags & VIRTUAL )
    {
        result += "virtual ";
    }
    else if( m_flags & ABSTARCT )
    {
        result += "abstract ";
    }
    else if( m_flags & SYNCHRONIZED )
    {
        result += "synchronized ";
    }
    else if( m_flags & VOLATILE )
    {
        result += "volatile ";
    }
    result += m_returnType + " ";
    result += m_name + "()";

    result += "\n"+GenerateShift( level )+"{\n";
    for( const auto& b : m_body )
    {
        result += b->Compile( level + 1 );
    }
    result +=  GenerateShift( level ) + "}\n";
    return result;
}



