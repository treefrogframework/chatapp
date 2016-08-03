#ifndef CHATLOGOBJECT_H
#define CHATLOGOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT ChatLogObject : public TSqlObject, public QSharedData
{
public:
    int id;
    QString message;
    QString updated_at;
    int lock_revision;

    enum PropertyIndex {
        Id = 0,
        Message,
        UpdatedAt,
        LockRevision,
    };

    int primaryKeyIndex() const { return Id; }
    int autoValueIndex() const { return Id; }
    QString tableName() const { return QLatin1String("chat_log"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int id READ getid WRITE setid)
    T_DEFINE_PROPERTY(int, id)
    Q_PROPERTY(QString message READ getmessage WRITE setmessage)
    T_DEFINE_PROPERTY(QString, message)
    Q_PROPERTY(QString updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QString, updated_at)
    Q_PROPERTY(int lock_revision READ getlock_revision WRITE setlock_revision)
    T_DEFINE_PROPERTY(int, lock_revision)
};

#endif // CHATLOGOBJECT_H
