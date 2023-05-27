#include <rogue.h>

/*
- a104526 / Olavo Carreira
- a103995 / José Soares

Funções relacionada à parte gráfica do jogo
*/

// desenha toda a parte gráfica do jogo e é chamada iterativamente na funcao gameLoop(engine.c)
void drawEverything(gameState * game) {
    clear();
    drawMap(game->map);
    handleInventory(game);
    drawPlayer(game->user);
    drawInterfaceMobStatus(game);
    //if (game->interface)
    //else drawInterface(game->shop);
    verificaShop(game);
    drawSelected(game->shop);
    drawInventory(game->user, game->numTochas);
    drawStatus(game,contaMobs(game->mobs));
    //isMobVisible(game->shop,game->mobs, game->map);
    drawMobs(game->mobs, game->map);
    drawChests(game->chest, game->map);
    vericaCoins(game->user, game->mobs, game->chest);
    drawShop(game->shop, game->map);
    drawCoins(game->user);

}


/*
- a104526 / Olavo Carreira

Funções relacionada à parte gráfica do menu
*/

// draw (em processo) do menu inicial
void drawMenu(menu menu) {
    clear();
    attron(COLOR_PAIR(SWORDC));
    mvprintw(10,65," :::::::::::    :::::::        :::       ::::      :::    :::  :::::::: ");
    mvprintw(11,65,"  +:+    +:+   +:+   +:+     :+: :+:    :+:        :+:    :+:  :+:    :");
    mvprintw(12,65,"   +:+    +:+  +:+   +:+    +:+   +:+   +:+        +:+    +:+  +#+     ");
    mvprintw(13,65,"   +#++:++#+   +#++:++#++: +#+     ++: +#+   +:+   +#:    :+#  +#++:+# ");
    mvprintw(14,65,"   +#+    +#+  +#+   +#+   +#+     +#  +#+  +: +#  +#+    +#+  +#+     ");
    mvprintw(15,65,"   #+#    #+#  #+#    #+#   ##     ##   ##     ##  #+#    #+#  #+#     ");
    mvprintw(16,65,"   ###+  +###  ###     ##    ######      ######      ######    ###    #");
    mvprintw(17,65,"  ##########                                                   ########");
    attroff(COLOR_PAIR(SWORDC));

    char* image[] = {
  "           ,   ,",
  "         ,-`{-`/",
  "      ,-~ , \\ {-~~-,",
  "    ,~  ,   ,`,-~~-,`,",
  "  ,`   ,   { {      } }                                             }/",
  " ;     ,--/`\\ \\    / /                                     }/      /,/",
  ";  ,-./      \\ \\  { {  (                                  /,;    ,/ ,/",
  "; /   `       } } \\   `-`-.___                           / `,  ,/  `,/",
  " (|         ,`,`                                         / ,`,,/  ,`,;",
  "  `        {  {                                     __  /  ,`/   ,`,;",
  "        /   \\ \\                                 _,`, `{  `{   `,`;",
  "       {     } }       /~\\         .-:::-.     (--,   ;\\ `,}  `,`;",
  "       \\ \\_./ /      /` , \\      ,:::::::::,     `~;   \\},/  `,`;     ,=-",
  "        `-..-`      /. `  .\\_   ;:::::::::::;  __,{     `/  `,`;     {",
  "                   / , ~ . ^ `~`\\:::::::::::<<~>-,,`,    `-,  ``,_    }",
  "                /~~ . `  . ~  , .`~~`:::::::;    _-~  ;__,        `,-`",
  "       /`\\    /~,  . ~ , '  `  ,  .` `::::;`   <<<~```   ``-,,__   ;",
  "      /` .`\\ /` .  ^  ,  ~  ,  . ` . ~\\~                       \\ \\, `,__",
  "     / ` , ,`\\.  ` ~  ,  ^ ,  `  ~ . . ``~~~`,                   `-`--, \\",
  "    / , ~ . ~ \\ , ` .  ^  `  , . ^   .   , ` .`-,___,---,__            ``",
  "  /` ` . ~ . ` `\\ `  ~  ,  .  ,  `  ,  . ~  ^  ,  .  ~  , .`~---,Facha",
  "/` . `  ,  . ~ , \\  `  ~  ,  .  ^  ,  ~  .  `  ,  ~  .  ^  ,  ~  . . - `-,"
};

    for (int i = 0; i < 22; i++) {

        mvprintw(30+i,63,"%s\n", image[i]);
    }  

    if ((menu.jogar == 1) && (menu.sair == 0) && (menu.tutorial == 0)) {

        mvprintw(26,89,"-|==>");
        attron(A_REVERSE | COLOR_PAIR(SWORDC));
        mvprintw(26,95,"PLAY");
        attroff(A_REVERSE | COLOR_PAIR(SWORDC));
        mvprintw(27,95,"SAIR");
        mvprintw(28,95,"TUTORIAL");
    
                                                                                                       
                        
    }
    else if ((menu.jogar == 0) && (menu.sair == 1) && (menu.tutorial == 0)) {
        mvprintw(26,95,"PLAY");
        mvprintw(27,89,"-|==>");
        attron(A_REVERSE | COLOR_PAIR(SWORDC));
        mvprintw(27,95,"SAIR");
        attroff(A_REVERSE | COLOR_PAIR(SWORDC));
        mvprintw(28,95,"TUTORIAL");

    } 
    else if ((menu.jogar == 0) && (menu.sair == 0) && (menu.tutorial == 1)) {
        mvprintw(26,95,"PLAY");
        mvprintw(27,95,"SAIR");
        mvprintw(28,89,"-|==>");
        attron(A_REVERSE | COLOR_PAIR(SWORDC));
        mvprintw(28,95,"TUTORIAL");
        attroff(A_REVERSE | COLOR_PAIR(SWORDC));
    }
    

}

/*
- a104526 / Olavo Carreira

Funções relacionada à parte gráfica do tutorial
*/

