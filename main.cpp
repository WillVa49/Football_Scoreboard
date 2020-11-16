// Wilfrido Varela  COCS-1437   11/14/2020
// Dr_T   Programming Fundamentals II
//C++ program that keeps track of various objects and variables in a Football Scoreboard
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <unistd.h>
using namespace std;

class Team1
{
  private:
    string Name;
    string CoachName;
    string HomeCity;
    bool HomeStatus;
    int score;
    int TimeoutCount;
  public:
    Team1()
    {
      Name = "DefaultName";
      CoachName = "Dr.T";
      HomeCity = "Home City";
      HomeStatus = true; //Visitor = false, Home = True
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
class Team2
{
  private:
    string Name;
    string CoachName;
    string visitorCity;
    bool visitorStatus;
    int score;
    int TimeoutCount;
  public:
    Team2()
    {
      Name = "DefaultName";
      CoachName = "Dr.T";
      visitorCity = "Visitor City";
      visitorStatus = false; //Visitor = false, Home = True
      score = 0;
      TimeoutCount = 0;
    }
    void setName(string n) {Name = n;}
    void setCoachName(string c) {CoachName = c;}
    void setVisitorCity (string vc) {visitorCity = vc;}
    void setVisitorStatus (bool vs) {visitorStatus = vs;}
    void setScore (int s) {score = s;}
    void setTimeoutCount (int t) {TimeoutCount = t;}
    string getName() const {return Name;}
    string getCoachName() const {return CoachName;}
    string getVisitorCity() const {return visitorCity;}
    bool getVisitorStatus() const {return visitorStatus;}
    int getScore() const {return score;}
    int getTimoutCount() const {return TimeoutCount;} 
};

class Scoreboard
{
  private:
    int quarter;
    Team1 home;
    Team2 visitor;
  public:
    Scoreboard()
    {
      quarter = 1;
    }
    void setQuarter (int q) {quarter = q;}
    void setHome (Team1 hSet) {home = hSet;}
    void setVisitor (Team2 vSet) {visitor = vSet;}
    int getQuarter() const {return quarter;}
    Team1 getHome() const {return home;}
    Team2 getVisitor() const {return visitor;}
    void ShowScoreboard()
    {
      string color = "";
      string color1 = "";
      string reset = "\x1b[0m";
      color = "\x1b[32;4m";
      color1 = "\x1b[39;1m";
      cout << color << "\tFOOTBALL SCOREBOARD" << reset << endl;
      cout << color1 << home.getHomeCity() << "\t\t" << visitor.getVisitorCity() << reset << endl;
      cout << color1 << home.getName() << "\t\t" << visitor.getName() << reset << endl;
      cout << home.getScore() << "\t\t\t\t" << visitor.getScore() << endl;
      cout << color << "\t\tQTR" << reset << "  " << quarter << endl;
    }
};


int minutes = 14;
int seconds = 60;

void timer()
{
while (true) 
	{   
    system("clear");
    cout << setfill('0') << setw(2) << minutes << " : " <<setfill('0') << setw (2) << seconds << endl;

		sleep(1); 
		seconds--; 
		if (seconds == 0) 
		{ 
			minutes--; 
			seconds = 60; 
		} 
	} 
}

int main() 
{
  Team1();
  Team2();
  Scoreboard s;
  Team1 tOne;
  Team2 tTwo;
  string newName = "";
  string cityName = "";
  string userChoice = "";
  int newScore = 0;
  int newQuarter = 0;

  tOne.setHomeStatus(true);
  tTwo.setVisitorStatus(false);

  s.setHome(tOne);
  s.setVisitor(tTwo);

  do
  {
    system("clear");
    s.ShowScoreboard();
    cout << "A = Update Home Team name and City: " << endl;
    cout << "B = Update Visitor Team name and City: " << endl;
    cout << "C = Home Team Score: " << endl;
    cout << "D = Visitor Team Score: " << endl;
    cout << "F = Update the Quarter they are in: " << endl;
    cout << "E = Exit" << endl;
    cin >> userChoice;

    if (userChoice == "A" || userChoice == "a")
    {
      cout << "\nPlease enter the city and new name for the home team : ";
      cin >> cityName;
      cin >> newName;  
      tOne.setName(newName);
      tOne.setHomeCity(cityName);
      s.ShowScoreboard();
    }
    else if (userChoice == "B" || userChoice == "b")
    {
      cout << "\nPlease enter the city and new name for the visitor team: " << endl;
      cin >> cityName;
      cin >> newName;
      
      tTwo.setName(newName);
      tTwo.setVisitorCity(cityName);
      s.ShowScoreboard();
    }
    else if (userChoice == "C" || userChoice == "c")
    {
      cout << "\nPlease enter a new score for the home team: " << endl;
      cin >> newScore;
      tOne.setScore(newScore);
    }
    else if (userChoice == "D" || userChoice == "d")
    {
      cout << "\nPlease enter a new score for the home team: " << endl;
      cin >> newScore;
      tTwo.setScore(newScore);
    }
    else if (userChoice == "F" || userChoice == "f")
    {
      cout << "\nPlease enter what quarter they are in: " << endl;
      cin >> newQuarter;
      s.setQuarter(newQuarter);
    }
    else if (userChoice == "E" || userChoice == "e")
    {
      cout << "Exit chosen." << endl;
    }
    else
    {
      cout << "\nInvalid input, try again." << endl;
    }

    s.setHome(tOne);
    s.setVisitor(tTwo);

  }while (userChoice != "E" && userChoice != "e");

  timer();

  return 0;
}
		
