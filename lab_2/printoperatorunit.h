#include <string>
#include <vector>
#include <unit.h>
#ifndef PRINTOPERATORUNIT_H
#define PRINTOPERATORUNIT_H

class PrintOperatorUnit : public Unit {
public:
    explicit PrintOperatorUnit( const std::string& text ) : m_text( text ) { }
    std::string compile( unsigned int level = 0 ) const {
        return generateShift( level ) + "printf( \"" + m_text + "\" );\n";
    }
private:
    std::string m_text;
};

#endif // PRINTOPERATORUNIT_H