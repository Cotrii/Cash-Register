/* 
* Description: Program that acts as a cash register that peforms transactions and generate a report of all the transactions in the program run
* Name : Cortez, Carlo Miguel W.  ID No. : 12043079   Section: S22
* Last modified: January 31, 2021
* Version : 2.00
*/

#include <stdio.h>
#include <stdlib.h>

/*To avoid implicit declaration and other errors that might ruin the program run (code in bottom for easier access with main) */
int action(int a, int totalQuantity[]);

/*Function displays text in main menu - also serves as the input for the Main Menu Options*/
void displayMainMenu(int totalQuantity[]){
    printf("\nHi, welcome to the Cash Register!\n \nSelect an option below:\n\n[1] New Transaction\n[2] Generate Report \n[3] Exit the program\n");
    int nMainOption; 

    /* Asks user for input and loops if the user inputs a number less than 1 or greater than 3 */
    while (nMainOption < 1 || nMainOption > 3){
        printf("\nInput: ");
        scanf("%d", &nMainOption);
        fflush(stdin);
    }

    action(nMainOption, totalQuantity); /*If number is between 1 to 3, the user will be directed to the action function */
}

/*Displays list of items for newTransaction*/
void displayItems(){
    printf("\n[1] Potato \n[2] Apple \n[3] Orange \n[4] Banana \n[5] Popcorn \n[6] Bottled Water\n[7] Cola \n[8] Cancel\n");
}

