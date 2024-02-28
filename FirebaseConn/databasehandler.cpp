#include "databasehandler.h"

#include <QNetworkRequest>
#include <QDebug>

DatabaseHandler::DatabaseHandler(QObject *parent)
    : QObject{parent}
{
    //11. Add this
    m_networkManager = new QNetworkAccessManager(this);

    //Here the new QNetworkAccessManager is now the parent whilw the m_network Manager becomes the child (this is in line 7)
    //Now whenever the db handler is removed, all the children in tree will also get removed

    // go back to header for step 12


    //18. add    m_networkReply = m_networkManager->get(QNetworkRequest(QUrl("URL")));
    m_networkReply = m_networkManager->get(QNetworkRequest(QUrl("https://qt-connectedrtdb-default-rtdb.asia-southeast1.firebasedatabase.app/Pets.json")));
//  NOTE: go to firebase rest api documentation and u can see that we need to add a name of the entry.json at the end of link
    //Get what the main is where there are children in the data for example Pets.json

//23. Add a connection
    connect(m_networkReply, &QNetworkReply::readyRead,this, &DatabaseHandler::networkReplyReadyRead);
    //REMOVE THE () AT THE END TO AVOID ERROR CANNOT TAKE THE ADDERSS OF RVALUE

}

DatabaseHandler::~DatabaseHandler()
{//14. Add m_networkManager -> deleteLater();
    m_networkManager -> deleteLater();
}

void DatabaseHandler::networkReplyReadyRead()
{
    qDebug()<<m_networkReply->readAll(); //22
}


//15. go to RTDB and copy the link shown by google
//16.#include <QNetworkRequest>
//17. #include <QDebug>
