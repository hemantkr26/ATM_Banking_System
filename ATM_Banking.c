#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

// Function to display transaction menu
void displayMenu()
{
    printf("\n\t\t\t************* Available Transactions ************");
    printf("\n\n\t\t1. Withdrawal");
    printf("\n\t\t2. Deposit");
    printf("\n\t\t3. Check Balance");
    printf("\n\n\t4. Please select an option: ");
}

int main()
{
    int correctPin = 9886;
    int chosenOption, enteredPin, attempts = 0, withdrawalAmount = 1;

    float accountBalance = 25000;

    int continueTransaction = 1;

    time_t currentTime;
    time(&currentTime);

    printf("\n");
    printf("\t\t\t\t\t       %s", ctime(&currentTime)); // Display current time and date
    printf("\n\t\t\t****************** WELCOME TO CODE WITH CURIOUS ATM *******************");

    while (correctPin != enteredPin)
    {
        printf("\nPlease enter your PIN: ");
        scanf("%d", &enteredPin);

        if (enteredPin != correctPin)
        {
            Beep(500, 450);
            printf("Invalid PIN! ");
        }

        attempts++;

        if (attempts == 3 && correctPin != enteredPin)
        {
            printf("\nMaximum attempts reached. Exiting...");
            exit(0);
        }
    }

    while (continueTransaction != 0)
    {
        displayMenu();
        scanf("%d", &chosenOption);

        switch (chosenOption)
        {
        case 1:
            printf("\n\t\tEnter the withdrawal amount: ");
            scanf("%d", &withdrawalAmount);

            if (accountBalance < withdrawalAmount)
            {
                printf("\n\t Sorry, insufficient balance");
                withdrawalAmount = 1;
                break;
            }
            else
            {
                accountBalance -= withdrawalAmount;
                printf("\n\t\tYou have withdrawn Rs. %d. Your new balance is %.2f", withdrawalAmount, accountBalance);
                withdrawalAmount = 1;
                break;
            }

        case 2:
            printf("\n\t\tPlease enter the deposit amount: ");
            scanf("%d", &withdrawalAmount);

            accountBalance += withdrawalAmount;
            printf("\n\t\tYou have deposited Rs. %d. Your new balance is %.2f", withdrawalAmount, accountBalance);
            printf("\n\t\t****************** Thank you for banking with Code with Curious ******************");
            withdrawalAmount = 1;
            break;

        case 3:
            printf("\n\t\tYour balance is Rs. %.2f", accountBalance);
            break;

        default:
            Beep(500, 450);
            printf("\n\t\tInvalid option!");
        }

        printf("\n\t\tDo you wish to perform another transaction? Press 1 for Yes, 0 for No: ");
        scanf("%d", &continueTransaction);
    }

    printf("\n\t\tThank you for using Code with Curious ATM! Have a great day!\n");

    return 0;
}