// Wilfrido Varela  COCS-1437   11/14/2020
// Dr_T   Programming Fundamentals II
//C++ program that keeps track of various objects and variables in a Football Scoreboard
#include <iostream>
using namespace std;

class Team
{
  private:
    string Name;
    string CoachName;
    string HomeCity;
    bool HomeStatus;
    int score;
    int TimeoutCount;
  public:
    Team()
    {
      Name = "Will V.";
      CoachName = "Dr.T";
      HomeCity = "DefaultHomeCity";
      HomeStatus = false; //Visitor = false, Home = True
      score = 0;
      TimeoutCount = 0;
    }
    void setName(string n) {Name = n;}
    void setCoachName(string c) {CoachName = c;}
    void setHomeCity (string hc) {HomeCity = hc;}
    void setHomeStatus (bool hs) {HomeStatus = hs;}
    void setScore (int s) {score = s;}
    void setTimeoutCount (int t) {TimeoutCount = t;}
    string getName() const {return Name;}
    string getCoachName() const {return CoachName;}
    string getHomeCity() const {return HomeCity;}
    bool getHomeStatus() const {return HomeStatus;}
    int getScore() const {return score;}
    int getTimoutCount() const {return TimeoutCount;} 
};

class Scoreboard
{
  private:
    int quarter;
    Team home;
    Team visitor;
  public:
    Scoreboard()
    {
      quarter = 1;
    }
    void setQuarter (int q) {quarter = q;}
    void setHome (Team hSet) {home = hSet;}
    void setVisitor (Team vSet) {visitor = vSet;}
    int getQuarter() const {return quarter;}
    Team getHome() const {return home;}
    Team getVisitor() const {return visitor;}
    void ShowScoreboard()
    {
      string color = "";
      string reset = "\x1b[0m";
      color = "\x1b[33;1m";
      cout << color << "Football Scoreboard" << reset << endl;
      cout << home.getName() << "\t\t" << visitor.getName() << endl;
      cout << home.getScore() << "\t\t\t\t" << visitor.getScore() << endl;
      cout << quarter << endl;
    }
};


int main() 
{
  Team();
  Scoreboard s;
  Team tOne;
  Team tTwo;
  string newName = "";
  string userChoice = "";
  int newScore = 0;

  tOne.setHomeStatus(true);

  s.setHome(tOne);
  s.setVisitor(tTwo);

//***************************************//
do
{
  system("clear");
  s.ShowScoreboard();
  cout << "A = Update Home Team name: " << endl;
  cout << "B = Update Visitor Team name: " << endl;
  cout << "C = Home Team Score: " << endl;
  cout << "D = Visitor Team Score: " << endl;
  cout << "F = Update Qtr: " << endl;
  cin >> userChoice;

  if (userChoice == "A" || userChoice == "a")
  {
     cout << "Please enter a new name for the home team: ";
  cin >> newName;
  }
 


return 0;
}
