#include <stdio.h>
/*
  배열의 특정 위치에 삽입하려면, 해당 위치 이후에 요소를 한 칸씩 뒤로 밀어야 한다.
  과정 : 배열의 크기가 충분한지 확인 -> 요소 삽입 위치 이후의 요소를 한 칸씩 뒤로 이동
  -> 원하는 위치에 새 요소 삽입
*/

void insert(int arr[], int *size, int pos, int value){
  if(*size >= 20) return; //배열 크기 제한

  for (int i = *size; i > pos; i--){
    arr[i] = arr[i-1]; //한 칸씩 뒤로 이동 
  }
  arr[pos] = value; //새로운 값 삽입
  (*size)++; //배열 크기 증가
}

int main(){
  int arr[20] = {1, 5, 10, 15, 20};
  int size = 5;

  insert(arr, &size, 3, 18);

  for (int i = 0; i < size; i++){
     printf("%d", arr[i]);
  }
  return 0;
}