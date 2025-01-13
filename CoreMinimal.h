#pragma once

#pragma warning (disable : 4275)

// STL
#include <iostream>
#include <string>
#include <fstream>
#include <functional>

// OLD
#include <math.h>
#include <conio.h>

// Collections
#include <vector>
#include <queue>
#include <list>
#include <set>
#include <map>

// SFML
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

using namespace std;
using namespace sf;

typedef unsigned int u_int;

#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)

#define INLINE __inline
#define FORCEINLINE __forceinline
#define Super __super
#define SLEEP(_duration) sf::sleep(_duration)

#define DISPLAY(_text, _endl) if(_endl) cout << endl; \
										cout << _text;

#define DISPLAY_ERROR(_text, _endl) if(_endl) cerr << endl; \
										cerr << _text;