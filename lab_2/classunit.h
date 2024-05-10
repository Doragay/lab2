#include <vector>
#include <memory>
#include <string>
#include <unit.h>
#ifndef CLASSUNIT_H
#define CLASSUNIT_H

class ClassUnit : public Unit
{
public:
    enum AccessModifier {
        PUBLIC,
        PROTECTED,
        PRIVATE
    };
    static const std::vector< std::string > ACCESS_MODIFIERS;
public:
    explicit ClassUnit( const std::string& name );
    void add( const std::shared_ptr< Unit >& unit, Flags flags );
    std::string compile( unsigned int level = 0 ) const;
private:
    std::string m_name;
    using Fields = std::vector< std::shared_ptr< Unit > >;
    std::vector< Fields > m_fields;
};
const std::vector< std::string > ClassUnit::ACCESS_MODIFIERS = { "public",
                                                              "protected", "private" };

#endif // CLASSUNIT_H
