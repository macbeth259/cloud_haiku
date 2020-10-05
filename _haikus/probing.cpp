#include <stdio.h>
#include <stdlib.h>
int tsize;
void dhash()
{
	int size;
	printf ("Enter the size of the hash table:  ");
    scanf ("%d",&size);
    int a3[size];
	int key,index,i,hkey,hash2;
	printf("\nEnter a value to insert into hash table\n");
	scanf("%d",&key);
	hkey=key%size;
	hash2 = 7-(key %7);
	for(i=0;i<size;i++)
	{
		index=(hkey+i*hash2)%size;
		if(a3[index]==NULL)
		{
			a3[index]=key;
			break;
		}
	}
	if(i == size)
	{
		printf("Element cannot be inserted\n");
	}
	printf("Elements in the hash table are \n");
	for(int i=0;i<size; i++)
	{
		printf("%d",a3[i]);
	}	
}
int hasht(int key)
{
	int i ;
	i = key%tsize ;
	return i;
}
int rehashq(int key, int j)
{
	int i ;
	i = (key+(j*j))%tsize ;
	return i ;
}
int rehashl(int key)
{
	int i ;
	i = (key+1)%tsize ;
	return i ;
}
int main()
{
    int key,a1[20],a2[20],i,n,op,j,k ;
    printf ("Enter the size of the hash table:  ");
    scanf ("%d",&tsize);
    printf ("\nEnter the number of elements: ");
    scanf ("%d",&n);
    for (i=0;i<tsize;i++)
    {
		a2[i]=-1 ;
	}
    printf ("Enter Elements: ");
    for (i=0;i<n;i++)
    {
		scanf("%d",&a1[i]);
    }
	do
    {
		printf("\n\n1.Linear Probing\n2.Quadratic Probing \n3Double Hashing\n4.Exit \nEnter your option: ");
		scanf("%d",&op);
		switch(op)
		{
			case 1:
			{
				for (i=0;i<tsize;i++)
				{
					a2[i]=-1;
				}
				for(k=0;k<n;k++)
				{
					key=a1[k] ;
					i = hasht(key);
					while (a2[i]!=-1)
					{
						i = rehashl(i);
					}
					a2[i]=key ;
				}
				printf("\nThe elements in the array are: ");
				for (i=0;i<tsize;i++)
				{
					printf("\n  Element at position %d: %d",i,a2[i]);
				}	
				break ;
			}
			case 2:
			{
				for (i=0;i<tsize;i++)
				{
					a2[i]=-1 ;
				}
				for(k=0;k<n;k++)
				{
					j=1;
					key=a1[k] ;
					i = hasht(key);
					while (a2[i]!=-1)
					{
						i = rehashq(i,j);
						j++;
					}
					a2[i]=key ;
				}
				printf("\nThe elements in the array are: ");
				for (i=0;i<tsize;i++)
				{
					printf("\n Element at position %d: %d",i,a2[i]);
				}
				break ;
			}
			case 3:
			{
				dhash();
				break;
			}
			case 4:
			{
				op=4;
				break;
			}
			default:
			{
				printf("Wrong Choice");
			}
		}
	}while(op!=4);
	return 0;
}
