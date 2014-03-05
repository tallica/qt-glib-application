#include <QtCore>
#include <QtGui>
#include <QApplication>
#include <QMainWindow>
#include "thread.h"

using namespace std;

extern "C" {
    #include <glib.h>
    #include <stdio.h>

    int callback() {
        qDebug() << "callback";
        return 1;
    }
}

void Thread::run() {
    qDebug() << "Thread start";
    GMainLoop *main_loop = g_main_loop_new(NULL, FALSE);
    g_main_loop_run(main_loop);
    qDebug() << "Thread end";
}

int main(int argc, char **argv) {

    g_timeout_add_seconds(1, (GSourceFunc) callback, NULL);

    Thread *t = new Thread;
    t->start();

    QApplication app(argc, argv);

    QMainWindow m;
    m.show();

    return app.exec();
}
