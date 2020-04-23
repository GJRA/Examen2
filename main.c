// Author: Gabriela Rojano Arenas
// File: main.c
// Date: 22/04/20

// ------------------------------------------
// System and application specific headers
// ------------------------------------------
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "examen2.h"

int main(void) {
    int msj = menu();
    convertirBinario(msj,"Mensaje fue:");
    return 0;
}