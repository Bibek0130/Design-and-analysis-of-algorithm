#include <stdio.h>
#include<time.h>
int main()
{
	double time;
  int array[100], search, c, n;
  	clock_t start, end;

  printf("Enter number of elements in array\n");
  scanf("%d", &n);

  printf("Enter %d integer(s)\n", n);
 	start=clock();
  for (c = 0; c < n; c++)
    scanf("%d", &array[c]);

  printf("Enter a number to search\n");
  scanf("%d", &search);

  for (c = 0; c < n; c++)
  {
    if (array[c] == search)    /* If required element is found */
    {
      printf("%d is present at location %d.\n", search, c+1);
      break;
    }
  }
  if (c == n)
    printf("%d isn't present in the array.\n", search);
    end=clock();
    time=((double)(end-start)*1000)/CLOCKS_PER_SEC;
	printf("Time = %lf \t milli seconds",time);

  return 0;
}
