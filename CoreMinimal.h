#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Macro.h"

using namespace std;
using namespace sf;

typedef unsigned int u_int;

#define DISPLAY(_text, _endl) if(_endl) cout << endl; \
										cout << _text;