/*--------------------------------------------------------
* Author             :Jiaq.yang
* Email              :thinklook1@outlook.com
* Create time        :2020-11-11 11:16
* Last modified      :2020-11-11 11:16
* Filename           :linklist.h
* Description        :
----------------------------------------------------------*/
#ifndef _LINKLIST_H_
#define _LINKLIST_H_

#define offset(T, name) (long long)(&(((T *)(NULL))->name))
#define Head(p, T, name) (T *)((char *)(p) - offset(T, name))

struct LinkNode {
	struct LinkNode *next;
};

#endif 
