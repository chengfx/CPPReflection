#ifndef __REFLECTION_H__
#define __REFLECTION_H__

#include <string>
#include <map>

namespace reflection{
  
  typedef void* (*createClass)(void);
  
  class CKClassFactory
  {
  public:
    CKClassFactory();
    virtual ~CKClassFactory();
    void* getClassByName(std::string className);
    void registClass(std::string name, createClass method);
    static CKClassFactory& sharedClassFactory();

  private:
    std::map<std::string, createClass> m_classMap;
  };


}

#endif
