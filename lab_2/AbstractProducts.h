#ifndef ABSTRACTPRODUCTS_H
#define ABSTRACTPRODUCTS_H
#include <string>
#include <memory>
#include <vector>
#include <stdexcept>
#include <cassert>
class AbstractUnit
{
public:
    using Flags = unsigned int;//тип модификатора
    virtual void Add(const std::shared_ptr<AbstractUnit>& unit, Flags flags);
    virtual std::string Compile( unsigned int level = 0 ) const = 0;
    virtual ~AbstractUnit() = default;
protected:
    virtual std::string GenerateShift( unsigned int level ) const;
};

class AbstractClassUnit : public AbstractUnit
{
public:
    enum AccessModifier {
        PUBLIC,
        PROTECTED,
        PRIVATE,
        INTERNAL,
        PROTECTED_INTERNAL,
        PRIVATE_PROTECTED
    };

    static const std::vector< std::string > ACCESS_MODIFIERS;
protected:
    std::string m_name;
    using Fields = std::vector<std::shared_ptr<AbstractUnit>>;
    std::vector<Fields> m_fields;
public:
    explicit AbstractClassUnit( const std::string& name ) : m_name(name){//конструктор принимает ссылку на имя класса и инициализирует поле m_name этим параметром
        m_fields.resize( ACCESS_MODIFIERS.size() );}//изменяет размер контейнера
    void Add(const std::shared_ptr<AbstractUnit >& unit, Flags flags );

};

class AbstractMethodUnit:public AbstractUnit
{
protected:
    std::string m_name;
    std::string m_returnType;
    Flags m_flags;
    std::vector<std::shared_ptr<AbstractUnit>>  m_body;
public:
    enum Modifier {
        STATIC = 1,
        CONST = 1 << 1,
        VIRTUAL = 1 << 2,
        ABSTARCT = 1 << 3,
        EXTERN = 1 << 4,
        SYNCHRONIZED = 1 << 5,
        VOLATILE = 1 << 6
    };

public:
    AbstractMethodUnit( const std::string& name, const std::string& returnType, Flags flags ) : m_name( name ), m_returnType( returnType ), m_flags( flags ){} //конструктор позволяет создавать объекты класса, инициализируя их
    void Add(const std::shared_ptr<AbstractUnit>& unit, Flags = 0 );

};

class AbstractPrintUnit:public AbstractUnit//оператор вывода
{
public:
    explicit AbstractPrintUnit( const std::string& text ) : m_text( text ) { }
protected:
    std::string m_text;
};



#endif //ABSTRACTPRODUCTS_H
