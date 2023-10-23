/*
 * linked_list.h
 *
 *  Created on: Jul 30, 2023
 *      Author: Mo'men
 */

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

typedef struct node{
	void *data;
	struct node * next;
}Node;



void ListInit            (void);
void AddNodeLast         (void *value);
void AddNodeFirst        (void *value);
void AddNode             (void *value, int position);
void DeleteNodeFirst     (void);
void DeleteNodeLast      (void);
void DeleteNodePosition  (int position);
void DeleteNodeValue     (void *value);
void PrintList           (void);
void getDataByIndex		 (int index, void * ptrToData);


#endif /* LINKED_LIST_H_ */
