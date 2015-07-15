#ifndef _SWG_SWGConversionApi_H_
#define _SWG_SWGConversionApi_H_

#include "SWGHttpRequest.h"

#include "SWGError.h"
#include <QString>
#include "SWGConversion.h"

#include <QObject>

namespace Swagger {

class SWGConversionApi: public QObject {
    Q_OBJECT

public:
    SWGConversionApi();
    SWGConversionApi(QString host, QString basePath);
    ~SWGConversionApi();

    QString host;
    QString basePath;

    void jobsJobIdConversionsGet(QString* xOcToken, QString* xOcApiKey, QString* jobId);
    void jobsJobIdConversionsPost(SWGConversion body, QString* xOcToken, QString* xOcApiKey, QString* jobId);
    void jobsJobIdConversionsConversionIdGet(QString* xOcToken, QString* xOcApiKey, QString* jobId, QString* conversionId);
    void jobsJobIdConversionsConversionIdDelete(QString* xOcToken, QString* xOcApiKey, QString* jobId, QString* conversionId);
    
private:
    void jobsJobIdConversionsGetCallback (HttpRequestWorker * worker);
    void jobsJobIdConversionsPostCallback (HttpRequestWorker * worker);
    void jobsJobIdConversionsConversionIdGetCallback (HttpRequestWorker * worker);
    void jobsJobIdConversionsConversionIdDeleteCallback (HttpRequestWorker * worker);
    
signals:
    void jobsJobIdConversionsGetSignal(QList<SWGConversion*>* summary);
    void jobsJobIdConversionsPostSignal(SWGConversion* summary);
    void jobsJobIdConversionsConversionIdGetSignal(SWGConversion* summary);
    void jobsJobIdConversionsConversionIdDeleteSignal(SWGConversion* summary);
    
};
}
#endif