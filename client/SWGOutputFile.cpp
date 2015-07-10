
#include "SWGOutputFile.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace Swagger {


SWGOutputFile::SWGOutputFile(QString* json) {
    init();
    this->fromJson(*json);
}

SWGOutputFile::SWGOutputFile() {
    init();
}

SWGOutputFile::~SWGOutputFile() {
    this->cleanup();
}

void
SWGOutputFile::init() {
    id = new QString("");
    source = NULL;
    uri = new QString("");
    filename = new QString("");
    size = 0;
    created_at = NULL;
    
}

void
SWGOutputFile::cleanup() {
    if(id != NULL) {
        delete id;
    }
    if(source != NULL) {
        delete source;
    }
    if(uri != NULL) {
        delete uri;
    }
    if(filename != NULL) {
        delete filename;
    }
    
    if(created_at != NULL) {
        delete created_at;
    }
    
}

SWGOutputFile*
SWGOutputFile::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGOutputFile::fromJsonObject(QJsonObject &pJson) {
    setValue(&id, pJson["id"], "QString", "QString");
    setValue(&source, pJson["source"], "SWGObject", "SWGObject");
    setValue(&uri, pJson["uri"], "QString", "QString");
    setValue(&filename, pJson["filename"], "QString", "QString");
    setValue(&size, pJson["size"], "qint32", "");
    setValue(&created_at, pJson["created_at"], "QDateTime", "QDateTime");
    
}

QString
SWGOutputFile::asJson ()
{
    QJsonObject* obj = this->asJsonObject();
    
    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    return QString(bytes);
}

QJsonObject*
SWGOutputFile::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    
    
    toJsonValue(QString("id"), id, obj, QString("QString"));
    
    
    
    
    
    toJsonValue(QString("source"), source, obj, QString("SWGObject"));
    
    
    
    
    
    toJsonValue(QString("uri"), uri, obj, QString("QString"));
    
    
    
    
    
    toJsonValue(QString("filename"), filename, obj, QString("QString"));
    
    
    
    obj->insert("size", QJsonValue(size));
    
    
    toJsonValue(QString("created_at"), created_at, obj, QString("QDateTime"));
    
    
    
    

    return obj;
}

QString*
SWGOutputFile::getId() {
    return id;
}
void
SWGOutputFile::setId(QString* id) {
    this->id = id;
}

SWGObject*
SWGOutputFile::getSource() {
    return source;
}
void
SWGOutputFile::setSource(SWGObject* source) {
    this->source = source;
}

QString*
SWGOutputFile::getUri() {
    return uri;
}
void
SWGOutputFile::setUri(QString* uri) {
    this->uri = uri;
}

QString*
SWGOutputFile::getFilename() {
    return filename;
}
void
SWGOutputFile::setFilename(QString* filename) {
    this->filename = filename;
}

qint32
SWGOutputFile::getSize() {
    return size;
}
void
SWGOutputFile::setSize(qint32 size) {
    this->size = size;
}

QDateTime*
SWGOutputFile::getCreatedAt() {
    return created_at;
}
void
SWGOutputFile::setCreatedAt(QDateTime* created_at) {
    this->created_at = created_at;
}



} /* namespace Swagger */