void drawTutorial () {
    
      mvprintw(5,55,"ooooooooooooo ooooo     ooo ooooooooooooo   .oooooo.   ooooooooo.   ooooo       .o.       ooooo");        
        mvprintw(6,55,"8'   888   `8 `888'     `8' 8'   888   `8  d8P'  `Y8b  `888   `Y88. `888'      .888.      `888'");       
        mvprintw(7,55,"     888       888       8       888      888      888  888   .d88'  888      .8`888.      888 ");        
        mvprintw(8,55,"     888       888       8       888      888      888  888ooo88P'   888     .8' `888.     888 ");        
        mvprintw(9,55,"     888       888       8       888      888      888  888`88b.     888    .88ooo8888.    888 ");        
        mvprintw(10,55,"     888       `88.    .8'       888      `88b    d88'  888  `88b.   888   .8'     `888.   888       o");
        mvprintw(11,55,"    o888o        `YbodP'        o888o      `Y8bood8P'  o888o  o888o o888o o88o     o8888o o888ooooood8");

        //estruturas
        mvprintw(15,10,"+-+-+-+-+-+-+-+-+-+-+");
        mvprintw(16,10,"|E|s|t|r|u|t|u|r|a|s|");
        mvprintw(17,10,"+-+-+-+-+-+-+-+-+-+-+");

        mvprintw(18,11,"-> Shop ($):");
        mvprintw(19,11,"    O vendedor desta loja é um ser misterioso, por isso tens que");
        mvprintw(20,11,"    o procurar se quiseres comprar melhor gear para as tuas aventuras");

        mvprintw(22,11,"-> Entrada Dungeon (/): ");
        mvprintw(23,11,"    A entrada é um portal que te leva para outro mundo mais perigoso.");
        mvprintw(24,11,"    O portal puxa-te e não a volta a dar. Se nao tiveres preparado");
        mvprintw(25,11,"    para embarcar numa aventura mais dificil, NAO TE APROXIMES DELE.");

        mvprintw(27,11,"-> Baus (&)");
        mvprintw(28,11,"    Aventureiros que morreram durante as suas missoes deixaram tesouros");
        mvprintw(29,11,"    com as suas fortunas para tras. Se encontrares uam destes baus, teras");
        mvprintw(30,11, "    muita sorte, visto que, ganhas coins para gastar na shop.");
        mvprintw(31,11,"    Mas CUIDADO que muitas vezes os monstros ficam a espera ao lado deles.");

        //jogador
        mvprintw(33,10,"+-+-+-+-+-+-+-+");
        mvprintw(34,10,"|J|o|g|a|d|o|r|");
        mvprintw(35,10,"+-+-+-+-+-+-+-+");

        mvprintw(37,10,"Podes movimentar o jogador nas setas to teclado");
        mvprintw(38,10,"O jogador tem uma barra de vida e uma de stamina (devido a armadura andar custa)");
        mvprintw(39,10,"Para abrir baus ou atacar mobs aperta ENTER");
        mvprintw(40,10,"Para trocares o item q tens na mao, troca com '1'-'2'-'3'");

        //objetivo
        mvprintw(42,10,"+-+-+-+-+");
        mvprintw(43,10,"|J|o|g|o|");
        mvprintw(44,10,"+-+-+-+-+");

        mvprintw(46,10,"O objetivo do jogo é matar todos os mobs e completar a dungeon.");
        mvprintw(47,10,"Acumula o maximo de coins possivel e compra o melhor gear antes");
        mvprintw(48,10,"de ires para a dungeon. As armas tem diferentes classes, quanto");
        mvprintw(49,10,"mais alta for a class mais dano da.... mas o preço é ACRESCIDO");

        //Monstros
        mvprintw(15,110,"+-+-+-+-+");
        mvprintw(16,110,"|M|o|b|s|");
        mvprintw(17,110,"+-+-+-+-+");

        mvprintw(19,110,"Existem diversos mobs que poderas encontrar nas tuas aventuras.");
        mvprintw(20,110,"Nao se sabe ao certo, que mago o fez, mas alguem encantou os mobs,");
        mvprintw(21,110,"da floresta. Agora, sempre que veem um aventureiro atacam-no,");
        mvprintw(22,110,"e NUNCA o deixam escapar.....Por isso tem cuidado");

        mvprintw(24,111," ->Kobold (K):");
        mvprintw(25,111,"Os Kobolds sao criaturas reptilinas, que nao gostam de luz.");
        mvprintw(26,111,"Nao sao os mais fortes da floresta, mas presta atençao na mesma");

        mvprintw(28,111," ->Orc (O):");
        mvprintw(29,111,"Os Orcs devem ser as criaturas mais agressivas desta floresta.");
        mvprintw(30,111,"Sao criaturas dificeis de matar devido a sua armadura de metal");

        mvprintw(32,111," ->Goblins (G):");
        mvprintw(33,111,"Os Goblins sao criaturas traicoeiras e rapidas.");
        mvprintw(34,111,"Sao uma versao enfraquecida dos Orcs");

        mvprintw(32,111," ->Troll (T):");
        mvprintw(33,111,"Os Trolls sao os reis da floresta.");
        mvprintw(34,111,"Sao seres gigantes e a maior parte das outras criaturas tem medo deles");

        mvprintw(36,111," ->Zombie (Z):");
        mvprintw(37,111,"Os Zombies, sao mortos vivos que lamentam as suas vidas passadas.");
        mvprintw(38,111,"Ao contrario doque podes pensar sao seres inteligentes");

        mvprintw(40,111," ->Creeper (C):");
        mvprintw(41,111,"Os Creepers sao seres irracionais, mas é melhor tratar deles de longe.");
        mvprintw(42,111,"Originalmente eram plantas, mas uma forca especial felos tornarem-se as criaturas que sao");

        mvprintw(44,111," ->Demon (D):");
        mvprintw(45,111,"Os Demon sao criaturas caoticas do inferno.");
        mvprintw(46,111,"Conseguem transformar-se na forma mais assutadora para quem o ve");

        mvprintw(48,111," ->Slime (S):");
        mvprintw(49,111,"Os Slimes sao criaturas que absorvem os corpos de aventureiros mortos");
        mvprintw(50,111,"e assumem a sua forma. Ao contrario doque se pensa, sao mortiferos");

        mvprintw(52,111," ->Wyrm (W):");
        mvprintw(53,111,"As Wyrms, sao dragões capazes de destruir nacoes inteiras.");
        mvprintw(54,111,"Se os Trolls sao os reis da floresta, as Wyrms sao as rainhas");

        mvprintw(56,111," ->DarqueMan (M):");
        mvprintw(57,111,"O DarqueMan é o pior inimigo que podes encontrar na tua vida.");
        mvprintw(58,111,"Muito fortes fisicamente e acima de tudo ladroes de elite.");  
}

