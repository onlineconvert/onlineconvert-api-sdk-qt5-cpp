
#include "SWGStatus.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace Swagger {


SWGStatus::SWGStatus(QString* json) {
    init();
    this->fromJson(*json);
}

SWGStatus::SWGStatus() {
    init();
}

SWGStatus::~SWGStatus() {
    this->cleanup();
}

void
SWGStatus::init() {
    code = new QString("");
    info = new QString("");
    
}

void
SWGStatus::cleanup() {
    if(code != NULL) {
        delete code;
    }
    if(info != NULL) {
        delete info;
    }
    
}

SWGStatus*
SWGStatus::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGStatus::fromJsonObject(QJsonObject &pJson) {
    setValue(&code, pJson["code"], "QString", "QString");
    setValue(&info, pJson["info"], "QString", "QString");
    
}

QString
SWGStatus::asJson ()
{
    QJsonObject* obj = this->asJsonObject();
    
    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    return QString(bytes);
}

QJsonObject*
SWGStatus::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    
    
    toJsonValue(QString("code"), code, obj, QString("QString"));
    
    
    
    
    
    toJsonValue(QString("info"), info, obj, QString("QString"));
    
    
    
    

    return obj;
}

QString*
SWGStatus::getCode() {
    return code;
}
void
SWGStatus::setCode(QString* code) {
    this->code = code;
}

QString*
SWGStatus::getInfo() {
    return info;
}
void
SWGStatus::setInfo(QString* info) {
    this->info = info;
}



} /* namespace Swagger */

