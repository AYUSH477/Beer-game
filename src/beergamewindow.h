#ifndef BEERGAMEWINDOW_H
#define BEERGAMEWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class BeerGameWindow; }
QT_END_NAMESPACE

class BeerGameWindow : public QMainWindow
{
    Q_OBJECT

public:
    BeerGameWindow(QWidget *parent = nullptr);
    ~BeerGameWindow();

private slots:
    void on_guestBtn_clicked();

private:
    Ui::BeerGameWindow *ui;
};
#endif // BEERGAMEWINDOW_H
