#ifndef ISCRIPT_HPP
#define ISCRIPT_HPP


class IScript
{
public:
  virtual ~IScript() = default;
  virtual void init() = 0;
  virtual void update() = 0;
};


#endif