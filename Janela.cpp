#include "Janela.h"


using namespace std;

/* @wgmlima - definição de cores temporária até concluir a programação */
#define BRANCA          1.0, 1.0, 1.0, 1.0
#define AZUL            0.53, 0.81, 0.92, 0.0       //azul céu
#define VERMELHO        0.55, 0.0, 0.0, 1.0         //vermelho escuro
#define VERDE           0.13, 0.55, 0.13, 1.0       //verde floresta
#define AMARELO         1.0, 1.0, 0.0, 1.0
#define CYAN            0.0, 1.0, 1.0, 1.0
#define LARANJA         1.0, 0.65, 0.0, 1.0
#define ROSA            1.0, 0.08, 0.58, 1.0
#define CINZA           0.7, 0.7, 0.7, 1.0
#define CINZA_CLARO     0.83, 0.83, 0.83, 1.0
#define GRAMA           0.49,0.99,0.0, 1.0          //verde grama
#define MARROM          0.59,  0.29,  0.0, 1.0
#define CYANCLARO       0.0, 1.0, 1.0, 0.25
#define CREME           1, 0.99 ,0.82, 1
#define BRANCO_NAVAJO   1, 0.87 ,0.68, 1

Janela::Janela(QWidget *parent) :
    QGLWidget(parent) {

    /** <ToDo> @wgmlima - [selecionar a posição inicial da camera e foco] */
    cameraFoco.setCoordenadas(0,0,0);
    cameraPosicao.setCoordenadas(0,800,0);
    posisao=false;
    janelaLargura=1175;
    janelaAltura=686;
    angulo = 45.0;
    raio = 4000.0;
    centroEstrutura.setCoordenadas(3230/2, 200, -3650/2);

    cameraRotate = 0;// ThiagoDE

    inserirDados();

    setFocusPolicy(Qt::StrongFocus); // Thiago: Eventos do Teclado

}/* ----- END Janela ----- */

void Janela::perspectiveGL( GLdouble fovY, GLdouble aspect, GLdouble zNear, GLdouble zFar ){
    const GLdouble pi = 3.1415926535897932384626433832795;
    GLdouble fW, fH;
    fH = tan( fovY / 360 * pi ) * zNear;
    fW = fH * aspect;
    glFrustum( -fW, fW, -fH, fH, zNear, zFar );
}/* ----- END perspectiveGL ----- */

void Janela::loadTexture()
{
    /** Define como texture [x] a textura indicada entre "(" ")" */
    texture[1] = SOIL_load_OGL_texture /* Grama */
    (
        //"/home/lucas/Documentos/6º periodo/computação gráfica/Trabalho Monumento/ V1.6 - 2013.12.05/MonumentoTeotonioVilela/grama.jpg",
        "/home/wgmlima/Documentos/UFAL/cg/Trabalho 09 - Projeto Monumento Teotonio/Recente/MonumentoTeotonioVilela/Texturas/grama.jpg",
        /** Lê o diretorio da textura*/
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_POWER_OF_TWO
    );

    texture[2] = SOIL_load_OGL_texture /* Marmore marrom */
    (
        //"/home/lucas/Documentos/6º periodo/computação gráfica/Trabalho Monumento/ V1.6 - 2013.12.05/MonumentoTeotonioVilela/MarmoreMarromRetangulo.jpeg",
        "/home/wgmlima/Documentos/UFAL/cg/Trabalho 09 - Projeto Monumento Teotonio/Recente/MonumentoTeotonioVilela/Texturas/MarmoreMarrom.jpg",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_POWER_OF_TWO
    );

    texture[3] = SOIL_load_OGL_texture /* Marmore branco */
    (
        //"/home/lucas/Documentos/6º periodo/computação gráfica/Trabalho Monumento/ V1.6 - 2013.12.05/MonumentoTeotonioVilela/MarmoreBranco.jpeg.jpeg",
        "/home/wgmlima/Documentos/UFAL/cg/Trabalho 09 - Projeto Monumento Teotonio/Recente/MonumentoTeotonioVilela/Texturas/MarmoreBranco.jpg",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_POWER_OF_TWO
    );

    texture[4] = SOIL_load_OGL_texture /* Marmore Branco bruto */
    (
        //"/home/lucas/Documentos/6º periodo/computação gráfica/Trabalho Monumento/ V1.6 - 2013.12.05/MonumentoTeotonioVilela/Marmore Branco bruto maior.jpeg",
        "/home/wgmlima/Documentos/UFAL/cg/Trabalho 09 - Projeto Monumento Teotonio/Recente/MonumentoTeotonioVilela/Texturas/MarmoreBrancoBrutoMaior.jpg",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_POWER_OF_TWO
    );

    texture[5] = SOIL_load_OGL_texture /* Água */
    (
        //"/home/lucas/Documentos/6º periodo/computação gráfica/Trabalho Monumento/ V1.6 - 2013.12.05/MonumentoTeotonioVilela/agua.jpg",
        "/home/wgmlima/Documentos/UFAL/cg/Trabalho 09 - Projeto Monumento Teotonio/Recente/MonumentoTeotonioVilela/Texturas/agua.jpg",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_POWER_OF_TWO
    );

    texture[6] = SOIL_load_OGL_texture /* Vitral */
    (
        //"/home/lucas/Documentos/6º periodo/computação gráfica/Trabalho Monumento/ V1.6 - 2013.12.05/MonumentoTeotonioVilela/Vitral.jpg",
        "/home/wgmlima/Documentos/UFAL/cg/Trabalho 09 - Projeto Monumento Teotonio/Recente/MonumentoTeotonioVilela/Texturas/Vitral.jpg",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_POWER_OF_TWO
    );

    texture[7] = SOIL_load_OGL_texture /* Placa */
    (
        //"/home/lucas/Documentos/6º periodo/computação gráfica/Trabalho Monumento/ V1.6 - 2013.12.05/MonumentoTeotonioVilela/placa.jpg",
        "/home/wgmlima/Documentos/UFAL/cg/Trabalho 09 - Projeto Monumento Teotonio/Recente/MonumentoTeotonioVilela/Texturas/placa.jpg",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_POWER_OF_TWO
    );

    texture[8] = SOIL_load_OGL_texture /* Pastilha de vidro */
    (
        //"/home/lucas/Documentos/6º periodo/computação gráfica/Trabalho Monumento/ V1.6 - 2013.12.05/MonumentoTeotonioVilela/pastilhas de vidro branca.jpg",
        "/home/wgmlima/Documentos/UFAL/cg/Trabalho 09 - Projeto Monumento Teotonio/Recente/MonumentoTeotonioVilela/Texturas/PastilhasDeVidroBranca.jpg",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_POWER_OF_TWO
    );

    texture[9] = SOIL_load_OGL_texture /* foto 1 */
    (
        //"/home/lucas/Documentos/6º periodo/computação gráfica/Trabalho Monumento/ V1.6 - 2013.12.05/MonumentoTeotonioVilela/Fotos/1.jpg",
        "/home/wgmlima/Documentos/UFAL/cg/Trabalho 09 - Projeto Monumento Teotonio/Recente/MonumentoTeotonioVilela/Texturas/Fotos/1.jpg",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_POWER_OF_TWO
    );

    texture[10] = SOIL_load_OGL_texture /* foto 2 */
    (
        //"/home/lucas/Documentos/6º periodo/computação gráfica/Trabalho Monumento/ V1.6 - 2013.12.05/MonumentoTeotonioVilela/Fotos/2.jpg",
        "/home/wgmlima/Documentos/UFAL/cg/Trabalho 09 - Projeto Monumento Teotonio/Recente/MonumentoTeotonioVilela/Texturas/Fotos/2.jpg",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_POWER_OF_TWO
    );

    texture[11] = SOIL_load_OGL_texture /* foto 3 */
    (
        //"/home/lucas/Documentos/6º periodo/computação gráfica/Trabalho Monumento/ V1.6 - 2013.12.05/MonumentoTeotonioVilela/Fotos/3.jpg",
        "/home/wgmlima/Documentos/UFAL/cg/Trabalho 09 - Projeto Monumento Teotonio/Recente/MonumentoTeotonioVilela/Texturas/Fotos/3.jpg",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_POWER_OF_TWO
    );

    texture[12] = SOIL_load_OGL_texture /* foto 4 */
    (
        //"/home/lucas/Documentos/6º periodo/computação gráfica/Trabalho Monumento/ V1.6 - 2013.12.05/MonumentoTeotonioVilela/Fotos/4.jpg",
        "/home/wgmlima/Documentos/UFAL/cg/Trabalho 09 - Projeto Monumento Teotonio/Recente/MonumentoTeotonioVilela/Texturas/Fotos/4.jpg",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_POWER_OF_TWO
    );

    texture[13] = SOIL_load_OGL_texture /* foto 5 */
    (
        //"/home/lucas/Documentos/6º periodo/computação gráfica/Trabalho Monumento/ V1.6 - 2013.12.05/MonumentoTeotonioVilela/Fotos/5.jpeg",
        "/home/wgmlima/Documentos/UFAL/cg/Trabalho 09 - Projeto Monumento Teotonio/Recente/MonumentoTeotonioVilela/Texturas/Fotos/5.jpeg",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_POWER_OF_TWO
    );

    texture[14] = SOIL_load_OGL_texture /* Foto 6 */
    (
        //"/home/lucas/Documentos/6º periodo/computação gráfica/Trabalho Monumento/ V1.6 - 2013.12.05/MonumentoTeotonioVilela/Fotos/6.jpg",
        "/home/wgmlima/Documentos/UFAL/cg/Trabalho 09 - Projeto Monumento Teotonio/Recente/MonumentoTeotonioVilela/Texturas/Fotos/6.jpg",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_POWER_OF_TWO
    );

    texture[15] = SOIL_load_OGL_texture /* Marmore Preto */
    (
        //"/home/lucas/Documentos/6º periodo/computação gráfica/Trabalho Monumento/ V1.6 - 2013.12.05/MonumentoTeotonioVilela/masmore preto.jpeg",
        "/home/wgmlima/Documentos/UFAL/cg/Trabalho 09 - Projeto Monumento Teotonio/Recente/MonumentoTeotonioVilela/Texturas/masmore preto.jpeg",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_POWER_OF_TWO
    );

    texture[16] = SOIL_load_OGL_texture /* Inox */
    (
        //"/home/lucas/Documentos/6º periodo/computação gráfica/Trabalho Monumento/ V1.6 - 2013.12.05/MonumentoTeotonioVilela/Inox.jpg",
        "/home/wgmlima/Documentos/UFAL/cg/Trabalho 09 - Projeto Monumento Teotonio/Recente/MonumentoTeotonioVilela/Texturas/Inox.jpg",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_POWER_OF_TWO
    );

    texture[17] = SOIL_load_OGL_texture /* Cobre */
    (
        //"/home/lucas/Documentos/6º periodo/computação gráfica/Trabalho Monumento/ V1.6 - 2013.12.05/MonumentoTeotonioVilela/Cobre.jpeg",
        "/home/wgmlima/Documentos/UFAL/cg/Trabalho 09 - Projeto Monumento Teotonio/Recente/MonumentoTeotonioVilela/Texturas/IMG_0098.jpg",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_POWER_OF_TWO
    );

}


