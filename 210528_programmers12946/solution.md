# 12946. 하노이의 탑

**Level 3**

https://programmers.co.kr/learn/courses/30/lessons/12946

# 풀이

재귀함수의 기본인 하노이의 탑이다. 
두개의 원판을 1번에서 3번으로 옮기기 위해서는 3개의 작업이 이루어진다. 
1. 윗 원판을 2번으로 옮긴다. 
2. 아래 원판을 3번으로 옮긴다. 
3. 윗 원판을 2에서 3번으로 옮긴다. 

이를 확장 시켜서 2개 이상의 원판에 대해서는 윗부분과 가장 아래 원판으로 분리 시켜주면된다. 
1. 가장 아래를 제외한 원판들을 2번으로 옮긴다. (재귀적인 호출 이용)
2. 아래 원판을 3번으로 옮긴다. 
3. 가장 아래를 제외한 원판들을 3번으로 옮긴다. (재귀적인 호출 이용)