#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H

#include <string>
#include <vector>

#include "game.h"
#include "instructorwindow.h"
#include "ui_instructorwindow.h"

/**
 * @brief what does this class do?
*/

class Instructor
{
private:
    int instrId;
    std::string instrEmail;
    std::string instrPassword;

    std::vector<Game> games;
    Ui::InstructorWindow *ui;
    QWidget* uiParent;

public: // every function here has been made void just for making template, change it accordingly

    void showGameStatus();

    int createGame();

    std::vector<Game> createGames(int numberOfGames);

    void setUi(Ui::InstructorWindow* ui);

    void setWindowParent(QWidget* parent);

    //// 
    // TEST
    ////

    void setInstrEmail(std::string instrEmail);

    void setInstrPassword(std::string instrPassword);

    void setInstrId(int instrID);


    std::string getInstrEmail();

    std::string getInstrPassword();

    int getInstrId();
};

#endif //INSTRUCTOR_H
