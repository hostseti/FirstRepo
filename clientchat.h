#ifndef CLIENTCHAT_H
#define CLIENTCHAT_H

#include <common_header.h>

namespace Ui { class ClientChat; }

class ServerChat;
class ClientChat : public QWidget
{
    Q_OBJECT

public:
    explicit ClientChat(const QString&, ServerChat*, QWidget *parent = nullptr);
    ~ClientChat() override;

public:
    void update_message(const QStringList&);
    void send_all_message(const QList<QStringList>&);

private slots:
    void on_pb_send_msg_clicked();

private:
    void closeEvent(QCloseEvent*) override;
    struct {
        QString MyName = "green";
        QString OtherName = "red";
        QString Text = "black";
    } const COLOR_FONT;

    Ui::ClientChat *ui;
    ServerChat *server;
    QString name;
};

#endif // CLIENTCHAT_H
