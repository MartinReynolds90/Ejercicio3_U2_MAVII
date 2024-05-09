#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "SFMLRenderer.h"
#include <list>

using namespace sf;
class Game
{
private:
	// Propiedades de la ventana
	int alto;
	int ancho;
	RenderWindow* wnd;
	Color clearColor;

	// Objetos de box2d
	b2World* phyWorld;
	SFMLRenderer* debugRender;

	//tiempo de frame
	float frameTime;
	int fps;

	// Cuerpo de box2d
	b2Body* controlBody;
	b2Vec2 impulso = b2Vec2(6000.0f, 10000.0f);
	b2Vec2 origen = b2Vec2(10.0f, 10.0f);

public:

	// Constructores, destructores e inicializadores
	Game(int ancho, int alto, std::string titulo);
	void CheckCollitions();
	void CreateEnemy(int x, int y);
	~Game(void);
	void InitPhysics();

	// Main game loop
	void Loop();
	void DrawGame();
	void UpdatePhysics();
	void DoEvents();
	void SetZoom();
};


