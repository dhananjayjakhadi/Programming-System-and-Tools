#include<stdio.h>
#include<stdlib.h>
char first_name[]="Dhananjay";
char last_name[]="Jakhadi";
int myStrStr(char haystack[], char needle[], char buffer[])
{
    int m,n,i,j,a,b;
    m = strlen(haystack);
    n = strlen(needle);

    for(i=0;i<(m-n+1);i++)
    {
        for(j=0;j<n;j++)
        {
            if(haystack[i+j]!=needle[j])
            {
                break;
            }
            else
            {
                if (j == n-1)
                printf("%d",&i);
                    b = 0;
                for(a=i;a<i+n;a++)
                {
                    buffer[b] = haystack[a];
                b++;
                }
                 buffer[b]='\0';
                return 1;
            }
        }
    }
    return 0;
}


void findJediName(char* first, char* last, char buffer[])
{
  int i,j,k=0;
  if(strlen(last)>=3 && strlen(first)>=2)
  {
  for(i=0;i<=2;i++)
  {
      buffer[k]= *last;
      last++;
      k++;
  }
   if( first[0] >= 65 && first[0] <=87){ first[0]=first[0]+32;}
 // first[0] = first[0] +32;
  for(j=0;j<=1;j++)
  {
      buffer[k] = *first;
      first++;
      k++;
  }
  } else {
  printf("\t\tInvalid String\n");}
int l;
  for(l=5;l<10;l++){
  buffer[l]='\0';
  }
}
int findAllJediNames(char * filename, char buffer[50][10])
{
    char lastname[300];
    char firstname[300];

    int i,j;
    int z=0;
    FILE *fp;
    char line[200];
    fp = fopen("names.txt","r");
    if( fp != NULL)
    {

        while(!feof(fp)){

            fgets(line,200,fp);
            {
                int p=0,c=0;
                while(line[p]!=',')
                    {
                        lastname[c]=line[p];
                        p++;
                        c++;
                    }
                        p++;
                        lastname[c]='\0';

                        int d=0;
                while(line[p]!='\0')
                    {
                        firstname[d]=line[p];
                        p++;
                        d++;
                    }
            firstname[d]='\0';

            int e=0;
            for(i=0;i<=2;i++)
                {

                    buffer[z][i] = lastname[i];
                    e++;
                }
                int a = 3;

            for(j=0;j<=1;j++)
                {
                    if( j==0){ firstname[0] = firstname[0]+32; }

                    buffer[z][a] = firstname[j]; a++;
                    e++;
                }
                buffer[z][a]='\0';


                z++;

            }


    }
    }
     fclose(fp);
     return z;
}

