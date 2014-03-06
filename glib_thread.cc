#include <QtCore>
#include "glib_thread.h"
#include <glib.h>

GlibThread::~GlibThread()
{
    if (mainLoop)
        g_main_loop_quit(mainLoop);
}

void GlibThread::run()
{
    mainLoop = g_main_loop_new(NULL, FALSE);
    g_idle_add(loop_started_cb, this);
    g_main_loop_run(mainLoop);
    g_main_loop_unref(mainLoop);
    mainLoop = NULL;
}

void GlibThread::clicked() {
    qDebug() << "Clicked!" << QThread::currentThread();
    g_idle_add((GSourceFunc) click_cb, NULL);
}
