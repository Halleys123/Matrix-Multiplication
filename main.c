// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
int **matrix(int height, int width, int pro)
{
    int **matrix = (int **)malloc(sizeof(int) * height);
    for (int i = 0; i < height; i++)
    {
        matrix[i] = (int *)malloc(sizeof(int) * width);
    }
    if (pro == 0)
    {
        printf("Enter values in the matrix: \n");
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (pro == 0)
            {
                printf("[%d][%d] = ", i, j);
                scanf("%d", &matrix[i][j]);
            }
            else
                matrix[i][j] = 0;
        }
    }
    return matrix;
}
void matrixPrinter(int **matrix, int h, int w)
{
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int height1, width1;
    int height2, width2;
    int **matrix1, **matrix2;
    int r = 0, c = 0;

    printf("Enter width and height of 1st Matrix.\n");
    scanf("%d %d", &height1, &width1);

    matrix1 = matrix(height1, width1, 0);

    printf("\nEnter width and height of 2nd Matrix.\n");
    scanf("%d %d", &height2, &width2);
    matrix2 = matrix(height2, width2, 0);

    int **product = matrix(height1, width2, 1);
    printf("\n\n\nArrays you used are: \n\nA = \n");
    matrixPrinter(matrix1, height1, width1);
    printf("\n\nB = \n");
    matrixPrinter(matrix2, height2, width2);

    if (width1 == height2)
    {

        printf("Multiplication of these two matrices will be: \n\n");
        for (int i = 0; i < height1; i++)
        {
            for (int j = 0; j < width2; j++)
            {
                for (int k = 0; k < width1; k++)
                    product[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
        matrixPrinter(product, height1, width2);
    }
    else
    {
        printf("Multiplication is not possible for given matrices");
    }
    getch();
    return 0;
}