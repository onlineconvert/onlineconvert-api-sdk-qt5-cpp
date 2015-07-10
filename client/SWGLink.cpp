
#include "SWGLink.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace Swagger {


SWGLink::SWGLink(QString* json) {
    init();
    this->fromJson(*json);
}

SWGLink::SWGLink() {
    init();
}

SWGLink::~SWGLink() {
    this->cleanup();
}

void
SWGLink::init() {
    id = new QString("");
    uri = new QString("");
    
}

void
SWGLink::cleanup() {
    if(id != NULL) {
        delete id;
    }
    if(uri != NULL) {
        delete uri;
    }
    
}

SWGLink*
SWGLink::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGLink::fromJsonObject(QJsonObject &pJson) {
    setValue(&id, pJson["id"], "QString", "QString");
    setValue(&uri, pJson["uri"], "QString", "QString");
    
}

QString
SWGLink::asJson ()
{
    QJsonObject* obj = this->asJsonObject();
    
    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    return QString(bytes);
}

QJsonObject*
SWGLink::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    
    
    toJsonValue(QString("id"), id, obj, QString("QString"));
    
    
    
    
    
    toJsonValue(QString("uri"), uri, obj, QString("QString"));
    
    
    
    

    return obj;
}

QString*
SWGLink::getId() {
    return id;
}
void
SWGLink::setId(QString* id) {
    this->id = id;
}

QString*
SWGLink::getUri() {
    return uri;
}
void
SWGLink::setUri(QString* uri) {
    this->uri = uri;
}



} /* namespace Swagger */

