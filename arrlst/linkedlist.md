##  The advantages of linked lists include:
- 메모리만 충분하다면 오버플로우는 발생하지 않는다.
- 삽입, 삭제연산이 array list보다 쉽다.(overflow걱정 ㄴㄴ)
- 많은 수의 데이터를 다룰때, element의 위치자체를 옮기는 것보다, 포인터로 바꿔주는게 편하다.


## The disadvantages of linked lists include:
- 포인터는 많은 공간을 요구로한다.
- arraylist와 달리 랜덤액세스를 허용하지 않는다.(index로 임의접근 불가)
pointers.
- 순회하고, 포인터를 바꾸는데에 시간이 걸린다.
- 포인터는 어렵다 ㅋ


SINGLY LINKED LIST OPERATION	ASSUMED TIME COMPLEXITY
Access i-th element						O(N)
Traverse all elements					O(N)
Insert element E at current point		O(1)
Delete current element					O(1)
Insert element E at front				O(1)
Insert element E at end					O(N)

arrlist와 다른점은, 현재 포인터에 삽입, 삭제연산을 하고싶다면 시간복잡도가 O(1)이라는 것이다.  
맨 마지막 원소를 없애고 싶다면, arrlist는 단순히 current_count를 줄여서 사용하지 못하게하면되나, linkedlist는 마지막 원소까지 타고가서 remove를 해야하므로, 더 많은 시간복잡도가 필요하다.
