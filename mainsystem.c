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
        printf("*\tѧ����Ϣ����ϵͳ\t*\n");
        printf("******************************\n");
        printf("*\t1��¼��ѧ����Ϣ \t*\n");
        printf("*\t2������ѧ����Ϣ \t*\n");
        printf("*\t3��ɾ��ѧ����Ϣ \t*\n");
        printf("*\t4�����ѧ����Ϣ \t*\n");
        printf("*\t5���˳���Ϣϵͳ \t*\n");
        printf("******************************\n");
        printf("��ѡ��");
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
                printf("�˳�ϵͳ�ɹ�\n");
                return;
                break;
            default:
                printf("�������\n");
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
