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
 * fork.c (Modulo de reloj)             
 *
 * Ultima modificacion: 11.02.2018
 *
 * @Autores: Daniel Francis. 12-10863
 *          Javier Vivas. 12-11067
 */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <math.h>



int main(int argc, char * argv[])
{
    int limite = atoi(argv[0]);
    
    pid_t childPID;

    childPID = fork();

    if(childPID >= 0) 
    {
        if(childPID == 0)
        {   

            for (int i = 0; i < limite; ++i)
            {
                sleep(1.02749125170);

                struct timeval tv;
                gettimeofday(&tv,NULL);

                unsigned long long millis = (unsigned long long)(tv.tv_sec)*1000 + (unsigned long long)(tv.tv_usec)/1000;
                float msd = 2440587.5 + (millis/(8.64 * pow(10,7)));
                
                msd = (msd + (37+32.184)/86400 - 2451545);
                msd = (((msd-4.5)/1.02749125170) + 44796 - 0.00096);
                float mtc = msd-(int)msd;

                int horasm = (int)(mtc*24);
                int minutosm = (24*mtc)-(int)(24*mtc);
                minutosm = (int)(60*minutosm);
                int segundosm = 60*(60*((24*mtc)-(int)(24*mtc)));

                minutosm = minutosm;
                if (minutosm<0)
                {
                    minutosm = minutosm +60;
                    horasm--;
                }

                while(segundosm>=60)
                {
                    segundosm = segundosm - 60;
                    minutosm++;
                }

                printf("Hora marciana: %dh %dm %ds\n",horasm,minutosm,segundosm);

            }
        }
        else
        {
            for (int i = 0; i < limite; ++i)
            {
                sleep(1);

                struct tm * tm;
                time_t hora = time(NULL);

                tm = localtime(&hora);
                int segundos = tm->tm_sec;
                int minutos = tm->tm_min;
                int horas = tm->tm_hour;

                
                printf("Hora terrestre: %dh %dm %ds \n",horas,minutos,segundos);
            }
         
         }
    }
    else 
    {
        printf("\n Fork fallido\n");
        return 1;
    }

    return 0;
}