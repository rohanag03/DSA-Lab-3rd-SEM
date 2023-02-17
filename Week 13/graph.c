//WAP to implement Graph data structure.

#include <stdio.h>
#include <stdlib.h>
struct edge;
struct node
{
    int data_2105738;
    struct edge *next_2105738;
    struct node *nextnode_2105738;
};
struct edge
{
    struct node *link_2105738;
    struct edge *next_2105738;
};
struct node *start_2105738 = NULL;
void createGraph_2105738()
{
    struct node *newnode_2105738, *temp_2105738;
    struct edge *newedge_2105738, *tempedge_2105738;
    int n_2105738, i_2105738, j_2105738, k_2105738, flag_2105738 = 0;
    printf("Enter the number of nodes: ");
    scanf("%d", &n_2105738);
    for (int i_2105738 = 0; i_2105738 < n_2105738; i_2105738++)
    {
        newnode_2105738 = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data for node %d: ", i_2105738 + 1);
        scanf("%d", &newnode_2105738->data_2105738);
        newnode_2105738->next_2105738 = NULL;
        newnode_2105738->nextnode_2105738 = NULL;
        if (start_2105738 == NULL)
        {
            start_2105738 = newnode_2105738;
        }
        else
        {
            temp_2105738 = start_2105738;
            while (temp_2105738->nextnode_2105738 != NULL)
            {
                temp_2105738 = temp_2105738->nextnode_2105738;
            }
            temp_2105738->nextnode_2105738 = newnode_2105738;
        }
    }
    temp_2105738 = start_2105738;
    while (temp_2105738!= NULL)
    {
        printf("Enter the edges for node %d: ", temp_2105738->data_2105738);
        scanf("%d", &k_2105738);
        for (j_2105738 = 0; j_2105738 < k_2105738; j_2105738++)
        {
            newedge_2105738 = (struct edge *)malloc(sizeof(struct edge));
            printf("Enter the data for edge %d: ", j_2105738 + 1);
            scanf("%d", &newedge_2105738->link_2105738->data_2105738);
            newedge_2105738->next_2105738 = NULL;
            if (temp_2105738->next_2105738 == NULL)
            {
                temp_2105738->next_2105738 = newedge_2105738;
            }
            else
            {
                tempedge_2105738 = temp_2105738->next_2105738;
                while (tempedge_2105738->next_2105738 != NULL)
                {
                    tempedge_2105738 = tempedge_2105738->next_2105738;
                }
                tempedge_2105738->next_2105738 = newedge_2105738;
            }
        }
        temp_2105738= temp_2105738->nextnode_2105738;
    }
}
int main()
{
    createGraph_2105738();
}

