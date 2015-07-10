#ifndef _SWG_SWGInformationApi_H_
#define _SWG_SWGInformationApi_H_

#include "SWGHttpRequest.h"

#include <QString>
#include "SWGNumber.h"
#include "SWGConversion.h"
#include "SWGStatus.h"

#include <QObject>

namespace Swagger {

class SWGInformationApi: public QObject {
    Q_OBJECT

public:
    SWGInformationApi();
    SWGInformationApi(QString host, QString basePath);
    ~SWGInformationApi();

    QString host;
    QString basePath;

    void conversionsGet(QString* category, QString* target, SWGNumber* page);
    void statusesGet();
    
private:
    void conversionsGetCallback (HttpRequestWorker * worker);
    void statusesGetCallback (HttpRequestWorker * worker);
    
signals:
    void conversionsGetSignal(QList<SWGConversion*>* summary);
    void statusesGetSignal(QList<SWGStatus*>* summary);
    
};
}
#endif