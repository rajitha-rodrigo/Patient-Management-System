/* COVID 19 Patient management system, 2021
CO253_E/18/306 */

#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include<conio.h>
typedef struct // create structure to store patient records
{
    int NIC;
    char fullName[50];
    int age;
    char gender[10];
    char admissionDate[20];
}patient;

int nmax; // number of maximum patient that can handle using this system
patient *data; // array for store patient data
int patientCount=0; //number of patient in the system
void input();

// main function
int main()
{
    data =(patient*)malloc(nmax*sizeof(patient));
    printf("WELCOME TO COVID 19 PATIENT MANAGEMANT SYSTEM\t\n\n");
    printf("\tPress any key to continue...\n");
    getch();
    printf("\n");
    printf("Enter the maximum number of patients that you want to add to the system: ");scanf("%d",&nmax);
    input ();
    return 0;
}

// 1.add new patient function
char add()
{
    int n;
    printf("Number of patients: "); scanf("%d",&n);
    printf("\n");


    for(int i=patientCount;i<n+patientCount;i++)
    {
       printf("Enter patient %d NIC: ",i+1);scanf("%d",&data[i].NIC);
       printf("Enter patient %d Full name: ",i+1);getchar();gets(data[i].fullName);
       printf("Enter patient %d Age: ",i+1);scanf("%d",&data[i].age);
       printf("Enter patient %d Gender: ",i+1);getchar();gets(data[i].gender);
       printf("Enter patient %d Date of Admission: ",i+1);gets(data[i].admissionDate);
       printf("\n");
    }
    printf("\n");
    patientCount+=n;
    input();
}

// 2.print a patient record function
void printOne()
{
    int PNIC;
    int flag;
    if(patientCount==0)
    {
        printf("\t'No any patient records.'\n\n");
        input();
    }
    else{
    printf("Enter the NIC number of the patient: ");scanf("%d",&PNIC);

    for(int i=0;i<patientCount;i++)
    {
        if(data[i].NIC==PNIC)
        {
            flag=1;
            printf("\n\t=============================PATIENT DETAILS==================================\n");
            printf("\n\tNIC: %d\t | FULL NAME: %s\t | AGE: %d\t | GENDER: %s\t | DATE of ADMISSION: %s\n\n",data[i].NIC,data[i].fullName,data[i].age,data[i].gender,data[i].admissionDate);

        }
        else
        {
            continue;
        }
    }
    if(flag!=1){printf("\n\t'Given NIC did not match with any patient record.'\n");}
    input();
    }
}

// 3. print all records function
void printAll()
{
    if(patientCount==0)
    {
        printf("\t'No any patient records.'\n\n");
        input();
    }
    else{
            printf("\n\t=============================PATIENT DETAILS==================================\n");
    for(int i=0;i<patientCount;i++)
    {
        printf("\nPatient [%d]\n NIC: %d\t | FULL NAME: %s\t | AGE: %d\t | GENDER: %s\t | DATE of ADMISSION: %s\n\n",i+1,data[i].NIC,data[i].fullName,data[i].age,data[i].gender,data[i].admissionDate);
    }
    printf("\n");
    input();
    }

}

// 4.delete a record of a patient function
void del()
{   int flag=0;
    int DNIC;
    printf("Enter the patient ID number which want to delete: "); scanf("%d",&DNIC);
    for(int i=0;i<patientCount;i++)
    {
        if(data[i].NIC==DNIC)
        {
           flag=1;
           char ans;
            printf("\n\tAre you sure you want to delete this recode. Enter [Y/N]: ");scanf("%s",&ans);
            if(ans=='Y')
            {
                 for(int j=i;j<patientCount;j++)
            {
                data[j]=data[j+1];
            }
                patientCount=patientCount-1;
                printf("\n\t'Patient record with NIC number %d was deleted successfully.'\n\n",DNIC);
                input();

            }
            else
            {
                printf("\n\t'Patient record not deleted.'\n");
                input();

            }

        }
    }
    if(flag!=1){printf("\n\t'Given NIC did not match any patient record.'\n");}
    input();

}


//main input function
void input()

{
    printf("------------------------------------------------\n"); // main user interface
    printf("\tCOVID-19 PATIENT MANANGMENT SYSTEM\n");
    printf("------------------------------------------------\n");
    printf("------------------MAIN MENU---------------------\n");
    printf("0. Quit\n");
    printf("1. Add a Patient Record\n");
    printf("2. Print a Patient Record\n");
    printf("3. Print All Patient Records\n");
    printf("4. Delete a Patient Record\n");
    printf("------------------------------------------------\n");
    printf("Enter Option[0-4]: ");
    int inputn;
    scanf("%d",&inputn);
    printf("\n");

    if(inputn==1)
    {
      add();
    }
    if(inputn==2)
    {
        printOne();
    }
    if(inputn==3)
    {
        printAll();
    }
    if(inputn==4)
    {
        del();
    }
    if(inputn==0)
    {
        printf("\t'Thank you, Have a nice day!'\t\n");
        exit(0);
    }
    else
    {
        printf("\t'Invalid input. Please input valid input.'\t\n");
        input();
    }

}
