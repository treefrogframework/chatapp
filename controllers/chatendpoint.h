#ifndef CHATENDPOINT_H
#define CHATENDPOINT_H

#include "applicationendpoint.h"

class T_CONTROLLER_EXPORT ChatEndpoint : public ApplicationEndpoint
{
public:
    ChatEndpoint() { }
    ChatEndpoint(const ChatEndpoint &other);

protected:
    bool onOpen(const TSession &session);
    void onClose(int closeCode);
    void onTextReceived(const QString &text);
    void onBinaryReceived(const QByteArray &binary);
};

T_DECLARE_CONTROLLER(ChatEndpoint, chatendpoint)

#endif // CHATENDPOINT_H
