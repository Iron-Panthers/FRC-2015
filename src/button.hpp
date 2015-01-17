#ifndef BUTTON_HPP
#define BUTTON_HPP
public:
bool down
{
if
{
return true;
}
else
{
return false;
}
}
public:
bool pressed
{
if
{
return true;
}
else
{
return false;
}
}
public:
bool up
{
if
{
return true;
}
else
{
return false;
}
}
public:
inline bool operator==(const Button& left, const Button& right)
public:
Button(ButtonNames name)
public:
Button(bool wouldBeDown, bool wouldBePressed, bool wouldBeUp, ButtonNames name)
private:
ButtonNames name
#endif