/*
- a104526 / Olavo Carreira

Funções relacionada à parte gráfica de quando o user morre
*/

void drawDeath () {

        init_pair(101, COLOR_RED, COLOR_BLACK);

        attron (COLOR_PAIR (101));
        mvprintw(10,55,"ooo        ooooo       .o.       ooooo  .oooooo..o " );
        mvprintw(11,55," `88.      .888'      .888.      `888' d8P'    `Y8 " );
        mvprintw(12,55," 888b     d'888      .8'888.      888  Y88bo.    " );
        mvprintw(13,55," 8 Y88. .P  888     .8' `888.     888   `'Y8888o. " );
        mvprintw(14,55," 8  `888'   888    .88ooo8888.    888       `'Y88b " );
        mvprintw(15,55," 8    Y     888   .8'     `888.   888  oo     .d8P " );
        mvprintw(16,55,"o8o        o888o o88o     o8888o o888o 8""88888P' " );

        mvprintw(20,30," .oooooo..o   .oooooo.    ooooooooo.  ooooooooooooo oooooooooooo      ooooo      ooo       .o.  ");
        mvprintw(21,30,"d8P'    `Y8 d8P'   `Y8b  `888   `Y88. 8'   888   `8 `888'     `8      `888b.     `8'      .888.    ");
        mvprintw(22,30,"Y88bo.      888      888  888   .d88'      888       888               8 `88b.    8      .8'888.    ");
        mvprintw(23,30," `'Y8888o.  888      888  888ooo88P'       888       888oooo8          8   `88b.  8     .8' `888.    ");
        mvprintw(24,30,"     `'Y88b 888      888  888`88b.         888       888    '          8     `88b.8    .88ooo8888.   ");
        mvprintw(25,30,"oo     .d8P `88b    d88'  888  `88b.       888       888       o       8       `888   .8'     `888.   ");
        mvprintw(26,30,"  8""88888P'   `Y8bood8P'  o888o  o888o     o888o     o888ooooood8      o8o        `8  o88o     o8888o ");

        mvprintw(30,35,"ooooooooo.   ooooooooo.     .oooooo.   ooooooo  ooooo ooooo ooo        ooooo       .o.  ");
        mvprintw(31,35,"`888   `Y88. `888   `Y88.  d8P'  `Y8b   `8888    d8'  `888' `88.       .888'      .888.        ");
        mvprintw(32,35," 888   .d88'  888   .d88' 888      888    Y888..8P     888   888b     d'888      .8'888.        ");
        mvprintw(33,35," 888ooo88P'   888ooo88P'  888      888     `8888'      888   8 Y88. .P  888     .8' `888.       ");
        mvprintw(34,35," 888          888`88b.    888      888    .8PY888.     888   8  `888'   888    .88ooo8888.   ");
        mvprintw(35,35," 888          888  `88b.  `88b    d88'   d8'  `888b    888   8    Y     888   .8'     `888.    ");
        mvprintw(36,35,"o888o        o888o  o888o  `Y8bood8P'  o888o  o88888o o888o o8o        o888o o88o     o8888o ");

        attroff(COLOR_PAIR (101));
}

/*
- a104526 / Olavo Carreira

Função relacionada à parte gráfica de quando o user morre
*/
void drawVictory () {

        clear();

        mvprintw(10,50,"  .oooooo.      .oooooo.   ooooo      ooo  .oooooo..o oooooooooooo   .oooooo.    ooooo     ooo ooooo  .oooooo..o ooooooooooooo oooooooooooo");
        mvprintw(11,50,"d8P'  `Y8b   d8P'   `Y8b  `888b.     `8' d8P'    `Y8  `888'     `8  d8P'  `Y8b   `888'     `8' `888' d8P'    `Y8 8'   888   `8 `888'     `8");
        mvprintw(12,50,"888          888      888  8 `88b.    8  Y88bo.        888         888            888       8   888  Y88bo.           888       888");
        mvprintw(13,50,"888          888      888  8   `88b.  8   `'Y8888o.    888oooo8    888            888       8   888   `'Y8888o.       888       888oooo8");
        mvprintw(14,50,"888          888      888  8     `88b.8       `'Y88b   888    '    888     ooooo  888       8   888       `'Y88b      888       888    '");
        mvprintw(15,50,"`88b    ooo  `88b    d88'  8       `888  oo     .d8P   888       o `88.    .88'   `88.    .8'   888  oo     .d8P      888       888       o");
        mvprintw(16,50," `Y8bood8P'   `Y8bood8P'  o8o        `8  88888888P'  o888ooooood8   `Y8bood8P'      `YbodP'    o888o 88888888P'      o888o     o888ooooood8");                                                                                                                                                                                                                                         

        mvprintw(20,50," oooooooooooo  .oooooo..o   .oooooo.         .o.       ooooooooo.         .o.       ooooooooo.");
        mvprintw(21,50," `888'     `8 d8P'    `Y8  d8P'  `Y8b       .888.      `888   `Y88.      .888.      `888   `Y88.  ");
        mvprintw(22,50,"  888         Y88bo.      888              .8'888.      888   .d88'     .8'888.      888   .d88'  ");
        mvprintw(23,50,"  888oooo8     `Y8888o.  888              .8 `888.      888ooo88P'     .8' `888.     888ooo88P  ");
        mvprintw(24,50,"  888    '         `'Y88b 888            .88ooo8888.    888           .88ooo8888.    888`88b.    ");
        mvprintw(25,50,"  888       o oo     .d8P `88b    ooo   .8'     `888.   888          .8'     `888.   888  `88b.   ");
        mvprintw(26,50," o888ooooood8 88888888P'   `Y8bood8P'  o88o     o8888o o888o        o88o     o8888o o888o  o888o ");                                                                                                                                                                                                                                         
                                                                                                                                                                                                                                                                                                                                            

}

