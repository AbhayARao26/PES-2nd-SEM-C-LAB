#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int roll_no;
    char name[100];
} Student;

void swap(Student** a, Student** b)
{
    Student* temp = *a;
    *a = *b;
    *b = temp;
}

void sort_by_roll(Student** students, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (students[j]->roll_no < students[min_index]->roll_no)
            {
                min_index = j;
            }
        }
        swap(&students[min_index], &students[i]);
    }
}

void sort_by_name(Student** students, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (strcmp(students[j]->name, students[min_index]->name) < 0)
            {
                min_index = j;
            }
        }
        swap(&students[min_index], &students[i]);
    }
}

void print_students(Student** students, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d %s\n", students[i]->roll_no, students[i]->name);
    }
}

int read_student_data(Student** students, const char* filename)
{
    FILE* file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Failed to open the file: %s\n", filename);
        return 0;
    }

    char line[110];
    int count = 0;

    while (fgets(line, sizeof(line), file) != NULL)
    {
        if (line[0] != '\n')
        {
            Student* student = (Student*)malloc(sizeof(Student));
            sscanf(line, "%d %s", &(student->roll_no), student->name);
            students[count] = student;
            count++;
        }
    }

    fclose(file);
    return count;
}

int main()
{
    const char* filename = "/Users/abhayarao/Documents/PES Engineering/1st YEAR/2nd SEM/C PROGRAMMING/C LAB PROGRAMS/LAB - 11/student.csv";
    Student* students[100];
    int count = read_student_data(students, filename);

    if (count == 0)
    {
        return 1;
    }

    int choice;
    printf("Enter the choice:\n");
    printf("1. Sort based on roll number\n");
    printf("2. Sort based on name\n");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            sort_by_roll(students, count);
            printf("Sorted by roll number:\n");
            print_students(students, count);
            break;
        case 2:
            sort_by_name(students, count);
            printf("Sorted by name:\n");
            print_students(students, count);
            break;
        default:
            printf("Invalid choice.\n");
    }

    for (int i = 0; i < count; i++)
    {
        free(students[i]);
    }

    return 0;
}

