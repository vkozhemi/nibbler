#pragma once

#include <dlfcn.h>
#include <unistd.h>
#include "IGraph.hpp"
#include "../libSFMLSound/ISound.hpp"
#include "Snake.hpp"
#define MAX 80 

class Game
{
	eKeyType			libNum;
	void				*ext_library;
	void				*ext_library2;
	typedef IGraph*		create_t(Snake*, Snake*);
	typedef void		destroy_t(IGraph*);
	typedef ISound*		create_s();
	typedef void		destroy_s(ISound*);
	create_t*			creat;
	destroy_t*			destroy;
	create_s*			creatS;
	destroy_s*			destroyS;
	IGraph				*dynLib;
	ISound				*soundLib;
	Snake				*snake1;
	Snake				*snake2;
	int					speed;
	bool				multiplayer;
	bool				menu;
	bool				start;
	int					buttonNum;
	rect				appleRect;
	int					winner;
	int					gameOverCount;

public:

	Game();
	Game(int w, int h);
	Game(int w, int h, std::string ip);
	~Game();
	
	bool				client_serv;
	bool				server_clie;
	std::string 		ip;
	char 				buff[MAX]; 
    int 				n; 
    int 				sockfd;
    int 				connfd;
    bool 				mult;

	void	keyHandle(eKeyType key);
	void	getLib(eKeyType key);
	void	closeLib();
	void	mainCycle();
	void	generateApple();
	bool	checkCollision();
	bool	newGame();
	void	gameOver();
	void	server();
	void 	client();
	void	func_server();


};