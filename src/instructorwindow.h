#ifndef INSTRUCTORWINDOW_H
#define INSTRUCTORWINDOW_H

#include <QDialog>

#include "instructor.h"

class Instructor;

namespace Ui {
class InstructorWindow;
}

class InstructorWindow : public QDialog
{
    Q_OBJECT

public:
    explicit InstructorWindow(QWidget *parent = nullptr);
    ~InstructorWindow();
    QWidget *parent;

private slots:
    void on_startBtn_clicked();

private:
    Instructor* instructor;
    Ui::InstructorWindow *ui;
};

#endif // INSTRUCTORWINDOW_H
