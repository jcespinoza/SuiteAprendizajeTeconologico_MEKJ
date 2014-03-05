#include "letralabel.h"

LetraLabel::LetraLabel(QWidget *parent) :
    QLabel(parent)
{
    QFont f(font());
    f.setPointSize(25);
    setFont(f);
}

void LetraLabel::setPosicionAnterior(QPoint p)
{
    posicionAnterior = p;
}

void LetraLabel::mousePressEvent(QMouseEvent *)
{
    emit clicked(this);
}

void LetraLabel::animarMover(QPoint dest){
    QPropertyAnimation *anim = new QPropertyAnimation(this,"pos");
    anim->setStartValue(pos());
    anim->setDuration(300);
    anim->setEndValue(dest);
    anim->start();
    connect(anim, SIGNAL(finished()), this, SLOT( terminoMover()));
}

void LetraLabel::terminoMover()
{
    if(pos() != posicionAnterior)
        emit animacionCompleta(this);
}
