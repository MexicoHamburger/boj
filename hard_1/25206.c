#include <stdio.h>
#include <string.h>


int main()
{
    char name[200];
    double sisu;
    char grade[10];

    double totGrade = 0.0;
    double totSisu = 0.0;
    for (int i = 1 ; i <= 20 ; i++) {
        memset(grade, 0, sizeof(grade));
        scanf("%s %lf %s", name, &sisu, grade);
        if (!strcmp(grade, "P")) {
        }
        else
        {
            if (!strcmp(grade, "A+")) {
                totGrade += 4.5 * sisu;
            }
            else if (!strcmp(grade, "A0")) {
                totGrade += 4.0 * sisu;
            }
            else if (!strcmp(grade, "B+")) {
                totGrade += 3.5 * sisu;
            }
            else if (!strcmp(grade, "B0")) {
                totGrade += 3.0 * sisu;
            }
            else if (!strcmp(grade, "C+")) {
                totGrade += 2.5 * sisu;
            }
            else if (!strcmp(grade, "C0")) {
                totGrade += 2.0 * sisu;
            }
            else if (!strcmp(grade, "D+")) {
                totGrade += 1.5 * sisu;
            }
            else if (!strcmp(grade, "D0")) {
                totGrade += 1.0 * sisu;
            }
            else if (!strcmp(grade, "F")) {

            }
            totSisu += sisu;
        }
    }
    printf("%lf", totGrade / totSisu);
}