/*
 * SWGJob.h
 * 
 * 
 */

#ifndef SWGJob_H_
#define SWGJob_H_

#include <QJsonObject>


#include "QDateTime.h"
#include <QList>
#include <QString>
#include "SWGInputFile.h"
#include "SWGConversion.h"
#include "SWGStatus.h"

#include "SWGObject.h"


namespace Swagger {

class SWGJob: public SWGObject {
public:
    SWGJob();
    SWGJob(QString* json);
    virtual ~SWGJob();
    void init();
    void cleanup();

    QString asJson ();
    QJsonObject* asJsonObject();
    void fromJsonObject(QJsonObject &json);
    SWGJob* fromJson(QString &jsonString);

    QString* getId();
    void setId(QString* id);
    QString* getToken();
    void setToken(QString* token);
    QString* getType();
    void setType(QString* type);
    SWGStatus* getStatus();
    void setStatus(SWGStatus* status);
    bool getProcess();
    void setProcess(bool process);
    QList<SWGConversion*>* getConversion();
    void setConversion(QList<SWGConversion*>* conversion);
    QList<SWGInputFile*>* getInput();
    void setInput(QList<SWGInputFile*>* input);
    QString* getCallback();
    void setCallback(QString* callback);
    QString* getServer();
    void setServer(QString* server);
    QDateTime* getCreatedAt();
    void setCreatedAt(QDateTime* created_at);
    QDateTime* getModifiedAt();
    void setModifiedAt(QDateTime* modified_at);
    

private:
    QString* id;
    QString* token;
    QString* type;
    SWGStatus* status;
    bool process;
    QList<SWGConversion*>* conversion;
    QList<SWGInputFile*>* input;
    QString* callback;
    QString* server;
    QDateTime* created_at;
    QDateTime* modified_at;
    
};

} /* namespace Swagger */

#endif /* SWGJob_H_ */
