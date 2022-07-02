    #include <stdio.h>
    #include <conio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <windows.h>

    // Develop a project to implement a simple bus reservation system where the user can perform tasks like insert bus information, reserve bus seat, show reservation information and show information regarding the buses available. For performing all these operations identify the proper data structure and analyse their time complexity

    #define MAX_SEAT 50
    #define MAX_NAME 50
    #define BUS_NO 5

    struct Details
    {
        char firstname[MAX_NAME];
        char lastname[MAX_NAME];
        char mobNo[10];
        int Booked;

    } Bus[BUS_NO][MAX_SEAT];

    void NewBooking(struct Details Buses[BUS_NO][MAX_SEAT], int seatNumber, int busNumber);
    void SeatEnquiry(struct Details Buses[BUS_NO][MAX_SEAT], int busNumber);
    void SeatInformation(struct Details Buses[BUS_NO][MAX_SEAT], int seatNumber, int busNumber);
    void CancelSeat(struct Details Buses[BUS_NO][MAX_SEAT], int seatNumber, int busNumber);

    // Function to check if mobile number is valid or not.
    int check_mobile(char str[])
    {
        if (strlen(str) != 10)
        {
            return 0;
        }
        else
        {
            int i;
            for (i = 0; i < 10; i++)
            {
                if (str[i] < '0' || str[i] > '9')
                {
                    return 0;
                }
            }
            return 1;
        }
    }
    // Function to check if name is valid or not.
    int check_name(char *str)
    {
        int i;
        for (i = 0; i < strlen(str); i++)
        {
            if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
            {
                continue;
            }
            else
                return 0;
        }
        return 1;
    }

    void NewBooking(struct Details Buses[BUS_NO][MAX_SEAT], int seatNumber, int busNumber)
    {
        int i, seat;
        system("cls");

        if (Buses[busNumber][seatNumber].Booked == 1)
        {
            system("cls");

            printf("This seat is already booked by %s %s\n", Buses[busNumber][seatNumber].firstname, Buses[busNumber][seatNumber].lastname);
            printf("Do you want to book another seat (Y/N): ");
            char ano;
            scanf("%s", &ano);
            if (ano == 'Y' || ano == 'y')
            {
                printf("Enter Seat Number : ");
                scanf("%d", &seat);
                NewBooking(Bus, seat, busNumber);
            }
        }
        else
        {
            Buses[busNumber][seatNumber].Booked = 1;
            printf("Enter your first name : ");

            while (1)
            {
                int valid_first_name;
                scanf("%s", &Buses[busNumber][seatNumber].firstname);
                valid_first_name = check_name(Buses[busNumber][seatNumber].firstname);
                if (valid_first_name == 1)
                {
                    break;
                }
                else
                {
                    printf("First name is invalid!!\n\nPlease enter a valid first name: ");
                }
            }

            printf("Enter your last name : ");
            while (1)
            {
                int valid_last_name;
                scanf("%s", &Buses[busNumber][seatNumber].lastname);
                valid_last_name = check_name(Buses[busNumber][seatNumber].lastname);
                if (valid_last_name == 1)
                {
                    break;
                }
                else
                {
                    printf("Last name is invalid!!\n\nPlease enter a valid last name: ");
                }
            }

            printf("Enter Passenger Mobile's Number : ");

            while (1)
            {
                int valid_mobile;
                scanf("%s", &Buses[busNumber][seatNumber].mobNo);
                valid_mobile = check_mobile(Buses[busNumber][seatNumber].mobNo);
                if (valid_mobile == 1)
                {
                    break;
                }
                else
                    printf("Invalid Mobile Number!!\n\nPlease enter a valid Mobile number: ");
            }

            system("cls");

            printf("\nYour ticket has been successfully booked... \n****** Happy Journey ******\n");
        }
    }

    void SeatEnquiry(struct Details Buses[BUS_NO][MAX_SEAT], int busNumber)
    {
        int i;
        system("cls");

        printf("Vacant Seats: \n");

        for (i = 0; i < 50; i++)
        {
            if (Buses[busNumber][i].Booked != 1)
            {
                printf("%d  ", i + 1);
            }
        }

        printf("\n");
        printf("Already Booked Seats: \n");
        for (i = 0; i < 50; i++)
        {
            if (Buses[busNumber][i].Booked == 1)
            {
                printf("%d  ", i + 1);
            }
        }
    }

    void SeatInformation(struct Details Buses[BUS_NO][MAX_SEAT], int seatNumber, int busNumber)
    {
        system("cls");
        if (Buses[busNumber][seatNumber].Booked == 1)
        {

            printf("Entered seat number %d of bus_%d is BOOKED by %s %s", seatNumber + 1, busNumber + 1, Buses[busNumber][seatNumber].firstname, Buses[busNumber][seatNumber].lastname);
        }
        else
        {
            printf("Entered seat number: %d of bus_%d is available!!!\n", seatNumber + 1, busNumber + 1);
            printf("Do you want to book ? (Y/N): ");
            char another;
            scanf("%s", &another);
            if (another == 'Y' || another == 'y')
            {
                NewBooking(Bus, seatNumber, busNumber);
            }
        }
    }

    void CancelSeat(struct Details Buses[BUS_NO][MAX_SEAT], int seatNumber, int busNumber)
    {
        if (Buses[busNumber][seatNumber].Booked != 1)
        {
            system("cls");
            printf("This seat is not booked yet.!!!");
        }
        else
        {
            Buses[busNumber][seatNumber].Booked = 0;
            Buses[busNumber][seatNumber].firstname == NULL;
            Buses[busNumber][seatNumber].lastname == NULL;
            system("cls");
            printf("***** Ticket Cancellation Successfull ****\n");
            printf("*** Thank You, Visit Again *** \n");
        }
    }

    // color codes:
    // 0 = Black       8 = Gray
    // 1 = Blue        9 = Light Blue
    // 2 = Green       A = Light Green
    // 3 = Aqua        B = Light Aqua
    // 4 = Red         C = Light Red
    // 5 = Purple      D = Light Purple
    // 6 = Yellow      E = Light Yellow
    // 7 = White       F = Bright White

    int main()
    {
        int seatNumber, busNumber;
        int choice;
        system("COLOR B0");
        system("cls");
        while (choice != 5)
        {
            printf("\n\n*** Welcome to Bus reservation system ***");
            printf("\n\n1. New Booking \n2. Knowing vacancies \n3. Ticket Information \n4. Cancel your ticket \n5. Exit");
            printf("\n\nWhat do you want?? Choose (1-5): ");
            scanf("%d", &choice);

            switch (choice)
            {
            case 1:
                printf("For New Registration...\n");
                printf("Choose Bus Number :\n1. Bus_1\t2. Bus_2\t3. Bus_3\t4. Bus_4\t5. Bus_5\n");
                scanf("%d", &busNumber);
                busNumber = busNumber - 1;
                printf("Enter Seat Number (1-50): ");
                scanf("%d", &seatNumber);
                seatNumber = seatNumber - 1;
                NewBooking(Bus, seatNumber, busNumber);
                break;

            case 2:
                printf("Choose Bus Number from above :\n1. Bus_1\t2. Bus_2\t3. Bus_3\t4. Bus_4\t5. Bus_5\n");
                scanf("%d", &busNumber);
                busNumber = busNumber - 1;
                SeatEnquiry(Bus, busNumber);
                break;

            case 3:
                printf("For seat Inquiry...\n");
                printf("Choose Bus Number from above :\n1. Bus_1\t2. Bus_2\t3. Bus_3\t4. Bus_4\t5. Bus_5\n");
                scanf("%d", &busNumber);
                busNumber = busNumber - 1;
                printf("Enter Seat Number (1-50): ");
                scanf("%d", &seatNumber);
                seatNumber = seatNumber - 1;
                SeatInformation(Bus, seatNumber, busNumber);
                break;

            case 4:
                printf("For cancelling reservation...\n");
                printf("Enter bus number :\n1. Bus_1\t2. Bus_2\t3. Bus_3\t4. Bus_4\t5. Bus_5\n");
                scanf("%d", &busNumber);
                busNumber = busNumber - 1;

                printf("Enter seatNumber (1-50): ");
                scanf("%d", &seatNumber);
                seatNumber = seatNumber - 1;
                CancelSeat(Bus, seatNumber, busNumber);
                break;

            default:
                printf("Software closed by User.");
                break;
            }
        }
        return 0;
    }
