#ifndef _SWG_SWGOutputApi_H_
#define _SWG_SWGOutputApi_H_

#include "SWGHttpRequest.h"

#include "SWGError.h"
#include <QString>
#include "SWGOutputFile.h"

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

    void jobsJobIdOutputGet(QString* conversionId, QString* inputId, QString* xOcToken, QString* xOcApiKey, QString* jobId);
    void jobsJobIdOutputFileIdGet(QString* xOcToken, QString* xOcApiKey, QString* jobId, QString* fileId);
    void jobsJobIdOutputFileIdDelete(QString* xOcToken, QString* xOcApiKey, QString* jobId, QString* fileId);
    
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