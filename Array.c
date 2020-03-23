#include "stdio.h"
#include "malloc.h"
#include "stdlib.h"
#include "stdbool.h"

struct Arr
{
	int *pBase;  //存储的是数组的第一个元素的地址
	int len;     //数组所能容纳的最大元素的个数
	int cnt;     //当前数组有效元素的个数
};

void init_arr(struct Arr *arr,int length);    //初始化
bool append_arr(struct Arr *arr,int val);   //追加
bool insert_arr(struct Arr *arr,int pos,int val);   //插入
bool delete_arr(struct Arr *arr,int pos,int * pval);   //
// bool get();
bool is_empty(struct Arr *arr);
bool is_full();
void sort_arr(struct Arr *arr);
void show_arr(struct Arr *arr);
void inversion_arr(struct Arr * arr);
 


int main(void)
{
	int len;
	int pval;
	struct Arr array;
	printf("please input the length of the array\n");
	scanf("%d",&len);
	init_arr(&array,len);
	show_arr(&array);
	append_arr(&array,1);
	append_arr(&array,2);
	append_arr(&array,3);
	append_arr(&array,4);
	insert_arr(&array,4,99);
	show_arr(&array);
	if(delete_arr(&array,4,&pval))
	{
		printf("delete successfully!\n");
		printf("the element is %d\n",pval);
	}
	else
	{
		printf("delete fail!");
	}
	
	show_arr(&array);
	inversion_arr(&array);
	printf("The result of array inversion: \n");
	show_arr(&array);
	//printf("%d\n",array.len);
	printf("Results of array ascending sorting: \n");
	sort_arr(&array);
	show_arr(&array);
	return 0;
}

//定义了一个数据类型，该数据类型的名字叫做struct Arr
//该数据类型含有三个成员，分别是pBase,len,cnt 

bool is_empty(struct Arr * arr)
{
	if (0 == arr->cnt)
	    return true;
	else
		return false;	
}

bool is_full(struct Arr * arr)
{
	if (arr->cnt == arr->len)
		return true;
	else
		return false;
}

bool append_arr(struct Arr * arr , int val)   //追加
{
	if ( is_full(arr) )
	{
		printf("the array is full,can't append element!");
		return false;
	}
	else
	{
		arr->pBase[arr->cnt] = val;
		arr->cnt ++;
		return true;
	}
	
	
}

bool delete_arr(struct Arr * arr,int pos,int * pval)   //
{   int i;
	if (is_empty(arr))
		return false;
	if ( pos<0 || pos>arr->cnt)
	{
		return false;
	}
	* pval = arr->pBase[pos];
	for ( i = pos; i <= arr->cnt-1; i++)
	{
		arr->pBase[i] = arr->pBase[i+1];
	}
	arr->cnt--;
	return true;
	

	
}


bool insert_arr(struct Arr * arr,int pos,int val)   //插入
{
	int i;
	//判断数组是否满，如果满，则返回false
	if ( is_full(arr))
	{
		return false;
	}
	//判断输入是否不满足要求，如果输入是小于1或者大于数组当前的个数
	//则返回false
	if ( pos<0 || pos>arr->cnt)
	{
		return false;
	}
	//上述检验均通过后，则先把pos后面的数组元素依次往后挪一个位置，
	//然后对要插入的位置进行赋值
	for ( i = arr->cnt-1 ; i >=pos ; --i)
	{
		arr->pBase[i+1] = arr->pBase[i];
	}
	arr->pBase[pos] = val;
	arr->cnt++;	
}

void show_arr(struct Arr * arr)
{
	if( is_empty(arr) )
	{
		printf("Array is empty!\n");
	}
	else
	{   
		printf("Here is your array: ");
		for (int i = 0; i < arr->cnt; i++)
		{
			printf("%d ",arr->pBase[i]);
		}
		printf("\n");
	}
	
}

void init_arr(struct Arr *array,int length)
{
	array->pBase = (int *)malloc(sizeof(int)*length);
	if (NULL == array->pBase)
	{
		printf("Dynamic memory allocation failed!\n");
		exit(-1);
	}
	else
	{
		array->len = length;
		array->cnt = 0;
	}
	return;
}

void inversion_arr(struct Arr * arr)
{
	int i = 0;
	int j = arr->cnt - 1;
	int temp;
	while( i < j )
	{
		temp = arr->pBase[i];
		arr->pBase[i] = arr->pBase[j];
		arr->pBase[j] = temp;
		i++;
		j--;
	}
	return;
}

void sort_arr(struct Arr *arr)
{	
	int i = 0;
	int j = 0;
	int temp;
	for (  i = arr->cnt-1 ; i > 0; i-- )
	{
		for ( j = 0; j < i; j++)
		{
			if (arr->pBase[j]>=arr->pBase[j+1])
			{
				temp = arr->pBase[j];
				arr->pBase[j] = arr->pBase[j+1];
				arr->pBase[j+1] = temp;
			}
			
		}
		
	}
	
}
