#include<stdio.h>
#include<string.h>
#include<stdlib.h>

FILE *student_detail;
FILE *admin_id;
FILE *student_id;

// buffer for storing the temporary data
char information[1000];


struct admi {
    int uniq_id;
    char Name[50];
    char dob[50];
    char Gender[50];
    char Religion[50];
    char Nationality[50];
    char Address[100];
    char City[50];
    char State[50];
    char Father_Name[50];
    char Father_Occupation[50];
    char Mother_Name[50];
    char Mother_Occupation[50];
    char father_income[50];
    char mother_income[50];
    char Name_b[50];
    char Name_school[50];
    char school_s[50];
    char mig[50];
    char tc[50];
}form;

// structure for storing the administrator id
struct adminitrator {
    float id;
}host;

void admission_form()
{
    int check_id;
    student_detail = fopen("student_details.txt","a+");
    student_id = fopen("student_id.txt","a+");
    printf(" \t \t STUDENT ADMISSION FORM \n");
    printf("\n1.Personal Details \n \n \n");
    printf("Enter Your Unique Id\n");
    scanf("%d",&form.uniq_id);
    while(!feof(student_id)) {
        fscanf(student_id,"%d",&check_id);
        if(form.uniq_id==check_id) {
            printf("\nSorry this ID has been taken please select a different ID\n");
            return;
        }
    }
    printf("Enter Your Name: \n \n");
    getchar();
    gets(form.Name);
    printf("Enter the DOB in DD/MM/YY format \n \n");
    gets(form.dob);
    printf("Enter Your Gender: \n \n");
    scanf("%s",form.Gender);
    printf("Enter Your Religion: \n \n");
    scanf("%s",form.Religion);
    printf("Enter Your Nationality: \n \n");
    scanf("%s",form.Nationality);
    printf("Enter Your Permanent Address: \n \n");
    getchar();
    gets(form.Address);
    printf("Enter Your City:\n \n");
    gets(form.City);
    printf("Enter Your Father's Name: \n \n");
    gets(form.Father_Name);
    printf("Enter Your Father's Occupation: \n \n");
    gets(form.Father_Occupation);
    printf("Enter Your Mother's Name:  \n \n");
    gets(form.Mother_Name);
    printf("Enter Your Mother's Occupation: \n \n");
    gets(form.Mother_Occupation);
    printf("Enter Your Father's Income: \n \n");
    scanf("%s",form.father_income);
    printf("Enter Your Mother's Income: \n \n");
    scanf("%s",form.mother_income);

    printf("Enter If you Have a Transfer Certificate or not \n");
    gets(form.tc);
    fprintf(student_id,"\n%d",form.uniq_id);
    fclose(student_id);
    fprintf(student_detail,"\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s",form.Name,form.dob,form.Gender,form.Religion,form.Nationality,form.Address,form.City,form.Father_Name,form.Father_Occupation,form.Mother_Name,form.Mother_Occupation,form.father_income,form.mother_income,form.tc);
    fclose(student_detail);
    printf("\n\nThankyou For Submitting the Admission form!\n\n");
}


// this function displays the academic details of the student based on branch
void show_academic_details() {

    int adm,choice;
    int Target;
    int Found=0;

    // opening the student_id file and checking if the file contains any data
    if ((student_id=fopen("student_id.txt","r+"))==NULL){
        printf(" There is no student data present.\n\n");
    } else {
        printf("\nEnter The ID Of Student : ");
        scanf("%d",&Target);

        // scanning the student_id file for the id entered
        while(!feof(student_id)&& Found==0) {
            fscanf(student_id,"%d",&form.uniq_id);
            if(Target==form.uniq_id) {
                Found=1;
            }
        }

        if(Found) {
            printf("\n\nAcademic Details\n\n\n");
            printf("Please Select Your Branch\n\n");
            printf("1.Computer Science\n");
            printf("2.Electrical And Communication Engineering\n");            
            printf("3.Information Technology\n");
            printf("\nPlease Enter your Choice \n");
            scanf("%d",&choice);
            switch(choice) {
            case 1: printf("\t\tDetails for the First Year\n\n\n");
                    printf("\t\t\tPHY CYCLE\n\n");
                    printf("\tS.No.\tSubject Name\t\t\tSubject Credits\n");
                    printf("\t1\tBasic Electrical Engineering\t\t4\n");
                    printf("\t2\tElements Of Mechanical Engineering\t4\n");
                    printf("\t3\tEngineering Mechanics\t\t\t4\n");
                    printf("\t4\tEngineering Mathematics 1\t\t4\n");
                    printf("\t5\tEngineering Physics\t\t\t4\n");
                    printf("\t6\tPhysics Lab\t\t\t\t1.5\n");
                    printf("\t7\tWorkshop\t\t\t\t1.5\n");
                    printf("\n\n\t\tTotal Credits = 23");
                    break;
            case 2: printf("\t\tDetails for the First Year\n\n\n");
                    printf("\n\n\t\t\tCHEM CYCLE\n\n");
                    printf("\tS.No.\tSubject Name\t\t\tSubject Credits\n");
                    printf("\t1\tBasic Electronics Engineering\t\t4\n");
                    printf("\t2\tEngineering Mathematics 2\t\t4\n");
                    printf("\t3\tConcepts of C programming\t\t4\n");
                    printf("\t4\tEngineering Chemistry\t\t\t4\n");
                    printf("\t5\tComputer Aided Drawin8g\t\t\t4\n");
                    printf("\t6\tChemistry Lab\t\t\t\t1.5\n");
                    printf("\t6\tChemistry Lab\t\t\t\t1.5\n");
                    printf("\t7\tConcepts of C programming Lab\t\t1.5\n");
                    printf("\t8\tEnglish Core\t\t\t\t2\n");
                    printf("\n\n\t\tTotal Credits = 25");
            default :break;
                        }
            }
        if(!Found) {
            printf(" ! There is no student entry with the entered student ID\n");
        }

        fclose(student_id);
        return;
        }
    }


