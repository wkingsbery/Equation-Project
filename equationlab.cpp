//Billy Kingsbery
//This program takes two randomly determined numbers, a random operand, and spits back out equations that the user has to answer.
#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;
//function defining
char randOp();
int randOperator();
int randomNum(int, int);
int negativeRandomNum(int, int);
double evaluate(int, int, char);
double percentage(int, int);
void createEquation(int, int, int[], int[], char[], double[]);
void createNegativeEquation(int, int, int[], int[], char[], double[]);
void signCount(int&, int&, int&, int&, char);
bool isRepeat(int, int, int, int, int, int);
bool repeatCheck(int, int[], int[], char[]);
//constants for each of the levels of the game
const int LEVEL_ONE_MIN = 0;
const int LEVEL_ONE_MAX = 10;
const int LEVEL_TWO_MIN = 0;
const int LEVEL_TWO_MAX = 25;
const int LEVEL_THREE_MIN = 10;
const int LEVEL_THREE_MAX = 25;
const int LEVEL_FOUR_MIN = 0;
const int LEVEL_FOUR_MAX = 25;
const int MAX = 100;
int main()
{
        char choice = '1';
	char secondChoice = '1';
	char thirdChoice = '1';
	char finalChoice = '1';
        int addCount = 0, subCount = 0, mulCount = 0, divCount = 0, levelTwoAddCount = 0, levelTwoSubCount = 0, levelTwoMulCount = 0, levelTwoDivCount = 0;
        int addRight = 0, subRight = 0, mulRight = 0, divRight = 0, levelTwoAddRight = 0, levelTwoSubRight = 0, levelTwoMulRight = 0, levelTwoDivRight = 0;
	int timesCompleted = 0;
	int levelThreeAddCount = 0, levelThreeSubCount = 0, levelThreeMulCount = 0, levelThreeDivCount = 0, levelThreeAddRight = 0;
	int levelThreeSubRight = 0, levelThreeMulRight = 0, levelThreeDivRight = 0;
	int levelFourAddCount = 0, levelFourSubCount = 0, levelFourMulCount = 0, levelFourDivCount = 0, levelFourAddRight = 0;
        int levelFourSubRight = 0, levelFourMulRight = 0, levelFourDivRight = 0, rightCountPartFour = 0;
        double myResult;
        int operator1[MAX], operator2[MAX], level2op1[MAX], level2op2[MAX], level3op1[MAX], level3op2[MAX], level4op1[MAX], level4op2[MAX];
        int  wrongCount, newResult, j, count, rightCount, total, rightCountPartTwo = 0, rightCountPartThree = 0;
        char operand[MAX], operandLevel2[MAX], operandLevel3[MAX], operandLevel4[MAX];
        double resultz[MAX], resultzLevel2[MAX], resultzLevel3[MAX], resultzLevel4[MAX];
	double addPercentage, subPercentage, mulPercentage, divPercentage, addPercentageLevelTwo, subPercentageLevelTwo, mulPercentageLevelTwo, divPercentageLevelTwo;
	double addPercentageLevelThree, subPercentageLevelThree, mulPercentageLevelThree, divPercentageLevelThree, addPercentageLevelFour, subPercentageLevelFour, mulPercentageLevelFour, divPercentageLevelFour;
        createEquation(LEVEL_ONE_MIN, LEVEL_ONE_MAX, operator1, operator2, operand, resultz);
	createEquation(LEVEL_TWO_MIN, LEVEL_TWO_MAX, level2op1, level2op2, operandLevel2, resultzLevel2);
	createEquation(LEVEL_THREE_MIN, LEVEL_THREE_MAX, level3op1, level3op2, operandLevel3, resultzLevel3);
	createNegativeEquation(LEVEL_FOUR_MIN, LEVEL_FOUR_MAX, level4op1, level4op2, operandLevel4, resultzLevel4);
	//This do-switch statement gives the user the ability to repeat an option as long as they stay options 1 or 3.  	
	do
	{
		switch(choice)
		{
			case '1':
			{
				rightCount = 0;
				j = 0;
				total = 0;
       				while(rightCount < 10 && j < MAX)
        			{
               				do
                			{
                        			cout << rightCount;
                        			cout << "What is " << operator1[(timesCompleted * 10) + j] << operand[(timesCompleted * 10) + j] << operator2[(timesCompleted * 10) +j] << "?"  << endl;
                        			signCount(addCount, subCount, mulCount, divCount, operand[(timesCompleted * 10) + j]);
                        			cin >> myResult;
                        			if ((myResult - resultz[(timesCompleted * 10) + j]) <= 0.001)
                        			{
                                			cout << "Correct!" << endl;
                                			rightCount++;
                                			if (operand[(timesCompleted * 10) + j] == '+')
                                			{
                                        			addRight++;
                                			}	
                                			else if (operand[(timesCompleted * 10) + j] == '-')
                                			{
                                        			subRight++;
                                			}
                                			else if (operand[(timesCompleted * 10) + j] == '/')
                                			{
                                        			divRight++;
                                			}	
                                			else if (operand[(timesCompleted * 10) + j] == '*')
                                			{
                                        			mulRight++;
                                			}
                        			}
                        			else
                        			{		
                                			cout << "Wrong."  << "The answer was: " << resultz[(timesCompleted * 10) + j] << endl;
                                			rightCount = 0;
                                			wrongCount++;
                        			}
               	 			}while(resultz[(timesCompleted * 10) + j] == -10000);
					j++;
        			}
				cout << "What would you like to do??" << endl;
				cout << "1) Repeat this level"  << endl;
				cout << "2) Go to the next level" << endl;
				cout << "3) See the statistics for this level" << endl;
				cout << "4) Quit the game" << endl;
				cin >> choice;
				timesCompleted++;
				break;
			}
			case '3':
			{
				addPercentage = percentage(addRight, addCount);
				subPercentage = percentage(subRight, subCount);
				mulPercentage = percentage(mulRight, mulCount);
				divPercentage = percentage(divRight, divCount);
				cout << "Your percentage of addition is : " << addPercentage << endl;
				cout << "Your percentage of subtraction is : " << subPercentage << endl;
				cout << "Your percentage of multiplication is : " << mulPercentage << endl;
				cout << "Your percentage of division is : " << divPercentage << endl;
				cout << "What would you like to do??" << endl;
	                	cout << "1) Repeat this level"  << endl;
        	        	cout << "2) Go to the next level" << endl;
                		cout << "3) See the statistics for this level" << endl;
                		cout << "4) Quit the game" << endl;
				cin >> choice;
				break;
			}
		}
	}while (choice == '1' || choice == '3');
	//Moving on to Level 2
	if (choice == '2')
	{
		do
		{
			switch(secondChoice)
			{
				case '1':
				{
					rightCountPartTwo = 0;
                               	 	j = 0;
					wrongCount = 0;
                                	total = 0;
                                	while(rightCountPartTwo < 10 && j < MAX)
                                	{
                                        	do
                                        	{
                                                	cout << rightCountPartTwo;
                                                	cout << "What is " << level2op1[(timesCompleted * 10) + j] << operandLevel2[(timesCompleted * 10) + j] << level2op2[(timesCompleted * 10) +j] << "?"  << endl;
                                                	signCount(levelTwoAddCount, levelTwoSubCount, levelTwoMulCount, levelTwoDivCount, operandLevel2[(timesCompleted * 10) + j]);
                                                	cin >> myResult;
                                                	if ((myResult - resultzLevel2[(timesCompleted * 10) + j]) <= 0.001)
                                                	{
                                                        	cout << "Correct!" << endl;
                                                        	rightCountPartTwo++;
                                                        	if (operandLevel2[(timesCompleted * 10) + j] == '+')
                                                        	{
                                                                	levelTwoAddRight++;
                                                        	}
                                                        	else if (operandLevel2[(timesCompleted * 10) + j] == '-')
                                                        	{
                                                                	levelTwoSubRight++;
                                                        	}
                                                        	else if (operandLevel2[(timesCompleted * 10) + j] == '/')
                                                        	{
                                                                	levelTwoDivRight++;
                                                        	}
                                                        	else if (operandLevel2[(timesCompleted * 10) + j] == '*')
                                                        	{
                                                                	levelTwoMulRight++;
                                                        	}
                                                	}
                                                	else
                                                	{
                                                        	cout << "Wrong."  << "The answer was: " << resultzLevel2[(timesCompleted * 10) + j] << endl;
                                                        	rightCountPartTwo = 0;
                                                        	wrongCount++;
                                                	}

						}while (resultzLevel2[(timesCompleted * 10) + j] == -10000);
						j++;
					}
					cout << "What would you like to do??" << endl;
                                        cout << "1) Repeat this level"  << endl;
                                        cout << "2) Go to the next level" << endl;
                                        cout << "3) See the statistics for this level" << endl;
					cout << "4) Quit the game"  << endl;
					cin >> secondChoice;
					break;
				}
				case '3':
				{
					addPercentageLevelTwo = percentage(levelTwoAddRight, levelTwoAddCount);
					subPercentageLevelTwo = percentage(levelTwoSubRight, levelTwoSubCount);
					mulPercentageLevelTwo = percentage(levelTwoMulRight, levelTwoMulCount);
					divPercentageLevelTwo = percentage(levelTwoDivRight, levelTwoDivCount);
					cout << "Your percentage of addition is : " << addPercentageLevelTwo << endl;
					cout << "Your percentage of subtraction is : " << subPercentageLevelTwo << endl;
					cout << "Your percentage of multiplication is : " << mulPercentageLevelTwo << endl;
					cout << "Your percentage of division is : " << divPercentageLevelTwo << endl;
					cout << "What would you like to do??" << endl;
					cout << "1) Repeat this level"  << endl;
                                	cout << "2) Go to the next level" << endl;
                                	cout << "3) See the statistics for this level" << endl;
                                	cout << "4) Quit the game" << endl;
                                	cin >> choice;
                                	break;
				}
			}
		}while (secondChoice == '1' || secondChoice == '3');
		//Quitting the game at Level 2
		if (secondChoice == '4')
		{
			addPercentage = percentage(addRight, addCount);
			subPercentage = percentage(subRight, subCount);
			mulPercentage = percentage(mulRight, mulCount);
			divPercentage = percentage(divRight, divCount);
			cout << "Your percentage of addition at Level 1 is: " << addPercentage << endl;
			cout << "Your percentage of subtraction at Level 1 is: " << subPercentage << endl;
			cout << "Your percentage of multiplication at Level 1 is: " << mulPercentage << endl;
			cout << "Your percentage of division at Level 1 is : " << divPercentage << endl;

			addPercentageLevelTwo = percentage(levelTwoAddRight, levelTwoAddCount);
			subPercentageLevelTwo = percentage(levelTwoSubRight, levelTwoSubCount);
			mulPercentageLevelTwo = percentage(levelTwoMulRight, levelTwoMulCount);
			divPercentageLevelTwo = percentage(levelTwoDivRight, levelTwoDivCount);
			cout << "Your percentage of addition at Level 2 is : " << addPercentageLevelTwo << endl;
			cout << "Your percentage of subtraction at Level 2 is : " << subPercentageLevelTwo << endl;
			cout << "Your percentage of multiplication at Level 2 is : " << mulPercentageLevelTwo << endl;
			cout << "Your percentage of division at Level 2 is : " << divPercentageLevelTwo << endl;

			cout << "Thanks for playing!"  << endl;
		}
		//Moving on to Level 3
		if (secondChoice == '2')
		{
			do
			{
				switch(thirdChoice)
				{
					case '1':
					{
						rightCountPartThree = 0;
						j = 0;
						wrongCount = 0;
						total = 0;
                        	                while(rightCountPartThree < 10 && j < MAX)
                                	        {
                                        	        do
                                                	{
                                                       		cout << rightCountPartThree;
                                                        	cout << "What is " << level3op1[(timesCompleted * 10) + j] << operandLevel3[(timesCompleted * 10) + j] << level3op2[(timesCompleted * 10) +j] << "?"  << endl;
                                                        	signCount(levelThreeAddCount, levelThreeSubCount, levelThreeMulCount, levelThreeDivCount, operandLevel3[(timesCompleted * 10) + j]);
                                                        	cin >> myResult;
                                                        	if ((myResult - resultzLevel3[(timesCompleted * 10) + j]) <= 0.001)
                                                        	{
                                                                	cout << "Correct!" << endl;
                                                                	rightCountPartThree++;
                                                                	if (operandLevel3[(timesCompleted * 10) + j] == '+')
                                                                	{
                                                                        	levelThreeAddRight++;
                                                                	}
                                                                	else if (operandLevel3[(timesCompleted * 10) + j] == '-')
                                                                	{
                                                                        	levelThreeSubRight++;
                                                                	}
                                                                	else if (operandLevel3[(timesCompleted * 10) + j] == '/')
                                                                	{
                                                                        	levelThreeDivRight++;
                                                                	}
                                                                	else if (operandLevel3[(timesCompleted * 10) + j] == '*')
                                                                	{
                                                                        	levelThreeMulRight++;
                                                                	}
                                                        	}
                                                        	else
                                                        	{
                                                                	cout << "Wrong."  << "The answer was: " << resultzLevel3[(timesCompleted * 10) + j] << endl;
                                                                	rightCountPartThree = 0;
                                                                	wrongCount++;
                                                        	}
                                               	 		}while (resultzLevel3[(timesCompleted * 10) + j] == -10000);
                                               		 j++;
						}
						cout << "What would you like to do??" << endl;
						cout << "1) Repeat this level"  << endl;
						cout << "2) Go to the next level" << endl;
                	                        cout << "3) See the statistics for this level" << endl;
                        	                cout << "4) Quit the game"  << endl;
                                	        cin >> thirdChoice;
                                       	 	break;
					}
					case '3':
					{
						addPercentageLevelThree = percentage(levelThreeAddRight, levelThreeAddCount);
						subPercentageLevelThree = percentage(levelThreeSubRight, levelThreeSubCount);
						divPercentageLevelThree = percentage(levelThreeDivRight, levelThreeDivCount);
						mulPercentageLevelThree = percentage(levelThreeMulRight, levelThreeMulCount);
		       				cout << "Your percentage of addition is : " << addPercentageLevelThree << endl;
                                        	cout << "Your percentage of subtraction is : " << subPercentageLevelThree << endl;
                                        	cout << "Your percentage of multiplication is : " << mulPercentageLevelThree << endl;
                                        	cout << "Your percentage of division is : " << divPercentageLevelThree << endl;
                                        	cout << "What would you like to do??" << endl;
                                        	cout << "1) Repeat this level"  << endl;
                                        	cout << "2) Go to the next level" << endl;
                                        	cout << "3) See the statistics for this level"  << endl;
						cout << "4) Quit the game" << endl;
						cin >> thirdChoice;
						break;
					}
				}
			}while (thirdChoice == '1' || thirdChoice == '3');
			//Moving on to Level 4
			if (thirdChoice == '2')
			{
				do
                        	{
                               		switch(finalChoice)
                                	{
                                        	case '1':
                                        	{
							timesCompleted = 0;
                                                	rightCountPartFour = 0;
                                                	j = 0;
                                                	wrongCount = 0;
                                                	total = 0;
                                                	while(rightCountPartFour < 10 && j < MAX)
                                                	{
                                                        	do
                                                        	{
                                                                	cout << rightCountPartFour;
                                                                	cout << "What is " << level4op1[(timesCompleted * 10) + j] << operandLevel4[(timesCompleted * 10) + j] << level4op2[(timesCompleted * 10) +j] << "?"  << endl;
                                                                	signCount(levelFourAddCount, levelFourSubCount, levelFourMulCount, levelFourDivCount, operandLevel4[(timesCompleted * 10) + j]);
                                                                	cin >> myResult;
                                                                	if ((myResult - resultzLevel4[(timesCompleted * 10) + j]) <= 0.001)
                                                                	{
                                                                        	cout << "Correct!" << endl;
                                                                        	rightCountPartFour++;
                                                                        	if (operandLevel4[(timesCompleted * 10) + j] == '+')
                                                                        	{
                                                                                	levelFourAddRight++;
                                                                        	}
                                                                        	else if (operandLevel4[(timesCompleted * 10) + j] == '-')
                                                                        	{
                                                                                	levelFourSubRight++;
                                                                        	}
                                                                        	else if (operandLevel4[(timesCompleted * 10) + j] == '/')
                                                                        	{
                                                                                	levelFourDivRight++;
                                                                        	}
                                                                        	else if (operandLevel4[(timesCompleted * 10) + j] == '*')
                                                                        	{
                                                                                	levelFourMulRight++;
                                                                        	}
                                                                	}
									else
	                        	                                {
        	                                        	                cout << "Wrong."  << "The answer was: " << resultzLevel4[(timesCompleted * 10) + j] << endl;
                	                	                                rightCountPartFour = 0;
                        	                	                        wrongCount++;
                                                     			 }
                                               			 }while (resultzLevel4[(timesCompleted * 10) + j] == -10000);
                                                		j++;
                                        		}
                                        		cout << "What would you like to do??" << endl;
                                        		cout << "1) Repeat this level"  << endl;
                               				cout << "2) See the statistics for this level" << endl;
                          				cout << "3) Quit the game"  << endl;
							cin >> finalChoice;
							break;
						}
						case '2':
						{
							addPercentageLevelFour = percentage(levelFourAddRight, levelFourAddCount);
	       	                                        subPercentageLevelFour = percentage(levelFourSubRight, levelFourSubCount);
       	        	                                divPercentageLevelFour = percentage(levelFourDivRight, levelFourDivCount);
                               	                	mulPercentageLevelFour = percentage(levelFourMulRight, levelFourMulCount);
                                       		        cout << "Your percentage of addition at Level 4 is : " << addPercentageLevelFour << endl;
                                               		cout << "Your percentage of subtraction at Level 4 is : " << subPercentageLevelFour << endl;
                                               		cout << "Your percentage of multiplication at Level 4 is : " << mulPercentageLevelFour << endl;
                                               		cout << "Your percentage of division is : " << divPercentageLevelFour << endl;
                                               		cout << "What would you like to do??" << endl;
                                               		cout << "1) Repeat this level"  << endl;
							cout << "2) See the statistics for this level"  << endl;
							cout << "3) Quit the game" << endl;
							cin >> finalChoice;
							break;
						}
								
					}
				}while(finalChoice == '1' || finalChoice == '2');
				if (finalChoice != '1' || finalChoice != '2')
				{
					addPercentage = percentage(addRight, addCount);
	                                subPercentage = percentage(subRight, subCount);
        	                        mulPercentage = percentage(mulRight, mulCount);
                	                divPercentage = percentage(divRight, divCount);
                        	        cout << "Your percentage of addition at Level 1 is: " << addPercentage << endl;
                                	cout << "Your percentage of subtraction at Level 1 is: " << subPercentage << endl;
                                	cout << "Your percentage of multiplication at Level 1 is: " << mulPercentage << endl;
                                	cout << "Your percentage of division at Level 1 is : " << divPercentage << endl;

                                	addPercentageLevelTwo = percentage(levelTwoAddRight, levelTwoAddCount);
                                	subPercentageLevelTwo = percentage(levelTwoSubRight, levelTwoSubCount);
                                	mulPercentageLevelTwo = percentage(levelTwoMulRight, levelTwoMulCount);
                                	divPercentageLevelTwo = percentage(levelTwoDivRight, levelTwoDivCount);
                                	cout << "Your percentage of addition at Level 2 is : " << addPercentageLevelTwo << endl;
                                	cout << "Your percentage of subtraction at Level 2 is : " << subPercentageLevelTwo << endl;
                                	cout << "Your percentage of multiplication at Level 2 is : " << mulPercentageLevelTwo << endl;
                                	cout << "Your percentage of division at Level 2 is : " << divPercentageLevelTwo << endl;

                                	addPercentageLevelThree = percentage(levelThreeAddRight, levelThreeAddCount);
                                	subPercentageLevelThree = percentage(levelThreeSubRight, levelThreeSubCount);
                                	divPercentageLevelThree = percentage(levelThreeDivRight, levelThreeDivCount);
                                	mulPercentageLevelThree = percentage(levelThreeMulRight, levelThreeMulCount);
                                	cout << "Your percentage of addition at Level 3 is : " << addPercentageLevelThree << endl;
                                	cout << "Your percentage of subtraction at Level 3 is : " << subPercentageLevelThree << endl;
                                	cout << "Your percentage of multiplication at Level 3 is : " << mulPercentageLevelThree << endl;
                                	cout << "Your percentage of division at Level 3 is: " << divPercentageLevelThree << endl;

					addPercentageLevelFour = percentage(levelFourAddRight, levelFourAddCount);
					subPercentageLevelFour = percentage(levelFourSubRight, levelFourSubCount);
					divPercentageLevelFour = percentage(levelFourDivRight, levelFourDivCount);
					mulPercentageLevelFour = percentage(levelFourMulRight, levelFourMulCount);
					cout << "Your percentage of addition at Level 4 is : " << addPercentageLevelFour << endl;
					cout << "Your percentage of subtraction at Level 4 is : " << subPercentageLevelFour << endl;
					cout << "Your percentage of multiplication at Level 4 is : " << mulPercentageLevelFour << endl;
					cout << "Your percentage of division is : " << divPercentageLevelFour << endl;

                                	cout << "Thanks for playing!"  << endl;

				}
			}
			//Quitting the game at Level 3
			if (thirdChoice == '4')
			{
				addPercentage = percentage(addRight, addCount);
	                        subPercentage = percentage(subRight, subCount);
        	                mulPercentage = percentage(mulRight, mulCount);
                	        divPercentage = percentage(divRight, divCount);
                       		cout << "Your percentage of addition at Level 1 is: " << addPercentage << endl;
                        	cout << "Your percentage of subtraction at Level 1 is: " << subPercentage << endl;
                        	cout << "Your percentage of multiplication at Level 1 is: " << mulPercentage << endl;
                        	cout << "Your percentage of division at Level 1 is : " << divPercentage << endl;

                        	addPercentageLevelTwo = percentage(levelTwoAddRight, levelTwoAddCount);
                        	subPercentageLevelTwo = percentage(levelTwoSubRight, levelTwoSubCount);
                        	mulPercentageLevelTwo = percentage(levelTwoMulRight, levelTwoMulCount);
                        	divPercentageLevelTwo = percentage(levelTwoDivRight, levelTwoDivCount);
                        	cout << "Your percentage of addition at Level 2 is : " << addPercentageLevelTwo << endl;
                        	cout << "Your percentage of subtraction at Level 2 is : " << subPercentageLevelTwo << endl;
                        	cout << "Your percentage of multiplication at Level 2 is : " << mulPercentageLevelTwo << endl;
                       		cout << "Your percentage of division at Level 2 is : " << divPercentageLevelTwo << endl;

				addPercentageLevelThree = percentage(levelThreeAddRight, levelThreeAddCount);
				subPercentageLevelThree = percentage(levelThreeSubRight, levelThreeSubCount);
				divPercentageLevelThree = percentage(levelThreeDivRight, levelThreeDivCount);
				mulPercentageLevelThree = percentage(levelThreeMulRight, levelThreeMulCount);
				cout << "Your percentage of addition is : " << addPercentageLevelThree << endl;
				cout << "Your percentage of subtraction is : " << subPercentageLevelThree << endl;
				cout << "Your percentage of multiplication is : " << mulPercentageLevelThree << endl;
				cout << "Your percentage of division is : " << divPercentageLevelThree << endl;
                        	cout << "Thanks for playing!"  << endl;

			}
		}
	}
	//Quitting the game at Level 1
	if (choice == '4')
	{
		addPercentage = percentage(addRight, addCount);
		subPercentage = percentage(subRight, subCount);
		mulPercentage = percentage(mulRight, mulCount);
		divPercentage = percentage(divRight, divCount);
		cout << "Your percentage of addition is : " << addPercentage << endl;
		cout << "Your percentage of subtraction is : " << subPercentage << endl;
		cout << "Your percentage of multiplication is : " << mulPercentage << endl;
		cout << "Your percentage of division is : " << divPercentage << endl;
		cout << "Thanks for playing!"  << endl;
	}	
}
//This function helps generate a random number, used to come up with numbers for equations AND to help make a number positive or negative.
int randomNum(int min, int max)
{
        static bool firstCall = true;
        if (firstCall)
        {
                srand(time(0));
                firstCall = false;
        }
        int rNum = random();
        rNum = (rNum % (max-min)) + min;
}
//This function allows a negative number to be in the random number generator, for Level 4.  
int negativeRandomNum(int min, int max)
{
	int number = randomNum(min, max);
	int negative = randomNum(0, 2);
	if (negative == 1)
	{
		number = number * -1;
	}
	return number;
}
//This function helps generate a mathematical sign randomly, if there is some error it will automatically make the sign negative  
char randOp()
{
        char op;
        int r = randomNum(1, 5);
        switch(r)
        {
                case 1:
                        op = '+';
                        break;
                case 2:
                        op = '-';
                        break;
                case 3:
                        op = '*';
                        break;
                case 4:
                        op = '/';
                        break;
		default:
			op = '+';
			break;

        }
        return op;
}
//This function evaluates the equation given the operand and the two operators.  
double evaluate(int op1, int op2, char operand)
{
        int newResult;
        double result;
        if (operand == '+')
       	{
               	result = op1 + op2;
       	}
       	else if (operand == '-')
       	{
               	result = op1 - op2;
       	}
       	else if (operand == '*')
	{
		result = op1 * op2;
	}
	else if (operand == '/' && op2 != 0)
	{
		result = (double) op1 / (double) op2;
        }
	else
	{
		result = -10000;
	}	
        return result;
}
//This program creates an equation using four arrays, one using the first number, one using the second number, one using the sign that the programmer
//would like to use, and then stores the result in a result array.  This function uses random numbers set by a limit of parameters lowerlimit and upperLimit
//After the arrays have been set, each sign used is counted using a switch statement to help computer the percentage of questions the user gets right.

