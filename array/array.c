#include <stdio.h>

/*
배열은 이미 구현되어 있어 간단한 출력 코드만 만들어 보자
*/
int main() {
  int arr[5] = {1, 2, 3, 4, 5};
  printf("배열 출력 : ");
  for(int i = 0; i<5; i++){
    printf("%d", arr[i]);
  }
  printf("\n");

  return 0;
}