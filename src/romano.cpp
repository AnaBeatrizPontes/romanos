// Copyright [2021] <Ana Beatriz>

//  Inclui o arquivo de cabeçalho do projeto
#include "../include/romano.hpp"

//  Função que converte os números de romano para arábico
//  e faz todos os testes necessários
int convert_number(std::string STRING_ROMANA_) {
    //  Declaração de um vetor com números arabicos
    int ARABIC_NUMBER_[8] = { 0, 1, 5, 10, 50, 100, 500, 1000 };
    //  Declaração de um vetor com numeros romanos
    char ROMAN_STRING_[8] = { '0', 'I', 'V', 'X', 'L', 'C', 'D', 'M' };

    // Declaração de variáveis auxiliares para o desenvolvimento
    int CONT = 0;
    int AUX = 0;
    int PREV = 0;
    int SUM = 0;
    int NUM = 0;
    char LETTER = ' ';
    int VAL = 0;

    //  Loop para percorrer toda a string recebida
    for (AUX = 0; AUX < STRING_ROMANA_.length(); AUX++) {
        // Verifica se a string tem alguma letra minuscula
        if ( islower(STRING_ROMANA_[AUX]) ) {
            return -1;
        //  Verifica se a string tem algum digito
        } else if ( isdigit(STRING_ROMANA_[AUX]) ) {
            return -1;
        //  Verifica se o tomamanho da string é menor ou igual a 30
        } else if ( STRING_ROMANA_.length() > 30 ) {
            return -1;
        //  Verifica se o número possui só algarismos romanos
        } else if ( STRING_ROMANA_.length() < 2 ) {
            for (VAL = 0; VAL <= 7; VAL++) {
                if ( STRING_ROMANA_[AUX] == ROMAN_STRING_[VAL] ) {
                    return ARABIC_NUMBER_[VAL];
                }
            }
        //  Faz a conversão do numero romano para arabico
        } else {
            LETTER = STRING_ROMANA_[AUX];
            for ( CONT = 0; CONT <= 7; CONT++ ) {
                //  Verifica a qual numero romano o caracter é igual
                if ( LETTER == ROMAN_STRING_[CONT] ) {
                    //  Verifica se existe um numero menor
                    //  na frente e depois de um maior
                    if ( CONT >= 1 && STRING_ROMANA_.length() >= 2 ) {
                        if ( ((STRING_ROMANA_[AUX - 1] ==
                            STRING_ROMANA_[AUX + 1]) &&
                            (STRING_ROMANA_[AUX] != STRING_ROMANA_[AUX - 1] &&
                            STRING_ROMANA_[AUX] != STRING_ROMANA_[AUX + 1])) ) {
                                return -1;
                        }
                    }
                    //  Faz a soma do numero já convertido
                    SUM = SUM + ARABIC_NUMBER_[CONT];
                    // Verifica se há subtração no numero
                    if ( PREV < (ARABIC_NUMBER_[CONT]) ) {
                        //  Se sim faz a subtração no total
                        SUM = SUM - PREV * 2;
                        PREV = ARABIC_NUMBER_[CONT];
                    }
                }
            }
        }
    }
    // Verifica se o número é menor ou igual a 3000
    if (SUM > 3000) {
        return -1;
    // Retorna o numero convertido
    } else {
        return SUM;
    }
}
