#pragma once

#include <QGridLayout>
#include <QWidget>

class MainWidget : public QWidget {
    Q_OBJECT

public:
    MainWidget();
    ~MainWidget();

private:
    QGridLayout *layout_;
};