/*
- a104446 / Nuno Melo
- a103995 / José Soares

Função relacionada à parte gráfica do mapa
*/

// draw do map, funcao chamada depois da inicialização e criacao do mapa na drawMap
void drawMap(tile ** map) {
    int rows = 50; 
	int cols = 145;
	for (int y = 0; y < rows; y++)
	{
		for (int x = 0; x < cols; x++)
		{
			if (map[y][x].visible)
			{   //se o espaço for visivel, a funcao drawMap desenha o char da cor VISIBLE
				mvaddch(y+3, x+3, map[y][x].ch | COLOR_PAIR(VISIBLE_COLOR) | A_BOLD);
			}
            if (map[y][x].seen)
            {   //se o espaço ja nao for visivel, a funcao drawMap desenha o char da cor SEEN
				mvaddch(y+3, x+3, map[y][x].ch | COLOR_PAIR(SEEN_COLOR));
			}
            if (map[y][x].transparent)
            {   //se o espaço ja nao for visivel, a funcao drawMap desenha o char da cor SEEN
				mvaddch(y+3, x+3, map[y][x].ch | COLOR_PAIR(TRANSPARENT_COLOR));
			}
            if (map[y][x].visibleT)
            {   //se o espaço ja nao for visivel, a funcao drawMap desenha o char da cor SEEN
				mvaddch(y+3, x+3, map[y][x].ch | COLOR_PAIR(VISIBLE_COLOR) | A_BOLD);
			}
		}
	}
}

/*
- a104092 / Diogo Outeiro

Função relacionada à parte gráfica do user
*/

// draw do player na sua posição atual
void drawPlayer(player * user) {
    mvaddch(user->pos.y, user->pos.x, user->ch | user->color);
}

/*
- a104526 / Olavo Carreira

Função relacionada à parte gráfica  de desenhar os mobs
*/

// draw do mob 
void drawMob(entity_mob mob, tile ** map) {
    int margem = 3;
    if (mob.visible && map[mob.pos.y-margem][mob.pos.x-margem].walkable && mob.vida > 0)
        mvaddch(mob.pos.y,mob.pos.x,mob.ch | COLOR_PAIR(SWORDC));
    else if (mob.visible && map[mob.pos.y-margem][mob.pos.x-margem].walkable && mob.coins > 0)
        mvaddch(mob.pos.y,mob.pos.x,mob.ch | COLOR_PAIR(COLOR_MAGENTA));
}

/*
- a104526 / Olavo Carreira

Função relacionada à parte gráfica  de desenhar os mobs
*/

void drawMobs(entity_mob mobs[], tile **map) {
    int  numMobs = 30;
    for (int i = 0; i < numMobs; i++) { // percorre o array de mobs
        drawMob(mobs[i], map); // desenha o mob atual
    }
}

/*
- a104526 / Olavo Carreira

Função relacionada à parte gráfica  de desenhar os chests
*/

void drawChest(chest chest, tile ** map) {
    int margem = 3;
    if (chest.visible && map[chest.pos.y-margem][chest.pos.x-margem].walkable && chest.vida > 0)
        mvaddch(chest.pos.y,chest.pos.x,chest.ch | COLOR_PAIR(BOWC));
    else if (chest.visible && map[chest.pos.y-margem][chest.pos.x-margem].walkable && chest.coins > 0)
        mvaddch(chest.pos.y,chest.pos.x,chest.ch | COLOR_PAIR(COLOR_MAGENTA));
}

/*
- a104526 / Olavo Carreira

Função relacionada à parte gráfica  de desenhar os chests
*/

void drawChests(chest chest[], tile **map) {
    int  numChests = 8;
    for (int i = 0; i < numChests; i++) { // percorre o array de mobs
        if (map[(chest+i)->pos.y-3][(chest+i)->pos.x-3].visible || map[(chest+i)->pos.y-3][(chest+i)->pos.x-3].visibleT)
            drawChest(chest[i], map); // desenha o mob atual
    }
}


/*
- a104526 / Olavo Carreira

Função relacionada à parte gráfica  de desenhar a shop
*/

void drawShop(shop * shop, tile ** map) {
    int margem = 3;
    if (map[shop->pos.y-margem][shop->pos.x-margem].visible || map[shop->pos.y-margem][shop->pos.x-margem].visibleT)
        mvaddch(shop->pos.y,shop->pos.x,shop->ch | COLOR_PAIR(SWORDC));
}

/*
- a104526 / Olavo Carreira

Função relacionada à parte gráfica  de desenhar o inventário
*/

// draw do Inventory do user
void drawInventory(player * user, int numTochas) {
    mvprintw(14,160,"+---------------------------------------+");
    mvprintw(15,160,"| =Inventory=                           |");
    mvprintw(16,160,"|                                       |");
    if (user->sword.dano > 0)
        mvprintw(17,160,"|  (1) Sword - DG: %d Rank: %c           |", user->sword.dano, user->sword.class);
    else mvprintw(17,160,"|                                       |");
    if (user->bow.dano > 0)
        mvprintw(18,160,"|  (2) Bow - DG: %d Rank: %c             |", user->bow.dano, user->bow.class);
    else mvprintw(18,160,"|                                       |");
    if (user->potion.class == 'A')
        mvprintw(19,160,"|  (3) Potion - DG: %d Rank: %c          |",user->potion.dano, user->potion.class);
    else if (user->potion.class == 'H')
        mvprintw(19,160,"|  (3) Potion - HL: %d Rank: %c  Q:%2d    |",user->potion.dano, user->potion.class, user->potion.get[1]);
    else if (user->potion.class == 'S')
        mvprintw(19,160,"|  (3) Potion - ST: %d Rank: %c  Q:%2d    |",user->potion.dano, user->potion.class, user->potion.get[2]);
    else mvprintw(19,160,"|                                       |");
    mvprintw(20,160,"|  (4) Tochas - Q:%d                     |",numTochas);
    mvprintw(21,160,"|                                       |");
    mvprintw(22,160,"+---------------------------------------+");
}

