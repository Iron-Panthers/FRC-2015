#include <JoyButton.hpp>

JoyButton::JoyButton()
{

}

JoyButton::JoyButton(ButtonNames name)
{
	std::cout << "Button #2" << std::endl;
}

JoyButton::JoyButton(bool wouldBeDown, bool wouldBePressed, bool wouldBeUp, ButtonNames name)
{
	std::cout << "Button #1" << std::endl;
}

inline bool JoyButton::operator==(const JoyButton& right)
{
	std::cout << "Operator== JoyButton" << std::endl;
	//TODO fix
	return true;
}
