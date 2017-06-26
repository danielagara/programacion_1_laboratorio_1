#include "fechas.h"

int main()
{
SYSTEMTIME  fecha;
int anos;
int mes;
int dia;
int contador=0;
int contador2=0;
int contador3=0;
int cuenta=0;
int i=0;

GetLocalTime (&fecha);
printf("ingrese  los años");
scanf("%d",&anos);
printf("ingrese  los meses");
scanf("%d",&mes);
printf("ingrese  los dias");
scanf("%d",&dia);

if(anos!=fecha.wYear)
{




contador=calculadias(anos,mes,dia);
anos++;
contador2=calculadiasxmes(anos,mes,dia);
anos=fecha.wYear;
contador3=calculafinal(anos,1,1);
cuenta=contador+contador2+contador3;

}
else
{
  cuenta=calculafinal2(anos,mes,dia);
}

printf("los dias vividos son %d",cuenta);
return 0;
}
