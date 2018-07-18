#pragma once
#include <string>

using FString = std::string;
using int32 = int;

struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0; 
};

enum class EGuessStatus
{
	Invalid_Status,
	OK,
	Not_Isogram,
	Wrong_length,
	Contains_numbers
};

class FBullCowGame {
public:
	FBullCowGame(); //constructor
	
	void Reset(); //resets the game values to default
	int32 GetMaxTries() const;
	int32 GetCurrentTries() const;
	bool IsGameWon() const;
	EGuessStatus CheckValidity(FString);
	FString GetNewWord();
	FString GetAnswer();
	int32 GetWordLength();
	//bool CheckIsAnswerCorrect() const;
	FBullCowCount SubmitGuess(FString);
	bool AnswerContainsNumbers(FString Guess);
	//ignore for now
private:
	
	bool IsIsogram(FString Guess) const;
	bool bIsGameWon = false;
	FString Answer;
	int32 MyCurrentTries;
};