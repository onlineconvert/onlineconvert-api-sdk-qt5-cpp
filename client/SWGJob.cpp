
#include "SWGJob.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace Swagger {


SWGJob::SWGJob(QString* json) {
    init();
    this->fromJson(*json);
}

SWGJob::SWGJob() {
    init();
}

SWGJob::~SWGJob() {
    this->cleanup();
}

void
SWGJob::init() {
    id = new QString("");
    token = new QString("");
    type = new QString("");
    status = new SWGStatus();
    process = false;
    conversion = new QList<SWGConversion*>();
    input = new QList<SWGInputFile*>();
    callback = new QString("");
    server = new QString("");
    created_at = NULL;
    modified_at = NULL;
    
}

void
SWGJob::cleanup() {
    if(id != NULL) {
        delete id;
    }
    if(token != NULL) {
        delete token;
    }
    if(type != NULL) {
        delete type;
    }
    if(status != NULL) {
        delete status;
    }
    
    if(conversion != NULL) {
        QList<SWGConversion*>* arr = conversion;
        foreach(SWGConversion* o, *arr) {
            delete o;
        }
        delete conversion;
    }
    if(input != NULL) {
        QList<SWGInputFile*>* arr = input;
        foreach(SWGInputFile* o, *arr) {
            delete o;
        }
        delete input;
    }
    if(callback != NULL) {
        delete callback;
    }
    if(server != NULL) {
        delete server;
    }
    if(created_at != NULL) {
        delete created_at;
    }
    if(modified_at != NULL) {
        delete modified_at;
    }
    
}

SWGJob*
SWGJob::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGJob::fromJsonObject(QJsonObject &pJson) {
    setValue(&id, pJson["id"], "QString", "QString");
    setValue(&token, pJson["token"], "QString", "QString");
    setValue(&type, pJson["type"], "QString", "QString");
    setValue(&status, pJson["status"], "SWGStatus", "SWGStatus");
    setValue(&process, pJson["process"], "bool", "");
    setValue(&conversion, pJson["conversion"], "QList", "SWGConversion");
    setValue(&input, pJson["input"], "QList", "SWGInputFile");
    setValue(&callback, pJson["callback"], "QString", "QString");
    setValue(&server, pJson["server"], "QString", "QString");
    setValue(&created_at, pJson["created_at"], "QDateTime", "QDateTime");
    setValue(&modified_at, pJson["modified_at"], "QDateTime", "QDateTime");
    
}

QString
SWGJob::asJson ()
{
    QJsonObject* obj = this->asJsonObject();
    
    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    return QString(bytes);
}

QJsonObject*
SWGJob::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    
    
    toJsonValue(QString("id"), id, obj, QString("QString"));
    
    
    
    
    
    toJsonValue(QString("token"), token, obj, QString("QString"));
    
    
    
    
    
    toJsonValue(QString("type"), type, obj, QString("QString"));
    
    
    
    
    
    toJsonValue(QString("status"), status, obj, QString("SWGStatus"));
    
    
    
    obj->insert("process", QJsonValue(process));
    
    
    QList<SWGConversion*>* conversionList = conversion;
    QJsonArray conversionJsonArray;
    toJsonArray((QList<void*>*)conversion, &conversionJsonArray, "conversion", "SWGConversion");

    obj->insert("conversion", conversionJsonArray);
    
    
    
    
    QList<SWGInputFile*>* inputList = input;
    QJsonArray inputJsonArray;
    toJsonArray((QList<void*>*)input, &inputJsonArray, "input", "SWGInputFile");

    obj->insert("input", inputJsonArray);
    
    
    
    
    toJsonValue(QString("callback"), callback, obj, QString("QString"));
    
    
    
    
    
    toJsonValue(QString("server"), server, obj, QString("QString"));
    
    
    
    
    
    toJsonValue(QString("created_at"), created_at, obj, QString("QDateTime"));
    
    
    
    
    
    toJsonValue(QString("modified_at"), modified_at, obj, QString("QDateTime"));
    
    
    
    

    return obj;
}

QString*
SWGJob::getId() {
    return id;
}
void
SWGJob::setId(QString* id) {
    this->id = id;
}

QString*
SWGJob::getToken() {
    return token;
}
void
SWGJob::setToken(QString* token) {
    this->token = token;
}

QString*
SWGJob::getType() {
    return type;
}
void
SWGJob::setType(QString* type) {
    this->type = type;
}

SWGStatus*
SWGJob::getStatus() {
    return status;
}
void
SWGJob::setStatus(SWGStatus* status) {
    this->status = status;
}

bool
SWGJob::getProcess() {
    return process;
}
void
SWGJob::setProcess(bool process) {
    this->process = process;
}

QList<SWGConversion*>*
SWGJob::getConversion() {
    return conversion;
}
void
SWGJob::setConversion(QList<SWGConversion*>* conversion) {
    this->conversion = conversion;
}

QList<SWGInputFile*>*
SWGJob::getInput() {
    return input;
}
void
SWGJob::setInput(QList<SWGInputFile*>* input) {
    this->input = input;
}

QString*
SWGJob::getCallback() {
    return callback;
}
void
SWGJob::setCallback(QString* callback) {
    this->callback = callback;
}

QString*
SWGJob::getServer() {
    return server;
}
void
SWGJob::setServer(QString* server) {
    this->server = server;
}

QDateTime*
SWGJob::getCreatedAt() {
    return created_at;
}
void
SWGJob::setCreatedAt(QDateTime* created_at) {
    this->created_at = created_at;
}

QDateTime*
SWGJob::getModifiedAt() {
    return modified_at;
}
void
SWGJob::setModifiedAt(QDateTime* modified_at) {
    this->modified_at = modified_at;
}



} /* namespace Swagger */

