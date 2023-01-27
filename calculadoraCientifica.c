
#include <stdio.h>

struct calculadora
{
    int (*sum)(int, int);
    int (*sub)(int, int);
    int (*mult)(int, int);
    int (*div)(int, int);
};

int somar(int a, int b){ return a+b;}
int subtrair(int a, int b){ return a-b;}
int multiplicar(int a, int b){ return a*b;}
int dividir(int a, int b){ return a/b;}

struct calculadora* calculadoraCreator(){
    struct calculadora *newCalculadora;
    newCalculadora->sum = somar;
    newCalculadora->sub = subtrair;
    newCalculadora->mult = multiplicar;
    newCalculadora->div = dividir;
    return newCalculadora;
}


struct calculadoraCientifica
{
    struct calculadora* calculadora;
    int (*sum)(int, int);
    int (*sub)(int, int);
    int (*mult)(int, int);
    int (*div)(int, int);
    int (*pow)(int, int);
    int (*mod)(int, int);

};

int potencia(int a, int b){ 
    int pow = a;
    while(--b){pow *= a;}
    return pow;
    }
int modulo(int a, int b){ return a%b;}


struct calculadoraCientifica calculadoraCientificaCreator(){
    struct calculadoraCientifica newCalculadoraCientifica;
    newCalculadoraCientifica.calculadora = calculadoraCreator();
    newCalculadoraCientifica.sum = newCalculadoraCientifica.calculadora->sum;
    newCalculadoraCientifica.sub = newCalculadoraCientifica.calculadora->sub;
    newCalculadoraCientifica.mult = newCalculadoraCientifica.calculadora->mult;
    newCalculadoraCientifica.div = newCalculadoraCientifica.calculadora->div;
    newCalculadoraCientifica.pow = potencia;
    newCalculadoraCientifica.mod = modulo;
    return newCalculadoraCientifica;
}

int main(){
    struct calculadoraCientifica t1 = calculadoraCientificaCreator();
    printf("sum: %d\n", t1.sum(3, 4));
    printf("sub: %d\n", t1.sub(3, 4));
    printf("mult: %d\n", t1.mult(3, 4));
    printf("div: %d\n", t1.div(3, 4));
    printf("pow: %d\n", t1.pow(3, 4));
    printf("mod: %d\n", t1.mod(3, 4));
    return(0);
}