/*Function for New Transaction Menu - Shows a menu of the items that can be purchased and the whole process for each transaction*/
void newTransaction(int totalQuantity[])
{
    system("cls");
    /*nTotal for Total amount to pay, nTransactOption, checkOut = to know if user has chosen [2] or [3] to stop loop, nAmount = money of user, isPaid = to know if user has completed purchase */ 
    int nTotal = 0, nTransactOption = 0, checkOut = 1, nAmount = 0, isPaid = 0;
    int number; /*Item chosen */
    int quantity[7]={0, 0, 0, 0, 0, 0, 0}; /*Checks quantity for each item initialized from 0*/
    int nPrice[7]={50, 35, 40, 25, 120, 20, 45}; /*price for each item */

    /*Loops until checkout is equal to 0*/
    while (checkOut > 0)
    {
        /*Current cart starts with 0 quantity*/
        printf("\nCurrent Cart\n");

        /*Starts with 0 but updates when user has chosen an item */
        printf("\nPotato     \t50.00  x %d\n", quantity[0]); 
        printf("Apple        \t35.00  x %d\n", quantity[1]);
        printf("Orange       \t40.00  x %d\n", quantity[2]); 
        printf("Banana       \t25.00  x %d\n", quantity[3]);
        printf("Popcorn      \t120.00 x %d\n", quantity[4]); 
        printf("Bottled Water\t20.00  x %d\n", quantity[5]);
        printf("Cola         \t45.00  x %d\n", quantity[6]); 
        printf("--------------------------\n");
        printf("Total        \tP %.2f\n", (float) nTotal);
        printf("\n[1] Purchase Items\n[2] Check Out\n[3] Cancel Transaction\n");

        /*Checks what user has input from 1-3 */
        while (nTransactOption < 1 || nTransactOption > 3){
            printf("\nInput: ");
            scanf("%d", &nTransactOption);
            fflush(stdin);
        }

        if (nTransactOption == 1)
        { /* Purchasing Items */
            system("cls");
            displayItems(); /*Displays items*/
            nTransactOption = 0; /*Resets the variable back to 0 to be ready for another purchase later*/
            printf("\nPurchase which item? "); 
            number = 0;
            scanf("%d", &number);
            fflush(stdin);
            switch(number) /*Goes for the inputted valid number by the user*/
            { 
                case 1: quantity[0] = 0;
                        printf("Buying Potato!\n\n");
                        while (quantity[0] <= 0){
                            printf("Enter quantity? ");
                            scanf("%d", &quantity[0]); 
                            fflush(stdin);
                        }
                        if (quantity[0] > 0)
                            printf("\n%d Potatoes purchased!\n", quantity[0]);
                        break;
                case 2: quantity[1] = 0;
                        printf("Buying Apple!\n\n");
                        while (quantity[1] <= 0){
                            printf("Enter quantity? ");
                            scanf("%d", &quantity[1]); 
                            fflush(stdin);
                        }
                        if (quantity[1] > 0)
                            printf("\n%d Apples purchased!\n", quantity[1]);
                        break;
                case 3: quantity[2] = 0;
                        printf("Buying Orange!\n\n");
                        while (quantity[2] <= 0){
                            printf("Enter quantity? ");
                            scanf("%d", &quantity[2]); 
                            fflush(stdin);
                        }
                        if (quantity[2] > 0)
                            printf("\n%d Oranges purchased!\n", quantity[2]);
                        break;
                case 4: quantity[3] = 0;
                        printf("Buying Banana!\n\n");
                        while (quantity[3] <= 0){
                            printf("Enter quantity? ");
                            scanf("%d", &quantity[3]); 
                            fflush(stdin);
                        }
                        if (quantity[3] > 0)
                            printf("\n%d Bananas purchased!\n", quantity[3]);
                        break;
                case 5: quantity[4] = 0;
                        printf("Buying Popcorn!\n\n");
                        while (quantity[4] <= 0){
                            printf("Enter quantity? ");
                            scanf("%d", &quantity[4]); 
                            fflush(stdin);
                        }
                        if (quantity[4] > 0)
                            printf("\n%d Popcorn purchased!\n", quantity[4]);
                        break;
                case 6: quantity[5] = 0;
                        printf("Buying Bottled Water!\n\n");
                        while (quantity[5] <= 0){
                            printf("Enter quantity? ");
                            scanf("%d", &quantity[5]); 
                            fflush(stdin);
                        }
                        if (quantity[5] > 0)
                            printf("\n%d Bottled Water purchased!\n", quantity[5]);
                        break;
                case 7: quantity[6] = 0;
                        printf("Buying Cola!\n\n");
                        while (quantity[6] <= 0){
                            printf("Enter quantity? ");
                            scanf("%d", &quantity[6]); 
                            fflush(stdin);
                        }
                        if (quantity[6] <= 0)
                            printf("\n%d Cola purchased!\n", quantity[6]);
                        break;
                case 8: printf("Cancel\n");
                        break;
                default: 
                    system("cls");
                    printf("\nInvalid\n\n");
                    break;
            }
            /*If number is greater than/equal to 1 && number is less than 8, get the quantity[number] multiplied to price[number] and add the product to nTotal*/
            if (number >= 1 && number < 8) {
                int i;
                nTotal = 0;
                for (i = 0; i < 7; i++) {
                    nTotal += quantity[i] * nPrice[i];
                }
            }
            
        }
        else if(nTransactOption == 2) /* Check Out part where the user will pay for the items bought*/
        { 
            checkOut = 0;
            system("cls");
            /*If isPaid = 0 meaning not yet paid, isPaid = 1 transaction is completed */ 
            while (isPaid == 0)
            {
                printf("\nCheck Out\n");
                if (quantity[0] > 0) /*Printing out the check out list no problems*/
                    printf("\nPotato        \t50.00 x %d = %.2f\n", quantity[0], (float) quantity[0] * nPrice[0]);
                if (quantity[1] > 0)
                    printf("Apple         \t35.00 x %d = %.2f\n", quantity[1], (float) quantity[1] * nPrice[1]);
                if (quantity[2] > 0)
                    printf("Orange        \t40.00 x %d = %.2f\n", quantity[2], (float) quantity[2] * nPrice[2]);
                if (quantity[3] > 0)
                    printf("Banana        \t25.00 x %d = %.2f\n", quantity[3], (float) quantity[3] * nPrice[3]);
                if (quantity[4] > 0)
                    printf("Popcorn       \t120.00 x %d = %.2f\n", quantity[4], (float) quantity[4] * nPrice[4]);
                if (quantity[5] > 0)
                    printf("Bottled Water\t20.00 x %d = %.2f\n", quantity[5], (float)quantity[5] * nPrice[5]);
                if (quantity[6] > 0)
                    printf("Cola         \t45.00 x %d = %.2f\n", quantity[6], (float) quantity[6] * nPrice[6]);
                printf("----------------------------------------\n");
                printf("TOTAL \t P %.2f\n", (float) nTotal);
                printf("\nEnter amount: ");
                scanf("%d", &nAmount);
                fflush(stdin);

                if (nAmount >= nTotal)
                { /*Printing out the official receipt */
                    system("cls");
                    printf("\nOfficial Receipt\n\n");
                    if (quantity[0] > 0){
                        printf("\nPotato        \t50.00 x %d = %.2f\n", quantity[0], (float) quantity[0] * nPrice[0]);
                    /*Passing all quantity for each item*/
                        totalQuantity[0] += quantity[0];
                    }
                    if (quantity[1] > 0){
                        printf("Apple         \t35.00 x %d = %.2f\n", quantity[1], (float) quantity[1] * nPrice[1]);
                        totalQuantity[1] += quantity[1];
                    }
                    if (quantity[2] > 0){
                        printf("Orange        \t40.00 x %d = %.2f\n", quantity[2], (float) quantity[2] * nPrice[2]);
                        totalQuantity[2] += quantity[2];
                    }
                    if (quantity[3] > 0){
                        printf("Banana        \t25.00 x %d = %.2f\n", quantity[3], (float) quantity[3] * nPrice[3]);
                        totalQuantity[3] += quantity[3];
                    }
                    if (quantity[4] > 0){
                        printf("Popcorn       \t120.00 x %d = %.2f\n", quantity[4], (float) quantity[4] * nPrice[4]);
                        totalQuantity[4] += quantity[4];
                    }
                    if (quantity[5] > 0){
                        printf("Bottled Water\t20.00 x %d = %.2f\n", quantity[5], (float) quantity[5] * nPrice[5]);
                        totalQuantity[5] += quantity[5];
                    }
                    if (quantity[6] > 0){
                        printf("Cola         \t45.00 x %d = %.2f\n", quantity[6], (float) quantity[6] * nPrice[6]);
                        totalQuantity[6] += quantity[6];
                    }
                    printf("----------------------------------------\n");
                    printf("TOTAL    \t P %.2f", (float) nTotal);
                    printf("\nCASH TENDERED \t P %.2f\n", (float) nAmount);
                    printf("CHANGE   \t P %.2f\n", (float) nAmount - nTotal);
                    printf("\nThank you for shopping!\n\n");
                    isPaid = 1;
                    displayMainMenu(totalQuantity);
                }
                else {
                    system("cls"); printf("\n\n\nInvalid. Please enter amount again\n"); 
                }
            }
        }
        else if(nTransactOption == 3)
        { /* Cancel transaction */
            checkOut = 0;
            system("cls");
            displayMainMenu(totalQuantity);
        }
    }
}

