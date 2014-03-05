#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
        this->setMaximumHeight(680);
        this->setMaximumWidth(800);
        this->setMinimumHeight(680);
        this->setMinimumWidth(800);
        ui->lbFondo->lower();
        srand(time(0));
        oracion = 0;
        inicializarOraciones();
        reiniciarOracion();
        Inicializar();
        connect(this->timer,SIGNAL(timeout()),this,SLOT(IniciarMatematicas()));
        connect(this->timerCheck,SIGNAL(timeout()),this,SLOT(ChangeImage()));
        connect(this->timerInstrucciones,SIGNAL(timeout()),this,SLOT(wait()));
        QSound::play("://sonidos/bienvenidoPaula.wav");

    }

    MainWindow::~MainWindow()
    {
        delete ui;
    }

    void MainWindow::Inicializar()
    {
        this->timer=new QTimer(this);
        this->timerCheck=new QTimer(this);
        this->timerInstrucciones=new QTimer(this);
        this->l1=-20;
        this->Operacion_esta=0;
        this->aciertos=0;
        this->fallos=0;
        Operaciones *op1=new Operaciones(this);
        Operaciones *op2=new Operaciones(this);
        Operaciones *op3=new Operaciones(this);
        Operaciones *op4=new Operaciones(this);
        Operaciones *op5=new Operaciones(this);
        Operaciones *op6=new Operaciones(this);
        Operaciones *op7=new Operaciones(this);
        Operaciones *op8=new Operaciones(this);
        Operaciones *op9=new Operaciones(this);
        Operaciones *op10=new Operaciones(this);
        Operaciones *op11=new Operaciones(this);
        Operaciones *op12=new Operaciones(this);
        Operaciones *op13=new Operaciones(this);
        Operaciones *op14=new Operaciones(this);
        Operaciones *op15=new Operaciones(this);

        op1->primer_numero=2;
        op1->segundo_numero=1;
        QPixmap pix("://Imagenes/1.png");
        op1->setGeometry(0,0,150,45);
        op1->setPixmap(pix);
        op1->operador='*';
        op1->move(rand()%650,-50);

        op2->primer_numero=2;
        op2->segundo_numero=3;
        pix.load("://Imagenes/2.png");
        op2->setGeometry(0,0,150,45);
        op2->setPixmap(pix);
        op2->operador='*';
        op2->move(rand()%650,-50);

        op3->primer_numero=5;
        op3->segundo_numero=3;
        pix.load("://Imagenes/3.png");
        op3->setGeometry(0,0,150,45);
        op3->setPixmap(pix);
        op3->operador='*';
        op3->move(rand()%650,-50);

        op4->primer_numero=5;
        op4->segundo_numero=4;
        pix.load("://Imagenes/4.png");
        op4->setGeometry(0,0,150,45);
        op4->setPixmap(pix);
        op4->operador='*';
        op4->move(rand()%650,-50);

        op5->primer_numero=3;
        op5->segundo_numero=4;
        pix.load("://Imagenes/5.png");
        op5->setGeometry(0,0,150,45);
        op5->setPixmap(pix);
        op5->operador='*';
        op5->move(rand()%650,-50);

        op6->primer_numero=9;
        op6->segundo_numero=4;
        pix.load("://Imagenes/6.png");
        op6->setGeometry(0,0,150,45);
        op6->setPixmap(pix);
        op6->operador='+';
        op6->move(rand()%650,-50);

        op7->primer_numero=3;
        op7->segundo_numero=8;
        pix.load("://Imagenes/7.png");
        op7->setGeometry(0,0,150,45);
        op7->setPixmap(pix);
        op7->operador='+';
        op7->move(rand()%650,-50);

        op8->primer_numero=7;
        op8->segundo_numero=8;
        pix.load("://Imagenes/8.png");
        op8->setGeometry(0,0,150,45);
        op8->setPixmap(pix);
        op8->operador='+';
        op8->move(rand()%650,-50);

        op9->primer_numero=5;
        op9->segundo_numero=8;
        pix.load("://Imagenes/9.png");
        op9->setGeometry(0,0,150,45);
        op9->setPixmap(pix);
        op9->operador='+';
        op9->move(rand()%650,-50);

        op10->primer_numero=7;
        op10->segundo_numero=9;
        pix.load("://Imagenes/10.png");
        op10->setGeometry(0,0,150,45);
        op10->setPixmap(pix);
        op10->operador='+';
        op10->move(rand()%650,-50);

        op11->primer_numero=8;
        op11->segundo_numero=5;
        pix.load("://Imagenes/11.png");
        op11->setGeometry(0,0,150,45);
        op11->setPixmap(pix);
        op11->operador='-';
        op11->move(rand()%650,-50);

        op12->primer_numero=9;
        op12->segundo_numero=2;
        pix.load("://Imagenes/12.png");
        op12->setGeometry(0,0,150,45);
        op12->setPixmap(pix);
        op12->operador='-';
        op12->move(rand()%650,-50);

        op13->primer_numero=5;
        op13->segundo_numero=4;
        pix.load("://Imagenes/13.png");
        op13->setGeometry(0,0,150,45);
        op13->setPixmap(pix);
        op13->operador='-';
        op13->move(rand()%650,-50);

        op14->primer_numero=8;
        op14->segundo_numero=3;
        pix.load("://Imagenes/14.png");
        op14->setGeometry(0,0,150,45);
        op14->setPixmap(pix);
        op14->operador='-';
        op14->move(rand()%650,-50);

        op15->primer_numero=7;
        op15->segundo_numero=1;
        pix.load("://Imagenes/15.png");
        op15->setGeometry(0,0,150,45);
        op15->setPixmap(pix);
        op15->operador='-';
        op15->move(rand()%650,-50);

        this->lista_de_operaciones.push_back(op6);
        this->lista_de_operaciones.push_back(op15);
        this->lista_de_operaciones.push_back(op3);
        this->lista_de_operaciones.push_back(op13);
        this->lista_de_operaciones.push_back(op4);
        this->lista_de_operaciones.push_back(op9);
        this->lista_de_operaciones.push_back(op7);
        this->lista_de_operaciones.push_back(op1);
        this->lista_de_operaciones.push_back(op11);
        this->lista_de_operaciones.push_back(op2);
        this->lista_de_operaciones.push_back(op8);
        this->lista_de_operaciones.push_back(op12);
        this->lista_de_operaciones.push_back(op10);
        this->lista_de_operaciones.push_back(op14);
        this->lista_de_operaciones.push_back(op5);

    }


    void MainWindow::IniciarMatematicas()
    {
        if(Operacion_esta<15)
        {
            if(l1<515)
            {
                lista_de_operaciones.at(Operacion_esta)->move(lista_de_operaciones.at(Operacion_esta)->x(),l1);
                l1++;
            }
            else
            {
                lista_de_operaciones.at(Operacion_esta)->move(lista_de_operaciones.at(Operacion_esta)->x(),-50);
                QPixmap *pix=new QPixmap();
                if(lista_de_operaciones.at(Operacion_esta)->retornar_valor_de_operacion()==ui->leRespuesta->text().toInt())
                {
                    pix->load("://Imagenes/check.png");
                    this->aciertos++;
                    QSound::play("://sonidos/Excelente.wav");
                    ui->lbAciertos->setText(QString::number(this->aciertos));
                }
                else
                {
                    pix->load("://Imagenes/error.png");
                    this->fallos++;
                    QSound::play("://sonidos/buen_intento.wav");
                    ui->lbFallos->setText(QString::number(this->fallos));
                }
                ui->lbCorrecto->setPixmap(*pix);
                this->timerCheck->start(1000);
                ui->leRespuesta->setText("");
                Operacion_esta++;
                l1=0;

            }
        }
        else
        {
            ui->stackedWidget->setCurrentIndex(0);
            ui->lbFondo->lower();
        }
    }

    void MainWindow::on_leRespuesta_returnPressed()
    {
        if(ui->leRespuesta->text()!="")
            l1=515;
    }

    void MainWindow::ChangeImage()
    {
        QPixmap pix;
        ui->lbCorrecto->setPixmap(pix);
        this->timerCheck->stop();
    }

