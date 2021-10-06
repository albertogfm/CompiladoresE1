#ifndef PARSER_H
#define PARSER_H
#include "Lexer.h"
#include <string>
using namespace std;
#include "tokens.h"

namespace C_1
{
    class Parser
    {
    private:
        Lexer *lexer;
        int token;
    public:
        Parser();
        Parser(Lexer *lexer);
        ~Parser();
        void programa();
        void declaraciones();
        void declaraciones_();
        void declaracion();
        void tipo();
        void lista_var();
        void lista_var_();
        void sentencias();
        void sentencias_();
        void sentencia();
        void expresion();
        void expresion_();
        void termino();
        void termino_();
        void factor();

        void eat(int t);
        void error(string msg);
        void parse();
    };    
    
} // namespace C_1


#endif