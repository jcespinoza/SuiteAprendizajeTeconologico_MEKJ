#ifndef LETRALABEL_H
#define LETRALABEL_H
#include <QLabel>
#include <QDebug>
#include <QPropertyAnimation>

class LetraLabel : public QLabel
{
    Q_OBJECT
public:
    explicit LetraLabel(QWidget *parent = 0);
    QPoint posicionAnterior;

    void setPosicionAnterior(QPoint);
    QPoint getPosicionAnterior(){return posicionAnterior;}


protected:
    void mousePressEvent(QMouseEvent *);
signals:
    void animacionCompleta(LetraLabel*);
    void clicked(LetraLabel*);
public slots:
    void animarMover(QPoint);
    void terminoMover();
};
#endif // LETRALABEL_H
