#include "SWGOutputApi.h"
#include "SWGHelpers.h"
#include "SWGModelFactory.h"

#include <QJsonArray>
#include <QJsonDocument>

namespace Swagger {
SWGOutputApi::SWGOutputApi() {}

SWGOutputApi::~SWGOutputApi() {}

SWGOutputApi::SWGOutputApi(QString host, QString basePath) {
    this->host = host;
    this->basePath = basePath;
}

void
SWGOutputApi::jobsJobIdOutputGet(QString* conversionId, QString* inputId, QString* xOcToken, QString* xOcApiKey, QString* jobId) {
    QString fullPath;
    fullPath.append(this->host).append(this->basePath).append("/jobs/{job_id}/output");

    
    QString jobIdPathParam("{"); jobIdPathParam.append("jobId").append("}");
    fullPath.replace(jobIdPathParam, stringValue(jobId));
    

    
    
    if(fullPath.indexOf("?") > 0) 
      fullPath.append("&");
    else 
      fullPath.append("?");
    fullPath.append(QUrl::toPercentEncoding("conversionId"))
        .append("=")
        .append(QUrl::toPercentEncoding(stringValue(conversionId)));
    

    
    
    
    if(fullPath.indexOf("?") > 0) 
      fullPath.append("&");
    else 
      fullPath.append("?");
    fullPath.append(QUrl::toPercentEncoding("inputId"))
        .append("=")
        .append(QUrl::toPercentEncoding(stringValue(inputId)));
    

    
    

    HttpRequestWorker *worker = new HttpRequestWorker();
    HttpRequestInput input(fullPath, "GET");

    

    

    
    // TODO: add header support
    
    // TODO: add header support
    

    connect(worker,
            &HttpRequestWorker::on_execution_finished,
            this,
            &SWGOutputApi::jobsJobIdOutputGetCallback);

    worker->execute(&input);
}

void
SWGOutputApi::jobsJobIdOutputGetCallback(HttpRequestWorker * worker) {
    QString msg;
    if (worker->error_type == QNetworkReply::NoError) {
        msg = QString("Success! %1 bytes").arg(worker->response.length());
    }
    else {
        msg = "Error: " + worker->error_str;
    }

    
    QList<SWGOutputFile*>* output = new QList<SWGOutputFile*>();
    QString json(worker->response);
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonArray jsonArray = doc.array();

    foreach(QJsonValue obj, jsonArray) {
        SWGOutputFile* o = new SWGOutputFile();
        QJsonObject jv = obj.toObject();
        QJsonObject * ptr = (QJsonObject*)&jv;
        o->fromJsonObject(*ptr);
        output->append(o);
    }
    

    

    worker->deleteLater();

    emit jobsJobIdOutputGetSignal(output);
    
}
void
SWGOutputApi::jobsJobIdOutputFileIdGet(QString* xOcToken, QString* xOcApiKey, QString* jobId, QString* fileId) {
    QString fullPath;
    fullPath.append(this->host).append(this->basePath).append("/jobs/{job_id}/output/{file_id}");

    
    QString jobIdPathParam("{"); jobIdPathParam.append("jobId").append("}");
    fullPath.replace(jobIdPathParam, stringValue(jobId));
    
    QString fileIdPathParam("{"); fileIdPathParam.append("fileId").append("}");
    fullPath.replace(fileIdPathParam, stringValue(fileId));
    

    

    HttpRequestWorker *worker = new HttpRequestWorker();
    HttpRequestInput input(fullPath, "GET");

    

    

    
    // TODO: add header support
    
    // TODO: add header support
    

    connect(worker,
            &HttpRequestWorker::on_execution_finished,
            this,
            &SWGOutputApi::jobsJobIdOutputFileIdGetCallback);

    worker->execute(&input);
}

void
SWGOutputApi::jobsJobIdOutputFileIdGetCallback(HttpRequestWorker * worker) {
    QString msg;
    if (worker->error_type == QNetworkReply::NoError) {
        msg = QString("Success! %1 bytes").arg(worker->response.length());
    }
    else {
        msg = "Error: " + worker->error_str;
    }

    
    QList<SWGOutputFile*>* output = new QList<SWGOutputFile*>();
    QString json(worker->response);
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonArray jsonArray = doc.array();

    foreach(QJsonValue obj, jsonArray) {
        SWGOutputFile* o = new SWGOutputFile();
        QJsonObject jv = obj.toObject();
        QJsonObject * ptr = (QJsonObject*)&jv;
        o->fromJsonObject(*ptr);
        output->append(o);
    }
    

    

    worker->deleteLater();

    emit jobsJobIdOutputFileIdGetSignal(output);
    
}
void
SWGOutputApi::jobsJobIdOutputFileIdDelete(QString* xOcToken, QString* xOcApiKey, QString* jobId, QString* fileId) {
    QString fullPath;
    fullPath.append(this->host).append(this->basePath).append("/jobs/{job_id}/output/{file_id}");

    
    QString jobIdPathParam("{"); jobIdPathParam.append("jobId").append("}");
    fullPath.replace(jobIdPathParam, stringValue(jobId));
    
    QString fileIdPathParam("{"); fileIdPathParam.append("fileId").append("}");
    fullPath.replace(fileIdPathParam, stringValue(fileId));
    

    

    HttpRequestWorker *worker = new HttpRequestWorker();
    HttpRequestInput input(fullPath, "DELETE");

    

    

    
    // TODO: add header support
    
    // TODO: add header support
    

    connect(worker,
            &HttpRequestWorker::on_execution_finished,
            this,
            &SWGOutputApi::jobsJobIdOutputFileIdDeleteCallback);

    worker->execute(&input);
}

void
SWGOutputApi::jobsJobIdOutputFileIdDeleteCallback(HttpRequestWorker * worker) {
    QString msg;
    if (worker->error_type == QNetworkReply::NoError) {
        msg = QString("Success! %1 bytes").arg(worker->response.length());
    }
    else {
        msg = "Error: " + worker->error_str;
    }

    
    QList<SWGOutputFile*>* output = new QList<SWGOutputFile*>();
    QString json(worker->response);
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonArray jsonArray = doc.array();

    foreach(QJsonValue obj, jsonArray) {
        SWGOutputFile* o = new SWGOutputFile();
        QJsonObject jv = obj.toObject();
        QJsonObject * ptr = (QJsonObject*)&jv;
        o->fromJsonObject(*ptr);
        output->append(o);
    }
    

    

    worker->deleteLater();

    emit jobsJobIdOutputFileIdDeleteSignal(output);
    
}
} /* namespace Swagger */
