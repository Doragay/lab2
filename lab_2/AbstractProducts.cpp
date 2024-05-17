#include "AbstractProducts.h"


void AbstractUnit::Add(const std::shared_ptr<AbstractUnit>& unit, Flags flags){
    throw std::runtime_error( "Not supported" );//выбрасывает исключения
}
std::string AbstractUnit::GenerateShift( unsigned int level ) const{ //генерация отступов
    static const auto DEFAULT_SHIFT = "  ";
    std::string result;
    for( unsigned int i = 0; i < level; ++i ) {
        result += DEFAULT_SHIFT;
    }
    return result;

}
//список модификаторов
const std::vector<std::string> AbstractClassUnit::ACCESS_MODIFIERS = { "public","protected", "private", "internal", "protected internal", "private protected"};

void AbstractClassUnit::Add( const std::shared_ptr<AbstractUnit>& unit, Flags flags )//
{
    int accessModifier = PRIVATE;
    if( flags < ACCESS_MODIFIERS.size() )//проверка на допустимость модификатора доступа
    {
        accessModifier = flags;
    }
    m_fields[accessModifier].push_back( unit );//добавляет объект
}


void AbstractMethodUnit::Add(const std::shared_ptr<AbstractUnit>& unit, Flags flags )
{
    m_body.push_back( unit );
}






