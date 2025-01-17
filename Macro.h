#pragma once

#pragma warning (disable : 4275)

// STL
#include <iostream>
#include <string>
#include <fstream>
#include <functional>
#include <typeindex>
#include <typeinfo>
#include <cassert>
#include <Windows.h>

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

#define DEBUG_PATH

#ifdef DEBUG_PATH
#define PATH __FUNCTION__
#else
#define PATH __FILE__
#endif // DEBUG

#define DEBUG_INFO " (File : " + string(PATH) + " | Line : " + to_string(__LINE__) + ")"

#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)

#define INLINE __inline
#define FORCEINLINE __forceinline
#define Super __super
#define SLEEP(_duration) sf::sleep(_duration)

#define DISPLAY(_text, _endl) if(_endl) cout << endl; \
										cout << _text;

#define NO_DISCARD _NODISCARD


using namespace std;
using namespace sf;

typedef unsigned short u_short;
typedef unsigned int u_int;
typedef long long l_long;

