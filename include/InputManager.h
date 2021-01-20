#pragma once

#include "SFML/Graphics.hpp"

enum InputType
{
	Keyboard,
	Mouse,
	Joystick
};

struct Input
{
	int button;
	InputType type;
};


/**
 * \brief Handle the inputs on keyboard, mouse and gamepad
 */
class InputManager
{
public:
	InputManager();
	~InputManager();

	/**
	 * \brief Add a keyboard binding
	 */
	void addBinding(std::string name, sf::Keyboard::Key key);

	/**
	 * \brief Add a mouse button binding
	 */
	void addBinding(std::string name, sf::Mouse::Button button);

	/**
	 * \brief Add a gamepad binding
	 */
	void addBinding(std::string name, int button);

	bool isPressed(const std::string name);

private:
	std::map<std::string, std::vector<Input>> bindings;

	void addBinding(std::string name, Input input);
};
