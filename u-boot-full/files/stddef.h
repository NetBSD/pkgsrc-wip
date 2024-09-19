#ifndef _STDDEF_H_
#define _STDDEF_H_

#ifdef	__SIZE_TYPE__
typedef __SIZE_TYPE__ size_t;	
#endif

#ifndef NULL
#define NULL ((void*)0)
#endif

#ifndef offsetof
#define	offsetof(type, member)	__builtin_offsetof(type, member)
#endif
 
#endif /* _STDDEF_H_ */
