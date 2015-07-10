/*
 * SWGStatus.h
 * 
 * 
 */

#ifndef SWGStatus_H_
#define SWGStatus_H_

#include <QJsonObject>


#include <QString>

#include "SWGObject.h"


namespace Swagger {

class SWGStatus: public SWGObject {
public:
    SWGStatus();
    SWGStatus(QString* json);
    virtual ~SWGStatus();
    void init();
    void cleanup();

    QString asJson ();
    QJsonObject* asJsonObject();
    void fromJsonObject(QJsonObject &json);
    SWGStatus* fromJson(QString &jsonString);

    QString* getCode();
    void setCode(QString* code);
    QString* getInfo();
    void setInfo(QString* info);
    

private:
    QString* code;
    QString* info;
    
};

} /* namespace Swagger */

#endif /* SWGStatus_H_ */
