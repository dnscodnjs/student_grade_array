#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS

#define ARRAY 10
#define ALL 3

char grade_check(double avg);


int main() {
	char name[ARRAY][10] = { " ", };
	int no[ARRAY], php[ARRAY], html[ARRAY], c[ARRAY], total[ARRAY] = { 0, };
	double avg[ARRAY] = { 0.0, };
	char grade[ARRAY] = { 0, };

	//char name_array[26] = { 0, };
	//for (int i = 0; i < 26; i++) {
	//	name_array[i] = 65 + i; // 아스키코드 알파벳
	//}

	for (int i = 0; i < 10; i++) {
		//random name
		name[i][0] = 'A' + rand() % 26;
		name[i][1] = 'A' + rand() % 26;
		name[i][2] = 'A' + rand() % 26;

		no[i] = rand() % 21;
		php[i] = rand() % 101; // (100-0+1) +0
		html[i] = rand() % 101;
		c[i] = rand() % 101;

		total[i] = php[i] + html[i] + c[i];
		avg[i] = total[i] / (double)ALL;

		grade[i] = grade_check(avg[i]);
	}

	for (int j = 0; j < 10; j++) {
		printf("%s %d %d %d %d %d %lf %c\n",
			name[j], no[j], php[j], html[j], c[j], total[j], avg[j], grade[j]);
	}

	//위에서 랜덤으로 출력된 학생 정보를 오름차순으로 정렬
	int k = 0;
	double v = 0.0;
	char g = 0;
	char name_buffer[10] = "";

	for (int i = 0; i < ARRAY - 1; i++) {
		for (int j = i + 1; j < ARRAY; j++) {

			if (total[i] < total[j]) {
				strcpy(name_buffer, name[i]);
				strcpy(name[i], name[j]);
				strcpy(name[j], name_buffer);

				k = no[i];
				no[i] = no[j];
				no[j] = k;

				k = php[i];
				php[i] = php[j];
				php[j] = k;

				k = html[i];
				html[i] = html[j];
				html[j] = k;

				k = c[i];
				c[i] = c[j];
				c[j] = k;

				k = total[i];
				total[i] = total[j];
				total[j] = k;

				v = avg[i];
				avg[i] = avg[j];
				avg[j] = v;

				g = grade[i];
				grade[i] = grade[j];
				grade[j] = g;
			}
		}
	}
	printf("\n");
	for (int j = 0; j < 10; j++) {
		printf("%s %d %d %d %d %d %lf %c\n",
			name[j], no[j], php[j], html[j], c[j], total[j], avg[j], grade[j]);
	}

}

char grade_check(double avg) {
	char grade = 0;

	if (avg >= 90) {
		grade = 'A';
	}
	else if (avg >= 80 && avg < 90) {
		grade = 'B';
	}
	else if (avg >= 70 && avg < 80) {
		grade = 'C';
	}
	else if (avg >= 60 && avg < 70) {
		grade = 'D';
	}
	else if (avg < 60) {
		grade = 'F';
	}
	return grade;
}