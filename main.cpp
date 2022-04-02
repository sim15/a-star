#include <iostream>
#include "source/AStar.hpp"
#include <bits/stdc++.h>
using namespace std;

int main()
{   
    freopen("location_schematic.in", "r", stdin);
	freopen("path.out", "w", stdout);

    int WIDTH, HEIGHT;
    cin >> WIDTH >> HEIGHT;


    AStar::Generator generator;
    generator.setWorldSize({WIDTH, HEIGHT});
    generator.setHeuristic(AStar::Heuristic::euclidean);
    generator.setDiagonalMovement(true);



    vector<int> startPos;
    vector<int> endPos;

    char grid[2000][2000];

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            char cur;
            cin >> cur;
            grid[y][x] = cur;
            switch (cur) {
                case '-': break;
                case 'S': startPos = {x, y}; break;
                case 'E': endPos = {x, y}; break;
                case 'O': generator.addCollision({x,y}); break;
            }
        }
    }

    auto path = generator.findPath({startPos[0], startPos[1]}, {endPos[0], endPos[1]});

    cout << startPos[0] << startPos[1] << endl;

    for(auto& coordinate : path) {
        grid[coordinate.y][coordinate.x] = 'X';
        // cout << coordinate.x << " " << coordinate.y << "\n";
    }

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            cout << grid[y][x];
        }
        cout << endl;
    }
}