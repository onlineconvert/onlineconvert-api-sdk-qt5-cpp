
#include "SWGConversion.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace Swagger {


SWGConversion::SWGConversion(QString* json) {
    init();
    this->fromJson(*json);
}

SWGConversion::SWGConversion() {
    init();
}

SWGConversion::~SWGConversion() {
    this->cleanup();
}

void
SWGConversion::init() {
    id = new QString("");
    target = new QString("");
    category = new QString("");
    options = NULL;
    
}

void
SWGConversion::cleanup() {
    if(id != NULL) {
        delete id;
    }
    if(target != NULL) {
        delete target;
    }
    if(category != NULL) {
        delete category;
    }
    if(options != NULL) {
        delete options;
    }
    
}

SWGConversion*
SWGConversion::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGConversion::fromJsonObject(QJsonObject &pJson) {
    setValue(&id, pJson["id"], "QString", "QString");
    setValue(&target, pJson["target"], "QString", "QString");
    setValue(&category, pJson["category"], "QString", "QString");
    setValue(&options, pJson["options"], "SWGObject", "SWGObject");
    
}

QString
SWGConversion::asJson ()
{
    QJsonObject* obj = this->asJsonObject();
    
    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    return QString(bytes);
}

QJsonObject*
SWGConversion::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    
    
    toJsonValue(QString("id"), id, obj, QString("QString"));
    
    
    
    
    
    toJsonValue(QString("target"), target, obj, QString("QString"));
    
    
    
    
    
    toJsonValue(QString("category"), category, obj, QString("QString"));
    
    
    
    
    
    toJsonValue(QString("options"), options, obj, QString("SWGObject"));
    
    
    
    

    return obj;
}

QString*
SWGConversion::getId() {
    return id;
}
void
SWGConversion::setId(QString* id) {
    this->id = id;
}

QString*
SWGConversion::getTarget() {
    return target;
}
void
SWGConversion::setTarget(QString* target) {
    this->target = target;
}

QString*
SWGConversion::getCategory() {
    return category;
}
void
SWGConversion::setCategory(QString* category) {
    this->category = category;
}

SWGObject*
SWGConversion::getOptions() {
    return options;
}
void
SWGConversion::setOptions(SWGObject* options) {
    this->options = options;
}



} /* namespace Swagger */

