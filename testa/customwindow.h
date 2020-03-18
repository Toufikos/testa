#ifndef CUSTOMWINDOW_H
#define CUSTOMWINDOW_H

#include <QWidget>
#include <QGridLayout>
#include "windowtitlebar.h"
#include <QPixmap>

class CustomWIndow : public QWidget
{
    Q_OBJECT
public:
    CustomWIndow(QWidget *parent = 0);
    ~CustomWIndow();
    void setWindowTitle(const QString &title);

protected:
    void showEvent(QShowEvent *event);
    void paintEvent(QPaintEvent *event);

 private:
    void CenterOnScreen();
    QGridLayout m_MainLayout;
    windowtitlebar m_TitleBar;

signals:
    void WindowTitleChanged();

};

#endif // CUSTOMWINDOW_H
