#ifndef ORACIONLABEL_H
#define ORACIONLABEL_H
#include "letralabel.h"
#include <QPropertyAnimation>

class OracionLabel : public QLabel
{
    Q_OBJECT
public:
    explicit OracionLabel(QWidget *parent = 0);
    QString oracionCorrecta;
    QString oracionAMostrar;
    QString ayudaTexto;
    QString url_Imagen;
    QString url_SonidoOracion;
    QString url_SonidoRegla;
    QList<QChar> letras;
    QChar letraCorrecta;
    QPoint posicion_Anterior;

    void setUrl_SonidoOracion(QString);
    QString getUrl_SonidoOracion(){return url_SonidoOracion;}

    void setUrl_SonidoRegla(QString);
    QString getUrl_SonidoRegla(){return url_SonidoRegla;}

    void setTextoAyuda(QString);
    QString getTextoAyuda(){return ayudaTexto;}

    void setOracionCorrecta(QString);
    QString getOracionCorrecta(){return oracionCorrecta;}

    void setLetraCorrecta(QChar c);
    QChar getLetraCorrecta(){return letraCorrecta;}

    void setOracionAMostrar(QString);
    QString getOracionAMostrar(){return oracionAMostrar;}

    void setUrl_Imagen(QString);
    QString getUrl_Imagen(){return url_Imagen;}

    void agregarLetra(QChar);
    QList<QChar> getLetras(){return letras;}

    void setPosicionAnterior(QPoint);
    QPoint getPosicionAnterior(){return posicion_Anterior;}



signals:
    void reportarAcierto(OracionLabel*);
    void reportarError(OracionLabel*);
public slots:
    void letraClicked(LetraLabel*);
    void verificarLetra(LetraLabel*);
    void seleccionCorrecta(LetraLabel* p);
    void seleccionIncorrecta(LetraLabel *p);
};
#endif // ORACIONLABEL_H
