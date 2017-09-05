#include "RFFactoryClass.h"
#include <string>
#include <map>
using namespace std;

namespace reflection{

  void* RFFactoryClass::getClassByName(string className)
  {
    auto iter = m_classMap.find(className);
    if(m_classMap.find(className) == m_classMap.end())
      return NULL;
    else
      return iter->second();
  }

  void RFFactoryClass::registClass(string name, CreateFunctionPtr method)
  {
    m_classMap.insert(pair<string, CreateFunctionPtr>(name, method));
  }

  RFFactoryClass& RFFactoryClass::sharedFactoryClass()
  {
    static RFFactoryClass _sharedClassFactory;
    return _sharedClassFactory;
  }

}
