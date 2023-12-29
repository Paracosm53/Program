//
// Created by 19196 on 2023/12/21.
//
#ifndef PROGRAM_MAINSYSTEM_H
#define PROGRAM_MAINSYSTEM_H

#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
#include "string.h"

void face();
void choice();
void insert();
void add();
void modify(char id[20]);
void deletes();
void display();
void sort();

typedef struct Student
{
    char id[20];
    char name[20];
    int age;
    char sex[10];
    char address[20];
    char phone[20];
    int Chinese;
    int English;
    int Math;
    int grade;
    int rank;
    int score;
    int finalrank;
    int matescore;
    int character;
    int teacherscore;
} Student;

typedef struct dot
{
    Student student;
    struct dot* next;
} dot;

dot* head = NULL;

int n = 0; //记录学生人数
char *filepath = "D:\\clion\\program\\StudentManageSystem\\studentmanage\\student.txt";

#endif //PROGRAM_MAINSYSTEM_H
