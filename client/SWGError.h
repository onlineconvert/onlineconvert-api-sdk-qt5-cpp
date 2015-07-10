/*
 * SWGError.h
 * 
 * 
 */

#ifndef SWGError_H_
#define SWGError_H_

#include <QJsonObject>


#include <QString>
#include "SWGObject.h"

#include "SWGObject.h"


namespace Swagger {

class SWGError: public SWGObject {
public:
    SWGError();
    SWGError(QString* json);
    virtual ~SWGError();
    void init();
    void cleanup();

    QString asJson ();
    QJsonObject* asJsonObject();
    void fromJsonObject(QJsonObject &json);
    SWGError* fromJson(QString &jsonString);

    qint32 getCode();
    void setCode(qint32 code);
    QString* getMessage();
    void setMessage(QString* message);
    SWGObject* getErrors();
    void setErrors(SWGObject* errors);
    

private:
    qint32 code;
    QString* message;
    SWGObject* errors;
    
};

} /* namespace Swagger */

#endif /* SWGError_H_ */
