#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
typedef struct array{
    int array[17];
    int toSearch[6];
    int size ;
    int searchingcurrent;
    int middleElement;
    int operation;
    int dirrection;
    int left;
    int right;
} BinarySearch;
void waitshort();

void waitshort(){
    sleep(1);
}
void printToSearch(BinarySearch *BinarySearch){
    printf("\n\t\x1b[42mBinary Search Algorithm Visualization !!\x1b[0m\n\n\t");
    switch (BinarySearch->searchingcurrent)
    {
    case 0:
        printf("Searching       ");
        printf("\x1b[32m6\x1b[0m");
        printf(" \x1b[42m \x1b[0m     ");
        printf("876");
        printf("       ");
        printf("1120");
        printf("       ");
        printf("1");
        printf("       ");
        printf("2000");
        printf("       ");
        printf("70");
        printf("       ");
        break;
    case 1:
        printf("Searching       ");
        printf("6");
        printf("       ");
        printf("\x1b[32m876\x1b[0m");
        printf(" \x1b[42m \x1b[0m     ");
        printf("1120");
        printf("       ");
        printf("1");
        printf("       ");
        printf("2000");
        printf("       ");
        printf("70");
        printf("       ");
        break;
    case 2:
        printf("Searching       ");
        printf("6");
        printf("       ");
        printf("876");
        printf("       ");
        printf("\x1b[32m1120\x1b[0m");
        printf(" \x1b[42m \x1b[0m     ");
        printf("1");
        printf("       ");
        printf("2000");
        printf("       ");
        printf("70");
        printf("       ");
        break;
    case 3:
        printf("Searching       ");
        printf("6");
        printf("       ");
        printf("876");
        printf("       ");
        printf("1120");
        printf("       ");
        printf("\x1b[32m1\x1b[0m");
        printf(" \x1b[42m \x1b[0m     ");
        printf("2000");
        printf("       ");
        printf("70");
        printf("       ");
        break;
    case 4:
        printf("Searching       ");
        printf("6");
        printf("       ");
        printf("876");
        printf("       ");
        printf("1120");
        printf("       ");
        printf("1");
        printf("       ");
        printf("\x1b[32m2000\x1b[0m");
        printf(" \x1b[42m \x1b[0m     ");
        printf("70");
        printf("       ");
        break;
    case 5:
        printf("Searching       ");
        printf("6");
        printf("       ");
        printf("876");
        printf("       ");
        printf("1120");
        printf("       ");
        printf("1");
        printf("       ");
        printf("2000");
        printf("       ");
        printf("\x1b[32m70\x1b[0m");
        printf(" \x1b[42m \x1b[0m     ");
        break;
    
    default:
        break;
    }
    printf("\n\n\n\t");
    switch (BinarySearch->operation)
    {
    case 0:
        printf("Next Middle Element");
        printf(" \x1b[43m \x1b[0m     ");
        printf("Matching");
        printf("       ");
        printf("Not Found");
        printf("       ");
        printf("Found");
        printf("       ");
        printf("\n\n\t");
        printf("Comapring");
        printf("       ");
        break;
    case 1:
        printf("Next Middle Element");
        printf("       ");
        printf("Matching");
        printf(" \x1b[46m \x1b[0m     ");
        printf("Not Found");
        printf("       ");
        printf("Found");
        printf("       ");
        printf("\n\n\t");
        printf("Comapring");
        printf("       ");
        break;
    case 2:
        printf("Next Middle Element");
        printf("       ");
        printf("Matching");
        printf("       ");
        printf("Not Found");
        printf(" \x1b[41m \x1b[0m     ");
        printf("Found");
        printf("       ");
        printf("\n\n\t");
        printf("Comapring");
        printf("       ");
        break;
    case 3:
        printf("Next Middle Element");
        printf("       ");
        printf("Matching");
        printf("       ");
        printf("Not Found");
        printf("       ");
        printf("Found");
        printf(" \x1b[42m \x1b[0m     ");
        printf("\n\n\t");
        printf("Comapring");
        printf("       ");
        break;
    case 4:
        printf("Next Middle Element");
        printf("       ");
        printf("Matching");
        printf("       ");
        printf("Not Found");
        printf(" \x1b[41m \x1b[0m     ");
        printf("Found");
        printf("       ");
        printf("\n\n\t");
        printf("Comapring");
        printf("       ");
        break;
    case 5:
        printf("Next Middle Element");
        printf("       ");
        printf("Matching");
        printf("       ");
        printf("Not Found");
        printf("       ");
        printf("Found");
        printf("       ");
        printf("\n\n\t");
        printf("Comapring");
        printf(" \x1b[45m \x1b[0m     ");
        break;
    default:
        break;
    }
    printf("\n\n\n");

    switch (BinarySearch->dirrection)   
    {
    case 5:
        printf("\n\n\t\x1b[31m%d Not Found in array\x1b[0m\n\t",BinarySearch->toSearch[BinarySearch->searchingcurrent]);
        break;
    case 4:
        printf("\n\n\t\x1b[32m%d Found at index %d\x1b[0m\n\t",BinarySearch->toSearch[BinarySearch->searchingcurrent],BinarySearch->middleElement);
        break;
    case 3:
        printf("\n\tCurrent element > element to search\n\n\tNext search in Sub Array");
        break;
    case 2:
        printf("\n\tCurrent element < element to search\n\n\tNext search in Sub Array");
        break;
    case 1:
        printf("\n\tCurrent element > element to search\n\n");
        break;
    case 0:
        printf("\n\tCurrent element < element to search\n\n");
        break;
    
    

    
    default:
        printf("\n\n\n");
        break;
    }
    printf("\n\n\n");

    
};
void printBinarySearch(BinarySearch * BinarySearch){
    printToSearch(BinarySearch);
    printf("\n\n\n\n  Index   ");
    for(int i; i< BinarySearch->size;i++){
        if(BinarySearch->dirrection == 2 || BinarySearch->dirrection == 3){
            if(i >= BinarySearch->left && i <= BinarySearch->right){
                printf("\x1b[31m%d\x1b[0m  ",i);
            }else {
                printf("%d  ",i);
            }
        }
        else{
        if(i == BinarySearch->middleElement){
            if(BinarySearch->operation == 1){
                printf("\x1b[36m%d\x1b[0m  ",i);
            }else if (BinarySearch->operation == 2 || BinarySearch->operation == 5){
                printf("\x1b[31m%d\x1b[0m  ",i);
            }else if (BinarySearch->operation == 3){
                printf("\x1b[32m%d\x1b[0m  ",i);
            }else{
                printf("\x1b[33m%d\x1b[0m  ",i);
            }
            
        }else{
            if(BinarySearch->operation == 4){
                printf("\x1b[31m%d\x1b[0m  ",i);
            }else {
                printf("%d  ",i);
            }
            
        }
        }


        if(i > 2){
            printf(" ");
        }
        if(i > 7 && i < 10){ 
            printf(" ");
        }
        
    }
    printf("\n\n\n\n  Array   ");
    for(int i; i< BinarySearch->size;i++){
if(BinarySearch->dirrection == 2 || BinarySearch->dirrection == 3){
            if(i >= BinarySearch->left && i <= BinarySearch->right){
               printf("\x1b[31m%d\x1b[0m  ",BinarySearch->array[i]);
            }else {
                printf("%d  ",BinarySearch->array[i]);
            }
        }else{
        if(i == BinarySearch->middleElement){
            if(BinarySearch->operation == 1){
                printf("\x1b[36m%d\x1b[0m  ",BinarySearch->array[i]);
            }else if (BinarySearch->operation == 2 || BinarySearch->operation == 5){
                printf("\x1b[31m%d\x1b[0m  ",BinarySearch->array[i]);
            }else if (BinarySearch->operation == 3){
                printf("\x1b[32m%d\x1b[0m  ",BinarySearch->array[i]);
            }else{
                printf("\x1b[33m%d\x1b[0m  ",BinarySearch->array[i]);
            }
            
        }else{
            if(BinarySearch->operation == 4){
                printf("\x1b[31m%d\x1b[0m  ",BinarySearch->array[i]);
            }else {
                printf("%d  ",BinarySearch->array[i]);
            }
            
        }
        }
        
    }

    printf("\n");
    
}


