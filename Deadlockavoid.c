#include<stdio.h>
int main()
{

    int noofresources;
    int i=0,j=0;
    printf("Enter no of resources\n");
    scanf("%d",&noofresources);
      int a[50],n;
      printf("Enter instances of each resource\n");
      for(i=0;i<noofresources;i++)
      {
          printf("\nResouce %d :",i+1);
          scanf("%d",&a[i]);
      }
      printf("Enter number of processes\n");
      scanf("%d",&n);
      int re[n][noofresources];
      int maxneed[n][noofresources];
      printf("Enter resources allocated to each process\n");
      for(i=0;i<n;i++)
      {
        for(j=0;j<noofresources;j++)
        {
            scanf("%d",&re[i][j]);
        }
      }
      printf("Resources allocated to process\n");
       for(i=0;i<n;i++)
      {
        for(j=0;j<noofresources;j++)
        {
            printf("%d ",re[i][j]);
        }
        printf("\n");
      }
      printf("Enter max need of each process\n");
      for(i=0;i<n;i++)
      {
        for(j=0;j<noofresources;j++)
        {
            scanf("%d",&maxneed[i][j]);
        }
      }

      int totalalloc[noofresources];
      int temp=0;

      for(i=0;i<noofresources;i++)
      {
          temp=0;
          for(j=0;j<n;j++)
          {
             temp+=re[j][i];

          }
          totalalloc[i]=temp;
      }
      printf("Current total allocated resuorces  :");
      for( i=0;i<noofresources;i++)
      {
          printf("%d ",totalalloc[i]);
      }
      printf("\n");
            int remneed[n][noofresources];
    for(i=0;i<n;i++)
    {
        for(j=0;j<noofresources;j++)
        {
            remneed[i][j]=maxneed[i][j]-re[i][j];;
        }
      }

      printf("Remaining need\n");
           for(i=0;i<n;i++)
      {
        for(j=0;j<noofresources;j++)
        {
            printf("%d  ",remneed[i][j]);
        }
        printf("\n");
      }

      int remneed1[n][noofresources],  maxneed1[n][noofresources];
      int total1[n][noofresources];
      int availble1=a[0]-totalalloc[0];
      int availble2=a[1]-totalalloc[1];
      int availble3=a[2]-totalalloc[2];
      int noofcomplete=0,noofin=0;
      printf("order of execution  is \n");
        for(i=0;i<n;i++)
      {

            if(remneed[i][0]<=availble1 && remneed[i][1]<=availble2 &&remneed[i][1]<=availble3)
           {
               noofcomplete++;
               printf("Currently available instances of resources : %d  %d  %d\n",availble1,availble2,availble3);

               printf("process with maxneed of resources %d %d %d is executed \n ",maxneed[i][0],maxneed[i][1],maxneed[i][2]);
               availble1=re[i][0]+availble1;
                availble2=re[i][1]+availble2;
                 availble3=re[i][2]+availble3;


        }
        else
        {
          remneed1[i][0]=remneed[i][0];
           remneed1[i][1]=remneed[i][1];
            remneed1[i][2]=remneed[i][2];
            total1[i][0]=re[i][0];
           total1[i][1]=re[i][1];
            total1[i][2]=re[i][2];
        maxneed1[i][0]=maxneed[i][0];
           maxneed1[i][1]=maxneed[i][1];
            maxneed1[i][2]=maxneed[i][2];
            noofin++;
        }

        }
    //    printf("no of complete %d\n ",noofcomplete);
      //      printf("no of incomplete %d\n ",noofin);

            if(noofin==0)
      {
          printf("system is safe");

      }

      else
      {
         for(i=0;i<=noofin;i++)
      {

            if(remneed1[i][0]<=availble1 && remneed1[i][1]<=availble2 &&remneed1[i][1]<=availble3)
           {
               noofcomplete++;
               printf(" Currently available instances of resources : %d  %d  %d\n",availble1,availble2,availble3);

              printf("process with maxneed of resources %d %d %d is executed\n ",maxneed1[i][0],maxneed1[i][1],maxneed1[i][2]);
               availble1=re[i][0]+availble1;
                availble2=re[i][1]+availble2;
                 availble3=re[i][2]+availble3;


        }


      }
      }
      printf("no of complete %d\n",noofcomplete);
      if(noofcomplete<n)
      {
          printf("System is unsafe\n");

      }
      else
      {
          printf("System is safe\n");
      }




}
