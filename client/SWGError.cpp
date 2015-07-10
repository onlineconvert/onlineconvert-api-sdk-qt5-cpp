
#include "SWGError.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace Swagger {


SWGError::SWGError(QString* json) {
    init();
    this->fromJson(*json);
}

SWGError::SWGError() {
    init();
}

SWGError::~SWGError() {
    this->cleanup();
}

void
SWGError::init() {
    code = 0;
    message = new QString("");
    errors = NULL;
    
}

void
SWGError::cleanup() {
    
    if(message != NULL) {
        delete message;
    }
    if(errors != NULL) {
        delete errors;
    }
    
}

SWGError*
SWGError::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGError::fromJsonObject(QJsonObject &pJson) {
    setValue(&code, pJson["code"], "qint32", "");
    setValue(&message, pJson["message"], "QString", "QString");
    setValue(&errors, pJson["errors"], "SWGObject", "SWGObject");
    
}

QString
SWGError::asJson ()
{
    QJsonObject* obj = this->asJsonObject();
    
    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    return QString(bytes);
}

QJsonObject*
SWGError::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    obj->insert("code", QJsonValue(code));
    
    
    toJsonValue(QString("message"), message, obj, QString("QString"));
    
    
    
    
    
    toJsonValue(QString("errors"), errors, obj, QString("SWGObject"));
    
    
    
    

    return obj;
}

qint32
SWGError::getCode() {
    return code;
}
void
SWGError::setCode(qint32 code) {
    this->code = code;
}

QString*
SWGError::getMessage() {
    return message;
}
void
SWGError::setMessage(QString* message) {
    this->message = message;
}

SWGObject*
SWGError::getErrors() {
    return errors;
}
void
SWGError::setErrors(SWGObject* errors) {
    this->errors = errors;
}



} /* namespace Swagger */

