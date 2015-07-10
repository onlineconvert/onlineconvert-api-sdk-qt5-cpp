/*
 * SWGOutputFile.h
 * 
 * 
 */

#ifndef SWGOutputFile_H_
#define SWGOutputFile_H_

#include <QJsonObject>


#include "QDateTime.h"
#include <QString>
#include "SWGObject.h"

#include "SWGObject.h"


namespace Swagger {

class SWGOutputFile: public SWGObject {
public:
    SWGOutputFile();
    SWGOutputFile(QString* json);
    virtual ~SWGOutputFile();
    void init();
    void cleanup();

    QString asJson ();
    QJsonObject* asJsonObject();
    void fromJsonObject(QJsonObject &json);
    SWGOutputFile* fromJson(QString &jsonString);

    QString* getId();
    void setId(QString* id);
    SWGObject* getSource();
    void setSource(SWGObject* source);
    QString* getUri();
    void setUri(QString* uri);
    QString* getFilename();
    void setFilename(QString* filename);
    qint32 getSize();
    void setSize(qint32 size);
    QDateTime* getCreatedAt();
    void setCreatedAt(QDateTime* created_at);
    

private:
    QString* id;
    SWGObject* source;
    QString* uri;
    QString* filename;
    qint32 size;
    QDateTime* created_at;
    
};

} /* namespace Swagger */

#endif /* SWGOutputFile_H_ */
