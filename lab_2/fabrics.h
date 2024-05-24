
#ifndef FABRICS_H
#define FABRICS_H
#include "classunit.h"
#include "methodunit.h"
#include "printoperatorunit.h"
#include "AbstractProducts.h"
#include <memory>
class AbstractFactory//интерфейс для фабричных методов
{
public:
    virtual std::unique_ptr < AbstractClassUnit > CreateClass(const std::string& name) = 0;//функция создает и возвращает умный указатель на объект
    virtual std::unique_ptr < AbstractMethodUnit > CreateMethod(const std::string& name, const std::string& returnType, AbstractUnit::Flags flags) = 0;
    virtual std::unique_ptr < AbstractPrintUnit > CreatePrintOperator(const std::string& text ) = 0;
    virtual ~AbstractFactory() = default;
};

class CppFactory:public AbstractFactory
{
public:
    std::unique_ptr < AbstractClassUnit > CreateClass(const std::string& name);
    std::unique_ptr < AbstractMethodUnit > CreateMethod(const std::string& name, const std::string& returnType, AbstractUnit::Flags flags);
    std::unique_ptr < AbstractPrintUnit > CreatePrintOperator(const std::string& text );
};

class CsFactory: public AbstractFactory
{
public:
    std::unique_ptr < AbstractClassUnit > CreateClass(const std::string& name);
    std::unique_ptr < AbstractMethodUnit > CreateMethod(const std::string& name, const std::string& returnType, AbstractUnit::Flags flags);
    std::unique_ptr < AbstractPrintUnit > CreatePrintOperator(const std::string& text );
};

class JavaFactory: public AbstractFactory
{
public:
    std::unique_ptr < AbstractClassUnit > CreateClass(const std::string& name);
    std::unique_ptr < AbstractMethodUnit > CreateMethod(const std::string& name, const std::string& returnType, AbstractUnit::Flags flags);
    std::unique_ptr < AbstractPrintUnit > CreatePrintOperator(const std::string& text );
};
#endif // FABRICS_H
