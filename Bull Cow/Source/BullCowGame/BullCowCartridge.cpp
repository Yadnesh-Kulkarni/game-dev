// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    SetupGame();
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{

    if(bGameOver)
    {
        ClearScreen();
        SetupGame();
    }
    else
    {
        ProcessGuess(Input);
    }
}

void UBullCowCartridge::SetupGame()
{
    HiddenWord = TEXT("about");
    Lives = HiddenWord.Len();
    bGameOver = false;

    //PrintLine(TEXT("Welcome to Bull Cow Game!"));
    PrintLine(TEXT("Guess the %i letter word..."),HiddenWord.Len());

    PrintLine(TEXT("You have %i lives left"),Lives);
}

void UBullCowCartridge::EndGame()
{
    bGameOver = true;
    PrintLine(TEXT("Press Enter to play again!"));
}

void UBullCowCartridge::ProcessGuess(FString Guess)
{
    if(Guess == HiddenWord)
    {
        PrintLine(TEXT("Congratualations! You have found the write word. Can you guess the next word?"));
        EndGame();
        return;
    }
    
        PrintLine(TEXT("Lost a life.\n%i lives left"),--Lives);
        if(Lives > 0)
        {
            if(Guess.Len() != HiddenWord.Len())
            {
                PrintLine(TEXT("Sorry! Wrong Guess.\nTry again you have %i lives left"),Lives);
            }
        }
        else
        {
            PrintLine(TEXT("Ran out of lives."));
            EndGame();
        }
    }
}