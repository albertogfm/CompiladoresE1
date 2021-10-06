
#include "iostream"
#include "string"
#include "Lexer.h"
#include "tokens.h"
using namespace std;
namespace COMPILADOR_C_1{
    
    //ABRIR ARCHIVO
    Lexer::Lexer(string file)
    {
        ifstream afd(file);
        string line, aceptar;
        stringstream s;
        int fila=0, col=0, q;
        getline(afd,line);
        s = stringstream(line);
        s>>numState;
        s>>numTokens;
    
    
    //TABLA DE TRANSICIONES
        tableT = new int*[numState];
        for(int i=0; i<numState; i++){
            tableT[i]=new int[numTokens];
        }

        acept = new bool[numState];

        while(fila < numState){
            getline(afd,line);
            s = stringstream(line);
            while(col < numTokens){
                s >> q;
                tableT[fila][col++]=q;
            }
            s >> aceptar;
            aceptar =="true"? acept[fila] = true : acept[fila]=false;
            fila++;
            col=0;
        }
        afd.close(); //cerrar archivo

    //SÍMBOLOS  
        alfabeto['+'] = 0;
        alfabeto['-'] = 1;
        alfabeto['*'] = 2;
        alfabeto['/'] = 3;
        alfabeto['='] = 4;
        alfabeto[' ']  = 5;
        alfabeto['\t'] = 5;
        alfabeto['\r'] = 5;
        alfabeto['\n'] = 5;
        alfabeto['0'] = 6;
        alfabeto['1'] = 6;
        alfabeto['2'] = 6;
        alfabeto['3'] = 6;
        alfabeto['4'] = 6;
        alfabeto['5'] = 6;
        alfabeto['6'] = 6;
        alfabeto['7'] = 6;
        alfabeto['8'] = 6;
        alfabeto['9'] = 6;
        alfabeto['a'] = 7;
        alfabeto['E'] = 8;
        alfabeto['e'] = 9;
        alfabeto['f'] = 10;
        alfabeto['h'] = 11;
        alfabeto['i'] = 12;
        alfabeto['l'] = 13;
        alfabeto['n'] = 14;
        alfabeto['o'] = 15;
        alfabeto['s'] = 16;
        alfabeto['t'] = 17;
        alfabeto['w'] = 18;
        alfabeto['A'] = 19;
        alfabeto['B'] = 19;
        alfabeto['C'] = 19;
        alfabeto['D'] = 19;
        alfabeto['F'] = 19;
        alfabeto['G'] = 19;
        alfabeto['H'] = 19;
        alfabeto['I'] = 19;
        alfabeto['J'] = 19;
        alfabeto['K'] = 19;
        alfabeto['L'] = 19;
        alfabeto['M'] = 19;
        alfabeto['N'] = 19;
        alfabeto['O'] = 19;
        alfabeto['P'] = 19;
        alfabeto['Q'] = 19;
        alfabeto['R'] = 19;
        alfabeto['S'] = 19;
        alfabeto['T'] = 19;
        alfabeto['U'] = 19;
        alfabeto['V'] = 19;
        alfabeto['W'] = 19;
        alfabeto['X'] = 19;
        alfabeto['Y'] = 19;
        alfabeto['Z'] = 19;
        alfabeto['_'] = 19;
        alfabeto['b'] = 19;
        alfabeto['c'] = 19;
        alfabeto['d'] = 19;
        alfabeto['g'] = 19;
        alfabeto['j'] = 19;
        alfabeto['k'] = 19;
        alfabeto['m'] = 19;
        alfabeto['p'] = 19;
        alfabeto['q'] = 19;
        alfabeto['u'] = 19;
        alfabeto['v'] = 19;
        alfabeto['x'] = 19;
        alfabeto['y'] = 19;
        alfabeto['z'] = 19;
        alfabeto['.'] = 20;
        alfabeto[','] = 21;
        alfabeto[';'] = 22;
        alfabeto['('] = 23;
        alfabeto[')'] = 24;
    }
    
    //DESTRUCTOR

    Lexer::~Lexer()
    {
        for(int i=0; i<numState; i++)
            delete tableT[i];
        delete tableT;
        delete acept;
    }

    bool Lexer::openFile(string file)
    {
        yyin.open(file,ios::in);
        if(!yyin.is_open()){
            cerr << "ERROR EN ABRIR EL ARCHIVO"
            << file << "" << endl;
            return false;
        }
        getChar();
        return true;
    }
    //CARÁCTERES DEL ARCHIVO
    
    void Lexer::getChar(){
        yyin.get(c);
    }
    
    //CERRAR ARCHIVO 

    void Lexer::closeFile(){
        yyin.close();
    }

    //OBTENERTOKENS
    
    int Lexer::yylex(){
        int q=0;
        int cc;
        yytext = "";        
        if(yyin.eof()) return 0;
        while(true){
            cc =  alfabeto[c];
            if(tableT[q][cc]!=-1){
                q=tableT[q][cc];
                yytext+=c;
                getChar();
                if(yyin.eof()) return 0;
            }else{
                if(acept[q]){
                    if(q==17){
                        q = 0;
                        yytext="";
                    }
                    else return token(q);
                }else{
                    return ERROR;
                }
            }
        }
    }

    string Lexer::getYytext(){
        return yytext;
    } 

    //IMPRIMIR TABLA  CON ESTADOS DE TRANSICIÓN
    
    void Lexer::printtableT(){
        for(int i = 0; i<numState; i++){
            for(int j = 0; j<numTokens; j++){
                cout << tableT[i][j] << "\t";
            }
            cout << acept[i] << "\t";
            cout << endl;
        }
    }


   int Lexer::token(int q)
    {
        // TODO(7) Completar la función para que pueda retornar los tokens
        //COMPLETADO SEGÚN
        switch(q){
            case 1:
                return MAS;
            case 2:
                return MENOS;
            case 3:
                return MUL;
            case 4:
                return DIV;
            case 5:
                return ASIG;
            case 6:
                return LPAR;
            case 7:
                return RPAR;
            case 8:
                return PYC;
            case 9:
                return COMA;
            case 10 : case 20 : case 35:
                return NUMERO;
            case 12 : case 13 : case 14 : case 15 : case 16 : case 18 : case 21 :
            case 22 : case 23 : case 25 : case 26 : case 27 :  case 30 :
                return ID;
            case 17:
                return ESP;
            case 19:
                return IF;
            case 24:
                return INT;
            case 29:
                return ELSE;
            case 31:
                return FLOAT;
            case 32:
                return WHILE; 
        }
        return -1;
    }


    //int Lexer::charToColumn()
    //{
    //    
    //}

}