/*
- a104526 / Olavo Carreira

Função relacionada à parte gráfica  de desenhar as coins
*/

// draw da quantidade de moedas do user
void drawCoins(player * user) {
    mvprintw(5,160,"+---------+");
    mvprintw(6,160,"|         |");
    mvprintw(7,160,"|  %.5d  |",user->coins);
    mvprintw(8,160,"|  Coins  |");
    mvprintw(9,160,"|         |");
    mvprintw(10,160,"+---------+");
}


/*
- a104526 / Olavo Carreira

Função relacionada à parte gráfica  de desenhar a interface
*/

void drawInterfaceMobStatus(gameState * game) {
    int numMobs = 30;
    mvprintw(24,160,"+---------------------------------------+");
    mvprintw(25,160,"| =MAP STATUS=                          |");
    mvprintw(26,160,"|                                       |");
    mvprintw(27,160,"|  (1) You                              |");
    if (game->shop->visible == 1)
        mvprintw(28,160,"|  (2) Shop                             |");
    else 
        mvprintw(28,160,"|                                       |");
    mvprintw(29,160,"|                                       |");
    mvprintw(30,160,"|                                       |");
    mvprintw(31,160,"|                                       |");
    mvprintw(32,160,"|                                       |");
    mvprintw(33,160,"|                                       |");
    mvprintw(34,160,"|                                       |");
    mvprintw(35,160,"|                                       |");
    mvprintw(36,160,"|                                       |");
    mvprintw(37,160,"|                                       |");
    mvprintw(38,160,"|                                       |");
    mvprintw(39,160,"|                                       |");
    mvprintw(40,160,"|                                       |");
    mvprintw(41,160,"|                                       |");
    mvprintw(42,160,"|                                       |");
    mvprintw(43,160,"|                                       |");
    mvprintw(44,160,"|                                       |");
    mvprintw(45,160,"|                                       |");
    mvprintw(46,160,"|                                       |");
    mvprintw(47,160,"|                                       |");
    mvprintw(48,160,"+---------------------------------------+");
    int j = 0; // variável auxiliar para percorrer a lista de mobs visíveis
    int i = 3;
    int linha = 33;
    while (j < numMobs) {
        if ((game->mobs+j)->visible && (game->mobs+j)->coins > 0) {
            mvprintw(linha,161,"  (%d) %5s | HP: %4d ",i,(game->mobs+j)->nome,(game->mobs+j)->vida);
            linha++;
            i++;
        }
        j++; // atualiza j para o próximo mob
    }
    int l = 0;
    i = 3;
    int linha1 = 30;
    while (l < 8) {
        if ((game->chest+l)->visible && (game->chest+l)->coins > 0) {
            mvprintw(linha1,161,"  (%d) Chest | HP: %4d ",i,(game->chest+l)->vida);
            linha1++;
            i++;
        }
        l++; // atualiza j para o próximo mob
    }
}


/*
- a104526 / Olavo Carreira

Função relacionada à parte gráfica  de desenhar a interface da shop
*/

void drawShopInterface() {
    mvprintw(24,160,"+---------------------------------------+");
    mvprintw(25,160,"| =SHOP LIST=                           |");
    mvprintw(26,160,"|                                       |");
    mvprintw(27,160,"|  (z) Swords                           |");
    mvprintw(28,160,"|         |______________               |");
    mvprintw(29,160,"|  [======|______________>              |");
    mvprintw(30,160,"|         |                             |");
    mvprintw(31,160,"|                                       |");
    mvprintw(32,160,"|  (x) Bows                             |");
    mvprintw(33,160,"|                                       |");
    mvprintw(34,160,"|      (                                |");
    mvprintw(35,160,"|       )                               |");
    mvprintw(36,160,"|   ##-------->                         |");
    mvprintw(37,160,"|       )                               |");
    mvprintw(38,160,"|      (                                |");
    mvprintw(39,160,"|                                       |");
    mvprintw(40,160,"|  (c) Potions                          |");
    mvprintw(41,160,"|      :~:                              |");
    mvprintw(42,160,"|      | |                              |");
    mvprintw(43,160,"|     .' `.                             |");
    mvprintw(44,160,"|   .'     `.                           |");
    mvprintw(45,160,"|   |       |                           |");
    mvprintw(46,160,"|    `.._..'                            |");
    mvprintw(47,160,"|                                       |");
    mvprintw(48,160,"+---------------------------------------+");
}

/*
- a104526 / Olavo Carreira

Função relacionada à parte gráfica de desenhar o item selecionado
*/

void drawSelected(shop * shop) {
    switch (shop->state)
    {
    case 1:
        switch (shop->sword)
        {
        case 1:
            mvaddch(44,166,'O' | COLOR_PAIR(SWORDC));
            break;
        case 2:
            mvaddch(44,179,'O' | COLOR_PAIR(SWORDC));
            break;
        case 3:
            mvaddch(44,191,'O' | COLOR_PAIR(SWORDC));
            break;
        default:
            break;
        }
        break;
    case 2:
        switch (shop->bow)
        {
        case 1:
            mvaddch(44,166,'O' | COLOR_PAIR(SWORDC));
            break;
        case 2:
            mvaddch(44,179,'O' | COLOR_PAIR(SWORDC));
            break;
        case 3:
            mvaddch(44,191,'O' | COLOR_PAIR(SWORDC));
            break;
        default:
            break;
        }
        break;
    case 3:
        switch (shop->potion)
        {
        case 1:
            mvaddch(41,166,'O' | COLOR_PAIR(SWORDC));
            break;
        case 2:
            mvaddch(41,179,'O' | COLOR_PAIR(SWORDC));
            break;
        case 3:
            mvaddch(41,191,'O' | COLOR_PAIR(SWORDC));
            break;
        default:
            break;
        }
        break;
    default:
        break;
    }
}

