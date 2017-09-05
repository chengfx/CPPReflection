#ifndef __RF_FACTORY_CLASS_H__
#define __RF_FACTORY_CLASS_H__

#include <string>
#include <map>

namespace reflection{
  
  typedef void* (*CreateFunctionPtr)(void);
  
  class RFFactoryClass
  {
  public:
    RFFactoryClass(){}
    virtual ~RFFactoryClass(){}
    void* getClassByName(std::string className);
    void registClass(std::string name, CreateFunctionPtr method);
    static RFFactoryClass& sharedFactoryClass();

  private:
    std::map<std::string, CreateFunctionPtr> m_classMap;
  };
  
  //Regist class
  class RFRegisterClass
  {
  public:
    RFRegisterClass(std::string name, CreateFunctionPtr method)
    {
      RFFactoryClass::sharedFactoryClass().registClass(name, method);
    }
  };
 
  #define DECLARE_CLASS(className) \
  static RFRegisterClass* m_##className##RF

  #define REGISTER_CLASS(className) \
  RFRegisterClass* className::m_##className##RF = \
  new RFRegisterClass(#className, className::createInstance)
}

#endif
