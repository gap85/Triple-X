#include <iostream>

/**Print introduction for each iteration of the game*/
void PrintIntroduction(int Difficulty, int Attempts)
{
    if(Difficulty == 1)
    { 
    std::cout << "You are trapped in a stinky dungeon.\n";
    std::cout << "Figure out the secret code on each level to escape your putrid prison.\n";
    std::cout << "You have 2 chances to guess the correct sequence.\n";
    std::cout << "Terminate each number with a space or by pressing enter.\n";
    std::cout << "The difficulty will increase with each successful attempt\n";
    }
    std::cout << "////////////////////////////////////////////\n";
    std::cout << "You are at level: " << Difficulty << std::endl;
    std::cout << "Attempts left: " << Attempts << std::endl;
}

/**Create a random number chosen from a range constricted by the difficulty
 * Number range is from 0 to INT_MAX % (difficulty*5) + 1
*/
int GenerateNumber(int MaxNum){
    //TODO: COMPLETE
    return rand() % MaxNum + 1;
}

/**Begin the game*/
bool PlayGame(int Difficulty, int Attempts)
{
    PrintIntroduction(Difficulty, Attempts);

    int MaxNum = Difficulty * 5;

    //Generate Code numbers
    const int num3 = GenerateNumber(MaxNum);
    const int num2 = GenerateNumber(MaxNum);
    const int num1 = GenerateNumber(MaxNum);

    //Hint values
    int codeProduct = num3 * num2 * num1;
    int codeSum = num3 + num2 + num1;
    
    std::cout << "-----------HINT-----------\n";
    std::cout << "The product of the numbers is " << codeProduct << std::endl;
    std::cout << "The sum of the numbers is " << codeSum << std::endl;
    std::cout << "The correct values lie in the range 1 to " << MaxNum << std::endl;

    //Store guess
    int guess3, guess2, guess1;
    std::cout << "Enter your guess.\n";
    std::cin >> guess3;
    std::cin >> guess2;
    std::cin >> guess1;
    std::cout << "You answered: " << guess3 << " " << guess2 << " " << guess1 << std::endl;

    //Check guess
    int guessSum = guess3 + guess2 + guess1;
    int guessProduct = guess3 * guess2 * guess1;  
     
     if(guessSum == codeSum && guessProduct == codeProduct)
     {
         
        std::cout << "Congratulations you successfully cracked the code\n";
        std::cout << "Proceeding to the next room\n\n";
        std::cout << "////////////////////////////////////////////\n\n";
        return true;
     }
     else
     {
        std::cout << "XXXXXXXXXXXXXXXXX\n";
        std::cout << "Ouch! You were shocked for guessing wrong.\n";
        std::cout << "////////////////////////////////////////////\n\n";
        return false;
     }
}

int main()
{
    srand(time(NULL));
    int LevelDifficulty = 1;
    const int MaxDifficulty = 1;
    int Attempts = 3;

    while (LevelDifficulty <= MaxDifficulty && Attempts > 0)
    {
        bool bLevelComplete = PlayGame(LevelDifficulty, Attempts);
        
        std::cin.clear(); //Clear user input errors
        
        std::cin.ignore(); //Clear input buffer

        if (bLevelComplete)
        {
            ++LevelDifficulty;
            Attempts = 3;
        }
        else
        {
            --Attempts;
        }
    }

    if (Attempts == 0)
    {
        std::cout << "You failed to escape and are cursed to forever bathe in stink\n";
    }
    else
    {
        std::cout << "Freedom!\n";
        std::cout << "You make it out and your nostrils are filled with the sweet scent of daisies.\n";
    }

    std::getchar();
    return 0;
}