/*
- a104526 / Olavo Carreira

Função relacionada à parte gráfica de desenhar a pagina Swords
*/

void drawShopInterfaceSword() {
    mvprintw(24,160,"+---------------------------------------+");
    mvprintw(25,160,"| =Swords=                              |");
    mvprintw(26,160,"|                                       |");
    mvprintw(27,160,"|    __                                 |");
    mvprintw(28,160,"|    ||            /|          N        |");
    mvprintw(29,160,"|   _||_          |||          U        |");
    mvprintw(30,160,"|  ( || )         |O|          N        |");
    mvprintw(31,160,"|    ||           |L|       ___O___     |");
    mvprintw(32,160,"|    ||           |A|         | |       |");
    mvprintw(33,160,"|    ||           |V|         | |       |");
    mvprintw(34,160,"|    ||           |O|         | |       |");
    mvprintw(35,160,"|    ||           |||         | |       |");
    mvprintw(36,160,"|    ||        ~-[{o}]-~      | |       |");
    mvprintw(37,160,"|    ||           |/|         | |       |");
    mvprintw(38,160,"|    |/           |_|         |/        |");
    mvprintw(39,160,"|                                       |");
    mvprintw(40,160,"|  Dano: 24    Dano: 30     Dano: 40    |");
    mvprintw(41,160,"|  Rank: B     Rank: A      Rank: S     |");
    mvprintw(42,160,"|  Cost: 3000  Cost: 6000   Cost: 10000 |");
    mvprintw(43,160,"|                                       |");
    mvprintw(44,160,"|                                       |");
    mvprintw(45,160,"|                                       |");
    mvprintw(46,160,"| (n) <- | (m) -> | (b) buy |  (v) sair |");
    mvprintw(47,160,"|                                       |");
    mvprintw(48,160,"+---------------------------------------+");
}

/*
- a104526 / Olavo Carreira

Função relacionada à parte gráfica de desenhar a pagina Bows
*/

void drawShopInterfaceBows() {
    mvprintw(24,160,"+---------------------------------------+");
    mvprintw(25,160,"| =Bows=                                |");
    mvprintw(26,160,"|                                       |");
    mvprintw(27,160,"|                                       |");
    mvprintw(28,160,"|                                       |");
    mvprintw(29,160,"|     (                                 |");
    mvprintw(30,160,"|      )                                |");
    mvprintw(31,160,"|      (                                |");
    mvprintw(32,160,"|    ##------>                          |");
    mvprintw(33,160,"|      (                                |");
    mvprintw(34,160,"|      )                                |");
    mvprintw(35,160,"|     (                                 |");
    mvprintw(36,160,"|                                       |");
    mvprintw(37,160,"|  Dano: 20                             |");
    mvprintw(38,160,"|  Rank: A                              |");
    mvprintw(39,160,"|  Cost: 4000                           |");
    mvprintw(40,160,"|                                       |");
    mvprintw(41,160,"|                                       |");
    mvprintw(42,160,"|                                       |");
    mvprintw(43,160,"|                                       |");
    mvprintw(44,160,"|                                       |");
    mvprintw(45,160,"|                                       |");
    mvprintw(46,160,"| (n) <- | (m) -> | (b) buy |  (v) sair |");
    mvprintw(47,160,"|                                       |");
    mvprintw(48,160,"+---------------------------------------+");
}

/*
- a104526 / Olavo Carreira

Função relacionada à parte gráfica de desenhar a pagina potions
*/

void drawShopInterfacePotions() {
    mvprintw(24,160,"+---------------------------------------+");
    mvprintw(25,160,"| =Potions=                             |");
    mvprintw(26,160,"|                                       |");
    mvprintw(27,160,"|                                       |");
    mvprintw(28,160,"|                                       |");
    mvprintw(29,160,"|     _            |                    |");
    mvprintw(30,160,"|   ,|||.         -+-           ||      |");
    mvprintw(31,160,"|   |||||        /-`-.        __(l      |");
    mvprintw(32,160,"|   ||||/)       :   :       :   :      |");
    mvprintw(33,160,"|   \\,,, /       : H :       : M :      |");
    mvprintw(34,160,"|   |___|        :___:       :___:      |");
    mvprintw(35,160,"|                                       |");
    mvprintw(36,160,"|  Repulsion      Heal       Stamina    |");
    mvprintw(37,160,"|  Rank: B      Use:100 HP   Use:100 SM |");
    mvprintw(38,160,"|  Cost: 2000   Cost: 1000   Cost: 1000 |");
    mvprintw(39,160,"|                                       |");
    mvprintw(40,160,"|                                       |");
    mvprintw(41,160,"|                                       |");
    mvprintw(42,160,"|                                       |");
    mvprintw(43,160,"|                                       |");
    mvprintw(44,160,"|                                       |");
    mvprintw(45,160,"|                                       |");
    mvprintw(46,160,"| (n) <- | (m) -> | (b) buy |  (v) sair |");
    mvprintw(47,160,"|                                       |");
    mvprintw(48,160,"+---------------------------------------+");
}

/*
- a104526 / Olavo Carreira

Função relacionada à parte gráfica de desenhar o status do jogo
*/

// draw do Status
void drawStatus(gameState * game, int num) {
    mvprintw(5,179, "+--------------------+");
    mvprintw(6,179, "|                    |");
    if (game->user->vida > 0)
        mvprintw(7,179, "|  HP: %3d/500       |", game->user->vida);
    else mvprintw(7,179, "|  HP:   0/500       |");
    if (game->user->stamina > 0)
        mvprintw(8,179, "|  Stamina: %3d/500  |", game->user->stamina);
    else mvprintw(8,179, "|  Stamina:   0/500  |");
    mvprintw(9,179, "|  Mobs: %2d/30       |",num);
    mvprintw(10,179,"|                    |");
    mvprintw(11,179,"+--------------------+");
}

