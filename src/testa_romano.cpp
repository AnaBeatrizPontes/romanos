//  Copyright [2021] <Ana Beatriz>
#define CATCH_CONFIG_MAIN

//  Inclui o arquivo de cabeçalho do projeto
#include "../include/romano.hpp"

//  Caso de teste 1
TEST_CASE("Se é um numero válido", "[convert_number]") {
    REQUIRE(convert_number("I") == 1);
    REQUIRE(convert_number("V") == 5);
    REQUIRE(convert_number("X") == 10);
    REQUIRE(convert_number("L") == 50);
    REQUIRE(convert_number("C") == 100);
    REQUIRE(convert_number("D") == 500);
    REQUIRE(convert_number("M") == 1000);
};

//  Caso de teste 2
TEST_CASE("Se é um número maior que 1 caractere e válido", "[convert_number]") {
    REQUIRE(convert_number("III") == 3);
    REQUIRE(convert_number("XXX") == 30);
    REQUIRE(convert_number("MMM") == 3000);
    REQUIRE(convert_number("VII") == 7);
    REQUIRE(convert_number("CCC") == 300);
};

//  Caso de teste 3
TEST_CASE("Se tem um número menor na frente do maior", "[convert_number]") {
    REQUIRE(convert_number("IV") == 4);
    REQUIRE(convert_number("IC") == 99);
    REQUIRE(convert_number("XM") == 990);
    REQUIRE(convert_number("XL") == 40);
    REQUIRE(convert_number("DM") == 500);
};

//  Caso de teste 4
TEST_CASE("Se as letras são válidas", "[convert_number]") {
    REQUIRE(convert_number("jjj") == -1);
    REQUIRE(convert_number("XXx") == -1);
    REQUIRE(convert_number("balinha") == -1);
    REQUIRE(convert_number("aKam") == -1);
    REQUIRE(convert_number("xxL") == -1);
};

//  Caso de teste 5
TEST_CASE("Se algum é numero", "[convert_number]") {
    REQUIRE(convert_number("X1X") == -1);
    REQUIRE(convert_number("123") == -1);
    REQUIRE(convert_number("C00") == -1);
    REQUIRE(convert_number("XX9") == -1);
    REQUIRE(convert_number("L98") == -1);
};

//  Caso de teste 6
TEST_CASE("Se é um número maior que 3000", "[convert_number]") {
    REQUIRE(convert_number("MMMM") == -1);
    REQUIRE(convert_number("MMMD") == -1);
    REQUIRE(convert_number("MMMMDCCC") == -1);
    REQUIRE(convert_number("MMMI") == -1);
    REQUIRE(convert_number("MMMMCMXCV") == -1);
};

//  Caso de teste 7
TEST_CASE("Um menor na frente e depois de um maior", "[convert_number]") {
    REQUIRE(convert_number("IXI") == -1);
    REQUIRE(convert_number("VXV") == -1);
    REQUIRE(convert_number("CMC") == -1);
    REQUIRE(convert_number("CDC") == -1);
    REQUIRE(convert_number("DMD") == -1);
};
