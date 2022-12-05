#include "mainwidget.h"

MainWidget::MainWidget() : QWidget() {
    layout_ = new QGridLayout(this);
}

MainWidget::~MainWidget() {
    delete layout_;
}