void MainWindow::on_pushButton_clicked()
{

    ui->stackedWidget->setCurrentIndex(1);
    QSound::play("://sonidos/instrucciones_mate.wav");
    this->timerInstrucciones->start(7000);
    this->Operacion_esta=0;
    this->l1=0;
    ui->lbAciertos->setText("0");
    ui->lbFondo->lower();
    ui->lbFallos->setText("0");
    ui->leRespuesta->setText("");
    this->aciertos=0;
    this->fallos=0;

}

void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->stackedWidget->update();
    ui->stackedWidget->setCurrentWidget(ui->swEspanol);
}

void MainWindow::wait()
{
    this->timer->start(14);
    this->timerInstrucciones->stop();
}

void MainWindow::inicializarOraciones()
{
    arr[0] =  new OracionLabel(ui->swEspanol);
    OracionLabel* temp = arr[0];
    int h=3*geometry().height()/4;
    temp->setEnabled(false);
    temp->setVisible(false);
    temp->setUrl_SonidoOracion("://sonidos/bicolor.wav");
    temp->setUrl_SonidoRegla("://sonidos/recuerda_con_b.wav");
    temp->setUrl_Imagen("://Imagenes/bandera.jpg");
    temp->setOracionCorrecta("La bandera de Honduras es bicolor; tiene dos colores.");
    temp->setOracionAMostrar("La bandera de Honduras es _icolor; tiene dos colores.");
    temp->setTextoAyuda("Recuerda: se escriben con be las palabras que llevan los prefijos bi, bis y biz.");
    temp->setLetraCorrecta(QChar('b'));
    temp->agregarLetra(QChar('b'));
    temp->agregarLetra(QChar('v'));
    temp->setPosicionAnterior(QPoint(20,h) );
    temp->move(temp->getPosicionAnterior());

    ////////////////////////////////////////////////
    arr[1] =  new OracionLabel(ui->swEspanol);
    temp = arr[1];
    temp->setEnabled(false);
    temp->setVisible(false);
    temp->setUrl_SonidoOracion("://sonidos/presidente.wav");
    temp->setUrl_SonidoRegla("://sonidos/recuerda_con_v.wav");
    temp->setUrl_Imagen("://Imagenes/presi.jpg");
    temp->setOracionCorrecta("El presidente del patronato se reunió con el vicealcalde.");
    temp->setOracionAMostrar("El presidente del patronato se reunió con el _icealcalde.");
    temp->setTextoAyuda("Recuerda que se escriben con V las palabras que lleven los prefijos vice, villa y veri.");
    temp->setLetraCorrecta(QChar('v'));
    temp->agregarLetra(QChar('b'));
    temp->agregarLetra(QChar('v'));
    temp->setPosicionAnterior(QPoint(20, h));
    temp->move(temp->getPosicionAnterior());

    ////////////////////////////////////////////////
    arr[2] =  new OracionLabel(ui->swEspanol);
    temp = arr[2];
    temp->setEnabled(false);
    temp->setVisible(false);
    temp->setUrl_SonidoOracion("://sonidos/La_fiesta.wav");
    temp->setUrl_SonidoRegla("://sonidos/recuerda_con_s.wav");
    temp->setUrl_Imagen("://Imagenes/fiesta.jpg");
    temp->setOracionCorrecta("La fiesta de cumpleaños de Javier estuvo animadísima!");
    temp->setOracionAMostrar("La fiesta de cumpleaños de Javier estuvo animadí_ima!");
    temp->setTextoAyuda("No olvides que se escriben con S las palabras que denotan aumentativos con los sufijos ísimo e ísima.");
    temp->setLetraCorrecta(QChar('s'));
    temp->agregarLetra(QChar('c'));
    temp->agregarLetra(QChar('s'));
    temp->agregarLetra(QChar('z'));
    temp->setPosicionAnterior(QPoint(20, h));
    temp->move(temp->getPosicionAnterior());

    ////////////////////////////////////////////////
    arr[3] =  new OracionLabel(ui->swEspanol);
    temp = arr[3];
    temp->setEnabled(false);
    temp->setVisible(false);
    temp->setUrl_SonidoOracion("://sonidos/primo_Ricardo.wav");
    temp->setUrl_SonidoRegla("://sonidos/recuerda_con_c.wav");
    temp->setUrl_Imagen("://Imagenes/pez.jpg");
    temp->setOracionCorrecta("Mi primo Ricardo tiene un pececito dorado como mascota.");
    temp->setOracionAMostrar("Mi primo Ricardo tiene un pece_ito dorado como mascota.");
    temp->setTextoAyuda("Ten en mente que se escriben con C las palabras que denotan diminutivos que teminan en cito, cico y cillo.");
    temp->setLetraCorrecta(QChar('c'));
    temp->agregarLetra(QChar('c'));
    temp->agregarLetra(QChar('s'));
    temp->agregarLetra(QChar('z'));
    temp->setPosicionAnterior(QPoint(20, h));
    temp->move(temp->getPosicionAnterior());

    ////////////////////////////////////////////////
    arr[4] =  new OracionLabel(ui->swEspanol);
    temp = arr[4];
    temp->setEnabled(false);
    temp->setVisible(false);
    temp->setUrl_SonidoOracion("://sonidos/maribel.wav");
    //temp->setUrl_SonidoRegla("://sonidos/recuerda_con_b.wav");
    temp->setUrl_Imagen("://Imagenes/soccer.png");
    temp->setOracionCorrecta("Maribel tuvo una muy buena actuación en el partido de ayer.");
    temp->setOracionAMostrar("Maribel tuvo una muy buena actua_ión en el partido de ayer.");
    temp->setTextoAyuda("Siempre recuerda que se escribe con C la partícula ción si proviene de verbos que terminan en: ectar, eptuar, ducir, tuar, jar y tar");
    temp->setLetraCorrecta(QChar('c'));
    temp->agregarLetra(QChar('c'));
    temp->agregarLetra(QChar('s'));
    temp->agregarLetra(QChar('z'));
    temp->setPosicionAnterior(QPoint(20,h));
    temp->move(temp->getPosicionAnterior());

    ////////////////////////////////////////////////
    arr[5] =  new OracionLabel(ui->swEspanol);
    temp = arr[5];
    temp->setEnabled(false);
    temp->setVisible(false);
    temp->setUrl_SonidoOracion("://sonidos/muy_importante.wav");
    temp->setUrl_SonidoRegla("://sonidos/antes_de_y_p.wav");
    temp->setUrl_Imagen("://Imagenes/respeto.jpg");
    temp->setOracionCorrecta("Es muy importante el respeto los demás para una buena convivencia.");
    temp->setOracionAMostrar("Es muy i_portante el respeto los demás para una buena convivencia.");
    temp->setTextoAyuda("Recuerda que antes de B y P, se escribe M.");
    temp->setLetraCorrecta(QChar('m'));
    temp->agregarLetra(QChar('n'));
    temp->agregarLetra(QChar('m'));
    temp->setPosicionAnterior(QPoint(20, h));
    temp->move(temp->getPosicionAnterior());

    ////////////////////////////////////////////////
    arr[6] =  new OracionLabel(ui->swEspanol);
    temp = arr[6];
    temp->setEnabled(false);
    temp->setVisible(false);
    temp->setUrl_SonidoOracion("://sonidos/Nuestro_maestro.wav");
    temp->setUrl_SonidoRegla("://sonidos/reconda_con_j.wav");
    temp->setUrl_Imagen("://Imagenes/maestro.jpg");
    temp->setOracionCorrecta("Nuestro maestro nos explica con muchos ejemplos.");
    temp->setOracionAMostrar("Nuestro maestro nos explica con muchos e_emplos.");
    temp->setTextoAyuda("No olvides que se escriben con J los verbos con las las sílabas: eje y jear.");
    temp->setLetraCorrecta(QChar('j'));
    temp->agregarLetra(QChar('j'));
    temp->agregarLetra(QChar('g'));
    temp->setPosicionAnterior(QPoint(20, h));
    temp->move(temp->getPosicionAnterior());

    ////////////////////////////////////////////////
    arr[7] =  new OracionLabel(ui->swEspanol);
    temp = arr[7];
    temp->setEnabled(false);
    temp->setVisible(false);
      temp->setUrl_SonidoOracion("://sonidos/primo_wilfredo.wav");
    temp->setUrl_SonidoRegla("://sonidos/recuerda_con_doble_l.wav");
    temp->setUrl_Imagen("://Imagenes/kid.jpg");
    temp->setOracionCorrecta("Mi primito Wilfredo es un chiquillo muy bien portado.");
    temp->setOracionAMostrar("Mi primito Wilfredo es un chiqui_o muy bien portado.");
    temp->setTextoAyuda("Se escriben con doble l los diminutivos que terminan en illo e illa.");
    temp->setLetraCorrecta(QChar('l'));
    temp->agregarLetra(QChar('y'));
    temp->agregarLetra(QChar('l'));
    temp->setPosicionAnterior(QPoint(20, h));
    temp->move(temp->getPosicionAnterior());

}

