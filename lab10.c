#include <stdio.h>
#include <stdlib.h>

struct node
{
  int info;
  struct node *lt, *rt;
};

typedef struct node *NODE;

NODE root = NULL;

void inorder(NODE temp)
{
  if (temp != NULL)
  {
    inorder(temp->lt);
    printf("%d\t", temp->info);
    inorder(temp->rt);
  }
}

void preorder(NODE temp)
{
  if (temp != NULL)
  {
    printf("%d\t", temp->info);
    preorder(temp->lt);
    preorder(temp->rt);
  }
}

void postorder(NODE temp)
{
  if (temp != NULL)
  {
    postorder(temp->lt);
    postorder(temp->rt);
    printf("%d\t", temp->info);
  }
}

void createbst()
{
  NODE temp, cur, prev;
  int ele;
  temp = (NODE)malloc(sizeof(struct node));
  temp->lt = temp->rt = NULL;
  printf("\nEnter the element\n");
  scanf("%d", &ele);
  temp->info = ele;
  if (root == NULL)
  {
    root = temp;
    return;
  }
  prev = NULL;
  cur = root;
  while (cur != NULL)
  {
    prev = cur;
    if (ele == cur->info)
    {
      printf("duplicate");
      free(temp);
      return;
    }
    if (ele < cur->info)
      cur = cur->lt;
    else
      cur = cur->rt;
  }
  if (ele < prev->info)
    prev->lt = temp;
  else
    prev->rt = temp;
}

int search()
{
  int key;
  NODE temp;
  printf("Enter the key element to be search\n");
  scanf("%d", &key);
  temp = root;
  while (temp != NULL)
  {
    if (temp->info == key)
      return 1;
    else if (key > temp->info)
      temp = temp->rt;
    else
      temp = temp->lt;
  }
  return 0;
}

void main()
{
  int ch;
  while (1)
  {
    printf("\n\n1.create BST\n2.Traversals\n3.search\n4.exit\n");
    printf("Enter the choice\n");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
      createbst();
      break;
    case 2:
      if (root == NULL)
        printf("\nBST is Empty\n");
      else
      {
        printf("\n\nINORDER:");
        inorder(root);
        printf("\n\nPREORDER:");
        preorder(root);
        printf("\n\nPOSTORDER:");
        postorder(root);
      }
      break;
    case 3:
      if (root == NULL)
        printf("\nBST is Empty\n");
      else
      {
        if (search() == 0)
          printf("The key element is not present\n");
        else
          printf("The key element is present in BST\n");
      }
      break;
    case 4:
      exit(0);
    default:
      printf("\ninvalid choice\n");
      break;
    }
  }
}