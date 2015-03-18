#include "JoyButton.hpp"

JoyButton::JoyButton()
	: name()
{
	down = false;
	pressed = false;
	up = false;
}
JoyButton::JoyButton(ButtonNames name)
	: name(name)
{
	std::cout << "Button #2" << std::endl;
}

JoyButton::JoyButton(const JoyButton& button)
	: down(button.down), pressed(button.pressed), up(button.up), name(button.name)
{

}

JoyButton::JoyButton(bool wouldBeDown, bool wouldBePressed, bool wouldBeUp, ButtonNames name)
	: down(wouldBeDown)
	, pressed(wouldBePressed)
	, up(wouldBeUp)
	, name(name)
{
	std::cout << std::boolalpha << wouldBeDown << "down\t"
			  	  	  	  	    << wouldBeUp << "up\t"
								<< wouldBePressed << "pressed\t"
								<< name << "button name" << std::endl;
}

inline bool JoyButton::operator==(const JoyButton& right)
{
	if ((down == right.down) && (pressed == right.pressed) && (up == right.up) && (name == right.name))
		return true;
	else
		return false;
}

bool JoyButton::operator<(const JoyButton& right) const
{
	return name < right.name;
}

std::ostream& operator<<(std::ostream &out, JoyButton &joyButton)
{
	out << std::boolalpha
		<< "Down: " << joyButton.down << '\t'
	    << "Pressed: " << joyButton.pressed << '\t'
		<< "Up: " << joyButton.up << '\t'
		<< "Button index: " << joyButton.name
		<< std::endl;

	return out;

}
