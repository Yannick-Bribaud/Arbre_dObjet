#include <QCoreApplication>
#include "Instance.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QObject::connect(&a, &QObject::destroyed, [] { qDebug() << "\nDestruction de a"; });

    // Création d'une instance automatique sans parent
    Instance i1("i1");

    // Création d'une instance automatique avec a pour parent
    Instance i2("i2", &a);

    // Création d'une instance automatique avec i2 pour parent
    Instance i3("i3", &i2);

    {
        // Création d'une instance automatique avec i1 pour parent
        Instance i4("i4", &i1);
    }

    // Création d'une instance dynamique avec a pour parent
    Instance *i5 = new Instance("i5", &a);

    // Création d'une instance dynamique avec i5 pour parent
    new Instance("i6", i5);

    // Création d'une instance dynamique sans parent
    new Instance("i7"); 
}
