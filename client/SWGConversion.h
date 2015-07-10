/*
 * SWGConversion.h
 * 
 * 
 */

#ifndef SWGConversion_H_
#define SWGConversion_H_

#include <QJsonObject>


#include <QString>
#include "SWGObject.h"

#include "SWGObject.h"


namespace Swagger {

class SWGConversion: public SWGObject {
public:
    SWGConversion();
    SWGConversion(QString* json);
    virtual ~SWGConversion();
    void init();
    void cleanup();

    QString asJson ();
    QJsonObject* asJsonObject();
    void fromJsonObject(QJsonObject &json);
    SWGConversion* fromJson(QString &jsonString);

    QString* getId();
    void setId(QString* id);
    QString* getTarget();
    void setTarget(QString* target);
    QString* getCategory();
    void setCategory(QString* category);
    SWGObject* getOptions();
    void setOptions(SWGObject* options);
    

private:
    QString* id;
    QString* target;
    QString* category;
    SWGObject* options;
    
};

} /* namespace Swagger */

#endif /* SWGConversion_H_ */
