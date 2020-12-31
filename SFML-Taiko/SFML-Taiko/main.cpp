/// <summary>
/// Taiko Drum SFML Controller Showcase
/// 
/// ---
/// Included in this project is a Taiko class, which uses SFML's Joystick in order to figure out
/// which part of the drum is being hit, and which side is being hit (Edge or Middle).
/// 
/// Using this, the Drum itself can be used as a controlled for niche game ideas with the drum in mind.
/// 
/// Created 31/12/2020
/// Time Taken: ~3 hours
/// 
/// ~~~~~~~~~~~~~~~~~
/// KNOWN BUGS:
/// Unsure if it's code-wise or Drum problem, but sometimes input is not taken in.
/// Requires further testing to figure out if it's a problem with Code or with how hard I'm hitting the Drum.
/// 
/// 
/// </summary>

#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-network-d.lib") 
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif 

#include "Game.h"

int main()
{
	Game game;
	game.run();

	return 0;
}