

#ifndef __Singleton_hh__
#define __Singleton_hh__

template <typename T>
class Singleton
{
  public:
    static T & Instance()
    {
      static T _instance;
      return _instance;
    }
};

#endif
