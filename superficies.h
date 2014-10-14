#ifndef SUPERFICIES_H
#define SUPERFICIES_H

#include <QVector> /* Para o uso de Vetores do QT e seus metodos implementados */

#include <GL/gl.h> /* Para o uso de tipos OpenGL */

#include "coordenadaxyz.h"

using namespace std;

class Superficies
{
private:
    GLfloat red,green,blue,alpha, rotacaoX, rotacaoY, rotacaoZ;
    QVector <CoordenadaXYZ> vertices;
    GLint textureID;
    /** Identificação da txtura se houver textura, caso contrário atribui valor -1 */

public:
    Superficies();

    void setCorRed(GLfloat red);        /** Atribue o valor "Red" do RGBA da superficie*/
    void setCorGreen(GLfloat green);    /** Atribue o valor "Green" do RGBA da superficie*/
    void setCorBlue(GLfloat blue);      /** Atribue o valor "Blue" do RGBA da superficie*/
    void setCorAlpha(GLfloat Alfa);     /** Atribue o valor "Transparencia" do RGBA da superficie*/
    void setTextureID(GLint ID);        /** Atribue o valor "Id da Textura" da superficie */

    /** Atribue o valor RGBA da superficie*/
    void setCorRGBA(GLfloat red,GLfloat green, GLfloat blue, GLfloat Alfa);

    /** Atribue as coordenadas do verteces da superficie */
    void setCoordenada (QVector <CoordenadaXYZ>& vertices);

    /** Adiciona ao vetor "vertices" as coordenadas do proximo vértice */
    void setProximaCoordenada (GLint x,GLint y, GLint z);

    /** Adiciona ao vetor "vertices" as coordenadas do proximo vértice */
    void setProximaCoordenada (GLint x,GLint y, GLint z, GLfloat x1, GLfloat y1);

    void setRotacaoX(GLfloat rotacao);     /** Atribue o valor "da rotação em X" a superficie*/
    void setRotacaoY(GLfloat rotacao);     /** Atribue o valor "da rotação em Y" a superficie*/
    void setRotacaoZ(GLfloat rotacao);     /** Atribue o valor "da rotação em Z" a superficie*/

    void setRotacaoXYZ(GLfloat rotacaoX,GLfloat rotacaoY ,GLfloat rotacaoZ);
    /** Atribue o valor da rotação a superficie*/

    void verticesClear(); /** Limpa o vetor de vertices */
    void textureIDClear(); /** Remove a textura */

    GLfloat getCorRed()    const { return this->red; }      /** Retorna a "Red" do RGBA da superficie */
    GLfloat getCorGreen()  const { return this->green; }    /** Retorna a "Green" do RGBA da superficie */
    GLfloat getCorBlue()   const { return this->blue; }     /** Retorna a "Blue" do RGBA da superficie */
    GLfloat getCorAlpha()  const { return this->alpha; }    /** Retorna a "Transparencia" do RGBA da superficie */
    GLint getTextureID()   const { return this->textureID; }/** Retorna o "Id da Textura" da superficie */

    GLfloat getRotacaoX() const { return this->rotacaoX; }  /** Retorna o valor "da rotação em X" a superficie*/
    GLfloat getRotacaoY() const { return this->rotacaoY; }  /** Retorna o valor "da rotação em Y" a superficie*/
    GLfloat getRotacaoZ() const { return this->rotacaoZ; }  /** Retorna o valor "da rotação em Z" a superficie*/


    /** Retortna os vértices da superficie na forma de vetor */
    QVector <CoordenadaXYZ>& getCoordenada();
};

#endif // SUPERFICIES_H
