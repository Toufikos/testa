#include "windowtitlebar.h"
#include "customwindow.h"
#include <QPainter>


windowtitlebar::windowtitlebar(QWidget *parent) : QWidget(parent)
{

    // Att : normalement c'est m&_TitleBar et non Title; J'ai laissé pour éviter un blocage;
    connect(this, SIGNAL(WindowTitleChanged()),
            &m_Title, SLOT(UpdateWindowTitle()));


    setFixedHeight(33);
    m_cache = nullptr;

    m_Title.setStyleSheet("color: white; font-family: Sans; font-weight: bold; font-size: 14px");

    UpdateWindowTitle();
}


//Design de la barre du haut
void windowtitlebar::resizeEvent(QResizeEvent *event){

    Q_UNUSED(event);

    delete m_cache; // Remove old cache

    m_cache = new QPixmap(size()); // Create a cache with same as the widget
    m_cache->fill(Qt::transparent); // Create a the transparent background

    QPainter painter(m_cache); // Start painting the cache

    QColor lightBlue(177, 177, 203, 255);
    QColor gradientStart(0, 0, 0, 0);
    QColor gradientEnd(0, 0, 0, 220);

    QLinearGradient linearGrad(QPoint(0,0), QPointF(0, height()));
    linearGrad.setColorAt(0, gradientStart);
    linearGrad.setColorAt(1, gradientEnd);

    /****** Title bar's frame *******/
    QPolygon frame;

    frame << QPoint( 20, 4)
          << QPoint(width() -4, 4)
          << QPoint(width() -4, 32)
          << QPoint( 4, 32)
          << QPoint( 4, 20);

    painter.setPen(QPen(lightBlue));
    painter.setBrush(QBrush(linearGrad));

    painter.drawPolygon(frame);

    /****** Title bar's buttons area *******/
    QPolygon buttons;

    buttons << QPoint(width() - 80, 4)
          << QPoint(width() -4, 4)
          << QPoint(width() -4, 32)
          << QPoint(width() - 88, 32)
          << QPoint(width() - 88, 12);

    painter.setPen(QPen (lightBlue));
    painter.setBrush(QBrush (lightBlue));

    painter.drawPolygon(buttons);

    // Titre du haut
    m_Title.move(28,4);
    m_Title.resize(width() - 116, 29);

}

void windowtitlebar::paintEvent(QPaintEvent *event){

    Q_UNUSED(event);

    if(m_cache != NULL){

        QPainter painter(this);

        painter.drawPixmap(0, 0, *m_cache);
    }
}

void windowtitlebar::UpdateWindowTitle(){
    m_Title.setText(window()->windowTitle());

}

windowtitlebar::~windowtitlebar(){

}
