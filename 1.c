#include<stdio.h>
#include<stdlib.h>
#define x 10
#define y 100

int test = 0;

float euclid(int m, int n)  { 
    int r; 
    float count = 0; 
    while (n) {   
        count++; 
        r = m % n; 
        m = n; 
        n = r; 
    } 
    printf("GCD = %d\n", m); 
    return count; 
} 

float consec(int m, int n) { 
    int min; 
    float count = 0; 
    min = m; 
    if (n < min) 
        min = n; 
    while (1) { 
        count++; 
        if (m % min == 0) { 
            count++; 
            if (n % min == 0) 
                break; 
            min -= 1; 
        } else 
            min -= 1; 
    } 
 
    printf("GCD = %d\n", min); 
    return count; 
} 

float modified(int m, int n) { 
    int temp; 
    float count = 0; 
    while (n > 0) { 
        if (n > m) { 
            temp = m;
            m = n;
            n = temp; 
        } 
        m = m - n; 
        count += 1; 
    } 
 
    printf("GCD = %d\n",m); 
    return count; // m is the GCD 
} 
void analysis(int ch) 
{ 
int m,n,i,j,k; 
float count,maxcount,mincount; 
FILE *fp1,*fp2; 
for(i=x;i<=y;i+=10) 
{ 
maxcount=0; mincount=10000; 
for (j=2;j<=i; j++ ) // To generate the data 
{ 
for(k=2;k<=i; k++) 
{ 
count=0; 
m=j; 
n=k; 
switch(ch) 
{ 
case 1:count=euclid(m,n); 
break; 
case 2:count=consec(m,n); 
break; 
case 3:count=modified(m,n); 
break; 
} 
if(count>maxcount) /* To find the maximum basic operations among all the 
combinations between 2 to n */
maxcount=count; 
if(count<mincount) 
/* To find the minimum basic operations among all the combinations between 2 
to n */
mincount=count; 
} 
} 
switch(ch) 
{ 
case 1:fp2=fopen("e_b.txt","a"); 
fp1=fopen("e_w.txt","a"); 
break; 
case 2:fp2=fopen("c_b.txt","a"); 
fp1=fopen("c_w.txt","a"); 
break; 
case 3:fp2=fopen("m_b.txt","a"); 
fp1=fopen("m_w.txt","a"); 
break; 
} 
fprintf(fp2,"%d %.2f\n",i,mincount); 
fclose(fp2); 
fprintf(fp1,"%d %.2f\n",i,maxcount); 
fclose(fp1); 
} 
}
 
 
void main() { 
    int ch; 
    while (1) { 
        printf("\nGCD\n"); 
        printf("1. Euclid\n2. Modified Euclid\n3. Consecutive integer method\n0. Exit\n"); 
        scanf("%d",&ch); 
        if (ch == 0) 
            break; 
        printf("ENTER THE VALUES M AND N\n"); 
        int m, n; 
        scanf("%d", &m); 
        scanf("%d", &n); 
        switch (ch) { 
            case 1:
                euclid(m,n);break; 
            case 2:
                modified(m,n);break; 
            case 3:
                consec(m,n);break; 
            default:
                break; 
        } 
    } 
}