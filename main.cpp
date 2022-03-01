/*
سيستم يقوم بعمل اختباران)
(math,english)
وحساب درجاتهم


١-برنامج يقوم بعمل امتحانان لعدد من الطلبه المستخدم هو من يحدد عددهم
٢-يجب أن الطالب يدخل اسمه و ID
- الاسم يكون مكون من حروف ومسافات فقط
 ID-
-يجب أن يكون من ارقام فقط ومكون من 4
dijit
-لو تكرر دخول
Id 
البرنامج مش هيقبله
3-  
البرنامج يقوم بحساب وتصحيح الاختبارات لكل طالب ويقوم بطباعه نتيجه الطلاب بتفاصيل النتيجه حيث يقوم بعرض اسم الطالب والId الخاص بيه ودرجاته بكل ماده والمجموع الكلي والGBA الكلي 
٤-البرنامج يسمح للمستخدم ب البحث عن نتيجته بالld الخاص بيه وبيعرضله كل تفاصيل نتيجته
5-البرنامج يقوم بعرض نتيجه الطالب صاحب اعلي درجه و gba من ضمن كل الطلاب المؤدين للاختبارات
  */
#include <stdio.h>
#include<string.h>
struct grade{
  int totalM,totalE,totalSC;
 float math,english,science;
};
struct grade g;
//English exame
void exameEnglish()
{
  int gradeE=0;
  int gradetotalE=0;
  char answer[10];
  printf("1:How old ------you?    ");
  scanf("%[^\n]%*c",answer);
  if(strcmp(answer,"are")==0||strcmp(answer, "ARE")==0)
  gradeE+=30;
  gradetotalE+=30;


printf("2:shut ------?           ");
  scanf("%[^\n]%*c",answer);
  if(strcmp(answer,"up")==0||strcmp(answer, "UB")==0)
  gradeE+=30;
  gradetotalE+=30;


  printf("3:see ------latter?      ");
  scanf("%[^\n]%*c",answer);
  if(strcmp(answer,"you")==0||strcmp(answer, "YOU")==0)
  gradeE+=30;
  gradetotalE+=30;
  
  g.totalE=gradetotalE;
  g.english=gradeE;
  
}
//math exame
void exameMath()
{
 
  int answer;
  int gradeM=0;
  int gradetotal=0;
  printf("1:1+2=------");
  scanf("%d%*c",&answer);
  if(answer==3)
  gradeM+=20;
gradetotal+=20;

  printf("2:5+2=------");
  scanf("%d%*c",&answer);
  if(answer==7)
  gradeM+=20;
gradetotal+=20;

printf("3:10+2=------");
  scanf("%d%*c",&answer);
  if(answer==12)
  gradeM+=20;
gradetotal+=20;

  printf("4:5-2=------");
  scanf("%d%*c",&answer);
  if(answer==3)
  gradeM+=20;
 gradetotal+=20;

  printf("5:10-2=------");
  scanf("%d%*c",&answer);
  if(answer==8)
  gradeM+=20;
  gradetotal+=20;
  g.totalM=gradetotal;
  g.math=gradeM;
  
  
}
//struct stuent
struct student{
char name[25];
char ID[25];
 int totalMath,totalEnglish,totalSCience;
 float mathg,englishg,scienceg;
 char gbaM,gbaE,gbaSC,gbaSum;
 int totalSub,sumGrade;
};



