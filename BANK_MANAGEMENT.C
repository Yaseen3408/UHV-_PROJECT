#include <stdio.h>
#include <string.h>

// Structure to represent a bank account
struct BankAccount {
    int accountNumber;
    char accountHolder[100];
    float balance;
};

// Function to create a new account
void createAccount(struct BankAccount accounts[], int *numAccounts) {
    struct BankAccount newAccount;
    
    printf("Enter account number: ");
    scanf("%d", &newAccount.accountNumber);
    printf("Enter account holder's name: ");
    scanf(" %[^\n]s", newAccount.accountHolder);
    printf("Enter initial balance: ");
    scanf("%f", &newAccount.balance);
    
    accounts[*numAccounts] = newAccount;
    (*numAccounts)++;
    
    printf("Account created successfully.\n");
}

// Function to deposit funds into an account
void deposit(struct BankAccount accounts[], int numAccounts) {
    int accNumber;
    float amount;
    
    printf("Enter account number: ");
    scanf("%d", &accNumber);
    
    for (int i = 0; i < numAccounts; i++) {
        if (accounts[i].accountNumber == accNumber) {
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);
            
            accounts[i].balance += amount;
            printf("Deposit successful. New balance: %.2f\n", accounts[i].balance);
            return;
        }
    }
    
    printf("Account not found.\n");
}

// Function to display account information
void displayAccount(struct BankAccount account) {
    printf("Account Number: %d\n", account.accountNumber);
    printf("Account Holder: %s\n", account.accountHolder);
    printf("Balance: %.2f\n", account.balance);
}

int main() {
    struct BankAccount accounts[100]; // Maximum of 100 accounts
    int numAccounts = 0;
    int choice;

    do {
        printf("\nBank Management System\n");
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Display Account\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount(accounts, &numAccounts);
                break;
            case 2:
                deposit(accounts, numAccounts);
                break;
            case 3:
                int accNumber;
                printf("Enter account number: ");
                scanf("%d", &accNumber);

                for (int i = 0; i < numAccounts; i++) {
                    if (accounts[i].accountNumber == accNumber) {
                        displayAccount(accounts[i]);
                        break;
                    }
                }
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
