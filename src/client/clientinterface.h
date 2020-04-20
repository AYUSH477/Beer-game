/**
 * @brief User interface to connect to the server and start placing orders.
 * This class is responsible for displaying a user interface for the player to communicate
 * with the server. It provides a user interface to connect to the server and to login and finally place orders.
 *
 */

#ifndef CLIENTINTERFACE_H
#define CLIENTINTERFACE_H
#include <QWidget>
#include "playerclient.h"
namespace Ui {
class ClientInterface;
}
class ClientInterface : public QWidget
{
    Q_OBJECT
    Q_DISABLE_COPY(ClientInterface)
public:
    explicit ClientInterface(QWidget *parent = nullptr);
    ~ClientInterface();
private:
    Ui::ClientInterface *ui;
    PlayerClient *m_PlayerClient;
    QString m_lastUserName;
private slots:
    /**
     * @brief Attempts to connect to the server
     * This function provides a user interface to connect to the
     * server by taking in the IP address and port numbers as input.
     *
     */
    void attemptConnection();

    /**
     * @brief Displays a dialog window to enter the role and gameId in
     * This function runs as soon as the connection to the server is established. It displays
     * a form dialog window for the user to enter the game ID and the role into. If the user enters
     * a valid game Id and role, the user can now place orders.
     */
    void connectedToServer();

    /**
     * @brief Sends login data to the server.
     * This function calls the PlayerClient class's attemptLogin() method which
     * in turn sends the entered login data to the server
     * \param GameId: The id of the game that the user wants to connect to
     * \param role: the role that the player wants to take in the game
     *
     */
    void attemptLogin(const int &GameId, const int &role);
    /**
     * @brief Sets the player role name once logged in.
     * This function runs once the player is logged in and is in the game. It sets the player role name.
    */
    void loggedIn();
    /**
     * @brief Login failure
     * \param reason Reason for login failure
     *
     */

    void loginFailed(const QString &reason);

    /**
     * @brief This function updates the user interface once the
     * message is received
     * \param sender the UI label to update
     * \param text The text to update the Ui label to
     */

    void messageReceived(const QString &sender, const QString &text);
    /**
     * @brief sends order message to the server.
     * This function is called once the place order button is pressed and
     * sends the text entered to the server
     */
    void sendMessage();
    /**
     * @brief Connection to the server is lost.
     * This function is called when the connection to the server is loast
     *
     */
    void disconnectedFromServer();

};
#endif // CLIENTINTERFACE_H
