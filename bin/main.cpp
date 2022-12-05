#include <QApplication>
#include <QGraphicsView>

#include "scene.h"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    Scene scene;

    QGraphicsView view;
    view.setScene(&scene);
    view.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view.show();

    return app.exec();
}
