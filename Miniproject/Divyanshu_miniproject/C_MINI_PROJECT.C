#include <stdio.h>
#include <string.h>
#include <conio.h>    // for getch()
#include <stdlib.h>   // for rand(), srand()
#include <time.h>     // for time()

#define MAX_ATTEMPTS 3

// Hash function (demo purpose)
unsigned long hashPassword(char password[])
{
    unsigned long hash = 5381;
    int c;

    for (int i = 0; password[i] != '\0'; i++)
    {
        c = password[i];
        hash = ((hash << 5) + hash) + c;
    }
    return hash;
}

// Masked password input
void getMaskedPassword(char password[])
{
    char ch;
    int i = 0;

    while (1)
    {
        ch = getch();

        if (ch == 13)   // Enter key
        {
            password[i] = '\0';
            break;
        }
        else if (ch == 8 && i > 0)   // Backspace
        {
            i--;
            printf("\b \b");
        }
        else
        {
            password[i++] = ch;
            printf("*");
        }
    }
}

int main()
{
    char storedUsername[20] = "Divyanshu10487";
    char registeredMobile[] = "9876543210";
    unsigned long storedPasswordHash = hashPassword("secure10487");

    char username[20], password[20], mobile[15];
    int attempts;
    int loggedIn = 0;   // flag

    while (!loggedIn)
    {
        attempts = 0;

        printf("\n====================================\n");
        printf("   Secure Lab Credential Manager\n");
        printf("====================================\n");

        // LOGIN ATTEMPTS
        while (attempts < MAX_ATTEMPTS)
        {
            printf("Username: ");
            scanf("%s", username);

            printf("Password: ");
            getMaskedPassword(password);
            printf("\n");

            if (strcmp(username, storedUsername) == 0 &&
                hashPassword(password) == storedPasswordHash)
            {
                printf("\n Access Granted!\n");
                printf("Welcome to the secure lab system.\n");
                loggedIn = 1;
                break;
            }
            else
            {
                attempts++;
                printf(" Invalid credentials.\n");
                printf("Attempts left: %d\n\n", MAX_ATTEMPTS - attempts);
            }
        }

        // IF LOCKED
        if (!loggedIn)
        {
            printf(" System Locked!\n");

            char choice;
            printf("Forgot Password? Press Y to continue or N to exit: ");
            scanf(" %c", &choice);

            if (choice == 'Y' || choice == 'y')
            {
                printf("Enter registered mobile number: ");
                scanf("%s", mobile);

                if (strcmp(mobile, registeredMobile) == 0)
                {
                    srand(time(0));
                    int otp = rand() % 9000 + 1000;

                    printf("\n OTP sent successfully!\n");
                    printf("(Demo OTP: %d)\n", otp);

                    int enteredOtp;
                    printf("Enter OTP: ");
                    scanf("%d", &enteredOtp);

                    if (enteredOtp == otp)
                    {
                        printf("\nOTP verified successfully!\n");
                        printf("Enter new password: ");
                        getMaskedPassword(password);
                        printf("\n");

                        storedPasswordHash = hashPassword(password);
                        printf(" Password reset successful!\n");
                        printf("Please login again.\n");
                    }
                    else
                    {
                        printf(" Incorrect OTP.\n");
                        break;
                    }
                }
                else
                {
                    printf(" Mobile number not registered.\n");
                    break;
                }
            }
            else
            {
                printf("System exiting...\n");
                break;
            }
        }
    }

    return 0;
}
