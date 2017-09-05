#ifndef __RF_FACTORY_CLASS_H__
#define __RF_FACTORY_CLASS_H__

#include <string>
#include <map>

namespace reflection{
  
  typedef void* (*CreateFunctionPtr)(void);
  
  class RFFactoryClass
  {
  public:
    RFFactoryClass();
    virtual ~RFFactoryClass();
    void* getClassByName(std::string className);
    void registClass(std::string name, CreateFunctionPtr method);
    static RFFactoryClass& sharedFactoryClass();

  private:
    std::map<std::string, CreateFunctionPtr> m_classMap;
  };


}

#endif
