#ifndef _SWG_SWGInputApi_H_
#define _SWG_SWGInputApi_H_

#include "SWGHttpRequest.h"

#include <QString>
#include "SWGInputFile.h"
#include "SWGError.h"

#include <QObject>

namespace Swagger {

class SWGInputApi: public QObject {
    Q_OBJECT

public:
    SWGInputApi();
    SWGInputApi(QString host, QString basePath);
    ~SWGInputApi();

    QString host;
    QString basePath;

    void jobsJobIdInputGet(QString* token, QString* key, QString* jobId);
    void jobsJobIdInputPost(SWGInputFile body, QString* token, QString* key, QString* jobId);
    void jobsJobIdInputFileIdGet(QString* token, QString* key, QString* jobId, QString* fileId);
    void jobsJobIdInputFileIdDelete(QString* token, QString* key, QString* jobId, QString* fileId);
    
private:
    void jobsJobIdInputGetCallback (HttpRequestWorker * worker);
    void jobsJobIdInputPostCallback (HttpRequestWorker * worker);
    void jobsJobIdInputFileIdGetCallback (HttpRequestWorker * worker);
    void jobsJobIdInputFileIdDeleteCallback (HttpRequestWorker * worker);
    
signals:
    void jobsJobIdInputGetSignal(QList<SWGInputFile*>* summary);
    void jobsJobIdInputPostSignal(SWGInputFile* summary);
    void jobsJobIdInputFileIdGetSignal(SWGInputFile* summary);
    void jobsJobIdInputFileIdDeleteSignal(SWGInputFile* summary);
    
};
}
#endif