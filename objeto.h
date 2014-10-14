#ifndef OBJETO_H
#define OBJETO_H

#include <QVector> /** Para o uso de Vetores do QT e seus metodos implementados */

#include "coordenadaxyz.h"
#include "superficies.h"

class Objeto : public Objeto
{
private:
    QVector <int> texturaID;
    QVector <Superficies> parte;

public:
    Objeto();
};

#endif // OBJETO_H
