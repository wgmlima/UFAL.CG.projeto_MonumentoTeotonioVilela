#ifndef COORDENADAXYZ_H
#define COORDENADAXYZ_H

#include <QGLWidget> /* Para usar os tipos de OpenGL */

class CoordenadaXYZ{

private:
    GLint x,y,z;
    GLfloat x1, y1;

public:

    CoordenadaXYZ();
    CoordenadaXYZ(GLint x,GLint y, GLint z);
    CoordenadaXYZ(GLint x,GLint y, GLint z, GLfloat x1, GLfloat y1);
    /** Atribue as coordenadas x,y,z */
    void setCoordenadas(GLint x,GLint y, GLint z);

    void setCoordenadas(GLint x,GLint y, GLint z, GLfloat x1, GLfloat y1);

    /** Retorna a coordenadas de X */
    GLint getX() const { return this->x; }

    /** Retorna a coordenadas de Y */
    GLint getY() const { return this->y; }

    /** Retorna a coordenadas de Z */
    GLint getZ() const { return this->z; }
    /** Retorna a coordenada x da textura*/
    GLint getX1() const {return this->x1; }
    /** Retorna a coordenada y da textura*/
    GLint getY1() const {return this->y1; }

    /** Atribue a coordenadas de X */
    void setX(GLint x) {this->x=x; }

    /** Atribue a coordenadas de Y */
    void setY(GLint y) { this->y=y; }

    /** Atribue a coordenadas de Z */
    void setZ(GLint z) { this->z=z; }
    /** Atribue a corrdenada x da textura*/
    void setX1(GLfloat x1) {this -> x1=x1; }
    /** Atribue a corrdenada y da textura*/
    void setY1(GLfloat y1) {this -> y1=y1; }

};

#endif // COORDENADAXYZ_H
