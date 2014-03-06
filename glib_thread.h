#ifndef GLIB_THREAD_H
#define GLIB_THREAD_H

#include <QtCore>
#include <glib.h>

class GlibThread : public QThread
{
    Q_OBJECT

    public:
        ~GlibThread();

        void run();

    public slots:
        void clicked();

    protected:
        GMainLoop *mainLoop;

        static gboolean loop_started_cb(gpointer data) {
            return ((GlibThread *)data)->loopStarted();
        }

        static gboolean click_cb() {
            qDebug() << "Clicked callback:" << QThread::currentThread();
            return FALSE;
        }

        int loopStarted() {
            qDebug() << "Glib loop started:" << QThread::currentThread();
            return FALSE;
        }
};

#endif

