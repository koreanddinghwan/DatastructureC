/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 16:34:30 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/25 10:53:22 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>
// #include "createLinkedList.c"
// #include "addLLElement.c"
// #include "removeLLElement.c"
// #include "getLLElement.c"
// #include "clearLinkedList.c"
// #include "getLinkedListLength.c"
// #include "deleteLinkedList.c"


void displayLinkedList(LinkedList *head)
{
	ListNode	*temp;
	int			cnt;

	if (head->currentElementCount == 0)
		printf("LinkedList is Null =====================\n");
	else
	{
		cnt = 0;
		temp = head->headerNode.pLink;
		printf("LinkedList currentElementCount : %d\n", head->currentElementCount);
		while (temp)
		{
			printf("LinkedList Index[%d] : %d\n", cnt, temp->data);
			temp = temp->pLink;
			cnt++;
		}
	}
}

int	main(void)
{
	LinkedList	*head;
	ListNode	node1;
	ListNode	node2;
	ListNode	node3;
	ListNode	node4;
	ListNode	node5;

	printf("createLinkedList =====================\n");
	head = createLinkedList();
	printf("addALElement =====================\n");

	node1.data = 10;
	addLLElement(head, 0, node1);
	node2.data = 3;
	addLLElement(head, 1, node2);
	node3.data = -1;
	addLLElement(head, 0, node3);
	node4.data = 5;
	addLLElement(head, 3, node4);
	node5.data = 10;
	addLLElement(head, 5, node5);
	displayLinkedList(head);
	printf("getLinkedListLength =====================\n");
	printf("Length : %d\n", getLinkedListLength(head));
	printf("getLLElement Index 3 =====================\n");
	printf("getLLElement[1] : %d\n", getLLElement(head, 1)->data);
	printf("getLLElement[3] : %d\n", getLLElement(head, 3)->data);	
	printf("removeLLElement Index 3 =====================\n");
	removeLLElement(head, 3);
	displayLinkedList(head);
	printf("clearLinkedList =====================\n");
	clearLinkedList(head);
	displayLinkedList(head);
	printf("deleteLinkedList =====================\n");
	deleteLinkedList(head);
	displayLinkedList(head);

	return (0);
}
