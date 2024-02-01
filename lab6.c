#include <stdio.h>

void read();
void replace(char *, char *, char *);
int find(char *, char *);

char STR[100], PAT[100], REP[100];
int len = 0;

void main()
{
  read();
}

void read()
{
  int i;
  printf("\n enter the main string :\n");
  gets(STR);
  printf("enter the pattern string :\n");
  gets(PAT);
  if (STR[0] == '\0' || PAT[0] == '\0')
    printf("string is empty\n");
  else
  {
    for (i = 0; PAT[i] != '\0'; i++)
      len++;
    if (find(STR, PAT) == 1)
    {
      printf("enter the replace string:\n");
      gets(REP);
      replace(STR, PAT, REP);
    }
    else
      printf("pattern is not found\n");
  }
}

int find(char *s, char *p)
{
  int i = 0, m = 0;
  while (s[i] != '\0')
  {
    if (s[i] == p[m])
      m++;
    else
      m = 0;
    if (m == len)
      break;
    i++;
  }
  if (m == len)
    return 1;
  else
    return 0;
}

void replace(char *s, char *p, char *r)
{
  int k, i = 0, m = 0, c = 0, j = 0;
  char temp[100];
  while (s[c] != '\0')
  {
    if (s[m] == p[i])
    {
      i++;
      m++;
      if (p[i] == '\0')
      {
        for (k = 0; r[k] != '\0'; k++, j++)
          temp[j] = r[k];
        i = 0;
        c = m;
      }
    }
    else
    {
      temp[j] = s[c];
      j++;
      c++;
      m = c;
      i = 0;
    }
  }
  temp[j] = '\0';
  printf("\n the resultant string is %s", temp);
}