void MainWindow::reiniciarOracion()
{
    int index = rand() % 7;
    if(oracion != 0){
        oracion->setText(oracion->getOracionAMostrar());
        oracion->setVisible(false);
        oracion->setEnabled(false);
    }
    for(int i = 0; i < letras.count(); i++){
        letras.at(i)->setVisible(false);
        letras.at(i)->setEnabled(false);
    }
    letras.clear();
    ui->imgLabel->setPixmap(QPixmap("://Imagenes/transparent.png"));
    ui->ayudaLabel->setText("");

    OracionLabel *temp = arr[index];

    for(int i = 0; i < temp->getLetras().count(); i++){
        LetraLabel *elem = new LetraLabel(ui->swEspanol);
        elem->setText(  temp->getLetras().at(i).toUpper());
        elem->setEnabled(false);
        elem->setVisible(false);
        letras.append(elem);
        QPoint p;
        p.setX(40 + i*60);
        p.setY(3*geometry().height()/4 + 100);
        elem->setPosicionAnterior(p);
        elem->move(p);
        connect(elem, SIGNAL(clicked(LetraLabel*)), temp, SLOT(letraClicked(LetraLabel*)));
        connect(elem, SIGNAL(animacionCompleta(LetraLabel*)),temp, SLOT(verificarLetra(LetraLabel*)));
        connect(temp, SIGNAL(reportarAcierto(OracionLabel*)), this, SLOT(oracionAcertada(OracionLabel*)));
        connect(temp, SIGNAL(reportarError(OracionLabel*)), this, SLOT(oracionErrada(OracionLabel*)));
    }
    cargarOracion(temp);
}

