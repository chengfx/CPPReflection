#ifndef __RF_FACTORY_CLASS_H__
#define __RF_FACTORY_CLASS_H__

#include <string>
#include <map>
#include <iostream>

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
    int getClassNum(){return m_classMap.size();}
    int display()
    {
      for(auto& iter : m_classMap)
      {
        std::cout << "ClassName:" << iter.first
	<< " FunctionPtr: " << std::hex << (long long)(iter.second) << std::endl;
      }
    }
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
  static RFRegisterClass* m_classNameRF

  #define REGISTER_CLASS(className) \
  RFRegisterClass* className::m_classNameRF = \
  new RFRegisterClass(#className, className::createInstance)
}

#endif
