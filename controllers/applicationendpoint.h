#ifndef APPLICATIONENDPOINT_H
#define APPLICATIONENDPOINT_H

#include "TWebSocketEndpoint"


class T_CONTROLLER_EXPORT ApplicationEndpoint : public TWebSocketEndpoint
{
public:
    Q_INVOKABLE
    ApplicationEndpoint();
    ApplicationEndpoint(const ApplicationEndpoint &other);
    virtual ~ApplicationEndpoint() { }

protected:
    virtual bool onOpen(const TSession &session) override;
    virtual void onClose(int closeCode) override;
    virtual void onTextReceived(const QString &text) override;
    virtual void onBinaryReceived(const QByteArray &binary) override;
    virtual void onPing(const QByteArray &data) override;
    virtual void onPong(const QByteArray &data) override;
    virtual bool transactionEnabled() const override;
};

#endif // APPLICATIONENDPOINT_H
