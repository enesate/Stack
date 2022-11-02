#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

#define MAX 100

int count = 0;

// struct yapısı
struct stack {
  int items[MAX];
  int top;
};
typedef struct stack st;

//stack eleman silme
void pop(st *s){
    if(s->top==0)
        printf("stack boş");
    else
        s->top--;
}

//stack e eleman ekleme
void push(st *s, int newitem) {
  if (s->top == MAX - 1) {
    printf("stack dolu");
  } else {
    s->top++;
    s->items[s->top] = newitem;
  }
  count++;
}
//stack oluşturma
void createEmptyStack(st *s) 
{
    s->top = -1; 
}
//stackdeki elemanları yazdırma
void printStack(st *s) {
  printf("Stack: ");
  for (int i = 0; i < count; i++) {
    printf("\n %d", s->items[i]);
  }
  printf("\n");
}
// stack de arama yapma
void search(st *s, int arananSayi) {
    int max=100;
  while(max--){
      if (arananSayi == s->items[max]) {
      printf("%d sayısı bulundu", s->items[max]);
      printf(" alttan %d.sıra  \n", 100-max);
      break;
    } 
  }
  if(arananSayi != s->items[max])
  {
    printf("%d sayısı bulunamadı\n",arananSayi);
  }
}
int main() {
  st *s = (st *)malloc(sizeof(st));
  int max = 100;
  int random;
  createEmptyStack(s);
  srand(time(NULL));
  while (max--) {
    random = rand() % 1000 + 1;
    push(s, random);
  }
  int girilenSayi;
  printf("0-1000 arasında bir sayı giriniz:");
  scanf("%d", &girilenSayi);
  search(s, girilenSayi);
  printStack(s);
}