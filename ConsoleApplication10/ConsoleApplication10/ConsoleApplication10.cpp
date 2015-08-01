// ConsoleApplication11.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h> 
#include<conio.h> 
#include<stdlib.h>
#include <cstdlib>  
#include <iostream> 
int IsLeapYear(int);   //��������
int months[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int main()
{
	int year, i,month,day;
	printf("1.Calendar\n2.Query\nSelect:");
	scanf_s("%d", &i);
	if (i == 1)
	{
		printf("Enter year:");
		scanf_s("%d", &year);
		calender(year);
	}
	else
	{
		query(year,month,day);//function 2 code    
	}
	getchar();
	getchar();
	return 0;
}
void  calender(int year)
{
	int i;
	int day;
	int year;
	int temp;
	int temp_i;
	long int Year_days = 0;
	int Year_Start = 1; 
	int Per_Year_Days;
	int month_day[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 29 };

	printf("Please enter the year: ");
	scanf_s("%d", &year);   //�������

	while (Year_Start < year)   //�ӹ�Ԫ1�꿪ʼִ��whileѭ��, �����һ��һ��Ϊ����һ
	{
		if (IsLeapYear(Year_Start))
			Per_Year_Days = 366;   //���������, ��һ����366��
		else
			Per_Year_Days = 365;   //�����������, ��һ����365��

		Year_days = Year_days + Per_Year_Days;   //Year_daysΪ�ӹ�Ԫ1�굽������ݵ�ǰһ����������ܺ�
		Year_Start++;
	}

	for (temp = 1; temp <= 12; temp++)   //temp��1��12, ��Ӧһ����12����
	{
		switch (temp)   //��switch��佫temp��12���¶�Ӧ����
		{
		case 1:
			printf(" January(%d)\n", year);   //һ��
			break;
		case 2:
			printf(" February(%d)\n", year);   //����
			break;
		case 3:
			printf(" March(%d)\n", year);   //����
			break;
		case 4:
			printf(" April(%d)\n", year);   //����
			break;
		case 5:
			printf(" May(%d)\n", year);   //����
			break;
		case 6:
			printf(" June(%d)\n", year);   //����
			break;
		case 7:
			printf(" July(%d)\n", year);     //����
			break;
		case 8:
			printf(" August(%d)\n", year);   //����
			break;
		case 9:
			printf(" September(%d)\n", year);   //����
			break;
		case 10:
			printf(" October(%d)\n", year);   //ʮ��
			break;
		case 11:
			printf(" November(%d)\n", year);   //ʮһ��
			break;
		case 12:
			printf(" December(%d)\n", year);   //ʮ����
			break;
		}
		i = Year_days % 7;   //ÿ��������7��, ����ÿ���������7ȡ��
		printf("Mon\tTue\tWed\tThu\tFri\tSat\tSun\n");
		if (i != 0)                      //���������Ϊ��
		for (temp_i = 0; temp_i < i; temp_i++)
			printf("\t");               //���ӡ�ո�(������\t����ո�, ��������), �ո���Ϊi
		day = 1;                        //��ʼ��dayΪ1, Ϊ�����whileѭ����׼��
		if (IsLeapYear(year) && temp == 2)   //�����������������, �����·�Ϊ2
		while (day <= month_day[12])    //dayΪһѭ������, ȡֵΪ1-365(����Ļ�Ϊ1-366)
		{
			if (day >1)                //�����������һ
			if (Year_days % 7 == 0)    //�����������, ����
				printf("\n");
			if (day >= 10)
				printf("%d\t", day);   //��ӡ����+�ո�
			else
				printf("%d\t", day);
			Year_days++;
			day++;
		}

		else                         //���������"��������������, �����·�Ϊ2"
		while (day <= month_day[temp - 1])
		{
			if (day > 1)
			if (Year_days % 7 == 0)
				printf("\n");
			if (day >= 10)
				printf("%d\t", day);
			else
				printf("%d\t", day);
			Year_days++;
			day++;
		}
		printf("\n");
		if (getchar() == 'q')        //�������Ϊq, ���˳�����
			exit(0);
	}
	getchar();                      //ÿ��һ�μ�, ��ӡһ���·�
}

int IsLeapYear(int year)
{
	                               
	
	//�ж��Ƿ�������, ���򷵻�1, ���򷵻�0
	if ((year % 4 == 0) && (year % 100 != 0) ||
		(year % 400 == 0))
		return 1;
	else
		return 0;
} 
//����Ϊ��ѯ�ܼ��Ĵ���

void Print(int weekday)
{
	switch (weekday){
	case 0: printf("������"); break;
	case 1: printf("����һ"); break;
	case 2: printf("���ڶ�"); break;
	case 3: printf("������"); break;
	case 4: printf("������"); break;
	case 5: printf("������"); break;
	case 6: printf("������"); break;
	default: printf("error");
	}
}

int GetDays(int year, int  month, int day)//�õ��������������  ��  1��1��1��  ���������   ���������һ�죩   
{
	int days = 0;
	int i, j, k;
	for (i = 1; i<year; i++){
		if (IsLeapYear(i))days = days + 366; else days = days + 365;
	}
	for (j = 1; j<month; j++){
		if (j == 2 && IsLeapYear(year)) days = days + 29;
		else days = days + months[j - 1];
	}
	for (k = 1; k<day; k++){
		days++;
	}
	return days;
}

int query(int year, int month, int day)
{
	printf("������Ҫ��ѯ�������գ��ã��ָ�\n");
	int result = scanf_s("%d,%d,%d", &year, &month, &day);

	if (result != 3){
		printf("�������");
		system("PAUSE");
	}
	if ((year<0) || (month<1) || (month>12) || (day<1) || (day >31)){
		printf("�������");
		system("PAUSE");
	}