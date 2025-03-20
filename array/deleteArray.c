#include <stdio.h>
/*
  배열 요소 삭제 
  요소 삭제 시, 해당 위치 이후의 요소를 한 칸씩 앞으로 이동해야한다
  과정 : 삭제 인덱스 찾음 -> 해당 인덱스 이후의 요소를 한 칸씩 앞으로 이동 -> 배열 크기 1 감소
*/

void delete(int arr[], int *size, int pos) {
  for (int i = pos; i < *size -1; i++) {
    arr[i] = arr[i+1]; //한 칸씩 앞으로 이동
  }
  (*size)--; //배열 크기 감소
}

int main() {
  int arr[20] = {1, 5, 10, 15, 20};
  int size = 5;

  delete(arr, &size, 3);

  for (int i = 0; i<size; i++){
    printf("%d", arr[i]);
  }
  
  return 0;
}