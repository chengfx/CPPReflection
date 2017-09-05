#ifndef __RF_BASE_CLASS_H__
#define __RF_BASE_CLASS_H__

#include "RFFactoryClass.h"
#include <map>
#include <string>

namespace reflection{

  class RFBaseClass
  {
  private:
    std::map<std::string, void* > m_propertyMap;

  public:
    RFBaseClass(){}
    virtual ~RFBaseClass(){}
    static void* createInstance(){return new RFBaseClass;}
    virtual void registProperty(std::string name, void* ptr){}
    virtual void display(){}
    void* getPropertyByName(std::string);
  };
}

#endif
