#include "serverchat.h"
#include "ui_serverchat.h"
#include "clientchat.h"

ServerChat::ServerChat(QWidget *parent) : QWidget(parent),
    ui(new Ui::ServerChat)
{
    ui->setupUi(this);

    connect(ui->le_login, &QLineEdit::returnPressed,
            this, &ServerChat::on_pb_register_user_clicked);
}

ServerChat::~ServerChat()
{
    delete ui;
}

void ServerChat::on_pb_register_user_clicked()
{
    QString name = ui->le_login->text();
    if(name == "") return;

    if(users_online.contains(name))
    {
        QMessageBox::information(this, "Уведомление",
                                 "В чате уже существует пользователь с таким именем.");
        ui->le_login->clear();
        return;
    }

    QSharedPointer<ClientChat> p_user(new ClientChat(name, this));

    connect(this, &ServerChat::new_msg, p_user.get(), &ClientChat::update_message);

    users_online.insert(name, p_user);
    p_user->send_all_message(message_base);
    p_user->show();

    ui->comboBox->addItem(name);
    ui->le_login->clear();
    ui->le_login->setFocus();
    activateWindow();
}

void ServerChat::on_pb_remove_user_clicked()
{
    QString name = ui->comboBox->currentText();
    delete_user_online(name);
}

void ServerChat::send_message(const QStringList& msg)
{
    if(msg[1].isEmpty()) return;

    auto& msg_str = const_cast<QStringList&>(msg);
    QString cur_time = QDateTime::currentDateTime().toString("dd MMMM yyyy hh:mm:ss");
    msg_str.append(cur_time);
    message_base.append(msg_str);

    emit new_msg(msg_str);
}

void ServerChat::delete_user_online(const QString& name)
{
    auto&& iter = users_online.find(name);
    if(iter != users_online.end())
    {
        users_online.erase(iter);
        ui->comboBox->removeItem(ui->comboBox->findText(name));
    }
}

void ServerChat::closeEvent(QCloseEvent *event)
{
    users_online.clear();
    QWidget::closeEvent(event);
}
