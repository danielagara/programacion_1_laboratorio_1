#include "fechas.h"
//devuelve 1 si es bisiesto
int calucalabisi(int ano)
{

    if(ano%4==0||ano%100!=0)
    {
        if(ano%400==0)
        {
            return 1;

        }


    }

return 0;
}
int calculadias(int ano,int mes,int dias)
{

int i;
int contador=0;
int bis;

int dias1=0;

bis=calucalabisi(ano);



        if(mes==2||mes==4||mes==6||mes==9||mes==11)
        {
                if(bis==1&&mes==2)
                {
                    dias1=29-dias;
                }
                else if(bis==0&&mes==2)
                    {
                        dias1=28-dias;

                    }
                    else
                    {
                        dias1=30-dias;
                    }

        }
        else
        {
             dias1=31-dias;
        }

mes++;

//dias que pasaron hast a el siguiente mes



    for(i=mes;i<13;i++)
        {

            if(mes==2||mes==4||mes==6||mes==9||mes==11)
            {
                if(bis==1&&mes==2)
                {
                    contador=contador+29;
                }
                  else if(bis==0&&mes==2)
                    {
                      contador=contador+28;

                    }
                    else
                    {
                       contador=contador+30;
                    }


            }
            else
            {
                contador=contador+31;
            }


        }



return (contador+dias1);


}


int calculadiasxmes(int ano,int mes,int dia)
{
int bis;
int contador=0;
SYSTEMTIME  fecha;
int i;


GetLocalTime (&fecha);





for(i=ano;i<fecha.wYear;i++)
{

    if (bis=calucalabisi(ano))
    {

    contador=contador+366;

    }
    else
    {
    contador=contador+365;
    }



}


return contador;

}

int calculafinal(int anos,int mes,int dia)
{
SYSTEMTIME  fecha;
int bis;
int dias2;
GetLocalTime (&fecha);
int contador=0;
int i;

bis=calucalabisi(anos);



for(i=mes;i<fecha.wMonth;i++)
       {

            if(mes==2||mes==4||mes==6||mes==9||mes==11)
            {
                if(bis==1&&mes==2)
                {
                    contador=contador+29;
                }
                  else if(bis==0&&mes==2)
                    {
                      contador=contador+28;

                    }
                    else
                    {
                       contador=contador+30;
                    }


            }
            else
            {
                contador=contador+31;
            }


        }

    contador=contador+(fecha.wDay);


return contador;
}

int calculafinal2(int anos,int mes,int dia)
{
SYSTEMTIME  fecha;
int bis;
int dias2;
GetLocalTime (&fecha);
int contador=0;
int i;

bis=calucalabisi(anos);



for(i=1;i<mes;i++)
       {

            if(i==2||i==4||i==6||i==9||i==11)
            {
                if(bis==1&&i==2)
                {
                    contador=contador+29;
                }
                  else if(bis==0&&i==2)
                    {
                      contador=contador+28;

                    }
                    else
                    {
                       contador=contador+30;
                    }


            }
            else
            {
                contador=contador+31;
            }


        }

    contador=contador+dia;


return contador;
}

