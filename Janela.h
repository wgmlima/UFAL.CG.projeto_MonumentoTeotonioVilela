#ifndef JANELA_H
#define JANELA_H

#include <QGLWidget>
#include <GL/glu.h>
#include <vector>
#include <QDebug> /** Para de bug (exibir no terminal) */
#include <QVector> /** Para o uso de Vetores do QT e seus metodos implementados */
#include <cmath> /** Para os comandos "cos" e "sin" */
#include <QKeyEvent> // Thiago
#include <GL/glu.h> // Thiago
#include <qmath.h> // Thiago
#include <QDebug> // Thiago
#include <SOIL/SOIL.h> /** Biblioteca para trabalhar com Textura */

#include "coordenadaxyz.h"
#include "superficies.h"

using namespace std;

class Janela : public QGLWidget
{
    Q_OBJECT

private:

    /* ------------------------------ VARIAVEIS PRIVADAS ------------------------------ */
    /** <ToDo> @wgmlima [definir constantes] */
    GLboolean posisao; /** valor = "false"-> Fora do monumento | valor = "true" -> Dentro do monumento */
    /*const*/ GLint cameraAltura, /** <ToDo> @wgmlima [ Verificar quais serão constantes ou estaticas ] */
        raioDentro,
        raioFora,
        janelaLargura,
        janelaAltura;

    int texture[18]; /* <ToDo> [Mudar p lib "QVector" ou "vector" ] */
    /** vetor de texturas
        0 - Nenhuma (NULL)
        1 - Grama
        2 - Marmore Marrom
        3 - Marmore branco
        4 - Marmore branco bruto
        5 - Água
        6 - Vitral
        7 - Placa frontal
        8 - Pastilhas de vidro
        9 a 14 - Fotos
        15 - Marmore preto
        16 - Inox
        17 - Cobre
     */

    GLint cameraRotate; // Thiago
    GLfloat angulo, raio;

    //Indica a posição (posicao_luz0) e as componentes de luz para reflexão difusa e especular (cor_luz0), e a componente de luz para reflexão ambiente (cor_luz0_amb).
    GLfloat posicao_Sol[4]    = { 3230/2, 10000, -3650/2, 1.0};//posição da luz
    GLfloat cor_Sol[4]        = { 1.0, 1.0, 1.0, 1.0};//cor da luz, branca
    GLfloat cor_sol_amb[4]    = { 1.0, 1.0, 1.0, 1.0};//cor da luz ambiente

//    //luz do tipo spot
//    GLfloat posicao_luz1[4]    = { 0.0, 10.0, 0.0, 1.0};
//    GLfloat cor_luz1[4]        = { 0.0, 0.0, 1.0, 1.0};//cor da luz
//    GLfloat direcao_luz1[4]    = { 0.0, -10.0, 0.0, 1.0};//vetor direção da luz
//    GLint   spot_luz1         = 60;//angulo em graus de abertura do spot

    CoordenadaXYZ centroEstrutura; /* <ToDo> @wgmlima [definir coordenada do centro da estrutura] */
    CoordenadaXYZ cameraFoco,cameraPosicao;
    Superficies porta,placaFrontal;
    QVector <Superficies> estrutura;


    /* ------------------------------- METODOS PRIVADOS ------------------------------- */


    void loadTexture();
    /**  Ler o arquivo imagem idependente do formato como se fosse uma textura OpenGL */

    void inserirDados();
    /** Insere os dados das estruturas do monumento */

    void desenhaCilindro(GLfloat raioBase, GLfloat raioTopo, GLfloat altura);

    void desenhaDisco(GLfloat raioInterno, GLfloat raioExterno);

    void desenharPoligono(Superficies& objeto);
    /** Desenhar poligonos */
    void desenharPorta();
    void desenhaPlaca(GLint texturaID,GLfloat largura, GLfloat altura);
    void desenhaEstatua(GLint texturaID, GLfloat largura, GLfloat altura);

    void moverCamera();
    /**  */

    void giraCamera(GLfloat angulo);
    /** Gira a a camera em 360° dentro do monumento movimentando o ponto focal da mesma na equação da
     *  circuferencia com o centro a posição da camera ou Movimenta a camera ao redor do monumento
     *  movimentando o posição da mesma na equação da circuferencia com centro no monumento
     */

    void portaAbrir();
    /** Metodos para fazer animação da porta */

    void portaFechar();

    void prepararEntra();
    /** Pocisiona a camera p entrar no monumento */




public:
    /* ------------------------------- METODOS PUBLICOS ------------------------------- */
    explicit Janela(QWidget *parent = 0);
    void keyPressEvent(QKeyEvent *event); //thiago

    //void setDimensoesJanela(GLint altura, GLint Largura);
    /** Atribue a ALTURA e a LARGURA da janela de Dezenho */
    /** <ToDo> @wgmlima [Ver com thiago o com atribuir os valores da widgetJanela por ponteiro ] */

protected:

    /* ------------------------------ METODOS PROTEGIDOS ------------------------------ */

    void perspectiveGL( GLdouble fovY, GLdouble aspect, GLdouble zNear, GLdouble zFar );
    /** perspectiveGL: (http://nehe.gamedev.net/article/replacement_for_gluperspective/21002/
     *
     *  Replaces gluPerspective. Sets the frustum to perspective mode.
     *  fovY     - Field of vision in degrees in the y direction
     *  aspect   - Aspect ratio of the viewport
     *  zNear    - The near clipping distance
     *  zFar     - The far clipping distance
     */

    void initializeGL();
    /** Inicializa o WidgetJanela */

    void resizeGL(GLint w, GLint h);    /* @wgmlima <ToDo> [ Implementar] */
    /** Renderiza a tela e objetos quando for redimensionada */

    void paintGL();
    /** Imprime na WidgetJanela */

signals:

    public slots:

        void EntrarMonumento();
        /** Evento do botao que movimenta a camera para dentro do monumento */

        void SairMonumento();
        /** Evento do botao que movimenta a camera para fora do monumento */

};

#endif // JANELA_H
