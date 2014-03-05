#ifndef OPERACIONES_H
#define OPERACIONES_H
#include <QLabel>
#include <QObject>
#include <algorithm>
#include <ctime>
class Operaciones: public QLabel
{
    Q_OBJECT
public:

    explicit Operaciones(QWidget *parent);
    int primer_numero;
       int segundo_numero;
       char operador;
        int Score;
      int Total_de_vida;
      QString comentario;
       int retornar_valor_de_operacion() const;
       void agregar_operacion();
};

#endif // OPERACIONES_H
