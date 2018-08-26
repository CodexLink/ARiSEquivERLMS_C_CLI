#include <stdio.h>   // Just Basic Input Output Header File
#include <stdlib.h>  // For SYSTEM Command
#include <conio.h>   // For Getch()
#include <windows.h> // Windows Designed Only Header, This Rips Compatibility.
#include <time.h>    // For Time Display and Such
#include <string.h>  // String Handling for Usage of Structure and Database
#define VERSION_NUMBER "2259-08102018-BETA"
#define PRODUCT_NAME "Team LM | Enrollment System for TiP Engineering and Architecture | C CLI Runtime"
#define FUNCTION_UNFINISHED 1362565
#define DATABASE_NOT_FOUND 40
#define FUNCTION_STEP1 "Team LM | Enrollment System for TiP Engineering and Architecture | C CLI Runtime \xAF [1st | 2nd | \xDD [3rd \xAF Subject Enrollment Selection] | 4th | 5th | Confirm | End]"
#define FUNCTION_STEP2 "Team LM | Enrollment System for TiP Engineering and Architecture | C CLI Runtime \xAF [1st | 2nd | \xDD [3rd \xAF Subject Enrollment Selection] | 4th | 5th | Confirm | End]"
#define FUNCTION_STEP3 "Team LM | Enrollment System for TiP Engineering and Architecture | C CLI Runtime \xAF [1st | 2nd | \xDD [3rd \xAF Subject Enrollment Selection] | 4th | 5th | Confirm | End]"
#define FUNCTION_STEP4 "Team LM | Enrollment System for TiP Engineering and Architecture | C CLI Runtime \xAF [1st | 2nd | \xDD [3rd \xAF Subject Enrollment Selection] | 4th | 5th | Confirm | End]"
#define FUNCTION_STEP5 "Team LM | Enrollment System for TiP Engineering and Architecture | C CLI Runtime \xAF [1st | 2nd | \xDD [3rd \xAF Subject Enrollment Selection] | 4th | 5th | Confirm | End]"
#define FUNCTION_STEP6 "Team LM | Enrollment System for TiP Engineering and Architecture | C CLI Runtime \xAF [1st | 2nd | \xDD [3rd \xAF Subject Enrollment Selection] | 4th | 5th | Confirm | End]"
#define FUNCTION_STEP7 "Team LM | Enrollment System for TiP Engineering and Architecture | C CLI Runtime \xAF [1st | 2nd | \xDD [3rd \xAF Subject Enrollment Selection] | 4th | 5th | Confirm | End]"
struct New_StudentRecords
{
    char stdnt_FName[30],
        stdnt_MName[30],
        stdnt_LName[30],
        stdnt_Gender[6],
        stdnt_Birthday[30],
        stdnt_Nationality[30],
        stdnt_SpecialBehavioral[50],
        stdnt_Address[MAX_PATH],
        stdnt_Email[40],
        stdnt_POC_Emergency[30];
    long int stdnt_PhoneNum, stdnt_MobileNum, stdnt_EmerNum;
};
struct Old_StudentRecords
{
    int stdnt_old_StudentIdentity;
    char stdnt_old_Username[20], stdnt_old_Password[32], stdnt_old_UserPersonalName[20];
};

struct Enrollment_InformationReceiver
{
    char *Subject_CodeName[12];
    char *Subject_FullName[12];
    char *Subject_LinearTime[12];
    char *Subject_Units[12];
};
void gotoxy(int x, int y);

int stdnt_DataCheck(struct New_StudentRecords NewData_Receiver);
int Main_Menu();
void Func_OldStdnt_ERLM();
int Func_OldStd_ERLM_Menu(struct Old_StudentRecords OldData);
void Func_NewStdnt_ERLM();
int stdnt_Scholarship_Check();
int Func_NewStdnt_ERLM_Step2();
int Func_NewStdnt_Eng_YearSelect(struct New_StudentRecords NewData_Receiver, char *MainCourse_CodeName_Passer, char *MainCourse_FullName_Passer);
int Func_NewStdnt_Arch_YearSelect(struct New_StudentRecords NewData, char *MainCourse_CodeName_Passer);
void PrintDocument_FinalTranscript();

int Func_NewStdnt_Eng_Subject_Select();

int Func_NewStdnt_Arch_Subject_Select();

int Func_Stdnt_ScholarshipCheck();

void PrintDocument_FinalTranscript();
//NEW
void Func_ERLM_Recheck();
//Architecture Selection Functions for Enrollment
int Stdnt_1stYear_Arch_FirstSem();
int Stdnt_1stYear_Arch_SecondSem();
int Stdnt_2ndYear_Arch_FirstSem();
int Stdnt_2ndYear_Arch_SecondSem();
int Stdnt_3rdYear_Arch_FirstSem();
int Stdnt_3rdYear_Arch_SecondSem();
int Stdnt_4thYear_Arch_FirstSem();
int Stdnt_4thYear_Arch_SecondSem();
int Stdnt_5thYear_Arch_FirstSem();
int Stdnt_5thYear_Arch_SecondSem();
// Civil Engineer Selection Functions for Enrollment
int Stdnt_1stYear_CE_FirstSem();
int Stdnt_1stYear_CE_SecondSem();
int Stdnt_2ndYear_CE_FirstSem();
int Stdnt_2ndYear_CE_SecondSem();
int Stdnt_3rdYear_CE_FirstSem();
int Stdnt_3rdYear_CE_SecondSem();
int Stdnt_4thYear_CE_FirstSem();
int Stdnt_4thYear_CE_SecondSem();
// Computer Engineer Selection Functions for Enrollment
int Stdnt_1stYear_CpE_FirstSem();
int Stdnt_1stYear_CpE_SecondSem();
int Stdnt_2ndYear_CpE_FirstSem();
int Stdnt_2ndYear_CpE_SecondSem();
int Stdnt_3rdYear_CpE_FirstSem();
int Stdnt_3rdYear_CpE_SecondSem();
int Stdnt_4thYear_CpE_FirstSem();
int Stdnt_4thYear_CpE_SecondSem();
// Electrical Engineer Selection Functions for Enrollment
int Stdnt_1stYear_EE_FirstSem();
int Stdnt_1stYear_EE_SecondSem();
int Stdnt_2ndYear_EE_FirstSem();
int Stdnt_2ndYear_EE_SecondSem();
int Stdnt_3rdYear_EE_FirstSem();
int Stdnt_3rdYear_EE_SecondSem();
int Stdnt_4thYear_EE_FirstSem();
int Stdnt_4thYear_EE_SecondSem();
// Electronics Engineer Selection Functions for Enrollment
int Stdnt_1stYear_ECE_FirstSem();
int Stdnt_1stYear_ECE_SecondSem();
int Stdnt_2ndYear_ECE_FirstSem();
int Stdnt_2ndYear_ECE_SecondSem();
int Stdnt_3rdYear_ECE_FirstSem();
int Stdnt_3rdYear_ECE_SecondSem();
int Stdnt_4thYear_ECE_FirstSem();
int Stdnt_4thYear_ECE_SecondSem();
// Environmental and Sanitary Engineer Selection Functions for Enrollment
int Stdnt_1stYear_EnSE_FirstSem();
int Stdnt_1stYear_EnSE_SecondSem();
int Stdnt_2ndYear_EnSE_FirstSem();
int Stdnt_2ndYear_EnSE_SecondSem();
int Stdnt_3rdYear_EnSE_FirstSem();
int Stdnt_3rdYear_EnSE_SecondSem();
int Stdnt_4thYear_EnSE_FirstSem();
int Stdnt_4thYear_EnSE_SecondSem();
// Industrial Engineer Selection Functions for Enrollment
int Stdnt_1stYear_IE_FirstSem();
int Stdnt_1stYear_IE_SecondSem();
int Stdnt_2ndYear_IE_FirstSem();
int Stdnt_2ndYear_IE_SecondSem();
int Stdnt_3rdYear_IE_FirstSem();
int Stdnt_3rdYear_IE_SecondSem();
int Stdnt_4thYear_IE_FirstSem();
int Stdnt_4thYear_IE_SecondSem();
// Mechanical Engineer Selection Functions for Enrollment
int Stdnt_1stYear_ME_FirstSem();
int Stdnt_1stYear_ME_SecondSem();
int Stdnt_2ndYear_ME_FirstSem();
int Stdnt_2ndYear_ME_SecondSem();
int Stdnt_3rdYear_ME_FirstSem();
int Stdnt_3rdYear_ME_SecondSem();
int Stdnt_4thYear_ME_FirstSem();
int Stdnt_4thYear_ME_SecondSem();

int main()
{
    HWND hwnd = GetConsoleWindow();
    ShowWindow(hwnd, SHOW_FULLSCREEN); // Temporarily Commented due to Terminal Shows CMD but Small Font
    Main_Menu();
}
int Main_Menu()
{
    SetConsoleTitle(PRODUCT_NAME);
    system("CLS");
    while (1)
    { // This will loop forever because wtf is 1?
        int Selection_1 = 0;
        system("CLS");
        gotoxy(30, 3);
        printf("\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB");
        gotoxy(30, 4);
        printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t       \xBA");
        gotoxy(30, 5);
        printf("\xBA \xDD Version " VERSION_NUMBER "\t\t\t\t\t\t\t\t\t       \xBA");
        gotoxy(30, 6);
        printf("\xBA \xDD " PRODUCT_NAME "\t\t       \xBA");
        gotoxy(30, 7);
        printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t       \xBA");
        gotoxy(30, 8);
        printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC");
        gotoxy(30, 10);
        printf("\xC9\xCD\xCD \xDD Main Menu \xDD \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB");
        gotoxy(30, 11);
        printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t       \xBA");
        gotoxy(30, 12);
        printf("\xBA [1] \xDD Old Student\t\t\t\t\t\t\t\t\t\t       \xBA");
        gotoxy(30, 13);
        printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t       \xBA");
        gotoxy(30, 14);
        printf("\xBA [2] \xDD New Student\t\t\t\t\t\t\t\t\t\t       \xBA");
        gotoxy(30, 15);
        printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t       \xBA");
        gotoxy(30, 16);
        printf("\xBA [3] \xDD Reprint Enrollment Student Form | Registration Form\t\t\t\t\t       \xBA");
        gotoxy(30, 17);
        printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t       \xBA");
        gotoxy(30, 18);
        printf("\xBA [4] \xDD Manage Enrollment\t\t\t\t\t\t\t\t\t\t       \xBA");
        gotoxy(30, 19);
        printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t       \xBA");
        gotoxy(30, 20);
        printf("\xBA [5] \xDD Exit Application\t\t\t\t\t\t\t\t\t\t       \xBA");
        gotoxy(30, 21);
        printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t       \xBA");
        gotoxy(30, 22);
        printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC");
        gotoxy(30, 24);
        printf("\xC8\xAF Please enter your decision [1 - 5] \xDD ");
        scanf("%i", &Selection_1);
        fflush(stdin); // Use fflush to flush \n because scanf always put \n when user inputs
        switch (Selection_1)
        {
        case 1:
            Func_OldStdnt_ERLM();
            break;
        case 2:
            Func_NewStdnt_ERLM();
            break;
        case 3:
            Func_ERLM_Recheck();
            break;
        case 4:
            gotoxy(30, 26);
            printf("\xC9\xCD\xCD \xDD Warning! \xDD \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB");
            gotoxy(30, 27);
            printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t      \xBA");
            gotoxy(30, 28);
            printf("\xBA Access Denied! Please rerun the program with '/mgr_md' in order to access this function!\t      \xBA");
            gotoxy(30, 29);
            printf("\xBA Press any key in the keyboard to terminate the program...\t\t\t\t\t      \xBA");
            gotoxy(30, 30);
            printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t      \xBA");
            gotoxy(30, 31);
            printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC");
            getch();
            continue;
        case 5:
            SetConsoleTitle("Terminating Enrollment System | LM Enrollment System");
            puts("Terminating Enrollment System...");
            Sleep(1500);
            return EXIT_SUCCESS;
        case 6:
            Stdnt_4thYear_ME_SecondSem();
        default:
            printf("Invalid Choice...");
            Sleep(1500);
            continue;
        }
    }
}
void Func_OldStdnt_ERLM()
{
    struct Old_StudentRecords OldData;
    FILE *FileDatabase_ERLM;
    char datapoint_ERLM[] = "data/2018_LM_Database_Enrollment.dat";
    while (1)
    {
        SetConsoleTitle("LM Enrollment System | Old Student Login");
        printf("Please enter your Username: ");
        scanf("%s", OldData.stdnt_old_Username);
        printf("Please enter your Password: ");
        scanf("%s", OldData.stdnt_old_Password);
        printf("Please enter your Student Number: ");
        scanf("%d", &OldData.stdnt_old_StudentIdentity);
        //if (//strcmp() == 0)
        //)
        //{

        //} else {
        Func_OldStdnt_ERLM();
        //}
        //printf("Hello %s | %d!\n", OldStudent.user_Username, OldStudent.user_StudentIdentity);
        //printf("Also your password is %s\n", OldStudent.user_Password);
        Func_OldStd_ERLM_Menu(OldData);
    }
}
int Func_OldStd_ERLM_Menu(struct Old_StudentRecords OldStudent_Continuation)
{
    FILE *FileDatabase_ERLM;
    char datapoint_ERLM[] = "data/2018_LM_Database_Enrollment.dat";
    FileDatabase_ERLM = fopen(datapoint_ERLM, "rb");
    if (FileDatabase_ERLM == NULL)
    {
        printf("Database Not Found, Terminating Program...");
        printf("Exit Code is %i", DATABASE_NOT_FOUND);
        return DATABASE_NOT_FOUND;
    }
    else
    {
        SetConsoleTitle("LM Enrollment System | Old Student Login");
        char *ENRL_Selection_Eng[4] = {"1st Year College", "2nd Year College", "3rd Year College", "4th Year College"};
        char ENRL_Stats_CurrentLevel, ENRL_Stats_Eligible;
        int Counter_For_Selection = 0;
        printf("-----------------------------");
        printf("Hello and Welcome %c", OldStudent_Continuation.stdnt_old_StudentIdentity);
        printf("-----------------------------");
        Sleep(2000);
        printf("Name %s | Student Number: %i", OldStudent_Continuation.stdnt_old_UserPersonalName, OldStudent_Continuation.stdnt_old_StudentIdentity);
        printf("Your Current Level is %c", ENRL_Stats_CurrentLevel);
        printf("Enrollment Eligibility %c", ENRL_Stats_Eligible);
        for (Counter_For_Selection; Counter_For_Selection < 5; Counter_For_Selection++)
        {
            printf(ENRL_Selection_Eng[Counter_For_Selection]);
        }
        Sleep(999);
        printf("Function Undefined... Press any key to continue...");
        getch();
        return FUNCTION_UNFINISHED;
    }
}

