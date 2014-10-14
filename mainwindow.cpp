#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->posisao=false;
    /** <ToDo> @wgmlima [ Verificar a possibilidade de atribuir a altura e largura do widgetJanela a variavel
     * altura e largura da janela ] */
}

MainWindow::~MainWindow()
{
    delete ui;
}/* ----- END MainWindow ----- */


void MainWindow::ClicBotaoEntrarSair(){
    if(posisao){
        ui->botaoEntrarSair->setText("Entrar");
        /** Muda o texto do botão "botaoEntrarSair" para "Entrar" */
        ui->botaoEntrarSair->hide();
        /** Esconde o botão até está fora do monumento de fora */
        posisao=false;
        ui->widgetJanela->SairMonumento();
        ui->botaoEntrarSair->show();
        /** Mostra o botão quando se localisa fora do monumento */

    }
    else{
        ui->botaoEntrarSair->setText("Sair");
        /** Muda o texto do botão "botaoEntrarSair" para "sair" */
        ui->botaoEntrarSair->hide();
        /** Esconde o botão até está dentro do monumento de fora */
        posisao=true;
        ui->widgetJanela->EntrarMonumento();
        ui->botaoEntrarSair->show();
        /** Mostra o botão quando se localisa dentro do monumento */
    }
}/* ----- END ClicBotaoEntrarSair ----- */
