#include "oracionlabel.h"

OracionLabel::OracionLabel(QWidget *parent) :
    QLabel(parent)
{
    QFont f(font());
    f.setPointSize(18);
    setFont(f);
    setGeometry(x(), y(), 751, 100);
}

void OracionLabel::setTextoAyuda(QString t)
{
    ayudaTexto = t;
}

void OracionLabel::setOracionCorrecta(QString p){
    oracionCorrecta = p;
}

void OracionLabel::setLetraCorrecta(QChar c)
{
    letraCorrecta = c;
}

void OracionLabel::setOracionAMostrar(QString p){
    oracionAMostrar = p;
    setText(p);
    setScaledContents(true);
}

void OracionLabel::setUrl_Imagen(QString p){
    url_Imagen = p;
}

void OracionLabel::agregarLetra(QChar c){
    letras.append(c);
}

void OracionLabel::setPosicionAnterior(QPoint point){
    posicion_Anterior = point;
}

void OracionLabel::letraClicked(LetraLabel *p)
{
    p->animarMover(pos() + (QPoint(0, height()) /2) );
}

void OracionLabel::verificarLetra(LetraLabel *p)
{
    if(p->text().toLower().at(0) == letraCorrecta){
        seleccionCorrecta(p);
    }else{
        seleccionIncorrecta(p);
    }
}

void OracionLabel::seleccionCorrecta(LetraLabel* p)
{
    //codigo para sumar puntos aqui
    p->hide();
    setText(oracionCorrecta);
    emit reportarAcierto(this);
}

void OracionLabel::seleccionIncorrecta(LetraLabel *p)
{
    //codigo para restar puntos aqui
    p->animarMover(p->getPosicionAnterior());
    emit reportarError(this);
}

void OracionLabel::setUrl_SonidoOracion(QString p)
{
    url_SonidoOracion=p;
}

void OracionLabel::setUrl_SonidoRegla(QString p)
{
    url_SonidoRegla=p;
}
