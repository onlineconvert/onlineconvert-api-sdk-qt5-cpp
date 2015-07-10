#include "SWGInformationApi.h"
#include "SWGHelpers.h"
#include "SWGModelFactory.h"

#include <QJsonArray>
#include <QJsonDocument>

namespace Swagger {
SWGInformationApi::SWGInformationApi() {}

SWGInformationApi::~SWGInformationApi() {}

SWGInformationApi::SWGInformationApi(QString host, QString basePath) {
    this->host = host;
    this->basePath = basePath;
}

void
SWGInformationApi::conversionsGet(QString* category, QString* target, SWGNumber* page) {
    QString fullPath;
    fullPath.append(this->host).append(this->basePath).append("/conversions");

    

    
    
    if(fullPath.indexOf("?") > 0) 
      fullPath.append("&");
    else 
      fullPath.append("?");
    fullPath.append(QUrl::toPercentEncoding("category"))
        .append("=")
        .append(QUrl::toPercentEncoding(stringValue(category)));
    

    
    
    
    if(fullPath.indexOf("?") > 0) 
      fullPath.append("&");
    else 
      fullPath.append("?");
    fullPath.append(QUrl::toPercentEncoding("target"))
        .append("=")
        .append(QUrl::toPercentEncoding(stringValue(target)));
    

    
    
    
    if(fullPath.indexOf("?") > 0) 
      fullPath.append("&");
    else 
      fullPath.append("?");
    fullPath.append(QUrl::toPercentEncoding("page"))
        .append("=")
        .append(QUrl::toPercentEncoding(stringValue(page)));
    

    
    

    HttpRequestWorker *worker = new HttpRequestWorker();
    HttpRequestInput input(fullPath, "GET");

    

    

    

    connect(worker,
            &HttpRequestWorker::on_execution_finished,
            this,
            &SWGInformationApi::conversionsGetCallback);

    worker->execute(&input);
}

void
SWGInformationApi::conversionsGetCallback(HttpRequestWorker * worker) {
    QString msg;
    if (worker->error_type == QNetworkReply::NoError) {
        msg = QString("Success! %1 bytes").arg(worker->response.length());
    }
    else {
        msg = "Error: " + worker->error_str;
    }

    
    QList<SWGConversion*>* output = new QList<SWGConversion*>();
    QString json(worker->response);
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonArray jsonArray = doc.array();

    foreach(QJsonValue obj, jsonArray) {
        SWGConversion* o = new SWGConversion();
        QJsonObject jv = obj.toObject();
        QJsonObject * ptr = (QJsonObject*)&jv;
        o->fromJsonObject(*ptr);
        output->append(o);
    }
    

    

    worker->deleteLater();

    emit conversionsGetSignal(output);
    
}
void
SWGInformationApi::statusesGet() {
    QString fullPath;
    fullPath.append(this->host).append(this->basePath).append("/statuses");

    

    

    HttpRequestWorker *worker = new HttpRequestWorker();
    HttpRequestInput input(fullPath, "GET");

    

    

    

    connect(worker,
            &HttpRequestWorker::on_execution_finished,
            this,
            &SWGInformationApi::statusesGetCallback);

    worker->execute(&input);
}

void
SWGInformationApi::statusesGetCallback(HttpRequestWorker * worker) {
    QString msg;
    if (worker->error_type == QNetworkReply::NoError) {
        msg = QString("Success! %1 bytes").arg(worker->response.length());
    }
    else {
        msg = "Error: " + worker->error_str;
    }

    
    QList<SWGStatus*>* output = new QList<SWGStatus*>();
    QString json(worker->response);
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonArray jsonArray = doc.array();

    foreach(QJsonValue obj, jsonArray) {
        SWGStatus* o = new SWGStatus();
        QJsonObject jv = obj.toObject();
        QJsonObject * ptr = (QJsonObject*)&jv;
        o->fromJsonObject(*ptr);
        output->append(o);
    }
    

    

    worker->deleteLater();

    emit statusesGetSignal(output);
    
}
} /* namespace Swagger */
