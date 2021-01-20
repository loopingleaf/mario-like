#include "SFML/Graphics.hpp"
#include "InputManager.h"

InputManager::InputManager()
{
	bindings = std::map<std::string, std::vector<Input>>();
}

InputManager::~InputManager()
{
	bindings = std::map<std::string, std::vector<Input>>();
}

void InputManager::addBinding(std::string name, sf::Keyboard::Key key)
{
	Input in;
	in.button = key;
	in.type = InputType::Keyboard;
	addBinding(name, in);
}

void InputManager::addBinding(std::string name, sf::Mouse::Button button)
{
	Input in;
	in.button = button;
	in.type = InputType::Mouse;
	addBinding(name, in);
}

void InputManager::addBinding(std::string name, int button)
{
	Input in;
	in.button = button;
	in.type = InputType::Joystick;
	addBinding(name, in);
}

bool InputManager::isPressed(const std::string name)
{
	std::map<std::string, std::vector<Input>>::iterator it = bindings.find(name);
	if (it == bindings.end())
	{
		return false;
	}

	bool found = false;
	for (Input in : bindings[name])
	{
		switch (in.type)
		{
		case(InputType::Keyboard):
			 sf::Keyboard::isKeyPressed(sf::Keyboard::Key(in.button));
		case(InputType::Mouse):
			sf::Mouse::isButtonPressed(sf::Mouse::Button(in.button));
		case(InputType::Joystick):
			sf::Joystick::isButtonPressed(0, in.button);
		default:
			break;
		}
		if (found)
			return true;
	}
	return false;
}

void InputManager::addBinding(std::string name, Input input)
{
	std::map<std::string, std::vector<Input>>::iterator it = bindings.find(name);
	if (it != bindings.end())
	{
		bindings[name].push_back(input);
	}
	else
	{
		std::vector<Input> inputVector;
		inputVector.push_back(input);
		bindings.insert(bindings.begin(), std::pair<std::string, std::vector<Input>>(name, inputVector));
	}
}