#include <stdio.h> //기본 입출력 헤더퍼일
#include <stdlib.h> //srand, rand를 사용하기 위한 헤더파일
#include <time.h> // time(rand의 시드)을 사용하기 위한 헤더파일

int main() {
    int up, upstudent[23]={0}, tmp, left=0, leftstudent[23]={0}, flag=0, nomal[100]={0}, point=0, students=0, column=5;
    
    printf("학생수를 입력하세요 : ");
    scanf("%d", &students); //변수 students에 학생수 받기
    
    if(students == 0)
        return 0; //학생수가 0이라면 종료(에러)
    
    for(int i=0; i<students; i++) {
        nomal[i] = i+1;
    } //학생수 만큼 기본 학생 번호 대입
    
    printf("앞자리에 앉을 학생의 수를 입력하세요(0입력시 없음) : ");
    scanf("%d",&up); //변수 up에 앞자리에 앉는 학생수 받기
    
    printf("가로줄의 개수(열의 개수)를 입력하세요(0입력시 기본값 5) : ");
    scanf("%d",&column);//변수 column에 앞자리에 앉는 학생수 받기
    if(column == 0)
        column = 5;
    
    if (up == 0) {
        srand((int)time(NULL));
        for(int i=0; i<100; i++) {
            int r = rand() % students;
            int temp = nomal[0];
            nomal[0] = nomal[r];
            nomal[r] = temp;
        }
        
        for(int i=0; i<students; i++) {
            if(i%column == 0)
                printf("\n");
            printf("%3d",nomal[i]);
        }
        return 0;
    }
    
    printf("앞자리에 앉을 학생의 번호를 입력하세요 : ");
    
    for(int i=0; i<up; i++) {
        scanf("%d",&upstudent[i]);
    }
    
    srand((int)time(NULL));
    for(int i=0; i<100; i++) {
        int r = rand() % up;
        int temp = upstudent[0];
        upstudent[0] = upstudent[r];
        upstudent[r] = temp;
    }
    
    tmp = students-up;
    
    if (tmp == 0) {
        for (int i=0; i<students; i++)
            printf("%d",upstudent[i]);
        return 0;
    }
    
    for(int i=0; i<=students; i++) {
        for(int j=0; j<up; j++) {
            if(nomal[i] == upstudent[j]) {
                flag = 1;
            }
        }
        if(flag==1) {
            flag = 0;
            continue;
        }
        else {
            leftstudent[point] = nomal[i];
            point++;
        }
    }
    
    srand((int)time(NULL));
    for(int i=0; i<100; i++) {
        int r = rand() % tmp;
        int temp = leftstudent[0];
        leftstudent[0] = leftstudent[r];
        leftstudent[r] = temp;
    }

    
    for (int i=0; i<up; i++) {
        if(left%column==0)
            printf("\n");
        printf("%3d",upstudent[i]);
        left++;
    }
    
    for (int i=0; i<tmp; i++) {
        if(left%column==0)
            printf("\n");
        printf("%3d",leftstudent[i]);
        left++;
    }
}
