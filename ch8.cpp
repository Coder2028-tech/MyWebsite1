#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define H 10
#include <time.h>
#include "Level1.h"


// #1

void repeating_digits() {

    printf("\n\nYou entered 1: Finding what digits were repeated in a number sequence. \n\n");

    int digit;
    long n;
    int digit_seen[10] = { 0 };

    printf("Enter a number: ");
    n = get_num();

    while (n > 0) {
        digit = n % 10;
        digit_seen[digit]++;
        n /= 10;
    }

    printf("Repeated digit(s): ");


    for (digit = 0; digit <= 9; digit++) {
        if (digit_seen[digit] > 1) {
            printf("%d ", digit);
            digit_seen[digit] = 0;
        }

    }
}
// #2

void repeating_digits_refined() {
    printf("\n\nYou entered 2: Finding what digits were repeated in a number sequence, more refined \n\n");

    long n;
    int digit;
    int digit_seen[10] = { 0 };

    printf("Enter a number: ");
    n = get_num();

    while (n > 0) {
        digit = n % 10;
        digit_seen[digit]++;
        n /= 10;
    }

    printf("Digit: %5c 0 1 2 3 4 5 6 7 8 9\n", ' ');
    printf("Occurrences: ");

    for (digit = 0; digit <= 9; digit++) {
        printf("%d ", digit_seen[digit]);
        digit_seen[digit] = 0;
    }
}

// #4


void reversing_digits() {
    printf("\n\nYou entered 3: Reversing a series of numbers.\n\n");

    char a[10];
    int i;

    int N = (int)(sizeof(a) / sizeof(a[0]));
    printf("Enter 10 numbers: ");
    for (i = 0; i < 10; i++)
        a[i] = getchar() - 48;

    printf("In reverse order: ");
    for (i = N - 1; i >= 0;i--)
        printf("%d", a[i]);
}

// #7

void row_column_sums() {

    printf("\n\nYou Entered 4: Calculating the sums of rows and columns in a 5x5 table.\n\n");

#define S 5

    int grid[S][S] = { 0 };
    int row, column;
    int row_total[S] = { 0 };
    int column_total[S] = { 0 };

    for (row = 0; row < S; row++) {
        printf("Enter row %d (%d numbers): ", row + 1, S);
        for (column = 0; column < S; column++) {
            scanf("%d,", &grid[row][column]);
            row_total[row] += grid[row][column];
            column_total[column] += grid[row][column];
        }
        getchar(); // to get rid of \n value in char
    }
    printf("Row totals: ");

    for (int row = 0; row < 5; row++) {
        printf("%d ", row_total[row]);
    }
    printf("\nColumn totals: ");

    for (int column = 0; column < 5; column++) {
        printf("%d ", column_total[column]);
    }
}

// #13

void first_last_name_refined() {

    printf("\n\nYou Entered 5: Displaying last name and first initial more refined.\n\n");

#define K 20
    char last_name[K] = { 0 };
    char first_initial;
    char ch = ' ';
    int c = 0;

    printf("Enter a first and last name: ");
    while (ch == ' ')
        ch = getchar();

    first_initial = ch;

    while (ch != ' ')
        ch = getchar();

    while (ch == ' ')
        ch = getchar();

    while (ch != '\n')
    {
        last_name[c] = ch;
        c++;
        ch = getchar();
    }

    for (int i = 0; i < K; i++)
        printf("%c", last_name[i]);

    printf(", %c.", first_initial);

}

// #14

void reversing_sentences() {

    printf("\n\nYou Entered 7: Reversing a sentence.\n\n");

#define W 10

    char sentence[W][W] = { 0 };
    int words = 0;
    int chars = 0;
    char ch = ' ';
    char last_mark;
    printf("Enter a sentence or question: ");
    while (ch == ' ')
        ch = getchar();
    ungetc(ch, stdin);
    while (ch != '?' && ch != '.' && ch != '!' && ch != '\n')
    {
        ch = getchar();
        chars++;
        if (ch != '?' && ch != '.' && ch != '!' && ch != '\n')
            sentence[words][chars] = ch;
        if (ch == ' ')
        {
            words++;
            chars = 0;
        }
    }

    last_mark = ch;
    for (int chars = 0; chars < W; chars++)
        printf("%c", sentence[words][chars]);

    printf(" ");

    for (int i = words - 1; i >= 0; i--)
    {
        for (int chars = 0; chars < W; chars++)
            printf("%c", sentence[i][chars]);
    }

    printf("%c", last_mark);

}

