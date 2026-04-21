/*
Name: ADAKU NOBERT MENDEL
Registration Number: 25/U/BIO/01351/PD
*/

#include <stdio.h>
#include <stdlib.h>

// 2. MAIN FUNCTION
int main() {
    // Semester I 
    char *codes1[] = {"TEMB 1101", "TEMB 1102", "TEMB 1103", "TEMB 1104", "TEMB 1105", "TEMB 1106", "TEMB 1107", "TEMB 1108"};
    char *names1[] = {"Fundamentals of Engineering Mathematics", "Biochemistry and Medical Physics", "Electrical Engineering Science", "Mechanics I", "Computing I", "Mechanical Drawing", "Engineering Profession", "Functional Anatomy and Physiology I"};
    int units1[] = {4, 3, 3, 3, 3, 3, 2, 3};
    
    // Semester II 
    char *codes2[] = {"TEMB 1201", "TEMB 1202", "TEMB 1203", "TEMB 1204", "TEMB 1205", "TEMB 1206", "TEMB 1207", "TEMB 1208"};
    char *names2[] = {"Further Engineering Mathematics", "Computing II", "Mechatronics Drawing", "Fluid Mechanics", "Thermodynamics", "Workshop Practice", "Functional Anatomy and Physiology II", "Electronics I"};
    int units2[] = {4, 3, 3, 3, 3, 3, 3, 3};

    int scores1[8], scores2[8];
    float gp1[8], gp2[8], weighted1[8], weighted2[8];
    char grade1[8], grade2[8];

    float totalWGP1 = 0, totalUnits1 = 0;
    float totalWGP2 = 0, totalUnits2 = 0;

    printf(" Enter Semester I Scores \n");
    for (int i = 0; i < 8; i++) {
        printf("Enter score for %s (%s): ", codes1[i], names1[i]);
        scanf("%d", &scores1[i]);
        if (scores1[i] < 0 || scores1[i] > 100) { 
            printf("Invalid score entered\n"); 
            return 0; 
        }
    }

    printf("\n--- Enter Semester II Scores ---\n");
    for (int i = 0; i < 8; i++) {
        printf("Enter score for %s (%s): ", codes2[i], names2[i]);
        scanf("%d", &scores2[i]);
        if (scores2[i] < 0 || scores2[i] > 100) { 
            printf("Invalid score entered\n"); 
            return 0; 
        }
    }

    //  GRADING LOGIC & CALCULATIONS
    for (int i = 0; i < 8; i++) {
        // Semester I 
        if (scores1[i] >= 80) { gp1[i] = 5.0; grade1[i] = 'A'; }
        else if (scores1[i] >= 70) { gp1[i] = 4.0; grade1[i] = 'B'; }
        else if (scores1[i] >= 60) { gp1[i] = 3.0; grade1[i] = 'C'; }
        else if (scores1[i] >= 50) { gp1[i] = 2.0; grade1[i] = 'D'; }
        else { gp1[i] = 0.0; grade1[i] = 'F'; }

        weighted1[i] = gp1[i] * units1[i];
        totalWGP1 += weighted1[i];
        totalUnits1 += (float)units1[i];

        // Semester II 
        if (scores2[i] >= 80) { gp2[i] = 5.0; grade2[i] = 'A'; }
        else if (scores2[i] >= 70) { gp2[i] = 4.0; grade2[i] = 'B'; }
        else if (scores2[i] >= 60) { gp2[i] = 3.0; grade2[i] = 'C'; }
        else if (scores2[i] >= 50) { gp2[i] = 2.0; grade2[i] = 'D'; }
        else { gp2[i] = 0.0; grade2[i] = 'F'; }

        weighted2[i] = gp2[i] * units2[i];
        totalWGP2 += weighted2[i];
        totalUnits2 += (float)units2[i];
    }

    //  ACADEMIC REPORT
    printf("\n==================== FULL ACADEMIC REPORT ====================\n");
    printf("%-12s %-7s %-7s %-5s %-7s %-10s\n", "Course Code", "Score", "Grade", "GP", "Units", "Weighted");
    
    // Semester I Table
    printf("\n--- SEMESTER ONE ---\n");
    for (int i = 0; i < 8; i++)
        printf("%-12s %-7d %-7c %-5.1f %-7d %-10.1f\n", codes1[i], scores1[i], grade1[i], gp1[i], units1[i], weighted1[i]);
    
    // Semester II Table
    printf("\n--- SEMESTER TWO ---\n");
    for (int i = 0; i < 8; i++)
        printf("%-12s %-7d %-7c %-5.1f %-7d %-10.1f\n", codes2[i], scores2[i], grade2[i], gp2[i], units2[i], weighted2[i]);

    // SUMMARY OUPUT
    float gpa1 = totalWGP1 / totalUnits1;
    float gpa2 = totalWGP2 / totalUnits2;
    float cgpa = (totalWGP1 + totalWGP2) / (totalUnits1 + totalUnits2);

    printf("\n--------------------------------------------------------------\n");
    printf("Semester I GPA: %.2f\n", gpa1);
    printf("Semester II GPA: %.2f\n", gpa2);
    printf("CGPA: %.2f\n", cgpa);

    // Classification Logic 
    printf("Classification: ");
    if (cgpa >= 4.40) printf("First Class\n");
    else if (cgpa >= 3.60) printf("Second Class Upper\n");
    else if (cgpa >= 2.80) printf("Second Class Lower\n");
    else if (cgpa >= 2.00) printf("Pass\n");
    else printf("Fail\n");

    return 0;
}