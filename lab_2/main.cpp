
#include <classunit.h>
#include <methodunit.h>
#include <printoperatorunit.h>
#include <memory>
#include <string>
#include <iostream>
#include <QCoreApplication>
#include <fabrics.h>

using namespace std;

// В зависимости от строки, функция создает и возвращает указатель на объект конкретной фабрики
AbstractFactory* generateFactory(string language){
    if (language == "Cpp"){
        return new CppFactory();
    } else if (language == "Cs"){
        return new CsFactory();
    } else if (language == "Java"){
        return new JavaFactory();
    } else {
        throw std::runtime_error("The language wasn't found\n"); // выбрасываем исключения
    }
}

// Функция, генерирующая программу на основе выбранного языка
std::string generateProgram(string language) {
    try {
        AbstractFactory* factory = generateFactory(language);// Создаем объект фабрики для выбранного языка
        // Создаем различные элементы программы с помощью фабрики
        std::shared_ptr<AbstractUnit> myClass = factory->CreateClass("MyClass");//создает новый класс с помощью фабрики и сохраняет умный указатель на этот класс в переменной
        std::shared_ptr<AbstractUnit> method1 = factory->CreateMethod("Functhion1","void", 0);
        std::shared_ptr<AbstractUnit> method2 = factory->CreateMethod("Functhion2","void",AbstractMethodUnit::STATIC);//имя, тип возвращаемого значения, флаг на модификатор
        std::shared_ptr<AbstractUnit> method3 = factory->CreateMethod("Functhion3","void",AbstractMethodUnit::VIRTUAL|AbstractMethodUnit::CONST);
        std::shared_ptr<AbstractUnit> printoperator = factory->CreatePrintOperator(R"(Hello, world!)"); //создаем оператор печати
        std::shared_ptr<AbstractUnit> method4= factory->CreateMethod("Functhion4","void",AbstractMethodUnit::STATIC);
        // Добавляем методы в класс
        method4->Add(printoperator,0);
        myClass->Add(method1,AbstractClassUnit::PUBLIC);
        myClass->Add(method2,AbstractClassUnit::PRIVATE);
        myClass->Add(method3,AbstractClassUnit::PUBLIC);
        myClass->Add(method4,AbstractClassUnit::PROTECTED);
        return myClass->Compile();// Компилируем и возвращаем строковое представление программы
    }
    //блок обрабатывает исключения, возникающие во вемя генерации программы, и выводит инфу об исключениях
    catch (const std::runtime_error& e) {
        std::cerr << e.what();
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    while(1){
        std::string language;//Переменная в которую будет сохранен язык программирования
        std::cin >> language;
        std::cout << generateProgram(language) << std::endl;//генерирует и выводит текст на нужном языке
    }
    return a.exec();
}


