#include "FBullCowGame.h"
#include <time.h>
#include <map>
#define Tmap std::map

using int32 = int;

int FBullCowGame::GetMaxTries() const
{
	Tmap<int32, int32> WordLengthToMaxTries{ {3,5}, {4,8}, {5,10}, {6,1},{7,14} };

	Answer.length();
	return WordLengthToMaxTries[Answer.length()];
	}
int FBullCowGame::GetCurrentTries() const { return MyCurrentTries; }

bool FBullCowGame::IsGameWon() const 
{ 
	return bIsGameWon;
}

FBullCowCount FBullCowGame::SubmitGuess(FString Guess) //recieves a valid guess, increments  turn and returns count
{
	MyCurrentTries++;
	FBullCowCount BullCowCount;


	////loop through all letters in the guess, //compare letters against Answer
		//compare letters agaainst the hidden word
			//if they match then increment bulls aand cows as needed

	int32 AnswerLength = Answer.length();

	for (int32 i = 0; i < AnswerLength; i++)
	{
		for (int32 j = 0; j < AnswerLength; j++)
		{
			char c = Guess[i];
			c = tolower(c);
			if (Answer[j] == c)
			{
				if (i == j)
				{
					BullCowCount.Bulls++;
				}
				else
				{
					BullCowCount.Cows++;
				}
			}
			
			
		}
		

	}

	if (BullCowCount.Bulls == Answer.length()) 
	{
		bIsGameWon = true;
	}
	return BullCowCount;
}

FBullCowGame::FBullCowGame() //this will run when instanced because it has same name as class
{
	return;
}

void FBullCowGame::Reset()
{
	MyCurrentTries = 1;
	Answer = GetNewWord();
	bIsGameWon = false;
	return ;
}

EGuessStatus FBullCowGame::CheckValidity(FString Guess)
{

	if (!IsIsogram(Guess)) //check if word is isogram
	{
		return EGuessStatus::Not_Isogram;
	}
 	else if (Guess.length() != Answer.length()) //Check if word if correct length
	{
		return EGuessStatus::Wrong_length;
	}
	else if (AnswerContainsNumbers(Guess))
	{
		return EGuessStatus::Contains_numbers;
	}

	
	else
	{
		return EGuessStatus::OK;
	}
}
//gets a new random word as answer, using RNG
FString FBullCowGame::GetNewWord() 
{
	int32 iSecret;
	srand(time(NULL));
	iSecret = rand() % 20 + 1;  //RNG  1-20

	switch (iSecret)
	{
	case 1:
		Answer = "cramp";
		break;
	case 2:
		Answer = "fast";
		break;
	case 3:
		Answer = "dragon";
		break;
	case 4:
		Answer = "whip";
		break;
	case 5:
		Answer = "shadow";
		break;
	case 6:
		Answer = "grant";
		break;
	case 7:
		Answer = "deny";
		break;
	case 8:
		Answer = "prove";
		break;
	case 9:
		Answer = "self";
		break;
	case 10:
		Answer = "body";
		break;
	case 11:
		Answer = "decay";
		break;
	case 12:
		Answer = "chin";
		break;
	case 13:
		Answer = "stand";
		break;
	case 14:
		Answer = "money";
		break;
	case 15:
		Answer = "care";
		break;
	case 16:
		Answer = "bowl";
		break;
	case 17:
		Answer = "what";
		break;
	case 18:
		Answer = "sound";
		break;
	case 19:
		Answer = "planet";
		break;
	case 20:
		Answer = "parsley";
		break;
	default:
		break;
	} //implement switch//
	
	if (Answer.length() == 5)
	{
		Answer = "cramp";
	}
	if (Answer.length() == 6)
	{
		Answer = "planet";
	}
	return Answer;
}
//returns answer to main.cpp
FString FBullCowGame::GetAnswer()
{

	return Answer;
}
//Get answer length
int32 FBullCowGame::GetWordLength()
{
	
	return Answer.length();
}

bool FBullCowGame::IsIsogram(FString Guess) const 
{
	if (Guess.length() < 2) { return true; }
	Tmap <char, bool > LettersSeen;

//i IS A CHAR!!, NOT AN INT REPRESENTING A CHAR!!
	for (auto i : Guess)
	{
		i = tolower(i);
		if (LettersSeen[i])
		{
			return false;
		}
		else
		{
			LettersSeen[i] = true;
		}
	}
	return true;
}

bool FBullCowGame::AnswerContainsNumbers(FString Guess)
{
	for (auto c: Guess)
	{//TODO fix bad code use map
		if		(c == 0) { return true; }
		else if (c == 1) { return true; }
		else if (c == 2) { return true; }
		else if (c == 3) { return true; }
		else if (c == 4) { return true; }
		else if (c == 5) { return true; }
		else if (c == 6) { return true; }
		else if (c == 7) { return true; }
		else if (c == 8) { return true; }
		else if (c == 9) { return true; }
	}
	return false;
}