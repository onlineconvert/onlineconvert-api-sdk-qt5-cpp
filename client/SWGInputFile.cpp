
#include "SWGInputFile.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace Swagger {


SWGInputFile::SWGInputFile(QString* json) {
    init();
    this->fromJson(*json);
}

SWGInputFile::SWGInputFile() {
    init();
}

SWGInputFile::~SWGInputFile() {
    this->cleanup();
}

void
SWGInputFile::init() {
    id = new QString("");
    type = new QString("");
    source = new QString("");
    filename = new QString("");
    size = 0;
    created_at = NULL;
    modified_at = NULL;
    
}

void
SWGInputFile::cleanup() {
    if(id != NULL) {
        delete id;
    }
    if(type != NULL) {
        delete type;
    }
    if(source != NULL) {
        delete source;
    }
    if(filename != NULL) {
        delete filename;
    }
    
    if(created_at != NULL) {
        delete created_at;
    }
    if(modified_at != NULL) {
        delete modified_at;
    }
    
}

SWGInputFile*
SWGInputFile::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGInputFile::fromJsonObject(QJsonObject &pJson) {
    setValue(&id, pJson["id"], "QString", "QString");
    setValue(&type, pJson["type"], "QString", "QString");
    setValue(&source, pJson["source"], "QString", "QString");
    setValue(&filename, pJson["filename"], "QString", "QString");
    setValue(&size, pJson["size"], "qint32", "");
    setValue(&created_at, pJson["created_at"], "QDateTime", "QDateTime");
    setValue(&modified_at, pJson["modified_at"], "QDateTime", "QDateTime");
    
}

QString
SWGInputFile::asJson ()
{
    QJsonObject* obj = this->asJsonObject();
    
    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    return QString(bytes);
}

QJsonObject*
SWGInputFile::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    
    
    toJsonValue(QString("id"), id, obj, QString("QString"));
    
    
    
    
    
    toJsonValue(QString("type"), type, obj, QString("QString"));
    
    
    
    
    
    toJsonValue(QString("source"), source, obj, QString("QString"));
    
    
    
    
    
    toJsonValue(QString("filename"), filename, obj, QString("QString"));
    
    
    
    obj->insert("size", QJsonValue(size));
    
    
    toJsonValue(QString("created_at"), created_at, obj, QString("QDateTime"));
    
    
    
    
    
    toJsonValue(QString("modified_at"), modified_at, obj, QString("QDateTime"));
    
    
    
    

    return obj;
}

QString*
SWGInputFile::getId() {
    return id;
}
void
SWGInputFile::setId(QString* id) {
    this->id = id;
}

QString*
SWGInputFile::getType() {
    return type;
}
void
SWGInputFile::setType(QString* type) {
    this->type = type;
}

QString*
SWGInputFile::getSource() {
    return source;
}
void
SWGInputFile::setSource(QString* source) {
    this->source = source;
}

QString*
SWGInputFile::getFilename() {
    return filename;
}
void
SWGInputFile::setFilename(QString* filename) {
    this->filename = filename;
}

qint32
SWGInputFile::getSize() {
    return size;
}
void
SWGInputFile::setSize(qint32 size) {
    this->size = size;
}

QDateTime*
SWGInputFile::getCreatedAt() {
    return created_at;
}
void
SWGInputFile::setCreatedAt(QDateTime* created_at) {
    this->created_at = created_at;
}

QDateTime*
SWGInputFile::getModifiedAt() {
    return modified_at;
}
void
SWGInputFile::setModifiedAt(QDateTime* modified_at) {
    this->modified_at = modified_at;
}



} /* namespace Swagger */

