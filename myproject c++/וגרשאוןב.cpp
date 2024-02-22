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
    GO_EMPTY = '/'
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

double pi = 3.1415926535897932;
const int VIEW_RANGE = 20;
const int VIEW_RANGE_FIXER = VIEW_RANGE/2;
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


void Map()
{
    for (size_t w = 0; w < MAP_WIDTH; w++)
    {
        for (size_t h = 0; h < MAP_HEIGHT; h++)
        {
            if (w == player_Y && w == MAP_WIDTH - 1)
            {

            }
            else if (h == player_X && w == player_Y)
            {
                GameMap[h][w] = GO_PLAYER;
            }
            else if (w == item1_Y&&h == item1_X)
            {
                GameMap[h][w] = GO_PICKUP;
            }
            else if (w == 0)
            {
                GameMap[h][w] = GO_WALL;
            }
            else if (h == 0)
            {
                GameMap[h][w] = GO_WALL;
            }
            else if (w == MAP_WIDTH-1)
            {
                GameMap[h][w] = GO_WALL;
            }
            else if (h == MAP_HEIGHT-1)
            {
                GameMap[h][w] = GO_WALL;
            }
            else
            {
                GameMap[h][w] = GO_EMPTY;
            }
        }
    }
}



void DrawMap()
{
    for (size_t i = player_Y - VIEW_RANGE / 2; i < player_Y + VIEW_RANGE / 2; i++)
    {
        for (size_t j = player_X - VIEW_RANGE_FIXER / 2; j < player_X + VIEW_RANGE_FIXER / 2; j++)
        {
            if (j > -1 && i > -1 && j < MAP_HEIGHT-1 && i < MAP_WIDTH-1)
            {
                std::cout << GameMap[i][j];
            }
        }
        std::cout << "\n";
    }
}
Position Player;

void keypress()
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

void random()
{
    randomNumber = GetRandomNumber(1, 100);
    item1_X = randomNumber % POSSIBLE_ITEM_PLACES_X + 1;
    randomNumber = GetRandomNumber(1, 100);
    item1_Y = randomNumber % POSSIBLE_ITEM_PLACES_Y + 1;
}

int main()
{
    do
    {
        while (item1_X == player_X && item1_Y == player_Y)
        {
            random();
        }
        Map();/*temp*/
        DrawMap();
        if (item_pickedup == 1)
        {
            system("cls");
            DrawMap();
            item_pickedup = 0;
        }
        keypress();
        system("cls");
    } while (true);
   
}