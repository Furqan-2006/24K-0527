#include <iostream>
#include <tuple>
#include <random>

using namespace std;

random_device rd;                         // Seed for the random number engine
mt19937 gen(rd());                        // Mersenne Twister engine for better randomness
uniform_int_distribution<int> dist(0, 1); // Random number in range [0, 1]

class Robot
{
    string name;
    int hits;

public:
    Robot(string n) : name(n), hits(0) {};

    void hitBall(int &ballX, int &ballY, const string &direction)
    {
        hits++;

        if (direction == "up")
            ballY++;
        else if (direction == "down")
            ballY--;
        else if (direction == "left")
            ballX--;
        else if (direction == "right")
            ballX++;
    }

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
        if (x >= 3)
            x = 3;

        if (y >= 3)
            y = 3;
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
    Team *teams[2];

    Game(string team1Name, string player1Name, string team2Name, string player2Name, int ballX, int ballY, int goalX, int goalY) : ball(ballX, ballY), goal(goalX, goalY)
    {
        teams[0] = new Team(team1Name, player1Name);
        teams[1] = new Team(team2Name, player2Name);
    }
    ~Game()
    {
        delete teams[0];
        delete teams[1];
    }

    void startGame()
    {
        cout << "GAME START!" << endl;
        while (!goal.isGoalReachead(ball.getX(), ball.getY()))
        {
            int turn = dist(gen);
            play(*teams[turn]);
        }
    }

    void play(Team &team)
    {
        string direction;
        cout << "Enter the direction of the hit: ";
        cin >> direction;

        Robot *player = team.getPlayer();
        int ballX = ball.getX();
        int ballY = ball.getY();

        player->hitBall(ballX, ballY, direction);            // Get movement changes
        ball.move(ballX - ball.getX(), ballY - ball.getY()); // Move the ball

        cout << team.getTeamName() << " moved ball to (" << ball.getX() << ", " << ball.getY() << ")." << endl;
    }

    void declareWinner()
    {
        int hits1 = teams[0]->getPlayer()->getHits();
        int hits2 = teams[1]->getPlayer()->getHits();

        cout << "\nTeams Scores: " << endl;
        cout << teams[0]->getTeamName() << ": " << hits1 << " hits" << endl;
        cout << teams[1]->getTeamName() << ": " << hits2 << " hits\n" << endl;

        if (hits1 < hits2)
        {
            cout << teams[0]->getTeamName() << " wins!" << endl;
        }
        else if (hits1 > hits2)
        {
            cout << teams[1]->getTeamName() << " wins!" << endl;
        }
        else
        {
            cout << "Game Draw! " << endl;
        }
    }
};
int main()
{
    string team1Name;
    string team2Name;
    string player1Name;
    string player2Name;

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
    game.declareWinner();

    return 0;
}