#include "customwindow.h"
#include <QDesktopWidget>
#include <QStylePainter>
#include "windowtitlebar.h"

CustomWIndow::CustomWIndow(QWidget *parent) : QWidget(parent)
{
    resize(1200,700);
    setWindowTitle(tr("Tutorial Qt: CustomWindow"));
    setWindowFlag(Qt::FramelessWindowHint);

    m_MainLayout.setMargin(0);
    m_MainLayout.setSpacing(0);
    setLayout(&m_MainLayout);

    // Titre en haut de la fenêtre;
    m_MainLayout.addWidget(&m_TitleBar, 0, 0, 1, 1);
    m_MainLayout.setRowStretch(1,1);
}

CustomWIndow::~CustomWIndow(){

}

void CustomWIndow::showEvent(QShowEvent *event){

    Q_UNUSED(event);
    CenterOnScreen();
}

void CustomWIndow::CenterOnScreen()
{
    QDesktopWidget screen;

    QRect screenGeom = screen.screenGeometry(this);

    int screenCenterX = screenGeom.center().x();
    int screenCenterY = screenGeom.center().y();

    move(screenCenterX - width() / 2,
         screenCenterY - height() / 2);

}

void CustomWIndow::paintEvent(QPaintEvent *event){

    QPainter painter(this);

    QBrush background(QColor(23,23,34));

    painter.setBrush(background);
    painter.setPen(Qt::NoPen);

    painter.drawRect(0,0, width(), height());

}

//Signal
void CustomWIndow::setWindowTitle(const QString &title){
    QWidget::setWindowTitle(title);
    emit WindowTitleChanged();
}
