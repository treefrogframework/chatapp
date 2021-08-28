#include "chatendpoint.h"
#include "chatlog.h"

#define TOPIC_NAME "foo"


bool ChatEndpoint::onOpen(const TSession &)
{
    subscribe(TOPIC_NAME);

    QList<ChatLog> logs = ChatLog::getAll();
    for (auto &log : logs) {
        sendText(log.message());
    }

    publish(TOPIC_NAME, QString(" [ New person joined ]\n"));

    startKeepAlive(300);
    return true;
}

void ChatEndpoint::onClose(int)
{
    unsubscribe(TOPIC_NAME);
    publish(TOPIC_NAME, QString(" [ A person left ]\n"));
}

void ChatEndpoint::onTextReceived(const QString &text)
{
    ChatLog::create(text);
    publish(TOPIC_NAME, text);

    ChatLog::removeOldLogs(30); // 30件残す
}

void ChatEndpoint::onBinaryReceived(const QByteArray &)
{ }

// Don't remove below this line
T_DEFINE_CONTROLLER(ChatEndpoint)
