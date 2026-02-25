void troca(int a[], int x,int y)
{
     int w;
    w=a[x];
    a[x]=a[y];
    a[y]=w;
}
void bobbleSort(int a[],int n)
{
     int contador = 1;
    int m=n;
    for(int j=0;j<n;j++)
    {
        if(contador==0)
        {
            break;
        }
        contador = 0;
        for(int i=0;i<m;i++)
        {
            if(a[i]>a[i+1])
            {
                troca(a,i,i+1);
                contador++;
            }
        
        }
        m--;
    }
}
void insertSort(int vetor[],int size)
{
    int aux,j;
    for(int i=0;i<size-1;i++)
    {
        if(vetor[i]>vetor[i+1])
        {
            aux = vetor[i+1];
            vetor[i+1] = vetor[i];
            vetor[i] = aux;
            j = i - 1;
            while(j>=0)
            {
                if(aux<vetor[j])
                {
                    vetor[j+1] = vetor[j];
                    vetor[j] = aux;
                }
                else
                {
                    break;
                }
                j = j - 1;
            }
        }
    }
}

void margesort(int *ini, int *slow, int *fim){
    int tamanho = (fim-ini)+1;
    int *temp = malloc(tamanho * sizeof(int));

    int *l1 = ini;
    int *l2 = slow + 1;

    int k = 0;


    while(l1 <= slow && l2 <= fim){
        if(*l1 <= *l2){
            temp[k] = *l1; 
            l1++;
        }
        else{
            temp[k] = *l2; 
            l2++;
        }
        k++;
    } 

    while(l1 <= slow){
        temp[k] = *l1;
        l1++;
        k++;
    }

    while(l2 <= fim){
        temp[k] = *l2;
        l2++;
        k++;
    }

 
    for(int i = 0; i < k; i++){
        ini[i] = temp[i];
    }


    free(temp); 
}

void marge(int *ini, int *fim){
    if(ini >= fim){
        return;
    }

    int *slow = ini;
    int *fast;

    
    for(fast = ini+1; fim >= fast; fast += 2){
        if(fast+2 <= fim){
            slow++;
        }
    }
   

   marge(ini, slow);
   marge(slow+1, fim);


   margesort(ini, slow, fim); 

}
