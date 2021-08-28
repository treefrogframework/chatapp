#ifndef CHATENDPOINT_H
#define CHATENDPOINT_H

#include "applicationendpoint.h"

class T_CONTROLLER_EXPORT ChatEndpoint : public ApplicationEndpoint
{
    Q_OBJECT
protected:
    bool onOpen(const TSession &session) override;
    void onClose(int closeCode) override;
    void onTextReceived(const QString &text) override;
    void onBinaryReceived(const QByteArray &binary) override;
};

#endif // CHATENDPOINT_H
