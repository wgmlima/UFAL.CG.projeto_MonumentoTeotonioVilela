#include "superficies.h"

Superficies::Superficies(){
    this->red=this->green=this->blue=this->alpha=0;
    this->textureID=0;
}

void Superficies::setCorRed(GLfloat red){
    this->red=red;
}/* ----- END setCorR ----- */

void Superficies::setCorGreen(GLfloat green){
    this->green=green;
}/* ----- END setCorG ----- */

void Superficies::setCorBlue(GLfloat blue){
    this->blue=blue;
}/* ----- END setCorB ----- */

void Superficies::setCorAlpha(GLfloat alpha){
    this->alpha=alpha;
}/* ----- END setCorA ----- */

void Superficies::setCorRGBA(GLfloat red,GLfloat green, GLfloat blue, GLfloat alpha){
    this->setCorRed(red);
    this->setCorGreen(green);
    this->setCorBlue(blue);
    this->setCorAlpha(alpha);
}/* ----- END setCorRGBA ----- */

void Superficies::setCoordenada(QVector <CoordenadaXYZ>& vertices){
    this->vertices=vertices;
}/* ----- END setCoordenada ----- */

void Superficies::setProximaCoordenada (GLint x,GLint y, GLint z){
    CoordenadaXYZ temp(x,y,z);
    this->vertices.push_back(temp);
}/* ----- END setProximaCoordenada ----- */

void Superficies::setProximaCoordenada (GLint x,GLint y, GLint z, GLfloat x1, GLfloat y1){
    CoordenadaXYZ temp(x,y,z, x1, y1);

    this->vertices.push_back(temp);
}/* ----- END setProximaCoordenada ----- */

void Superficies::setRotacaoX(GLfloat rotacao){
    this->rotacaoX=rotacao;
}/* ----- END setRotacaoX ----- */

void Superficies::setRotacaoY(GLfloat rotacao){
    this->rotacaoY=rotacao;
}/* ----- END setRotacaoY ----- */

void Superficies::setRotacaoZ(GLfloat rotacao){
    this->rotacaoZ=rotacao;
}/* ----- END setRotacaoZ ----- */

void Superficies::setRotacaoXYZ(GLfloat rotacaoX,GLfloat rotacaoY ,GLfloat rotacaoZ){
    this->setRotacaoX(rotacaoX);
    this->setRotacaoY(rotacaoY);
    this->setRotacaoZ(rotacaoZ);
}/* ----- END setRotacaoXYZ ----- */

void Superficies::verticesClear(){
    vertices.clear();
}/* ----- END verticesClear ----- */

void Superficies::textureIDClear(){
    this->textureID=0;
}/* ----- END textureIDClear ----- */


void Superficies::setTextureID(int ID){
    this->textureID = ID;
}/* ----- END setTextureID ----- */


QVector <CoordenadaXYZ>& Superficies::getCoordenada(){
    return(this->vertices);
}/* ----- END getCoordenada ----- */


