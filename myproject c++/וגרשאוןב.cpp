#include <iostream>
#include <ctime>
#include <conio.h>
#include<random>
#include <cstdlib>
#include <thread>
#include <chrono>

char keypressed = ' ';

enum GameObjects : char
{
    GO_WALL = '#',
    GO_PLAYER = '@',
    GO_PICKUP = 'o',
    GO_EMPTY = ' '
};

struct Position
{
    int x;
    int y;
};

int GetRandomNumber(int min, int max)
{
   std::random_device generator;
   std::uniform_int_distribution<int> range(min, max);
   return range(generator);
}

const int MAP_WIDTH = 20;
const int MAP_HEIGHT = 10;
char GameMap[MAP_HEIGHT][MAP_WIDTH];
int player_X= MAP_HEIGHT/2;
int player_Y= MAP_WIDTH/2;
int randomNumber;
int item1_Y;
int item1_X;
int gravity_check;
const int POSSIBLE_ITEM_PLACES_X = MAP_HEIGHT - 3;
const int POSSIBLE_ITEM_PLACES_Y = MAP_WIDTH - 3;
int item_pickedup = 0;

void DrawMap()
{
    if (MAP_WIDTH < 121 && MAP_HEIGHT > 3 && MAP_WIDTH > 3)
    {
        for (size_t i = 0; i < MAP_HEIGHT; i++)
        {
            for (size_t j = 0; j < MAP_WIDTH; j++)
            {
                if (i == player_Y && i == MAP_WIDTH - 1)
                {

                }
                else if (i == player_X && j == player_Y && i == item1_X && j == item1_Y)
                {
                    std::cout << GO_PLAYER;
                    if (i == player_Y && i == MAP_WIDTH - 1)
                    {

                    }
                    else if (i == player_X && j == player_Y && i == item1_X && j == item1_Y)
                    {
                        std::cout << GO_PLAYER;
                        item_pickedup = 1;
                        randomNumber = GetRandomNumber(1, 100);
                        item1_X = randomNumber % POSSIBLE_ITEM_PLACES_X + 1;
                        randomNumber = GetRandomNumber(1, 100);
                        item1_Y = randomNumber % POSSIBLE_ITEM_PLACES_Y + 1;
                    }
                    else if (i == player_X && j == player_Y)
                    {
                        std::cout << GO_PLAYER;
                    }
                    else if (i > 0 && i < MAP_HEIGHT - 1 && j != 0 && j != MAP_WIDTH - 1)
                    {
                        GameMap[i][j] = GO_EMPTY;
                        std::cout << GameMap[i][j];
                    }
                    else
                    {
                        GameMap[i][j] = GO_WALL;
                        std::cout << GameMap[i][j];
                    }
                }
                else if (i == player_X && j == player_Y)
                {
                    std::cout << GO_PLAYER;
                }

                else if (i == item1_X && j == item1_Y)
                {
                    std::cout << GO_PICKUP;
                    while (item1_X == player_X && item1_Y == player_Y)
                    {
                        randomNumber = GetRandomNumber(1, 100);
                        item1_X = randomNumber % POSSIBLE_ITEM_PLACES_X + 1;
                        randomNumber = GetRandomNumber(1, 100);
                        item1_Y = randomNumber % POSSIBLE_ITEM_PLACES_Y + 1;
                    }
                }
                else if (i > 0 && i < MAP_HEIGHT - 1 && j != 0 && j != MAP_WIDTH - 1)
                {
                    GameMap[i][j] = GO_EMPTY;
                    std::cout << GameMap[i][j];
                }
                else
                {
                    GameMap[i][j] = GO_WALL;
                    std::cout << GameMap[i][j];
                }

            }
            std::cout << "\n";
        }

    }
    else
    {
        std::cout << "invalid map size";
    }
}
Position Player;

void Initialize()
{
    keypressed = _getch();
    if (keypressed == 'w' && player_X!=1)
    {
        player_X--;
    }
    else if(keypressed=='d' && player_Y < MAP_WIDTH-2)
    {
        player_Y++;
    }
    else if (keypressed=='s' && player_X < MAP_HEIGHT-2)
    {
        player_X++;
    }
    else if (keypressed == 'a' && player_Y != 1)
    {
        player_Y--;
    }
}

void items()
{

}

int main()
{
    randomNumber = GetRandomNumber(1, 100);
    item1_X = randomNumber % POSSIBLE_ITEM_PLACES_X + 1;
    randomNumber = GetRandomNumber(1, 100);
    item1_Y = randomNumber % POSSIBLE_ITEM_PLACES_Y + 1;
   srand(time(0));
    char key;
    do
    {
        
   GetRandomNumber(3,6);

  


    DrawMap();
    if (item_pickedup == 1)
    {
        system("cls");
        DrawMap();
        item_pickedup = 0;
    }
    Initialize();
    system("cls");
    } while (true);
   
}