//#15

void encryption() {

    printf("\n\nYou entered 8: Encrypting a message\n\n");


#define M 80

    int shift_amount;
    char sentence[M] = { ' ' };
    char encrypt[M] = { ' ' };
    char ch = ' ';
    int len = 0;


    printf("Enter a sentence for encryption: ");

    while (ch != '\n')
    {
        ch = getchar();
        sentence[len] = ch;
        len++;
    }

    printf("Enter a shift amount: ");
    scanf("%d", &shift_amount);

    for (int i = 0; i <= len; i++) {
        if (sentence[i] <= 90 && sentence[i] >= 65)
            encrypt[i] = ((sentence[i] - 'A') + shift_amount) % 26 + 'A';
        else if (sentence[i] >= 97 && sentence[i] <= 122)
            encrypt[i] = ((sentence[i] - 'a') + shift_amount) % 26 + 'a';
        else
            encrypt[i] = sentence[i];

    }

    for (int i = 0; i <= len; i++)
        printf("%c", encrypt[i]);
}


bool valid_move(char walk[H][H], int r, int c) {
    if ((r >= 0 && r < H) && (c >= 0 && c < H)) {

        if (walk[r][c] == '.')
            return true;
    }
    return false;
}

bool any_valid_moves(char walk[H][H], int r, int c) {

    bool answer = valid_move(walk, r - 1, c) ||
        valid_move(walk, r + 1, c) ||
        valid_move(walk, r, c - 1) ||
        valid_move(walk, r, c + 1);

    return answer;

}
// #9

void random_walk_program() {
    printf("\n\nYou Entered 6: Going through a random walk program. \n\n");

    srand((unsigned)time(NULL));
    char walk[H][H] = { '.' };
    int row = 0, col = 0;
    char c = 'A';
    int r = 0;
    int direction;
    int fail = 0;


    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < H; j++)
        {
            walk[i][j] = '.';
        }
    }

    walk[row][col] = c;
    c++;

    while (1) {
        if (c > 'Z')
            break;
        if (!any_valid_moves(walk, row, col))
            break;

        direction = rand() % 4;

        if (fail >= 0) {

            switch (direction) {

            case 0:
                if (valid_move(walk, row - 1, col)) { // up
                    row--;
                    walk[row][col] = c;
                    c++;
                }
                fail++;
            case 1:
                if (valid_move(walk, row + 1, col)) { // down
                    row++;
                    walk[row][col] = c;
                    c++;
                }
                fail++;
            case 2:
                if (valid_move(walk, row, col - 1)) { // left
                    col--;
                    walk[row][col] = c;
                    c++;
                }
                fail++;
            case 3:
                if (valid_move(walk, row, col + 1)) { // right
                    col++;
                    walk[row][col] = c;
                    c++;
                }
                fail++;
            }
        }
        fail = 0;
    }
    // printing

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < H; j++)
        {
            printf("%c", walk[i][j]);
        }
        printf("\n");
    }
}

// # 1

void row_column_sums_refined() {
    printf("You entered 9: Calculating sums and rows - preset and refined.\n\n");

#define L 20

    int grid[L][L] = { 0 };
    int row, column;
    int row_total[L] = { 0 };
    int column_total[L] = { 0 };

    for (row = 0; row < L; row++) {
        for (column = 0; column < L; column++) {
            grid[row][column] = row * 100 + column;
            row_total[row] += grid[row][column];
            column_total[column] += grid[row][column];
        }
    }

    // printing array

    for (row = 0; row < L; row++) {
        for (column = 0; column < L; column++) {
            printf("%d ", grid[row][column]);
            if (row <= 9) {
                printf(" ");
            }
        }
        printf("\n");
    }
    printf("Row totals: ");

    for (int row = 0; row < L; row++) {
        printf("%d ", row_total[row]);
    }
    printf("\nColumn totals: ");

    for (int column = 0; column < L; column++) {
        printf("%d ", column_total[column]);
    }
}

