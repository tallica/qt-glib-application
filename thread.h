#include <QtCore>

class Thread : public QThread
{
    Q_OBJECT;

    private:
        void run();
};
