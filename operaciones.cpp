#include "operaciones.h"

Operaciones::Operaciones(QWidget *parent=0):QLabel(parent)
{

}

 int Operaciones::retornar_valor_de_operacion ()const
{

        switch(operador)
        {
        case '+':

            return (primer_numero)+(segundo_numero);
        case '-':

            return (primer_numero)-(segundo_numero);
        case '*':

            return (primer_numero)*(segundo_numero);
        }


    return -1;
}

void Operaciones::agregar_operacion()
{
   primer_numero=1+rand()%9;
   segundo_numero=1+rand()%9;

   int asignar_operador=1+rand()%3;

    switch(asignar_operador)
    {

    //suma
        case 1:
       operador='+';
        return;

        //resta
    case 2:
         operador='-';
        if(this->primer_numero<this->segundo_numero)
        {
          int temp=this->primer_numero;
          this->primer_numero=this->segundo_numero;
          this->segundo_numero=temp;
        }

        return;

        //multiplicacion
    case 3:
        operador='*';
        return;
    }

}
