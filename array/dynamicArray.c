#include <stdio.h>
#include <stdlib.h>
/*
  동적 배열 삽입, 삭제 등 구현해보기 메모리관리 등의 이유로 구현해보자
*/

typedef struct
{
  int *data;    // 배열 포인터
  int size;     // 현재 배열 크기
  int capacity; // 최대 용량 
} DynamicArray;

//동적 배열 초기화
void initArray(DynamicArray *arr, int capacity){
  arr->data = (int*)malloc(capacity * sizeof(int));
  arr->size = 0;
  arr->capacity = capacity;
}

//동적 배열
void resizeArray(DynamicArray *arr, int newCapacity){
  arr->data = (int*)realloc(arr->data, newCapacity * sizeof(int));
  arr->capacity = newCapacity;
}

//배열 삽입
void insert(DynamicArray *arr, int value){
  if (arr->size >= arr->capacity){
    resizeArray(arr, arr->capacity * 2); //크기 2배 증가
  }
  arr->data[arr->size++] = value;
}

// 특정 인덱스 삭제
void delete(DynamicArray *arr, int index){
  if(index < 0 || index >= arr->size){
    printf("삭제 중 에러");
    return;
  }

  //인덱스 이후 값을 한 칸씩 앞으로 이동
  for(int i = index; i < arr->size - 1; i++){
    arr->data[i] = arr->data[i+1];
  }
  arr->size--; //크기 감소

  //사용하지 않는 메모리가 많으면 축소
  if (arr->size < arr->capacity /4) {
    resizeArray(arr, arr->capacity / 2);
  }
}

//배열 출력
void printArray(DynamicArray *arr) {
  for (int i = 0; i < arr->size; i++){
    printf("%d", arr->data[i]);
  }
  printf("\n");
}

//메모리 해제
void freeArray(DynamicArray *arr){
  free(arr->data);
  arr->size = 0;
  arr->capacity = 0;
}

// 실행
int main(){
  DynamicArray arr;
  initArray(&arr, 2); //초기 사이즈 2

  insert(&arr, 10);
  insert(&arr, 20);
  insert(&arr, 30);
  insert(&arr, 40);
  printArray(&arr);

  delete(&arr, 1);
  printArray(&arr);

  insert(&arr, 50);
  insert(&arr, 60);
  printArray(&arr);

  freeArray(&arr);
  return 0;
}
