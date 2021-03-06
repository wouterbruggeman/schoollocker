#ifndef KEYPADHANDLER_H
#define KEYPADHANDLER_H

#include <Keypad.h>
#include "settings.h"

#define KEYPAD_ROWS 4
#define KEYPAD_COLS 4

const char KEYS[KEYPAD_ROWS][KEYPAD_COLS] = {
	{'1', '2', '3', 'A'},
	{'4', '5', '6', 'B'},
	{'7', '8', '9', 'C'},
	{'*', '0', '#', 'D'}
};

#define INPUT_NORMAL 0
#define INPUT_MASTER 1

class KeypadHandler{
	public:
		KeypadHandler(
				const char row_pins[KEYPAD_ROWS],
				const char col_pins[KEYPAD_COLS]
			     );
		void loop();
		void reset();
		int getCommand();
		unsigned char getIndex(int index);

		enum Commands{
			WAIT = 0,
			AUTH_NORMAL = 1,
			AUTH_MASTER = 2,
			AUTH_LOGOUT = 3
		};
	private:
		void addKeyStroke(char key);
		void submit();

		//Variables:
		Keypad *_keypad;

		char _pressedKeys[PRESSED_KEYS_BUFFER_SIZE];
		int _pressedKeysCounter = 0;

		int _command;
		int _inputMode;

};

#endif
