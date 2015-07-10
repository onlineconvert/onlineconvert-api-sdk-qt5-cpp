/*
 * SWGThread.h
 * 
 * 
 */

#ifndef SWGThread_H_
#define SWGThread_H_

#include <QJsonObject>


#include "QDateTime.h"
#include <QString>

#include "SWGObject.h"


namespace Swagger {

class SWGThread: public SWGObject {
public:
    SWGThread();
    SWGThread(QString* json);
    virtual ~SWGThread();
    void init();
    void cleanup();

    QString asJson ();
    QJsonObject* asJsonObject();
    void fromJsonObject(QJsonObject &json);
    SWGThread* fromJson(QString &jsonString);

    QString* getHash();
    void setHash(QString* hash);
    qint32 getStatus();
    void setStatus(qint32 status);
    QString* getInfo();
    void setInfo(QString* info);
    QDateTime* getCreatedAt();
    void setCreatedAt(QDateTime* created_at);
    QDateTime* getModifiedAt();
    void setModifiedAt(QDateTime* modified_at);
    

private:
    QString* hash;
    qint32 status;
    QString* info;
    QDateTime* created_at;
    QDateTime* modified_at;
    
};

} /* namespace Swagger */

#endif /* SWGThread_H_ */
