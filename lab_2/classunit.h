#ifndef CLASSUNIT_H
#define CLASSUNIT_H

#include <AbstractProducts.h>
#include <memory>
#include <vector>
#include <string>

class CppClassUnit final: public AbstractClassUnit
{
public:
    CppClassUnit( const std::string& name ) : AbstractClassUnit(name){}//вывзывает конструктор абастрактного класса и передаем параметр
    std::string Compile( unsigned int level = 0 ) const;
};

class CsClassUnit final:public AbstractClassUnit
{
public:
    CsClassUnit( const std::string& name ) : AbstractClassUnit(name){}
    std::string Compile( unsigned int level = 0 ) const;
};


class JavaClassUnit final:public AbstractClassUnit
{
public:
    JavaClassUnit( const std::string& name ) : AbstractClassUnit(name){}
    std::string Compile( unsigned int level = 0 ) const;
};


#endif // CLASSUNIT_H
