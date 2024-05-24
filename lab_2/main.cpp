
#include <classunit.h>
#include <methodunit.h>
#include <printoperatorunit.h>
#include <memory>
#include <iostream>
#include <QCoreApplication>
#include <fabrics.h>

std::string generateProgram( const std::shared_ptr< AbstractFactory >& program ) {//создаем объекты с помощью переданной абстрактной фабрики
    std::string str = "MyClass";
    auto myClass = program->CreateClass(str);//создаем класс
    myClass->Add(program->CreateMethod( "Functhion1", "void", 0 ),AbstractClassUnit::PUBLIC);//добавляю метод к классу с модификатором доступа
    myClass->Add(program->CreateMethod( "Functhion2", "void", AbstractMethodUnit::STATIC ),AbstractClassUnit::PRIVATE);
    myClass->Add(program->CreateMethod( "Functhion3", "void", AbstractMethodUnit::VIRTUAL | AbstractMethodUnit::CONST ), AbstractClassUnit::PUBLIC);
    std::shared_ptr< AbstractMethodUnit > method = program->CreateMethod( "Functhion4", "void",AbstractMethodUnit::EXTERN );
    method->Add( program->CreatePrintOperator( R"(Hello, world!\n)" ) );
    myClass->Add( method, AbstractClassUnit::PROTECTED );
    myClass->Add(program->CreateMethod( "Functhion5", "void", AbstractMethodUnit::VIRTUAL | AbstractMethodUnit::CONST ), AbstractClassUnit::PUBLIC);

    return myClass->Compile();//вызов метода и возвращение результата компиляции

}

int main(int argc, char *argv[])
{
    std::cout << "=================================" << std::endl;
    std::cout << "C++ program" << std::endl;
    std::cout << "=================================" << std::endl;
    std::cout << generateProgram(std::make_shared< CppFactory >()) << std::endl;
    std::cout << std::endl;

    QCoreApplication a(argc, argv);
    std::cout << "=================================" << std::endl;
    std::cout << "C# program" << std::endl;
    std::cout << "=================================" << std::endl;
    std::cout << generateProgram(std::make_shared< CsFactory >()) << std::endl;
    std::cout << std::endl;

    std::cout << "=================================" << std::endl;
    std::cout << "Java program" << std::endl;
    std::cout << "=================================" << std::endl;
    std::cout << generateProgram(std::make_shared< JavaFactory >()) << std::endl;
    return a.exec();
}
