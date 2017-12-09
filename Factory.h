#include <map>
#include <string>
#include"Resource.h"

#ifndef Fac
#define Fac
 
template<typename T, typename std::enable_if<std::is_base_of<Resource, T>::value>::type* = nullptr>
Resource* constructor() { return (Resource*)new T(); }

struct factory
{
   typedef Resource*(*constructor_t)();
   typedef std::map<std::string, constructor_t> map_type;
   map_type m_classes;

   template<typename T, typename std::enable_if<std::is_base_of<Resource, T>::value>::type* = nullptr>
   void register_class(std::string const& n)
   { m_classes.insert(std::make_pair(n, &constructor<T>)); }

   Resource* construct(std::string const& n)
   {
      map_type::iterator i = m_classes.find(n);
      if (i == m_classes.end()) return 0; // or throw or whatever you want
      return i->second();
   }
};
#endif
