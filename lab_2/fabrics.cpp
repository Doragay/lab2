
#include "fabrics.h"

std::unique_ptr < AbstractClassUnit > CppFactory::CreateClass(const std::string& name)//создает продукты
{
    return std::unique_ptr < AbstractClassUnit >(new CppClassUnit(name));//возвращаем созданные продукт
}
std::unique_ptr < AbstractMethodUnit > CppFactory::CreateMethod(const std::string& name, const std::string& returnType, AbstractUnit::Flags flags)
{
    return std::unique_ptr < AbstractMethodUnit >(new CppMethodUnit(name,returnType,flags));
}
std::unique_ptr < AbstractPrintUnit > CppFactory::CreatePrintOperator(const std::string& text )
{
    return std::unique_ptr < AbstractPrintUnit >(new CppPrintUnit(text));
}


std::unique_ptr < AbstractClassUnit > CsFactory::CreateClass(const std::string& name)
{
    return std::unique_ptr < AbstractClassUnit >(new CsClassUnit(name));
}
std::unique_ptr < AbstractMethodUnit > CsFactory::CreateMethod(const std::string& name, const std::string& returnType, AbstractUnit::Flags flags)
{
    return std::unique_ptr < AbstractMethodUnit >(new CsMethodUnit(name,returnType,flags));
}
std::unique_ptr < AbstractPrintUnit > CsFactory::CreatePrintOperator(const std::string& text )
{
    return std::unique_ptr < AbstractPrintUnit >(new CsPrintUnit(text));
}

std::unique_ptr < AbstractClassUnit > JavaFactory::CreateClass(const std::string& name)
{
    return std::unique_ptr < AbstractClassUnit >(new JavaClassUnit(name));
}
std::unique_ptr < AbstractMethodUnit > JavaFactory::CreateMethod(const std::string& name, const std::string& returnType, AbstractUnit::Flags flags)
{
    return std::unique_ptr < AbstractMethodUnit >(new JavaMethodUnit(name,returnType,flags));
}
std::unique_ptr < AbstractPrintUnit > JavaFactory::CreatePrintOperator(const std::string& text )
{
    return std::unique_ptr < AbstractPrintUnit >(new JavaPrintUnit(text));
}

