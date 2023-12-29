//
// Created by 19196 on 2023/12/23.
//
#include "mainsystem.h"

int main(){
    choice();
    return 0;
}

void choice(){
    int choice;
    while (1){
        face();
        printf("请选择：");
        scanf("%d",&choice);
        switch (choice) {
            case 1:
                insert();
                n++;
                break;
            case 2:
                add();
                break;
            case 3:
                deletes();
                n--;
                break;
            case 4:
                sort();
                printf("排序后的结果为：\n");
                display();
                break;
            case 5:
                printf("谢谢使用！\n");
                exit(0);
            default:
                printf("输入错误，请重新输入！\n");
                break;
        }
    }
}

void face(){
    printf("******************************\n");
    printf("*\t学生信息管理系统\t*\n");
    printf("******************************\n");
    printf("*\t1、录入学生信息 \t*\n");
    printf("*\t2、插入(修改)学生信息 \t*\n");
    printf("*\t3、删除学生信息 \t*\n");
    printf("*\t4、浏览学生信息 \t*\n");
    printf("*\t5、退出信息系统 \t*\n");
    printf("******************************\n");
}

void insert(){
    dot* p = (dot*)malloc(sizeof (dot));
    if (p == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    p->next = NULL;

    if(head == NULL)
    {
        head = p;
    } else{
        p->next = head;
        head = p;
    }

    printf("请输入学号：");
    scanf(" %s",p->student.id);
    printf("请输入姓名：");
    scanf("%s",p->student.name);
    printf("请输入年龄：");
    scanf("%d",&p->student.age);
    printf("请输入性别：");
    scanf("%s",p->student.sex);
    printf("请输入家庭地址：");
    scanf("%s",p->student.address);
    printf("请输入电话号码：");
    scanf("%s",p->student.phone);
    printf("请输入语文成绩：");
    scanf("%d",&p->student.Chinese);
    printf("请输入数学成绩：");
    scanf("%d",&p->student.Math);
    printf("请输入英语成绩：");
    scanf("%d",&p->student.English);
    printf("请输入同学互评分：");
    scanf("%d",&p->student.matescore);
    printf("请输入品德成绩：");
    scanf("%d",&p->student.character);
    printf("请输入任课老师评分：");
    scanf("%d",&p->student.teacherscore);
    printf("学生信息录入成功\n");
    system("pause");
    }

void add(){
    int flag,a;
    char id[20];
    printf("请选择插入/修改(1/0):");
    scanf("%d",&flag);
    if(flag==1){
        insert();
        n++;
        return;
    }else if (flag==0) {
        printf("请输入要修改的学生的学号：");
        scanf(" %s",id);
        modify(id);
    } else{
        printf("输入错误，请是否重新选择？(1)\n");
        scanf(" %d",&a);
        if(a==1){
            system("cls");
            add();
            return;
        } else{
            return;
        }
    }
    system("cls");
}

void modify(char id[20]) {
    dot *p = head;
    while (p != NULL) {
        if (strcmp(p->student.id, id) == 0) {
            printf("请输入学号：");
            scanf(" %s",p->student.id);
            printf("请输入姓名：");
            scanf("%s", p->student.name);
            printf("请输入年龄：");
            scanf("%d", &p->student.age);
            printf("请输入性别：");
            scanf("%s", p->student.sex);
            printf("请输入家庭地址：");
            scanf("%s", p->student.address);
            printf("请输入电话号码：");
            scanf("%s", p->student.phone);
            printf("请输入语文成绩：");
            scanf("%d", &p->student.Chinese);
            printf("请输入数学成绩：");
            scanf("%d", &p->student.Math);
            printf("请输入英语成绩：");
            scanf("%d", &p->student.English);
            printf("学生信息修改成功\n");
            system("pause");
            system("cls");
            return;
        }
        p = p->next;
    }
    printf("未找到该学生，请重新输入！\n");
    system("pause");
    system("cls");
    return;
}

void deletes(){
    printf("请输入要删除的学生的学号：");
    int a,b,c=0;
    char id[20];
    scanf(" %s",id);
    dot *p = head;
    dot *q = head;
    while (p != NULL) {
        if (strcmp(p->student.id, id) == 0){
            c=1;
            printf("该学生信息为：\t%s\t%s\t%d\t%s\t%s\t%s\t%d\t%d\t%d\n",p->student.id,p->student.name,p->student.age,
                   p->student.sex,p->student.address,p->student.phone,p->student.Chinese,p->student.Math,p->student.English);
            printf("确定删除该学生信息？(1/0):");
            scanf(" %d",&a);
            if (a == 1){
                q->next = p->next;
                free(p);
                printf("删除成功\n");
                n--;
                system("pause");
                system("cls");
                break;
            } else if(a == 0){
                system("pause");
                system("cls");
                break;
            } else{
                printf("输入错误，是否重新输入？(1):");
                scanf(" %d",&b);
                if (b == 1){
                    printf("输入错误，请重新输入！\n");
                    system("cls");
                    deletes();
                    return;
                } else{
                    system("pause");
                    system("cls");
                    return;
                }
            }
        }
        q = p;
        p =  p->next;
    }
    if(c== 0)
        printf("未找到该学生信息\n");
    return;
}

void display(){
    dot* p = head;
    dot* q = head;
    while (p != NULL && p->next != NULL){
        dot* temp = p->next;
        while (q != NULL && strcmp(p->student.id, q->student.id) > 0){
            p = q;
            q = q->next;
        }
        if (temp != q->next){
            q->next = temp->next;
            temp->next = p->next;
            p->next = temp;
        }
        p = temp->next;
    }

    p = head;
    printf("1");
    FILE *fp = fopen(filepath,"w");
    if (fp == NULL) {
        printf("Failed to open file\n");
        return;
    }
    fprintf(fp,"********************************************************************\n");
    fprintf(fp,"*\t\t\t学生信息\t\t\t*\n");
    fprintf(fp,"********************************************************************\n");
    fprintf(fp,"* 学号  姓名  年龄  性别  家庭住址  电话号码  语文成绩  数学成绩  英语成绩  考试成绩  成绩排名  综测成绩  综测排名 *\n");
    while (p != NULL){
        fprintf(fp,"* %4s  %4s  %4d  %4s  %8s  %8s  %8d  %8d  %8d  %8d  %8d  %8d  %8d *\n",p->student.id,
                 p->student.name,p->student.age,p->student.sex,p->student.address,p->student.phone,
                 p->student.Chinese,p->student.Math,p->student.English,p->student.grade,
                 p->student.rank,p->student.score,p->student.finalrank);
        p = p->next;
    }
    fprintf(fp,"********************************************************************\n");
    fclose(fp);

    FILE *fg = fopen(filepath,"r");
    char buf[20];
    while (fgets(buf,20,fg) != NULL){
        printf("%s",buf);
    }
    fclose(fg);

    system("pause");
}

void sort(){
    dot* p = head;
    while (p != NULL){
        p->student.grade = (p->student.Chinese + p->student.Math + p->student.English)/3;
        p->student.score = p->student.grade * 0.6 + p->student.matescore * 0.1 + p->student.character * 0.1
                 + p->student.teacherscore * 0.2;
        p = p->next;
    }
    p = head;
    dot* q;
    while (p != NULL){
        p->student.rank = 1;
        p->student.finalrank = 1;
        q = head;
        while (q != NULL){
            if (q->next != NULL && q->next->student.grade > p->student.grade){
                p->student.rank++;
            }
            if (q->next != NULL && q->next->student.score > p->student.score){
                p->student.finalrank++;
            }
            q = q->next;
        }
        p = p->next;
    }

    return;
}