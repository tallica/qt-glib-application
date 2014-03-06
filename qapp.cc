#include <QtCore>
#include <QtGui>
#include <QApplication>
#include <QMainWindow>
#include <QPushButton>
#include <QHBoxLayout>
#include "glib_thread.h"

using namespace std;

extern "C" {
    #include <glib.h>
    #include <stdio.h>

    gboolean callback() {
        qDebug() << "Timer callback:" << QThread::currentThread();
        return TRUE;
    }
}

int main(int argc, char **argv) {

    g_timeout_add_seconds(1, (GSourceFunc) callback, NULL);

    GlibThread *loop = new GlibThread;
    loop->start();

    QApplication app(argc, argv);

    QWidget *window = new QWidget;
    QPushButton *button = new QPushButton("Click clik!");
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(button);
    window->setLayout(layout);
    window->show();

    qDebug() << "Qt GUI:" << QThread::currentThread();

    QObject::connect(button, SIGNAL(clicked()), loop, SLOT(clicked()));

    return app.exec();
}
