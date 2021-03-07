//BINARY TREE PROGRAM!!!

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

typedef struct node *NODE;

NODE Insert(NODE);
void Disp(NODE);
NODE Search(NODE, int, NODE*);
void Inorder(NODE);
void Preorder(NODE);
void Postorder(NODE);
NODE Delete(NODE);
int heighttree(NODE);
NODE createcopy(NODE);

// PN= Parent Node, NS= Node Search, CN= Child Node, NN= New Node, ND= Node deletion
void main()
{
    int ch,key;
    NODE Root = NULL, NS = NULL, PN = NULL;
    for(;;)
    {
        printf("1:Insert\n2:Disp\n3:Search\n4:Delete\n5:Height of tree\n6:CreateCopy\n");
        printf("Enter choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: Root = Insert(Root); break;
            case 2: Disp(Root); break;
            case 3: printf("enter the key of node to be searched:\n");
                    scanf("%d",&key);
                    if(Root->data == key)
                    {
                        printf("searching node data = %d and No parent for the root n",Root->data);
                    }
                    else
                    {
                        NS = Search(Root,key, &PN);
                        if(NS == NULL)
                            printf("Node doesn't exist\n");
                        else
                            printf("Searching node data = %d and its parent is: %d\n", NS->data, PN->data);
                    }
                    break;
            case 4: Root = Delete(Root); Disp(Root); break;
            case 5: printf("Height of the tree: %d\n",heighttree(Root)); break;
            case 6: createcopy(Root); Disp(Root); break;
            default: exit(0);
        }
    }
}

NODE Insert(NODE R)
{
    NODE NN, CN, PN;
    int i;
    char dir[6];
    NN = (NODE) malloc(sizeof(struct node));
    printf("enter info:");
    scanf("%d",&NN->data);
    NN->left = NN->right = NULL;
    if(R==NULL)
        return NN;
    L1: printf("enter direction:\n");
    scanf("%s",dir);
    CN = R;
    PN = NULL;
    for(i = 0; i<strlen(dir); i++)
    {
        PN = CN;
        if(CN == NULL)
            break;
        if(dir[i] == 'L')
            CN = CN->left;
        else
            CN = CN->right;
    }
    if(i!=strlen(dir) || CN !=NULL)
    {
        printf("insertion of newnode in this direction not possible,read new direction\n");
        goto L1;
    }
    if(dir[i-1] == 'L')
        PN->left = NN;
    else
        PN->right = NN;
    return R;
}

void Disp(NODE R)
{
    int ch;
    if(R==NULL)
    {
        printf("Tree empty\n");
        return;
    }
    printf("\nInorder Traversal is:");
    Inorder(R);
    printf("\nPreorder Traversal is:");
    Preorder(R);
    printf("\nPostorder Traversal is:");
    Postorder(R);
}

void Inorder(NODE R)
{
    if(R==NULL)
        return;
    Inorder(R->left);
    printf("%d",R->data);
    Inorder(R->right);
}

void Preorder(NODE R)
{
    if(R==NULL)
        return;
    printf("%d",R->data);
    Preorder(R->left);
    Preorder(R->right);
}

void Postorder(NODE R)
{
    if(R==NULL)
        return;
    Postorder(R->left);
    Postorder(R->right);
    printf("%d",R->data);
}

NODE Search(NODE R,int key, NODE *PN)
{
    NODE NS = NULL;
    if(R==NULL)
        return NULL;
    if(R->data == key)
    {
        NS = R;
    }
    if(NS == NULL)
    {
        *PN = R;
        NS = Search(R->left,key,PN);
    }
    if(NS == NULL)
    {
        *PN = R;
        NS = Search(R->right,key,PN);
    }
    return NS;
}

NODE Delete(NODE R) //delete node
{
    int key;
    NODE ND = NULL, PN = NULL, IS, ISP;
    if(R == NULL)
    {
        printf("tree empty\n");
        return NULL;
    }
    printf("enter key of the node to be deleted:\n");
    scanf("%d",&key);

    if(R->data == key && R->left == NULL && R->right ==NULL)
    {
        printf("deleted:%d\n",R->data);
        free(R);
        return NULL;
    }
    ND = Search(R,key, &PN);
    if(ND == NULL)
    {
        printf("Node doesn't exist\n");
        return R;
    }
    printf("node to be deleted is %d and it's parent is:%d\n",ND->data,PN->data);
    // CASE 1  IF NODE TO BE DELETED IS LEAF NODE 
    if(ND->left == NULL && ND->right == NULL)
    {
        if(ND == PN->left)
            PN->left = NULL;
        else
            PN->right = NULL;
            printf("deleted:%d\n",ND->data);
            free(ND);
            return R;
    }
    else   // CASE 2  IF NODE TO BE DELETED HAS ONLY ONE CHILD
    if(ND->left != NULL && ND->right == NULL || ND->left ==NULL && ND->right!=NULL)
    {
        if(ND->right == NULL)
        {
            if(ND == PN->right)
                PN->right = ND->left;
            else
                PN->left = ND->left;
        }
        else
        if(ND->left == NULL)
        {
            if(ND == PN->right)
                PN->right = ND->right;
            else
                PN->left = ND->right;
        }
        printf("deleted:%d\n",ND->data);
        free(ND);
        return R;
    }
    else  //CASE 3  IF NODE TO BE DELETED HAS 2 CHILDREN
    {
        IS = ND->right; // IS = INOREDER SUCCESSOR, ISP = INOREDER SUCESSOR'S PARENT
        ISP = ND;
        while(IS->left !=NULL)
        {
            ISP = IS;
            IS = IS->left;
        }
        printf("deleted:%d\n",ND->data);
        ND->data = IS->data;
        if(IS->left == NULL && IS->right == NULL)
        {
            if(IS == ISP->left)
                ISP->left = NULL;
            else
                ISP->right = NULL;
        }
        else
        {
            if(IS == ISP->left)
                ISP->left = IS->right;
            else
                ISP->right = IS->right;
        }
        free(IS);
        return R;
    }
}

int heighttree(NODE R)
{
    if(R==NULL)
        return 0;
    int leftheight = heighttree(R->left);
    int rightheight = heighttree(R->right);
    if(leftheight > rightheight)
        return leftheight+1;
    return rightheight+1;
}

NODE createcopy(NODE R)
{
    if(R==NULL)
        return  NULL;
    NODE temp = (NODE)malloc(sizeof(struct node));
    temp = R;
    temp->left = createcopy(R->left);
    temp->right = createcopy(R->right);
    temp->data  = R->data;
    return temp;
}

/*
void Count(NODE Root)
{
    if(Root == NULL)
        return 0;
    return 1 + Count(Root->left) + Count(Root->right);
}


int Countleaf(NODE Root)
{
    if(Root == NULL)
        return;
    if(Root->left == NULL && Root->right == NULL)
        return 1;
    else
        return Countleaf(Root->left) + Countleaf(Root->right);
}

int Countnonleaf(NODE Root)
{
    if(Root == NULL)
        return 0;
    if(Root->left == NULL && Root->right == NULL)
        return 0;
    else
        return 1+Countnonleaf(Root->left) + Countnonleaf(Root->right);
}

*/