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
        printf("��ѡ��");
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
                printf("�����Ľ��Ϊ��\n");
                display();
                break;
            case 5:
                printf("ллʹ�ã�\n");
                exit(0);
            default:
                printf("����������������룡\n");
                break;
        }
    }
}

void face(){
    printf("******************************\n");
    printf("*\tѧ����Ϣ����ϵͳ\t*\n");
    printf("******************************\n");
    printf("*\t1��¼��ѧ����Ϣ \t*\n");
    printf("*\t2������(�޸�)ѧ����Ϣ \t*\n");
    printf("*\t3��ɾ��ѧ����Ϣ \t*\n");
    printf("*\t4�����ѧ����Ϣ \t*\n");
    printf("*\t5���˳���Ϣϵͳ \t*\n");
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

    printf("������ѧ�ţ�");
    scanf(" %s",p->student.id);
    printf("������������");
    scanf("%s",p->student.name);
    printf("���������䣺");
    scanf("%d",&p->student.age);
    printf("�������Ա�");
    scanf("%s",p->student.sex);
    printf("�������ͥ��ַ��");
    scanf("%s",p->student.address);
    printf("������绰���룺");
    scanf("%s",p->student.phone);
    printf("���������ĳɼ���");
    scanf("%d",&p->student.Chinese);
    printf("��������ѧ�ɼ���");
    scanf("%d",&p->student.Math);
    printf("������Ӣ��ɼ���");
    scanf("%d",&p->student.English);
    printf("������ͬѧ�����֣�");
    scanf("%d",&p->student.matescore);
    printf("������Ʒ�³ɼ���");
    scanf("%d",&p->student.character);
    printf("�������ο���ʦ���֣�");
    scanf("%d",&p->student.teacherscore);
    printf("ѧ����Ϣ¼��ɹ�\n");
    system("pause");
    }

void add(){
    int flag,a;
    char id[20];
    printf("��ѡ�����/�޸�(1/0):");
    scanf("%d",&flag);
    if(flag==1){
        insert();
        n++;
        return;
    }else if (flag==0) {
        printf("������Ҫ�޸ĵ�ѧ����ѧ�ţ�");
        scanf(" %s",id);
        modify(id);
    } else{
        printf("����������Ƿ�����ѡ��(1)\n");
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
            printf("������ѧ�ţ�");
            scanf(" %s",p->student.id);
            printf("������������");
            scanf("%s", p->student.name);
            printf("���������䣺");
            scanf("%d", &p->student.age);
            printf("�������Ա�");
            scanf("%s", p->student.sex);
            printf("�������ͥ��ַ��");
            scanf("%s", p->student.address);
            printf("������绰���룺");
            scanf("%s", p->student.phone);
            printf("���������ĳɼ���");
            scanf("%d", &p->student.Chinese);
            printf("��������ѧ�ɼ���");
            scanf("%d", &p->student.Math);
            printf("������Ӣ��ɼ���");
            scanf("%d", &p->student.English);
            printf("ѧ����Ϣ�޸ĳɹ�\n");
            system("pause");
            system("cls");
            return;
        }
        p = p->next;
    }
    printf("δ�ҵ���ѧ�������������룡\n");
    system("pause");
    system("cls");
    return;
}

void deletes(){
    printf("������Ҫɾ����ѧ����ѧ�ţ�");
    int a,b,c=0;
    char id[20];
    scanf(" %s",id);
    dot *p = head;
    dot *q = head;
    while (p != NULL) {
        if (strcmp(p->student.id, id) == 0){
            c=1;
            printf("��ѧ����ϢΪ��\t%s\t%s\t%d\t%s\t%s\t%s\t%d\t%d\t%d\n",p->student.id,p->student.name,p->student.age,
                   p->student.sex,p->student.address,p->student.phone,p->student.Chinese,p->student.Math,p->student.English);
            printf("ȷ��ɾ����ѧ����Ϣ��(1/0):");
            scanf(" %d",&a);
            if (a == 1){
                q->next = p->next;
                free(p);
                printf("ɾ���ɹ�\n");
                n--;
                system("pause");
                system("cls");
                break;
            } else if(a == 0){
                system("pause");
                system("cls");
                break;
            } else{
                printf("��������Ƿ��������룿(1):");
                scanf(" %d",&b);
                if (b == 1){
                    printf("����������������룡\n");
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
        printf("δ�ҵ���ѧ����Ϣ\n");
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
    fprintf(fp,"*\t\t\tѧ����Ϣ\t\t\t*\n");
    fprintf(fp,"********************************************************************\n");
    fprintf(fp,"* ѧ��  ����  ����  �Ա�  ��ͥסַ  �绰����  ���ĳɼ�  ��ѧ�ɼ�  Ӣ��ɼ�  ���Գɼ�  �ɼ�����  �۲�ɼ�  �۲����� *\n");
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