// # 3

void ascending_order() {
    printf("You entered 10: Sorting numbers into ascending order.\n\n");
#define N 6
    int nums[N] = { 0 };
    int max;

    printf("Enter a series of %d numbers: ", N);

    for (int i = 0; i < N; i++)
    {
        scanf("%d, ", &nums[i]);
    }


    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++) {
            if (nums[i] > nums[j]) {
                max = nums[i];
                nums[i] = nums[j];
                nums[j] = max;
            }
        }
    }

    for (int i = 0; i < N; i++)
        printf("%d ", nums[i]);

}
// # 4

void descending_order() {
    printf("You entered 11: Sorting numbers into descending order.\n\n");
#define N 6
    int nums[N] = { 0 };
    int min;

    printf("Enter a series of %d numbers: ", N);

    for (int i = 0; i < N; i++)
    {
        scanf("%d, ", &nums[i]);
    }


    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++) {
            if (nums[i] < nums[j]) {
                min = nums[i];
                nums[i] = nums[j];
                nums[j] = min;
            }
        }
    }

    for (int i = 0; i < N; i++)
        printf("%d ", nums[i]);

}
// # 8

void rotating_numbers() {
    printf("You entered 12: Rotating a series of numbers\n\n");
#define P 10
    int nums[P] = { 0 };
    int count = 0;
    int rot = 0;
    int last = 0;
    int d = 0;

    printf("Enter a series of numbers (enter 0 to terminate program): ");

    for (int i = 0; i < P; i++) {
        scanf("%d", &nums[i]);
        if (nums[i] == 0)
            break;
        count++;
    }

    printf("Input: ");
    for (int i = 0; i < count; i++)
        printf("%d ", nums[i]);

    printf("\nEnter a rotation number: ");
    scanf("%d", &rot);

    for (int c = 0; d < rot; d++)
    {
        last = nums[c];
        for (int j = 0; j < count; j++)
        {
            nums[j] = nums[j + 1];
        }
        nums[count - 1] = last;
    }

    printf("New List: ");

    for (int i = 0; i < count; i++)
        printf("%d ", nums[i]);
}

// # 9
void matrix_adding() {
    printf("You entered 13: Adding diagonals in a square matrix.\n\n");
#define w 20
    int size;
    int elements[w][w] = { 0 };
    int total_right = 0;
    int total_left = 0;

    printf("Enter size of the square matrix: ");
    scanf("%d", &size);

    printf("Enter elements in the first matrix: ");

    for (int row = 0; row <= size; row++)
    {
        for (int column = 0; column <= size; column++)
        {
            scanf("%1d", &elements[row][column]);
        }
    }

    printf("Elements in the first matrix: ");

    printf("\n");
    for (int row = 0; row <= size; row++)
    {
        for (int column = 0; column <= size;column++)
        {
            printf("%d ", elements[row][column]);
        }
        printf("\n");
    }


    printf("Sum of the right diagonal: ");

    for (int row = 0, column = 0; row <= size; row++)
    {
        column = row;
        total_right += elements[row][column];
    }

    printf("%d\n", total_right);

    printf("Sum of the left diagonal: ");

    for (int row = size, column = 0; row >= 0; row--)
    {
        column = row;
        total_left += elements[row][column];
    }

    printf("%d", total_left);
}
// # 5

void deleting_with_positions() {
    printf("You entered 14: Deleting a number in a set position.\n\n");
#define R 10

    int nums[20] = { ' ' };
    int del;
    int count = 0;
    int c = 0;

    printf("Enter a list of numbers (enter 0 to terminate): ");

    for (int i = 0; i < R; i++)
    {
        scanf("%d, ", &nums[i]);
        if (nums[i] == 0)
            break;
        count = i;
    }


    printf("Enter a position to delete: ");
    scanf("%d", &del);

    for (c = del; c < count; c++)
    {
        nums[c] = nums[c + 1];
    }

    for (int c = 0; c < count; c++)
    {
        printf("%d ", nums[c]);
    }

}

