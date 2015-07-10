#ifndef _SWG_SWGJobsApi_H_
#define _SWG_SWGJobsApi_H_

#include "SWGHttpRequest.h"

#include <QString>
#include "SWGNumber.h"
#include "SWGJob.h"
#include "SWGError.h"
#include "SWGThread.h"

#include <QObject>

namespace Swagger {

class SWGJobsApi: public QObject {
    Q_OBJECT

public:
    SWGJobsApi();
    SWGJobsApi(QString host, QString basePath);
    ~SWGJobsApi();

    QString host;
    QString basePath;

    void jobsGet(QString* status, QString* token, QString* key, SWGNumber* page);
    void jobsPost(QString* key, SWGJob body);
    void jobsJobIdGet(QString* token, QString* key, QString* jobId);
    void jobsJobIdDelete(QString* token, QString* key, QString* jobId);
    void jobsJobIdPatch(SWGJob body, QString* token, QString* key, QString* jobId);
    void jobsJobIdThreadsGet(QString* token, QString* key, QString* jobId);
    
private:
    void jobsGetCallback (HttpRequestWorker * worker);
    void jobsPostCallback (HttpRequestWorker * worker);
    void jobsJobIdGetCallback (HttpRequestWorker * worker);
    void jobsJobIdDeleteCallback (HttpRequestWorker * worker);
    void jobsJobIdPatchCallback (HttpRequestWorker * worker);
    void jobsJobIdThreadsGetCallback (HttpRequestWorker * worker);
    
signals:
    void jobsGetSignal(QList<SWGJob*>* summary);
    void jobsPostSignal(SWGJob* summary);
    void jobsJobIdGetSignal(SWGJob* summary);
    void jobsJobIdDeleteSignal(SWGJob* summary);
    void jobsJobIdPatchSignal(SWGJob* summary);
    void jobsJobIdThreadsGetSignal(QList<SWGThread*>* summary);
    
};
}
#endif