#include "SWGJobsApi.h"
#include "SWGHelpers.h"
#include "SWGModelFactory.h"

#include <QJsonArray>
#include <QJsonDocument>

namespace Swagger {
SWGJobsApi::SWGJobsApi() {}

SWGJobsApi::~SWGJobsApi() {}

SWGJobsApi::SWGJobsApi(QString host, QString basePath) {
    this->host = host;
    this->basePath = basePath;
}

void
SWGJobsApi::jobsGet(QString* status, QString* token, QString* key, SWGNumber* page) {
    QString fullPath;
    fullPath.append(this->host).append(this->basePath).append("/jobs");

    

    
    
    if(fullPath.indexOf("?") > 0) 
      fullPath.append("&");
    else 
      fullPath.append("?");
    fullPath.append(QUrl::toPercentEncoding("status"))
        .append("=")
        .append(QUrl::toPercentEncoding(stringValue(status)));
    

    
    
    
    if(fullPath.indexOf("?") > 0) 
      fullPath.append("&");
    else 
      fullPath.append("?");
    fullPath.append(QUrl::toPercentEncoding("page"))
        .append("=")
        .append(QUrl::toPercentEncoding(stringValue(page)));
    

    
    

    HttpRequestWorker *worker = new HttpRequestWorker();
    HttpRequestInput input(fullPath, "GET");

    

    

    
    // TODO: add header support
    
    // TODO: add header support
    

    connect(worker,
            &HttpRequestWorker::on_execution_finished,
            this,
            &SWGJobsApi::jobsGetCallback);

    worker->execute(&input);
}

void
SWGJobsApi::jobsGetCallback(HttpRequestWorker * worker) {
    QString msg;
    if (worker->error_type == QNetworkReply::NoError) {
        msg = QString("Success! %1 bytes").arg(worker->response.length());
    }
    else {
        msg = "Error: " + worker->error_str;
    }

    
    QList<SWGJob*>* output = new QList<SWGJob*>();
    QString json(worker->response);
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonArray jsonArray = doc.array();

    foreach(QJsonValue obj, jsonArray) {
        SWGJob* o = new SWGJob();
        QJsonObject jv = obj.toObject();
        QJsonObject * ptr = (QJsonObject*)&jv;
        o->fromJsonObject(*ptr);
        output->append(o);
    }
    

    

    worker->deleteLater();

    emit jobsGetSignal(output);
    
}
void
SWGJobsApi::jobsPost(QString* key, SWGJob body) {
    QString fullPath;
    fullPath.append(this->host).append(this->basePath).append("/jobs");

    

    

    HttpRequestWorker *worker = new HttpRequestWorker();
    HttpRequestInput input(fullPath, "POST");

    

    
    
    
    QString output = body.asJson();
    input.request_body.append(output);
    

    
    // TODO: add header support
    

    connect(worker,
            &HttpRequestWorker::on_execution_finished,
            this,
            &SWGJobsApi::jobsPostCallback);

    worker->execute(&input);
}

void
SWGJobsApi::jobsPostCallback(HttpRequestWorker * worker) {
    QString msg;
    if (worker->error_type == QNetworkReply::NoError) {
        msg = QString("Success! %1 bytes").arg(worker->response.length());
    }
    else {
        msg = "Error: " + worker->error_str;
    }

    

    
    
    
    QString json(worker->response);
    SWGJob* output = static_cast<SWGJob*>(create(json, QString("SWGJob")));
    
    
    

    worker->deleteLater();

    emit jobsPostSignal(output);
    
}
void
SWGJobsApi::jobsJobIdGet(QString* token, QString* key, QString* jobId) {
    QString fullPath;
    fullPath.append(this->host).append(this->basePath).append("/jobs/{job_id}");

    
    QString jobIdPathParam("{"); jobIdPathParam.append("jobId").append("}");
    fullPath.replace(jobIdPathParam, stringValue(jobId));
    

    

    HttpRequestWorker *worker = new HttpRequestWorker();
    HttpRequestInput input(fullPath, "GET");

    

    

    
    // TODO: add header support
    
    // TODO: add header support
    

    connect(worker,
            &HttpRequestWorker::on_execution_finished,
            this,
            &SWGJobsApi::jobsJobIdGetCallback);

    worker->execute(&input);
}

void
SWGJobsApi::jobsJobIdGetCallback(HttpRequestWorker * worker) {
    QString msg;
    if (worker->error_type == QNetworkReply::NoError) {
        msg = QString("Success! %1 bytes").arg(worker->response.length());
    }
    else {
        msg = "Error: " + worker->error_str;
    }

    

    
    
    
    QString json(worker->response);
    SWGJob* output = static_cast<SWGJob*>(create(json, QString("SWGJob")));
    
    
    

    worker->deleteLater();

    emit jobsJobIdGetSignal(output);
    
}
void
SWGJobsApi::jobsJobIdDelete(QString* token, QString* key, QString* jobId) {
    QString fullPath;
    fullPath.append(this->host).append(this->basePath).append("/jobs/{job_id}");

    
    QString jobIdPathParam("{"); jobIdPathParam.append("jobId").append("}");
    fullPath.replace(jobIdPathParam, stringValue(jobId));
    

    

    HttpRequestWorker *worker = new HttpRequestWorker();
    HttpRequestInput input(fullPath, "DELETE");

    

    

    
    // TODO: add header support
    
    // TODO: add header support
    

    connect(worker,
            &HttpRequestWorker::on_execution_finished,
            this,
            &SWGJobsApi::jobsJobIdDeleteCallback);

    worker->execute(&input);
}

void
SWGJobsApi::jobsJobIdDeleteCallback(HttpRequestWorker * worker) {
    QString msg;
    if (worker->error_type == QNetworkReply::NoError) {
        msg = QString("Success! %1 bytes").arg(worker->response.length());
    }
    else {
        msg = "Error: " + worker->error_str;
    }

    

    
    
    
    QString json(worker->response);
    SWGJob* output = static_cast<SWGJob*>(create(json, QString("SWGJob")));
    
    
    

    worker->deleteLater();

    emit jobsJobIdDeleteSignal(output);
    
}
void
SWGJobsApi::jobsJobIdPatch(SWGJob body, QString* token, QString* key, QString* jobId) {
    QString fullPath;
    fullPath.append(this->host).append(this->basePath).append("/jobs/{job_id}");

    
    QString jobIdPathParam("{"); jobIdPathParam.append("jobId").append("}");
    fullPath.replace(jobIdPathParam, stringValue(jobId));
    

    

    HttpRequestWorker *worker = new HttpRequestWorker();
    HttpRequestInput input(fullPath, "PATCH");

    

    
    
    
    QString output = body.asJson();
    input.request_body.append(output);
    

    
    // TODO: add header support
    
    // TODO: add header support
    

    connect(worker,
            &HttpRequestWorker::on_execution_finished,
            this,
            &SWGJobsApi::jobsJobIdPatchCallback);

    worker->execute(&input);
}

void
SWGJobsApi::jobsJobIdPatchCallback(HttpRequestWorker * worker) {
    QString msg;
    if (worker->error_type == QNetworkReply::NoError) {
        msg = QString("Success! %1 bytes").arg(worker->response.length());
    }
    else {
        msg = "Error: " + worker->error_str;
    }

    

    
    
    
    QString json(worker->response);
    SWGJob* output = static_cast<SWGJob*>(create(json, QString("SWGJob")));
    
    
    

    worker->deleteLater();

    emit jobsJobIdPatchSignal(output);
    
}
void
SWGJobsApi::jobsJobIdThreadsGet(QString* token, QString* key, QString* jobId) {
    QString fullPath;
    fullPath.append(this->host).append(this->basePath).append("/jobs/{job_id}/threads");

    
    QString jobIdPathParam("{"); jobIdPathParam.append("jobId").append("}");
    fullPath.replace(jobIdPathParam, stringValue(jobId));
    

    

    HttpRequestWorker *worker = new HttpRequestWorker();
    HttpRequestInput input(fullPath, "GET");

    

    

    
    // TODO: add header support
    
    // TODO: add header support
    

    connect(worker,
            &HttpRequestWorker::on_execution_finished,
            this,
            &SWGJobsApi::jobsJobIdThreadsGetCallback);

    worker->execute(&input);
}

void
SWGJobsApi::jobsJobIdThreadsGetCallback(HttpRequestWorker * worker) {
    QString msg;
    if (worker->error_type == QNetworkReply::NoError) {
        msg = QString("Success! %1 bytes").arg(worker->response.length());
    }
    else {
        msg = "Error: " + worker->error_str;
    }

    
    QList<SWGThread*>* output = new QList<SWGThread*>();
    QString json(worker->response);
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonArray jsonArray = doc.array();

    foreach(QJsonValue obj, jsonArray) {
        SWGThread* o = new SWGThread();
        QJsonObject jv = obj.toObject();
        QJsonObject * ptr = (QJsonObject*)&jv;
        o->fromJsonObject(*ptr);
        output->append(o);
    }
    

    

    worker->deleteLater();

    emit jobsJobIdThreadsGetSignal(output);
    
}
} /* namespace Swagger */
