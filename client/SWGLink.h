/*
 * SWGLink.h
 * 
 * 
 */

#ifndef SWGLink_H_
#define SWGLink_H_

#include <QJsonObject>


#include <QString>

#include "SWGObject.h"


namespace Swagger {

class SWGLink: public SWGObject {
public:
    SWGLink();
    SWGLink(QString* json);
    virtual ~SWGLink();
    void init();
    void cleanup();

    QString asJson ();
    QJsonObject* asJsonObject();
    void fromJsonObject(QJsonObject &json);
    SWGLink* fromJson(QString &jsonString);

    QString* getId();
    void setId(QString* id);
    QString* getUri();
    void setUri(QString* uri);
    

private:
    QString* id;
    QString* uri;
    
};

} /* namespace Swagger */

#endif /* SWGLink_H_ */
