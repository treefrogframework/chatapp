#ifndef CHATENDPOINT_H
#define CHATENDPOINT_H

#include "applicationendpoint.h"

class T_CONTROLLER_EXPORT ChatEndpoint : public ApplicationEndpoint
{
    Q_OBJECT
public:
    Q_INVOKABLE
    ChatEndpoint() : ApplicationEndpoint() {}
    ChatEndpoint(const ChatEndpoint &other);

protected:
    bool onOpen(const TSession &session) override;
    void onClose(int closeCode) override;
    void onTextReceived(const QString &text) override;
    void onBinaryReceived(const QByteArray &binary) override;
};

T_DECLARE_CONTROLLER(ChatEndpoint, chatendpoint)

#endif // CHATENDPOINT_H
