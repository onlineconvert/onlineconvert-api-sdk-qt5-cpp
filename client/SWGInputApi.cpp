#include "SWGInputApi.h"
#include "SWGHelpers.h"
#include "SWGModelFactory.h"

#include <QJsonArray>
#include <QJsonDocument>

namespace Swagger {
SWGInputApi::SWGInputApi() {}

SWGInputApi::~SWGInputApi() {}

SWGInputApi::SWGInputApi(QString host, QString basePath) {
    this->host = host;
    this->basePath = basePath;
}

void
SWGInputApi::jobsJobIdInputGet(QString* xOcToken, QString* xOcApiKey, QString* jobId) {
    QString fullPath;
    fullPath.append(this->host).append(this->basePath).append("/jobs/{job_id}/input");

    
    QString jobIdPathParam("{"); jobIdPathParam.append("jobId").append("}");
    fullPath.replace(jobIdPathParam, stringValue(jobId));
    

    

    HttpRequestWorker *worker = new HttpRequestWorker();
    HttpRequestInput input(fullPath, "GET");

    

    

    
    // TODO: add header support
    
    // TODO: add header support
    

    connect(worker,
            &HttpRequestWorker::on_execution_finished,
            this,
            &SWGInputApi::jobsJobIdInputGetCallback);

    worker->execute(&input);
}

void
SWGInputApi::jobsJobIdInputGetCallback(HttpRequestWorker * worker) {
    QString msg;
    if (worker->error_type == QNetworkReply::NoError) {
        msg = QString("Success! %1 bytes").arg(worker->response.length());
    }
    else {
        msg = "Error: " + worker->error_str;
    }

    
    QList<SWGInputFile*>* output = new QList<SWGInputFile*>();
    QString json(worker->response);
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonArray jsonArray = doc.array();

    foreach(QJsonValue obj, jsonArray) {
        SWGInputFile* o = new SWGInputFile();
        QJsonObject jv = obj.toObject();
        QJsonObject * ptr = (QJsonObject*)&jv;
        o->fromJsonObject(*ptr);
        output->append(o);
    }
    

    

    worker->deleteLater();

    emit jobsJobIdInputGetSignal(output);
    
}
void
SWGInputApi::jobsJobIdInputPost(SWGInputFile body, QString* xOcToken, QString* xOcApiKey, QString* jobId) {
    QString fullPath;
    fullPath.append(this->host).append(this->basePath).append("/jobs/{job_id}/input");

    
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
            &SWGInputApi::jobsJobIdInputPostCallback);

    worker->execute(&input);
}

void
SWGInputApi::jobsJobIdInputPostCallback(HttpRequestWorker * worker) {
    QString msg;
    if (worker->error_type == QNetworkReply::NoError) {
        msg = QString("Success! %1 bytes").arg(worker->response.length());
    }
    else {
        msg = "Error: " + worker->error_str;
    }

    

    
    
    
    QString json(worker->response);
    SWGInputFile* output = static_cast<SWGInputFile*>(create(json, QString("SWGInputFile")));
    
    
    

    worker->deleteLater();

    emit jobsJobIdInputPostSignal(output);
    
}
void
SWGInputApi::jobsJobIdInputFileIdGet(QString* xOcToken, QString* xOcApiKey, QString* jobId, QString* fileId) {
    QString fullPath;
    fullPath.append(this->host).append(this->basePath).append("/jobs/{job_id}/input/{file_id}");

    
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
            &SWGInputApi::jobsJobIdInputFileIdGetCallback);

    worker->execute(&input);
}

void
SWGInputApi::jobsJobIdInputFileIdGetCallback(HttpRequestWorker * worker) {
    QString msg;
    if (worker->error_type == QNetworkReply::NoError) {
        msg = QString("Success! %1 bytes").arg(worker->response.length());
    }
    else {
        msg = "Error: " + worker->error_str;
    }

    

    
    
    
    QString json(worker->response);
    SWGInputFile* output = static_cast<SWGInputFile*>(create(json, QString("SWGInputFile")));
    
    
    

    worker->deleteLater();

    emit jobsJobIdInputFileIdGetSignal(output);
    
}
void
SWGInputApi::jobsJobIdInputFileIdDelete(QString* xOcToken, QString* xOcApiKey, QString* jobId, QString* fileId) {
    QString fullPath;
    fullPath.append(this->host).append(this->basePath).append("/jobs/{job_id}/input/{file_id}");

    
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
            &SWGInputApi::jobsJobIdInputFileIdDeleteCallback);

    worker->execute(&input);
}

void
SWGInputApi::jobsJobIdInputFileIdDeleteCallback(HttpRequestWorker * worker) {
    QString msg;
    if (worker->error_type == QNetworkReply::NoError) {
        msg = QString("Success! %1 bytes").arg(worker->response.length());
    }
    else {
        msg = "Error: " + worker->error_str;
    }

    

    
    
    
    QString json(worker->response);
    SWGInputFile* output = static_cast<SWGInputFile*>(create(json, QString("SWGInputFile")));
    
    
    

    worker->deleteLater();

    emit jobsJobIdInputFileIdDeleteSignal(output);
    
}
} /* namespace Swagger */
