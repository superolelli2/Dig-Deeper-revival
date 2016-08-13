#pragma once


#include "SFML\Graphics.hpp"
#include "Makros.hpp"


enum Keystates{None, Pressed, Held, Released};

//typedef for the key ids
typedef sf::Keyboard::Key KeyID;
typedef sf::Mouse::Button ButtonID;

class CWindow
{
public:

	//Inits the window 
	void Init();

	//Quits everything safe
	void Quit();

	//Fills the background black
	void Clear(const sf::Color &_color) const;

	//flips the double-buffer and shows the new frame
	void Flip();

	//returns a list of all events, happened
	void ProcessEvents();

	//returns a pointer to the window
	inline sf::RenderWindow *GetWindow() { return m_pWindow; }

	//The getters
	Keystates  const &GetKeystates(KeyID _id) const { return m_keyStates[_id]; }
	Keystates const &GetButtonstates(ButtonID _id) const { return m_mouseStates[_id]; }
	inline int GetMouseWheelMovement() const { return m_mouseWheelMovement; }


private:
	//arrays for saving the key- and buttonstates
	Keystates m_keyStates[sf::Keyboard::KeyCount];
	Keystates m_mouseStates[sf::Mouse::ButtonCount];
	int m_mouseWheelMovement;

	//the window to render on
	sf::RenderWindow *m_pWindow;

	void ClearKeyStates();
};