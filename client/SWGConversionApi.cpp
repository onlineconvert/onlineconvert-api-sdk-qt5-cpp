#include "SWGConversionApi.h"
#include "SWGHelpers.h"
#include "SWGModelFactory.h"

#include <QJsonArray>
#include <QJsonDocument>

namespace Swagger {
SWGConversionApi::SWGConversionApi() {}

SWGConversionApi::~SWGConversionApi() {}

SWGConversionApi::SWGConversionApi(QString host, QString basePath) {
    this->host = host;
    this->basePath = basePath;
}

void
SWGConversionApi::jobsJobIdConversionsGet(QString* token, QString* key, QString* jobId) {
    QString fullPath;
    fullPath.append(this->host).append(this->basePath).append("/jobs/{job_id}/conversions");

    
    QString jobIdPathParam("{"); jobIdPathParam.append("jobId").append("}");
    fullPath.replace(jobIdPathParam, stringValue(jobId));
    

    

    HttpRequestWorker *worker = new HttpRequestWorker();
    HttpRequestInput input(fullPath, "GET");

    

    

    
    // TODO: add header support
    
    // TODO: add header support
    

    connect(worker,
            &HttpRequestWorker::on_execution_finished,
            this,
            &SWGConversionApi::jobsJobIdConversionsGetCallback);

    worker->execute(&input);
}

void
SWGConversionApi::jobsJobIdConversionsGetCallback(HttpRequestWorker * worker) {
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

    emit jobsJobIdConversionsGetSignal(output);
    
}
void
SWGConversionApi::jobsJobIdConversionsPost(SWGConversion body, QString* token, QString* key, QString* jobId) {
    QString fullPath;
    fullPath.append(this->host).append(this->basePath).append("/jobs/{job_id}/conversions");

    
    QString jobIdPathParam("{"); jobIdPathParam.append("jobId").append("}");
    fullPath.replace(jobIdPathParam, stringValue(jobId));
    

    

    HttpRequestWorker *worker = new HttpRequestWorker();
    HttpRequestInput input(fullPath, "POST");

    

    
    
    
    QString output = body.asJson();
    input.request_body.append(output);
    

    
    // TODO: add header support
    
    // TODO: add header support
    

    connect(worker,
            &HttpRequestWorker::on_execution_finished,
            this,
            &SWGConversionApi::jobsJobIdConversionsPostCallback);

    worker->execute(&input);
}

void
SWGConversionApi::jobsJobIdConversionsPostCallback(HttpRequestWorker * worker) {
    QString msg;
    if (worker->error_type == QNetworkReply::NoError) {
        msg = QString("Success! %1 bytes").arg(worker->response.length());
    }
    else {
        msg = "Error: " + worker->error_str;
    }

    

    
    
    
    QString json(worker->response);
    SWGConversion* output = static_cast<SWGConversion*>(create(json, QString("SWGConversion")));
    
    
    

    worker->deleteLater();

    emit jobsJobIdConversionsPostSignal(output);
    
}
void
SWGConversionApi::jobsJobIdConversionsConversionIdGet(QString* token, QString* key, QString* jobId, QString* conversionId) {
    QString fullPath;
    fullPath.append(this->host).append(this->basePath).append("/jobs/{job_id}/conversions/{conversion_id}");

    
    QString jobIdPathParam("{"); jobIdPathParam.append("jobId").append("}");
    fullPath.replace(jobIdPathParam, stringValue(jobId));
    
    QString conversionIdPathParam("{"); conversionIdPathParam.append("conversionId").append("}");
    fullPath.replace(conversionIdPathParam, stringValue(conversionId));
    

    

    HttpRequestWorker *worker = new HttpRequestWorker();
    HttpRequestInput input(fullPath, "GET");

    

    

    
    // TODO: add header support
    
    // TODO: add header support
    

    connect(worker,
            &HttpRequestWorker::on_execution_finished,
            this,
            &SWGConversionApi::jobsJobIdConversionsConversionIdGetCallback);

    worker->execute(&input);
}

void
SWGConversionApi::jobsJobIdConversionsConversionIdGetCallback(HttpRequestWorker * worker) {
    QString msg;
    if (worker->error_type == QNetworkReply::NoError) {
        msg = QString("Success! %1 bytes").arg(worker->response.length());
    }
    else {
        msg = "Error: " + worker->error_str;
    }

    

    
    
    
    QString json(worker->response);
    SWGConversion* output = static_cast<SWGConversion*>(create(json, QString("SWGConversion")));
    
    
    

    worker->deleteLater();

    emit jobsJobIdConversionsConversionIdGetSignal(output);
    
}
void
SWGConversionApi::jobsJobIdConversionsConversionIdDelete(QString* token, QString* key, QString* jobId, QString* conversionId) {
    QString fullPath;
    fullPath.append(this->host).append(this->basePath).append("/jobs/{job_id}/conversions/{conversion_id}");

    
    QString jobIdPathParam("{"); jobIdPathParam.append("jobId").append("}");
    fullPath.replace(jobIdPathParam, stringValue(jobId));
    
    QString conversionIdPathParam("{"); conversionIdPathParam.append("conversionId").append("}");
    fullPath.replace(conversionIdPathParam, stringValue(conversionId));
    

    

    HttpRequestWorker *worker = new HttpRequestWorker();
    HttpRequestInput input(fullPath, "DELETE");

    

    

    
    // TODO: add header support
    
    // TODO: add header support
    

    connect(worker,
            &HttpRequestWorker::on_execution_finished,
            this,
            &SWGConversionApi::jobsJobIdConversionsConversionIdDeleteCallback);

    worker->execute(&input);
}

void
SWGConversionApi::jobsJobIdConversionsConversionIdDeleteCallback(HttpRequestWorker * worker) {
    QString msg;
    if (worker->error_type == QNetworkReply::NoError) {
        msg = QString("Success! %1 bytes").arg(worker->response.length());
    }
    else {
        msg = "Error: " + worker->error_str;
    }

    

    
    
    
    QString json(worker->response);
    SWGConversion* output = static_cast<SWGConversion*>(create(json, QString("SWGConversion")));
    
    
    

    worker->deleteLater();

    emit jobsJobIdConversionsConversionIdDeleteSignal(output);
    
}
} /* namespace Swagger */