int main(void) {
  
  int number;
printf("enter number of student:\n");
scanf("%d%*c",&number);
//defind struct arry student
struct student x[number];
char exame;
//scan the data
for(int i=0;i<number;i++){
  printf("for student:%d\n",i+1);
//scan the name 

  printf("enter the name of student:\n");
  scanf("%[^\n]%*c",x[i].name);
  //the name must be all dijit contante letter and space
 for(int j=0;x[i].name[j]!='\0';j++)
 
if(!((x[i].name[j]>='a'&&x[i].name[j]<='z')||(x[i].name[j]>='A'&&x[i].name[j]<='Z')||x[i].name[j]==' ')){
printf("Error,the name must be all dijit latter\n");
return 0;
 }
 char actual[10];
//enter the id
printf("enter the id: ");
scanf("%[^\n]%*c",x[i].ID);

//ID must be all dijit number only
for(int j=0;x[i].ID[j]!='\0';j++)
if(!(x[i].ID[j]>='0'&&x[i].ID[j]<='9'))
{
  printf("Error,the dijit of ID must be number\n");
  return 0;
}
// ID must be 4 dijit

if(strlen(x[i].ID)!=4)
{
  printf("Erorr,the id must be 4 dijit");
  return 0;
}
//to stop repeate the ID
int coutnter=0;
strcpy(actual,x[i].ID);
for(int k=0;k<number;k++)
{
  if(strcmp(actual, x[k].ID)==0)
  coutnter++;
}
if(coutnter==2){
printf("repated ID,pleas enter anthor ID\n");
return 0;
}

// the exame 

  printf("Math exame \n");
  exameMath();
  x[i].totalMath=g.totalM;
  x[i].mathg=g.math;
printf("English exame\n");
exameEnglish();
x[i].totalEnglish=g.totalE;
// printf("x[i].totalEnglisg= %d\n",x[i].totalEnglish);
x[i].englishg=g.english;
//total subject
x[i].totalSub=x[i].totalMath+x[i].totalEnglish;
//total your Grade
x[i].sumGrade=x[i].mathg+x[i].englishg;
}

int max=0;
char nameFirst[10];
char gbaF;
char IDF[10];
//printing data
for(int i=0;i<number;i++ )
{

//finaliy gba for student
  if(x[i].sumGrade<(.5*x[i].totalSub))
  x[i].gbaSum='F';
  else if((x[i].sumGrade>=.5*x[i].totalSub)&&(x[i].sumGrade<(.60*x[i].totalSub)))
  x[i].gbaSum='D';

else if((x[i].sumGrade>=.6*x[i].totalSub)&&(x[i].sumGrade<(.70*x[i].totalSub)))
 x[i].gbaSum='C';

  else if((x[i].sumGrade>=.70*x[i].totalSub)&&(x[i].sumGrade<(.85*x[i].totalSub)))
 x[i].gbaSum='B';

  else if((x[i].sumGrade>=.85*x[i].totalSub)&&(x[i].sumGrade<=(1*x[i].totalSub)))
 x[i].gbaSum='A';




if(x[i].sumGrade>max){
max=x[i].sumGrade;
strcpy(nameFirst,x[i].name);
gbaF=x[i].gbaSum;
strcpy(IDF,x[i].ID);
}


//printing the grade of exams (math and English)

printf("----------------------------------------------------\n");

printf("student %d\n",i+1);
printf("The Name:%s                  ID: %s     \n",x[i].name,x[i].ID);
printf("Math:     grade=%.2f           total=%d\n",x[i].mathg,x[i].totalMath);

printf("English:  grade=%.2f          total=%d\n",x[i].englishg,x[i].totalEnglish);
printf("     total grade=%d       your grade=%d     finaly GBA=%c\n",x[i].totalSub,x[i].sumGrade,x[i].gbaSum);
printf("\n----------------------------------------------------\n");


}

printf("\n===================================================\n");
printf("=                   the first                       =\n");
printf("NAME:%s  ID:%s    GRADE=%d     GBA:%c               =",nameFirst,IDF,max,gbaF);
printf("\n===================================================\n");

//search by  your ID to funde the  your Result 
 char search[10];
  printf("enter your ID:   ");
  scanf("%[^\n]%*c",search);
for(int i=0;i<number;i++){

  
  if((strcmp(search, x[i].ID)==0))

{
  
printf("student %d\n",i+1);
printf("The Name:%s                  ID: %s     \n",x[i].name,x[i].ID);
printf("Math:     grade=%.2f           total=%d\n",x[i].mathg,x[i].totalMath);

printf("English:  grade=%.2f          total=%d\n",x[i].englishg,x[i].totalEnglish);
printf("     total grade=%d       your grade=%d     finaly GBA=%c\n",x[i].totalSub,x[i].sumGrade,x[i].gbaSum);
printf("\n----------------------------------------------------\n");
break;
}

}


 return 0; 
}