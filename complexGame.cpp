/*
  Author: Romain Dzeinse
  Date: 07/31/24
  Finished: 8/11/24 at 12:00pm
  File name: game1.cpp
  Objective: Build an interactive 2-player game using classes, encapsulation and other Object Oriented Programming(OOP) concepts
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <random>  // for random number
#include <cctype>   // this allows me to make strings lowercase

using namespace std;

class Player{
public:
  string name;
  int points = 0;   // Starting number of points for both players
  int dps = 0;   // Starting damage per second for both players
  bool hasPet = false;
};


class Pet{
public:
  string name;
  int points = 0;
  string ability;

};


string display1[5][6] = {
  {"Games", "100", "150", "200", "250", "300"},
  {"Common Knowledge", "100", "150", "200", "250", "300"},
  {"Clash Royale", "100", "150", "200", "250", "300"},
  {"Programming", "100", "150", "200", "250", "300"},
  {"Riddles", "100", "150", "200", "250", "300"},
};

string questions1[5][6] = {
  {"Games", "Name a popular board game old people play?", "Name a popular video game?", "What classic board game involves buying, trading, and developing properties like Boardwalk and Park Place?", "Name a popu\
lar addictive supercell game where Romain strives at.", "Name one playable characters in 'Overwatch.'"},
  {"Common Knowledge", "Name a periodic element starting with the letter C", "Name a planet in our solar system that comes after Earth.", "Name one of The 13 Colonies (the not so popular ones).", "Name one of t\
he 5 renewable energy sources.", "Name a major mountain range in the world."},
  {"Clash Royale", "Name a well known common rarity card in Clash Royale.", "Name a popular win condition in Clash Royale.", "Name a well known legendary rarity card in Clash Royale.",  "Name the most annoying \
card?", "Who is the best Clash Royale Player you've ever met and played against (only CR names)?"},
  {"Programming", "Name a popular programming language.", "Name a programming language that deals well with Object Oriented Programming (OOP)", "Name a popular Integrated Develpment Environment (IDE), used by c\
ollege students.", "Name a programming langauage where you can you can use ANSI color codes.", "Name a programming concept that is difficult/confusing to learn but very effective and usefull."},
  {"Riddles", "I speak without a mouth and hear without ears. I have no body, but I come alive with the wind. What am I?", "What has keys but can't open locks?", "The more you take, the more you leave behind. W\
hat am I?", "I’m not alive, but I grow; I don’t have lungs, but I need air; I don’t have a mouth, but water kills me. What am I?", "I can be cracked, made, told, and played. What am I?"},
};

string games[5][6] = {
  {"100", "Sudoku", "Bingo", "Chess", "Checkers", "Scrabble"},
  {"150", "Madden", "Call of Duty", "Fifa", "Valorant", "Apex Legends"},
  {"200", "Monopoly", "NONE", "NONE", "NONE", "NONE"},
  {"250", "Clash Royale", "Clash of Clans", "Brawl Stars", "Boom Beach", "NONE"},
  {"300", "Tracer", "Reaper", "Winston", "Mercy", "Genji"},
};
string commonKnowledge[5][6] = {
  {"100", "Carbon", "Chromium", "Chlorine", "Copper", "Calcium"},
  {"150", "Mars", "Jupiter", "Saturn", "Uranus", "Neptune"},
  {"200", "Georgia", "Maryland", "Rhode Island", "New Jersey", "North Carolina"},
  {"250", "Solar", "Wind", "Hydropower", "Geothermal", "Biomass"},
  {"300", "Himalayas", "Andes", "Rockies", "Alps", "Appalachians"},
};
string clashRoyale[5][6] = {
  {"100", "Knight", "Archers", "Minions", "Skeletons", "Goblins"},
  {"200", "Hog Rider", "Royal Giant", "Balloon", "Graveyard", "Fireball"},
  {"150", "Princess", "Log", "Sparky", "Electro Wizzard", "Magic Archer"},
  {"250", "Goblin Barrel", "Miner", "Mega Knight", "Elite Barbarians", "Princess"},
  {"300", "Tyrone", "Melted", "Impossible", "Gabe is Gabe", "RandomDude"},
};
string programming[5][6] = {
  {"100", "Python", "C++", "Javascript", "Bash", "Ruby"},
  {"150", "Swift", "Ruby", "Java", "C#", "Python"},
  {"200", "Visual Studio Code", "Pycharm", "IntelliJ", "Replit", "Visual Studio"},
  {"250", "C++", "PowerShell", "Javascript", "Bash", "Python"},
  {"300", "Algorithms", "Complexity", "Memory", "OOP", "Recursion"},
};
string riddles[5][6] = {
  {"100", "An echo", "echo", "NONE", "NONE", "NONE"},
  {"150", "A piano", "piano", "NONE", "NONE", "NONE"},
  {"200", "Footsteps", "steps", "NONE", "NONE", "NONE"},
  {"250", "Fire", "NONE", "NONE", "NONE", "NONE"},
  {"300", "A joke", "joke", "NONE", "NONE", "NONE"},
};


string display2[20] =
{
  "250", "250", "250", "250", "250", "250", "250", "250", "250", "250", "250", "250", "250", "250", "250", "250", "250", "250", "250", "250",
};
string questions2[20] =
{
    "What is the capital of France?", "What is the largest ocean on Earth?", "What is the capital of Japan?", "Which country is known as the Land of the Rising Sun?", "What is the longest river in the world?", \
"Which planet is known as the Red Planet?", "What is the powerhouse of the cell?", "Which organ in the human body is responsible for pumping blood?", "What is the hardest natural substance on Earth?", "What is \
the smallest planet in our solar system?", "Which gas do plants absorb from the atmosphere?", "Which vitamin is produced when the skin is exposed to sunlight?", "In which year did the Titanic sink?", "Which cou\
ntry won the FIFA World Cup in 2018?", "Who wrote 'Romeo and Juliet'?", "Who painted the Mona Lisa?", "What is the main ingredient in guacamole?", "Which language is the most spoken worldwide?", "Who is known a\
s the Father of Computers?", "What does CPU stand for in computer terms?",
};
string answerChoices[20][4] =
{
    {"Marseille", "Lyon", "Nice", "Paris"},
    {"Indian Ocean", "Arctic Ocean", "Pacific Ocean", "Atlantin Ocean"},
    {"Hiroshima", "Kyoto", "Tokyo", "Osaka"},
    {"Korea", "China", "Japan", "Thailand"},
    {"Amazon", "Nile", "Yangtze", "Mississippi"},
    {"Jupiter", "Earth", "Mars", "Venus"},
    {"Nucleus", "Ribosome", "Mitochondria", "Endoplasmic Rectilum"},
    {"Liver", "Heart", "Brain", "Kidneys"},
    {"Quartz", "Gold", "Iron", "Diamond"},
    {"Mars", "Mercury", "Venus", "Neptune"},
    {"Carbon Dioxide", "Oxygen", "Nitrogen", "Methane"},
    {"Vitamin C", "Vitamin A", "Vitamin D", "Vitamin B12"},
    {"1912", "1905", "1915", "1920"},
    {"Germany", "Argentina", "Brazil", "France"},
    {"Charles Dickens", "Jane Austen", "William Shakespear", "Mark Twain"},
    {"Leonardo Da Vinci", "Claude Monet", "Vincent Van Gogh", "Pablo Picasso"},
    {"Onion", "Avocado", "Tomato", "Line"},
    {"Hindi", "English", "Mandarin Chinese", "Spanish"},
    {"Alan Turning", "Charles Babbage", "Steve Jobs", "Bill Gates"},
    {"Central Procreation Utility", "Central Processing Unit", "Cant Pay u", "Chip Proctor Unit"},
};
string answers[20][1] =
{
    {"Paris"},
    {"Pacific Ocean"},
    {"Tokyo"},
    {"Japan"},
    {"Nile"},
    {"Mars"},
    {"Mitochondria"},
    {"Heart"},
    {"Diamond"},
    {"Mercury"},
    {"Carbon Dioxide"},
    {"Vitamin D"},
    {"1912"},
    {"France"},
    {"William Shakespear"},
    {"Leonardo Da Vinci"},
    {"Avocado"},
    {"Mandarin Chinese"},
    {"Charles Babbage"},
    {"Central Processing Unit"},
};


// lowercase function
string lowercase(string str){
  string newStr;
  for(char c: str){
    newStr += tolower(c);
  }
  return newStr;
}
// lowercase function


void displayQuestions(string arr[20]){
  cout << "_____________________" << endl;
  cout << "|";
  for(int i=0; i<20; i++){
    if(arr[i] == "000"){
      if(i != 0 && i % 5 == 0)
        cout << endl << "|";
      cout << "\033[32m" << arr[i] << "\033[0m|";
    }
    else{
      if(i != 0 && i % 5 == 0)
        cout << endl << "|";
      cout << "\033[33m" << arr[i] << "\033[0m|";
    }

  }
  cout << "\n¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯" << endl;
  cout << endl;
}

void displayQuestions2(string arr[20]){
  cout << "____________________________________________________________________________________________________________________" << endl;
  for(int i=0; i<20; i++){
    int space = 47 - arr[i].size();
    int space2 = 63 - arr[i].size();
if(i != 0 && i % 2 == 0){
      cout << "|" << endl;
    }
    if(i % 2 == 0 || i == 0)
      cout << "|\033[33m" << arr[i] << "\033[0m";
    else
      cout << " | \033[33m" << arr[i] << " \033[0m";
    if((i % 2 == 0) || (i == 0)){
      for(int k=0; k<space; k++)
        cout << " ";
    }
    else{
      for(int k=0; k<space2; k++)
        cout << " ";
    }
    if(i == 19)
      cout << "|";
  }
  cout << "\n¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯" << endl;
  cout << endl;
}







void displayFormat(string format[5][6]){
  cout << "____________________________________________" << endl;
  for(int i=0; i<5; i++){
    int space = 16 - (format[i][0].size());
    cout << "|\033[31m"  << format[i][0] << "\033[0m";
    for(int k=0; k<space; k++){
      cout << " ";
    }
    cout << "|  ";
    for(int j=1; j<6; j++){
      if(format[i][j] == "000"){
        if(j==5)
          cout << "\033[32m" << format[i][j] << "\033[0m";
        else
          cout << "\033[32m" << format[i][j] << "\033[0m  ";
      }
      else{
        if(j==5)
          cout << "\033[33m" << format[i][j] << "\033[0m";
        else
          cout << "\033[33m" << format[i][j] << "\033[0m  ";
      }
    }
    cout << "|"  << endl;
  }
  cout << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯" << endl;
}

void displayAnswers(string ans[20][4], int indice){
  cout << ">>>>>>>>>>>>   ";
  for(int i=0; i<4; i++)
    cout << i+1  << ":\033[33m" << ans[indice][i] << "\033[0m   ";
  cout << endl;
}
// make sure these variables are casted to lowercase when the function is called
bool checkAnswer(int indice, string actualAnswer){
  if(lowercase(answers[indice][0]) == actualAnswer)
    return true;
  else
    return false;
}


void changeFormat(string format[5][6], string targetAmount, string mode){
  for(int i=0; i<5; i++){
    if(lowercase(format[i][0]) == lowercase(mode)){
      for(int j=0; j<6; j++){
        if(format[i][j] == targetAmount){
          format[i][j] = "000";
          break;
        }
      }
    }
  }
}

void changeFormat2(string format[20], int indice){
  format[indice] = "000";
}


string trivia1(string categ, int amount){
  categ = lowercase(categ);

  if(amount == 100)
    amount = 1;
  else if(amount == 150)
    amount = 2;
  else if(amount == 200)
    amount = 3;
  else if(amount == 250)
    amount = 4;
  else if(amount == 300)
    amount = 5;
  else{
    return "\033[31minvalid amount\033[0m";
  }
  for(int i=0; i<5; i++){
    string str = questions1[i][0];
    str = lowercase(str);
    if(str == categ)
      cout << questions1[i][amount] << endl;
  }
  string userGuess;
  cout << ">>> ";
  getline(cin, userGuess);
  userGuess = lowercase(userGuess);
  return userGuess;
}

//////////////////////////////
// tictactoe game pasted below

const int row = 3;
const int col = 3;

void displayBoard(string board[row][col]){
    cout << "    ";
    for(int i=0; i<3; i++){
        cout << i << " ";
    }
    cout << endl;

    for(int i=0; i<3; i++){
      cout << i << "  |";
      for(int j = 0; j<3; j++){
        if(board[i][j] == "X"){
          cout << "\033[33m" << board[i][j] << "\033[0m|";
        }
        else if(board[i][j] == "O"){
          cout << "\033[32m" << board[i][j] << "\033[0m|" ;
        }
        else {
          cout << board[i][j] << "|";
        }
      }
      cout << endl;
    }
}

void makeBoard(string arr[row][col]){
  for(int i=0; i<row; i++){
    for(int j=0; j<col; j++){
      arr[i][j] = "-";
    }
  }
}


bool validPosition(string arr[row][col], int x, int y){
    if(arr[x][y] == "-" & x < row & y < col)
        return true;
    else
        return false;
}


bool checkHori(string arr[row][col], string piece){
    for(int i=0; i<row; i++){
        if(arr[i][0] == piece & arr[i][1] == piece & arr[i][2] == piece)
            return true;
        }
    return false;
}


bool checkVert(string arr[row][col], string piece){
    for(int i=0; i<row; i++){
        if(arr[0][i] == piece & arr[1][i] == piece & arr[2][i] == piece)
            return true;
    }
    return false;
}


bool checkDiag(string arr[row][col], string piece){
    if(arr[0][0] == piece & arr[1][1] == piece & arr[2][2] == piece)
        return true;
    else if(arr[0][2] == piece & arr[1][1] == piece & arr[2][0] == piece)
        return true;
    else
        return false;
}


bool noMoreDash(string arr[row][col]){
  for(int i=0; i<row; i++){
    for(int j=0; j<col; j++){
      if(arr[i][j] == "-")
        return false;
    }
  }
  return true;
}


void changeBoard(string arr[row][col], string piece, int x, int y){
  arr[x][y] = piece;
}


bool* playGame(string name1, string name2) {
  string board[row][col];
  makeBoard(board);
  displayBoard(board);
  cout << endl;

  bool winner = false;
  bool winp1 = false;
  bool winp2 = false;

  int player1X;
  int player1Y;
  int player2X;
  int player2Y;

  while (! winner){
    cout << "Where to play \033[33m" << name1 << "\033[0m [x] :  ";
    cin >> player1X;
    cout << "Where to play \033[33m" << name1 << "\033[0m [y] :  ";
    cin >> player1Y;
    bool tryAgain1 = false;
    // Loop until user gives valid position
    while (! validPosition(board, (int)player1X, (int)player1Y)){
      tryAgain1 = true;
      cout << "Invalid position " << name1 << endl;
      cout << "Where to play again " << name1 << " [x] :  ";
      cin >> player1X;
      cout << "Where to play again " << name1 << " [y] :  ";
      cin >> player1Y;
    }
    // Now we know it's a valid position
    if(tryAgain1)
      cout << "\033[33mValid Position " << name1 << "\033[0m\n";
    // Change the position in the baord
    changeBoard(board, "X", player1X, player1Y);

    if(checkHori(board, "X")){
        winner = true;
        winp1 = true;
        }
        else if(checkVert(board, "X")){
        winner = true;
        winp1 = true;
        }
        else if(checkDiag(board, "X")){
        winner = true;
        winp1 = true;
        }
        if(winner)
        break;
        if(noMoreDash(board))
        break;

        cout << "_____________________________\n";

        cout << "Where to play \033[32m" << name2 << "\033[0m [x] :  ";
        cin >> player2X;
        cout << "Where to play \033[32m" << name2 << "\033[0m [x] :  ";
        cin >> player2Y;
        bool tryAgain2 = false;
        while (! validPosition(board, (int)player2X, (int)player2Y)){
        tryAgain2 = true;
        cout << "Invalid position " << name2 << endl;
        cout << "Where to play again " << name2 << " [x] :  ";
        cin >> player2X;
        cout << "Where to play again " << name2 << " [y] :  ";
        cin >> player2Y;
        }
        changeBoard(board, "O", player2X, player2Y);
        if(tryAgain2)
        cout << "\033[32mValid Position Player2\033[0m\n";
        if(checkHori(board, "O")){
        winner = true;
        winp2 = true;
        }
        else if(checkVert(board, "O")){
        winner = true;
        winp2 = true;
        }
        else if(checkDiag(board, "O")){
        winner = true;
        winp2 = true;
        }
        displayBoard(board);
    }
    // Final board
    cout << "\n\n    ";
    for(int i=0; i<3; i++){
        cout << i << " ";
    }
    cout << endl;

    for(int i=0; i<3; i++){
      cout << i << "  |";
      for(int j = 0; j<3; j++){
        if (winp1){
          if(board[i][j] == "X"){
            cout << "\033[47m" << board[i][j] << "|\033[0m";
          }
          else if(board[i][j] == "O"){
            cout << "\033[32m" << board[i][j] << "\033[0m|" ;
          }
          else {
            cout << board[i][j] << "|";
          }
        }
        else if (winp2){
          if(board[i][j] == "X"){
            cout << "\033[33m" << board[i][j] << "\033[0m|";
          }
          else if(board[i][j] == "O"){
            cout << "\033[47m" << board[i][j] << "|\033[0m" ;
          }
          else {
            cout << board[i][j] << "|";
          }
        }
      }
      cout << endl;
    }



    bool static result[2] = {false, false};
    // if(winner){
        // if(winp1){
        // displayBoard(board);
        // result[0] = true;
        // cout << "\033[33m" << name1 << "\033[0m has won the game\n";
        // }
        // else if(winp2){
        // result[1] = true;
        // cout << "\033[32m" << name2 << "\033[0m has won the game\n";
        // }
    //     result[0] = false;
    //     result[1] = false;
    // }
    if (winner == false)
      cout << "The game ended as a draw\n";

    result[0] = winp1;
    result[1] = winp2;


  return result;
}


// tictactoe game pasted above
//////////////////////////////

void start(){
  cout << "\033[33m**********Welcome to The Ultimate Game once again players**********\n";
  cout << "Here are the rules: \n";
  cout << "1. Scrap for \033[32m2500\033[0m \033[33mpoints to win\n";
  cout << "2. You can solve trivia questions to earn points\n";
  cout << "3. You can \033[32mdeduct points\033[0m \033[33mfrom your opponent\n";
  cout << "4. You can \033[32mtransfer your opponent's points\033[0m \033[33minto your points holder\n";
  cout << "5. You can \033[32mpurchase pets with some points\033[0m \033[33mand choose an ability for them(pets and pets abilities are optional)\n";
  cout << "6. You can lose some points if you don't answer the trivia correctly\n\033[0m";
}


int begin(int *score1, int *score2, string name1, string name2){
  cout << "\t\t\t\t\t-----Options-----\n";
  vector <string>toDo = {"Answer some trivia", "Random questions", "Steal opponent points"};
  cout << "<>";
  for(int i=0; i<toDo.size(); i++)
    cout << "\033[31m" << toDo[i] << "\033[0m<>";
  cout << endl;
  cout << "\t\t\t\t\t";
  for(int i=1; i<=toDo.size(); i++)
    cout << " <\033[31m"  << i << "\033[0m> ";
  cout << endl;
  int choice;
  cout << "What would you like to do to start off the game " << name1 << "?: ";
  cin >> choice;    // Watch bro code's video to solve this problem

  string category, ptAmount, guess, value, startTTT;
  int counter, randInt, answer;
  bool corrOrIncorr;
  bool* tttWinner;
  // three lines inbetween these commnets are for random numbers generation
  random_device rd;
  mt19937 generator(rd());
  uniform_int_distribution <int> distribution(0, 19);
  // three lines inbetween these comments are for random numbers generation




  switch(choice){
  case 1:{
    cout << "\033[31m" << choice  << "<-- " << toDo[1] << "\033[0m" << endl;
    displayFormat(display1);
    cout << "\nWhat category do you want: " << endl;
    cout << "--> ";
    cin.ignore();
    getline(cin, category);
    cout << "How many points do you want to play for: " << endl;
    cout << "--> ";
    getline(cin >> ws, ptAmount);
    // if user enters games
    if(lowercase(category) == "games"){
      guess = trivia1(category, stoi(ptAmount));
      if(stoi(ptAmount) == 0){
        counter += 1;
      }
      for(int i=0; i<5; i++){
        for(int j=0; j<6; j++){
          if(ptAmount == games[i][0]){
            if(guess == lowercase(games[i][j])){
              cout << "\033[32mCorrect answer\033[0m" << endl;
              *score1 += stoi(ptAmount);
              counter += 2;
              changeFormat(display1, ptAmount, "games");
              break;
            }
          }
          else
              break;
        }
      }
    if(counter == 2)
      cout << "\033[32m+" + ptAmount + " \033[44m" << name1  << "\033[0m you get \033[0mpoints"<< endl;
    else if(counter == 1)
      cout << "\033[31mInvalid amount\033[0m \033[44m" << name1 << "\033[0m you get +0 points" << endl;
    else
      cout << "\033[31mWrong answer\033[0m \033[44m" << name1 << "\033[0m you get +0 points" << endl;
    }
    // if user enters common knowledge
    else if(lowercase(category) == "common knowledge"){
      guess = trivia1(category, stoi(ptAmount));
      if(stoi(ptAmount) == 0)
        counter += 1;
      for(int i=0; i<5; i++){
        for(int j=0; j<6; j++){
          if(ptAmount == commonKnowledge[i][0]){
            if(guess == lowercase(commonKnowledge[i][j])){
              cout << "\033[32mCorrect answer\033[0m" << endl;
              *score1 += stoi(ptAmount);
              counter += 2;
              changeFormat(display1, ptAmount, "common knowledge");
              break;
            }
          }
          else
              break;
        }
      }
      if(counter == 2)
        cout << "\033[32m+" + ptAmount + " \033[44m" << name1  << "\033[0m you get \033[0mpoints"<< endl;
      else if(counter == 1)
        cout << "\033[31mInvalid amount\033[0m \033[44m" << name1 << "\033[0m you get +0 points" << endl;
      else
        cout << "\033[31mWrong answer\033[0m \033[44m" << name1 << "\033[0m you get +0 points" << endl;
    }
    // if user enters clash royale
    else if(lowercase(category) == "clash royale"){
      guess = trivia1(category, stoi(ptAmount));
      if(stoi(ptAmount) == 0){
          counter += 1;
      }
      for(int i=0; i<5; i++){
        for(int j=0; j<6; j++){
          if(ptAmount == clashRoyale[i][0]){
            if(guess == lowercase(clashRoyale[i][j])){
              cout << "\033[32mCorrect answer\033[0m" << endl;
              *score1 += stoi(ptAmount);
              counter += 2;
              changeFormat(display1, ptAmount, "clash royale");
              break;
            }
          }
          else
              break;
        }
      }
      if(counter == 2)
        cout << "\033[32m+" + ptAmount + " \033[44m" << name1  << "\033[0m you get \033[0mpoints"<< endl;
      else if(counter == 1)
        cout << "\033[31mInvalid amount\033[0m \033[44m" << name1 << "\033[0m you get +0 points" << endl;
      else
        cout << "\033[31mWrong answer\033[0m \033[44m" << name1 << "\033[0m you get +0 points" << endl;
    }
    // if user enters programming
    else if(lowercase(category) == "programming"){
      guess = trivia1(category, stoi(ptAmount));
      if(stoi(ptAmount) == 0)
        counter += 1;
      for(int i=0; i<5; i++){
        for(int j=0; j<6; j++){
          if(ptAmount == programming[i][0]){
            if(guess == lowercase(programming[i][j])){
              cout << "\033[32mCorrect answer\033[0m" << endl;
              *score1 += stoi(ptAmount);
              counter += 2;
              changeFormat(display1, ptAmount, "programming");
              break;
            }
          }
          else
              break;
        }
      }
      if(counter == 2)
        cout << "\033[32m+" + ptAmount + " \033[44m" << name1  << "\033[0m you get \033[0mpoints"<< endl;
      else if(counter == 1)
        cout << "\033[31mInvalid amount\033[0m \033[44m" << name1 << "\033[0m you get +0 points" << endl;
      else
        cout << "\033[31mWrong answer\033[0m \033[44m" << name1 << "\033[0m you get +0 points" << endl;
    }
    // if user enters riddles
    else if(lowercase(category) == "riddles"){
      guess = trivia1(category, stoi(ptAmount));
      if(stoi(ptAmount) == 0)
        counter += 1;
      for(int i=0; i<5; i++){
        for(int j=0; j<6; j++){
          if(ptAmount == riddles[i][0]){
            if(guess == lowercase(riddles[i][j])){
              cout << "\033[32mCorrect answer\033[0m" << endl;
              *score1 += stoi(ptAmount);
              counter += 2;
              changeFormat(display1, ptAmount, "riddles");
              break;
            }
          }
          else
              break;
        }
      }
      if(counter == 2)
        cout << "\033[32m+" + ptAmount + " \033[44m" << name1  << "\033[0m you get \033[0mpoints"<< endl;
      else if(counter == 1)
        cout << "\033[31mInvalid amount\033[0m \033[44m" << name1 << "\033[0m you get +0 points" << endl;
      else
        cout << "\033[31mWrong answer\033[0m \033[44m" << name1 << "\033[0m you get +0 points" << endl;
    }

    break;
  }

  case 2:{
    cout << "\033[31m"  << choice  << "<-- " << toDo[2] << "\033[0m" << endl << endl;
    cout << "You are now up, \033[44m" << name1 << "\033[0m" << endl;
    displayQuestions(display2);
    do {
      // uses randit to guess a random indice [0-19] inclusive -> it will use this as the indece of the questions array
      randInt = distribution(generator);
      value = display2[randInt];
    }
    // if the display2[randit] == "000" you keep doing rand int
    while(value == "000");
    changeFormat2(display2, randInt);
    cout << "\033[32mSelect the number\033[0m corresponding to the answer you want to choose." << endl;
    cout << "\033[33mQuestion: \033[0m";
    cout <<  questions2[randInt] << endl;
    displayAnswers(answerChoices, randInt);
    cout << ">>> ";
    cin >> answer;
    corrOrIncorr = checkAnswer((randInt), lowercase(answerChoices[randInt][(answer-1)]));
    if(corrOrIncorr){
      cout << "\033[32mCorrect Answer\n+250\033[0m points" << endl;
      *score1 += 250;
    }
    else
      cout << "\033[31mIncorrect Answer\n+0\033[0m points" << endl;

    // Find a way to give the right player the points
    break;
    // this closing curly bracket is for case 3
  }
  case 3:{
    cout << "\033[31m"  << choice  << "<-- " << toDo[2] << "\033[0m" << endl << endl;
    cout << "You will now be playing a game of tic tac toe to against your opponent." << endl << endl;
    cout << "\033[32mWIN  -> +300 points\033[0m for you   \033[31m-300 points\033[0m for your opponent" << endl;
    cout << "DRAW -> +0 points for you     -0 points for your opponent" << endl;
    cout << "\033[31mLOSE -> -150 points\033[0m for you   \033[32m+150 points\033[0m for your opponent" << endl;
    cout << "Press any key to begin(EXCEPT space) or dont, I dont really care: " << endl;
    cout << ">>> ";
    cin >> startTTT;
    cout << "\033[32m*************************************************************\033[0m" << endl;
    cout << "Player1: \033[44m" << name1 << "\033[0m\t\tPlayer2: \033[45m" << name2  << "\033[0m" << endl;
    tttWinner = playGame(name1, name2);
    
    if(tttWinner[0]){
      cout << "\033[44m" << name1 << "\033[0m has \033[32mWON\033[0m the tictactoe match, therefore, they get, \033[32m+300 points\033[0m" << endl;
      cout << "\033[45m" << name2 << "\033[0m has \033[31mLOST -300 points\033[0m" << endl;
      *score1 += 300;
      *score2 -= 300;
    }
    else if(tttWinner[1]){
      cout << "\033[44m" << name1 << "\033[0m has \033[31mLOST\033[0m the tictactoe match, therefore, they get, \033[31m-300 points\033[0m" << endl;
      cout << "\033[45m" << name2 << "\033[0m has \033[32mWON +300 points\033[0m" << endl;
      *score1 -= 300;
      *score2 += 300;
    }
    else{
      cout << "Game ended in a draw." << endl;
      cout << "\033[44m" << name1 << "\033[0m, you get +0 points" << endl;
      cout << "\033[45m" << name2 << "\033[0m, you get +0 points" << endl;
    }
    //ttWinner is a boolean array, use it to decide who gets the points

    break;
    // this closing curly bracket is for case 4
  }


  }
  return 0;

}




int main(){
  Player player1;
  Player player2;
  cout << "Player 1, what is your name: ";
  getline(cin, player1.name);
  cout << "\033[32mWelcome to The Ultimate Game,\033[0m " << player1.name << endl;
  ////////////////////////////////
  cout << "Player 2, what is your name: ";
  getline(cin, player2.name);
  cout << "\033[32mWelcome to The Ultimate Game,\033[0m " << player2.name << endl;
  start();

  bool playerWins[2] = {false, false};
  bool turns[2] = {true, false};

  while((!playerWins[0]) && (!playerWins[1])){
    if(turns[0]){
      begin(&player1.points, &player2.points, player1.name, player2.name);
      cout << "\t\t\t\t\t\033[44m" << player1.name << ":\033[0m   \033[3m\033[4m\033[38;5;208m" << player1.points << "\033[0m" << endl;
      cout << "\t\t\t\t\t\033[44m" << player2.name << ":\033[0m   \033[3m\033[4m\033[38;5;208m" << player2.points << "\033[0m" << endl;

      turns[0] = false;
      turns[1] = true;
      if(player1.points >= 2500){
        playerWins[0] = true;
        break;
      }
      else if(player2.points >= 2500){
        playerWins[1] = true;
        break;
      }
    }
    else if(turns[1]){
      begin(&player2.points, &player1.points, player2.name, player1.name);
      cout << "\t\t\t\t\t\033[44m" << player1.name << ":\033[0m   \033[3m\033[4m\033[38;5;208m" << player1.points << "\033[0m" << endl;
      cout << "\t\t\t\t\t\033[44m" << player2.name << ":\033[0m   \033[3m\033[4m\033[38;5;208m" << player2.points << "\033[0m" << endl;

      turns[1] = false;
      turns[0] = true;
      if(player2.points >= 2500){
        playerWins[1] = true;
        break;
      }
      else if(player1.points >= 2500){
        playerWins[0] = true;
        break;
      }
    }

  }
  if(playerWins[0])
    cout << "\033[42m" << player1.name << " is the winner.\033[0m" << endl;
  else if(playerWins)
    cout << "\033[42m" << player2.name << " is the winner.\033[0m" << endl;

  return 0;
}
