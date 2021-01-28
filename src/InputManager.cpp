#include <fstream>
#include <iostream>
#include "InputManager.h"
#include "SFML/Graphics.hpp"
#include "nlohmann/json.hpp"

InputManager::InputManager()
{
	bindings = std::map<std::string, std::vector<Input>>();
}

InputManager::~InputManager()
{
	bindings = std::map<std::string, std::vector<Input>>();
}

void InputManager::loadConfig()
{
	std::ifstream file(keymapPath);
	nlohmann::json json;
	file >> json;
	for (auto it = json.begin(); it != json.end(); it++)
	{
#ifdef _DEBUG
		std::cout << it.key() << "; ";
#endif // _DEBUG
		std::string newBindingName = it.key();
		for (auto it2 = it.value().begin(); it2 != it.value().end(); it2++)
		{
			Input inputToAdd;
			if (it2.key() == "keyboard")
			{
				inputToAdd.type = InputType::Keyboard;
				for (int i = 0; i < it2.value().size(); i++)
				{
					std::cout << it2.value()[i];
					inputToAdd.button = nameKey[it2.value()[i]];
					addBinding(it.key(), inputToAdd);
				}
			}
		}
	}
#ifdef _DEBUG
	std::cout << std::endl << "Bindings loaded:" << std::endl;
	for (auto pair : bindings)
	{
		std::cout << "	" << pair.first << ": ";
		for (auto item : pair.second)
		{
			std::cout << item.type << ":" << item.button << " ";
		}
		std::cout << std::endl;
	}
#endif // _DEBUG
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
			 break;
		case(InputType::Mouse):
			sf::Mouse::isButtonPressed(sf::Mouse::Button(in.button));
			break;
		case(InputType::Joystick):
			sf::Joystick::isButtonPressed(0, in.button);
			break;
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