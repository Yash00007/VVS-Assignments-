#include<stdio.h>
#include<stdlib.h>

struct node {
int data;
struct node * left;
struct node * right;
};
struct node * root= NULL;

struct node * findmax(struct node *,int);
struct node * findmin(struct node *,int);
int delete(int data);
struct node * create_node(int data){


struct node * new = (struct node *)malloc(sizeof(struct node));
new->data = data;
new->left = new->right = NULL;


return new;
}

int insert(int data){
struct node * temp;
struct node * new = create_node(data);
if(root == NULL)
{
/*This means that BST is empty*/
   root = new ;
   return 0;

}
else
{

   temp = root;
   while(1){
   if(temp == NULL)
   return 0;
    
 
   if( (data < temp->data ) && (temp->left == NULL) )   
   {
      temp->left = new; 
      return 0;
   }
   if((data >= temp->data)&& (temp->right == NULL))
   {
      temp->right = new; 
      return 0;
   }
   
   if(data < temp->data)
      temp = temp->left;
   else
      temp = temp->right;
   } 
}

}

  int inorder(struct node * temp){
     
     if(temp == NULL)
        return 0;
     inorder(temp->left);
     printf("%d ",temp->data );
     inorder(temp->right);

 
  }
  
  int preorder(struct node * temp){
     if(temp==NULL)
        return 0;
     printf("%d ", temp->data);
     preorder(temp->left);
     preorder(temp->right);
 	
  }
  int postorder(struct node * temp){
     if(temp == NULL)
        return 0;
     postorder(temp->left);
     postorder(temp->right);
     printf("%d ",temp->data);
     
  }

    

  int delete(int data){
    void * p;
    int left,right;
    struct node * temp = root;
    struct node * target_node;
    struct node * last;
    struct node * temp2;
    while(1){
    if(temp == NULL)
       return 0;
    if(data < temp->data)
       {
       last = temp;
       temp = temp->left;
       left =1;
       right =0;      
 
	}
    if(data == temp->data)
       {
       if(left == 1)
         last->left =NULL;
       else
         last->right =NULL;  
    printf(" data found" );
    target_node = temp; 
    break ;
        }
    if(data > temp->data)
       {
       last = temp; 
       temp = temp->right;
       right = 1 ;
       left = 0;
       }	  

    }   
    /////////////////////////////////
    /*Given node is a leaf node*/
    /*Leaf node is a node which has no children*/

    if((target_node->left == NULL )&& (target_node->right == NULL)) 
       {
       if(left == 1)
          last->left=NULL;
       else 
  	  last->right=NULL;
       free(target_node);
       target_node = NULL;
       return 0;
       }
     if((target_node->left != NULL )&&(target_node->right == NULL)){
     /* our target node has left sub-tree but no right sub tree*/  
        temp2 = findmin(target_node,1);
        if(left ==1)
           last->left = temp2; 
	else
  	   last->right = temp2;

 	
     }
      if((target_node->left == NULL )&&(target_node->right != NULL)){
     /* our target node has right sub-tree but no left sub tree*/ 
      
        temp2 =  findmax(target_node,1);  
        if(left ==1)
           last->left = temp2;
        else
           last->right = temp2;
      
      }else{

        temp2 = findmin(target_node,1);
        if(left ==1)
           last->left = temp2;
        else
           last->right = temp2;
	temp2->right= target_node->right;

	}

    
   }





  

 struct node * findmax(struct node * temp,int flag){
   struct node * last ;
   
   while(temp!= NULL){
   
   if(temp != NULL)
      printf(" ## %d\n\n",temp->data);
   if(temp->right == NULL || temp==NULL)
      break;
    
   if(temp->right != NULL)
      {
      last = temp;
      temp= temp->right;
      }
    }
    if(flag == 1)
       last->right = NULL;
    return temp;
    }

   

 struct node * findmin(struct node * temp,int flag){
   struct node * last;	
   while(temp!=NULL){
   
   if(temp != NULL)
      printf(" ## %d\n\n",temp->data);
   if(temp->left == NULL || temp==NULL)
      break;

   if(temp->left != NULL)
        {
  	last = temp;
 	temp= temp->left;
	
        }
    }
    if(flag == 1)
       last->left = NULL;
    return temp;
    }

int gui();
int main(){


struct node * ans;
//printf("%d ",root->data);
gui();
return 0;
}

 int gui(){
int  c;
int value;
do{
printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
printf("*****************************\n");
printf("Choose from following options\n");
printf("#1 to Insert\n");
printf("#2 to delete\n" );
printf("#3 to print in INORDER\n");
printf("#4 to print in PREORDER\n");
printf("#5 to print in POSTORDER\n");
printf("#6 to print in EXIT\n");
printf("*****************************\n");
printf("enter your choice:\n" );
scanf("%d",&c);
system("clear" );
switch (c)
{

 case 1:
     printf("\n YOU HAVE CHOSEN OPTION 1 \n" );
     printf(" enter value to be INSERTED :\n");
     scanf("%d",&value);
    // printf("###################################\n\n")
     insert(value);
//     printf("###################################\n\n")
 
     break;
 case 2:
     printf(" YOU HAVE CHOSEN OPTION 2 " );
     printf("\n");
     printf(" enter value to be DELETED :\n");
     scanf("%d",&value);
  		
     delete(value);
     break;
 case 3:
     printf(" YOU HAVE CHOSEN OPTION 3 " );
     printf("\n");
     printf("###################################\n\n");
     inorder(root);
     printf("\n");
     printf("###################################\n\n");
 
     break;
 case 4:
     printf(" YOU HAVE CHOSEN OPTION 4 " );
     printf("\n");
     printf("###################################\n\n");
     preorder(root);
     printf("\n");
     printf("###################################\n\n");
     break;
 
 case 5:
     printf(" YOU HAVE CHOSEN OPTION 5 " );
     printf("\n");
     printf("###################################\n\n");
     postorder(root);
     printf("\n");
     printf("###################################\n\n");
     break;
 
 case 6:
     break;

     
     
 default:
     printf("Please select correct option \n" );
}
}while(c!=6);
}

