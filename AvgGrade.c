/*
 * AvgGrade.c
 *
 *  Created on: 19-Jul-2020
 *      Author: dc
 */
#include <stdio.h>
int main()
{
	float testScore, avgScore, totalScore = 0.0;
	int i, totalStudents, studentCount = 0;
	printf("Enter the number of students in this class:\t");
	scanf(" %d", &totalStudents);
	for(i=1;i<=totalStudents;i++){
		printf("Enter the score for student %d (If absent, enter -1):\t", i);
		scanf(" %f", &testScore);
		if(testScore>0){
		totalScore += testScore;
		studentCount++;
		}
	}
	avgScore = totalScore/studentCount;
	printf("The avg score for your class is %.2f\n", avgScore);
}
