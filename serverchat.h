#ifndef SERVERCHAT_H
#define SERVERCHAT_H

#include "common_header.h"

namespace Ui { class ServerChat; }

class ClientChat;
class ServerChat : public QWidget
{
    Q_OBJECT

public:
    ServerChat(QWidget *parent = nullptr);
    ~ServerChat() override;

    void send_message(const QStringList&);
    void delete_user_online(const QString&);

signals:
    void new_msg(const QStringList&);

private slots:
    void on_pb_register_user_clicked();
    void on_pb_remove_user_clicked();

private:
    void closeEvent(QCloseEvent*) override;

    Ui::ServerChat *ui;
    QHash<QString, QSharedPointer<ClientChat>> users_online;
    QList<QStringList> message_base;
};

#endif // SERVERCHAT_H