//fees details of the student to be seleceted by the student//
void fees_details() {
    int feec,bec;
    printf("\n\nFEES DETAILS:\n\n");
    printf("Select the Course \n\n");
    printf("\n1.B.Tech\n\n2.Exit\n\n");
    scanf("%d",&feec);
    switch(feec) {
    case 1:
            printf("\t\t\t\nB.E.\n");
            printf("\n\nEnter The Admission Type:-\n");
            printf("\n1.Josaa\n\n2.JAC\n\n3.Others\n\n");
            scanf("%d",&bec);
            if(bec==1) {
                printf("\n\nCOMEDK-UGET\n\n");
                printf("\n\n\t\t\t\t\tFees per Year\n");
                printf("\nTution Fees= 1,00,000/-\n");
                printf("\nCollege University Fees = 35,000/-");
                printf("\nUniversity Eligibility Fees = 1,500/- \n");
                printf("\nHostel Fees\n\n");
                printf("\nCaution Deposit = 15,000/-");
                printf("\nRoom Rent/Electricity Charges = 48,000/-");
                printf("\nTotal Hostel Fees\n\n");
                printf("\nHostel Mess Charges = 1800/- per month\n");
                } else if(bec==2) {
                printf("\n\n\t\t\tCET\n\n");
                printf("\n\n\t\t\t\t\tFees per Year\n");
                printf("\nTution Fees= 37,000/-\n");
                printf("\nCollege University Fees = 30,000/-");
                printf("\nHostel Fees\n\n");
                printf("\nCaution Deposit = 15,000/-");
                printf("\nRoom Rent/Electricity Charges = 48,000/-");
                printf("\nTotal Hostel Fees\n\n");
                printf("\nHostel Mess Charges = 1800/- per month\n");
                } else {
                printf("\n\n\t\t\tOthers\n\n");
                printf("\n\n\t\t\t\t\tFees per Year\n");
                printf("\nTution Fees= 1,37,000/-\n");
                printf("\nCollege University Fees = 30,000/-");
                printf("\nUniversity Eligibility Fees = 1,500/- \n");
                printf("\nHostel Fees\n\n");
                printf("\nCaution Deposit = 15,000/-");
                printf("\nRoom Rent/Electricity Charges = 48,000/-");
                printf("\nTotal Hostel Fees\n\n");
                printf("\nHostel Mess Charges = 1800/- per month\n");
                }


    default:    break;
    }
}

// main function
void main()
{
    int i,j,n,choice,feec,bec,pgc,adm;
    long int m;
    for(;;) {
        printf("\n\n+-++-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+--+-+--\n");
        printf("+ \t\t     MENU\t\t\t+\n+\t\t\t\t\t\t");
        printf("+\n+\t\t\t\t\t\t+\n+-++-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n");
        printf("+\t\t\t\t\t\t+\n+ 1.Admission/Registration\t\t\t+\n+\t\t\t\t\t\t+\n+ 2.Academic Details\t\t\t\t+\n+\t\t\t\t\t\t+\n+ 3.Fees Details\t\t\t\t+\n+\t\t\t\t\t\t+\n+ 4.Quit\t\t\t\t\t+\n+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+--+-+-+-+-+-+-");
        printf("\n\nEnter Your Choice? \n\n");
        scanf("%d",&choice);
        switch(choice) {
        case 1: system("cls");
                admission_form();
                break;
        case 2: show_academic_details();
                break;
        case 3: fees_details();
                break;
        case 4: return;
                break;
        default:break;
        }
    }
  }
