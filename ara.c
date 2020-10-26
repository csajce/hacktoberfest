#include<stdio.h>
#include<stdlib.h>
struct node
{
    int ProcessID;
    int busttime;
    int startingtime;
    int waitingtime;
    int leftback;
    int turnaroundtime;
    struct node *link;
};

void main()
{
    int i;
    int root=1;
    int id;
    int bustt;
    int k;
    int chip=0;
    int count;
    int pitin;
    int totalwait,totalturn;
    int currenttime;
    int timeslice;
    struct node *temp, *head,*tail,*ptr1,*ptr,*temp1;
    printf("Enter the Time Slice");
    scanf("%d",&timeslice);
    while(root=1)
    {
        temp=(int*)malloc(sizeof(struct node*));

        if (temp==NULL)
        {
            printf("Memmory overflow");
            break;
        }
        else
        {
            printf("3455");
            temp->link=NULL;
            printf("456");
            printf("Enter The process ID");
            scanf("%d",&id);
            printf("123");
            temp->ProcessID=id;
            printf("345");
            printf("Enter Bust Time ");
            scanf("%d",&bustt);
            temp->leftback=bustt;
            temp->busttime=bustt;
            if (head==NULL)
            {
                head=temp;
            }
            else
            {
                ptr=head;
                while (ptr->link!=NULL)
                {
                    ptr=ptr->link;
                }
                ptr->link=temp;
            }
        }
            printf("Do You Want Enter another Process? Yes-1 & No- 0");
            scanf("%d",&root);
    }
    printf ("\n \n Deatails You Enterd\n" );
    ptr=head;
    count=0;
    while(ptr!=NULL)
    {
        printf("\nProcess ID=%d",ptr->ProcessID);
        printf("\nBust Time=%d",ptr->busttime);
        ptr=ptr->link;
        count=count+1;
    }
    currenttime=0;
    pitin=0;
    ptr=head;
    while (ptr->link!=NULL)
    {
        ptr=ptr->link;
    }
    ptr->link=head;
    ptr=head;
    while(chip<=count)
    {
        if (ptr->leftback==0)
        {
            ptr=ptr->link;
        }
        else
        {
            while(pitin<=timeslice)
            {
              if (ptr->busttime==ptr->leftback)
               {
                  ptr->waitingtime=currenttime;
                  ptr->startingtime=currenttime;

               }
                currenttime=currenttime+1;
                ptr->leftback=ptr->leftback-1;
                pitin=pitin+1;
                if (ptr->leftback==0)
                {
                    ptr->turnaroundtime=currenttime-ptr->startingtime;
                    ptr=ptr->link;
                    chip=chip+1;
                    break;
                }

            }


        }

    }
    ptr=head;
    while(ptr->link!=head)
    {
        ptr=ptr->link;

    }
    ptr->link=NULL;
    ptr=head;
    totalwait=0;
    totalturn=0;
    while(ptr!=NULL)
    {
        printf("\n The Process ID=%d",ptr->ProcessID);
        printf("\nThe Waiting Time=%d",ptr->waitingtime);
        printf("\nTurn Around TIme=%d",ptr->turnaroundtime);
        printf("\n Bust Time =",ptr->busttime);
        totalwait=totalwait+ptr->waitingtime;
        totalturn=totalturn+ptr->turnaroundtime;
        ptr=ptr->link;

    }
    totalwait=totalwait/count;
    totalturn=totalturn/count;
    printf("Average Waiting Time= %d",totalturn);
    printf("Averaga Turn Around Time=%d",totalturn);




}
