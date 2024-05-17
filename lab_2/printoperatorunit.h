#ifndef PRINTOPERATORUNIT_H
#define PRINTOPERATORUNIT_H

#include <AbstractProducts.h>
class CppPrintUnit final:public AbstractPrintUnit
{
public:
    CppPrintUnit( const std::string& text ) : AbstractPrintUnit( text ) { }
    std::string Compile( unsigned int level = 0 ) const;
};


class CsPrintUnit final: public AbstractPrintUnit
{
public:
    CsPrintUnit( const std::string& text ) : AbstractPrintUnit( text ) { }
    std::string Compile( unsigned int level = 0 ) const;
};

class JavaPrintUnit final:public AbstractPrintUnit
{
public:
    JavaPrintUnit( const std::string& text ) : AbstractPrintUnit( text ) { }
    std::string Compile( unsigned int level = 0 ) const;
};


#endif // PRINTOPERATORUNIT_H
