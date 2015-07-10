#ifndef _SWG_SWGOutputApi_H_
#define _SWG_SWGOutputApi_H_

#include "SWGHttpRequest.h"

#include <QString>
#include "SWGOutputFile.h"
#include "SWGError.h"

#include <QObject>

namespace Swagger {

class SWGOutputApi: public QObject {
    Q_OBJECT

public:
    SWGOutputApi();
    SWGOutputApi(QString host, QString basePath);
    ~SWGOutputApi();

    QString host;
    QString basePath;

    void jobsJobIdOutputGet(QString* conversionId, QString* inputId, QString* token, QString* key, QString* jobId);
    void jobsJobIdOutputFileIdGet(QString* token, QString* key, QString* jobId, QString* fileId);
    void jobsJobIdOutputFileIdDelete(QString* token, QString* key, QString* jobId, QString* fileId);
    
private:
    void jobsJobIdOutputGetCallback (HttpRequestWorker * worker);
    void jobsJobIdOutputFileIdGetCallback (HttpRequestWorker * worker);
    void jobsJobIdOutputFileIdDeleteCallback (HttpRequestWorker * worker);
    
signals:
    void jobsJobIdOutputGetSignal(QList<SWGOutputFile*>* summary);
    void jobsJobIdOutputFileIdGetSignal(QList<SWGOutputFile*>* summary);
    void jobsJobIdOutputFileIdDeleteSignal(QList<SWGOutputFile*>* summary);
    
};
}
#endif