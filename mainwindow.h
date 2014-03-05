#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "oracionlabel.h"
#include "letralabel.h"
#include <QMainWindow>
#include <QTimer>
#include "time.h"
#include "operaciones.h"
#include <QSound>
#include <QMediaPlayer>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
     QList<Operaciones*> lista_de_operaciones;
     void Inicializar();
     QTimer *timer;
     QTimer *timerCheck;
     QTimer *timerInstrucciones;
     int l1,Operacion_esta,aciertos,fallos;
     OracionLabel *oracion;
     QList<LetraLabel*> letras;
     OracionLabel* arr[8];
public slots:
    void IniciarMatematicas();
    void ChangeImage();
    void wait();
    void reiniciarOracion();
    void oracionAcertada(OracionLabel*);
    void oracionErrada(OracionLabel*);
    void cargarOracion(OracionLabel *&);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_leRespuesta_returnPressed();

private:
    Ui::MainWindow *ui;
    void inicializarOraciones();
};

#endif // MAINWINDOW_H
