#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <GL/gl.h> /* Para o uso de tipos OpenGL */

#include <QMainWindow>
#include "Janela.h" /* Para chamar o slot "SairMonumento()" e "EntrarMonumento()" */

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    GLboolean posisao; /** valor = "false"-> Fora do monumento | valor = "true" -> Dentro do monumento */
    Ui::MainWindow *ui;

signals:

public slots:
    /** Evento do botao que movimenta a camera para dentro ou fora do monumento */
    void ClicBotaoEntrarSair();
};

#endif // MAINWINDOW_H
