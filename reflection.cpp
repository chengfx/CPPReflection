#include "reflection.h"
#include <string>
#include <map>

namespace reflection{

  using namespace std;

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
