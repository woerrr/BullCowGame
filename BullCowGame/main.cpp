/* This is the console executablre, that makes use of the BullCow class
This acts as the view in a MVC pattern, and is 

*/
#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
FBullCowGame BCGame; //instantiate a new game
FBullCowCount BullCowCount;

void PrintIntro();
void PlayGame();
FText GetGuess();
bool AskToPlayAgain();
void PrintGameSummary();



int main() 
{
	
	//this is what does stuff 
	do 
	{	
		BCGame.Reset();
		PrintIntro();
		PlayGame();
	} 
	while (AskToPlayAgain());
	return 0;
}

void PlayGame()
{
	
	// ||
	//move this code
	/*
	std::cout << "please Enter word Length:";
	int UserWordLength;
	std::getline(std::cin, UserWordLength) >> UserWordLength;
	std::cout << std::endl;
	*/

	
	
	int32 Tries = BCGame.GetMaxTries();
	int32 i = 1;
	bool Gamewon = false;
	while (!Gamewon && i < BCGame.GetMaxTries())
	{
		FText Guess = GetGuess();		//submit valid guess to game
		BullCowCount = BCGame.SubmitGuess(Guess); // This passes a valid guess to  // LEARN THIS!!

		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << std::endl;
		std::cout << "Your guess was: " << Guess << std::endl; 

		PrintGameSummary();
		
		Gamewon = BCGame.IsGameWon();


		i++;
	}
	return;
	//TODO Summarise Game
}

void PrintIntro() 
{	//Introduction	
	std::cout << "Welcome to bulls and Cows\n";
	std::cout << "Guess the " << BCGame.GetWordLength() << " letter word\n";
	std::cout << std::endl;
	return;
}


FText GetGuess()
{
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	FText Guess = "";
	do {
		std::cout << std::endl << "try." << BCGame.GetCurrentTries() << " of " << BCGame.GetMaxTries() << " Enter you guess\n";
		
		std::getline(std::cin,Guess);

		Status = BCGame.CheckValidity(Guess);
		
		switch (Status)
		{
		case EGuessStatus::Not_Isogram:
			std::cout << "Sorry, your guess was invalid\n";
			std::cout << "Please enter an isogram\n";
			break;
		case EGuessStatus::Wrong_length:
			std::cout << "Sorry, your guess was invalid\n";
			std::cout << "Please enter a " << BCGame.GetWordLength() << " letter word\n";
			break;
		case EGuessStatus::Contains_numbers:
			std::cout << "Nah, Fuck you\n";
			std::cout << "word means no numbers\n";
		default:
			//assume guess is valid
			break;
		}
	} while (Status != EGuessStatus::OK);
	return Guess;
}


bool AskToPlayAgain()
{//Ask player if he wants to play again
	std::cout << "Do you want to play again?" << std::endl;
	std::cout << "y/n?" << std::endl;
	FText Response = "";
	getline(std::cin, Response);
	return (Response[0] == 'y' || Response[0] == 'Y');
}

void PrintGameSummary()
{
	if (BCGame.IsGameWon())
	{
		std::cout << "\n\nGrats on the thing\n\n";
	}
	else if (BCGame.GetMaxTries() - BCGame.GetCurrentTries() == 0)
	{
		std::cout << "\n\nAww shit nigga, you lost\n\n";
	}
}