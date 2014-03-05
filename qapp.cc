#include <QtCore>
#include <QtGui>
#include <QApplication>
#include <QMainWindow>
#include <QtConcurrent/QtConcurrent>

using namespace std;

extern "C" {
    #include <glib.h>
    #include <stdio.h>

    int callback() {
        qDebug() << "callback";
        return 1;
    }
}

int main(int argc, char * * argv) {

    g_timeout_add_seconds(1, (GSourceFunc) callback, NULL);

    QCoreApplication app(argc, argv);
    // QApplication app(argc, argv);

    // QMainWindow m;
    // m.show();

    return app.exec();
}
