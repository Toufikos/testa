#ifndef WINDOWTITLEBAR_H
#define WINDOWTITLEBAR_H

#include <QWidget>
#include <QPaintEvent>
#include <QLabel>


class windowtitlebar : public QWidget
{
    Q_OBJECT
public:
    windowtitlebar(QWidget *parent = 0);
    ~windowtitlebar();

protected:
    void resizeEvent(QResizeEvent *event);
    void paintEvent(QPaintEvent *event);

   private:
    QPixmap *m_cache;
    QLabel m_Title;

public slots:
    void UpdateWindowTitle();
};

#endif // WINDOWTITLEBAR_H