// # 6 

void deleting_with_numbers() {

    printf("You entered 15: Deleting a number from a series.\n\n");
#define D 10

    int nums[20] = { ' ' };
    int del;
    int count = 0;
    int counter = 0;

    printf("Enter a list of numbers (enter 0 to terminate): ");

    for (int i = 0; i < D; i++)
    {
        scanf("%d, ", &nums[i]);
        if (nums[i] == 0)
            break;
        count = i;
    }

    printf("Enter a number to delete: ");
    scanf("%d", &del);

    for (int c = 0; c <= count; c++)
    {
        if (nums[c] == del)
        {
            counter++;
            printf("%d\n", counter);
            for (int j = c; j < count; j++)
            {
                nums[j] = nums[j + 1];
            }
            nums[count] = 0;
        }
    }

    for (int c = 0; c <= count - counter; c++)
    {
        printf("%d ", nums[c]);

    }
}

// # 7

void repeating_odd_amount() {
    printf("You entered 16: Seeing which numbers repeat odd amount of times.\n\n");
#define A 20

    int num[A] = { 8, 3, 8, 5, 4, 3, 4, 3, 5, 1, 7, 8, 9, 5, 6, 7, 4, 9, 2, 0 };
    int digit_seen[20] = { 0 };
    int digit = 0;

    printf("The given array is: ");

    for (int i = 0; i < A; i++)
    {
        printf("%d ", num[i]);
        digit = num[i];
        digit_seen[digit]++;
    }

    printf("\n\nThe element(s) odd number of times is: ");

    for (digit = 0; digit < A; digit++)
    {
        if (digit_seen[digit] % 2 == 1)
        {
            if (digit_seen[digit] != 1) {
                printf("%d ", digit);
                digit_seen[digit] = 0;
            }
        }
    }
}

int
mainchapter8()
{
    int options;
    printf("You are in chapter 8\n");
    printf("Here are the options you can run: \n\n");
    printf("Enter 1: Finding what digits were repeated in a number sequence. \n");
    printf("Enter 2: Finding what digits were repeated in a number sequence, more refined \n");
    printf("Enter 3: Reversing a series of numbers.\n");
    printf("Enter 4: Calculating the sums of rows and columns in a 5x5 table.\n");
    printf("Enter 5: Displaying last name and first initial more refined.\n");
    printf("Enter 6: Going through a random walk program. \n");
    printf("Enter 7: Reversing a sentence.\n");
    printf("Enter 8: Encrypting a message.\n");
    printf("Enter 9: Calculating sums and rows - preset and refined.\n");
    printf("Enter 10: Sorting numbers into ascending order.\n");
    printf("Enter 11: Sorting numbers into descending order.\n");
    printf("Enter 12: Roating a series of numbers\n");
    printf("Enter 13: Adding diagonals in a square matrix.\n");
    printf("Enter 14: Deleting a number in a set position.\n");
    printf("Enter 15: Deleting a number from a series.\n");
    printf("Enter 16: Seeing which numbers repeat odd amount of times.\n");
    printf("After reading the options, enter a number (1-16) to choose what function you want to call:");
    scanf("%d", &options);
    getchar();

    switch (options)
    {

    case 1:
        repeating_digits();
        break;
    case 2:
        repeating_digits_refined();
        break;
    case 3:
        reversing_digits();
        break;
    case 4:
        row_column_sums();
        break;
    case 5:
        first_last_name_refined();
        break;
    case 6:
        random_walk_program();
        break;
    case 7:
        reversing_sentences();
        break;
    case 8:
        encryption();
        break;
    case 9:
        row_column_sums_refined();
        break;
    case 10:
        ascending_order();
        break;
    case 11:
        descending_order();
        break;
    case 12:
        rotating_numbers();
        break;
    case 13:
        matrix_adding();
        break;
    case 14:
        deleting_with_positions();
        break;
    case 15:
        deleting_with_numbers();
        break;
    case 16:
        repeating_odd_amount();
        break;
    }
    return 0;
}