/*
- a104526 / Olavo Carreira

Função que conta e adiciona coins ao status do user
*/

void vericaCoins(player * user, entity_mob * mobs, chest * chests) {
    int numMobs = 30;
    for (int i = 0; i< numMobs; i++) {
        if ((mobs+i)->pos.y == user->pos.y && (mobs+i)->pos.x == user->pos.x && (mobs+i)->vida <= 0) {
                    user->coins += (mobs+i)->coins;
                    (mobs+i)->coins = 0;
                }
        if ((chests+i)->pos.y == user->pos.y && (chests+i)->pos.x == user->pos.x && (chests+i)->vida <= 0) {
                    user->coins += (chests+i)->coins;
                    (chests+i)->coins = 0;
                }
    }
}

/*

           ,   ,
         ,-`{-`/
      ,-~ , \ {-~~-,
    ,~  ,   ,`,-~~-,`,
  ,`   ,   { {      } }                                             }/
 ;     ,--/`\ \    / /                                     }/      /,/
;  ,-./      \ \  { {  (                                  /,;    ,/ ,/
; /   `       } } `, `-`-.___                            / `,  ,/  `,/
 \|         ,`,`    `~.___,---}                         / ,`,,/  ,`,;
  `        { {                                     __  /  ,`/   ,`,;
        /   \ \                                 _,`, `{  `,{   `,`;`
       {     } }       /~\         .-:::-.     (--,   ;\ `,}  `,`;
       \\._./ /      /` , \      ,:::::::::,     `~;   \},/  `,`;     ,-=-
        `-..-`      /. `  .\_   ;:::::::::::;  __,{     `/  `,`;     {
                   / , ~ . ^ `~`\:::::::::::<<~>-,,`,    `-,  ``,_    }
                /~~ . `  . ~  , .`~~`:::::::;    _-~  ;__,        `,-`
       /`\    /~,  . ~ , '  `  ,  .` `::::;`   <<<~```   ``-,,__   ;
      /` .`\ /` .  ^  ,  ~  ,  . ` . ~\~                       \\, `,__
     / ` , ,`\.  ` ~  ,  ^ ,  `  ~ . . ``~~~`,                   `-`--, \
    / , ~ . ~ \ , ` .  ^  `  , . ^   .   , ` .`-,___,---,__            ``
  /` ` . ~ . ` `\ `  ~  ,  .  ,  `  ,  . ~  ^  ,  .  ~  , .`~---,___
/` . `  ,  . ~ , \  `  ~  ,  .  ^  ,  ~  .  `  ,  ~  .  ^  ,  ~  .  `-,

       |______________
[======|______________>  
       |
       '
   (
    \
     )
##--------> 
     )
    /
   (

   :~:    
   | |    
  .' `.   
.'     `. 
|       | 
 `.._..' 

    mvprintw(24,160,"+---------------------------------------+");
    mvprintw(25,160,"| =Swords=                              |");
    mvprintw(26,160,"|                                       |");
    mvprintw(27,160,"|    __                                 |");
    mvprintw(28,160,"|    ||            /|          N        |");
    mvprintw(29,160,"|   _||_          |||          U        |");
    mvprintw(30,160,"|  ( || )         |||          N        |");
    mvprintw(31,160,"|    ||           |||       ___O___     |");
    mvprintw(32,160,"|    ||           |||         | |       |");
    mvprintw(33,160,"|    ||           |||         | |       |");
    mvprintw(34,160,"|    ||           |||         | |       |");
    mvprintw(35,160,"|    ||           |||         | |       |");
    mvprintw(36,160,"|    ||        ~-[{o}]-~      | |       |");
    mvprintw(37,160,"|    ||           |/|         | |       |");
    mvprintw(38,160,"|    ||           |/|         | )       |");
    mvprintw(39,160,"|    |/           |_|         |/        |");
    mvprintw(40,160,"|                                       |");
    mvprintw(41,160,"|  Dano: 24    Dano: 30     Dano: 40    |");
    mvprintw(42,160,"|  Rank: B     Rank: A      Rank: S     |");
    mvprintw(43,160,"|  Cost: 4000  Cost: 5000   Cost: 7000  |");
    mvprintw(44,160,"|                                       |");
    mvprintw(45,160,"|                                       |");
    mvprintw(46,160,"|                                       |");
    mvprintw(47,160,"|                                       |");
    mvprintw(48,160,"+---------------------------------------+");
  __
  ||
 _||_
( || )
  ||
  ||
  ||
  ||
  ||
  ||
  ||
  \/  

    /|
   |\|
   |||
   |||
   |||
   |||
   |||
   |||
~-[{o}]-~
   |/|
   |/|

   O
   D
   I
___E___
  | |
  | |
  | |
  | |
  | |
  | |
  | |
  \ /
   '

       /\
/vvvvvvv \----------------------------,
`^^^^^^^ /==========================="
       \/



    \|/
   - o -
    /-`-.
    :   :
    :TNT:
    :___:

    char* image[] = {
  "                                                                           ,   ,",
  "                                                                         ,-`{-`/",
  "                                                                      ,-~ , \\ {-~~-,",
  "                                                                    ,~  ,   ,`,-~~-,`,",
  "                                                                  ,`   ,   { {      } }                                             }/    ",
  "                                                                 ;     ,--/`\\ \\    / /                                     }/      /,/  ",
  "                                                                ;  ,-./      \\ \\  { {  (                                  /,;    ,/ ,/  ",
  "                                                                ; /   `       } } \\   `-`-.___                           / `,  ,/  `,/   ",
  "                                                                 (|         ,`,`                                         / ,`,,/  ,`,;    ",
  "                                                                  `        {  {                                     __  /  ,`/   ,`,; ",
  "                                                                        /   \\ \\                                 _,`, `{  `{   `,`;  ",
  "                                                                       {     } }       /~\\         .-:::-.     (--,   ;\\ `,}  `,`;  ",
  "                                                                       \\ \\_./ /      /` , \\      ,:::::::::,     `~;   \\},/  `,`;     ,=- ",
  "                                                                        `-..-`      /. `  .\\_   ;:::::::::::;  __,{     `/  `,`;     {   ",
  "                                                                                   / , ~ . ^ `~`\\:::::::::::<<~>-,,`,    `-,  ``,_    }  ",
  "                                                                                /~~ . `  . ~  , .`~~`:::::::;    _-~  ;__,        `,-`    ",
  "                                                                       /`\\    /~,  . ~ , '  `  ,  .` `::::;`   <<<~```   ``-,,__   ; ",
  "                                                                      /` .`\\ /` .  ^  ,  ~  ,  . ` . ~\\~                       \\ \\, `,__  ",
  "                                                                     / ` , ,`\\.  ` ~  ,  ^ ,  `  ~ . . ``~~~`,                   `-`--, \\   ",
  "                                                                    / , ~ . ~ \\ , ` .  ^  `  , . ^   .   , ` .`-,___,---,__            ``    ",
  "                         /\\                                       /` ` . ~ . ` `\\ `  ~  ,  .  ,  `  ,  . ~  ^  ,  .  ~  , .`~---,___             ",
  "                        / ~ \\        /\\                        /` . `  ,  . ~ , \\  `  ~  ,  .  ^  ,  ~  .  `  ,  ~  .  ^  ,  ~  .  ``~---,___     ",
  "                       /- ' ~ \\     /  \\                      /       ~  ,  ^ ,  `  ~  ~ . ^  ~  ,  ^ ,  `  ~ : ~  ,  ^ ,  `  ~ ,  `` ~  ,  ^ ``~---,__ ",
  "                     / `  ,  ^ \\   / ^ , \\                   /   ~  ,  ^ ,  `  ~ ^ ,  `  ~  , .`~ ~  ,  ^ ,  `  ~  ~  ,  ^ ,  `  ~      ~  ,  ^ ,  `  ~ ~---,___ `",
  "                    / `  ~ , ^  \\  / ^ ,  ` \\               / ~  ,  ^ ,  `  ~   ~  ,  ^ ,  `  ~   ,  . ~  ,  ^ ,  `  ~  ~  ,  ^ ,  `  ~ ;   ~  ,  ^ ,  `  ~     ~---,___",
  "                  / ~ ~ `  ~ ,  ^ ,      /  ^ ,  ___,---,    /  ~/ ,  ^,  ^ ,  `  ~ ~  ,  ^ ,  `  ~    ~  ,  ^ ,  `  ~  ,  ^ ,  `  ~  ~  ,  `~ ~  ,  ^ ,  `  ~  ~  ,  ^ ,  ~---,___",
  "       ___,---,__ / ` `  ~ ,  ^ ,     `    `  ~ ^  `     \\/,  `  ~ ~  ,  ^ ~   `  ~ . . ~  ,  ^ ,  `  ~ ~  ,  ^ ,  `  `~ ~  ,  `  `~ ~  ,  `  ~  ~  ,  ^ , `  ~  ~  ,  ^ ,~  ,  ^ ,~---,___",
  ",___,-  `  ~ ^ ,  ,  ^ ,  `  ~ ^ ,  `  ~ ~  ,  ^ ,  `  ~   `  ~  ~  ,  .  ,  `  ,  . ~  ^  `~ ~  ,  ^ ,  `  ~  ~  , ,  `  `~ ~  ,   ,  `  `~ ~  ,      ,  `  `~ ~  , ,    `~ ~  ,  ^ ,  `  ~~---,___",
  ",  ^ ,  `  ~ ^ ,   ~  ,  ^ ,  `  ~ ,  ^ ,  `  ~  ,  `  ~ ^  `  , . ^   .   , ` .`~ ~  ,  ^ ,  `  ~  ~  ,  ^ , `  ~  ~  ,  `  `~ ~  ,   ,  `  `~ ~  ,   ,  ^ ,~  ,  ^ ,  `  ~  ~  ,  ^ ,   ~  ,  ^ ,   ~---,___",
  " ,  ^ ,  `  ~ ^ ,   ,  ^ ,  `  ~ ^ ,  `  ~ ~  ,  ^ ,  `  ~   `  ~  ~  ,  .  ,  `  ,  . ~  ^  `~ ~  ,  ^ ,  `  ~  ~    ` ,  `  `~ ~  ,   ,  `  `~ ~  ,   ,  `  `~ ~  ,  ~ ,  `  `~ ~  ,   ~    ,,  ^ , ,  ^ ,   ~  ~  ^ ,     ",
  "  ,  ^ ,  `  ~ ^ ,  ~  ,  ^ ,  `  ~ ,  ^ ,  `  ~  ,  `  ~ ^  `  , . ^   .   , ` .`~ ~  ,  ^ ,  `  ~  ~  ,  ^ , `  ~  ~ ,  `  `~ ~  ,   ,  `  `~ ~  ,   ,  `  `~ ~  ,    ,  ^ ,~  ,  ^ ,  `  ~  ~  ,  ^ ,   ~,  ^ ,   ~,  ^ ,    ",
  ",  ^ ,  `  ~ ^ ,  ,  ^ ,  `  ~ ^ ,  `  ~ ~  ,  ^ ,  `  ~   `  ~  ~  ,  .  ,  `  ,  . ~  ^  `~ ~  ,  ^ ,  `  ~  ~     ,  `  `~ ~  ,   ,  `  `~ ~  ,  `~ ~  ,  ^ ,  `   `~ ~  ,  ^ ,  `  ~  ~ ,  ^ ,   ~,  ^ ,   ~,  ^ ,   ~,  ^ ,   ~,  ^ ,   ~    "
};
*/