/////////////////////////////////////////////////////////////////////////////////////
void Func_NewStdnt_ERLM()
{
    struct New_StudentRecords NewData;
    //char Confirmation_Exit;

    NewData.stdnt_PhoneNum = 0;
    NewData.stdnt_MobileNum = 0;
    NewData.stdnt_EmerNum = 0;

    system("CLS");
    SetConsoleTitle("New Student: Step 1 | Filling up Information | LM Enrollment System");
    gotoxy(30, 3);
    printf("\xC9\xCD\xCD CURRENT PROGRESS \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
    gotoxy(30, 4);
    printf("\xBA \xDD [1st Step - Input your Personal Information] | 2nd | 3rd | 4th | 5th | Confirm | End\t\t           \xBA\n");
    gotoxy(30, 5);
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    gotoxy(30, 7);
    printf("\xAF Information \xAF Please provide your information to let us identify you as a future student!\n\n");
    gotoxy(30, 8);
    printf("\xDD NOTE \xAF Please input your information accurately!\n\n");
    gotoxy(30, 10);
    printf("\xC9\xCD\xCD IDENTITY INFORMATION \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
    gotoxy(30, 11);
    printf("\xBA [1] First Name \xDD\xAF ");
    fgets(NewData.stdnt_FName, sizeof(NewData.stdnt_FName), stdin);
    gotoxy(30, 13);
    printf("\xBA [2] Middle Name \xDD\xAF ");
    fgets(NewData.stdnt_MName, sizeof(NewData.stdnt_MName), stdin);
    gotoxy(30, 15);
    printf("\xBA [3] Last Name \xDD\xAF ");
    fgets(NewData.stdnt_LName, sizeof(NewData.stdnt_LName), stdin);
    gotoxy(30, 17);
    puts("--- GENERAL INFORMATION ---------------------------------------------------------------------------");
    printf("\n [4] Gender \xDD\xAF ");
    fgets(NewData.stdnt_Gender, sizeof(NewData.stdnt_Gender), stdin);
    printf("\n [5] Birthday \xDD\xAF ");
    fgets(NewData.stdnt_Birthday, sizeof(NewData.stdnt_Birthday), stdin);
    printf("\n [6] Home (Main) Address \xDD\xAF "); //Include City and Village, ZIP CODE
    fgets(NewData.stdnt_Address, sizeof(NewData.stdnt_Address), stdin);
    printf("\n [7] Nationality \xDD\xAF ");
    fgets(NewData.stdnt_Nationality, sizeof(NewData.stdnt_Nationality), stdin);
    printf("\n");
    puts("--- TECHNICAL INFORMATION -------------------------------------------------------------------------");
    printf("\n [8] Mobile Number \xDD\xAF ");
    scanf("%11li", &NewData.stdnt_MobileNum);
    printf("\n [9] Phone Number \xDD\xAF ");
    scanf("%11li", &NewData.stdnt_PhoneNum);
    printf("\n [10] Emergency Number and Emergency Point of Contact (Seperated)\n");
    printf("\n [10.1] Input Emergency Number \xDD\xAF ");
    scanf("%11li", &NewData.stdnt_EmerNum);
    fflush(stdin);
    printf("\n [10.2] Input Name Emergency Point of Contact |> ");
    fgets(NewData.stdnt_POC_Emergency, sizeof(NewData.stdnt_POC_Emergency), stdin);
    printf("\n [11] Personal Email \xDD\xAF ");
    fgets(NewData.stdnt_Email, sizeof(NewData.stdnt_Email), stdin);
    printf("\n [12] Behavioral Issues \xDD\xAF ");
    fgets(NewData.stdnt_SpecialBehavioral, sizeof(NewData.stdnt_SpecialBehavioral), stdin);
    printf("\n");
    puts("--- USER INPUT DONE ------------------------------------------------------------------------------------");
    Sleep(2000);
    stdnt_DataCheck(NewData);
}

int stdnt_DataCheck(struct New_StudentRecords NewData_Receiver)
{
    char Data_Confirmation;
    system("CLS");
    printf("--! [1st Step - User Input Checkpoint] | 2nd | 3rd | 4th | 5th | Confirm | End --!\n");
    puts("\xC9\xCD\xCD USER INPUT CHECKPOINT \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB");
    printf("\n");
    printf("Is the following data inputted is correct?\n");
    printf("\n [1] First Name: %s", NewData_Receiver.stdnt_FName);
    printf(" [2] Middle Name: %s", NewData_Receiver.stdnt_MName);
    printf(" [3] Last Name: %s", NewData_Receiver.stdnt_LName);
    printf("\n");
    puts("--- GENERAL INFORMATION ---------------------------------------------------------------------------");
    printf("\n");
    printf(" [4] Gender: %s", NewData_Receiver.stdnt_Gender);
    printf(" [5] Birthday: %s", NewData_Receiver.stdnt_Birthday);
    printf(" [6] Home (Main) Address: %s", NewData_Receiver.stdnt_Address); //Include City and Village, ZIP CODE
    printf(" [7] Nationality: %s", NewData_Receiver.stdnt_Nationality);
    printf("\n");
    printf("\xCD\xCD\xCD TECHNICAL INFORMATION \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    printf("\n");
    printf(" [8] Mobile Number: %d\n", NewData_Receiver.stdnt_MobileNum);
    printf(" [9] Phone Number: %d\n", NewData_Receiver.stdnt_PhoneNum);
    printf(" [10] Emergency Number and Emergency Point of Contact (Seperated)): %d | %s", NewData_Receiver.stdnt_EmerNum, NewData_Receiver.stdnt_POC_Emergency);
    printf(" [11] Personal Email: %s", NewData_Receiver.stdnt_Email);
    printf(" [12] Behavioral Issues: %s\n\n", NewData_Receiver.stdnt_SpecialBehavioral);
    puts("\xDD USER INPUT CHECKPOINT \xDD");
    printf("Are you sure the following details you entered from the above is correct?\n");
    printf("[{Y}es or {N}o] \xAF ");
    Data_Confirmation = getchar();
    if (Data_Confirmation == 'Y' || Data_Confirmation == 'y')
    {
        fflush(stdin);
        printf("Data Temporarily On Hold... Continuing on the Next Step...");
        Sleep(2000);
        Func_NewStdnt_ERLM_Step2(NewData_Receiver);
    }
    else if (Data_Confirmation == 'N' || Data_Confirmation == 'n')
    {
        fflush(stdin); // To Avoid \n to be fed in fgets;
        printf("Returning To Step 1 | Filling up Personal Information");
        Sleep(3000);
        Func_NewStdnt_ERLM();
    }
    else
    {
        fflush(stdin); // To Avoid \n to be fed in fgets;
        printf("ERROR: Invalid Character...");
        Sleep(2000);
        stdnt_DataCheck(NewData_Receiver);
    }
}
int Func_NewStdnt_ERLM_Step2(struct New_StudentRecords NewData_Receiver)
{
    system("CLS");
    int BranchBase_Accepter = 0, MainCourse_Accepter = 0;
    char *MainCourse_CodeName[8] = {"BSCE", "BSCpE", "BSEE", "BSECE", "BSEnSE", "BSIE", "BSME", "Arch"};
    char *MainCourse_FullName[8] = {"Civil Engineering", "Computer Engineering", "Electrical Engineering", "Electronics Engineering", "Environmental and Sanitary Engineering", "Industrial Engineering", "Mechanical Engineering", "Architecture"};
    char MainCourse_CodeName_Passer[6];
    char MainCourse_FullName_Passer[40];
    SetConsoleTitle("New Student: Step 2 | Filling up | LM Enrollment System");
    printf("--! 1st | [2nd Step - Course Registration] | 3rd | 4th | 5th | Confirm | End --!\n\n"); //3RD IS SCHOLARSHIP, 4TH IS MODE OF PAYMENT
    printf("\xC9\xCD\xCD\xCD COURSE REGISTRATION \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
    printf("\xBA Please fill up your course to take and year that you want to take into.\n");
    printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    printf("\n");
    printf("\xBA\xCD\xCD \xDD PLEASE CHOOSE A BRANCH BASE COURSE \xDD \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    printf("\xBA");
    printf("\n\n [1] \xDD College of Engineering \t\t|\t\t [2] \xDD College of Architecture\n\n");
    printf("Enter your desired decision [1-2], 3 To Cancel or Abort \xAF ");
    scanf("%i", &BranchBase_Accepter);
    if (BranchBase_Accepter == 1)
    {
        system("CLS");
        printf("--! 1st | [2nd Step - Course Registration] | 3rd | 4th | 5th | Confirm | End --!\n\n");
        printf("\xCD\xCD\xCD CHOICE YOUR MAIN / DESIRED COURSE \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\n\n");
        printf("\xAF [1] | %s | %s\n", MainCourse_FullName[0], MainCourse_CodeName[0]);
        printf("\xAF [2] | %s | %s\n", MainCourse_FullName[1], MainCourse_CodeName[1]);
        printf("\xAF [3] | %s | %s\n", MainCourse_FullName[2], MainCourse_CodeName[2]);
        printf("\xAF [4] | %s | %s\n", MainCourse_FullName[3], MainCourse_CodeName[3]);
        printf("\xAF [5] | %s | %s\n", MainCourse_FullName[4], MainCourse_CodeName[4]);
        printf("\xAF [6] | %s | %s\n", MainCourse_FullName[5], MainCourse_CodeName[5]);
        printf("\xAF [7] | %s | %s\n", MainCourse_FullName[6], MainCourse_CodeName[6]);
        printf("\xDD [1-7], 8 To Cancel or Abort | \xAF ");
        scanf("%i", &MainCourse_Accepter);
        if (MainCourse_Accepter == 1)
        {
            printf("You have selected %s. Moving Foward to Year Selection...", MainCourse_FullName[0]);
            Sleep(2000);
            strcpy(MainCourse_CodeName_Passer, MainCourse_CodeName[0]);
            fflush(stdin); // Remove This Soon
            strcpy(MainCourse_FullName_Passer, MainCourse_FullName[0]);
            Func_NewStdnt_Eng_YearSelect(NewData_Receiver, MainCourse_CodeName_Passer, MainCourse_FullName_Passer);
        }
        if (MainCourse_Accepter == 2)
        {
            printf("You have selected %s. Moving Foward to Year Selection...", MainCourse_FullName[1]);
            Sleep(2000);
            strcpy(MainCourse_CodeName_Passer, MainCourse_CodeName[1]);
            fflush(stdin); // Remove This Soon
            strcpy(MainCourse_FullName_Passer, MainCourse_FullName[1]);
            Func_NewStdnt_Eng_YearSelect(NewData_Receiver, MainCourse_CodeName_Passer, MainCourse_FullName_Passer);
        }
        if (MainCourse_Accepter == 3)
        {
            printf("You have selected %s. Moving Foward to Year Selection...", MainCourse_FullName[2]);
            Sleep(2000);
            strcpy(MainCourse_CodeName_Passer, MainCourse_CodeName[2]);
            fflush(stdin); // Remove This Soon
            strcpy(MainCourse_FullName_Passer, MainCourse_FullName[2]);
            Func_NewStdnt_Eng_YearSelect(NewData_Receiver, MainCourse_CodeName_Passer, MainCourse_FullName_Passer);
        }
        if (MainCourse_Accepter == 4)
        {
            printf("You have selected %s. Moving Foward to Year Selection...", MainCourse_FullName[3]);
            Sleep(2000);
            strcpy(MainCourse_CodeName_Passer, MainCourse_CodeName[3]);
            fflush(stdin); // Remove This Soon
            strcpy(MainCourse_FullName_Passer, MainCourse_FullName[3]);
            Func_NewStdnt_Eng_YearSelect(NewData_Receiver, MainCourse_CodeName_Passer, MainCourse_FullName_Passer);
        }
        if (MainCourse_Accepter == 5)
        {
            printf("You have selected %s. Moving Foward to Year Selection...", MainCourse_FullName[4]);
            Sleep(2000);
            strcpy(MainCourse_CodeName_Passer, MainCourse_CodeName[4]);
            fflush(stdin); // Remove This Soon
            strcpy(MainCourse_FullName_Passer, MainCourse_FullName[4]);
            Func_NewStdnt_Eng_YearSelect(NewData_Receiver, MainCourse_CodeName_Passer, MainCourse_FullName_Passer);
        }
        if (MainCourse_Accepter == 6)
        {
            printf("You have selected %s. Moving Foward to Year Selection...", MainCourse_FullName[5]);
            Sleep(2000);
            strcpy(MainCourse_CodeName_Passer, MainCourse_CodeName[5]);
            fflush(stdin); // Remove This Soon
            strcpy(MainCourse_FullName_Passer, MainCourse_FullName[5]);
            Func_NewStdnt_Eng_YearSelect(NewData_Receiver, MainCourse_CodeName_Passer, MainCourse_FullName_Passer);
        }
        if (MainCourse_Accepter == 7)
        {
            printf("You have selected %s. Moving Foward to Year Selection...", MainCourse_FullName[6]);
            Sleep(2000);
            strcpy(MainCourse_CodeName_Passer, MainCourse_CodeName[6]);
            fflush(stdin); // Remove This Soon
            strcpy(MainCourse_FullName_Passer, MainCourse_FullName[6]);
            Func_NewStdnt_Eng_YearSelect(NewData_Receiver, MainCourse_CodeName_Passer, MainCourse_FullName_Passer);
        }
    }
    else if (BranchBase_Accepter == 2)
    {
        printf("\xCD\xCD\xCD ARCHITECTURE \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\n");
        printf("\nArchitecture is already declared as main course. Going forward to year selection!\n");
        Sleep(2000);
        strcpy(MainCourse_CodeName_Passer, MainCourse_CodeName[7]);
        strcpy(MainCourse_FullName_Passer, MainCourse_FullName[7]);
        Func_NewStdnt_Arch_YearSelect(NewData_Receiver, MainCourse_CodeName_Passer);
    }
    else if (BranchBase_Accepter == 3)
    {
        system("CLS");
        printf("Process Aborted by User... Returning to Main Menu");
        Sleep(3000);
        Main_Menu();
    }
    else
    {
        printf("ERROR: Input Read to Selector is Out of Range, Reinitializing...");
        Sleep(2000);
        Func_NewStdnt_ERLM_Step2(NewData_Receiver);
    }
}
// Engineering Subject Set Functions
int Func_NewStdnt_Eng_YearSelect(struct New_StudentRecords NewData, char *MainCourse_CodeName_Passer, char *MainCourse_FullName_Passer)
{
    system("CLS");
    int YearSelection_Accepter_Eng = 0, YearSelection_Accepter_Eng_Sem = 0;
    char DataCheck = 'A';
    char *ERLM_Selection_Eng[4] = {"1st Year College", "2nd Year College", "3rd Year College", "4th Year College"};
    char *ERLM_Selection_Eng_Sem[2] = {"1st Semester", "2nd Semester"};
    while (1)
    {
        printf("--! 1st | [2nd Step - Course Registration | Year Select] | 3rd | 4th | 5th | Confirm | End --!\n\n");
        printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\n");
        printf("CODENAME   |     COURSE NAME     |    STUDENT NAME\n");
        printf("%s   |     %s      %s,  %s  %s", MainCourse_CodeName_Passer, MainCourse_CodeName_Passer, NewData.stdnt_LName, NewData.stdnt_FName, NewData.stdnt_MName);
        printf("\n\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\n");
        printf("[1] 1st Year College\n");
        printf("[2] 2nd Year College\n");
        printf("[3] 3rd Year College\n");
        printf("[4] 4th Year College\n");
        printf("\n\xAF Please Select Desired College Year Level [1 - 4] \xAF ");
        scanf("%i", &YearSelection_Accepter_Eng);
        if (YearSelection_Accepter_Eng == 1)
        {
            fflush(stdin);
            printf("You have selected %s", ERLM_Selection_Eng[YearSelection_Accepter_Eng - 1]);
            break;
        }
        else if (YearSelection_Accepter_Eng == 2)
        {
            fflush(stdin);
            printf("You have selected %s", ERLM_Selection_Eng[YearSelection_Accepter_Eng - 1]);
            break;
        }
        else if (YearSelection_Accepter_Eng == 3)
        {
            fflush(stdin);
            printf("You have selected %s", ERLM_Selection_Eng[YearSelection_Accepter_Eng - 1]);
            break;
        }
        else if (YearSelection_Accepter_Eng == 4)
        {
            fflush(stdin);
            printf("You have selected %s", ERLM_Selection_Eng[YearSelection_Accepter_Eng - 1]);
            break;
        }
        else
        {
            fflush(stdin);
            printf("Your input is invalid from the choices...");
            Sleep(2000);
            continue;
        }
    }
    Sleep(2000);
    system("CLS");

    while (1)
    {
        printf("--! 1st | [2nd Step - Course Registration | Year Select] | 3rd | 4th | 5th | Confirm | End --!\n\n");
        printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\n");
        printf("\tCODENAME\t|\tNAME\t");
        printf("%s\t | \t%s,%s %s\t\t", MainCourse_CodeName_Passer, NewData.stdnt_LName, NewData.stdnt_FName, NewData.stdnt_MName);
        printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\n\n");
        fflush(stdin);
        printf("[1] | First Semester\n");
        printf("[2] | Second Semester\n");
        printf("Please choose your Desired Semester [1 - 2] \xAF ");
        scanf("%i", &YearSelection_Accepter_Eng_Sem);

        if (YearSelection_Accepter_Eng_Sem == 1)
        {
            fflush(stdin);
            printf("You have selected %s", ERLM_Selection_Eng_Sem[YearSelection_Accepter_Eng_Sem - 1]);
            break;
        }
        else if (YearSelection_Accepter_Eng_Sem == 2)
        {
            fflush(stdin);
            printf("You have selected %s", ERLM_Selection_Eng_Sem[YearSelection_Accepter_Eng_Sem - 1]);
            break;
        }
        else
        {
            fflush(stdin);
            printf("Your input is invalid from the choices...");
            Sleep(2000);
            continue;
        }
    }
    Sleep(2000);
    system("CLS");

    while (1)
    {
        printf("\xCD\xCD\xCD CONFIRMATION \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\n\n");
        printf("Are you sure is this correct?\n\n");
        printf("\xCD\xCD COURSE NAME \t\t|\t\t YEAR LEVEL && SEMESTER \t\t|\t\t COURSE CODE \n");
        printf("%s \t\t|\t\t %s | %s \t\t|\t\t %s\n", MainCourse_FullName_Passer, ERLM_Selection_Eng[YearSelection_Accepter_Eng - 1], ERLM_Selection_Eng_Sem[YearSelection_Accepter_Eng_Sem - 1], MainCourse_CodeName_Passer);
        DataCheck = getchar();
        if (DataCheck == 'Y' || DataCheck == 'y')
        {
            printf("Data Inputted | Yes. -> Going To The Next Step");
            Sleep(2000);
            // WARNING THERE ARE 64 IF AND ELSE FUNCTION INSIDE, STARTING AT THIS POINT
            if (strcmp(MainCourse_CodeName_Passer, "BSCE") == 0)
            {
                if (strcmp(ERLM_Selection_Eng[YearSelection_Accepter_Eng - 1], "1st Year College") == 0)
                {
                    if (strcmp(ERLM_Selection_Eng_Sem[YearSelection_Accepter_Eng_Sem - 1], "First Semester") == 0)
                    {
                        Stdnt_1stYear_CE_FirstSem();
                        break;
                    }
                    else
                    {
                        Stdnt_1stYear_CE_SecondSem();
                        break;
                    }
                }
                else if (strcmp(ERLM_Selection_Eng[YearSelection_Accepter_Eng - 1], "2nd Year College") == 0)
                {
                    if (strcmp(ERLM_Selection_Eng_Sem[YearSelection_Accepter_Eng_Sem - 1], "First Semester") == 0)
                    {
                        Stdnt_2ndYear_CE_FirstSem();
                        break;
                    }
                    else
                    {
                        Stdnt_2ndYear_CE_SecondSem();
                        break;
                    }
                }
                else if (strcmp(ERLM_Selection_Eng[YearSelection_Accepter_Eng - 1], "3rd Year College") == 0)
                {
                    if (strcmp(ERLM_Selection_Eng_Sem[YearSelection_Accepter_Eng_Sem - 1], "First Semester") == 0)
                    {
                        Stdnt_3rdYear_CE_FirstSem();
                        break;
                    }
                    else
                    {
                        Stdnt_3rdYear_CE_SecondSem();
                        break;
                    }
                }
                else if (strcmp(ERLM_Selection_Eng[YearSelection_Accepter_Eng - 1], "4th Year College") == 0)
                {
                    if (strcmp(ERLM_Selection_Eng_Sem[YearSelection_Accepter_Eng_Sem - 1], "First Semester") == 0)
                    {
                        Stdnt_4thYear_CE_FirstSem();
                        break;
                    }
                    else
                    {
                        Stdnt_4thYear_CE_SecondSem();
                        break;
                    }
                }
            }
            if (strcmp(MainCourse_CodeName_Passer, "BSCpE") == 0)
            {
                if (strcmp(ERLM_Selection_Eng[YearSelection_Accepter_Eng - 1], "1st Year College") == 0)
                {
                    if (strcmp(ERLM_Selection_Eng_Sem[YearSelection_Accepter_Eng_Sem - 1], "First Semester") == 0)
                    {
                        Stdnt_1stYear_CpE_FirstSem();
                        break;
                    }
                    else
                    {
                        Stdnt_1stYear_CpE_SecondSem();
                        break;
                    }
                }
                else if (strcmp(ERLM_Selection_Eng[YearSelection_Accepter_Eng - 1], "2nd Year College") == 0)
                {
                    if (strcmp(ERLM_Selection_Eng_Sem[YearSelection_Accepter_Eng_Sem - 1], "First Semester") == 0)
                    {
                        Stdnt_2ndYear_CpE_FirstSem();
                        break;
                    }
                    else
                    {
                        Stdnt_2ndYear_CpE_SecondSem();
                        break;
                    }
                }
                else if (strcmp(ERLM_Selection_Eng[YearSelection_Accepter_Eng - 1], "3rd Year College") == 0)
                {
                    if (strcmp(ERLM_Selection_Eng_Sem[YearSelection_Accepter_Eng_Sem - 1], "First Semester") == 0)
                    {
                        Stdnt_3rdYear_CpE_FirstSem();
                        break;
                    }
                    else
                    {
                        Stdnt_3rdYear_CpE_SecondSem();
                        break;
                    }
                }
                else if (strcmp(ERLM_Selection_Eng[YearSelection_Accepter_Eng - 1], "4th Year College") == 0)
                {
                    if (strcmp(ERLM_Selection_Eng_Sem[YearSelection_Accepter_Eng_Sem - 1], "First Semester") == 0)
                    {
                        Stdnt_4thYear_CpE_FirstSem();
                        break;
                    }
                    else
                    {
                        Stdnt_4thYear_CpE_SecondSem();
                        break;
                    }
                }
            }
            if (strcmp(MainCourse_CodeName_Passer, "BSEE") == 0)
            {
                if (strcmp(ERLM_Selection_Eng[YearSelection_Accepter_Eng - 1], "1st Year College") == 0)
                {
                    if (strcmp(ERLM_Selection_Eng_Sem[YearSelection_Accepter_Eng_Sem - 1], "First Semester") == 0)
                    {
                        Stdnt_1stYear_EE_FirstSem();
                        break;
                    }
                    else
                    {
                        Stdnt_1stYear_EE_SecondSem();
                        break;
                    }
                }
                else if (strcmp(ERLM_Selection_Eng[YearSelection_Accepter_Eng - 1], "2nd Year College") == 0)
                {
                    if (strcmp(ERLM_Selection_Eng_Sem[YearSelection_Accepter_Eng_Sem - 1], "First Semester") == 0)
                    {
                        Stdnt_2ndYear_EE_FirstSem();
                        break;
                    }
                    else
                    {
                        Stdnt_2ndYear_EE_SecondSem();
                        break;
                    }
                }
                else if (strcmp(ERLM_Selection_Eng[YearSelection_Accepter_Eng - 1], "3rd Year College") == 0)
                {
                    if (strcmp(ERLM_Selection_Eng_Sem[YearSelection_Accepter_Eng_Sem - 1], "First Semester") == 0)
                    {
                        Stdnt_3rdYear_EE_FirstSem();
                        break;
                    }
                    else
                    {
                        Stdnt_3rdYear_EE_SecondSem();
                        break;
                    }
                }
                else if (strcmp(ERLM_Selection_Eng[YearSelection_Accepter_Eng - 1], "4th Year College") == 0)
                {
                    if (strcmp(ERLM_Selection_Eng_Sem[YearSelection_Accepter_Eng_Sem - 1], "First Semester") == 0)
                    {
                        Stdnt_4thYear_EE_FirstSem();
                        break;
                    }
                    else
                    {
                        Stdnt_4thYear_EE_SecondSem();
                        break;
                    }
                }
            }
            if (strcmp(MainCourse_CodeName_Passer, "BSECE") == 0)
            {
                if (strcmp(ERLM_Selection_Eng[YearSelection_Accepter_Eng - 1], "1st Year College") == 0)
                {
                    if (strcmp(ERLM_Selection_Eng_Sem[YearSelection_Accepter_Eng_Sem - 1], "First Semester") == 0)
                    {
                        Stdnt_1stYear_ECE_FirstSem();
                        break;
                    }
                    else
                    {
                        Stdnt_1stYear_ECE_SecondSem();
                        break;
                    }
                }
                else if (strcmp(ERLM_Selection_Eng[YearSelection_Accepter_Eng - 1], "2nd Year College") == 0)
                {
                    if (strcmp(ERLM_Selection_Eng_Sem[YearSelection_Accepter_Eng_Sem - 1], "First Semester") == 0)
                    {
                        Stdnt_2ndYear_ECE_FirstSem();
                        break;
                    }
                    else
                    {
                        Stdnt_2ndYear_ECE_SecondSem();
                        break;
                    }
                }
                else if (strcmp(ERLM_Selection_Eng[YearSelection_Accepter_Eng - 1], "3rd Year College") == 0)
                {
                    if (strcmp(ERLM_Selection_Eng_Sem[YearSelection_Accepter_Eng_Sem - 1], "First Semester") == 0)
                    {
                        Stdnt_3rdYear_ECE_FirstSem();
                        break;
                    }
                    else
                    {
                        Stdnt_3rdYear_ECE_SecondSem();
                        break;
                    }
                }
                else if (strcmp(ERLM_Selection_Eng[YearSelection_Accepter_Eng - 1], "4th Year College") == 0)
                {
                    if (strcmp(ERLM_Selection_Eng_Sem[YearSelection_Accepter_Eng_Sem - 1], "First Semester") == 0)
                    {
                        Stdnt_4thYear_ECE_FirstSem();
                        break;
                    }
                    else
                    {
                        Stdnt_4thYear_ECE_SecondSem();
                        break;
                    }
                }
            }
            if (strcmp(MainCourse_CodeName_Passer, "BSEnSE") == 0)
            {
                if (strcmp(ERLM_Selection_Eng[YearSelection_Accepter_Eng - 1], "1st Year College") == 0)
                {
                    if (strcmp(ERLM_Selection_Eng_Sem[YearSelection_Accepter_Eng_Sem - 1], "First Semester") == 0)
                    {
                        Stdnt_1stYear_EnSE_FirstSem();
                        break;
                    }
                    else
                    {
                        Stdnt_1stYear_EnSE_SecondSem();
                        break;
                    }
                }
                else if (strcmp(ERLM_Selection_Eng[YearSelection_Accepter_Eng - 1], "2nd Year College") == 0)
                {
                    if (strcmp(ERLM_Selection_Eng_Sem[YearSelection_Accepter_Eng_Sem - 1], "First Semester") == 0)
                    {
                        Stdnt_2ndYear_EnSE_FirstSem();
                        break;
                    }
                    else
                    {
                        Stdnt_2ndYear_EnSE_SecondSem();
                        break;
                    }
                }
                else if (strcmp(ERLM_Selection_Eng[YearSelection_Accepter_Eng - 1], "3rd Year College") == 0)
                {
                    if (strcmp(ERLM_Selection_Eng_Sem[YearSelection_Accepter_Eng_Sem - 1], "First Semester") == 0)
                    {
                        Stdnt_3rdYear_EnSE_FirstSem();
                        break;
                    }
                    else
                    {
                        Stdnt_3rdYear_EnSE_SecondSem();
                        break;
                    }
                }
                else if (strcmp(ERLM_Selection_Eng[YearSelection_Accepter_Eng - 1], "4th Year College") == 0)
                {
                    if (strcmp(ERLM_Selection_Eng_Sem[YearSelection_Accepter_Eng_Sem - 1], "First Semester") == 0)
                    {
                        Stdnt_4thYear_EnSE_FirstSem();
                        break;
                    }
                    else
                    {
                        Stdnt_4thYear_EnSE_SecondSem();
                        break;
                    }
                }
            }
            if (strcmp(MainCourse_CodeName_Passer, "BSIE") == 0)
            {
                if (strcmp(ERLM_Selection_Eng[YearSelection_Accepter_Eng - 1], "1st Year College") == 0)
                {
                    if (strcmp(ERLM_Selection_Eng_Sem[YearSelection_Accepter_Eng_Sem - 1], "First Semester") == 0)
                    {
                        Stdnt_1stYear_IE_FirstSem();
                        break;
                    }
                    else
                    {
                        Stdnt_1stYear_IE_SecondSem();
                        break;
                    }
                }
                else if (strcmp(ERLM_Selection_Eng[YearSelection_Accepter_Eng - 1], "2nd Year College") == 0)
                {
                    if (strcmp(ERLM_Selection_Eng_Sem[YearSelection_Accepter_Eng_Sem - 1], "First Semester") == 0)
                    {
                        Stdnt_2ndYear_IE_FirstSem();
                        break;
                    }
                    else
                    {
                        Stdnt_2ndYear_IE_SecondSem();
                        break;
                    }
                }
                else if (strcmp(ERLM_Selection_Eng[YearSelection_Accepter_Eng - 1], "3rd Year College") == 0)
                {
                    if (strcmp(ERLM_Selection_Eng_Sem[YearSelection_Accepter_Eng_Sem - 1], "First Semester") == 0)
                    {
                        Stdnt_3rdYear_IE_FirstSem();
                        break;
                    }
                    else
                    {
                        Stdnt_3rdYear_IE_SecondSem();
                        break;
                    }
                }
                else if (strcmp(ERLM_Selection_Eng[YearSelection_Accepter_Eng - 1], "4th Year College") == 0)
                {
                    if (strcmp(ERLM_Selection_Eng_Sem[YearSelection_Accepter_Eng_Sem - 1], "First Semester") == 0)
                    {
                        Stdnt_4thYear_IE_FirstSem();
                        break;
                    }
                    else
                    {
                        Stdnt_4thYear_IE_SecondSem();
                        break;
                    }
                }
            }
            if (strcmp(MainCourse_CodeName_Passer, "BSME") == 0)
            {
                if (strcmp(ERLM_Selection_Eng[YearSelection_Accepter_Eng - 1], "1st Year College") == 0)
                {
                    if (strcmp(ERLM_Selection_Eng_Sem[YearSelection_Accepter_Eng_Sem - 1], "First Semester") == 0)
                    {
                        Stdnt_1stYear_ME_FirstSem();
                        break;
                    }
                    else
                    {
                        Stdnt_1stYear_ME_SecondSem();
                        break;
                    }
                }
                else if (strcmp(ERLM_Selection_Eng[YearSelection_Accepter_Eng - 1], "2nd Year College") == 0)
                {
                    if (strcmp(ERLM_Selection_Eng_Sem[YearSelection_Accepter_Eng_Sem - 1], "First Semester") == 0)
                    {
                        Stdnt_2ndYear_ME_FirstSem();
                        break;
                    }
                    else
                    {
                        Stdnt_2ndYear_ME_SecondSem();
                        break;
                    }
                }
                else if (strcmp(ERLM_Selection_Eng[YearSelection_Accepter_Eng - 1], "3rd Year College") == 0)
                {
                    if (strcmp(ERLM_Selection_Eng_Sem[YearSelection_Accepter_Eng_Sem - 1], "First Semester") == 0)
                    {
                        Stdnt_3rdYear_ME_FirstSem();
                        break;
                    }
                    else
                    {
                        Stdnt_3rdYear_ME_SecondSem();
                        break;
                    }
                }
                else if (strcmp(ERLM_Selection_Eng[YearSelection_Accepter_Eng - 1], "4th Year College") == 0)
                {
                    if (strcmp(ERLM_Selection_Eng_Sem[YearSelection_Accepter_Eng_Sem - 1], "First Semester") == 0)
                    {
                        Stdnt_4thYear_ME_FirstSem();
                        break;
                    }
                    else
                    {
                        Stdnt_4thYear_ME_SecondSem();
                        break;
                    }
                }
                else
                {
                    printf("\xDD\xAF ERROR! : Comparison OUT OF RANGE. This is a bug or flow issue. Please report it to the developer.");
                    return EXIT_FAILURE;
                }
            }
        }
        else if (DataCheck == 'N' || DataCheck == 'n')
        {
            printf("Going back...");
            Sleep(2000);
            continue;
            //Func_NewStdnt_Eng_YearSelect(NewData, MainCourse_CodeName_Passer, MainCourse_FullName_Passer);
        }
        else
        {
            printf("Your input is 'Out of Range' from the Choices!");
            Sleep(2000);
            continue;
        }
    }
}
// Architecture Functions
int Func_NewStdnt_Arch_YearSelect(struct New_StudentRecords NewData, char *MainCourse_CodeName_Passer)
{
    system("CLS");
    int YearSelection_Accepter_Arch = 0, YearSelection_Accepter_Arch_Sem = 0;
    char DataCheck = 'A';
    char *ERLM_Selection_Arch[5] = {"1st Year College", "2nd Year College", "3rd Year College", "4th Year College", "5th Year College"};
    char *ERLM_Selection_Arch_Sem[2] = {"1st Semester", "2nd Semester"};
    while (1)
    {
        printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
        printf("\t\t CODENAME \t | \t COURSE NAME \t | \t STUDENT NAME\n");
        printf("\t\t %s \t\t | %s,%s,%s\t\t", MainCourse_CodeName_Passer, NewData.stdnt_LName, NewData.stdnt_FName, NewData.stdnt_MName);
        printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\n");
        printf("[0] 1st Year College");
        printf("[1] 2nd Year College");
        printf("[2] 3rd Year College");
        printf("[3] 4th Year College");
        printf("[4] 5th Year College");
        printf("\n\xAF Please Select Your Year \xAF ");
        scanf("%i", &YearSelection_Accepter_Arch);
        if (YearSelection_Accepter_Arch == 1)
        {
            fflush(stdin);
            printf("You have selected %s", ERLM_Selection_Arch[YearSelection_Accepter_Arch - 1]);
            break;
        }
        else if (YearSelection_Accepter_Arch == 2)
        {
            fflush(stdin);
            printf("You have selected %s", ERLM_Selection_Arch[YearSelection_Accepter_Arch - 1]);
            break;
        }
        else if (YearSelection_Accepter_Arch == 3)
        {
            fflush(stdin);
            printf("You have selected %s", ERLM_Selection_Arch[YearSelection_Accepter_Arch - 1]);
            break;
        }
        else if (YearSelection_Accepter_Arch == 4)
        {
            fflush(stdin);
            printf("You have selected %s", ERLM_Selection_Arch[YearSelection_Accepter_Arch - 1]);
            break;
        }
        else
        {
            fflush(stdin);
            printf("Your input is invalid from the choices...");
            Sleep(2000);
            continue;
        }
    }
    Sleep(2000);
    system("CLS");
    while (1)
    {
        printf("--! 1st | [2nd Step - Course Registration | Year Select] | 3rd | 4th | 5th | Confirm | End --!\n\n");
        printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
        printf("\t\t CODENAME \t\t | \t\t NAME \t\t ");
        printf("\t\t %s \t\t | %s,%s,%s\t\t", MainCourse_CodeName_Passer, NewData.stdnt_LName, NewData.stdnt_FName, NewData.stdnt_MName);
        printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
        fflush(stdin);
        printf("[1] | First Semester");
        printf("[2] | Second Semester");
        printf("Please choose your Semester: \xAF ");
        scanf("%i", &YearSelection_Accepter_Arch_Sem);
        fflush(stdin);

        if (YearSelection_Accepter_Arch_Sem == 1)
        {
            fflush(stdin);
            printf("You have selected %s", ERLM_Selection_Arch_Sem[YearSelection_Accepter_Arch_Sem - 1]);
            break;
        }
        else if (YearSelection_Accepter_Arch_Sem == 2)
        {
            fflush(stdin);
            printf("You have selected %s", ERLM_Selection_Arch_Sem[YearSelection_Accepter_Arch_Sem - 1]);
            break;
        }
        else
        {
            fflush(stdin);
            printf("Your input is invalid from the choices...");
            Sleep(2000);
            continue;
        }
    }
    system("CLS");
    while (1)
    {
        printf("\xCD\xCD\xCD CONFIRMATION \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\n\n");
        printf("Are you sure is this correct?\n\n");
        printf("\xCD\xCD COURSE NAME \t\t|\t\t YEAR LEVEL && SEMESTER \t\t|\t\t COURSE CODE ");
        printf("%s \t\t|\t\t %s | %s \t\t|\t\t %s", "Architecture", ERLM_Selection_Arch[YearSelection_Accepter_Arch], ERLM_Selection_Arch_Sem[YearSelection_Accepter_Arch], MainCourse_CodeName_Passer);
        scanf("%c", &DataCheck);
        if (DataCheck == 'Y' || DataCheck == 'y')
        {
            printf("Data Inputted | Yes. -> Going To The Next Step");
            Sleep(2000);
            if (strcmp(ERLM_Selection_Arch[YearSelection_Accepter_Arch], "1st Year College") == 0)
            {
                if (strcmp(ERLM_Selection_Arch_Sem[YearSelection_Accepter_Arch_Sem], "First Semester") == 0)
                {
                    Stdnt_1stYear_Arch_FirstSem();
                    break;
                }
                else
                {
                    Stdnt_1stYear_Arch_SecondSem();
                    break;
                }
            }
            else if (strcmp(ERLM_Selection_Arch[YearSelection_Accepter_Arch], "2nd Year College") == 0)
            {
                if (strcmp(ERLM_Selection_Arch_Sem[YearSelection_Accepter_Arch_Sem], "First Semester") == 0)
                {
                    Stdnt_2ndYear_Arch_FirstSem();
                    break;
                }
                else
                {
                    Stdnt_2ndYear_Arch_SecondSem();
                    break;
                }
            }
            else if (strcmp(ERLM_Selection_Arch[YearSelection_Accepter_Arch], "3rd Year College") == 0)
            {
                if (strcmp(ERLM_Selection_Arch_Sem[YearSelection_Accepter_Arch_Sem], "First Semester") == 0)
                {
                    Stdnt_3rdYear_Arch_FirstSem();
                    break;
                }
                else
                {
                    Stdnt_3rdYear_Arch_SecondSem();
                    break;
                }
            }
            else if (strcmp(ERLM_Selection_Arch[YearSelection_Accepter_Arch], "4th Year College") == 0)
            {
                if (strcmp(ERLM_Selection_Arch_Sem[YearSelection_Accepter_Arch_Sem], "First Semester") == 0)
                {
                    Stdnt_4thYear_Arch_FirstSem();
                    break;
                }
                else
                {
                    Stdnt_4thYear_Arch_SecondSem();
                    break;
                }
            }
            else if (strcmp(ERLM_Selection_Arch[YearSelection_Accepter_Arch], "5th Year College") == 0)
            {
                if (strcmp(ERLM_Selection_Arch_Sem[YearSelection_Accepter_Arch_Sem], "First Semester") == 0)
                {
                    Stdnt_5thYear_Arch_FirstSem();
                    break;
                }
                else
                {
                    Stdnt_5thYear_Arch_SecondSem();
                    break;
                }
            }
        }
        else if (DataCheck == 'N' || DataCheck == 'n')
        {
            printf("\xDD PROCESS \xAF No. \xAF Going Back...");
            Sleep(2000);
            continue;
            //Func_NewStdnt_Arch_YearSelect(NewData, MainCourse_CodeName_Passer);
        }
        else
        {
            printf("\xDD PROCESS \xAF Out of Range from Choices. Going Back...");
            Sleep(2000);
            continue;
            //Func_NewStdnt_Arch_YearSelect(NewData, MainCourse_CodeName_Passer);
        }
    }
}

//Architecture Selection Functions for Enrollment
int Stdnt_1stYear_Arch_FirstSem()
{
    int Subject_Selector;
    char *Subject_FullNameEncoded[11];
    char *Subject_FullNameEncode_Bool[11];
    char *Subject_Units[11];
    char *Subject_LinearTime[12] = {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-"};
    system("CLS");
    gotoxy(30, 3);
    printf("\xC9\xCD\xCD CURRENT PROGRESS \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
    gotoxy(30, 4);
    printf("\xBA 1st | 2nd | \xDD [3rd Subject Enrollment Selection] | 4th | 5th | Confirm | End\t\t           \xBA\n");
    gotoxy(30, 5);
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xBA [0] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [1] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [2] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [3] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [4] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [5] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [6] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [7] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [8] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [9] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xDD Please select the subject corresponding to the number to be enrollled \xAF ");
    scanf("%i", &Subject_Selector);
    //Continue Function...
}
int Stdnt_1stYear_Arch_SecondSem()
{
    int Subject_Selector;
    char *Subject_FullNameEncoded[11];
    char *Subject_FullNameEncode_Bool[11];
    char *Subject_Units[11];
    char *Subject_LinearTime[12] = {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-"};
    system("CLS");
    gotoxy(30, 3);
    printf("\xC9\xCD\xCD CURRENT PROGRESS \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
    gotoxy(30, 4);
    printf("\xBA 1st | 2nd | \xDD [3rd Subject Enrollment Selection] | 4th | 5th | Confirm | End\t\t           \xBA\n");
    gotoxy(30, 5);
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xBA [0] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [1] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [2] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [3] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [4] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [5] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [6] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [7] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [8] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [9] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xDD Please select the subject corresponding to the number to be enrollled \xAF ");
    scanf("%i", &Subject_Selector);
    //Continue Function...
}
int Stdnt_2ndYear_Arch_FirstSem()
{
    int Subject_Selector;
    char *Subject_FullNameEncoded[11];
    char *Subject_FullNameEncode_Bool[11];
    char *Subject_Units[11];
    char *Subject_LinearTime[12] = {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-"};
    system("CLS");
    gotoxy(30, 3);
    printf("\xC9\xCD\xCD CURRENT PROGRESS \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
    gotoxy(30, 4);
    printf("\xBA 1st | 2nd | \xDD [3rd Subject Enrollment Selection] | 4th | 5th | Confirm | End\t\t           \xBA\n");
    gotoxy(30, 5);
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xBA [0] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [1] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [2] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [3] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [4] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [5] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [6] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [7] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [8] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [9] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xDD Please select the subject corresponding to the number to be enrollled \xAF ");
    scanf("%i", &Subject_Selector);
    //Continue Function...
}
int Stdnt_2ndYear_Arch_SecondSem()
{
    int Subject_Selector;
    char *Subject_FullNameEncoded[11];
    char *Subject_FullNameEncode_Bool[11];
    char *Subject_Units[11];
    char *Subject_LinearTime[12] = {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-"};
    system("CLS");
    gotoxy(30, 3);
    printf("\xC9\xCD\xCD CURRENT PROGRESS \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
    gotoxy(30, 4);
    printf("\xBA 1st | 2nd | \xDD [3rd Subject Enrollment Selection] | 4th | 5th | Confirm | End\t\t           \xBA\n");
    gotoxy(30, 5);
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xBA [0] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [1] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [2] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [3] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [4] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [5] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [6] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [7] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [8] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [9] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xDD Please select the subject corresponding to the number to be enrollled \xAF ");
    scanf("%i", &Subject_Selector);
    //Continue Function...
}
int Stdnt_3rdYear_Arch_FirstSem()
{
    int Subject_Selector;
    char *Subject_FullNameEncoded[11];
    char *Subject_FullNameEncode_Bool[11];
    char *Subject_Units[11];
    char *Subject_LinearTime[12] = {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-"};
    system("CLS");
    gotoxy(30, 3);
    printf("\xC9\xCD\xCD CURRENT PROGRESS \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
    gotoxy(30, 4);
    printf("\xBA 1st | 2nd | \xDD [3rd Subject Enrollment Selection] | 4th | 5th | Confirm | End\t\t           \xBA\n");
    gotoxy(30, 5);
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xBA [0] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [1] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [2] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [3] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [4] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [5] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [6] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [7] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [8] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [9] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xDD Please select the subject corresponding to the number to be enrollled \xAF ");
    scanf("%i", &Subject_Selector);
    //Continue Function...
}
int Stdnt_3rdYear_Arch_SecondSem()
{
    int Subject_Selector;
    char *Subject_FullNameEncoded[11];
    char *Subject_FullNameEncode_Bool[11];
    char *Subject_Units[11];
    char *Subject_LinearTime[12] = {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-"};
    system("CLS");
    gotoxy(30, 3);
    printf("\xC9\xCD\xCD CURRENT PROGRESS \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
    gotoxy(30, 4);
    printf("\xBA 1st | 2nd | \xDD [3rd Subject Enrollment Selection] | 4th | 5th | Confirm | End\t\t           \xBA\n");
    gotoxy(30, 5);
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xBA [0] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [1] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [2] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [3] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [4] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [5] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [6] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [7] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [8] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [9] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xDD Please select the subject corresponding to the number to be enrollled \xAF ");
    scanf("%i", &Subject_Selector);
    //Continue Function...
}
int Stdnt_4thYear_Arch_FirstSem()
{
    int Subject_Selector;
    char *Subject_FullNameEncoded[11];
    char *Subject_FullNameEncode_Bool[11];
    char *Subject_Units[11];
    char *Subject_LinearTime[12] = {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-"};
    system("CLS");
    gotoxy(30, 3);
    printf("\xC9\xCD\xCD CURRENT PROGRESS \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
    gotoxy(30, 4);
    printf("\xBA 1st | 2nd | \xDD [3rd Subject Enrollment Selection] | 4th | 5th | Confirm | End\t\t           \xBA\n");
    gotoxy(30, 5);
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xBA [0] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [1] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [2] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [3] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [4] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [5] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [6] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [7] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [8] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [9] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xDD Please select the subject corresponding to the number to be enrollled \xAF ");
    scanf("%i", &Subject_Selector);
    //Continue Function...
}
int Stdnt_4thYear_Arch_SecondSem()
{
    int Subject_Selector;
    char *Subject_FullNameEncoded[11];
    char *Subject_FullNameEncode_Bool[11];
    char *Subject_Units[11];
    char *Subject_LinearTime[12] = {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-"};
    system("CLS");
    gotoxy(30, 3);
    printf("\xC9\xCD\xCD CURRENT PROGRESS \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
    gotoxy(30, 4);
    printf("\xBA 1st | 2nd | \xDD [3rd Subject Enrollment Selection] | 4th | 5th | Confirm | End\t\t           \xBA\n");
    gotoxy(30, 5);
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xBA [0] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [1] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [2] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [3] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [4] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [5] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [6] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [7] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [8] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [9] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xDD Please select the subject corresponding to the number to be enrollled \xAF ");
    scanf("%i", &Subject_Selector);
    //Continue Function...
}
int Stdnt_5thYear_Arch_FirstSem()
{
    int Subject_Selector;
    char *Subject_FullNameEncoded[11];
    char *Subject_FullNameEncode_Bool[11];
    char *Subject_Units[11];
    char *Subject_LinearTime[12] = {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-"};
    system("CLS");
    gotoxy(30, 3);
    printf("\xC9\xCD\xCD CURRENT PROGRESS \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
    gotoxy(30, 4);
    printf("\xBA 1st | 2nd | \xDD [3rd Subject Enrollment Selection] | 4th | 5th | Confirm | End\t\t           \xBA\n");
    gotoxy(30, 5);
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xBA [0] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [1] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [2] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [3] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [4] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [5] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [6] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [7] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [8] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [9] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xDD Please select the subject corresponding to the number to be enrollled \xAF ");
    scanf("%i", &Subject_Selector);
    //Continue Function...
}
int Stdnt_5thYear_Arch_SecondSem()
{
    int Subject_Selector;
    char *Subject_FullNameEncoded[11];
    char *Subject_FullNameEncode_Bool[11];
    char *Subject_Units[11];
    char *Subject_LinearTime[12] = {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-"};
    system("CLS");
    gotoxy(30, 3);
    printf("\xC9\xCD\xCD CURRENT PROGRESS \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
    gotoxy(30, 4);
    printf("\xBA 1st | 2nd | \xDD [3rd Subject Enrollment Selection] | 4th | 5th | Confirm | End\t\t           \xBA\n");
    gotoxy(30, 5);
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xBA [0] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [1] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [2] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [3] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [4] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [5] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [6] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [7] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [8] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [9] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xDD Please select the subject corresponding to the number to be enrollled \xAF ");
    scanf("%i", &Subject_Selector);
    //Continue Function...
}
// Civil Engineer Selection Functions for Enrollment
int Stdnt_1stYear_CE_FirstSem()
{
    int Subject_Selector;
    char *Subject_FullNameEncoded[11];
    char *Subject_FullNameEncode_Bool[11];
    char *Subject_Units[11];
    char *Subject_LinearTime[12] = {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-"};
    system("CLS");
    gotoxy(30, 3);
    printf("\xC9\xCD\xCD CURRENT PROGRESS \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
    gotoxy(30, 4);
    printf("\xBA 1st | 2nd | \xDD [3rd Subject Enrollment Selection] | 4th | 5th | Confirm | End\t\t           \xBA\n");
    gotoxy(30, 5);
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xBA [0] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [1] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [2] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [3] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [4] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [5] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [6] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [7] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [8] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [9] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xDD Please select the subject corresponding to the number to be enrollled \xAF ");
    scanf("%i", &Subject_Selector);
    //Continue Function...
}
int Stdnt_1stYear_CE_SecondSem()
{
    int Subject_Selector;
    char *Subject_FullNameEncoded[11];
    char *Subject_FullNameEncode_Bool[11];
    char *Subject_Units[11];
    char *Subject_LinearTime[12] = {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-"};
    system("CLS");
    gotoxy(30, 3);
    printf("\xC9\xCD\xCD CURRENT PROGRESS \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
    gotoxy(30, 4);
    printf("\xBA 1st | 2nd | \xDD [3rd Subject Enrollment Selection] | 4th | 5th | Confirm | End\t\t           \xBA\n");
    gotoxy(30, 5);
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xBA [0] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [1] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [2] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [3] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [4] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [5] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [6] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [7] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [8] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [9] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xDD Please select the subject corresponding to the number to be enrollled \xAF ");
    scanf("%i", &Subject_Selector);
    //Continue Function...
}
int Stdnt_2ndYear_CE_FirstSem()
{
    int Subject_Selector;
    char *Subject_FullNameEncoded[11];
    char *Subject_FullNameEncode_Bool[11];
    char *Subject_Units[11];
    char *Subject_LinearTime[12] = {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-"};
    system("CLS");
    gotoxy(30, 3);
    printf("\xC9\xCD\xCD CURRENT PROGRESS \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
    gotoxy(30, 4);
    printf("\xBA 1st | 2nd | \xDD [3rd Subject Enrollment Selection] | 4th | 5th | Confirm | End\t\t           \xBA\n");
    gotoxy(30, 5);
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xBA [0] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [1] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [2] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [3] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [4] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [5] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [6] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [7] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [8] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [9] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xDD Please select the subject corresponding to the number to be enrollled \xAF ");
    scanf("%i", &Subject_Selector);
    //Continue Function...
}
int Stdnt_2ndYear_CE_SecondSem()
{
    int Subject_Selector;
    char *Subject_FullNameEncoded[11];
    char *Subject_FullNameEncode_Bool[11];
    char *Subject_Units[11];
    char *Subject_LinearTime[12] = {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-"};
    system("CLS");
    gotoxy(30, 3);
    printf("\xC9\xCD\xCD CURRENT PROGRESS \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
    gotoxy(30, 4);
    printf("\xBA 1st | 2nd | \xDD [3rd Subject Enrollment Selection] | 4th | 5th | Confirm | End\t\t           \xBA\n");
    gotoxy(30, 5);
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xBA [0] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [1] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [2] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [3] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [4] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [5] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [6] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [7] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [8] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [9] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xDD Please select the subject corresponding to the number to be enrollled \xAF ");
    scanf("%i", &Subject_Selector);
    //Continue Function...
}
int Stdnt_3rdYear_CE_FirstSem()
{
    int Subject_Selector;
    char *Subject_FullNameEncoded[11];
    char *Subject_FullNameEncode_Bool[11];
    char *Subject_Units[11];
    char *Subject_LinearTime[12] = {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-"};
    system("CLS");
    gotoxy(30, 3);
    printf("\xC9\xCD\xCD CURRENT PROGRESS \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
    gotoxy(30, 4);
    printf("\xBA 1st | 2nd | \xDD [3rd Subject Enrollment Selection] | 4th | 5th | Confirm | End\t\t           \xBA\n");
    gotoxy(30, 5);
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xBA [0] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [1] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [2] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [3] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [4] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [5] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [6] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [7] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [8] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [9] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xDD Please select the subject corresponding to the number to be enrollled \xAF ");
    scanf("%i", &Subject_Selector);
    //Continue Function...
}
int Stdnt_3rdYear_CE_SecondSem()
{
    int Subject_Selector;
    char *Subject_FullNameEncoded[11];
    char *Subject_FullNameEncode_Bool[11];
    char *Subject_Units[11];
    char *Subject_LinearTime[12] = {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-"};
    system("CLS");
    gotoxy(30, 3);
    printf("\xC9\xCD\xCD CURRENT PROGRESS \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
    gotoxy(30, 4);
    printf("\xBA 1st | 2nd | \xDD [3rd Subject Enrollment Selection] | 4th | 5th | Confirm | End\t\t           \xBA\n");
    gotoxy(30, 5);
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xBA [0] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [1] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [2] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [3] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [4] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [5] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [6] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [7] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [8] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [9] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xDD Please select the subject corresponding to the number to be enrollled \xAF ");
    scanf("%i", &Subject_Selector);
    //Continue Function...
}
int Stdnt_4thYear_CE_FirstSem()
{
    int Subject_Selector;
    system("CLS");
    gotoxy(30, 3);
    printf("\xC9\xCD\xCD CURRENT PROGRESS \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
    gotoxy(30, 4);
    printf("\xBA 1st | 2nd | \xDD [3rd Subject Enrollment Selection] | 4th | 5th | Confirm | End\t\t           \xBA\n");
    gotoxy(30, 5);
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xBA [0] \xAF Year.Subject \xDD  Sem.Units\xBA\n");
    printf("\xBA [1] \xAF Year.Subject \xDD  Sem.Units\xBA\n");
    printf("\xBA [2] \xAF Year.Subject \xDD  Sem.Units\xBA\n");
    printf("\xBA [3] \xAF Year.Subject \xDD  Sem.Units\xBA\n");
    printf("\xBA [4] \xAF Year.Subject \xDD  Sem.Units\xBA\n");
    printf("\xBA [5] \xAF Year.Subject \xDD  Sem.Units\xBA\n");
    printf("\xBA [6] \xAF Year.Subject \xDD  Sem.Units\xBA\n");
    printf("\xBA [7] \xAF Year.Subject \xDD  Sem.Units\xBA\n");
    printf("\xBA [8] \xAF Year.Subject \xDD  Sem.Units\xBA\n");
    printf("\xBA [9] \xAF Year.Subject \xDD  Sem.Units\xBA\n");
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xDD Please select the subject corresponding to the number to be enrollled \xAF ");
    scanf("%i", &Subject_Selector);
    //Continue Function...
}
int Stdnt_4thYear_CE_SecondSem()
{
    int Subject_Selector;
    char *Subject_FullNameEncoded[11];
    char *Subject_FullNameEncode_Bool[11];
    char *Subject_Units[11];
    char *Subject_LinearTime[12] = {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-"};
    system("CLS");
    gotoxy(30, 3);
    printf("\xC9\xCD\xCD CURRENT PROGRESS \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
    gotoxy(30, 4);
    printf("\xBA 1st | 2nd | \xDD [3rd Subject Enrollment Selection] | 4th | 5th | Confirm | End\t\t           \xBA\n");
    gotoxy(30, 5);
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xBA [0] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [1] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [2] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [3] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [4] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [5] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [6] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [7] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [8] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [9] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xDD Please select the subject corresponding to the number to be enrollled \xAF ");
    scanf("%i", &Subject_Selector);
    //Continue Function...
}
// Computer Engineer Selection Functions for Enrollment
int Stdnt_1stYear_CpE_FirstSem()
{
    int Subject_Selector;
    char *Subject_FullNameEncoded[11];
    char *Subject_FullNameEncode_Bool[11];
    char *Subject_Units[11];
    char *Subject_LinearTime[12] = {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-"};
    system("CLS");
    gotoxy(30, 3);
    printf("\xC9\xCD\xCD CURRENT PROGRESS \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
    gotoxy(30, 4);
    printf("\xBA 1st | 2nd | \xDD [3rd Subject Enrollment Selection] | 4th | 5th | Confirm | End\t\t           \xBA\n");
    gotoxy(30, 5);
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xBA [0] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [1] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [2] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [3] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [4] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [5] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [6] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [7] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [8] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [9] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xDD Please select the subject corresponding to the number to be enrollled \xAF ");
    scanf("%i", &Subject_Selector);
    //Continue Function...
}
int Stdnt_1stYear_CpE_SecondSem()
{
    int Subject_Selector;
    char *Subject_FullNameEncoded[11];
    char *Subject_FullNameEncode_Bool[11];
    char *Subject_Units[11];
    char *Subject_LinearTime[12] = {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-"};
    system("CLS");
    gotoxy(30, 3);
    printf("\xC9\xCD\xCD CURRENT PROGRESS \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
    gotoxy(30, 4);
    printf("\xBA 1st | 2nd | \xDD [3rd Subject Enrollment Selection] | 4th | 5th | Confirm | End\t\t           \xBA\n");
    gotoxy(30, 5);
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xBA [0] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [1] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [2] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [3] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [4] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [5] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [6] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [7] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [8] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [9] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xDD Please select the subject corresponding to the number to be enrolled \xAF ");
    scanf("%i", &Subject_Selector);
    //Continue Function...
}
int Stdnt_2ndYear_CpE_FirstSem()
{
    int Subject_Selector;
    char *Subject_FullNameEncoded[11];
    char *Subject_FullNameEncode_Bool[11];
    char *Subject_Units[11];
    char *Subject_LinearTime[12] = {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-"};
    system("CLS");
    gotoxy(30, 3);
    printf("\xC9\xCD\xCD CURRENT PROGRESS \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
    gotoxy(30, 4);
    printf("\xBA 1st | 2nd | \xDD [3rd Subject Enrollment Selection] | 4th | 5th | Confirm | End\t\t           \xBA\n");
    gotoxy(30, 5);
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xBA [0] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [1] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [2] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [3] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [4] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [5] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [6] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [7] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [8] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [9] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xDD Please select the subject corresponding to the number to be enrolled \xAF ");
    scanf("%i", &Subject_Selector);
    //Continue Function...
}
int Stdnt_2ndYear_CpE_SecondSem()
{
    int Subject_Selector;
    char *Subject_FullNameEncoded[11];
    char *Subject_FullNameEncode_Bool[11];
    char *Subject_Units[11];
    char *Subject_LinearTime[12] = {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-"};
    system("CLS");
    gotoxy(30, 3);
    printf("\xC9\xCD\xCD CURRENT PROGRESS \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
    gotoxy(30, 4);
    printf("\xBA 1st | 2nd | \xDD [3rd Subject Enrollment Selection] | 4th | 5th | Confirm | End\t\t           \xBA\n");
    gotoxy(30, 5);
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xBA [ ] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [ ] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [ ] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [ ] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [ ] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [ ] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [ ] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [ ] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [ ] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [ ] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
}
int Stdnt_3rdYear_CpE_FirstSem()
{
    int Subject_Selector;
    char *Subject_FullNameEncoded[11];
    char *Subject_FullNameEncode_Bool[11];
    char *Subject_Units[11];
    char *Subject_LinearTime[12] = {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-"};
    system("CLS");
    gotoxy(30, 3);
    printf("\xC9\xCD\xCD CURRENT PROGRESS \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
    gotoxy(30, 4);
    printf("\xBA 1st | 2nd | \xDD [3rd Subject Enrollment Selection] | 4th | 5th | Confirm | End\t\t           \xBA\n");
    gotoxy(30, 5);
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xBA [0] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [1] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [2] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [3] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [4] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [5] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [6] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [7] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [8] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [9] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xDD Please select the subject corresponding to the number to be enrolled \xAF ");
    scanf("%i", &Subject_Selector);
    //Continue Function...
}
int Stdnt_3rdYear_CpE_SecondSem()
{
    int Subject_Selector;
    char *Subject_FullNameEncoded[11];
    char *Subject_FullNameEncode_Bool[11];
    char *Subject_Units[11];
    char *Subject_LinearTime[12] = {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-"};
    system("CLS");
    gotoxy(30, 3);
    printf("\xC9\xCD\xCD CURRENT PROGRESS \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
    gotoxy(30, 4);
    printf("\xBA 1st | 2nd | \xDD [3rd Subject Enrollment Selection] | 4th | 5th | Confirm | End\t\t           \xBA\n");
    gotoxy(30, 5);
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xBA [0] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [1] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [2] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [3] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [4] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [5] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [6] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [7] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [8] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [9] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xDD Please select the subject corresponding to the number to be enrolled \xAF ");
    scanf("%i", &Subject_Selector);
    //Continue Function...
}
int Stdnt_4thYear_CpE_FirstSem()
{
    int Subject_Selector;
    char *Subject_FullNameEncoded[11];
    char *Subject_FullNameEncode_Bool[11];
    char *Subject_Units[11];
    char *Subject_LinearTime[12] = {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-"};
    system("CLS");
    gotoxy(30, 3);
    printf("\xC9\xCD\xCD CURRENT PROGRESS \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
    gotoxy(30, 4);
    printf("\xBA 1st | 2nd | \xDD [3rd Subject Enrollment Selection] | 4th | 5th | Confirm | End\t\t           \xBA\n");
    gotoxy(30, 5);
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xBA [0] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [1] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [2] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [3] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [4] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [5] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [6] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [7] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [8] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [9] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xDD Please select the subject corresponding to the number to be enrolled \xAF ");
    scanf("%i", &Subject_Selector);
    //Continue Function...
}
int Stdnt_4thYear_CpE_SecondSem()
{
    int Subject_Selector;
    char *Subject_FullNameEncoded[11];
    char *Subject_FullNameEncode_Bool[11];
    char *Subject_Units[11];
    char *Subject_LinearTime[12] = {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-"};
    system("CLS");
    gotoxy(30, 3);
    printf("\xC9\xCD\xCD CURRENT PROGRESS \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
    gotoxy(30, 4);
    printf("\xBA 1st | 2nd | \xDD [3rd Subject Enrollment Selection] | 4th | 5th | Confirm | End\t\t           \xBA\n");
    gotoxy(30, 5);
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xBA [0] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [1] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [2] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [3] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [4] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [5] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [6] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [7] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [8] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [9] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xDD Please select the subject corresponding to the number to be enrollled \xAF ");
    scanf("%i", &Subject_Selector);
    //Continue Function...
}
// Electrical Engineer Selection Functions for Enrollment
int Stdnt_1stYear_EE_FirstSem()
{
    int Subject_Selector;
    char *Subject_FullNameEncoded[11];
    char *Subject_FullNameEncode_Bool[11];
    char *Subject_Units[11];
    char *Subject_LinearTime[12] = {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-"};
    system("CLS");
    gotoxy(30, 3);
    printf("\xC9\xCD\xCD CURRENT PROGRESS \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
    gotoxy(30, 4);
    printf("\xBA 1st | 2nd | \xDD [3rd Subject Enrollment Selection] | 4th | 5th | Confirm | End\t\t           \xBA\n");
    gotoxy(30, 5);
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xBA [0] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [1] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [2] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [3] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [4] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [5] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [6] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [7] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [8] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [9] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xDD Please select the subject corresponding to the number to be enrolled \xAF ");
    scanf("%i", &Subject_Selector);
    //Continue Function...
}
int Stdnt_1stYear_EE_SecondSem()
{
    int Subject_Selector;
    char *Subject_FullNameEncoded[11];
    char *Subject_FullNameEncode_Bool[11];
    char *Subject_Units[11];
    char *Subject_LinearTime[12] = {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-"};
    system("CLS");
    gotoxy(30, 3);
    printf("\xC9\xCD\xCD CURRENT PROGRESS \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
    gotoxy(30, 4);
    printf("\xBA 1st | 2nd | \xDD [3rd Subject Enrollment Selection] | 4th | 5th | Confirm | End\t\t           \xBA\n");
    gotoxy(30, 5);
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xBA [0] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [1] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [2] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [3] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [4] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [5] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [6] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [7] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [8] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [9] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xDD Please select the subject corresponding to the number to be enrolled \xAF ");
    scanf("%i", &Subject_Selector);
    //Continue Function...
}
int Stdnt_2ndYear_EE_FirstSem()
{
    int Subject_Selector;
    char *Subject_FullNameEncoded[11];
    char *Subject_FullNameEncode_Bool[11];
    char *Subject_Units[11];
    char *Subject_LinearTime[12] = {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-"};
    system("CLS");
    gotoxy(30, 3);
    printf("\xC9\xCD\xCD CURRENT PROGRESS \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
    gotoxy(30, 4);
    printf("\xBA 1st | 2nd | \xDD [3rd Subject Enrollment Selection] | 4th | 5th | Confirm | End\t\t           \xBA\n");
    gotoxy(30, 5);
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xBA [0] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [1] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [2] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [3] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [4] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [5] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [6] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [7] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [8] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [9] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xDD Please select the subject corresponding to the number to be enrolled \xAF ");
    scanf("%i", &Subject_Selector);
    //Continue Function...
}
int Stdnt_2ndYear_EE_SecondSem()
{
    int Subject_Selector;
    char *Subject_FullNameEncoded[11];
    char *Subject_FullNameEncode_Bool[11];
    char *Subject_Units[11];
    char *Subject_LinearTime[12] = {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-"};
    system("CLS");
    gotoxy(30, 3);
    printf("\xC9\xCD\xCD CURRENT PROGRESS \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
    gotoxy(30, 4);
    printf("\xBA 1st | 2nd | \xDD [3rd Subject Enrollment Selection] | 4th | 5th | Confirm | End\t\t           \xBA\n");
    gotoxy(30, 5);
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xBA [0] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [1] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [2] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [3] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [4] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [5] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [6] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [7] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [8] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [9] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xDD Please select the subject corresponding to the number to be enrolled \xAF ");
    scanf("%i", &Subject_Selector);
    //Continue Function...
}
int Stdnt_3rdYear_EE_FirstSem()
{
    int Subject_Selector;
    char *Subject_FullNameEncoded[11];
    char *Subject_FullNameEncode_Bool[11];
    char *Subject_Units[11];
    char *Subject_LinearTime[12] = {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-"};
    system("CLS");
    gotoxy(30, 3);
    printf("\xC9\xCD\xCD CURRENT PROGRESS \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
    gotoxy(30, 4);
    printf("\xBA 1st | 2nd | \xDD [3rd Subject Enrollment Selection] | 4th | 5th | Confirm | End\t\t           \xBA\n");
    gotoxy(30, 5);
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xBA [0] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [1] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [2] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [3] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [4] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [5] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [6] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [7] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [8] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [9] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xDD Please select the subject corresponding to the number to be enrolled \xAF ");
    scanf("%i", &Subject_Selector);
    //Continue Function...
}
int Stdnt_3rdYear_EE_SecondSem()
{
    int Subject_Selector;
    char *Subject_FullNameEncoded[11];
    char *Subject_FullNameEncode_Bool[11];
    char *Subject_Units[11];
    char *Subject_LinearTime[12] = {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-"};
    system("CLS");
    gotoxy(30, 3);
    printf("\xC9\xCD\xCD CURRENT PROGRESS \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
    gotoxy(30, 4);
    printf("\xBA 1st | 2nd | \xDD [3rd Subject Enrollment Selection] | 4th | 5th | Confirm | End\t\t           \xBA\n");
    gotoxy(30, 5);
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xBA [0] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [1] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [2] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [3] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [4] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [5] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [6] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [7] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [8] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [9] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xDD Please select the subject corresponding to the number to be enrolled \xAF ");
    scanf("%i", &Subject_Selector);
    //Continue Function...
}
int Stdnt_4thYear_EE_FirstSem()
{
    int Subject_Selector;
    char *Subject_FullNameEncoded[11];
    char *Subject_FullNameEncode_Bool[11];
    char *Subject_Units[11];
    char *Subject_LinearTime[12] = {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-"};
    system("CLS");
    gotoxy(30, 3);
    printf("\xC9\xCD\xCD CURRENT PROGRESS \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
    gotoxy(30, 4);
    printf("\xBA 1st | 2nd | \xDD [3rd Subject Enrollment Selection] | 4th | 5th | Confirm | End\t\t           \xBA\n");
    gotoxy(30, 5);
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xBA [0] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [1] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [2] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [3] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [4] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [5] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [6] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [7] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [8] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [9] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xDD Please select the subject corresponding to the number to be enrolled \xAF ");
    scanf("%i", &Subject_Selector);
    //Continue Function...
}
int Stdnt_4thYear_EE_SecondSem()
{
    int Subject_Selector;
    char *Subject_FullNameEncoded[11];
    char *Subject_FullNameEncode_Bool[11];
    char *Subject_Units[11];
    char *Subject_LinearTime[12] = {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-"};
    system("CLS");
    gotoxy(30, 3);
    printf("\xC9\xCD\xCD CURRENT PROGRESS \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
    gotoxy(30, 4);
    printf("\xBA 1st | 2nd | \xDD [3rd Subject Enrollment Selection] | 4th | 5th | Confirm | End\t\t           \xBA\n");
    gotoxy(30, 5);
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xBA [0] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [1] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [2] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [3] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [4] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [5] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [6] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [7] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [8] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [9] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xDD Please select the subject corresponding to the number to be enrolled \xAF ");
    scanf("%i", &Subject_Selector);
    //Continue Function...
}
// Electronics Engineer Selection Functions for Enrollment
int Stdnt_1stYear_ECE_FirstSem()
{
    system("CLS");
    gotoxy(30, 3);
    int Subject_Selector;
    char *Subject_FullNameEncoded[10];
    char *Subject_FullNameEncode_Bool[11];
    char *Subject_Units[11];
    char *Subject_LinearTime[12] = {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-"};
    printf("\xC9\xCD\xCD CURRENT PROGRESS \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
    gotoxy(30, 4);
    printf("\xBA 1st | 2nd | \xDD [3rd Subject Enrollment Selection] | 4th | 5th | Confirm | End\t\t           \xBA\n");
    gotoxy(30, 5);
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xBA [0] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [1] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [2] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [3] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [4] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [5] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [6] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [7] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [8] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [9] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xDD Please select the subject corresponding to the number to be enrolled \xAF ");
    scanf("%i", &Subject_Selector);
    //Continue F\tunct\t Subject.TimeLineari\t\xDD\t n...
}
int Stdnt_1stYear_ECE_SecondSem()
{
    int Subject_Selector;
    char *Subject_FullNameEncoded[11];
    char *Subject_FullNameEncode_Bool[11];
    char *Subject_Units[11];
    char *Subject_LinearTime[12] = {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-"};
    system("CLS");
    gotoxy(30, 3);
    printf("\xC9\xCD\xCD CURRENT PROGRESS \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
    gotoxy(30, 4);
    printf("\xBA 1st | 2nd | \xDD [3rd Subject Enrollment Selection] | 4th | 5th | Confirm | End\t\t           \xBA\n");
    gotoxy(30, 5);
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xBA [0] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [1] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [2] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [3] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [4] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [5] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [6] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [7] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [8] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [9] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xDD Please select the subject corresponding to the number to be enrolled \xAF ");
    scanf("%i", &Subject_Selector);
    //Continue Function...
}
int Stdnt_2ndYear_ECE_FirstSem()
{
    int Subject_Selector;
    char *Subject_FullNameEncoded[11];
    char *Subject_FullNameEncode_Bool[11];
    char *Subject_Units[11];
    char *Subject_LinearTime[12] = {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-"};
    system("CLS");
    gotoxy(30, 3);
    printf("\xC9\xCD\xCD CURRENT PROGRESS \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
    gotoxy(30, 4);
    printf("\xBA 1st | 2nd | \xDD [3rd Subject Enrollment Selection] | 4th | 5th | Confirm | End\t\t           \xBA\n");
    gotoxy(30, 5);
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xBA [0] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [1] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [2] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [3] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [4] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [5] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [6] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [7] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [8] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [9] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xDD Please select the subject corresponding to the number to be enrolled \xAF ");
    scanf("%i", &Subject_Selector);
    //Continue Function...
}
int Stdnt_2ndYear_ECE_SecondSem()
{
    int Subject_Selector;
    char *Subject_FullNameEncoded[11];
    char *Subject_FullNameEncode_Bool[11];
    char *Subject_Units[11];
    char *Subject_LinearTime[12] = {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-"};
    system("CLS");
    gotoxy(30, 3);
    printf("\xC9\xCD\xCD CURRENT PROGRESS \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
    gotoxy(30, 4);
    printf("\xBA 1st | 2nd | \xDD [3rd Subject Enrollment Selection] | 4th | 5th | Confirm | End\t\t           \xBA\n");
    gotoxy(30, 5);
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xBA [0] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [1] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [2] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [3] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [4] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [5] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [6] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [7] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [8] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [9] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xDD Please select the subject corresponding to the number to be enrolled \xAF ");
    scanf("%i", &Subject_Selector);
    //Continue Function...
}
int Stdnt_3rdYear_ECE_FirstSem()
{
    int Subject_Selector;
    char *Subject_FullNameEncoded[11];
    char *Subject_FullNameEncode_Bool[11];
    char *Subject_Units[11];
    char *Subject_LinearTime[12] = {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-"};
    system("CLS");
    gotoxy(30, 3);
    printf("\xC9\xCD\xCD CURRENT PROGRESS \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
    gotoxy(30, 4);
    printf("\xBA 1st | 2nd | \xDD [3rd Subject Enrollment Selection] | 4th | 5th | Confirm | End\t\t           \xBA\n");
    gotoxy(30, 5);
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xBA [0] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [1] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [2] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [3] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [4] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [5] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [6] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [7] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [8] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [9] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xDD Please select the subject corresponding to the number to be enrolled \xAF ");
    scanf("%i", &Subject_Selector);
    //Continue Function...
}
int Stdnt_3rdYear_ECE_SecondSem()
{
    int Subject_Selector;
    char *Subject_FullNameEncoded[11];
    char *Subject_FullNameEncode_Bool[11];
    char *Subject_Units[11];
    char *Subject_LinearTime[12] = {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-"};
    system("CLS");
    gotoxy(30, 3);
    printf("\xC9\xCD\xCD CURRENT PROGRESS \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
    gotoxy(30, 4);
    printf("\xBA 1st | 2nd | \xDD [3rd Subject Enrollment Selection] | 4th | 5th | Confirm | End\t\t           \xBA\n");
    gotoxy(30, 5);
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xBA [0] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [1] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [2] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [3] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [4] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [5] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [6] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [7] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [8] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [9] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xDD Please select the subject corresponding to the number to be enrolled \xAF ");
    scanf("%i", &Subject_Selector);
    //Continue Function...
}
int Stdnt_4thYear_ECE_FirstSem()
{
    int Subject_Selector;
    char *Subject_FullNameEncoded[11];
    char *Subject_FullNameEncode_Bool[11];
    char *Subject_Units[11];
    char *Subject_LinearTime[12] = {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-"};
    system("CLS");
    gotoxy(30, 3);
    printf("\xC9\xCD\xCD CURRENT PROGRESS \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
    gotoxy(30, 4);
    printf("\xBA 1st | 2nd | \xDD [3rd Subject Enrollment Selection] | 4th | 5th | Confirm | End\t\t           \xBA\n");
    gotoxy(30, 5);
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xBA [0] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [1] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [2] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [3] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [4] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [5] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [6] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [7] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [8] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [9] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xDD Please select the subject corresponding to the number to be enrolled \xAF ");
    scanf("%i", &Subject_Selector);
    //Continue Function...
}
int Stdnt_4thYear_ECE_SecondSem()
{
    int Subject_Selector;
    char *Subject_FullNameEncoded[11];
    char *Subject_FullNameEncode_Bool[11];
    char *Subject_Units[11];
    char *Subject_LinearTime[12] = {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-"};
    system("CLS");
    gotoxy(30, 3);
    printf("\xC9\xCD\xCD CURRENT PROGRESS \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
    gotoxy(30, 4);
    printf("\xBA 1st | 2nd | \xDD [3rd Subject Enrollment Selection] | 4th | 5th | Confirm | End\t\t           \xBA\n");
    gotoxy(30, 5);
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xBA [0] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [1] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [2] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [3] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [4] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [5] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [6] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [7] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [8] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [9] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xDD Please select the subject corresponding to the number to be enrolled \xAF ");
    scanf("%i", &Subject_Selector);
    //Continue Function...
}
// Environmental and Sanitary Engineer Selection Functions for Enrollment
int Stdnt_1stYear_EnSE_FirstSem()
{
    int Subject_Selector;
    char *Subject_FullNameEncoded[11];
    char *Subject_FullNameEncode_Bool[11];
    char *Subject_Units[11];
    char *Subject_LinearTime[12] = {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-"};
    system("CLS");
    gotoxy(30, 3);
    printf("\xC9\xCD\xCD CURRENT PROGRESS \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
    gotoxy(30, 4);
    printf("\xBA 1st | 2nd | \xDD [3rd Subject Enrollment Selection] | 4th | 5th | Confirm | End\t\t           \xBA\n");
    gotoxy(30, 5);
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xBA [0] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [1] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [2] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [3] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [4] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [5] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [6] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [7] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [8] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [9] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xDD Please select the subject corresponding to the number to be enrolled \xAF ");
    scanf("%i", &Subject_Selector);
    //Continue Function...
}
int Stdnt_1stYear_EnSE_SecondSem()
{
    int Subject_Selector;
    char *Subject_FullNameEncoded[11];
    char *Subject_FullNameEncode_Bool[11];
    char *Subject_Units[11];
    char *Subject_LinearTime[12] = {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-"};
    system("CLS");
    gotoxy(30, 3);
    printf("\xC9\xCD\xCD CURRENT PROGRESS \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
    gotoxy(30, 4);
    printf("\xBA 1st | 2nd | \xDD [3rd Subject Enrollment Selection] | 4th | 5th | Confirm | End\t\t           \xBA\n");
    gotoxy(30, 5);
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xBA [0] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [1] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [2] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [3] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [4] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [5] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [6] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [7] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [8] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [9] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xDD Please select the subject corresponding to the number to be enrolled \xAF ");
    scanf("%i", &Subject_Selector);
    //Continue Function...
}
int Stdnt_2ndYear_EnSE_FirstSem()
{
    int Subject_Selector;
    char *Subject_FullNameEncoded[11];
    char *Subject_FullNameEncode_Bool[11];
    char *Subject_Units[11];
    char *Subject_LinearTime[12] = {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-"};
    system("CLS");
    gotoxy(30, 3);
    printf("\xC9\xCD\xCD CURRENT PROGRESS \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
    gotoxy(30, 4);
    printf("\xBA 1st | 2nd | \xDD [3rd Subject Enrollment Selection] | 4th | 5th | Confirm | End\t\t           \xBA\n");
    gotoxy(30, 5);
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xBA [0] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [1] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [2] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [3] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [4] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [5] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [6] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [7] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [8] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [9] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xDD Please select the subject corresponding to the number to be enrollled \xAF ");
    scanf("%i", &Subject_Selector);
    //Continue Function...
}
int Stdnt_2ndYear_EnSE_SecondSem()
{
    int Subject_Selector;
    char *Subject_FullNameEncoded[11];
    char *Subject_FullNameEncode_Bool[11];
    char *Subject_Units[11];
    char *Subject_LinearTime[12] = {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-"};
    system("CLS");
    gotoxy(30, 3);
    printf("\xC9\xCD\xCD CURRENT PROGRESS \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
    gotoxy(30, 4);
    printf("\xBA 1st | 2nd | \xDD [3rd Subject Enrollment Selection] | 4th | 5th | Confirm | End\t\t           \xBA\n");
    gotoxy(30, 5);
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xBA [0] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [1] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [2] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [3] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [4] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [5] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [6] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [7] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [8] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [9] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xDD Please select the subject corresponding to the number to be enrolled \xAF ");
    scanf("%i", &Subject_Selector);
    //Continue Function...
}
int Stdnt_3rdYear_EnSE_FirstSem()
{
    int Subject_Selector;
    char *Subject_FullNameEncoded[11];
    char *Subject_FullNameEncode_Bool[11];
    char *Subject_Units[11];
    char *Subject_LinearTime[12] = {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-"};
    system("CLS");
    gotoxy(30, 3);
    printf("\xC9\xCD\xCD CURRENT PROGRESS \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
    gotoxy(30, 4);
    printf("\xBA 1st | 2nd | \xDD [3rd Subject Enrollment Selection] | 4th | 5th | Confirm | End\t\t           \xBA\n");
    gotoxy(30, 5);
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xBA [0] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [1] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [2] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [3] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [4] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [5] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [6] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [7] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [8] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [9] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xDD Please select the subject corresponding to the number to be enrolled \xAF ");
    scanf("%i", &Subject_Selector);
    //Continue Function...
}
int Stdnt_3rdYear_EnSE_SecondSem()
{
    int Subject_Selector;
    char *Subject_FullNameEncoded[11];
    char *Subject_FullNameEncode_Bool[11];
    char *Subject_Units[11];
    char *Subject_LinearTime[12] = {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-"};
    system("CLS");
    gotoxy(30, 3);
    printf("\xC9\xCD\xCD CURRENT PROGRESS \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
    gotoxy(30, 4);
    printf("\xBA 1st | 2nd | \xDD [3rd Subject Enrollment Selection] | 4th | 5th | Confirm | End\t\t           \xBA\n");
    gotoxy(30, 5);
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xBA [0] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [1] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [2] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [3] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [4] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [5] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [6] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [7] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [8] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [9] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xDD Please select the subject corresponding to the number to be enrolled \xAF ");
    scanf("%i", &Subject_Selector);
    //Continue Function...
}
int Stdnt_4thYear_EnSE_FirstSem()
{
    int Subject_Selector;
    char *Subject_FullNameEncoded[11];
    char *Subject_FullNameEncode_Bool[11];
    char *Subject_Units[11];
    char *Subject_LinearTime[12] = {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-"};
    system("CLS");
    gotoxy(30, 3);
    printf("\xC9\xCD\xCD CURRENT PROGRESS \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
    gotoxy(30, 4);
    printf("\xBA 1st | 2nd | \xDD [3rd Subject Enrollment Selection] | 4th | 5th | Confirm | End\t\t           \xBA\n");
    gotoxy(30, 5);
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xBA [0] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [1] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [2] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [3] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [4] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [5] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [6] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [7] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [8] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [9] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xDD Please select the subject corresponding to the number to be enrolled \xAF ");
    scanf("%i", &Subject_Selector);
    //Continue Function...
}
int Stdnt_4thYear_EnSE_SecondSem()
{
    int Subject_Selector;
    char *Subject_FullNameEncoded[11];
    char *Subject_FullNameEncode_Bool[11];
    char *Subject_Units[11];
    char *Subject_LinearTime[12] = {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-"};
    system("CLS");
    gotoxy(30, 3);
    printf("\xC9\xCD\xCD CURRENT PROGRESS \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
    gotoxy(30, 4);
    printf("\xBA 1st | 2nd | \xDD [3rd Subject Enrollment Selection] | 4th | 5th | Confirm | End\t\t           \xBA\n");
    gotoxy(30, 5);
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xBA [0] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [1] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [2] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [3] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [4] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [5] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [6] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [7] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [8] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [9] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xDD Please select the subject corresponding to the number to be enrolled \xAF ");
    scanf("%i", &Subject_Selector);
    //Continue Function...
}
// Industrial Engineer Selection Functions for Enrollment
int Stdnt_1stYear_IE_FirstSem()
{
    int Subject_Selector;
    char *Subject_FullNameEncoded[11];
    char *Subject_FullNameEncode_Bool[11];
    char *Subject_Units[11];
    char *Subject_LinearTime[12] = {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-"};
    system("CLS");
    gotoxy(30, 3);
    printf("\xC9\xCD\xCD CURRENT PROGRESS \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
    gotoxy(30, 4);
    printf("\xBA 1st | 2nd | \xDD [3rd Subject Enrollment Selection] | 4th | 5th | Confirm | End\t\t           \xBA\n");
    gotoxy(30, 5);
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xBA [0] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [1] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [2] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [3] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [4] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [5] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [6] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [7] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [8] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [9] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xDD Please select the subject corresponding to the number to be enrolled \xAF ");
    scanf("%i", &Subject_Selector);
    //Continue Function...
}
int Stdnt_1stYear_IE_SecondSem()
{
    int Subject_Selector;
    char *Subject_FullNameEncoded[11];
    char *Subject_FullNameEncode_Bool[11];
    char *Subject_Units[11];
    char *Subject_LinearTime[12] = {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-"};
    system("CLS");
    gotoxy(30, 3);
    printf("\xC9\xCD\xCD CURRENT PROGRESS \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
    gotoxy(30, 4);
    printf("\xBA 1st | 2nd | \xDD [3rd Subject Enrollment Selection] | 4th | 5th | Confirm | End\t\t           \xBA\n");
    gotoxy(30, 5);
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xBA [0] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [1] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [2] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [3] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [4] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [5] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [6] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [7] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [8] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [9] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xDD Please select the subject corresponding to the number to be enrolled \xAF ");
    scanf("%i", &Subject_Selector);
    //Continue Function...
}
int Stdnt_2ndYear_IE_FirstSem()
{
    int Subject_Selector;
    char *Subject_FullNameEncoded[11];
    char *Subject_FullNameEncode_Bool[11];
    char *Subject_Units[11];
    char *Subject_LinearTime[12] = {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-"};
    system("CLS");
    gotoxy(30, 3);
    printf("\xC9\xCD\xCD CURRENT PROGRESS \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
    gotoxy(30, 4);
    printf("\xBA 1st | 2nd | \xDD [3rd Subject Enrollment Selection] | 4th | 5th | Confirm | End\t\t           \xBA\n");
    gotoxy(30, 5);
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xBA [0] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [1] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [2] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [3] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [4] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [5] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [6] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [7] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [8] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [9] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xDD Please select the subject corresponding to the number to be enrolled \xAF ");
    scanf("%i", &Subject_Selector);
    //Continue Function...
}
int Stdnt_2ndYear_IE_SecondSem()
{
    int Subject_Selector;
    char *Subject_FullNameEncoded[11];
    char *Subject_FullNameEncode_Bool[11];
    char *Subject_Units[11];
    char *Subject_LinearTime[12] = {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-"};
    system("CLS");
    gotoxy(30, 3);
    printf("\xC9\xCD\xCD CURRENT PROGRESS \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
    gotoxy(30, 4);
    printf("\xBA 1st | 2nd | \xDD [3rd Subject Enrollment Selection] | 4th | 5th | Confirm | End\t\t           \xBA\n");
    gotoxy(30, 5);
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xBA [0] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [1] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [2] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [3] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [4] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [5] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [6] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [7] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [8] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [9] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xDD Please select the subject corresponding to the number to be enrolled \xAF ");
    scanf("%i", &Subject_Selector);
    //Continue Function...
}
int Stdnt_3rdYear_IE_FirstSem()
{
    int Subject_Selector;
    char *Subject_FullNameEncoded[11];
    char *Subject_FullNameEncode_Bool[11];
    char *Subject_Units[11];
    char *Subject_LinearTime[12] = {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-"};
    system("CLS");
    gotoxy(30, 3);
    printf("\xC9\xCD\xCD CURRENT PROGRESS \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
    gotoxy(30, 4);
    printf("\xBA 1st | 2nd | \xDD [3rd Subject Enrollment Selection] | 4th | 5th | Confirm | End\t\t           \xBA\n");
    gotoxy(30, 5);
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xBA [0] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [1] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [2] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [3] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [4] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [5] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [6] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [7] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [8] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [9] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xDD Please select the subject corresponding to the number to be enrolled \xAF ");
    scanf("%i", &Subject_Selector);
    //Continue Function...
}
int Stdnt_3rdYear_IE_SecondSem()
{
    int Subject_Selector;
    char *Subject_FullNameEncoded[11];
    char *Subject_FullNameEncode_Bool[11];
    char *Subject_Units[11];
    char *Subject_LinearTime[12] = {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-"};
    system("CLS");
    gotoxy(30, 3);
    printf("\xC9\xCD\xCD CURRENT PROGRESS \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
    gotoxy(30, 4);
    printf("\xBA 1st | 2nd | \xDD [3rd Subject Enrollment Selection] | 4th | 5th | Confirm | End\t\t           \xBA\n");
    gotoxy(30, 5);
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xBA [0] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [1] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [2] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [3] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [4] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [5] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [6] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [7] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [8] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [9] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xDD Please select the subject corresponding to the number to be enrolled \xAF ");
    scanf("%i", &Subject_Selector);
    //Continue Function...
}
int Stdnt_4thYear_IE_FirstSem()
{
    int Subject_Selector;
    char *Subject_FullNameEncoded[11];
    char *Subject_FullNameEncode_Bool[11];
    char *Subject_Units[11];
    char *Subject_LinearTime[12] = {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-"};
    system("CLS");
    gotoxy(30, 3);
    printf("\xC9\xCD\xCD CURRENT PROGRESS \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
    gotoxy(30, 4);
    printf("\xBA 1st | 2nd | \xDD [3rd Subject Enrollment Selection] | 4th | 5th | Confirm | End\t\t           \xBA\n");
    gotoxy(30, 5);
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xBA [0] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [1] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [2] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [3] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [4] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [5] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [6] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [7] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [8] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [9] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xDD Please select the subject corresponding to the number to be enrolled \xAF ");
    scanf("%i", &Subject_Selector);
    //Continue Function...
}
int Stdnt_4thYear_IE_SecondSem()
{
    int Subject_Selector;
    char *Subject_FullNameEncoded[11];
    char *Subject_FullNameEncode_Bool[11];
    char *Subject_Units[11];
    char *Subject_LinearTime[12] = {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-"};
    system("CLS");
    gotoxy(30, 3);
    printf("\xC9\xCD\xCD CURRENT PROGRESS \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
    gotoxy(30, 4);
    printf("\xBA 1st | 2nd | \xDD [3rd Subject Enrollment Selection] | 4th | 5th | Confirm | End\t\t           \xBA\n");
    gotoxy(30, 5);
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xBA [0] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [1] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [2] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [3] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [4] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [5] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [6] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [7] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [8] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [9] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xDD Please select the subject corresponding to the number to be enrolled \xAF ");
    scanf("%i", &Subject_Selector);
    //Continue Function...
}
// Mechanical Engineer Selection Functions for Enrollment
int Stdnt_1stYear_ME_FirstSem()
{
    int Subject_Selector;
    char *Subject_FullNameEncoded[11];
    char *Subject_FullNameEncode_Bool[11];
    char *Subject_Units[11];
    char *Subject_LinearTime[12] = {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-"};
    system("CLS");
    gotoxy(30, 3);
    printf("\xC9\xCD\xCD CURRENT PROGRESS \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
    gotoxy(30, 4);
    printf("\xBA 1st | 2nd | \xDD [3rd Subject Enrollment Selection] | 4th | 5th | Confirm | End\t\t           \xBA\n");
    gotoxy(30, 5);
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xBA [0] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [1] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [2] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [3] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [4] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [5] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [6] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [7] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [8] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [9] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xDD Please select the subject corresponding to the number to be enrolled \xAF ");
    scanf("%i", &Subject_Selector);
    //Continue Function...
}
int Stdnt_1stYear_ME_SecondSem()
{
    int Subject_Selector;
    char *Subject_FullNameEncoded[11];
    char *Subject_FullNameEncode_Bool[11];
    char *Subject_Units[11];
    char *Subject_LinearTime[12] = {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-"};
    system("CLS");
    gotoxy(30, 3);
    printf("\xC9\xCD\xCD CURRENT PROGRESS \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
    gotoxy(30, 4);
    printf("\xBA 1st | 2nd | \xDD [3rd Subject Enrollment Selection] | 4th | 5th | Confirm | End\t\t           \xBA\n");
    gotoxy(30, 5);
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xBA [0] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [1] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [2] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [3] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [4] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [5] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [6] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [7] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [8] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [9] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xDD Please select the subject corresponding to the number to be enrolled \xAF ");
    scanf("%i", &Subject_Selector);
    //Continue Function...
}
int Stdnt_2ndYear_ME_FirstSem()
{
    int Subject_Selector;
    char *Subject_FullNameEncoded[11];
    char *Subject_FullNameEncode_Bool[11];
    char *Subject_Units[11];
    char *Subject_LinearTime[12] = {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-"};
    system("CLS");
    gotoxy(30, 3);
    printf("\xC9\xCD\xCD CURRENT PROGRESS \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
    gotoxy(30, 4);
    printf("\xBA 1st | 2nd | \xDD [3rd Subject Enrollment Selection] | 4th | 5th | Confirm | End\t\t           \xBA\n");
    gotoxy(30, 5);
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xBA [0] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [1] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [2] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [3] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [4] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [5] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [6] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [7] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [8] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [9] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xDD Please select the subject corresponding to the number to be enrolled \xAF ");
    scanf("%i", &Subject_Selector);
    //Continue Function...
}
int Stdnt_2ndYear_ME_SecondSem()
{
    int Subject_Selector;
    char *Subject_FullNameEncoded[11];
    char *Subject_FullNameEncode_Bool[11];
    char *Subject_Units[11];
    char *Subject_LinearTime[12] = {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-"};
    system("CLS");
    gotoxy(30, 3);
    printf("\xC9\xCD\xCD CURRENT PROGRESS \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
    gotoxy(30, 4);
    printf("\xBA 1st | 2nd | \xDD [3rd Subject Enrollment Selection] | 4th | 5th | Confirm | End\t\t           \xBA\n");
    gotoxy(30, 5);
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xBA [0] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [1] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [2] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [3] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [4] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [5] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [6] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [7] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [8] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [9] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xDD Please select the subject corresponding to the number to be enrolled \xAF ");
    scanf("%i", &Subject_Selector);
    //Continue Function...
}
int Stdnt_3rdYear_ME_FirstSem()
{
    int Subject_Selector;
    char *Subject_FullNameEncoded[11];
    char *Subject_FullNameEncode_Bool[11];
    char *Subject_Units[11];
    char *Subject_LinearTime[12] = {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-"};
    system("CLS");
    gotoxy(30, 3);
    printf("\xC9\xCD\xCD CURRENT PROGRESS \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
    gotoxy(30, 4);
    printf("\xBA 1st | 2nd | \xDD [3rd Subject Enrollment Selection] | 4th | 5th | Confirm | End\t\t           \xBA\n");
    gotoxy(30, 5);
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xBA [0] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [1] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [2] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [3] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [4] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [5] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [6] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [7] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [8] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [9] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xDD Please select the subject corresponding to the number to be enrolled \xAF ");
    scanf("%i", &Subject_Selector);
    //Continue Function...
}
int Stdnt_3rdYear_ME_SecondSem()
{
    int Subject_Selector;
    char *Subject_FullNameEncoded[11];
    char *Subject_FullNameEncode_Bool[11];
    char *Subject_Units[11];
    char *Subject_LinearTime[12] = {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-"};
    system("CLS");
    gotoxy(30, 3);
    printf("\xC9\xCD\xCD CURRENT PROGRESS \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
    gotoxy(30, 4);
    printf("\xBA 1st | 2nd | \xDD [3rd Subject Enrollment Selection] | 4th | 5th | Confirm | End\t\t           \xBA\n");
    gotoxy(30, 5);
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xBA [0] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [1] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [2] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [3] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [4] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [5] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [6] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [7] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [8] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [9] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xDD Please select the subject corresponding to the number to be enrolled \xAF ");
    scanf("%i", &Subject_Selector);
    //Continue Function...
}
int Stdnt_4thYear_ME_FirstSem()
{
    int Subject_Selector, Option_Selector;
    char *Subject_FullNameEncoded[11];
    char *Subject_FullNameEncode_Bool[11];
    char *Subject_Units[11];
    char *Subject_LinearTime[12] = {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-"};
    system("CLS");
    gotoxy(30, 3);
    printf("\xC9\xCD\xCD CURRENT PROGRESS \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
    gotoxy(30, 4);
    printf("\xBA 1st | 2nd | \xDD [3rd Subject Enrollment Selection] | 4th | 5th | Confirm | End\t\t                \xBA\n");
    gotoxy(30, 5);
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xBA [0] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [1] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [2] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [3] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [4] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [5] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [6] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [7] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [8] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xBA [9] \xAF Year.Subject \t\xDD\t Subject.TimeLinear \t\xDD\t Sem.Units\xBA\n");
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("\xDD Please select the subject corresponding to the number to be enrolled \xAF ");
    scanf("%i", &Subject_Selector);
    //Continue Function...
}
int Stdnt_4thYear_ME_SecondSem()
{
    int Subject_Selector, Option_Selector, Final_Comp_SelectedSubjects = 0, Final_Comp_SemUnits = 0, Subject_Counter = 0, SbjSel_Checker = 1, Subject_WholeSize = 12;
    int Subject_UnitsGuard_AntiDuplicate_Include[12] = {0};
    int Subject_UnitsGuard_AntiDuplicate_Exclude[12] = {0};
    int Subject_Units[12] = {3, 3, 3, 0, 1, 3, 0, 2, 2, 1, 2, 3};
    char Final_Decision_Selector;
    char *Subject_CodeName[12] = {"MATH 001", "MATH 002", "CHEM 001", "AR 001", "COE 001", "ENGL 001", "FIL 001", "PE 001", "NSTP 001", "MATH 004", "CPE 001", "HUMMS 001"};
    char *Subject_FullName[12] = {"---------", "---------", "---------", "---------", "---------", "---------", "---------", "---------", "---------", "---------", "---------", "---------"};
    char *Subject_Include[12] = {"Unknown", "Unknown", "Unknown", "Unknown", "Unknown", "Unknown", "Unknown", "Unknown", "Unknown", "Unknown", "Unknown", "Unknown"};
    char *Subject_Parameters[2] = {"Include", "Exclude"};
    char *Subject_LinearTime[12] = {"8:00AM - 9:30AM", "9:30AM - 10:30AM", "10:30AM - 11:30AM", "11:30AM - 1:30PM", "1:30PM - 2:30PM", "2:30PM - 3:30PM", "1:30PM - 4:30PM", "7:30AM - 9:30AM", "9:30AM - 12:00PM", "4:30PM - :5:30PM", "4:30PM - 6:30PM", "5:30PM - 6:30PM"};
    char *SbjSel_Stats[12] = {"Unknown", "Unknown", "Unknown", "Unknown", "Unknown", "Unknown", "Unknown", "Unknown", "Unknown", "Unknown", "Unknown", "Unknown"};
    system("CLS");
    int Counter = 0;
    SetConsoleTitle(FUNCTION_STEP3);
    struct Enrollment_InformationReceiver ReceiveData;
    while (1)
    {
        int Sbj_Stats_Increment = 0, Sbj_Stats_Decrement = 0, SbjSel_Stats_Exceptions = 0;
        system("CLS");
        gotoxy(30, 3);
        printf("\xC9\xCD\xCD \xDD CURRENT PROGRESS \xDD \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB");
        gotoxy(30, 4);
        printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
        gotoxy(30, 5);
        printf("\xBA 1st | 2nd | \xDD [3rd \xAF Subject Enrollment Selection] | 4th | 5th | Confirm | End\t\t                   \xBA");
        gotoxy(30, 6);
        printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
        gotoxy(30, 7);
        printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC");
        gotoxy(30, 8);
        printf("\n");
        gotoxy(30, 9);
        printf("\xC9\xCD\xCD \xDD SUBJECT LIST FOR 4TH YEAR MECHANICAL ENGINEERING \xAF SECOND SEMESTER \xDD \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB");
        gotoxy(30, 10);
        printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
        gotoxy(30, 11);
        printf("\xBA #    \xDD  STATUS  \xDD\tSUBJECT CODE - SUBJECT NAME\t  \xDD \tLINEAR TIME(START - END)    \xDD\t UNITS \t   \xBA\n");
        gotoxy(30, 12);
        printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
        gotoxy(30, 13);
        printf("\xCC\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xB9");
        gotoxy(30, 14);
        printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
        gotoxy(30, 15);
        printf("\xBA [1]  \xAF %s\t\xDD %s - %s \t\xDD\t %s \t\xDD\t %i\xBA", SbjSel_Stats[0], Subject_CodeName[0], Subject_FullName[0], Subject_LinearTime[0], Subject_Units[0]);
        gotoxy(30, 16);
        printf("\xBA [2]  \xAF %s\t\xDD %s - %s \t\xDD\t %s \t\xDD\t %i\xBA", SbjSel_Stats[1], Subject_CodeName[1], Subject_FullName[1], Subject_LinearTime[1], Subject_Units[1]);
        gotoxy(30, 17);
        printf("\xBA [3]  \xAF %s\t\xDD %s - %s \t\xDD\t %s \t\xDD\t %i\xBA", SbjSel_Stats[2], Subject_CodeName[2], Subject_FullName[2], Subject_LinearTime[2], Subject_Units[2]);
        gotoxy(30, 18);
        printf("\xBA [4]  \xAF %s\t\xDD %s - %s \t\xDD\t %s \t\xDD\t %i\xBA \t ", SbjSel_Stats[3], Subject_CodeName[3], Subject_FullName[3], Subject_LinearTime[3], Subject_Units[3]);
        gotoxy(30, 19);
        printf("\xBA [5]  \xAF %s\t\xDD %s - %s \t\xDD\t %s \t\xDD\t %i\xBA \t ", SbjSel_Stats[4], Subject_CodeName[4], Subject_FullName[4], Subject_LinearTime[4], Subject_Units[4]);
        gotoxy(30, 20);
        printf("\xBA [6]  \xAF %s\t\xDD %s - %s \t\xDD\t %s \t\xDD\t %i\xBA \t ", SbjSel_Stats[5], Subject_CodeName[5], Subject_FullName[5], Subject_LinearTime[5], Subject_Units[5]);
        gotoxy(30, 21);
        printf("\xBA [7]  \xAF %s\t\xDD %s - %s \t\xDD\t %s \t\xDD\t %i\xBA \t ", SbjSel_Stats[6], Subject_CodeName[6], Subject_FullName[6], Subject_LinearTime[6], Subject_Units[6]);
        gotoxy(30, 22);
        printf("\xBA [8]  \xAF %s\t\xDD %s - %s \t\xDD\t %s \t\xDD\t %i\xBA \t ", SbjSel_Stats[7], Subject_CodeName[7], Subject_FullName[7], Subject_LinearTime[7], Subject_Units[7]);
        gotoxy(30, 23);
        printf("\xBA [9]  \xAF %s\t\xDD %s - %s \t\xDD\t %s \t\xDD\t %i\xBA \t ", SbjSel_Stats[8], Subject_CodeName[8], Subject_FullName[8], Subject_LinearTime[8], Subject_Units[8]);
        gotoxy(30, 24);
        printf("\xBA [10] \xAF %s\t\xDD %s - %s \t\xDD\t %s \t\xDD\t %i\xBA \t ", SbjSel_Stats[9], Subject_CodeName[9], Subject_FullName[9], Subject_LinearTime[9], Subject_Units[9]);
        gotoxy(30, 25);
        printf("\xBA [11] \xAF %s\t\xDD %s - %s \t\xDD\t %s \t\xDD\t %i\xBA \t ", SbjSel_Stats[10], Subject_CodeName[10], Subject_FullName[10], Subject_LinearTime[10], Subject_Units[10]);
        gotoxy(30, 26);
        printf("\xBA [12] \xAF %s\t\xDD %s - %s \t\xDD\t %s \t\xDD\t %i\xBA \t ", SbjSel_Stats[11], Subject_CodeName[11], Subject_FullName[11], Subject_LinearTime[11], Subject_Units[11]);
        gotoxy(30, 27);
        printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
        gotoxy(30, 28);
        printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC");
        gotoxy(30, 30);
        printf("\xC9\xCD\xCD STATISTICS \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB");
        gotoxy(30, 31);
        printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
        gotoxy(30, 32);
        printf("\xBA \xDD Total Included Subject/s \xAF %d \t \xDD Total Included Units \xAF %d", Final_Comp_SelectedSubjects, Final_Comp_SemUnits);
        gotoxy(30, 33);
        printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
        gotoxy(30, 34);
        printf("\xCC\xCD\xCD OPTIONS FOR INPUT \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xB9");
        gotoxy(30, 35);
        printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
        gotoxy(30, 36);
        printf("\xBA Input '1' To Include Subject/s     \t\xDD      Input '-1' To Include All Subject/s                         \xBA");
        gotoxy(30, 37);
        printf("\xBA Input '2' To Withdraw Subject/s \t\xDD      Input '-2' To Exclude All Subject/s                         \xBA");
        gotoxy(30, 38);
        printf("\xBA Input '3' to process the data. \t\t\t\t\t\t\t\t\t\t   \xBA");
        gotoxy(30, 39);
        printf("\xBA\t\t\t\t\t\t\t\t\t\t\t\t\t           \xBA");
        gotoxy(30, 40);
        printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC");
        gotoxy(30, 42);
        printf("INPUT \xDD Please select an option \xAF ");
        scanf("%d", &Option_Selector);
        if (Option_Selector == 1)
        {
            gotoxy(30, 44);
            printf("Please select the subject number to be included \xAF ");
            scanf("%d", &Subject_Selector);
            if (Subject_Selector == 1)
            {
                if (Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] == 0)
                {
                    Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] = 0;
                    Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] = 1;
                    SbjSel_Stats[Subject_Selector - 1] = Subject_Parameters[0];
                    Final_Comp_SelectedSubjects += 1;
                    Final_Comp_SemUnits += Subject_Units[Subject_Selector - 1];
                    gotoxy(30, 45);
                    printf("\xDD INFO \xAF Subject #%i | '%s' is now included!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                    Sleep(500);
                    continue;
                }
                else
                {
                    gotoxy(30, 45);
                    printf("\xDD INFO \xAF Subject #%i | '%s' is already included!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                    Sleep(500);
                    continue;
                }
            }
            else if (Subject_Selector == 2)
            {
                if (Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] == 0)
                {
                    Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] = 0;
                    Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] = 1;
                    SbjSel_Stats[Subject_Selector - 1] = Subject_Parameters[0];
                    Final_Comp_SelectedSubjects += 1;
                    Final_Comp_SemUnits += Subject_Units[Subject_Selector - 1];
                    gotoxy(30, 45);
                    printf("\xDD INFO \xAF Subject #%i | '%s' is now included!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                    Sleep(500);
                    continue;
                }
                else
                {
                    gotoxy(30, 45);
                    printf("\xDD INFO \xAF Subject #%i | '%s' is already included!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                    Sleep(500);
                    continue;
                }
            }
            else if (Subject_Selector == 3)
            {
                if (Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] == 0)
                {
                    Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] = 0;
                    Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] = 1;
                    SbjSel_Stats[Subject_Selector - 1] = Subject_Parameters[0];
                    Final_Comp_SelectedSubjects += 1;
                    Final_Comp_SemUnits += Subject_Units[Subject_Selector - 1];
                    gotoxy(30, 45);
                    printf("\xDD INFO \xAF Subject #%i | '%s' is now included!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                    Sleep(500);
                    continue;
                }
                else
                {
                    gotoxy(30, 45);
                    printf("\xDD INFO \xAF Subject #%i | '%s' is already included!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                    Sleep(500);
                    continue;
                }
            }
            else if (Subject_Selector == 4)
            {
                if (Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] == 0)
                {
                    Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] = 0;
                    Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] = 1;
                    SbjSel_Stats[Subject_Selector - 1] = Subject_Parameters[0];
                    Final_Comp_SelectedSubjects += 1;
                    Final_Comp_SemUnits += Subject_Units[Subject_Selector - 1];
                    gotoxy(30, 45);
                    printf("\xDD INFO \xAF Subject #%i | '%s' is now included!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                    Sleep(500);
                    continue;
                }
                else
                {
                    gotoxy(30, 45);
                    printf("\xDD INFO \xAF Subject #%i | '%s' is already included!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                    Sleep(500);
                    continue;
                }
            }
            else if (Subject_Selector == 5)
            {
                if (Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] == 0)
                {
                    Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] = 0;
                    Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] = 1;
                    SbjSel_Stats[Subject_Selector - 1] = Subject_Parameters[0];
                    Final_Comp_SelectedSubjects += 1;
                    Final_Comp_SemUnits += Subject_Units[Subject_Selector - 1];
                    gotoxy(30, 45);
                    printf("\xDD INFO \xAF Subject #%i | '%s' is now included!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                    Sleep(500);
                    continue;
                }
                else
                {
                    gotoxy(30, 45);
                    printf("\xDD INFO \xAF Subject #%i | '%s' is already included!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                    Sleep(500);
                    continue;
                }
            }
            else if (Subject_Selector == 6)
            {
                if (Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] == 0)
                {
                    Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] = 0;
                    Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] = 1;
                    SbjSel_Stats[Subject_Selector - 1] = Subject_Parameters[0];
                    Final_Comp_SelectedSubjects += 1;
                    Final_Comp_SemUnits += Subject_Units[Subject_Selector - 1];
                    gotoxy(30, 45);
                    printf("\xDD INFO \xAF Subject #%i | '%s' is now included!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                    Sleep(500);
                    continue;
                }
                else
                {
                    gotoxy(30, 45);
                    printf("\xDD INFO \xAF Subject #%i | '%s' is already included!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                    Sleep(500);
                    continue;
                }
            }
            else if (Subject_Selector == 7)
            {
                if (Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] == 0)
                {
                    Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] = 0;
                    Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] = 1;
                    SbjSel_Stats[Subject_Selector - 1] = Subject_Parameters[0];
                    Final_Comp_SelectedSubjects += 1;
                    Final_Comp_SemUnits += Subject_Units[Subject_Selector - 1];
                    gotoxy(30, 45);
                    printf("\xDD INFO \xAF Subject #%i | '%s' is now included!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                    Sleep(500);
                    continue;
                }
                else
                {
                    gotoxy(30, 45);
                    printf("\xDD INFO \xAF Subject #%i | '%s' is already included!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                    Sleep(500);
                    continue;
                }
            }
            else if (Subject_Selector == 8)
            {
                if (Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] == 0)
                {
                    Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] = 0;
                    Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] = 1;
                    SbjSel_Stats[Subject_Selector - 1] = Subject_Parameters[0];
                    Final_Comp_SelectedSubjects += 1;
                    Final_Comp_SemUnits += Subject_Units[Subject_Selector - 1];
                    gotoxy(30, 45);
                    printf("\xDD INFO \xAF Subject #%i | '%s' is now included!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                    Sleep(500);
                    continue;
                }
                else
                {
                    gotoxy(30, 45);
                    printf("\xDD INFO \xAF Subject #%i | '%s' is already included!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                    Sleep(500);
                    continue;
                }
            }
            else if (Subject_Selector == 9)
            {
                if (Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] == 0)
                {
                    Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] = 0;
                    Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] = 1;
                    SbjSel_Stats[Subject_Selector - 1] = Subject_Parameters[0];
                    Final_Comp_SelectedSubjects += 1;
                    Final_Comp_SemUnits += Subject_Units[Subject_Selector - 1];
                    gotoxy(30, 45);
                    printf("\xDD INFO \xAF Subject #%i | '%s' is now included!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                    Sleep(500);
                    continue;
                }
                else
                {
                    gotoxy(30, 45);
                    printf("\xDD INFO \xAF Subject #%i | '%s' is already included!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                    Sleep(500);
                    continue;
                }
            }
            else if (Subject_Selector == 10)
            {
                if (Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] == 0)
                {
                    Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] = 0;
                    Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] = 1;
                    SbjSel_Stats[Subject_Selector - 1] = Subject_Parameters[0];
                    Final_Comp_SelectedSubjects += 1;
                    Final_Comp_SemUnits += Subject_Units[Subject_Selector - 1];
                    gotoxy(30, 45);
                    printf("\xDD INFO \xAF Subject #%i | '%s' is now included!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                    Sleep(500);
                    continue;
                }
                else
                {
                    gotoxy(30, 45);
                    printf("\xDD INFO \xAF Subject #%i | '%s' is already included!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                    Sleep(500);
                    continue;
                }
            }
            else if (Subject_Selector == 11)
            {
                if (Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] == 0)
                {
                    Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] = 0;
                    Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] = 1;
                    SbjSel_Stats[Subject_Selector - 1] = Subject_Parameters[0];
                    Final_Comp_SelectedSubjects += 1;
                    Final_Comp_SemUnits += Subject_Units[Subject_Selector - 1];
                    gotoxy(30, 45);
                    printf("\xDD INFO \xAF Subject #%i | '%s' is now included!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                    Sleep(500);
                    continue;
                }
                else
                {
                    gotoxy(30, 45);
                    printf("\xDD INFO \xAF Subject #%i | '%s' is already included!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                    Sleep(500);
                    continue;
                }
            }
            else if (Subject_Selector == 12)
            {
                if (Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] == 0)
                {
                    Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] = 0;
                    Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] = 1;
                    SbjSel_Stats[Subject_Selector - 1] = Subject_Parameters[0];
                    Final_Comp_SelectedSubjects += 1;
                    Final_Comp_SemUnits += Subject_Units[Subject_Selector - 1];
                    gotoxy(30, 45);
                    printf("\xDD INFO \xAF Subject #%i | '%s' is now included!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                    Sleep(500);
                    continue;
                }
                else
                {
                    gotoxy(30, 45);
                    printf("\xDD INFO \xAF Subject #%i | '%s' is already included!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                    Sleep(500);
                    continue;
                }
            }
            else
            {
                gotoxy(30, 45);
                printf("\xDD WARNING \xAF You have inputted a wrong number! Out of Choice.Bonds! Reinitialing Function...");
                Sleep(2000);
                continue;
            }
        }
        else if (Option_Selector == 2)
        {
            gotoxy(30, 44);
            printf("\xDD INPUT \xAF Please select the subject number to be excluded \xAF ");
            scanf("%d", &Subject_Selector);
            if (Subject_Selector == 1)
            {
                if (Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] == 0)
                {
                    Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] = 1;
                    Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] = 0;
                    if (Final_Comp_SelectedSubjects == 0)
                    {
                        Final_Comp_SelectedSubjects = 0;
                    }
                    else
                    {
                        Final_Comp_SelectedSubjects -= 1;
                    }
                    if (Final_Comp_SemUnits == 0)
                    {
                        Final_Comp_SemUnits = 0;
                    }
                    else
                    {
                        Final_Comp_SemUnits -= Subject_Units[Subject_Selector - 1];
                    }
                    SbjSel_Stats[Subject_Selector - 1] = Subject_Parameters[1];
                    gotoxy(30, 45);
                    printf("\xDD INFO \xAF Subject #%i | '%s' is now excluded!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                    Sleep(500);
                    continue;
                }
                else
                {
                    gotoxy(30, 45);
                    printf("\xDD INFO \xAF Subject #%i | '%s' is already excluded!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                    Sleep(500);
                    continue;
                }
            }
            else if (Subject_Selector == 2)
            {
                if (Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] == 0)
                {
                    Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] = 1;
                    Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] = 0;
                    if (Final_Comp_SelectedSubjects == 0)
                    {
                        Final_Comp_SelectedSubjects = 0;
                    }
                    else
                    {
                        Final_Comp_SelectedSubjects -= 1;
                    }
                    if (Final_Comp_SemUnits == 0)
                    {
                        Final_Comp_SemUnits = 0;
                    }
                    else
                    {
                        Final_Comp_SemUnits -= Subject_Units[Subject_Selector - 1];
                    }
                    SbjSel_Stats[Subject_Selector - 1] = Subject_Parameters[1];
                    gotoxy(30, 45);
                    printf("\xDD INFO \xAF Subject #%i | '%s' is now excluded!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                    Sleep(500);
                    continue;
                }
                else
                {
                    gotoxy(30, 45);
                    printf("\xDD INFO \xAF Subject #%i | '%s' is already excluded!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                    Sleep(500);
                    continue;
                }
            }
            else if (Subject_Selector == 3)
            {
                if (Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] == 0)
                {
                    Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] = 1;
                    Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] = 0;
                    if (Final_Comp_SelectedSubjects == 0)
                    {
                        Final_Comp_SelectedSubjects = 0;
                    }
                    else
                    {
                        Final_Comp_SelectedSubjects -= 1;
                    }
                    if (Final_Comp_SemUnits == 0)
                    {
                        Final_Comp_SemUnits = 0;
                    }
                    else
                    {
                        Final_Comp_SemUnits -= Subject_Units[Subject_Selector - 1];
                    }
                    SbjSel_Stats[Subject_Selector - 1] = Subject_Parameters[1];
                    gotoxy(30, 45);
                    printf("\xDD INFO \xAF Subject #%i | '%s' is now excluded!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                    Sleep(500);
                    continue;
                }
                else
                {
                    gotoxy(30, 45);
                    printf("\xDD INFO \xAF Subject #%i | '%s' is already excluded!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                    Sleep(500);
                    continue;
                }
            }
            else if (Subject_Selector == 4)
            {
                if (Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] == 0)
                {
                    Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] = 1;
                    Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] = 0;
                    if (Final_Comp_SelectedSubjects == 0)
                    {
                        Final_Comp_SelectedSubjects = 0;
                    }
                    else
                    {
                        Final_Comp_SelectedSubjects -= 1;
                    }
                    if (Final_Comp_SemUnits == 0)
                    {
                        Final_Comp_SemUnits = 0;
                    }
                    else
                    {
                        Final_Comp_SemUnits -= Subject_Units[Subject_Selector - 1];
                    }
                    SbjSel_Stats[Subject_Selector - 1] = Subject_Parameters[1];
                    gotoxy(30, 45);
                    printf("\xDD INFO \xAF Subject #%i | '%s' is now excluded!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                    Sleep(500);
                    continue;
                }
                else
                {
                    gotoxy(30, 45);
                    printf("\xDD INFO \xAF Subject #%i | '%s' is already excluded!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                    Sleep(500);
                    continue;
                }
            }
            else if (Subject_Selector == 5)
            {
                if (Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] == 0)
                {
                    Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] = 1;
                    Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] = 0;
                    if (Final_Comp_SelectedSubjects == 0)
                    {
                        Final_Comp_SelectedSubjects = 0;
                    }
                    else
                    {
                        Final_Comp_SelectedSubjects -= 1;
                    }
                    if (Final_Comp_SemUnits == 0)
                    {
                        Final_Comp_SemUnits = 0;
                    }
                    else
                    {
                        Final_Comp_SemUnits -= Subject_Units[Subject_Selector - 1];
                    }
                    SbjSel_Stats[Subject_Selector - 1] = Subject_Parameters[1];
                    gotoxy(30, 45);
                    printf("\xDD INFO \xAF Subject #%i | '%s' is now excluded!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                    Sleep(500);
                    continue;
                }
                else
                {
                    gotoxy(30, 45);
                    printf("\xDD INFO \xAF Subject #%i | '%s' is already excluded!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                    Sleep(500);
                    continue;
                }
            }
            else if (Subject_Selector == 6)
            {
                if (Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] == 0)
                {
                    Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] = 1;
                    Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] = 0;
                    if (Final_Comp_SelectedSubjects == 0)
                    {
                        Final_Comp_SelectedSubjects = 0;
                    }
                    else
                    {
                        Final_Comp_SelectedSubjects -= 1;
                    }
                    if (Final_Comp_SemUnits == 0)
                    {
                        Final_Comp_SemUnits = 0;
                    }
                    else
                    {
                        Final_Comp_SemUnits -= Subject_Units[Subject_Selector - 1];
                    }
                    SbjSel_Stats[Subject_Selector - 1] = Subject_Parameters[1];
                    gotoxy(30, 45);
                    printf("\xDD INFO \xAF Subject #%i | '%s' is now excluded!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                    Sleep(500);
                    continue;
                }
                else
                {
                    gotoxy(30, 45);
                    printf("\xDD INFO \xAF Subject #%i | '%s' is already excluded!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                    Sleep(500);
                    continue;
                }
            }
            else if (Subject_Selector == 7)
            {
                if (Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] == 0)
                {
                    Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] = 1;
                    Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] = 0;
                    if (Final_Comp_SelectedSubjects == 0)
                    {
                        Final_Comp_SelectedSubjects = 0;
                    }
                    else
                    {
                        Final_Comp_SelectedSubjects -= 1;
                    }
                    if (Final_Comp_SemUnits == 0)
                    {
                        Final_Comp_SemUnits = 0;
                    }
                    else
                    {
                        Final_Comp_SemUnits -= Subject_Units[Subject_Selector - 1];
                    }
                    SbjSel_Stats[Subject_Selector - 1] = Subject_Parameters[1];
                    gotoxy(30, 45);
                    printf("\xDD INFO \xAF Subject #%i | '%s' is now excluded!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                    Sleep(500);
                    continue;
                }
                else
                {
                    gotoxy(30, 45);
                    printf("\xDD INFO \xAF Subject #%i | '%s' is already excluded!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                    Sleep(500);
                    continue;
                }
            }
            else if (Subject_Selector == 8)
            {
                if (Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] == 0)
                {
                    Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] = 1;
                    Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] = 0;
                    if (Final_Comp_SelectedSubjects == 0)
                    {
                        Final_Comp_SelectedSubjects = 0;
                    }
                    else
                    {
                        Final_Comp_SelectedSubjects -= 1;
                    }
                    if (Final_Comp_SemUnits == 0)
                    {
                        Final_Comp_SemUnits = 0;
                    }
                    else
                    {
                        Final_Comp_SemUnits -= Subject_Units[Subject_Selector - 1];
                    }
                    SbjSel_Stats[Subject_Selector - 1] = Subject_Parameters[1];
                    gotoxy(30, 45);
                    printf("\xDD INFO \xAF Subject #%i | '%s' is now excluded!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                    Sleep(500);
                    continue;
                }
                else
                {
                    gotoxy(30, 45);
                    printf("\xDD INFO \xAF Subject #%i | '%s' is already excluded!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                    Sleep(500);
                    continue;
                }
            }
            else if (Subject_Selector == 9)
            {
                if (Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] == 0)
                {
                    Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] = 1;
                    Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] = 0;
                    if (Final_Comp_SelectedSubjects == 0)
                    {
                        Final_Comp_SelectedSubjects = 0;
                    }
                    else
                    {
                        Final_Comp_SelectedSubjects -= 1;
                    }
                    if (Final_Comp_SemUnits == 0)
                    {
                        Final_Comp_SemUnits = 0;
                    }
                    else
                    {
                        Final_Comp_SemUnits -= Subject_Units[Subject_Selector - 1];
                    }
                    SbjSel_Stats[Subject_Selector - 1] = Subject_Parameters[1];
                    gotoxy(30, 45);
                    printf("\xDD INFO \xAF Subject #%i | '%s' is now excluded!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                    Sleep(500);
                    continue;
                }
                else
                {
                    gotoxy(30, 45);
                    printf("\xDD INFO \xAF Subject #%i | '%s' is already excluded!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                    Sleep(500);
                    continue;
                }
            }
            else if (Subject_Selector == 10)
            {
                if (Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] == 0)
                {
                    Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] = 1;
                    Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] = 0;
                    if (Final_Comp_SelectedSubjects == 0)
                    {
                        Final_Comp_SelectedSubjects = 0;
                    }
                    else
                    {
                        Final_Comp_SelectedSubjects -= 1;
                    }
                    if (Final_Comp_SemUnits == 0)
                    {
                        Final_Comp_SemUnits = 0;
                    }
                    else
                    {
                        Final_Comp_SemUnits -= Subject_Units[Subject_Selector - 1];
                    }
                    SbjSel_Stats[Subject_Selector - 1] = Subject_Parameters[1];
                    gotoxy(30, 45);
                    printf("\xDD INFO \xAF Subject #%i | '%s' is now excluded!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                    Sleep(500);
                    continue;
                }
                else
                {
                    gotoxy(30, 45);
                    printf("\xDD INFO \xAF Subject #%i | '%s' is already excluded!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                    Sleep(500);
                    continue;
                }
            }
            else if (Subject_Selector == 11)
            {
                if (Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] == 0)
                {
                    Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] = 1;
                    Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] = 0;
                    if (Final_Comp_SelectedSubjects == 0)
                    {
                        Final_Comp_SelectedSubjects = 0;
                    }
                    else
                    {
                        Final_Comp_SelectedSubjects -= 1;
                    }
                    if (Final_Comp_SemUnits == 0)
                    {
                        Final_Comp_SemUnits = 0;
                    }
                    else
                    {
                        Final_Comp_SemUnits -= Subject_Units[Subject_Selector - 1];
                    }
                    SbjSel_Stats[Subject_Selector - 1] = Subject_Parameters[1];
                    gotoxy(30, 45);
                    printf("\xDD INFO \xAF Subject #%i | '%s' is now excluded!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                    Sleep(500);
                    continue;
                }
                else
                {
                    gotoxy(30, 45);
                    printf("\xDD INFO \xAF Subject #%i | '%s' is already excluded!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                    Sleep(500);
                    continue;
                }
            }
            else if (Subject_Selector == 12)
            {
                if (Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] == 0)
                {
                    Subject_UnitsGuard_AntiDuplicate_Exclude[Subject_Selector - 1] = 1;
                    Subject_UnitsGuard_AntiDuplicate_Include[Subject_Selector - 1] = 0;
                    if (Final_Comp_SelectedSubjects == 0)
                    {
                        Final_Comp_SelectedSubjects = 0;
                    }
                    else
                    {
                        Final_Comp_SelectedSubjects -= 1;
                    }
                    if (Final_Comp_SemUnits == 0)
                    {
                        Final_Comp_SemUnits = 0;
                    }
                    else
                    {
                        Final_Comp_SemUnits -= Subject_Units[Subject_Selector - 1];
                    }
                    SbjSel_Stats[Subject_Selector - 1] = Subject_Parameters[1];
                    gotoxy(30, 45);
                    printf("\xDD INFO \xAF Subject #%i | '%s' is now excluded!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                    Sleep(500);
                    continue;
                }
                else
                {
                    gotoxy(30, 45);
                    printf("\xDD INFO \xAF Subject #%i | '%s' is already excluded!", Subject_Selector, Subject_CodeName[Subject_Selector - 1]);
                    Sleep(500);
                    continue;
                }
            }
        }
        else if (Option_Selector == 3)
        {
            fflush(stdin);
            while (1)
            {
                gotoxy(30, 44);
                printf("\xDD QUESTION \xAF Are you sure you picked the subjects that you wanted to take???");
                gotoxy(30, 45);
                printf("\xDD Choices \xAF [Y]es or [N]o \xAF");
                scanf("%c", &Final_Decision_Selector);
                if (Final_Decision_Selector == 'Y' || Final_Decision_Selector == 'y')
                {
                    while (SbjSel_Checker <= 12)
                    {
                        if (SbjSel_Stats_Exceptions == Subject_WholeSize)
                        {
                            gotoxy(30, 46);
                            printf("\xDD CRITICAL ERROR \xAF Are you even trying to enroll without any subjects!?");
                            Sleep(5000);
                            break;
                        }
                        else if (SbjSel_Stats[SbjSel_Checker - 1] == "Unknown")
                        {
                            gotoxy(30, 46);
                            printf("\xDD ERROR \xAF You cannot leave subject/s to be 'Unknown'. Set them to exclude if you don't want to include it.");
                            Sleep(3000);
                            break;
                        }
                        else if (SbjSel_Stats[SbjSel_Checker - 1] == "Exclude")
                        {
                            SbjSel_Stats_Exceptions++;
                        }
                        else
                        {
                            gotoxy(30, 46);
                            printf("\xDD PROCESS \xAF Copying information to structure to pass with....");
                            //Insert Code To Copy with TRUE to Struct Array
                            gotoxy(30, 47);
                            printf("\xDD PROCESS \xAF Moving Foward to \xDD [ 4th ] Scholarship Check...");
                            Func_Stdnt_ScholarshipCheck();
                            break;
                        }
                    }
                    continue; // Trick to go back to the Main Loop While(1) at the top...
                }
                else
                {
                    gotoxy(30, 46);
                    printf("\xDD PROCESS \xAF Going back...");
                    break;
                }
            }
            continue;
        }
        else if (Option_Selector == -1)
        {
            gotoxy(30, 44);
            printf("\xDD PROCESS \xAF Including All Available Subjects...");
            Final_Comp_SelectedSubjects = 0;
            Final_Comp_SemUnits = 0;
            while (Sbj_Stats_Increment <= Subject_WholeSize)
            {
                SbjSel_Stats[Sbj_Stats_Increment - 1] = Subject_Parameters[0];
                Final_Comp_SelectedSubjects += 1;
                Final_Comp_SemUnits += Subject_Units[Sbj_Stats_Increment - 1];
                Subject_UnitsGuard_AntiDuplicate_Include[Sbj_Stats_Increment - 1] = 1;
                Subject_UnitsGuard_AntiDuplicate_Exclude[Sbj_Stats_Increment - 1] = 0;
                Sbj_Stats_Increment++;
            }
            Sleep(1500);
            continue;
        }
        else if (Option_Selector == -2)
        {
            gotoxy(30, 44);
            printf("\xDD PROCESS \xAF Excluding All Available Subjects...");
            Final_Comp_SelectedSubjects = 0;
            Final_Comp_SemUnits = 0;
            while (Sbj_Stats_Decrement <= Subject_WholeSize)
            {
                SbjSel_Stats[Sbj_Stats_Decrement - 1] = Subject_Parameters[1];
                Subject_UnitsGuard_AntiDuplicate_Include[Sbj_Stats_Decrement - 1] = 0;
                Subject_UnitsGuard_AntiDuplicate_Exclude[Sbj_Stats_Decrement - 1] = 0;
                Sbj_Stats_Decrement++;
            }
            Sleep(1500);
            continue;
        }
        else
        {
            gotoxy(30, 44);
            printf("\xDD WARNING \xAF You have inputted a wrong number! Out of Choice.Bonds! Reinitialing Function...");
            Sleep(2000);
            continue;
        }
    }
}

//Continue Function...

int Func_Stdnt_ScholarshipCheck()
{
    printf("\xDD INFO \xAF We on the 4th Step of this!");
    getch();
    return ERROR_SUCCESS;
}

void PrintDocument_FinalTranscript()
{
    //FILE*
}

void Func_ERLM_Recheck()
{
}

// Uncategoterized Function
void gotoxy(int x, int y)
{
    COORD ConsoleXY = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), ConsoleXY);
}
