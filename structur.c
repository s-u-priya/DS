#include <stdio.h> 
struct Student 
 { 
	 char name[50]; 
	 int m1,m2,m3;  // Assuming each student has 3 subjects 
	 float total,avg; 
}; 
int main() 
 { 
	 int n, i; 
	 printf("Enter the number of students: "); 
	 scanf("%d", &n); 
	 struct Student s[n]; 
	 // Input data for each student 
	 for(i = 0; i < n; i++)  
		{ 
			printf("enter name,3 subject marks of student %d\n",i+1); 			scanf("%s%d%d%d",s[i].name,&s[i].m1,&s[i].m2,&s[i].m3); 		} 
	 for(i=0;i<n;i++) 
	 { 
                                   s[i].total=s[i].m1+s[i].m2+s[i].m3; 
			 s[i].avg=s[i].total/3.0; 
 printf("Total and Average marks of Student %d=%.2f,%.2f\n",i+1,s[i].total,s[i].avg); 	 } 
		 return 0; 
} 
