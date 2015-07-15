#ifndef _SWG_SWGJobsApi_H_
#define _SWG_SWGJobsApi_H_

#include "SWGHttpRequest.h"

#include "SWGError.h"
#include <QString>
#include "SWGNumber.h"
#include "SWGJob.h"
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

    void jobsGet(QString* status, QString* xOcToken, QString* xOcApiKey, SWGNumber* page);
    void jobsPost(QString* xOcApiKey, SWGJob body);
    void jobsJobIdGet(QString* xOcToken, QString* xOcApiKey, QString* jobId);
    void jobsJobIdDelete(QString* xOcToken, QString* xOcApiKey, QString* jobId);
    void jobsJobIdPatch(SWGJob body, QString* xOcToken, QString* xOcApiKey, QString* jobId);
    void jobsJobIdThreadsGet(QString* xOcToken, QString* xOcApiKey, QString* jobId);
    
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