#include <stdio.h>
#include <math.h>

/*=========================================================================
  Constants and definitions:
==========================================================================*/

#define N 50
#define M 50
#define REST 4
#define TOP_LINE 0
#define LEFT_COLUMN 1
#define BOTTOM_LINE 2
#define RIGHT_COLUMN 3
#define DIVISION 2
#define FIRST_CELL 0

/* put your #defines and typedefs here*/
void compute_integral_image(int image[][M], int n, int m, int integral_image[][M]);
int sum_rect(int integral_image[][M], int rect[4]);
void sliding_average(int integral_image[][M], int n, int m, int h, int w, int average[][M]);
void print_array(int a[N][M], int n, int m);


/*-------------------------------------------------------------------------
  The main program. (describe what your program does here)
 -------------------------------------------------------------------------*/


int main() {

    int n = 0, m = 0;
    printf("Enter image dimensions:\n");
    scanf("%d%d", &n, &m);

    int image[N][M] = {{0}};
    printf("Enter image:\n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &image[i][j]);
        }
    }

    int h = 0, w = 0;

    printf("Enter sliding window dimensions:\n");
    scanf("%d%d", &h, &w);
    int integral_image[N][M];
    compute_integral_image(image, n, m, integral_image);
    printf("Integral image is:\n");
    print_array(integral_image, n, m);
    int average[N][M];
    sliding_average(integral_image, n, m, h, w, average);
    printf("Smoothed image is:\n");
    print_array(average, n, m);

    return 0;
}

void print_array(int a[N][M], int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            printf("%d", a[i][j]);
            if (j != m-1) {
                printf(" ");
            }
        }
        printf("\n");
    }
}

//calculate integral image
void compute_integral_image(int image[][M], int n, int m, int integral_image[][M]) {
    integral_image[FIRST_CELL][FIRST_CELL] = image[FIRST_CELL][FIRST_CELL];
    //calculate first column
    for (int k = 1; k < m; k++) {
        integral_image[FIRST_CELL][k]=integral_image[FIRST_CELL][k-1]+image[FIRST_CELL][k];
    }
    //calculate first line
    for (int l = 1; l < n; ++l) {
        integral_image[l][FIRST_CELL]=integral_image[l-1][FIRST_CELL]+image[l][FIRST_CELL];
    }
    //calculate internal of image
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            integral_image[i][j] = integral_image[i][j - 1] + integral_image[i - 1][j] - integral_image[i - 1][j - 1] + image[i][j];
        }
    }
}

//calculate sum of the window
int sum_rect(int integral_image[][M], int rect[REST]){
    int sum=0;
    //calculate internal window
    if((rect[TOP_LINE] != 0) && (rect[LEFT_COLUMN] != 0)) {
        sum = integral_image[rect[BOTTOM_LINE]][rect[RIGHT_COLUMN]] - integral_image[rect[TOP_LINE] - 1][rect[RIGHT_COLUMN]]
              - integral_image[rect[BOTTOM_LINE]][rect[LEFT_COLUMN] - 1] + integral_image[rect[TOP_LINE] - 1][rect[LEFT_COLUMN] - 1];
    }
    //calculate upper window
    if((rect[TOP_LINE] == 0) && (rect[LEFT_COLUMN] != 0)) {
        sum = integral_image[rect[BOTTOM_LINE]][rect[RIGHT_COLUMN]] - integral_image[rect[BOTTOM_LINE]][rect[LEFT_COLUMN] - 1];
    }
    //calculate left window
    if((rect[TOP_LINE] != 0) && (rect[LEFT_COLUMN] == 0)) {
        sum = integral_image[rect[BOTTOM_LINE]][rect[RIGHT_COLUMN]] - integral_image[rect[TOP_LINE] - 1][rect[RIGHT_COLUMN]];
    }
    //calculate upper and left window
    if((rect[TOP_LINE] == 0) && (rect[LEFT_COLUMN] == 0)) {
        sum = integral_image[rect[BOTTOM_LINE]][rect[RIGHT_COLUMN]];
    }
    return sum;
}

//Checking an exception from the window
void rest1(int rest[REST], int h,int w,int i,int j,int n,int m){
    //upper Exception
    if((i- h / DIVISION) < 0)
        rest[TOP_LINE]=0;
    else
        rest[TOP_LINE]= i - h / DIVISION;
    //left exception
    if((j- w / DIVISION) < 0)
        rest[LEFT_COLUMN]=0;
    else
        rest[LEFT_COLUMN]= j - w / DIVISION;
    //lower Exception
    if((i+ h / DIVISION) > n - 1)
    rest[BOTTOM_LINE]= n - 1;
    else
        rest[BOTTOM_LINE]= i + h / DIVISION;
    //right Exception
    if((j+ w / DIVISION) > m - 1)
        rest[RIGHT_COLUMN]= m - 1;
    else
        rest[RIGHT_COLUMN]= j + w / DIVISION;
    return;
}

//calculating average of the window
void sliding_average(int integral_image[][M], int n, int m, int h, int w, int average[][M]){
    int rest[REST];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <m ; ++j) {
            rest1(rest,h,w,i,j,n,m);
            average[i][j]=round((double)(sum_rect(integral_image,rest))/(h*w));
        }
    }
}