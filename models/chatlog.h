#ifndef CHATLOG_H
#define CHATLOG_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class ChatLogObject;
class QJsonArray;


class T_MODEL_EXPORT ChatLog : public TAbstractModel
{
public:
    ChatLog();
    ChatLog(const ChatLog &other);
    ChatLog(const ChatLogObject &object);
    ~ChatLog();

    int id() const;
    QString message() const;
    void setMessage(const QString &message);
    QString updatedAt() const;
    int lockRevision() const;
    ChatLog &operator=(const ChatLog &other);

    bool create() { return TAbstractModel::create(); }
    bool update() { return TAbstractModel::update(); }
    bool save()   { return TAbstractModel::save(); }
    bool remove() { return TAbstractModel::remove(); }

    static ChatLog create(const QString &message);
    static ChatLog create(const QVariantMap &values);
    static ChatLog get(int id);
    static ChatLog get(int id, int lockRevision);
    static int count();
    static QList<ChatLog> getAll();
    //static QJsonArray getAllJson();
    static void removeOldLogs(int remainingCount);

private:
    QSharedDataPointer<ChatLogObject> d;

    TModelObject *modelData();
    const TModelObject *modelData() const;
};

Q_DECLARE_METATYPE(ChatLog)
Q_DECLARE_METATYPE(QList<ChatLog>)

#endif // CHATLOG_H
