#include "classunit.h"

std::string CppClassUnit::Compile( unsigned int level ) const//метод возвращает строку, собирает код
{
    std::string result = GenerateShift( level ) + "class " + m_name + " {\n";
    for( size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i )//проходимся по модификаторам доступа
    {

        if( m_fields[i].empty() ) {//пустые, пропускаем
            continue;
        }
        result += ACCESS_MODIFIERS[ i ] + ":\n"; //достаем модификаторы
        for( const auto& f : m_fields[i] )//проходимся по всем внутреностям
        {
            result += f->Compile( level + 1 );//добавляем результаты компиляции для каждого элемента вектора
        }
        result += "\n";
    }
    result += GenerateShift( level ) + "};\n";
    return result;//возвращаем окончательный вид
}

std::string CsClassUnit::Compile( unsigned int level ) const
{
    std::string result = GenerateShift( level ) + "class " + m_name + "\n{\n";
    for( size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i )
    {
        if( m_fields[i].empty() ) {
            continue;
        }

        for( const auto& f : m_fields[i] )
        {
            result +=GenerateShift( level + 1)+ACCESS_MODIFIERS[ i ]+ f->Compile( level + 1 );
        }
    }
    result += GenerateShift( level ) + "};\n";
    return result;
}


std::string JavaClassUnit::Compile( unsigned int level ) const
{
    std::string result = GenerateShift( level ) + "class " + m_name + "\n{\n";
    for( size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i )
    {
        if( m_fields[i].empty() ) {
            continue;
        }
        for( const auto& f : m_fields[i] )
        {
            result +=GenerateShift( level + 1)+ACCESS_MODIFIERS[ i ]+ f->Compile( level + 1 );
        }

    }
    result += GenerateShift( level ) + "};\n";
    return result;
}
