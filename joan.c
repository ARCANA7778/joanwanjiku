  #include<stdio.h>

#define TRUE 1
#define FALSE 0

int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
char *months[] = {"", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

int inputyear() {
    int year;
    printf("Please enter a year: ");
    scanf("%d", &year);
    return year;
}

void determineleapyear(int year) {
    if ((year % 4 == FALSE && year % 100 != FALSE) || (year % 400 == FALSE)) {
        days_in_month[2] = 29;
    }
}

int determinedaycode(int year) {
    int daycode;
    daycode = (year + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400) % 7;
    return daycode;
}

void calender(int year, int daycode) {
    int month, day;
    for (month = 1; month <= 12; month++) {
        printf("\n\n\n%s", months[month]);
        printf("\n\nSun   Mon   Tue   Wed   Thu   Fri   Sat\n");
 
        for (day = 1; day <= 1 + daycode * 6; day++) {
            printf(" ");
        }
 
        for (day = 1; day <= days_in_month[month]; day++) {
            printf("%2d", day);
 
            if ((day + daycode) % 7 > 0) {
                printf("    ");
            } else {
                printf("\n ");
            }
        }
 
        daycode = (daycode + days_in_month[month]) % 7;
    }
}

int main() {
    int year, daycode, leapyear;
    year = inputyear();
    daycode = determinedaycode(year);
    determineleapyear(year);
    calender(year, daycode);
    printf("\n");
    return 0;
}             
                                                          
         