int generateReport(int totalQuantity[]) /*Generates report of all the transactions made in the program run*/
{
    system("cls");
    printf("Daily Report\n\n");
    int nTotalPotato, nTotalApple, nTotalOrange, nTotalBanana, nTotalPopcorn, nTotalBottledWater, nTotalCola, nIncome, nReturnToMenu;
    /* Gets the total for each with their quantity and price*/
    nTotalPotato = totalQuantity[0] * 50;
    nTotalApple = totalQuantity[1] * 35;
    nTotalOrange = totalQuantity[2] * 40;
    nTotalBanana = totalQuantity[3] * 25;
    nTotalPopcorn = totalQuantity[4] * 120;
    nTotalBottledWater = totalQuantity[5] * 20;
    nTotalCola = totalQuantity[6] * 45;
    
    /*Prints total for each item*/
    if (totalQuantity[0] > 0) 
        printf("Potato       \t 50.00 x %d = %.2f\n", totalQuantity[0], (float) nTotalPotato);
    if (totalQuantity[1] > 0)
        printf("Apple        \t 35.00 x %d = %.2f\n", totalQuantity[1], (float) nTotalApple);
    if (totalQuantity[2] > 0)
        printf("Orange       \t 40.00 x %d = %.2f\n", totalQuantity[2], (float) nTotalOrange);
    if (totalQuantity[3] > 0)
        printf("Banana       \t 25.00 x %d = %.2f\n", totalQuantity[3], (float) nTotalBanana);
    if (totalQuantity[4] > 0)
        printf("Popcorn      \t 120.00 x %d = %.2f\n", totalQuantity[4], (float) nTotalPopcorn);
    if (totalQuantity[5] > 0)
        printf("Bottled Water\t 20.00 x %d = %.2f\n", totalQuantity[5], (float) nTotalBottledWater);
    if (totalQuantity[6] > 0)
        printf("Cola         \t 45.00 x %d = %.2f\n", totalQuantity[6], (float) nTotalCola);
    nIncome = nTotalPotato + nTotalApple + nTotalOrange + nTotalBanana + nTotalPopcorn + nTotalBottledWater + nTotalCola;
    printf("----------------------------------------\n");
    printf("Total \t \t P %.2f\n", (float) nIncome);
    printf("\n[1] Return to the main menu\n");

    while (nReturnToMenu != 1){
        scanf("%d", &nReturnToMenu);
        fflush(stdin);
        if (nReturnToMenu != 1)
            printf("\nInvalid. Press 1\n");
    }

    if (nReturnToMenu == 1){
        system("cls");
        displayMainMenu(totalQuantity);
    }  
}

/*Main Menu Selection - Goes to the inputted option from 1-3*/
int action(int a, int totalQuantity[]){
    switch(a){
        case 1: newTransaction(totalQuantity); 
                break;
        case 2: generateReport(totalQuantity); 
                break;
        case 3: /* Exits the program */
                system("cls"); 
                break;
    }
}
 
int main(){
    int totalQuantity[7] = {0, 0, 0, 0, 0, 0, 0};
    displayMainMenu(totalQuantity);
    return 0;
}
