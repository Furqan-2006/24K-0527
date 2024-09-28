#include <stdio.h>

int main()
{
    int Ascore, Mscore, FEscore, tot_score;
    float atten;
    char grade;
    int invalid = 1;

    while (invalid)
    {
        printf("Enter your Assignment score (0-20): ");
        scanf("%d", &Ascore);
        printf("Enter your Midterm score (0-30): ");
        scanf("%d", &Mscore);
        printf("Enter your Final exam score (0-50): ");
        scanf("%d", &FEscore);
        printf("Enter your Attendance %% (0-100): ");
        scanf("%f", &atten);

        if ((Ascore >= 0 && Ascore <= 20) &&
            (Mscore >= 0 && Mscore <= 30) &&
            (FEscore >= 0 && FEscore <= 50) &&
            (atten >= 0 && atten <= 100))
        {
            invalid = 0;
        }
        else
        {
            printf("Your inputs are not correct. Please enter valid scores.\n");
        }
    }

    if (atten >= 90)
    {
        tot_score = Ascore + Mscore + FEscore;

        if (tot_score >= 90 && tot_score <= 100)
        {
            printf("Grade is A.");
            grade = 'A';
        }
        else if (tot_score >= 80 && tot_score < 90)
        {
            printf("Grade is B.");
            grade = 'B';
        }
        else if (tot_score >= 70 && tot_score < 80)
        {
            printf("Grade is C.");
            grade = 'C';
        }
        else if (tot_score >= 60 && tot_score < 70)
        {
            printf("Grade is D.");
            grade = 'D';
        }
        else if (tot_score >= 50 && tot_score < 60)
        {
            printf("Grade is E.");
            grade = 'E';
        }
        else
        {
            if (tot_score < 50 && tot_score >= 0)
            {
                printf("Grade is F.");
                grade = 'F';
            }
        }
    }
    else
    {
        printf("Your Credit Hours are not enough to pass the course.");
        return 0;
    }

    return 0;
}