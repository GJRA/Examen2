// Author: Gabriela Jaquelina Rojano Arenas
// File: examen2.c
// Date: 22/04/20

// ------------------------------------------
// System and aplication specific headers
// ------------------------------------------

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "examen2.h"
// -----------------------------
// Private elements
// -----------------------------

/* Private types */

unsigned int menu(){
    unsigned int num = 0;
    printf("Ingresar dato: \n");
    scanf("%u",&num);
    unsigned int codigo = (unsigned int)generarBitParidad(num);
    convertirBinario(num,"Dato");
    convertirBinario(codigo,"Codigo");
    num = generarError(codigo);
    return num;
}

unsigned int generarError(unsigned int codigo){
    unsigned int pos = 0;
    unsigned int numN = 0;
    printf("Generaremos un error\n");
    printf("Las posiciones son las siguientes [7][6][5][4][3][2][1]\n");
    printf("Ingresa la posición que quieres cambiar: \n");
    scanf("%u",&pos);
    // 1 2 3 4 5 6 7
    numN=pow(2,(pos-1));
    codigo = codigo ^ numN;
    convertirBinario(codigo,"Codigo con Error");
    return corregir(codigo);
}

unsigned int corregir(unsigned int datoC){
    unsigned int c0,c1,c3, err, correcto;
    c0 = (unsigned int)sacarP(datoC,0,2,0);
    c1 = (unsigned int)sacarP(datoC,1,1,2);
    c1 = c1<<1;
    c3 = (unsigned int)sacarP(datoC,3,1,0);
    c3 = c3 << 2;
    err = (c0 | c1 )| c3 ;
    convertirBinario(err,"Error en bit en binario" );
    printf("Error en el bit %d  \n",err);
    correcto = (unsigned int)pow(2,(err-1));
    correcto = datoC | correcto;
    return correcto;
}

void convertirBinario(int num, char *cadena){
    int a[10],i;    
    for(i=0;num>0;i++){    
        a[i]=num%2;    
        num=num/2;    
    }    
    printf("%s : ",cadena);    
    for(i=i-1;i>=0;i--)    
    {    
    printf("%d",a[i]);    
    }
    printf("\n"); 
}

int generarBitParidad(unsigned int num){
    unsigned int c0,c1,c3;
    unsigned int datoC = num>>1;
    datoC = datoC<<4;
    datoC = datoC | ((unsigned int)1&num)<<2;
    c0 = (unsigned int)sacarP(datoC,0,2,0);
    c1 = (unsigned int)sacarP(datoC,1,1,2);
    c1 = c1<<1;
    c3 = (unsigned int)sacarP(datoC,3,1,0);
    c3 = c3 << 3;
    datoC = datoC | c0;
    datoC = datoC | c1;
    datoC = datoC | c3;
    return (int)datoC;
}

int sacarP(unsigned int numC, int num, int incremento, int espaciamiento){
    //si c0 = 2⁰+2²+2⁴+2⁶ 
    //si c1 = 2¹+2²+2⁵+2⁶ 
    //si c3 = 2³+2⁴+2⁵+2⁶ 
    int veces = 0; 
    unsigned int c = 0;
    unsigned int mask[4] = {0,0,0,0};
    int i = num;
    while (veces < 4){
        if(veces==2){
            i=i+espaciamiento;
        }
        //printf("num %d",i);
        mask[veces] = (unsigned int)pow(2,i);
        mask[veces] = (numC&mask[veces]);
        if(mask[veces]!=0){
            mask[veces] = mask[veces]>>i;
        }
        //printf(" numMASK %u \n",mask[veces]);
        i= i+incremento;
        veces++;
    }
    c=mask[0]^mask[1]^mask[2]^mask[3];
    //printf("C%d %u \n",num,c);
    return (int)c;
}
