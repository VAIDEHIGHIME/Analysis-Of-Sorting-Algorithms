#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#define INPUT_FILE_NAME "i0.txt"
#define OUTPUT_FILE_NAME "o0.txt"
#define NO_OF_ELEMENTS_GENERATED 0
#define MAX_ARRAY_SIZE 0

using namespace std;

void generate_input_for_the_array()
{
    srand(clock());
    ofstream ofile;
    ofile.open (INPUT_FILE_NAME);
    for(int i=0;i<NO_OF_ELEMENTS_GENERATED;i++)
    {
            ofile << rand() <<endl;
    }
    ofile.close();
}

void read_input_from_file_and_insert_into_array(int sample_array[])
{
    ifstream input_file;
    input_file.open(INPUT_FILE_NAME);
    if(input_file.fail())
    {
        cout<<"FILE OPENING ERROR"<<endl;
    }
    else
    {
        int index;
        index=0;
        int element;
        while( index<NO_OF_ELEMENTS_GENERATED && input_file.eof()==false)
        {
                input_file>>element;
                sample_array[index]=element;
                index++;
        }
    }
    input_file.close();
}

void print_the_array(int sample_array[])
{
    for(int i=0;i<NO_OF_ELEMENTS_GENERATED ;i++)
    {
        cout<<sample_array[i]<<",  " ;
    }
    cout<<endl;
}

void insertion_sort(int sample_array[])
{
    int i,j,temp;
    for( i=1;i<=NO_OF_ELEMENTS_GENERATED;i++)
    {
        j=i;
        while(j>0 && sample_array[j]<sample_array[j-1])
        {
                temp=sample_array[j];
                sample_array[j]=sample_array[j-1];
                sample_array[j-1]=temp;
                j--;
        }

    }
}

void selection_sort(int sample_array[])
{
    int i,j,maximum,temp;
    for(i=0;i<=NO_OF_ELEMENTS_GENERATED-1;i++)
    {
        maximum=0;
        for(j=0;j<=NO_OF_ELEMENTS_GENERATED-1-i;j++)
        {
            if(sample_array[j]>sample_array[maximum])
            {
                maximum=j;
            }
        }
        temp=sample_array[maximum];
        sample_array[maximum]=sample_array[NO_OF_ELEMENTS_GENERATED-1-i];
        sample_array[NO_OF_ELEMENTS_GENERATED-1-i]=temp;
    }

}

void bubble_sort_modified(int sample_array[])
{
    int i,sorted,j,temp;
    sorted=0;
    for(i=0;i<=NO_OF_ELEMENTS_GENERATED-1 && sorted==0;i++)
    {
        for(j=0;j<NO_OF_ELEMENTS_GENERATED-1-i;j++)
        {
            sorted=1;
            if(sample_array[j]>sample_array[j+1])
            {
                temp=sample_array[j];
                sample_array[j]=sample_array[j+1];
                sample_array[j+1]=temp;
                sorted=0;
            }
        }
    }
}

int array_partition (int sample_array[], int l, int h)
{
    int x = sample_array[h];
    int i = (l - 1);

    for (int j = l; j <= h- 1; j++)
    {
        if (sample_array[j] <= x)
        {
            i++;
            int temp1;
            temp1=sample_array[i];
            sample_array[i]=sample_array[j];
            sample_array[j]=temp1;
        }
    }
    int temp2;
    temp2=sample_array[i+1];
    sample_array[i+1]=sample_array[h];
    sample_array[h]=temp2;

    return (i + 1);
}

void quick_sort(int sample_array[], int l, int h)
{
    if (l < h)
    {
        int p = array_partition(sample_array, l, h);
        quick_sort(sample_array, l, p - 1);
        quick_sort(sample_array, p + 1, h);
    }
}