void binarySearch(BinarySearch *BinarySearch){
    
    BinarySearch->right = BinarySearch->size-1;
    system("clear");
    printBinarySearch(BinarySearch);
    waitshort();
    BinarySearch->middleElement = BinarySearch->left + (BinarySearch->right - BinarySearch->left) / 2;
    system("clear");
    printBinarySearch(BinarySearch);
    waitshort();
    while(1){
        system("clear");
        BinarySearch->operation = 1;
        printBinarySearch(BinarySearch);
        waitshort();
        if(BinarySearch->array[BinarySearch->middleElement] == BinarySearch->toSearch[BinarySearch->searchingcurrent]){
            BinarySearch->operation = 3;
            BinarySearch->dirrection = 4;
            system("clear");
            printBinarySearch(BinarySearch);
            waitshort();
            waitshort();
            waitshort();
            sleep(2);
            BinarySearch->dirrection = -1;
            BinarySearch->operation = 0;
            BinarySearch->left = 0;
            BinarySearch->right = 0;
            BinarySearch->middleElement = -1;
            return;
        }else if (BinarySearch->toSearch[BinarySearch->searchingcurrent] > BinarySearch->array[BinarySearch->middleElement] && BinarySearch->middleElement < (BinarySearch->size - 1)){
            system("clear");
            BinarySearch->operation = 2;
            printBinarySearch(BinarySearch);
            waitshort();
            system("clear");
            BinarySearch->operation = 5;
            printBinarySearch(BinarySearch);
            waitshort();

            system("clear");
            BinarySearch->dirrection = 0;
            printBinarySearch(BinarySearch);
            waitshort();
            BinarySearch->dirrection = -1;

            BinarySearch->left = BinarySearch->middleElement + 1;

            system("clear");
            BinarySearch->dirrection = 2;
            printBinarySearch(BinarySearch);
            waitshort();
            waitshort();
            waitshort();
            BinarySearch->dirrection = -1;

            BinarySearch->middleElement = BinarySearch->left + (BinarySearch->right - BinarySearch->left) / 2;
            if (BinarySearch->left > BinarySearch->right){
                break;
            }
            system("clear");
            BinarySearch->operation = 0;
            printBinarySearch(BinarySearch);
            waitshort();
            
        }else if (BinarySearch->toSearch[BinarySearch->searchingcurrent] < BinarySearch->array[BinarySearch->middleElement] && BinarySearch->middleElement != 0){
            system("clear");
            BinarySearch->operation = 2;
            printBinarySearch(BinarySearch);
            waitshort();

            system("clear");
            BinarySearch->operation = 5;
            printBinarySearch(BinarySearch);
            waitshort();

            system("clear");
            BinarySearch->dirrection = 1;
            printBinarySearch(BinarySearch);
            waitshort();
            BinarySearch->dirrection = -1;

            BinarySearch->right = BinarySearch->middleElement - 1;

            system("clear");
            BinarySearch->dirrection = 3;
            printBinarySearch(BinarySearch);
            waitshort();
            waitshort();
            waitshort();
            BinarySearch->dirrection = -1;
            BinarySearch->middleElement = BinarySearch->left + (BinarySearch->right - BinarySearch->left) / 2;
            if (BinarySearch->left > BinarySearch->right){
                break;
            }

            system("clear");
            BinarySearch->operation = 0;
            printBinarySearch(BinarySearch);
            waitshort();
            
        }else {
            break;
        }
    }
        BinarySearch->middleElement = -1;
        system("clear");
        BinarySearch->operation = 4;
        BinarySearch->dirrection = 5;
        printBinarySearch(BinarySearch);
        BinarySearch->operation = 0;
        BinarySearch->left = 0;
        BinarySearch->right = 0;
        BinarySearch->dirrection = -1;
        waitshort();
        waitshort();
        waitshort();
        waitshort();
    
}

void search(BinarySearch *BinarySearch){
    for(int i = 0;i<6;i++){
        BinarySearch->searchingcurrent = i;
        binarySearch(BinarySearch);
    }
}



int main(){
    BinarySearch BinarySearch = {{2,6,9,20,35,68,70,90,95,100,150,200,269,876,900,1050,1120},{6,876,1120,1,2000,70},17,0,-1,0,-1};
    search(&BinarySearch);
    return 0;
}