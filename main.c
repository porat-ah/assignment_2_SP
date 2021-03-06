#include "myBank.h"
//#define debug
float roundf(float val);
void help();
int check_amount(int bool);
int check_acc_number(int bool, int number,int situation);
int main()
{
    float amount;
    int account_number;
    int bool;
    int interest_rate;
    init();
    char input = 'H';
    while (input != 'E')
    {
        help();
        scanf(" %c", &input);
        switch (input)
        {
        case 'E':
            shut_down();
            break;
        case 'O':
            printf("Please enter amount for deposit: ");
            bool = scanf(" %f", &amount);
            if (!check_amount(bool))
            {
                break;
            }
            amount = roundf(amount * 100) / 100;
            open_new_acc(amount);
            break;
        case 'B':
            printf("Please enter account number: ");
            bool = scanf(" %d", &account_number);
            if (!check_acc_number(bool, account_number,0))
            {
                break;
            }
            check_balance(account_number);
            break;
        case 'D':
            printf("Please enter account number: ");
            bool = scanf(" %d", &account_number);
            if (!check_acc_number(bool, account_number,1))
            {
                break;
            }
            printf("Please enter the amount to deposit: ");
            bool = scanf(" %f", &amount);
            if (!check_amount(bool))
            {
                break;
            }
            amount = roundf(amount * 100) / 100;
            deposit(account_number, amount);
            break;
        case 'W':
            printf("Please enter account number: ");
            bool = scanf(" %d", &account_number);
            if (!check_acc_number(bool, account_number,2))
            {
                break;
            }
            printf("Please enter amount to withdraw: ");
            bool = scanf(" %f", &amount);
            if (!check_amount(bool))
            {
                break;
            }
            amount = roundf(amount * 100) / 100;
            withdrawal(account_number, amount);
            break;
        case 'C':
            printf("Please enter account number: ");
            bool = scanf(" %d", &account_number);
            if (!check_acc_number(bool, account_number,3))
            {
                break;
            }
            close_acc(account_number);
            break;
        case 'P':
            print();
            break;
        case 'I':
            printf("Please enter interest rate: ");
            bool = scanf(" %d", &interest_rate);
            if (!bool)
            {
                printf("Failed to read the interest rate\n");
                break;
            }
            amount = (float) interest_rate;
            amount = roundf(amount) / 100;
            add_intrest(amount);
            break;
        default:
            printf("Invalid transaction type\n");
            break;
        }
        #ifdef debug
            printf("input : %c\n",input);
            printf("account_number : %d\n",account_number);
            printf("amount : %f\n",amount);
            printf("\n\n");
            account_number = 0;
            amount = 0;
        #endif

    }
    return 0;
}
//* Inits the 50 bank accounts data base .
void init()
{
    for (int i = 0; i < 50; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            accounts_list[i][j] = 0;
        }
    }
}
void help()
{
    printf("\n");
    printf("Please choose a transaction type:\nO-Open Account\nB-Balance Inquiry\nD-Deposit\nW-Withdrawal\nC-Close Account\nI-Interest\nP-Print\nE-Exit\n");
}
float roundf(float val)
{
    int temp = (int)val;
    val = temp * 1.0;
    return val;
}
int check_amount(int bool)
{
    if (!bool)
    {
        printf("Failed to read the amount\n");
    }
    return bool;
}
int check_acc_number(int bool, int number,int situation)
{
    if (!bool)
    {
        printf("Failed to read the account number\n");
        return 0;
    }
    bool = check_open(number,situation);
    return bool;
}