void Janela::initializeGL(){ /** <ToDo> @wgmlima [Verificar a os metodos de da GL
    e implementar direito] */

    glViewport(0, 0, janelaLargura, janelaAltura);
    glEnable(GL_DEPTH_TEST);//habilita perspectiva de trás e frente

    glClearColor(0,0,0,1);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    perspectiveGL(angulo, (double)janelaLargura/janelaAltura, 4000, -4000 );

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glEnable (GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glEnable(GL_TEXTURE_2D);

    loadTexture();/** Carrega as texturas pré-definidas*/

    glShadeModel(GL_SMOOTH);//modelo de sombreamento Gouraud

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<


//    //função retorna os valores dos parâmetros da fonte de luz.
//    glLightfv(GL_LIGHT0, GL_DIFFUSE, cor_Sol);//iluminação difusa
//    glLightfv(GL_LIGHT0, GL_SPECULAR, cor_Sol);//iluminação especular
//    glLightfv(GL_LIGHT0, GL_AMBIENT, cor_sol_amb);//iluminação ambiente
//    glLightfv(GL_LIGHT0, GL_POSITION, posicao_Sol);//posição da iluminação

////    //luz spot
////    glLightfv(GL_LIGHT1, GL_DIFFUSE, cor_luz1);
////    glLightfv(GL_LIGHT1, GL_SPECULAR, cor_luz1);
////    glLightf (GL_LIGHT1, GL_SPOT_CUTOFF, spot_luz1);
////    glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 10.0);
////    glLightfv(GL_LIGHT1, GL_POSITION, posicao_luz1);
////    glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, direcao_luz1);

//    glEnable(GL_LIGHTING);//habilita iluminação
//    glEnable(GL_LIGHT0);//habilita iluminação do primeiro objeto,
//    glEnable(GL_LIGHT1);

//    glEnable(GL_AUTO_NORMAL);//habilita a normal da superficie
//    glEnable(GL_NORMALIZE);//vetores normais são normalizados para unidade de comprimento após transformação e antes de iluminação.

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
// Thyago implementação
//    glFrontFace(GL_CW);
//    glEnable(GL_LIGHTING);
//    glEnable(GL_CULL_FACE);

//    glLightfv(GL_LIGHT0, GL_DIFFUSE, cor_Sol);//iluminação difusa
//    glLightfv(GL_LIGHT0, GL_SPECULAR, cor_Sol);//iluminação especular
//    glLightfv(GL_LIGHT0, GL_AMBIENT, cor_sol_amb);//iluminação ambiente
//    glLightfv(GL_LIGHT0, GL_POSITION, posicao_Sol);//posição da iluminação

//    glEnable(GL_LIGHT0);
//    glEnable(GL_COLOR_MATERIAL);
//    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

//    glEnable(GL_NORMALIZE);

}/* ----- END initializeGL ----- */

void Janela::inserirDados(){
    /** @wgmlima <Todo> [Implementar com leitura de arquivo TXT] */
    Superficies temp;

    /** Variáveis auxiiliar para as estruturas de loop */
    GLint var;
    GLfloat var2,var3;

// ------ Grama ------
    /* frente esquerda*/
    temp.setCorRGBA(VERDE);
    temp.setTextureID(1);   /** Define a textura correspondente no vetor de textura*/

    temp.setProximaCoordenada(0,0,0, 0.0, 0.0);
    temp.setProximaCoordenada(790,270,-790,0,1);
    temp.setProximaCoordenada(1450,270,-790,1,1);
    temp.setProximaCoordenada(1450,0,0,1,0);

    estrutura.push_back(temp);
    temp.verticesClear();

    /* lado esquerdo */
    temp.setCorRGBA(VERDE);

    temp.setProximaCoordenada(0,0,-3706,0,0);
    temp.setProximaCoordenada(790,270,-2916,0,1);
    temp.setProximaCoordenada(790,270,-790,1,1);
    temp.setProximaCoordenada(0,0,0,1,0);

    estrutura.push_back(temp);
    temp.verticesClear();

    /* trás */
    temp.setCorRGBA(VERDE);

    temp.setProximaCoordenada(3230,0,-3706,0,0);
    temp.setProximaCoordenada(2440,270,-2916,0,1);
    temp.setProximaCoordenada(790,270,-2916,1,1);
    temp.setProximaCoordenada(0,0,-3706,1,0);

    estrutura.push_back(temp);
    temp.verticesClear();

    /* lado direita */
    temp.setCorRGBA(VERDE);

    temp.setProximaCoordenada(3230,0,0,0,0);
    temp.setProximaCoordenada(2440,270,-790,0,1);
    temp.setProximaCoordenada(2440,270,-2916,1,1);
    temp.setProximaCoordenada(3230,0,-3706,1,0);

    estrutura.push_back(temp);
    temp.verticesClear();

    /* frente direita */
    temp.setCorRGBA(VERDE);

    temp.setProximaCoordenada(1780,0,0,0,0);
    temp.setProximaCoordenada(1780,270,-790,0,1);
    temp.setProximaCoordenada(2440,270,-790,1,1);
    temp.setProximaCoordenada(3230,0,0,1,0);

    estrutura.push_back(temp);
    temp.verticesClear();
    temp.textureIDClear();

// ------ Entrada ------
    /* Entrada Rampa */
    temp.setCorRGBA(BRANCA);
    temp.setTextureID(4);

    var3=0;

        for (var = 0; var > -800; var-=50) {


                temp.setProximaCoordenada(1465,(GLint)var3,var,0,0);
                temp.setProximaCoordenada(1465,(GLint)(var3-6.25),var-50,0,1);
                temp.setProximaCoordenada(1615,(GLint)(var3-6.25),var-50,1,1);
                temp.setProximaCoordenada(1615,(GLint)var3,var,1,0);

                estrutura.push_back(temp);
                temp.verticesClear();

                temp.setProximaCoordenada(1765,(GLint)var3,var,0,0);
                temp.setProximaCoordenada(1765,(GLint)(var3-6.25),var-50,0,1);
                temp.setProximaCoordenada(1615,(GLint)(var3-6.25),var-50,1,1);
                temp.setProximaCoordenada(1615,(GLint)var3,var,1,0);

                estrutura.push_back(temp);
                temp.verticesClear();

            var3-=6.25;


}
   temp.textureIDClear();


//    temp.setProximaCoordenada(1465,0,0);
//    temp.setProximaCoordenada(1465,-100,-830);
//    temp.setProximaCoordenada(1765,-100,-830);
//    temp.setProximaCoordenada(1765,0,0);

//    estrutura.push_back(temp);
//    temp.verticesClear();

//    temp.setProximaCoordenada(1465,-100,-830);
//    temp.setProximaCoordenada(1465,-100,-1100);
//    temp.setProximaCoordenada(1545,-100,-1100);
//    temp.setProximaCoordenada(1545,-100,-1150);
//    temp.setProximaCoordenada(1685,-100,-1150);
//    temp.setProximaCoordenada(1685,-100,-1100);
//    temp.setProximaCoordenada(1765,-100,-1100);
//    temp.setProximaCoordenada(1765,-100,-830);

//    estrutura.push_back(temp);
//    temp.verticesClear();


    /* Entrada Parede esquerda rampa meiofio */
    temp.setCorRGBA(CINZA_CLARO);

    temp.setProximaCoordenada(1465,0,0);
    temp.setProximaCoordenada(1450,0,0);
    temp.setProximaCoordenada(1450,280,-790);
    temp.setProximaCoordenada(1465,280,-790);

    estrutura.push_back(temp);
    temp.verticesClear();


    temp.setProximaCoordenada(1450,0,0);
    temp.setProximaCoordenada(1450,-10,0);
    temp.setProximaCoordenada(1450,270,-790);
    temp.setProximaCoordenada(1450,280,-790);

    estrutura.push_back(temp);
    temp.verticesClear();

    /* Paredes rampa */
    temp.setTextureID(3);
    var2=var3=0;

    for (var = 0; var > -800; var-=50) {
        if (var2<80){
            temp.setProximaCoordenada(1465,(GLint)var3,var,0,0);
            temp.setProximaCoordenada(1465,(GLint)var2,var,0,1);
            temp.setProximaCoordenada(1465,(GLint)(var2+17.5),var-50,1,1);
            temp.setProximaCoordenada(1465,(GLint)(var3-6.25),var-50,1,0);

            estrutura.push_back(temp);
            temp.verticesClear();


            temp.setProximaCoordenada(1765,(GLint)var3,var,0,0);
            temp.setProximaCoordenada(1765,(GLint)var2,var,0,1);
            temp.setProximaCoordenada(1765,(GLint)(var2+17.5),var-50,1,1);
            temp.setProximaCoordenada(1765,(GLint)(var3-6.25),var-50,1,0);

            estrutura.push_back(temp);
            temp.verticesClear();
        }else {

            temp.setProximaCoordenada(1465,80,var,0,0);
            temp.setProximaCoordenada(1465,(GLint)var2,var,0,1);
            temp.setProximaCoordenada(1465,(GLint)(var2+17.5),var-50,1,1);
            temp.setProximaCoordenada(1465,80,var-50,1,0);

            estrutura.push_back(temp);
            temp.verticesClear();

            temp.setProximaCoordenada(1765,80,var,0,0);
            temp.setProximaCoordenada(1765,(GLint)var2,var,0,1);
            temp.setProximaCoordenada(1765,(GLint)(var2+17.5),var-50,1,1);
            temp.setProximaCoordenada(1765,80,var-50,1,0);

            estrutura.push_back(temp);
            temp.verticesClear();


            temp.setProximaCoordenada(1465,(GLint)var3,var,0,0);
            temp.setProximaCoordenada(1465,80,var,0,1);
            temp.setProximaCoordenada(1465,80,var-50,1,1);
            temp.setProximaCoordenada(1465,(GLint)(var3-6.25),var-50,1,0);

            estrutura.push_back(temp);
            temp.verticesClear();

            temp.setProximaCoordenada(1765,(GLint)var3,var,0,0);
            temp.setProximaCoordenada(1765,80,var,0,1);
            temp.setProximaCoordenada(1765,80,var-50,1,1);
            temp.setProximaCoordenada(1765,(GLint)(var3-6.25),var-50,1,0);

            estrutura.push_back(temp);
            temp.verticesClear();
        }
        var2+=17.75;
        var3-=6.25;
    }

    for (int var = -800; var > -1100; var-=50) {
        temp.setProximaCoordenada(1465,80,var,0,0);
        temp.setProximaCoordenada(1465,250,var,0,1);
        temp.setProximaCoordenada(1465,250,var-50,1,1);
        temp.setProximaCoordenada(1465,80,var-50,1,0);

        estrutura.push_back(temp);
        temp.verticesClear();

        temp.setProximaCoordenada(1765,80,var,0,0);
        temp.setProximaCoordenada(1765,250,var,0,1);
        temp.setProximaCoordenada(1765,250,var-50,1,1);
        temp.setProximaCoordenada(1765,80,var-50,1,0);

        estrutura.push_back(temp);
        temp.verticesClear();


        temp.setProximaCoordenada(1465,-100,var,0,0);
        temp.setProximaCoordenada(1465,80,var,0,1);
        temp.setProximaCoordenada(1465,80,var-50,1,1);
        temp.setProximaCoordenada(1465,-100,var-50,1,0);

        estrutura.push_back(temp);
        temp.verticesClear();

        temp.setProximaCoordenada(1765,-100,var,0,0);
        temp.setProximaCoordenada(1765,80,var,0,1);
        temp.setProximaCoordenada(1765,80,var-50,1,1);
        temp.setProximaCoordenada(1765,-100,var-50,1,0);

        estrutura.push_back(temp);
        temp.verticesClear();
    }


    /* Entrada Parede esquerda porta */

    temp.setProximaCoordenada(1465,-100,-1100,0,0);
    temp.setProximaCoordenada(1465,80,-1100,0,1);
    temp.setProximaCoordenada(1545,80,-1100,1,1);
    temp.setProximaCoordenada(1545,-100,-1100,1,0);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(1465,80,-1100,0,0);
    temp.setProximaCoordenada(1465,250,-1100,0,1);
    temp.setProximaCoordenada(1545,250,-1100,1,1);
    temp.setProximaCoordenada(1545,80,-1100,1,0);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(1545,-100,-1100,0,0);
    temp.setProximaCoordenada(1545,80,-1100,0,1);
    temp.setProximaCoordenada(1545,80,-1150,1,1);
    temp.setProximaCoordenada(1545,-100,-1150,1,0);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(1545,80,-1100,0,0);
    temp.setProximaCoordenada(1545,250,-1100,0,1);
    temp.setProximaCoordenada(1545,250,-1150,1,1);
    temp.setProximaCoordenada(1545,80,-1150,1,0);

    estrutura.push_back(temp);
    temp.verticesClear();

    /* Entrada Parede direita porta */

    temp.setProximaCoordenada(1765,80,-1100,0,0);
    temp.setProximaCoordenada(1685,80,-1100,0,1);
    temp.setProximaCoordenada(1685,-100,-1100,1,1);
    temp.setProximaCoordenada(1765,-100,-1100,1,0);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(1765,250,-1100,0,0);
    temp.setProximaCoordenada(1685,250,-1100,0,1);
    temp.setProximaCoordenada(1685,80,-1100,1,1);
    temp.setProximaCoordenada(1765,80,-1100,1,0);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(1685,80,-1100,0,0);
    temp.setProximaCoordenada(1685,80,-1150,0,1);
    temp.setProximaCoordenada(1685,-100,-1150,1,1);
    temp.setProximaCoordenada(1685,-100,-1100,1,0);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(1685,250,-1100,0,0);
    temp.setProximaCoordenada(1685,250,-1150,0,1);
    temp.setProximaCoordenada(1685,80,-1150,1,1);
    temp.setProximaCoordenada(1685,80,-1100,1,0);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.textureIDClear();

    /* Entrada Parede direita meiofio */

    temp.setProximaCoordenada(1765,0,0);
    temp.setProximaCoordenada(1780,0,0);
    temp.setProximaCoordenada(1780,280,-790);
    temp.setProximaCoordenada(1765,280,-790);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(1780,0,0);
    temp.setProximaCoordenada(1780,-10,0);
    temp.setProximaCoordenada(1780,270,-790);
    temp.setProximaCoordenada(1780,280,-790);

    estrutura.push_back(temp);
    temp.verticesClear();

    /* Entrada teto */
    temp.setCorRGBA(CREME);
    temp.setProximaCoordenada(1465,250,-790);
    temp.setProximaCoordenada(1465,250,-1100);
    temp.setProximaCoordenada(1545,250,-1100);
    temp.setProximaCoordenada(1545,250,-1150);
    temp.setProximaCoordenada(1685,250,-1150);
    temp.setProximaCoordenada(1685,250,-1100);
    temp.setProximaCoordenada(1765,250,-1100);
    temp.setProximaCoordenada(1765,250,-790);

    estrutura.push_back(temp);
    temp.verticesClear();

// ------ Galeria ------
    /* Chao */
    temp.setCorRGBA(MARROM);
    temp.setTextureID(2);

//    temp.setProximaCoordenada(1545,-100,-1150, 0,0);
//    temp.setProximaCoordenada(1545,-100,-1200, 0,1);
//    temp.setProximaCoordenada(1615,-100,-1200, 1,1);
//    temp.setProximaCoordenada(1615,-100,-1150, 1,0);
//    estrutura.push_back(temp);
//    temp.verticesClear();

//    temp.setProximaCoordenada(1615,-100,-1150, 0,0);
//    temp.setProximaCoordenada(1615,-100,-1200, 0,1);
//    temp.setProximaCoordenada(1685,-100,-1200, 1,1);
//    temp.setProximaCoordenada(1685,-100,-1150, 1,0);
//    estrutura.push_back(temp);
//    temp.verticesClear();

    for (var = -830/*-1200*/; var > -2150; var-=50) {

        temp.setProximaCoordenada(1365,-100,var, 0,0);
        temp.setProximaCoordenada(1365,-100,var-50, 0,1);
        temp.setProximaCoordenada(1615,-100,var-50, 1,1);
        temp.setProximaCoordenada(1615,-100,var, 1,0);

        estrutura.push_back(temp);
        temp.verticesClear();

        temp.setProximaCoordenada(1615,-100,var, 0,0);
        temp.setProximaCoordenada(1615,-100,var-50, 0,1);
        temp.setProximaCoordenada(1865,-100,var-50, 1,1);
        temp.setProximaCoordenada(1865,-100,var, 1,0);

        estrutura.push_back(temp);
        temp.verticesClear();
    }

    temp.textureIDClear();

    /* Paredes galeria */
    temp.setCorRGBA(CINZA_CLARO);
    temp.setTextureID(3);

    temp.setProximaCoordenada(1545, -100, -1150, 0, 0);
    temp.setProximaCoordenada(1545, 80, -1150, 0,1);
    temp.setProximaCoordenada(1545, 80, -1200, 1,1);
    temp.setProximaCoordenada(1545, -100,-1200, 1,0);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(1545, 80, -1150, 0, 0);
    temp.setProximaCoordenada(1545, 250, -1150, 0,1);
    temp.setProximaCoordenada(1545, 250, -1200, 1,1);
    temp.setProximaCoordenada(1545, 80,-1200, 1,0);

    estrutura.push_back(temp);
    temp.verticesClear();


    temp.setProximaCoordenada(1685, -100, -1200, 0, 0);
    temp.setProximaCoordenada(1685, 80, -1200, 0,1);
    temp.setProximaCoordenada(1685, 80, -1150, 1,1);
    temp.setProximaCoordenada(1685, -100,-1150, 1,0);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(1685, 80, -1200, 0, 0);
    temp.setProximaCoordenada(1685, 250, -1200, 0,1);
    temp.setProximaCoordenada(1685, 250, -1150, 1,1);
    temp.setProximaCoordenada(1685, 80,-1150, 1,0);

    estrutura.push_back(temp);
    temp.verticesClear();


    for (var = 1545; var > 1365; var-=50) {
        temp.setProximaCoordenada(var, 80, -1200, 0, 0);
        temp.setProximaCoordenada(var-50, 80, -1200, 0, 1);
        temp.setProximaCoordenada(var-50, -100, -1200, 1, 1);
        temp.setProximaCoordenada(var, -100,-1200 , 1, 0);

        estrutura.push_back(temp);
        temp.verticesClear();

        temp.setProximaCoordenada(var, 250, -1200, 0, 0);
        temp.setProximaCoordenada(var-50, 250, -1200, 0, 1);
        temp.setProximaCoordenada(var-50, 80, -1200, 1, 1);
        temp.setProximaCoordenada(var, 80,-1200 , 1, 0);

        estrutura.push_back(temp);
        temp.verticesClear();

    }


    for (var = 1685; var < 1865; var+=50) {
        temp.setProximaCoordenada(var, 80, -1200, 0, 0);
        temp.setProximaCoordenada(var+50, 80, -1200, 0, 1);
        temp.setProximaCoordenada(var+50, -100, -1200, 1, 1);
        temp.setProximaCoordenada(var, -100,-1200 , 1, 0);

        estrutura.push_back(temp);
        temp.verticesClear();

        temp.setProximaCoordenada(var, 250, -1200, 0, 0);
        temp.setProximaCoordenada(var+50, 250, -1200, 0, 1);
        temp.setProximaCoordenada(var+50, 80, -1200, 1, 1);
        temp.setProximaCoordenada(var, 80,-1200 , 1, 0);

        estrutura.push_back(temp);
        temp.verticesClear();
    }

    for (var = -1200; var  > -2525; var-=50) {

        if (-2050 < var && var < -1450 ) {
            temp.setProximaCoordenada(1365,-100,var,0,0);
            temp.setProximaCoordenada(1365,-20,var,0,1);
            temp.setProximaCoordenada(1365,-20,var-50,1,1);
            temp.setProximaCoordenada(1365,-100,var-50,1,0);

            estrutura.push_back(temp);
            temp.verticesClear();

            temp.setProximaCoordenada(1865,-100,var-50,0,0);
            temp.setProximaCoordenada(1865,-20,var-50,0,1);
            temp.setProximaCoordenada(1865,-20,var,1,1);
            temp.setProximaCoordenada(1865,-100,var,1,0);

            estrutura.push_back(temp);
            temp.verticesClear();
        }else{
            temp.setProximaCoordenada(1365,-100,var,0,0);
            temp.setProximaCoordenada(1365,80,var,0,1);
            temp.setProximaCoordenada(1365,80,var-50,1,1);
            temp.setProximaCoordenada(1365,-100,var-50,1,0);

            estrutura.push_back(temp);
            temp.verticesClear();

            temp.setProximaCoordenada(1865,-100,var-50,0,0);
            temp.setProximaCoordenada(1865,80,var-50,0,1);
            temp.setProximaCoordenada(1865,80,var,1,1);
            temp.setProximaCoordenada(1865,-100,var,1,0);

            estrutura.push_back(temp);
            temp.verticesClear();
        }

        temp.setProximaCoordenada(1365,80,var,0,0);
        temp.setProximaCoordenada(1365,280,var,0,1);
        temp.setProximaCoordenada(1365,280,var-50,1,1);
        temp.setProximaCoordenada(1365,80,var-50,1,0);

        estrutura.push_back(temp);
        temp.verticesClear();

        temp.setProximaCoordenada(1865,80,var-50,0,0);
        temp.setProximaCoordenada(1865,280,var-50,0,1);
        temp.setProximaCoordenada(1865,280,var,1,1);
        temp.setProximaCoordenada(1865,80,var,1,0);

        estrutura.push_back(temp);
        temp.verticesClear();
    }

    /* <ToDo> [melhorar as paredes da queda d'água] */

//    temp.setProximaCoordenada(1365,250,-1200);
//    temp.setProximaCoordenada(1365,250,-2180);
//    temp.setProximaCoordenada(1365,280,-2180);
//    temp.setProximaCoordenada(1365,280,-2525);
//    temp.setProximaCoordenada(1365,250,-2525);
//    temp.setProximaCoordenada(1365,250,-2511);
//    temp.setProximaCoordenada(1365,200,-2501);
//    temp.setProximaCoordenada(1365,151,-2491);
//    temp.setProximaCoordenada(1365,91,-2473);
//    temp.setProximaCoordenada(1365,50,-2450);
//    temp.setProximaCoordenada(1365,6,-2420);
//    temp.setProximaCoordenada(1365,-29,-2384);
//    temp.setProximaCoordenada(1365,-58,-2343);
//    temp.setProximaCoordenada(1365,-80,-2298);
//    temp.setProximaCoordenada(1365,-94,-2250);
//    temp.setProximaCoordenada(1365,-100,-2200);
//    temp.setProximaCoordenada(1365,-100,-1200);



//    temp.setProximaCoordenada(1865,250,-1200);
//    temp.setProximaCoordenada(1865,250,-2180);
//    temp.setProximaCoordenada(1865,280,-2180);
//    temp.setProximaCoordenada(1865,280,-2525);
//    temp.setProximaCoordenada(1865,250,-2525);
//    temp.setProximaCoordenada(1865,250,-2511);
//    temp.setProximaCoordenada(1865,200,-2501);
//    temp.setProximaCoordenada(1865,151,-2491);
//    temp.setProximaCoordenada(1865,91,-2473);
//    temp.setProximaCoordenada(1865,50,-2450);
//    temp.setProximaCoordenada(1865,6,-2420);
//    temp.setProximaCoordenada(1865,-29,-2384);
//    temp.setProximaCoordenada(1865,-58,-2343);
//    temp.setProximaCoordenada(1865,-80,-2298);
//    temp.setProximaCoordenada(1865,-94,-2250);
//    temp.setProximaCoordenada(1865,-100,-2200);
//    temp.setProximaCoordenada(1865,-100,-1200);


    temp.textureIDClear();

    /* vitrines esquerda */
    temp.setCorRGBA(CREME);
    temp.setProximaCoordenada(1315,100,-1450);
    temp.setProximaCoordenada(1315,-20,-1450);
    temp.setProximaCoordenada(1365,-20,-1450);
    temp.setProximaCoordenada(1365,100,-1450);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(1315,100,-2050);
    temp.setProximaCoordenada(1315,-20,-2050);
    temp.setProximaCoordenada(1365,-20,-2050);
    temp.setProximaCoordenada(1365,100,-2050);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(1315,100,-1450);
    temp.setProximaCoordenada(1315,-20,-1450);
    temp.setProximaCoordenada(1315,-20,-2050);
    temp.setProximaCoordenada(1315,100,-2050);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(1315,100,-1450);
    temp.setProximaCoordenada(1315,100,-2050);
    temp.setProximaCoordenada(1365,100,-2050);
    temp.setProximaCoordenada(1365,100,-1450);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(1315,-20,-1450);
    temp.setProximaCoordenada(1315,-20,-2050);
    temp.setProximaCoordenada(1365,-20,-2050);
    temp.setProximaCoordenada(1365,-20,-1450);

    estrutura.push_back(temp);
    temp.verticesClear();


    /* vitrines direita */
    temp.setCorRGBA(CREME);
    temp.setProximaCoordenada(1915,100,-1450);
    temp.setProximaCoordenada(1915,-20,-1450);
    temp.setProximaCoordenada(1865,-20,-1450);
    temp.setProximaCoordenada(1865,100,-1450);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(1915,100,-2050);
    temp.setProximaCoordenada(1915,-20,-2050);
    temp.setProximaCoordenada(1865,-20,-2050);
    temp.setProximaCoordenada(1865,100,-2050);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(1915,100,-1450);
    temp.setProximaCoordenada(1915,-20,-1450);
    temp.setProximaCoordenada(1915,-20,-2050);
    temp.setProximaCoordenada(1915,100,-2050);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(1915,100,-1450);
    temp.setProximaCoordenada(1915,100,-2050);
    temp.setProximaCoordenada(1865,100,-2050);
    temp.setProximaCoordenada(1865,100,-1450);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(1915,-20,-1450);
    temp.setProximaCoordenada(1915,-20,-2050);
    temp.setProximaCoordenada(1865,-20,-2050);
    temp.setProximaCoordenada(1865,-20,-1450);

    estrutura.push_back(temp);
    temp.verticesClear();

    /* Queda d'água */
    temp.setCorRGBA(CINZA_CLARO);
    temp.setTextureID(4);

    temp.setProximaCoordenada(1365,-100,-2185,0,0);
    temp.setProximaCoordenada(1365,-100,-2200,0,1);
    temp.setProximaCoordenada(1615,-100,-2200,1,1);
    temp.setProximaCoordenada(1615,-100,-2185,1,0);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(1615,-100,-2185,0,0);
    temp.setProximaCoordenada(1615,-100,-2200,0,1);
    temp.setProximaCoordenada(1865,-100,-2200,1,1);
    temp.setProximaCoordenada(1865,-100,-2185,1,0);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(1365,-100,-2200,0,0);
    temp.setProximaCoordenada(1365,-94,-2250,0,1);
    temp.setProximaCoordenada(1615,-94,-2250,1,1);
    temp.setProximaCoordenada(1615,-100,-2200,1,0);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(1615,-100,-2200,0,0);
    temp.setProximaCoordenada(1615,-94,-2250,0,1);
    temp.setProximaCoordenada(1865,-94,-2250,1,1);
    temp.setProximaCoordenada(1865,-100,-2200,1,0);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(1365,-80,-2298,0,0);
    temp.setProximaCoordenada(1365,-94,-2250,0,1);
    temp.setProximaCoordenada(1615,-94,-2250,1,1);
    temp.setProximaCoordenada(1615,-80,-2298,1,0);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(1615,-80,-2298,0,0);
    temp.setProximaCoordenada(1615,-94,-2250,0,1);
    temp.setProximaCoordenada(1865,-94,-2250,1,1);
    temp.setProximaCoordenada(1865,-80,-2298,1,0);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(1365,-80,-2298,0,0);
    temp.setProximaCoordenada(1365,-58,-2343,0,1);
    temp.setProximaCoordenada(1615,-58,-2343,1,1);
    temp.setProximaCoordenada(1615,-80,-2298,1,0);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(1615,-80,-2298,0,0);
    temp.setProximaCoordenada(1615,-58,-2343,0,1);
    temp.setProximaCoordenada(1865,-58,-2343,1,1);
    temp.setProximaCoordenada(1865,-80,-2298,1,0);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(1365,-58,-2343,0,0);
    temp.setProximaCoordenada(1365,-29,-2384,0,1);
    temp.setProximaCoordenada(1615,-29,-2384,1,1);
    temp.setProximaCoordenada(1615,-58,-2343,1,0);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(1615,-58,-2343,0,0);
    temp.setProximaCoordenada(1615,-29,-2384,0,1);
    temp.setProximaCoordenada(1865,-29,-2384,1,1);
    temp.setProximaCoordenada(1865,-58,-2343,1,0);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(1365,-29,-2384,0,0);
    temp.setProximaCoordenada(1365,6,-2420,0,1);
    temp.setProximaCoordenada(1615,6,-2420,1,1);
    temp.setProximaCoordenada(1615,-29,-2384,1,0);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(1615,-29,-2384,0,0);
    temp.setProximaCoordenada(1615,6,-2420,0,1);
    temp.setProximaCoordenada(1865,6,-2420,1,1);
    temp.setProximaCoordenada(1865,-29,-2384,1,0);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(1365,6,-2420,0,0);
    temp.setProximaCoordenada(1365,50,-2450,0,1);
    temp.setProximaCoordenada(1615,50,-2450,1,1);
    temp.setProximaCoordenada(1615,6,-2420,1,0);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(1615,6,-2420,0,0);
    temp.setProximaCoordenada(1615,50,-2450,0,1);
    temp.setProximaCoordenada(1865,50,-2450,1,1);
    temp.setProximaCoordenada(1865,6,-2420,1,0);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(1365,50,-2450,0,0);
    temp.setProximaCoordenada(1365,91,-2473,0,1);
    temp.setProximaCoordenada(1615,91,-2473,1,1);
    temp.setProximaCoordenada(1615,50,-2450,1,0);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(1615,50,-2450,0,0);
    temp.setProximaCoordenada(1615,91,-2473,0,1);
    temp.setProximaCoordenada(1865,91,-2473,1,1);
    temp.setProximaCoordenada(1865,50,-2450,1,0);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(1365,91,-2473,0,0);
    temp.setProximaCoordenada(1365,151,-2491,0,1);
    temp.setProximaCoordenada(1615,151,-2491,1,1);
    temp.setProximaCoordenada(1615,91,-2473,1,0);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(1615,91,-2473,0,0);
    temp.setProximaCoordenada(1615,151,-2491,0,1);
    temp.setProximaCoordenada(1865,151,-2491,1,1);
    temp.setProximaCoordenada(1865,91,-2473,1,0);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(1365,151,-2491,0,0);
    temp.setProximaCoordenada(1365,200,-2501,0,1);
    temp.setProximaCoordenada(1615,200,-2501,1,1);
    temp.setProximaCoordenada(1615,151,-2491,1,0);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(1615,151,-2491,0,0);
    temp.setProximaCoordenada(1615,200,-2501,0,1);
    temp.setProximaCoordenada(1865,200,-2501,1,1);
    temp.setProximaCoordenada(1865,151,-2491,1,0);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(1365,200,-2501,0,0);
    temp.setProximaCoordenada(1365,250,-2511,0,1);
    temp.setProximaCoordenada(1615,250,-2511,1,1);
    temp.setProximaCoordenada(1615,200,-2501,1,0);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(1615,200,-2501,0,0);
    temp.setProximaCoordenada(1615,250,-2511,0,1);
    temp.setProximaCoordenada(1865,250,-2511,1,1);
    temp.setProximaCoordenada(1865,200,-2501,1,0);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(1365,250,-2511,0,0);
    temp.setProximaCoordenada(1365,250,-2525,0,1);
    temp.setProximaCoordenada(1615,250,-2525,1,1);
    temp.setProximaCoordenada(1615,250,-2511,1,0);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(1615,250,-2511,0,0);
    temp.setProximaCoordenada(1615,250,-2525,0,1);
    temp.setProximaCoordenada(1865,250,-2525,1,1);
    temp.setProximaCoordenada(1865,250,-2511,1,0);

    estrutura.push_back(temp);
    temp.verticesClear();
    temp.textureIDClear();

    /* teto  galeria */
    temp.setCorRGBA(CREME);

    temp.setProximaCoordenada(1545,250,-1200);
    temp.setProximaCoordenada(1365,250,-1200);
    temp.setProximaCoordenada(1365,250,-2180);
    temp.setProximaCoordenada(1865,250,-2180);
    temp.setProximaCoordenada(1865,250,-1200);
    temp.setProximaCoordenada(1685,250,-1200);
    temp.setProximaCoordenada(1685,250,-1150);
    temp.setProximaCoordenada(1545,250,-1150);
    temp.setProximaCoordenada(1545,250,-1150);

    estrutura.push_back(temp);
    temp.verticesClear();

    /* piso superior */
    temp.setCorRGBA(CINZA_CLARO); // cinza escuro
    temp.setProximaCoordenada(1465,250,-790);
    temp.setProximaCoordenada(1465,280,-790);
    temp.setProximaCoordenada(1765,280,-790);
    temp.setProximaCoordenada(1765,250,-790);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(1350,280,-790);
    temp.setProximaCoordenada(1350,280,-2180);
    temp.setProximaCoordenada(1865,280,-2180);
    temp.setProximaCoordenada(1880,280,-2180);
    temp.setProximaCoordenada(1880,280,-790);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(1365,280,-2525);
    temp.setProximaCoordenada(1365,280,-2180);
    temp.setProximaCoordenada(1350,280,-2180);
    temp.setProximaCoordenada(1350,280,-2525);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(1865,280,-2525);
    temp.setProximaCoordenada(1880,280,-2525);
    temp.setProximaCoordenada(1880,280,-2180);
    temp.setProximaCoordenada(1865,280,-2180);

    estrutura.push_back(temp);
    temp.verticesClear();

    /* Borda espelho d'água */
    temp.setCorRGBA(CINZA_CLARO);



    temp.setProximaCoordenada(1350,280,-790);
    temp.setProximaCoordenada(790,280,-790);
    temp.setProximaCoordenada(850,280,-850);
    temp.setProximaCoordenada(1350,280,-850);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(1450,280,-790);
    temp.setProximaCoordenada(790,280,-790);
    temp.setProximaCoordenada(790,270,-790);
    temp.setProximaCoordenada(1450,270,-790);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(790,280,-790);
    temp.setProximaCoordenada(790,280,-2916);
    temp.setProximaCoordenada(850,280,-2856);
    temp.setProximaCoordenada(850,280,-850);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(790,280,-2916);
    temp.setProximaCoordenada(790,280,-790);
    temp.setProximaCoordenada(790,270,-790);
    temp.setProximaCoordenada(790,270,-2916);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(850,280,-2856);
    temp.setProximaCoordenada(790,280,-2916);
    temp.setProximaCoordenada(2440,280,-2916);
    temp.setProximaCoordenada(2380,280,-2856);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(2440,280,-2916);
    temp.setProximaCoordenada(790,280,-2916);
    temp.setProximaCoordenada(790,270,-2916);
    temp.setProximaCoordenada(2440,270,-2916);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(2380,280,-2856);
    temp.setProximaCoordenada(2440,280,-2916);
    temp.setProximaCoordenada(2440,280,-790);
    temp.setProximaCoordenada(2380,280,-850);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(2440,280,-790);
    temp.setProximaCoordenada(2440,280,-2916);
    temp.setProximaCoordenada(2440,270,-2916);
    temp.setProximaCoordenada(2440,270,-790);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(2380,280,-850);
    temp.setProximaCoordenada(2440,280,-790);
    temp.setProximaCoordenada(1880,280,-790);
    temp.setProximaCoordenada(1880,280,-850);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(1780,280,-790);
    temp.setProximaCoordenada(2440,280,-790);
    temp.setProximaCoordenada(2440,270,-790);
    temp.setProximaCoordenada(1780,270,-790);

    estrutura.push_back(temp);
    temp.verticesClear();

    /* espelho dágua PAREDE */
    temp.setCorRGBA(CINZA_CLARO); // cinza escuro
    temp.setTextureID(8); /** Textura é composto por "n" poligonos de 30x30 */

    for (var = 850; var < 2380; var+=30) {
        if(var<1350 || var>1850){
            for (int var2 = 220; var2 < 280; var2+=30) {
                temp.setProximaCoordenada(var,var2,-850,0,0);
                temp.setProximaCoordenada(var,var2+30,-850,0,1);
                temp.setProximaCoordenada(var+30,var2+30,-850,1,1) ;
                temp.setProximaCoordenada(var+30,var2,-850,1,0);
            }
        }else {
            temp.setProximaCoordenada(var,220,-2525,0,0);
            temp.setProximaCoordenada(var,250,-2525,0,1);
            temp.setProximaCoordenada(var+30,250,-2525,1,1);
            temp.setProximaCoordenada(var+30,220,-2525,1,0);
        }

        estrutura.push_back(temp);
        temp.verticesClear();

        temp.setProximaCoordenada(var,220,-2856,0,0);
        temp.setProximaCoordenada(var,280,-2856,0,1);
        temp.setProximaCoordenada(var+30,280,-2856,1,1) ;
        temp.setProximaCoordenada(var+30,220,-2856,1,0);

        estrutura.push_back(temp);
        temp.verticesClear();
    }

    for (var = -850; var > -2856; var-=30)
        for (int var2 = 220; var2 < 280; var2+=30) {
            temp.setProximaCoordenada(850,var2,var,0,0);
            temp.setProximaCoordenada(850,var2+30,var,0,1) ;
            temp.setProximaCoordenada(850,var2+30,var-30,1,1);
            temp.setProximaCoordenada(850,var2,var-30,1,0) ;

            estrutura.push_back(temp);
            temp.verticesClear();

            temp.setProximaCoordenada(2380,var2,var,0,0);
            temp.setProximaCoordenada(2380,var2+30,var,0,1) ;
            temp.setProximaCoordenada(2380,var2+30,var-30,1,1);
            temp.setProximaCoordenada(2380,var2,var-30,1,0) ;

            estrutura.push_back(temp);
            temp.verticesClear();

            if (var>-2525) {
                temp.setProximaCoordenada(1350,var2,var,0,0);
                temp.setProximaCoordenada(1350,var2+30,var,0,1) ;
                temp.setProximaCoordenada(1350,var2+30,var-30,1,1);
                temp.setProximaCoordenada(1350,var2,var-30,1,0) ;

                estrutura.push_back(temp);
                temp.verticesClear();

                temp.setProximaCoordenada(1880,var2,var,0,0);
                temp.setProximaCoordenada(1880,var2+30,var,0,1) ;
                temp.setProximaCoordenada(1880,var2+30,var-30,1,1);
                temp.setProximaCoordenada(1880,var2,var-30,1,0) ;

                estrutura.push_back(temp);
                temp.verticesClear();
            }
        }
    temp.textureIDClear();

    /* espelho dágua FUNDO */
    temp.setCorRGBA(CINZA_CLARO);
    temp.setTextureID(8);

    for (int var = 850; var < 2380; var+=30) {
        for (int var2 = -850; var2 > -2856; var2-=30) {
            if ( (var<1350 || var >= 1850) || var2<=-2495 ){
                temp.setProximaCoordenada(var,220,var2,0,0);
                temp.setProximaCoordenada(var,220,var2-30,0,1);
                temp.setProximaCoordenada(var+30,220,var2-30,1,1);
                temp.setProximaCoordenada(var+30,220,var2,1,0);

                estrutura.push_back(temp);
                temp.verticesClear();
            }
        }
    }
    temp.textureIDClear();

    /* água */
    temp.setCorRGBA(CYANCLARO);
    temp.setCorAlpha(0.70);
    temp.setTextureID(5);

    for (int var = 850; var < 2380; var+=30) {
        for (int var2 = -850; var2 > -2856; var2-=30) {
            if ( (var<1350 || var >= 1850) || var2<=-2495 ){
                temp.setProximaCoordenada(var,260,var2,0,0);
                temp.setProximaCoordenada(var,260,var2-30,0,1);
                temp.setProximaCoordenada(var+30,260,var2-30,1,1);
                temp.setProximaCoordenada(var+30,260,var2,1,0);

                estrutura.push_back(temp);
                temp.verticesClear();
            }
        }
    }
    temp.textureIDClear();

    /* MONUMENTO */

    temp.setCorRGBA(CREME);

    //pé frente
    temp.setProximaCoordenada(1465,280,-1127);
    temp.setProximaCoordenada(1765,280,-1127);
    temp.setProximaCoordenada(1765,575,-1340);
    temp.setProximaCoordenada(1465,575,-1340);

    estrutura.push_back(temp);
    temp.verticesClear();

    //pé fundo
    temp.setProximaCoordenada(1465,280,-1200);
    temp.setProximaCoordenada(1765,280,-1200);
    temp.setProximaCoordenada(1765,492,-1335);
    temp.setProximaCoordenada(1465,492,-1335);

    estrutura.push_back(temp);
    temp.verticesClear();

    //curva pé

    temp.setProximaCoordenada(1465,492,-1335);
    temp.setProximaCoordenada(1765,492,-1335);
    temp.setProximaCoordenada(1765,513,-1357);
    temp.setProximaCoordenada(1465,513,-1357);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(1465,513,-1357);
    temp.setProximaCoordenada(1765,513,-1357);
    temp.setProximaCoordenada(1765,526,-1380);
    temp.setProximaCoordenada(1465,526,-1380);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(1465,526,-1380);
    temp.setProximaCoordenada(1765,526,-1380);
    temp.setProximaCoordenada(1765,530,-1414);
    temp.setProximaCoordenada(1465,530,-1414);

    estrutura.push_back(temp);
    temp.verticesClear();

    //meio cima
    temp.setProximaCoordenada(1465,575,-1340);
    temp.setProximaCoordenada(1765,575,-1340);
    temp.setProximaCoordenada(1765,584,-1472);
    temp.setProximaCoordenada(1465,584,-1472);

    estrutura.push_back(temp);
    temp.verticesClear();

    //meio baixo
    temp.setProximaCoordenada(1465,530,-1414);
    temp.setProximaCoordenada(1765,530,-1414);
    temp.setProximaCoordenada(1765,530,-1566);
    temp.setProximaCoordenada(1465,530,-1566);

    estrutura.push_back(temp);
    temp.verticesClear();


    //curvavde traz

    temp.setProximaCoordenada(1465,530,-1566);
    temp.setProximaCoordenada(1765,530,-1566);
    temp.setProximaCoordenada(1765,526,-1597);
    temp.setProximaCoordenada(1465,526,-1597);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(1465,526,-1597);
    temp.setProximaCoordenada(1765,526,-1597);
    temp.setProximaCoordenada(1765,512,-1647);
    temp.setProximaCoordenada(1465,512,-1647);

    estrutura.push_back(temp);
    temp.verticesClear();
    temp.setProximaCoordenada(1465,512,-1647);
    temp.setProximaCoordenada(1765,512,-1647);
    temp.setProximaCoordenada(1765,480,-1697);
    temp.setProximaCoordenada(1465,480,-1697);

    estrutura.push_back(temp);
    temp.verticesClear();
    temp.setProximaCoordenada(1465,480,-1697);
    temp.setProximaCoordenada(1765,480,-1697);
    temp.setProximaCoordenada(1765,441,-1732);
    temp.setProximaCoordenada(1465,441,-1732);

    estrutura.push_back(temp);
    temp.verticesClear();

    //ponta de traz frete
    temp.setProximaCoordenada(1465,441,-1732);
    temp.setProximaCoordenada(1765,441,-1732);
    temp.setProximaCoordenada(1765,372,-1760);
    temp.setProximaCoordenada(1465,372,-1760);

    estrutura.push_back(temp);
    temp.verticesClear();

    //ponta de traz traz
    temp.setProximaCoordenada(1465,569,-1704);
    temp.setProximaCoordenada(1765,569,-1704);
    temp.setProximaCoordenada(1765,380,-1794);
    temp.setProximaCoordenada(1465,380,-1794);

    estrutura.push_back(temp);
    temp.verticesClear();

    //ponta da ponta de traz
    temp.setProximaCoordenada(1465,380,-1794);
    temp.setProximaCoordenada(1765,380,-1794);
    temp.setProximaCoordenada(1765,372,-1760);
    temp.setProximaCoordenada(1465,372,-1760);

    estrutura.push_back(temp);
    temp.verticesClear();

    //ponta de cima
    temp.setProximaCoordenada(1465,1080,-1047);
    temp.setProximaCoordenada(1765,1080,-1047);
    temp.setProximaCoordenada(1765,1052,-1047);
    temp.setProximaCoordenada(1465,1052,-1047);

    estrutura.push_back(temp);
    temp.verticesClear();

    // curva superior cima

    temp.setProximaCoordenada(1465,1080,-1047);
    temp.setProximaCoordenada(1765,1080,-1047);
    temp.setProximaCoordenada(1765,1063,-1097);
    temp.setProximaCoordenada(1465,1063,-1097);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(1465,1063,-1097);
    temp.setProximaCoordenada(1765,1063,-1097);
    temp.setProximaCoordenada(1765,1044,-1147);
    temp.setProximaCoordenada(1465,1044,-1147);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(1465,1044,-1147);
    temp.setProximaCoordenada(1765,1044,-1147);
    temp.setProximaCoordenada(1765,1023,-1197);
    temp.setProximaCoordenada(1465,1023,-1197);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(1465,1023,-1197);
    temp.setProximaCoordenada(1765,1023,-1197);
    temp.setProximaCoordenada(1765,998,-1247);
    temp.setProximaCoordenada(1465,998,-1247);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(1465,998,-1247);
    temp.setProximaCoordenada(1765,998,-1247);
    temp.setProximaCoordenada(1765,970,-1297);
    temp.setProximaCoordenada(1465,970,-1297);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(1465,970,-1297);
    temp.setProximaCoordenada(1765,970,-1297);
    temp.setProximaCoordenada(1765,939,-1347);
    temp.setProximaCoordenada(1465,939,-1347);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(1465,939,-1347);
    temp.setProximaCoordenada(1765,939,-1347);
    temp.setProximaCoordenada(1765,905,-1397);
    temp.setProximaCoordenada(1465,905,-1397);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(1465,905,-1397);
    temp.setProximaCoordenada(1765,905,-1397);
    temp.setProximaCoordenada(1765,866,-1447);
    temp.setProximaCoordenada(1465,866,-1447);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(1465,866,-1447);
    temp.setProximaCoordenada(1765,866,-1447);
    temp.setProximaCoordenada(1765,823,-1497);
    temp.setProximaCoordenada(1465,823,-1497);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(1465,823,-1497);
    temp.setProximaCoordenada(1765,823,-1497);
    temp.setProximaCoordenada(1765,772,-1547);
    temp.setProximaCoordenada(1465,772,-1547);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(1465,772,-1547);
    temp.setProximaCoordenada(1765,772,-1547);
    temp.setProximaCoordenada(1765,716,-1597);
    temp.setProximaCoordenada(1465,716,-1597);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(1465,718,-1597);
    temp.setProximaCoordenada(1765,718,-1597);
    temp.setProximaCoordenada(1765,654,-1647);
    temp.setProximaCoordenada(1465,654,-1647);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(1465,654,-1647);
    temp.setProximaCoordenada(1765,654,-1647);
    temp.setProximaCoordenada(1765,580,-1697);
    temp.setProximaCoordenada(1465,580,-1697);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(1465,580,-1697);
    temp.setProximaCoordenada(1765,580,-1697);
    temp.setProximaCoordenada(1765,569,-1704);
    temp.setProximaCoordenada(1465,569,-1704);

    estrutura.push_back(temp);
    temp.verticesClear();

    //Curva Superior baixo

    temp.setProximaCoordenada(1465,1052,-1047);
    temp.setProximaCoordenada(1765,1052,-1047);
    temp.setProximaCoordenada(1765,1034,-1097);
    temp.setProximaCoordenada(1465,1034,-1097);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(1465,1034,-1097);
    temp.setProximaCoordenada(1765,1034,-1097);
    temp.setProximaCoordenada(1765,1012,-1147);
    temp.setProximaCoordenada(1465,1012,-1147);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(1465,1012,-1147);
    temp.setProximaCoordenada(1765,1012,-1147);
    temp.setProximaCoordenada(1765,988,-1197);
    temp.setProximaCoordenada(1465,988,-1197);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(1465,988,-1197);
    temp.setProximaCoordenada(1765,988,-1197);
    temp.setProximaCoordenada(1765,960,-1247);
    temp.setProximaCoordenada(1465,960,-1247);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(1465,960,-1247);
    temp.setProximaCoordenada(1765,960,-1247);
    temp.setProximaCoordenada(1765,928,-1297);
    temp.setProximaCoordenada(1465,928,-1297);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(1465,928,-1297);
    temp.setProximaCoordenada(1765,928,-1297);
    temp.setProximaCoordenada(1765,894,-1347);
    temp.setProximaCoordenada(1465,894,-1347);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(1465,894,-1347);
    temp.setProximaCoordenada(1765,894,-1347);
    temp.setProximaCoordenada(1765,854,-1397);
    temp.setProximaCoordenada(1465,854,-1397);


    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(1465,854,-1397);
    temp.setProximaCoordenada(1765,854,-1397);
    temp.setProximaCoordenada(1765,809,-1447);
    temp.setProximaCoordenada(1465,809,-1447);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(1465,809,-1447);
    temp.setProximaCoordenada(1765,809,-1447);
    temp.setProximaCoordenada(1765,756,-1497);
    temp.setProximaCoordenada(1465,756,-1497);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(1465,756,-1497);
    temp.setProximaCoordenada(1765,756,-1497);
    temp.setProximaCoordenada(1765,720,-1526);
    temp.setProximaCoordenada(1465,720,-1526);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(1465,720,-1526);
    temp.setProximaCoordenada(1765,720,-1526);
    temp.setProximaCoordenada(1765,703,-1540);
    temp.setProximaCoordenada(1465,703,-1540);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(1465,703,-1540);
    temp.setProximaCoordenada(1765,703,-1540);
    temp.setProximaCoordenada(1765,677,-1547);
    temp.setProximaCoordenada(1465,677,-1547);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(1465,677,-1547);
    temp.setProximaCoordenada(1765,677,-1547);
    temp.setProximaCoordenada(1765,651,-1545);
    temp.setProximaCoordenada(1465,651,-1545);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(1465,651,-1545);
    temp.setProximaCoordenada(1765,651,-1545);
    temp.setProximaCoordenada(1765,626,-1536);
    temp.setProximaCoordenada(1465,626,-1536);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(1465,626,-1536);
    temp.setProximaCoordenada(1765,626,-1536);
    temp.setProximaCoordenada(1765,603,-1520);
    temp.setProximaCoordenada(1465,603,-1520);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(1465,603,-1520);
    temp.setProximaCoordenada(1765,603,-1520);
    temp.setProximaCoordenada(1765,590,-1497);
    temp.setProximaCoordenada(1465,590,-1497);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(1465,590,-1497);
    temp.setProximaCoordenada(1765,590,-1497);
    temp.setProximaCoordenada(1765,584,-1472);
    temp.setProximaCoordenada(1465,584,-1472);

    estrutura.push_back(temp);
    temp.verticesClear();

// lateral esquerda monumento

    temp.setProximaCoordenada(1465,280,-1127);
    temp.setProximaCoordenada(1465,575,-1340);
    temp.setProximaCoordenada(1465,492,-1335);
    temp.setProximaCoordenada(1465,280,-1200);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(1465,575,-1340);
    temp.setProximaCoordenada(1465,584,-1472);
    temp.setProximaCoordenada(1465,530,-1566);
    temp.setProximaCoordenada(1465,530,-1414);
    temp.setProximaCoordenada(1465,526,-1380);
    temp.setProximaCoordenada(1465,513,-1357);
    temp.setProximaCoordenada(1465,492,-1335);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(1465,441,-1732);
    temp.setProximaCoordenada(1465,372,-1760);
    temp.setProximaCoordenada(1465,380,-1794);
    temp.setProximaCoordenada(1465,569,-1704);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(1465,1080,-1047);
    temp.setProximaCoordenada(1465,1052,-1047);
    temp.setProximaCoordenada(1465,1034,-1097);
    temp.setProximaCoordenada(1465,1063,-1097);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(1465,1063,-1097);
    temp.setProximaCoordenada(1465,1034,-1097);
    temp.setProximaCoordenada(1465,1012,-1147);
    temp.setProximaCoordenada(1465,1044,-1147);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(1465,1044,-1147);
    temp.setProximaCoordenada(1465,1012,-1147);
    temp.setProximaCoordenada(1465,988,-1197);
    temp.setProximaCoordenada(1465,1023,-1197);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(1465,1023,-1197);
    temp.setProximaCoordenada(1465,988,-1197);
    temp.setProximaCoordenada(1465,960,-1247);
    temp.setProximaCoordenada(1465,998,-1247);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(1465,998,-1247);
    temp.setProximaCoordenada(1465,960,-1247);
    temp.setProximaCoordenada(1465,928,-1297);
    temp.setProximaCoordenada(1465,970,-1297);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(1465,970,-1297);
    temp.setProximaCoordenada(1465,928,-1297);
    temp.setProximaCoordenada(1465,894,-1347);
    temp.setProximaCoordenada(1465,939,-1347);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(1465,939,-1347);
    temp.setProximaCoordenada(1465,894,-1347);
    temp.setProximaCoordenada(1465,854,-1397);
    temp.setProximaCoordenada(1465,905,-1397);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(1465,905,-1397);
    temp.setProximaCoordenada(1465,854,-1397);
    temp.setProximaCoordenada(1465,809,-1447);
    temp.setProximaCoordenada(1465,866,-1447);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(1465,866,-1447);
    temp.setProximaCoordenada(1465,809,-1447);
    temp.setProximaCoordenada(1465,756,-1497);
    temp.setProximaCoordenada(1465,823,-1497);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(1465,823,-1497);
    temp.setProximaCoordenada(1465,756,-1497);
    temp.setProximaCoordenada(1465,720,-1526);
    temp.setProximaCoordenada(1465,772,-1547);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(1465,772,-1547);
    temp.setProximaCoordenada(1465,720,-1526);
    temp.setProximaCoordenada(1465,703,-1540);
    temp.setProximaCoordenada(1465,716,-1597);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(1465,718,-1597);
    temp.setProximaCoordenada(1465,703,-1540);
    temp.setProximaCoordenada(1465,677,-1547);
    temp.setProximaCoordenada(1465,654,-1647);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(1465,654,-1647);
    temp.setProximaCoordenada(1465,677,-1547);
    temp.setProximaCoordenada(1465,651,-1545);
    temp.setProximaCoordenada(1465,580,-1697);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(1465,580,-1697);
    temp.setProximaCoordenada(1465,651,-1545);
    temp.setProximaCoordenada(1465,626,-1536);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(1465,580,-1697);
    temp.setProximaCoordenada(1465,651,-1545);
    temp.setProximaCoordenada(1465,626,-1536);
    temp.setProximaCoordenada(1465,603,-1520);
    temp.setProximaCoordenada(1465,590,-1497);
    temp.setProximaCoordenada(1465,584,-1472);
    temp.setProximaCoordenada(1465,530,-1566);
    temp.setProximaCoordenada(1465,526,-1597);
    temp.setProximaCoordenada(1465,512,-1647);
    temp.setProximaCoordenada(1465,480,-1697);
    temp.setProximaCoordenada(1465,441,-1732);
    temp.setProximaCoordenada(1465,569,-1704);

    estrutura.push_back(temp);
    temp.verticesClear();


// lateral direita monumento

    temp.setProximaCoordenada(1765,280,-1127);
    temp.setProximaCoordenada(1765,575,-1340);
    temp.setProximaCoordenada(1765,492,-1335);
    temp.setProximaCoordenada(1765,280,-1200);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(1765,575,-1340);
    temp.setProximaCoordenada(1765,584,-1472);
    temp.setProximaCoordenada(1765,530,-1566);
    temp.setProximaCoordenada(1765,530,-1414);
    temp.setProximaCoordenada(1765,526,-1380);
    temp.setProximaCoordenada(1765,513,-1357);
    temp.setProximaCoordenada(1765,492,-1335);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(1765,441,-1732);
    temp.setProximaCoordenada(1765,372,-1760);
    temp.setProximaCoordenada(1765,380,-1794);
    temp.setProximaCoordenada(1765,569,-1704);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(1765,1080,-1047);
    temp.setProximaCoordenada(1765,1052,-1047);
    temp.setProximaCoordenada(1765,1034,-1097);
    temp.setProximaCoordenada(1765,1063,-1097);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(1765,1063,-1097);
    temp.setProximaCoordenada(1765,1034,-1097);
    temp.setProximaCoordenada(1765,1012,-1147);
    temp.setProximaCoordenada(1765,1044,-1147);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(1765,1044,-1147);
    temp.setProximaCoordenada(1765,1012,-1147);
    temp.setProximaCoordenada(1765,988,-1197);
    temp.setProximaCoordenada(1765,1023,-1197);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(1765,1023,-1197);
    temp.setProximaCoordenada(1765,988,-1197);
    temp.setProximaCoordenada(1765,960,-1247);
    temp.setProximaCoordenada(1765,998,-1247);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(1765,998,-1247);
    temp.setProximaCoordenada(1765,960,-1247);
    temp.setProximaCoordenada(1765,928,-1297);
    temp.setProximaCoordenada(1765,970,-1297);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(1765,970,-1297);
    temp.setProximaCoordenada(1765,928,-1297);
    temp.setProximaCoordenada(1765,894,-1347);
    temp.setProximaCoordenada(1765,939,-1347);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(1765,939,-1347);
    temp.setProximaCoordenada(1765,894,-1347);
    temp.setProximaCoordenada(1765,854,-1397);
    temp.setProximaCoordenada(1765,905,-1397);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(1765,905,-1397);
    temp.setProximaCoordenada(1765,854,-1397);
    temp.setProximaCoordenada(1765,809,-1447);
    temp.setProximaCoordenada(1765,866,-1447);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(1765,866,-1447);
    temp.setProximaCoordenada(1765,809,-1447);
    temp.setProximaCoordenada(1765,756,-1497);
    temp.setProximaCoordenada(1765,823,-1497);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(1765,823,-1497);
    temp.setProximaCoordenada(1765,756,-1497);
    temp.setProximaCoordenada(1765,720,-1526);
    temp.setProximaCoordenada(1765,772,-1547);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(1765,772,-1547);
    temp.setProximaCoordenada(1765,720,-1526);
    temp.setProximaCoordenada(1765,703,-1540);
    temp.setProximaCoordenada(1765,716,-1597);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(1765,718,-1597);
    temp.setProximaCoordenada(1765,703,-1540);
    temp.setProximaCoordenada(1765,677,-1547);
    temp.setProximaCoordenada(1765,654,-1647);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(1765,654,-1647);
    temp.setProximaCoordenada(1765,677,-1547);
    temp.setProximaCoordenada(1765,651,-1545);
    temp.setProximaCoordenada(1765,580,-1697);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(1765,580,-1697);
    temp.setProximaCoordenada(1765,651,-1545);
    temp.setProximaCoordenada(1765,626,-1536);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(1765,580,-1697);
    temp.setProximaCoordenada(1765,651,-1545);
    temp.setProximaCoordenada(1765,626,-1536);
    temp.setProximaCoordenada(1765,603,-1520);
    temp.setProximaCoordenada(1765,590,-1497);
    temp.setProximaCoordenada(1765,584,-1472);
    temp.setProximaCoordenada(1765,530,-1566);
    temp.setProximaCoordenada(1765,526,-1597);
    temp.setProximaCoordenada(1765,512,-1647);
    temp.setProximaCoordenada(1765,480,-1697);
    temp.setProximaCoordenada(1765,441,-1732);
    temp.setProximaCoordenada(1765,569,-1704);

    estrutura.push_back(temp);
    temp.verticesClear();

    /* Fotos */

    temp.setCorRGBA(BRANCA);
    temp.setTextureID(9);

    temp.setProximaCoordenada(1316,50,-1602,0,0);
    temp.setProximaCoordenada(1316,50,-1561,0,1);
    temp.setProximaCoordenada(1316,10,-1561,1,1);
    temp.setProximaCoordenada(1316,10,-1602,1,0);

    estrutura.push_back(temp);
    temp.verticesClear();
    temp.textureIDClear();

    temp.setTextureID(10);

    temp.setProximaCoordenada(1316,50,-1772,0,0);
    temp.setProximaCoordenada(1316,50,-1713,0,1);
    temp.setProximaCoordenada(1316,10,-1713,1,1);
    temp.setProximaCoordenada(1316,10,-1772,1,0);

    estrutura.push_back(temp);
    temp.verticesClear();
    temp.textureIDClear();

    temp.setTextureID(11);

    temp.setProximaCoordenada(1316,50,-1939,0,0);
    temp.setProximaCoordenada(1316,50,-1883,0,1);
    temp.setProximaCoordenada(1316,10,-1883,1,1);
    temp.setProximaCoordenada(1316,10,-1939,1,0);

    estrutura.push_back(temp);
    temp.verticesClear();
    temp.textureIDClear();

    temp.setTextureID(12);

    temp.setProximaCoordenada(1914,50,-1561,0,0);
    temp.setProximaCoordenada(1914,50,-1602,0,1);
    temp.setProximaCoordenada(1914,10,-1602,1,1);
    temp.setProximaCoordenada(1914,10,-1561,1,0);

    estrutura.push_back(temp);
    temp.verticesClear();
    temp.textureIDClear();

    temp.setTextureID(13);

    temp.setProximaCoordenada(1914,50,-1723,0,0);
    temp.setProximaCoordenada(1914,50,-1778,0,1);
    temp.setProximaCoordenada(1914,10,-1778,1,1);
    temp.setProximaCoordenada(1914,10,-1723,1,0);

    estrutura.push_back(temp);
    temp.verticesClear();
    temp.textureIDClear();

    temp.setTextureID(14);

    temp.setProximaCoordenada(1914,50,-1893,0,0);
    temp.setProximaCoordenada(1914,50,-1922,0,1);
    temp.setProximaCoordenada(1914,10,-1922,1,1);
    temp.setProximaCoordenada(1914,10,-1893,1,0);

    estrutura.push_back(temp);
    temp.verticesClear();
    temp.textureIDClear();



    /* vitral vitrine */
    temp.setCorRGBA(CYANCLARO);

    temp.setProximaCoordenada(1360,80,-1450);
    temp.setProximaCoordenada(1360,-20,-1450);
    temp.setProximaCoordenada(1360,-20,-2050);
    temp.setProximaCoordenada(1360,80,-2050);

    estrutura.push_back(temp);
    temp.verticesClear();

    temp.setProximaCoordenada(1870,80,-1450);
    temp.setProximaCoordenada(1870,-20,-1450);
    temp.setProximaCoordenada(1870,-20,-2050);
    temp.setProximaCoordenada(1870,80,-2050);

    estrutura.push_back(temp);
    temp.verticesClear();

    /* Vitral galeria */
    temp.setCorRGBA(CYANCLARO);
    temp.setTextureID(6);
    temp.setCorAlpha(0.70);

    temp.setProximaCoordenada(1865,250,-2156,0,0);
    temp.setProximaCoordenada(1365,250,-2156,0,1);
    temp.setProximaCoordenada(1365,-100,-2156,1,1);
    temp.setProximaCoordenada(1865,-100,-2156,1,0);

    estrutura.push_back(temp);
    temp.verticesClear();
    temp.textureIDClear();



    /* Janela de vidro */
    temp.setCorRGBA(CYANCLARO);
    temp.setProximaCoordenada(1545,148,-1150);
    temp.setProximaCoordenada(1545,250,-1150);
    temp.setProximaCoordenada(1685,250,-1150);
    temp.setProximaCoordenada(1685,148,-1150);

    estrutura.push_back(temp);
    temp.verticesClear();

     /* Porta de vidro */
     porta.setCorRGBA(CYANCLARO);
     porta.setProximaCoordenada(-128,0,0);
     porta.setProximaCoordenada(-128,244,0);
     porta.setProximaCoordenada(10,244,0);
     porta.setProximaCoordenada(10,0,0);

}/* ----- END inserirDados ----- */

void Janela::desenhaCilindro(GLfloat raioBase, GLfloat raioTopo, GLfloat altura){

    GLUquadricObj* Cylinder = gluNewQuadric();//cria um objeto quádrico
    gluQuadricDrawStyle( Cylinder, GLU_FILL );//renderizar como pontos, linhas ou poligonos preenchidos.
    gluQuadricOrientation( Cylinder, GLU_OUTSIDE );//diferenciar o interior a partir do exterior, GLU_OUTSIDE: vetores apontados para dentro
    gluQuadricTexture( Cylinder, GL_TRUE);//gerar coordenadas da textura
    gluQuadricNormals( Cylinder, GLU_SMOOTH );//especifica como normais da superficie deveriam ser geradas. GLU_SMOOTH: uma normal para cada vértice
    gluCylinder(Cylinder, raioBase, raioTopo, altura, 20, 20);

    gluDeleteQuadric(Cylinder);//deleta o objeto quádrico

}/* ----- END desenhaCilindro ----- */

void Janela::desenhaDisco(GLfloat raioInterno, GLfloat raioExterno){
    GLUquadricObj* disck = gluNewQuadric();//cria um objeto quádrico
    gluQuadricDrawStyle( disck, GLU_FILL );//renderizar como pontos, linhas ou poligonos preenchidos.
    gluQuadricOrientation( disck, GLU_OUTSIDE );//diferenciar o interior a partir do exterior, GLU_OUTSIDE: vetores apontados para dentro
    gluQuadricTexture( disck, GL_TRUE);//gerar coordenadas da textura
    gluQuadricNormals( disck, GLU_SMOOTH );//especifica como normais da superficie deveriam ser geradas. GLU_SMOOTH: uma normal para cada vértice
    gluDisk(disck, raioInterno, raioExterno, 20, 20);

}

void Janela::desenharPorta(){
    glPushMatrix();
        glTranslatef(1674, -98, -1149); /* <ToDo> receber a posiçao do objeto como parametro da funcao */
        glRotatef(this->porta.getRotacaoY(),0,1,0);
        desenharPoligono (this->porta);
    glPopMatrix();
}/* ----- END desenharPorta ----- */

void Janela::desenhaPlaca(GLint texturaID, GLfloat largura, GLfloat altura){
    glPushMatrix();
        glColor3f(1,1,1);
        glBindTexture(GL_TEXTURE_2D, texture[texturaID]);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

        glTranslatef(3230,altura,-50); /* <ToDo> receber a posiçao do objeto como parametro da funcao */
        glRotatef(90,1,0,0);
        glScalef(0.25, 1, 1);
        desenhaCilindro(largura/2,largura/2,altura);

        /** Fecha o cilindro com 2 discos de inox */
        glBindTexture(GL_TEXTURE_2D, texture[16]);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
        desenhaDisco(0,largura/2);
        glPushMatrix();
            glTranslatef(0,0,altura/2);
            desenhaDisco(0,largura/2);
        glPopMatrix();

    glPopMatrix();
}/* ----- END desenhaPlaca ----- */

void Janela::desenhaEstatua(GLint texturaID, GLfloat largura, GLfloat altura){
    glPushMatrix();

        glColor3f(1,1,1);
        glBindTexture(GL_TEXTURE_2D, texture[texturaID]);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

        glTranslatef(1615,altura+575,-(1355+largura/2) ); /* <ToDo> receber a posiçao do objeto como parametro da funcao */
        glRotatef(90,1,0,0);
        glRotatef(180,0,0,1);
        desenhaCilindro(largura/2,largura/2,altura);

        /** Fecha o cilindro com 2 discos */
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
        desenhaDisco(0,largura/2);
        glPushMatrix();
            glTranslatef(0,0,altura/2);
            desenhaDisco(0,largura/2);
        glPopMatrix();

    glPopMatrix();
}

void Janela::EntrarMonumento(){
    this->portaAbrir();

    /* @wgmlima <ToDo> [ Implementar] */

}/* ----- END EntrarMonumento ----- */

void Janela::SairMonumento(){
    this->portaFechar();

    /* @wgmlima <ToDo> [ Implementar] */

}/* ----- END SairMonumento ----- */

void Janela::portaAbrir(){
    for (GLint var = 0; var >= -90; var-=10) {
        this->porta.setRotacaoY(var);
        updateGL();
    }
}/* ----- END portaAbrir ----- */

void Janela::portaFechar(){
    for (GLint var = -90; var <= 0; var+=10) {
        this->porta.setRotacaoY(var);
        updateGL();
    }
}/* ----- END portaFechar ----- */

void Janela::desenharPoligono(Superficies &objeto){
    QVector <CoordenadaXYZ> vertices = objeto.getCoordenada();
    //se não houver textura, pega a cor normal (Icaro + Lucas)
    if(objeto.getTextureID() == 0 )
        glColor4f(objeto.getCorRed(),objeto.getCorGreen(),objeto.getCorBlue(),objeto.getCorAlpha());
    //se houver textura, pinta de branco (Icaro + Lucas)
    else
        glColor4f(1,1,1,objeto.getCorAlpha());

    glBegin(GL_POLYGON);
        /* Varredura com iterators "C++ 11" */
        for (CoordenadaXYZ &c : vertices) {
            glVertex3i(c.getX(),c.getY(),c.getZ());
            //se houver textura, carrega as coordenadas da textura
            if(objeto.getTextureID() != 0 )
                glTexCoord2f(c.getX1(), c.getY1());
        }
    glEnd();
}/* ----- END desenharPoligono ----- */

// Implementação da função qDegreesToRadians
inline float degreesToRadians(float degrees)
{
    return degrees * float(M_PI/180);
}

void Janela::resizeGL(GLint w, GLint h){

    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glLoadIdentity();
    perspectiveGL(45, (double)janelaLargura/janelaAltura, 0.1, 100000 );

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

}/* ----- END resizeGL ----- */

void Janela::paintGL(){

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    glLoadIdentity();
    gluLookAt(raio * sin(degreesToRadians(cameraRotate)),
         cameraPosicao.getY(),raio * cos(degreesToRadians(cameraRotate)),
         0,0, 0, 0.0f, 1.0f ,0.0f);

    glPushMatrix();
        glTranslatef(-centroEstrutura.getX(), 0, -centroEstrutura.getZ());

//        glPushMatrix();
//          glTranslatef(posicao_Sol[0],posicao_Sol[1],posicao_Sol[2]);
//          glColor3f(1,1,1);
//          glMaterialfv(GL_FRONT, GL_EMISSION, cor_Sol);//GL_EMISSION define a intensidade luminosa emitida pelo material como sendo a própria cor da fonte de luz

//          GLUquadricObj* esfera = gluNewQuadric();//cria um objeto quádrico
//          gluQuadricDrawStyle( esfera, GLU_FILL );//renderizar como pontos, linhas ou poligonos preenchidos.
//          gluQuadricOrientation( esfera, GLU_OUTSIDE );//diferenciar o interior a partir do exterior, GLU_OUTSIDE: vetores apontados para dentro
//          gluQuadricTexture( esfera, GL_TRUE);//gerar coordenadas da textura
//          gluQuadricNormals( esfera, GLU_SMOOTH );//especifica como normais da superficie deveriam ser geradas. GLU_SMOOTH: uma normal para cada vértice
//          gluSphere(esfera,100,20,20);

//          //glutWireSphere(0.3,5,5);
//          //glutSolidSphere(0.3,5,5);
//          glPopMatrix();


        for (Superficies &s : estrutura){
            /** habilita textura 2D*/
            glBindTexture(GL_TEXTURE_2D, texture[s.getTextureID()]);
            glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
            glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

            desenharPoligono(s);
        }
        desenharPorta();
        desenhaPlaca(7,60,300);
        desenhaEstatua(17,75,200);

        swapBuffers();
    glPopMatrix();

}/* ----- END paintGL ----- */

void Janela::moverCamera(){
    /** <ToDo> @wgmlima [ Implementar ] */
    updateGL();
}

void Janela::giraCamera(GLfloat angulo){ /** <ToDo> @gmail [ testar ] */

    if (this->posisao)
        cameraFoco.setCoordenadas( ceil(cameraPosicao.getX() + raioDentro * cos(angulo)), this->cameraAltura , ceil(cameraPosicao.getZ() + raioDentro * sin(angulo)));
    else cameraPosicao.setCoordenadas( ceil( cameraFoco.getX() + raioFora * cos(angulo)), this->cameraAltura , ceil(cameraFoco.getZ() + raioFora * sin(angulo)));

    updateGL();

//    Na forma parametrizada

//        x = x_0 + r* sen(o)cos(a)
//        y = y_0 + r * sen(o)sen(a)
//        z = z_0 + r * sen(o)
}

void Janela::keyPressEvent(QKeyEvent *event) // Thiago
{
    int current_key  = event->key();

    if (cameraRotate > 360.0f)
        cameraRotate -= 360.0f;

    switch(current_key) {
        case 'A':
            cameraRotate++;
            break;
        case 'D':
            cameraRotate--;
            break;
        case 'W':
            raio -=20;
            break;
        case 'S':
            raio += 20;
            break;
        case 'P':
            this->portaAbrir();
            this->portaFechar();
            break;
        case Qt::Key_Down:
            cameraPosicao.setY(cameraPosicao.getY()-20);
            break;
        case Qt::Key_Up:
            cameraPosicao.setY(cameraPosicao.getY()+20);
            break;
    }
    updateGL(); /** Atualiza a tela */
}

