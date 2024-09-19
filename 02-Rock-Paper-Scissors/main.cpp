#include <iostream>
#include <cctype>
#include <cassert>
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;

const string R = "Rock";
const string P = "Paper";
const string S = "Scissors";


// Convert the random number rappresenting the choice into a string
// *TESTED*
string codeToChoice(int number){
    string choice = " ";
    switch(number){
            case 1:
                choice = R;
                break;
            case 2:
                choice = P;
                break;
            case 3:
                choice = S;
                break;
            
            default:
                cerr << "Random number is not valid.";
                exit(EXIT_FAILURE);
        }
    return choice;
}


// function which return Rock, Paper or Scissors from a random generated number.
// *TESTED*
string getComputerChoice(){
    int random_number = 0;
    string choice = " ";

    random_number = rand() % 3 + 1; // random number between 1 and 3 both included
    return codeToChoice(random_number); // converting 1,2,3 to Rock,Paper,Scissor
    
    
}


// function to get user choice from std input
//*TESTED* 
string getPlayerChoice(){
    bool running = true;
    int choice_code = 0;
    while(running){
        cout << "1)Rock     2)Paper         3)Scissor" << endl;
        cout << "Insert your choice: ";
        cin >> choice_code;
        if(cin.fail() || choice_code < 1 || choice_code > 3){
            cin.clear();
            cin.ignore(123, '\n');
            cout << "Inserisci un numero valido.\n";
        }else{
            running = false;
        }
    }
    return codeToChoice(choice_code);
}



// function to calculate single hand winner 
// 1 if player wins, 2 if computer wins, 0 if draw
// *TESTED*
int getSingleHandWinner(string player, string computer){
    if(player == R){                    //rock
                                        // vs
        if(computer == S){              // scissors or
            return 1;                   
        } else if(computer == P){       // paper or
            return 2;
        } else if(computer == R){       // rock
            return 0;
        } else{                         // invalid match up
            cerr << "Error, invalid match up " << computer << " vs " << player;
            exit(EXIT_FAILURE);
        }
    }
    if(player == P){                    //paper
                                        // vs
        if(computer == S){              // scissors or
            return 2;                   
        } else if(computer == P){       // paper or
            return 0;
        } else if(computer == R){       // rock
            return 1;
        } else{                         // invalid match up
            cerr << "Error, invalid match up " << computer << " vs " << player;
            exit(EXIT_FAILURE);
        }
    }

    if(player == S){                    //scissor
                                        // vs
        if(computer == S){              // scissors or
            return 0;                   
        } else if(computer == P){       // paper or
            return 1;
        } else if(computer == R){       // rock
            return 2;
        } else{                         // invalid match up
            cerr << "Error, invalid match up " << computer << " vs " << player;
            exit(EXIT_FAILURE);
        }
    }

    cerr << "Player has no valid choose" << endl;
    exit(EXIT_FAILURE);
    
}

// function to print result
void print_result(int winnerCode, int& playerScore, int& computerScore){
    switch(winnerCode){
        case 1:
            cout << "Player wins!" << endl;
            playerScore++;
            break;
        case 2:
            cout << "Computer wins!" << endl;
            computerScore++;
            break;
        case 0:
            cout << "That's a draw!" << endl;
            break;
        default:
            cerr << "Invalid result!(check print_result() function)";
    }
}

void startGame(){
    int playerScore = 0, computerScore = 0, handWinner = 0;
    int roundCounter = 0;
    bool running = true;
    string computerChoice = " ";
    string playerChoice = " ";
    // best of five game
    while(running){
        cout << "-------------------------------------------- NEW ROUND --------------------------------------------" << endl;
        cout << "Round " << ++roundCounter << endl;
        cout << "Player's Score: " << playerScore <<
                "               Computer's Score: " << computerScore << endl;

        playerChoice = getPlayerChoice();           // getting playerChoice
        computerChoice = getComputerChoice();       // getting computer choice
        cout << playerChoice << " vs " << computerChoice << endl;
        handWinner = getSingleHandWinner(playerChoice, computerChoice); // calculate single hand winner
        print_result(handWinner, playerScore, computerScore);
        Sleep(100);
        

        // check for possible winner
        if(playerScore == 5 || computerScore == 5){
            cout << "The score is " << playerScore << " to " << computerScore << endl;
            running = false;
            if(playerScore == 5){
                cout << "Player wins!" << endl;
            } else if(computerScore == 5){
                cout << "Computer wins!" << endl;
            }
            
        }
            

    }

}

int main(){
    srand(time(NULL)); // adding a random seed with time function
    bool running = true;
    char keepGoing = ' ';

    while(running){
        startGame();
        cout << "Press E to exit, any key to play again." << endl;
        cin >> keepGoing;
        if(tolower(keepGoing) == 'e'){
            running = false;
        }
    }
    
    
    
    return 0;
}