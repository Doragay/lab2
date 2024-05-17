#ifndef METHODUNIT_H
#define METHODUNIT_H

#include <AbstractProducts.h>
#include <memory>
#include <vector>
#include <classunit.h>

class CppMethodUnit final:public AbstractMethodUnit
{
public:
    CppMethodUnit( const std::string& name, const std::string& returnType, Flags flags ) :AbstractMethodUnit(name,returnType,flags){}
    std::string Compile( unsigned int level ) const;
};

class CsMethodUnit final: public AbstractMethodUnit
{
public:
    CsMethodUnit( const std::string& name, const std::string& returnType, Flags flags ) :AbstractMethodUnit(name,returnType,flags){}
    std::string Compile( unsigned int level ) const;
};

class JavaMethodUnit final: public AbstractMethodUnit
{
public:
    JavaMethodUnit( const std::string& name, const std::string& returnType, Flags flags ) :AbstractMethodUnit(name,returnType,flags){}
    std::string Compile( unsigned int level ) const;
};
#endif // METHODUNIT_H
