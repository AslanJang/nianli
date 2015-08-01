// ConsoleApplication11.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h> 
#include<conio.h> 
#include<stdlib.h>
#include <cstdlib>  
#include <iostream> 
int IsLeapYear(int);   //函数定义
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
	scanf_s("%d", &year);   //输入年份

	while (Year_Start < year)   //从公元1年开始执行while循环, 该年的一月一号为星期一
	{
		if (IsLeapYear(Year_Start))
			Per_Year_Days = 366;   //如果是闰年, 则一年有366天
		else
			Per_Year_Days = 365;   //如果不是闰年, 则一年有365天

		Year_days = Year_days + Per_Year_Days;   //Year_days为从公元1年到输入年份的前一年的天数的总和
		Year_Start++;
	}

	for (temp = 1; temp <= 12; temp++)   //temp从1到12, 对应一年内12个月
	{
		switch (temp)   //用switch语句将temp和12个月对应起来
		{
		case 1:
			printf(" January(%d)\n", year);   //一月
			break;
		case 2:
			printf(" February(%d)\n", year);   //二月
			break;
		case 3:
			printf(" March(%d)\n", year);   //三月
			break;
		case 4:
			printf(" April(%d)\n", year);   //四月
			break;
		case 5:
			printf(" May(%d)\n", year);   //五月
			break;
		case 6:
			printf(" June(%d)\n", year);   //六月
			break;
		case 7:
			printf(" July(%d)\n", year);     //七月
			break;
		case 8:
			printf(" August(%d)\n", year);   //八月
			break;
		case 9:
			printf(" September(%d)\n", year);   //九月
			break;
		case 10:
			printf(" October(%d)\n", year);   //十月
			break;
		case 11:
			printf(" November(%d)\n", year);   //十一月
			break;
		case 12:
			printf(" December(%d)\n", year);   //十二月
			break;
		}
		i = Year_days % 7;   //每个星期有7天, 故用每年的天数对7取余
		printf("Mon\tTue\tWed\tThu\tFri\tSat\tSun\n");
		if (i != 0)                      //如果余数不为零
		for (temp_i = 0; temp_i < i; temp_i++)
			printf("\t");               //则打印空格(这里用\t代替空格, 更加美观), 空格数为i
		day = 1;                        //初始化day为1, 为下面的while循环做准备
		if (IsLeapYear(year) && temp == 2)   //如果输入的年份是闰年, 并且月份为2
		while (day <= month_day[12])    //day为一循环变量, 取值为1-365(闰年的话为1-366)
		{
			if (day >1)                //如果天数大于一
			if (Year_days % 7 == 0)    //如果是星期日, 则换行
				printf("\n");
			if (day >= 10)
				printf("%d\t", day);   //打印天数+空格
			else
				printf("%d\t", day);
			Year_days++;
			day++;
		}

		else                         //如果不满足"输入的年份是闰年, 并且月份为2"
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
		if (getchar() == 'q')        //如果输入为q, 则退出程序
			exit(0);
	}
	getchar();                      //每按一次键, 打印一个月份
}

int IsLeapYear(int year)
{
	                               
	
	//判断是否是闰年, 是则返回1, 否则返回0
	if ((year % 4 == 0) && (year % 100 != 0) ||
		(year % 400 == 0))
		return 1;
	else
		return 0;
} 
//以下为查询周几的代码

void Print(int weekday)
{
	switch (weekday){
	case 0: printf("星期日"); break;
	case 1: printf("星期一"); break;
	case 2: printf("星期二"); break;
	case 3: printf("星期三"); break;
	case 4: printf("星期四"); break;
	case 5: printf("星期五"); break;
	case 6: printf("星期六"); break;
	default: printf("error");
	}
}

int GetDays(int year, int  month, int day)//得到输入的年月日月  与  1年1月1日  相隔的天数   （不计算第一天）   
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
	printf("输入你要查询的年月日，用，分隔\n");
	int result = scanf_s("%d,%d,%d", &year, &month, &day);

	if (result != 3){
		printf("输入错误");
		system("PAUSE");
	}
	if ((year<0) || (month<1) || (month>12) || (day<1) || (day >31)){
		printf("输入错误");
		system("PAUSE");
	}