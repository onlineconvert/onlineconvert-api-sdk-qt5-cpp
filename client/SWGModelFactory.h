#ifndef ModelFactory_H_
#define ModelFactory_H_


#include "SWGJob.h"
#include "SWGInputFile.h"
#include "SWGOutputFile.h"
#include "SWGConversion.h"
#include "SWGThread.h"
#include "SWGStatus.h"
#include "SWGError.h"

namespace Swagger {
  inline void* create(QString type) {
    if(QString("SWGJob").compare(type) == 0) {
      return new SWGJob();
    }
    if(QString("SWGInputFile").compare(type) == 0) {
      return new SWGInputFile();
    }
    if(QString("SWGOutputFile").compare(type) == 0) {
      return new SWGOutputFile();
    }
    if(QString("SWGConversion").compare(type) == 0) {
      return new SWGConversion();
    }
    if(QString("SWGThread").compare(type) == 0) {
      return new SWGThread();
    }
    if(QString("SWGStatus").compare(type) == 0) {
      return new SWGStatus();
    }
    if(QString("SWGError").compare(type) == 0) {
      return new SWGError();
    }
    
    return NULL;
  }

  inline void* create(QString json, QString type) {
    void* val = create(type);
    if(val != NULL) {
      SWGObject* obj = static_cast<SWGObject*>(val);
      return obj->fromJson(json);
    }
    if(type.startsWith("QString")) {
      return new QString();
    }
    return NULL;
  }
} /* namespace Swagger */

#endif /* ModelFactory_H_ */
