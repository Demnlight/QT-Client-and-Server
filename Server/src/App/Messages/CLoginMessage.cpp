#include "CLoginMessage.h"
#include "../../PostgreSQL/CDataBaseConnector.h"

#include <string>

QJsonObject CLoginMessage::Handle(const QJsonObject &source, CDataBaseConnector *connector)
{
    QJsonObject jAnswer = QJsonObject();

    pqxx::work work(*connector->GetConnection());

    QString Username = source["login"].toString();
    QString Password = source["password"].toString();

    QString CheckUserScript = QString("SELECT login FROM users WHERE EXISTS (SELECT * FROM Users WHERE login = '%1' AND password = '%2')").arg(Username, Password);

    pqxx::result R = work.exec(CheckUserScript.toStdString());

    if (R.columns() <= 0)
    {
        qDebug() << "User not found";
    }
    else
    {
        for (auto const &row : R)
        {
            for (auto const &field : row)
            {
                jAnswer["token"] = field.c_str();
            }
        }

        //work.exec("CREATE TABLE IF NOT EXISTS users_tokens (login VARCHAR(32), token VARCHAR(32), last_login TIMESTAMP DEFAULT CURRENT_TIMESTAMP);");
        //work.exec(QString("INSERT INTO users_tokens (login, token) VALUES( '%1', '%2' );").arg(Username, jAnswer["token"].toString()).toStdString());
    }
    work.commit();

    return jAnswer;
}