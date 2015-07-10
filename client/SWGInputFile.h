/*
 * SWGInputFile.h
 * 
 * 
 */

#ifndef SWGInputFile_H_
#define SWGInputFile_H_

#include <QJsonObject>


#include "QDateTime.h"
#include <QString>

#include "SWGObject.h"


namespace Swagger {

class SWGInputFile: public SWGObject {
public:
    SWGInputFile();
    SWGInputFile(QString* json);
    virtual ~SWGInputFile();
    void init();
    void cleanup();

    QString asJson ();
    QJsonObject* asJsonObject();
    void fromJsonObject(QJsonObject &json);
    SWGInputFile* fromJson(QString &jsonString);

    QString* getId();
    void setId(QString* id);
    QString* getType();
    void setType(QString* type);
    QString* getSource();
    void setSource(QString* source);
    QString* getFilename();
    void setFilename(QString* filename);
    qint32 getSize();
    void setSize(qint32 size);
    QDateTime* getCreatedAt();
    void setCreatedAt(QDateTime* created_at);
    QDateTime* getModifiedAt();
    void setModifiedAt(QDateTime* modified_at);
    

private:
    QString* id;
    QString* type;
    QString* source;
    QString* filename;
    qint32 size;
    QDateTime* created_at;
    QDateTime* modified_at;
    
};

} /* namespace Swagger */

#endif /* SWGInputFile_H_ */
