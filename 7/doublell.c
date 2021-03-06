#include<stdio.h>
#include<stdlib.h>
struct NODE
{
  int info;
  struct NODE *llink;
  struct NODE *rlink;
};
typedef struct NODE * node;
void InsertFront(node);
void InsertRear(node);
void DeleteFront(node);
void DeleteRear(node);
void Disp();
void InsertPos(node);
void DeletePos(node);
void DeleteKey(node);
void Search(node);
void main()
{
   int ch;
   node Head;   // L2=NULL;
   Head = (node)malloc(sizeof(struct NODE));
   Head->info = 0;
   Head->llink=Head->rlink = Head;
   for(;;)
   {
      printf("\nenter choice:\n1:InsertFront\n2:Disply\n3:InsertRear\n4:DeleteFront\n5:DeleteRear\n6:InsertByposition\n7:DeleteByposition\n8:DeleteByKey\n9:Search Key\n");
      scanf("%d",&ch);
      switch(ch)
      {
        case 1: InsertFront(Head);
                //printf("in main %d\n", first->info);
                Disp(Head);
                break;
        case 2: Disp(Head); break;
        case 3: InsertRear(Head); Disp(Head); break;
        case 4:  DeleteFront(Head); Disp(Head); break;
        case 5:  DeleteRear(Head); Disp(Head); break;
        case 6:  InsertPos(Head); Disp(Head); break;
        case 7:  DeletePos(Head); Disp(Head);break;

        case 8:  DeleteKey(Head);Disp(Head);break;
        case 9: Search(Head); break;

        default:exit(0);
     }
 }

 }

void InsertFront(node H)
    {
       node NN;
       int info;
       NN = (node)malloc(sizeof(struct NODE));
       printf("enter info field:");
       scanf("%d",&NN->info);
       NN->llink = H;
       NN->rlink = H->rlink;
       NN->rlink->llink = NN;
       H->rlink = NN;
       H->info++;
    }
void  InsertRear(node H)
    {
       node NN;
       int info;
       NN = (node)malloc(sizeof(struct NODE));
       printf("enter info field:");
       scanf("%d",&NN->info);


       NN->rlink = H;
       NN->llink = H->llink;
       H->llink->rlink = NN;
       H->llink = NN;
       H->info++;
         }


  void Disp(node H)
   {    node TP;
       if(H->info==0)
       {
         printf("empty\n");
         return;

         }
         TP = H->rlink;
       printf("\nList is:\n");
      while(TP!=H)
       {
          printf("%d ", TP->info);
          TP =TP->rlink;
      }
  }

void DeleteFront(node H)
  {  node ND;
     if(H->info==0)
       {
         printf("empty\n");
         return;
       }
       ND=H->rlink;
       printf("\ndeleted %d",ND->info);
      H->rlink = ND->rlink;
      ND->rlink->llink =H;
      H->info--;
      free(ND);
  }

 void DeleteRear(node H)
  {  node  ND;
     if(H->info==0)
       {
         printf("empty\n");
         return ;
       }
       ND = H->llink;
      printf("\ndeletd %d",ND->info);
      ND->llink->rlink = H;
      H->llink = ND->llink;
      H->info--;
      free(ND);

  }

void InsertPos(node H)
  {

       node NN,TN;
       int pos,cnt;
       int info;
       NN = (node)malloc(sizeof(struct NODE));
       printf("enter info field:");
       scanf("%d",&NN->info);

       printf("\nenter position   from 1 to %d:" ,H->info+1);
       scanf("%d",&pos);
       if(pos>=1 && pos<=H->info+1)
       {
          cnt= 1;
          TN = H;
          while(cnt<pos)
          {
             TN= TN->rlink;
              cnt++;
          }
          NN->rlink = TN->rlink;
          NN->llink = TN;
          TN->rlink = NN;
          NN->rlink->llink = NN;
          H->info++;
       }
       else
       printf("Invalid position\n");
 }

void  DeletePos(node H)
 {
    node  TN;
    int pos, cnt;
     if(H->info==0)
       {
         printf("empty\n");
         return ;
       }
        printf("\nenter position   from 1 to %d:" ,H->info);
       scanf("%d",&pos);
       if(pos>=1 && pos<=H->info)
       {
         TN = H->rlink;
         cnt = 1;
         while(cnt !=pos)
         {
           TN=TN->rlink ;
           cnt++;
         }
         TN->llink->rlink = TN->rlink;
         TN->rlink->llink = TN->llink;
         printf("Deleted %d\n",TN->info);
         free(TN);
         H->info--;
      }
      else
      printf("Invalid position retry\n");
 }



void DeleteKey(node H)
{
    node  TN;
    int pos, info;
     if(H->info==0)
       {
         printf("empty\n");
         return ;
       }
       printf("enter the info of the node to be deleted\n");
       scanf("%d", &info);
      TN = H->rlink;
      pos = 1;
      while(TN!=H && TN->info !=info)
      {
          TN=TN->rlink;  pos++;
      }
       if(TN == H)
       printf("Node does not exist\n");
       else
       {
         printf("node with the info %d is present at position %dis deleted \n", TN->info, pos);
         TN->llink->rlink = TN->rlink;
         TN->rlink->llink = TN->llink;
         free(TN);
         H->info--;
       }
}


void Search(node H)
{
    node  TN;
    int pos, info;
     if(H->info==0)
       {
         printf("empty\n");
         return ;
       }
       printf("enter the info of the node to be searched\n");
       scanf("%d", &info);
      TN = H->rlink;
      pos = 1;
      while(TN!=H && TN->info !=info)
      {
          TN=TN->rlink;  pos++;
      }
       if(TN == H)
       printf("Node does not exist\n");
       else

         printf("node with the info %dwhich  is present at position %d \n", TN->info, pos);

}


