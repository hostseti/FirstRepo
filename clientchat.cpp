#include "clientchat.h"
#include "ui_clientchat.h"
#include "serverchat.h"

ClientChat::ClientChat(const QString& _name, ServerChat *serv, QWidget *parent) :
    QWidget(parent), ui(new Ui::ClientChat)
{
    ui->setupUi(this);
    ui->te_common_msg->setReadOnly(true);

    name = _name;
    setWindowTitle(name);
    server = serv;

    auto hot_keys = new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_Return),
                                  ui->te_send_msg, nullptr, nullptr,
                                  Qt::WidgetShortcut);
    connect(hot_keys, &QShortcut::activated, this, &ClientChat::on_pb_send_msg_clicked);
}

ClientChat::~ClientChat()
{
    delete ui;
}

void ClientChat::on_pb_send_msg_clicked()
{
    QStringList list;
    list.append(name);
    list.append(ui->te_send_msg->toPlainText());

    server->send_message(list);
    ui->te_send_msg->clear();
    ui->te_send_msg->setFocus();
}

void ClientChat::update_message(const QStringList& str_msg)
{
    //Note: str_msg[0] = name, str_msg[1] = text, str_msg[2] = date

    QString color_font = (str_msg[0] == name) ? COLOR_FONT.MyName : COLOR_FONT.OtherName;
    auto& text = const_cast<QString&>(str_msg[1]);
    text.replace("\n", "<br>");

    ui->te_common_msg->insertHtml(QString("<font color=%3>%1 [%2]:</font><br>")
                                  .arg(str_msg[0]).arg(str_msg[2]).arg(color_font));

    ui->te_common_msg->insertHtml(QString("<font color=%2>%1</font><br><br>")
                                  .arg(text).arg(COLOR_FONT.Text));

    auto scrbar = ui->te_common_msg->verticalScrollBar();
    scrbar->setValue(scrbar->maximum());
}

void ClientChat::send_all_message(const QList<QStringList>& all_msg)
{
    for (auto& str_msg : all_msg)
    {
        update_message(str_msg);
    }
}

void ClientChat::closeEvent(QCloseEvent *event)
{
    server->delete_user_online(name);
    QWidget::closeEvent(event);
}
