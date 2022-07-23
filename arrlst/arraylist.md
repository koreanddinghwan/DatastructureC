array 정리
https://www.geeksforgeeks.org/time-complexities-of-different-data-structures/
https://iq.opengenus.org/time-complexity-of-array/
https://www.simplilearn.com/tutorials/data-structure-tutorial/arrays-in-data-structure
1. 시간복잡도

## access 

특정 값의 위치를 알고있다면, 인덱스로 바로 접근할 수 있다(unit time 접근이 가능하다)는 장점이 있다.  
값의 인덱스를 알고있다는 가정하에 `O(1)의 시간복잡도`를 가진다.  
인덱스를 통해 `random access`가 가능해서 list보단 search 성능이 좋다.  


## insert 

insert하는 경우, 맨 앞에 데이터를 넣어야하는 경우, 모든 데이터를 뒤로 밀어야하므로 `O(N)`의 시간복잡돌르 가진다.

## search

search 연산은 값을 모르고있다는 가정하에 모든 배열을 순회해야하므로, `O(N)`의 시간복잡도를 가진다.

## delete

delete하는 경우에도 최악의 경우 가장 앞의 데이터를 삭제해야한다면, 
모든 데이터를 앞으로 이동해야하므로, 시간복잡도는 `O(N)`  

단, 데이터를 clear, 초기화하는 연산의 경우, cur_index를 0으로만 바꿔주면 되므로, 이쪽에서 강점을 가진다.

## 공간복잡도  

선형의 배열을 가지므로, 공간복잡도는 `O(1)`이다.  
고정된 수의 변수만을 가질 수 있기 때문이다.  
만약, 추가적인 공간을 요구로하는(병합정렬) 알고리즘으로 정렬하는 경우에 공간복잡도는 더 늘어날 수 있다.  

## 장점

- 메모리 오버플로우를 방지한다.(고정으로 배열을 선언하므로, 한 번 선언한 후에는 계속 사용가능)
- 리스트처럼 노드를 계속 추가하지 않으므로, 추가적인 메모리 손실이 없다.
- 랜덤액세스가 가능하다.

## 단점

- 원소의 개수를 미리 알아야한다.
- 선언 후 크기를 변경할수는 있으나, 매우 귀찮다.
- 삽입, 삭제 연산에서 모든 원소를 움직여야하므로, 이 작업에서는 느리다.
- 필요한 것보다 많은 메모리를 할당하면 메모리가 낭비된다.
