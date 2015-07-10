
#include "SWGThread.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace Swagger {


SWGThread::SWGThread(QString* json) {
    init();
    this->fromJson(*json);
}

SWGThread::SWGThread() {
    init();
}

SWGThread::~SWGThread() {
    this->cleanup();
}

void
SWGThread::init() {
    hash = new QString("");
    status = 0;
    info = new QString("");
    created_at = NULL;
    modified_at = NULL;
    
}

void
SWGThread::cleanup() {
    if(hash != NULL) {
        delete hash;
    }
    
    if(info != NULL) {
        delete info;
    }
    if(created_at != NULL) {
        delete created_at;
    }
    if(modified_at != NULL) {
        delete modified_at;
    }
    
}

SWGThread*
SWGThread::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGThread::fromJsonObject(QJsonObject &pJson) {
    setValue(&hash, pJson["hash"], "QString", "QString");
    setValue(&status, pJson["status"], "qint32", "");
    setValue(&info, pJson["info"], "QString", "QString");
    setValue(&created_at, pJson["created_at"], "QDateTime", "QDateTime");
    setValue(&modified_at, pJson["modified_at"], "QDateTime", "QDateTime");
    
}

QString
SWGThread::asJson ()
{
    QJsonObject* obj = this->asJsonObject();
    
    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    return QString(bytes);
}

QJsonObject*
SWGThread::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    
    
    toJsonValue(QString("hash"), hash, obj, QString("QString"));
    
    
    
    obj->insert("status", QJsonValue(status));
    
    
    toJsonValue(QString("info"), info, obj, QString("QString"));
    
    
    
    
    
    toJsonValue(QString("created_at"), created_at, obj, QString("QDateTime"));
    
    
    
    
    
    toJsonValue(QString("modified_at"), modified_at, obj, QString("QDateTime"));
    
    
    
    

    return obj;
}

QString*
SWGThread::getHash() {
    return hash;
}
void
SWGThread::setHash(QString* hash) {
    this->hash = hash;
}

qint32
SWGThread::getStatus() {
    return status;
}
void
SWGThread::setStatus(qint32 status) {
    this->status = status;
}

QString*
SWGThread::getInfo() {
    return info;
}
void
SWGThread::setInfo(QString* info) {
    this->info = info;
}

QDateTime*
SWGThread::getCreatedAt() {
    return created_at;
}
void
SWGThread::setCreatedAt(QDateTime* created_at) {
    this->created_at = created_at;
}

QDateTime*
SWGThread::getModifiedAt() {
    return modified_at;
}
void
SWGThread::setModifiedAt(QDateTime* modified_at) {
    this->modified_at = modified_at;
}



} /* namespace Swagger */