void merge(int sample_array[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
    {
        L[i] = sample_array[l + i];
    }

    for (j = 0; j < n2; j++)
    {
         R[j] = sample_array[m + 1+ j];
    }
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            sample_array[k] = L[i];
            i++;
        }
        else
        {
            sample_array[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        sample_array[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        sample_array[k] = R[j];
        j++;
        k++;
    }
}
void merge_sort(int sample_array[], int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2;
        merge_sort(sample_array, l, m);
        merge_sort(sample_array, m+1, r);
        merge(sample_array, l, m, r);
    }
}

int main()
{

    generate_input_for_the_array();

    ofstream out;
    out.open(OUTPUT_FILE_NAME);

    out<<"1) Insertion sort"<<endl;

    int sample_array_for_insertion_sort[MAX_ARRAY_SIZE];
    read_input_from_file_and_insert_into_array(sample_array_for_insertion_sort);
    out<<"Ihe Input array is"<<endl;
    for(int i=0;i<NO_OF_ELEMENTS_GENERATED;i++)
    {
        out<<sample_array_for_insertion_sort[i]<<",  ";
    }
    out<<endl;
    double t1=clock();
    insertion_sort(sample_array_for_insertion_sort);
    double t2=clock();
    double t3=t2-t1;
    t3=t3/CLOCKS_PER_SEC;
    out<<"Result"<<endl;
    out<<"Time Complexity for Insertion sort:"<<t3<<endl;

    out<<"2)Selection sort"<<endl;
    int sample_array_for_selection_sort[MAX_ARRAY_SIZE];
    read_input_from_file_and_insert_into_array(sample_array_for_selection_sort);
    out<<"Ihe Input array is"<<endl;
    for(int i=0;i<NO_OF_ELEMENTS_GENERATED;i++)
    {
        out<<sample_array_for_selection_sort[i]<<",  ";
    }
    out<<endl;
    t1=clock();
    selection_sort(sample_array_for_selection_sort);
    t2=clock();
    t3=t2-t1;
    t3=t3/CLOCKS_PER_SEC;
    out<<"Result"<<endl;
    out<<"Time Complexity for Selection sort:"<<t3<<endl;


    out<<"3)Bubble sort(Modified)"<<endl;
    int sample_array_for_bubble_sort_modified[MAX_ARRAY_SIZE];
    read_input_from_file_and_insert_into_array(sample_array_for_bubble_sort_modified);
    out<<"Ihe Input array is"<<endl;
    for(int i=0;i<NO_OF_ELEMENTS_GENERATED;i++)
    {
        out<<sample_array_for_bubble_sort_modified[i]<<",  ";
    }
    out<<endl;
    t1=clock();
    bubble_sort_modified(sample_array_for_bubble_sort_modified);
    t2=clock();
    t3=t2-t1;
    t3=t3/CLOCKS_PER_SEC;
    out<<"Result"<<endl;
    out<<"Time Complexity for Bubble sort (Modified):"<<t3<<endl;

    out<<"4)Quick sort"<<endl;
    int sample_array_for_quick_sort[MAX_ARRAY_SIZE];
    read_input_from_file_and_insert_into_array(sample_array_for_quick_sort);
    out<<"Ihe Input array is"<<endl;
    for(int i=0;i<NO_OF_ELEMENTS_GENERATED;i++)
    {
        out<<sample_array_for_quick_sort[i]<<",  ";
    }
    out<<endl;
    t1=clock();
    quick_sort(sample_array_for_quick_sort,0,NO_OF_ELEMENTS_GENERATED-1);
    t2=clock();
    t3=t2-t1;
    t3=t3/CLOCKS_PER_SEC;
    out<<"Result"<<endl;
    out<<"Time Complexity for Quick sort:"<<t3<<endl;

    out<<"5)Merge sort"<<endl;
    int sample_array_for_merge_sort[MAX_ARRAY_SIZE];
    read_input_from_file_and_insert_into_array(sample_array_for_merge_sort);
    out<<"Ihe Input array is"<<endl;
    for(int i=0;i<NO_OF_ELEMENTS_GENERATED;i++)
    {
        out<<sample_array_for_merge_sort[i]<<",  ";
    }
    out<<endl;
    t1=clock();
    merge_sort(sample_array_for_merge_sort,0,NO_OF_ELEMENTS_GENERATED-1);
    t2=clock();
    t3=t2-t1;
    t3=t3/CLOCKS_PER_SEC;
    out<<"Result"<<endl;
    out<<"Time Complexity for Merge sort:"<<t3<<endl;

    out.close();
    return(0);
}



