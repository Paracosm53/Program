//
// Created by 19196 on 2023/12/23.
//
#include "mainsystem.h"

int main(){
    screen();

    return 0;
}

void screen(){
    int choice;
    while (1){
        printf("******************************\n");
        printf("*\t学生信息管理系统\t*\n");
        printf("******************************\n");
        printf("*\t1、录入学生信息 \t*\n");
        printf("*\t2、插入学生信息 \t*\n");
        printf("*\t3、删除学生信息 \t*\n");
        printf("*\t4、浏览学生信息 \t*\n");
        printf("*\t5、退出信息系统 \t*\n");
        printf("******************************\n");
        printf("请选择：");
        scanf("%d",&choice);
        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                add();
                break;
            case 3:
                delete();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("退出系统成功\n");
                return;
                break;
            default:
                printf("输入错误\n");
                break;
        }
    }
}

void insert(){

    }

void add(){

}

void delete(){

}

void display(){

}
