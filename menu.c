/* 
 * Universidad Simon Bolivar
 * Departamento de Computación y Tecnologı́a de la Información
 * Sistemas de Operacion I - CI3825
 * Trimestre Enero-Marzo 2018
 *
 * Laboratorio. Semana 4.
 * 
 * Reloj de hora marciana: Este programa permite al usuario saber
 *                         la hora coordinada de Marte (MTC)
 *                         donde 1s MTC = 1.02749125170s UTC.
 * 
 * menu.c (Modulo de menu)             
 *
 * @Ultima_modificacion: 11.02.2018
 *
 * @Autores: Daniel Francis. 12-10863
 *          Javier Vivas. 12-11067
 */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/wait.h>


int main()
{
    printf("Este programa imprime la hora marciana \ny la terrestre\n");
    printf("Introduzca cuantas impresiones quiere:\n");
    
    const char * cmd = "./fork";
    char limite[10] = "0";
    scanf("%s",limite);
    char * argv[2];
    argv[0] = limite;
    argv[1] = NULL;

    execvp(cmd,argv);
    wait(0);
    exit(1); //Llegar hasta aqui equivale a error...

    return 0;
}