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

struct calculadora calculadoraCreator(){
    struct calculadora newCalculadora;
    newCalculadora.sum = somar;
    newCalculadora.sub = subtrair;
    newCalculadora.mult = multiplicar;
    newCalculadora.div = dividir;
    return newCalculadora;
}

int main(){
    struct calculadora t1 = calculadoraCreator();
    printf("sum: %d\n", t1.sum(3, 4));
    printf("sub: %d\n", t1.sub(3, 4));
    printf("mult: %d\n", t1.mult(3, 4));
    printf("div: %d\n", t1.div(3, 4));
    return(0);
}
