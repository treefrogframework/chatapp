#include <TreeFrogModel>
#include "chatlog.h"
#include "chatlogobject.h"

ChatLog::ChatLog()
    : TAbstractModel(), d(new ChatLogObject)
{
    d->id = 0;
    d->lock_revision = 0;
}

ChatLog::ChatLog(const ChatLog &other)
    : TAbstractModel(), d(new ChatLogObject(*other.d))
{ }

ChatLog::ChatLog(const ChatLogObject &object)
    : TAbstractModel(), d(new ChatLogObject(object))
{ }

ChatLog::~ChatLog()
{
    // If the reference count becomes 0,
    // the shared data object 'ChatLogObject' is deleted.
}

int ChatLog::id() const
{
    return d->id;
}

QString ChatLog::message() const
{
    return d->message;
}

void ChatLog::setMessage(const QString &message)
{
    d->message = message;
}

QString ChatLog::updatedAt() const
{
    return d->updated_at;
}

int ChatLog::lockRevision() const
{
    return d->lock_revision;
}

ChatLog &ChatLog::operator=(const ChatLog &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

ChatLog ChatLog::create(const QString &message)
{
    ChatLogObject obj;
    obj.message = message;
    if (!obj.create()) {
        return ChatLog();
    }
    return ChatLog(obj);
}

ChatLog ChatLog::create(const QVariantMap &values)
{
    ChatLog model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

ChatLog ChatLog::get(int id)
{
    TSqlORMapper<ChatLogObject> mapper;
    return ChatLog(mapper.findByPrimaryKey(id));
}

ChatLog ChatLog::get(int id, int lockRevision)
{
    TSqlORMapper<ChatLogObject> mapper;
    TCriteria cri;
    cri.add(ChatLogObject::Id, id);
    cri.add(ChatLogObject::LockRevision, lockRevision);
    return ChatLog(mapper.findFirst(cri));
}

int ChatLog::count()
{
    TSqlORMapper<ChatLogObject> mapper;
    return mapper.findCount();
}

QList<ChatLog> ChatLog::getAll()
{
    return tfGetModelListByCriteria<ChatLog, ChatLogObject>(TCriteria(), ChatLogObject::Id, Tf::AscendingOrder);
}

// QJsonArray ChatLog::getAllJson()
// {
//     QJsonArray array;
//     TSqlORMapper<ChatLogObject> mapper;

//     if (mapper.find() > 0) {
//         for (TSqlORMapperIterator<ChatLogObject> i(mapper); i.hasNext(); ) {
//             array.append(QJsonValue(QJsonObject::fromVariantMap(ChatLog(i.next()).toVariantMap())));
//         }
//     }
//     return array;
// }

void ChatLog::removeOldLogs(int remainingCount)
{
    int del = count() - remainingCount;
    if (del > 0) {
        TSqlORMapper<ChatLogObject> mapper;
        mapper.setSortOrder(ChatLogObject::Id, Tf::DescendingOrder);
        auto log = mapper.findFirst();
        int maxId = log.id;

        TCriteria ctr(ChatLogObject::Id, TSql::LessEqual, maxId - remainingCount);
        mapper.removeAll(ctr);
    }
}

TModelObject *ChatLog::modelData()
{
    return d.data();
}

const TModelObject *ChatLog::modelData() const
{
    return d.data();
}
