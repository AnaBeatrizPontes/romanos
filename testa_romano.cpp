#define CATCH_CONFIG_MAIN

#include "../include/romano.hpp"

// TEST_CASE("Se é um numero válido", "[convert_number]") {
//     REQUIRE(convert_number("I") == 1);
//     REQUIRE(convert_number("V") == 5);
//     REQUIRE(convert_number("X") == 10);
//     REQUIRE(convert_number("L") == 50);
//     REQUIRE(convert_number("C") == 100);
//     REQUIRE(convert_number("D") == 500);
//     REQUIRE(convert_number("M") == 1000);
// };

TEST_CASE("Se é um numero maior que 1 e válido", "[convert_number]") {
    REQUIRE(convert_number("III") == 3);
    REQUIRE(convert_number("XXX") == 30);
    REQUIRE(convert_number("MMM") == 3000);
    REQUIRE(convert_number("VII") == 7);
    REQUIRE(convert_number("CCC") == 300);
};

TEST_CASE("Se tem um número menor na frente do maior", "[convert_number]") {
    REQUIRE(convert_number("IV") == 4);
    REQUIRE(convert_number("IX") == 9);
};

// TEST_CASE("Se é letra minuscula", "[convert_number]") {
//     REQUIRE(convert_number("jjj") == -1);
//     REQUIRE(convert_number("aaaaaa") == -1);
//     REQUIRE(convert_number("balinha") == -1);
//     REQUIRE(convert_number("aKam") == -1);
//     REQUIRE(convert_number("xxL") == -1);
// };

// TEST_CASE("Se todas as letras estão dentro da sintaxe romana", "[convert_number]") {
//     REQUIRE(convert_number("jjj") == -1);

// };

// TEST_CASE("Se tudo é letra", "[convert_number]") {
//     REQUIRE(convert_number("jjj") == -1);

// };


