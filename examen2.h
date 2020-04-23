// Functions that simulates a node with basic operators
// Author: Gabriela Rojano
// File: graph.h
// Date: 30/03/20

#ifndef EXAMEN2_H
#define EXAMEN2_H


// -----------------------------
// Public interface
// -----------------------------

/* Types declarations */

/* Function prototypes */
/**
 * Display the menu
 *
 * @return data (number)
 */
unsigned int menu();

/**
 * Generate an Error in the code
 *
 * @param codigo The correct code
 * @return Corrected code
 */
unsigned int generarError(unsigned int codigo);

/**
 * Fix the error with hamming codes
 *
 * @param datoC the code to fix it
 * @return Corrected code
 */
unsigned int corregir(unsigned int datoC);

/**
 * Display the binary number
 *
 * @param num the number to display
 * @param cadena label to display with the binary number
 */
void convertirBinario(int num, char *cadena);

/**
 * Create the Data with Code Hamming
 *  
 * @param num Data (decimal) to transmit
 * @return Data with Code Hamming
 */
int generarBitParidad(unsigned int num);

/**
 * Get the C's of Hamming 
 *
 * @param numC Code with Hamming 
 * @param num the C number (c0,c1,c3)
 * @param incremento increase in powers
 * @param espaciamiento jumps to calculate c
 * @return C bit
 */
int sacarP(unsigned int numC, int num, int incremento, int espaciamiento);
#endif