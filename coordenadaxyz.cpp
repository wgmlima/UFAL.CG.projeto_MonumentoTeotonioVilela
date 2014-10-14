#include "coordenadaxyz.h"

CoordenadaXYZ::CoordenadaXYZ(){
    x=y=z=0;
    x1=y1=0.0;//coordenadas textura
}/* ----- END CoordenadaXYZ() ----- */

CoordenadaXYZ::CoordenadaXYZ(GLint x,GLint y, GLint z){
    this->x=x;
    this->y=y;
    this->z=z;
} /* ----- END CoordenadaXYZ(GLint,GLint,GLint) ----- */

CoordenadaXYZ::CoordenadaXYZ(GLint x,GLint y, GLint z, GLfloat x1, GLfloat y1){
    this->x=x;
    this->y=y;
    this->z=z;
    this->x1=x1;
    this->y1=y1;
} /* ----- END CoordenadaXYZ(GLint,GLint,GLint,GLfloat,GLfloat) ----- */


void CoordenadaXYZ::setCoordenadas(int x,int y, int z){
    this->x=x;
    this->y=y;
    this->z=z;

}/* ----- END setCoordenadas(GLint,GLint,GLint) ----- */

void CoordenadaXYZ::setCoordenadas(int x,int y, int z, float x1, float y1){
    this->x=x;
    this->y=y;
    this->z=z;
    this->x1=x1;
    this->y1=y1;
} /* ----- END setCoordenadaXYZ(GLint,GLint,GLint,GLfloat,GLfloat) ----- */
