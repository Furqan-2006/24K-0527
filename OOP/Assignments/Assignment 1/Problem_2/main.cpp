#include <iostream>
#include <tuple>
#include <random>

using namespace std;

class Robot
{
    string name;
    int hits;

public:
    Robot(string n) : name(n), hits(0) {};

    void hitBall(int &dx, int &dy, const string &direction)
    {
        hits++;

        if (direction == "up")
        {
            dy = 1;
            dx = 0;
        }
        else if (direction == "down")
        {
            dy = -1;
            dx = 0;
        }
        else if (direction == "left")
        {
            dy = 0;
            dx = -1;
        }
        else if (direction == "right")
        {
            dy = 0;
            dx = 1;
        }
    };
    int getHits()
    {
        return hits;
    }
};

class Ball
{
    int x, y;

public:
    Ball(int x, int y) : x(x), y(y) {};

    int getX()
    {
        return x;
    }
    int getY()
    {
        return y;
    }
    void move(int dx, int dy)
    {
        x += dx;
        y += dy;
    };

    tuple<int, int> getPosition()
    {
        return make_tuple(x, y);
    }
};
class Goal
{
    int x, y;

public:
    Goal(int x, int y) : x(x), y(y) {};

    bool isGoalReachead(int ballX, int ballY)
    {
        return (ballX == x && ballY == y);
    }
};
class Team
{
    string teamName;
    Robot *player;

public:
    Team(string name, string robotName) : teamName(name)
    {
        player = new Robot(robotName);
    }
    ~Team()
    {
        delete player;
    }

    Robot *getPlayer() { return player; }
    string getTeamName() { return teamName; }
};
class Game
{
public:
    Ball ball;
    Goal goal;

    Team teams[2];
    Game(string team1Name, string player1Name, string team2Name, string player2Name, int ballX, int ballY, int goalX, int goalY) : teams{Team(team1Name, player1Name), Team(team2Name, player2Name)}, ball(ballX, ballY), goal(goalX, goalY) {};

    void startGame()
    {
        cout << "GAME START!" << endl;
    }

    void play(Team &team)
    {
        string direction;
        cout << "Enter the direction of the hit: ";
        cin >> direction;

        Robot *player = team.getPlayer();
        int dx = 0, dy = 0;

        player->hitBall(dx, dy, direction); // Get movement changes
        ball.move(dx, dy);                  // Move the ball

        cout << team.getTeamName() << " moved ball to (" << ball.getX() << ", " << ball.getY() << ")." << endl;
    }

    void declareWinner()
    {
        int hits1 = teams[0].getPlayer()->getHits();
        int hits2 = teams[1].getPlayer()->getHits();

        if (hits1 > hits2)
        {
            cout << teams[0].getTeamName() << " wins!" << endl;
        }
        else if (hits1 < hits2)
        {
            cout << teams[1].getTeamName() << " wins!" << endl;
        }
        else
        {
            cout << " Draw! " << endl;
        }
    }
};
int main()
{
    string team1Name;
    string team2Name;
    string player1Name;
    string player2Name;

    random_device rd;                         // Seed for the random number engine
    mt19937 gen(rd());                        // Mersenne Twister engine for better randomness
    uniform_int_distribution<int> dist(0, 1); // Random number in range [0, 1]

    cout << "Enter the following detail: " << endl;
    cout << "Enter team 1 name: ";
    getline(cin, team1Name);
    cout << "Enter team 2 name: ";
    getline(cin, team2Name);
    cout << "Enter robot 1 name: ";
    getline(cin, player1Name);
    cout << "Enter robot 2 name: ";
    getline(cin, player2Name);

    Game game(team1Name, player1Name, team2Name, player2Name, 0, 0, 3, 3);

    game.startGame();
    while (!game.goal.isGoalReachead(game.ball.getX(), game.ball.getY()))
    {
        int turn = dist(gen);
        game.play(game.teams[turn]);
    }
    game.declareWinner();

    return 0;
}