void MainWindow::oracionAcertada(OracionLabel *oracion)
{
    qDebug()<<oracion->getUrl_SonidoRegla();
    //QSound::play(oracion->getUrl_SonidoRegla());
    QTimer *timer = new QTimer(this);
    timer->setSingleShot(true);
    connect(timer, SIGNAL(timeout()), this,SLOT(reiniciarOracion()));
    timer->start(6000);
    //QTimer::singleShot(2000,this,SLOT(reiniciarOracion()) );
    ui->ayudaLabel->setText(oracion->getTextoAyuda());
}

void MainWindow::oracionErrada(OracionLabel *oracion)
{
    //codigo para restar puntos aqui
}

void MainWindow::cargarOracion(OracionLabel *&ora){
    if(oracion != 0){
        oracion->setVisible(false);
        oracion->setEnabled(false);
        for(int i = 0; i < letras.count(); i++){
            letras.at(i)->setVisible(false);
            letras.at(i)->setEnabled(false);
        }
    }
    oracion = ora;
    oracion->setVisible(true);
    oracion->setEnabled(true);
    for(int i = 0; i < letras.count(); i++){
        letras.at(i)->setVisible(true);
        letras.at(i)->setEnabled(true);
    }
    ui->imgLabel->setPixmap(QPixmap(oracion->getUrl_Imagen()));
    //QSound::play(oracion->getUrl_SonidoOracion());
}
