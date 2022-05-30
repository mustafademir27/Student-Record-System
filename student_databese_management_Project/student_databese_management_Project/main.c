#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>


void addstudent();
void studentrecord();
void searchstudent();
void delete();

struct student {
    char first_name[20];
    char last_name[20];
    int roll_no;
    char Class[10];
    char vill[20];
    float per;
};


void main() {
    int choice;
    do {
 //       printf("\n\n\nSKSGGFJFGJFFHFHFGHFGHFGHFGHFGHFHFG\n\n");
        printf("\n");
        printf("\n\t\t\t====STUDENT DATABASE MANAGEMENT SYSTEM ====");
        printf("\n\n\n\t\t\t\t 1. Add Student Record\n");
        printf("\t\t\t\t 2. Student Record\n");
        printf("\t\t\t\t 3. Search Student \n");
        printf("\t\t\t\t 4. Delete Record\n");
        printf("\t\t\t\t 5.Exit\n");
        printf("\t\t\t\t___________________\n");
        printf("\t\t\t\t");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addstudent();
            break;

        case 2:
            studentrecord();
            printf("Press any key to exit : ");
            _getch();
            break;

        case 3:
            searchstudent();
            break;

        case 4:
            delete();
            printf("Press any key to exit : ");
            _getch();
            break;

        default:
            break;
        }

    } while (choice != 5);
}

void delete() {
    FILE* fp, * fp1;
    struct student info;
    int roll_no, found = 0;
    printf("\n\n\t\t\t\t====Delete Student Record=====\n\n\n");
    fp = fopen("C:\\Users\\mustafa.demir\\Desktop\\MUSTAFA\\C\\student_databese_management_Project\\student_info.txt", "r");
    fp1 = fopen("temp.txt", "w");
    printf("\t\tEnter roll no : ");
    scanf("%d", &roll_no);

    if (fp == NULL) {
        fprintf(stderr, "\t\t\t\t Can't open file \n");
    }
    while (fread(&info, sizeof(struct student), 1, fp)) {
        if (info.roll_no == roll_no) {
            printf("info.roll_no = roll_no bulundu");
            found = 1;
        }
        else {
            fwrite(&info, sizeof(struct student), 1, fp1);
        }
        fclose(fp);
        fclose(fp1);

        if (found) {
            remove("C:\\Users\\mustafa.demir\\Desktop\\MUSTAFA\\C\\student_management_system\\student_info.txt");
            rename("temp.txt", "C:\\Users\\mustafa.demir\\Desktop\\MUSTAFA\\C\\student_databese_management_Project\\student_info.txt");
            printf("\n\t\t\tRecord deleted succesfully");
        }
        else if (!found) {
            printf("\n\t\t\tRecord not found.\n");
        }
        _getch();
    }

}


void searchstudent() {
    FILE* fp;
    int roll_no, flag = 0;
    struct student info;
    fp = fopen("C:\\Users\\mustafa.demir\\Desktop\\MUSTAFA\\C\\student_databese_management_Project\\student_info.txt", "r");

    printf("\n\t\t\t Search Record\n\n");
    printf("Enter roll no : ");
    scanf("%d", &roll_no);

    while (fread(&info, sizeof(struct student), 1, fp)) {
        if (info.roll_no == roll_no) {
            flag = 1;
            printf("\n\t\t\t\t Student Name  : %s %s", info.first_name, info.last_name);
            printf("\n\t\t\t\t Roll NO       : %d", info.roll_no);
            printf("\n\t\t\t\t Class         : %s", info.Class);
            printf("\n\t\t\t\t Village/City  : %s", info.vill);
            printf("\n\t\t\t\t Percentage    : %f%", info.per);
            printf("\n\t\t\t\t ________________________________\n");
        }
    }
    if (!flag) {
        printf("\t\t\tRecord not found.\n\n");
    }
    fclose(fp);
    _getch();
}

void addstudent() {

    char another;
    FILE* fp;
    int n, i;
    struct student info;
    do {
        //        int clrscr();
        printf("\t\t\t\t=======Add Students Info=======\n\n\n");
        fp = fopen("C:\\Users\\mustafa.demir\\Desktop\\MUSTAFA\\C\\student_databese_management_Project\\student_info.txt", "a");; //use can give any file name. Give the name with extention or without extention.

        printf("\n\t\t\tEnter First Name     : ");
        scanf("%s", &info.first_name);
        printf("\n\t\t\tEnter Last Name     : ");
        scanf("%s", &info.last_name);
        printf("\n\t\t\tEnter Roll-No       : ");
        scanf("%d", &info.roll_no);
        printf("\n\t\t\tEnter Class(course) : ");
        scanf("%s", &info.Class);
        printf("\n\t\t\tEnter Address       : ");
        scanf("%s", &info.vill);
        printf("\n\t\t\tEnter Percentage    : ");
        scanf("%f", &info.per);
        printf("\n\t\t\t______________________________\n");

        if (fp == NULL) {
            fprintf(stderr, "can't open file");
        }
        else {
            printf("\t\t\tRecord stored successfuly\n");
        }

        fwrite(&info, sizeof(struct student), 1, fp);
        fclose(fp);

        printf("\t\t\tYou want to add another record?(y/n) : ");


        scanf(" %c", &another);


    } while (another == 'y' || another == 'Y');
}

void studentrecord() {

    FILE* fp;

    struct student info;
    fp = fopen("C:\\Users\\mustafa.demir\\Desktop\\MUSTAFA\\C\\student_databese_management_Project\\student_info.txt", "r");

    printf("\t\t\t\t=======STUDENTS RECORD=======\n\n\n");

    if (fp == NULL) {

        fprintf(stderr, "can't open file\n");
        exit(0);
    }
    else {
        printf("\t\t\t\tRECORDS :\n");
        printf("\t\t\t\t___________\n\n");
    }

    while (fread(&info, sizeof(struct student), 1, fp)) {
        printf("\n\t\t\t\t Student Name  : %s %s", info.first_name, info.last_name);
        printf("\n\t\t\t\t Roll NO       : %d", info.roll_no);
        printf("\n\t\t\t\t Class         : %s", info.Class);
        printf("\n\t\t\t\t Village/City  : %s", info.vill);
        printf("\n\t\t\t\t Percentage    : %f%", info.per);
        printf("\n\t\t\t\t ________________________________\n");

    }
    fclose(fp);
    _getch();
}








