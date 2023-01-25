#include <stdio.h>


void fun(int& g)


int main(){

    int x = 400;

    fun(x);

    // point one

    return 0;

}

void fun(int& g) {

     g += 2;

}