void createEquation(int lowerLimit, int upperLimit, int array1[], int array2[], char array3[], double array4[])
{
        for (int i = 0; i < MAX; i++)
	{       
               	array1[i] = randomNum(lowerLimit, upperLimit);
                array3[i] = randOp();
		if (array3[i] == '/' && lowerLimit == 0)
		{
			array2[i] = randomNum((lowerLimit+1), upperLimit);
		}
		else
		{
			array2[i] = randomNum(lowerLimit, upperLimit);
		}
		array4[i] = evaluate(array1[i], array2[i], array3[i]);
	}

}
//This function is just like the createEquation one except it uses negativeRandomNum, for the purpose of Level 4.
void createNegativeEquation(int min, int max, int array1[], int array2[], char array3[], double array4[])
{
	for (int i = 0; i < MAX; i++)
	{
		array1[i] = negativeRandomNum(min, max);
		array3[i] = randOp();
		if (array3[i] == '/' && min == 0)
		{
			array2[i] = randomNum((min+1), max);
		}
		else
		{
			array2[i] = randomNum(min, max);
		}
		array4[i] = evaluate (array1[i], array2[i], array3[i]);
	}
}

//This program determines the percentage, used later on for the percentage statistics at the end of the game.
double percentage(int num1, int num2)
{
        double correct = (double)num1 / num2;
        correct = correct * 100;
}
//
//This program takes the four operands and keeps count of what sign they are in order to track the percentages for each type of problem. (I.E. Addition, Subtraction, Multiplication, and Division).
void signCount(int &a, int &b, int &c, int &d, char sign)
{
        switch(sign)
                {
                        case '+':
                                 a++;
                                 break;
                        case '-':
                                b++;
                                break;
                        case '*':
                                c++;
                                break;
                        case '/':
                                d++;
                                break;
                }
}

//This program tells if 4 numbers and 2 characters are the same or different
bool isRepeat(int a, int b, int c, int d, char e, char f)
{
        bool repeat;
        if (a == b && c == d && e == f)
        {
                repeat = true;
        }
        else
        {
                repeat = false;
        }
                                                       
}

//This program checks to see if the position in the array has already been made.  
bool repeatCheck(int position, int array1[], int array2[], char array3[])
{
        bool isACopy;
        for (int i = position; i <= 0; i++)
        {
                if (isRepeat(array1[position], array1[i], array2[position], array2[i], array3[position], array3[i])== true)
                {
                        isACopy = true;
                }

        }
        return repeatCheck;
}


