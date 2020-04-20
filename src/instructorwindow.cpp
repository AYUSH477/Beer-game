#include "instructorwindow.h"
#include "ui_instructorwindow.h"

#include "player.h"
#include "playerinterface.h"
#include "game.h"
#include "instructor.h"

#include <QIntValidator>
#include <QDoubleValidator>
#include <QDesktopWidget>

#include <iostream>

InstructorWindow::InstructorWindow(QWidget *parent) :
    QDialog(parent),
    parent(parent),
    ui(new Ui::InstructorWindow)
{
    ui->setupUi(this);
    QDoubleValidator* costValidator = new QDoubleValidator(0, 10, 2, this);
    costValidator->setNotation(QDoubleValidator::StandardNotation);

    ui->backlogCostIn->setValidator(costValidator);
    ui->factoryDelayIn->setValidator(new QIntValidator(1, 5, this));
    ui->holdingCostIn->setValidator(costValidator);
    ui->nWeeksIn->setValidator(new QIntValidator(1, 52, this));
    ui->orderDelayIn->setValidator(new QIntValidator(1, 5, this));
    ui->startInventoryIn->setValidator(new QIntValidator(0, 1000, this));

    Instructor* instructor = new Instructor();
    instructor->setInstrId(1);
    instructor->setInstrEmail("gamer@beergame.com");
    instructor->setInstrPassword("ankabanrid");
    instructor->setUi(ui);
    instructor->setWindowParent(parent);

    this->instructor = instructor;
}

InstructorWindow::~InstructorWindow()
{
    delete ui;
}

void InstructorWindow::on_startBtn_clicked()
{
    instructor->createGame();

    this->hide();
}
