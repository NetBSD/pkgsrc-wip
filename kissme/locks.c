/*
 * Copyright (C) 2001, John Leuner.
 *
 * This file is part of the kissme/teaseme project, which in turn is part
 * of the JOS project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2,
 * or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

#include "config.h"
#include "vm/wrappers.h"
#include "vm/stdtypes.h"
#include "vm/thread.h"
#include "vm/jni.h"
#include "vm/locks.h"

#include "vm/interp_methods.h"
#include "vm/newobject.h"

/* 
 * This file contains a new lock implementation for kissme/teaseme
 *
 * It is based on Roger Bacon's thin locks and some ideas from IBM's
 * work on their JDK as well as a paper by Etienne Gagnon on SableVM.
 *
 * Status 15/01
 *	- atomic enter done for unlocked and same thread cases
 *	- atomic enter not done for contention case
 *	- exit for single lock and recursive cases done
 *	- exit for foreign owner not done
 *
 * When a thread tries to acquire a lock an object and it sees that
 * the lock is already owned by another thread (and is thin), it
 * should:
 * 1) find the owning thread
 * 2) acquire the mutex for that thread
 * 3) set the contention bit for that thread
 * 3.1) rechecks the lock
 * 5) if set, adds the tuple <this thread, this object, cond var> to 
 *    the owning threads list
 * 5.1) then sleep on the cond var
 * 6) else check if the lock is thin
 * 7) if so go back to 1)
 * 8) else acquire the fat lock
 *
 * When a thread is about to release a thin lock, it should check its
 * contention bit. If it is set:
 * 1) It should aquire its own contention mutex
 * 1.1) Inflate the lock to a fat lock
 * 2) For each tuple in the list, if the object matches the current object
 * 3) Signal that cond var in the tuple
 * 4) else if it's a different object, inflate that lock and signal the thread
 * 4) Clear the waiting list
 * 5) Clear contention bit
 * 6) Release its contention lock
 *
 * 24/01/2001 - Creating a separate structure that holds fat locks
 * 
 * This means that the lock word will now hold 1 bit indicating
 * whether it is a fat or thin lock:
 *  0 indicates a fat lock or no lock
 *  1 indicates a thin lock
 * Then the last 8 bits are a recursion count in the case of a thin lock
 * The next 23 bits are a thread identifier in the thin lock case
 *
 * If it is a fat lock, the next 31 bits are a pointer to the fat monitor.
 * The fat monitor's address must be word aligned
 *
 * 06/09/2002 - crawley@dstc.edu.au
 * A call to Thread.interrupt() should cause a thread that is waiting in
 * Object.wait(...) to stop waiting and throw InterruptedException.
 * However, a waiting thread will typically be blocked on a condition
 * variable in pthread_cond_wait or pthread_cond_timedwait.  We can't
 * unblock the thread by using pthread_kill, because LinuxThreads won't
 * return EINTR (or anything).  The thread can only be woken up using
 * pthread_cond_broadcast.
 */


#ifdef KISSME_LINUX_USER
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>
#endif

#include <errno.h>

#ifdef SABLE_LOCKS

#include "vm/threads_native.h"
#include "vm/interp.h"

#ifndef TEASEME
int pthread_mutexattr_setkind_np (pthread_mutexattr_t* kind, int tkind);
#endif

/* Structure of the lock word
 *
 * Thin lock case, 
 * T is 1 (1 bit)
 * x is unused (7 bits)
 * I is the thread identifier (16 bits)
 * R is the recursion count (8 bits)
 *
 * bit 31                         bit 0
 * |--------------------------------|
 * |TxxxxxxxIIIIIIIIIIIIIIIIRRRRRRRR|
 * |--------------------------------|
 *
 * Fat lock case
 *
 * T is 0 (1 bit)
 * P is the pointer to the fat lock struct >> 1 (31 bits)
 *
 * bit 31                        bit 0
 * |--------------------------------|
 * |TPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP|
 * |--------------------------------|
 *
 * If the whole word is 0, there is no lock
 *
 */

// Macros for handling lock_word values

#define RECURSION_COUNT_MASK 0xff
#define MAX_INLINE_RECURSION_COUNT ((uint8) RECURSION_COUNT_MASK)
#define THREAD_ID_SHIFT 8
#define THREAD_ID_MASK THREAD_ID_MAX << THREAD_ID_SHIFT
#define THIN_THICK_MASK 0x80000000
#define THIN_BIT THIN_THICK_MASK
#define FAT_LOCK_SHIFT 1

#define IS_THIN_LOCK(_word) \
  (((_word) & THIN_THICK_MASK) == THIN_BIT)
#define GET_FAT_LOCK(_word) \
  ((tFatlock *) ((_word) << FAT_LOCK_SHIFT))
#define GET_THREAD_ID(_word) \
  ((threadId_t) (((_word) & THREAD_ID_MASK) >> THREAD_ID_SHIFT))
#define GET_RECURSION_COUNT(_word) \
  ((unsigned char) ((_word) & RECURSION_COUNT_MASK))
#define FAT_LOCK_WORD(_ptr) \
  ((uint32) (((uint32) _ptr) >> FAT_LOCK_SHIFT))
#define THIN_LOCK_WORD(_threadId, _recursion) \
  ((uint32) (THIN_BIT | (((_threadId) << THREAD_ID_SHIFT) & THREAD_ID_MASK) | \
              ((_recursion) & RECURSION_COUNT_MASK)))

// The threadId bitmap.

#define NOS_THREAD_ID_WORDS (NOS_THREAD_IDS / 32)

static uint32 threadIdBitmap[NOS_THREAD_ID_WORDS];
static int freeThreadIdHint;
static pthread_mutex_t threadIdMutex;


void THREAD_SynchroniseEnter (tOBREF pstObject	/* @parm Object to lock */ )
{
  uint32 before;
  pthread_t pthread = sys_current_thread();
  threadId_t threadId = THREAD_getThreadId(pthread);
  uint32 temp_word;
  
  // set high bit to 1 (thin lock), set the next 23 bits to the thread
  // identifier, and set the recursion count to 1
  
  temp_word = THIN_LOCK_WORD(threadId, 1);

  traceLock("(pthread %i) Before locking %p, lock word is %x",
	    (int) pthread, pstObject, ODEREF(pstObject)->lock_word);
  
  before = ODEREF(pstObject)->lock_word;
  
  if (before == 0) {		//object is unlocked
#if (defined( __powerpc__))

    //XXX do we have to check result?
    uint32 result, tmp;
    __asm__ __volatile__ (
			  "  li %0,0;" /* result = 0. Assume failure. */
			  "1:lwarx %1,0,%2;" /* tmp = *pword, and reserve address. */
			  "  cmpw %1,%3;" /* Is tmp == old_value? */
			  "  bne 2f;" /* unequal, done. */
			  "  stwcx. %4,0,%2;" /* *pword = new_value, if reserved. */
			  "  bne- 1b;" /* Try again if reservation failed. */
			  "  li %0,1;" /* result = 1. Success!*/
 "2:"
			  : "=&r" (result), "=r&" (tmp)
			  : "r" (&ODEREF(pstObject)->lock_word), "r" (before), "r" (temp_word)
			  : "cr0", "memory"); /* Sets cr0 field and changes memory (*pword) */


    //	__asm__ __volatile__ (".set noat ; add $0, %0, $1 ; \n":"=r" (temp_word));
    //    printf("result is %lx, tmp is %lx, before is %x, temp_word %lx", result, tmp, before, temp_word);
#else
    // set eax to 0
    // compare ecx to eax, if they are the same, then copy ecx (temp_word) 
    //   to lock_word
    __asm__ __volatile__ ("movl $0x0, %%eax ; \n"
			  "movl %1, %%ecx ; \n"
			  " cmpxchg %%ecx,%0 ; \n":"=r" (ODEREF(pstObject)->lock_word):"r"
			  (temp_word),
			  "0" (ODEREF(pstObject)->lock_word):"ax", "cx");
#endif
    traceLock("(pthread %i) locked object %p (%s), Lock word is now %x",
	      (int) pthread, pstObject, ODEREF(pstObject)->pstType->uidName, 
	      ODEREF(pstObject)->lock_word);
  }
  else {
    //check if it is a fat or thin lock
    if (IS_THIN_LOCK(ODEREF(pstObject)->lock_word)) {
      //this is a thin lock
      if (GET_THREAD_ID(ODEREF(pstObject)->lock_word) == threadId) {
	//we own the lock
	//so we just increment the count
	if (GET_RECURSION_COUNT(before) == MAX_INLINE_RECURSION_COUNT) {
	  traceLock("(pthread %i) thin lock overflow", (int) pthread);
	  // XXX - shouldn't we inflate the lock?
	  temp_word = before;
	}
	else {
	  temp_word = before + 1;
	}
	
	{
#if (defined(__powerpc__))

    //XXX do we have to check result?
   uint32 result, tmp;
    __asm__ __volatile__ (
			  "  li %0,0;" /* result = 0. Assume failure. */
			  "1:lwarx %1,0,%2;" /* tmp = *pword, and reserve address. */
			  "  cmpw %1,%3;" /* Is tmp == old_value? */
			  "  bne 2f;" /* unequal, done. */
			  "  stwcx. %4,0,%2;" /* *pword = new_value, if reserved. */
			  "  bne- 1b;" /* Try again if reservation failed. */
			  "  li %0,1;" /* result = 1. Success!*/
 "2:"
			  : "=&r" (result), "=r&" (tmp)
			  : "r" (&ODEREF(pstObject)->lock_word), "r" (before), "r" (temp_word)
			  : "cr0", "memory"); /* Sets cr0 field and changes memory (*pword) */
	
#else
	__asm__ __volatile__ ("movl %3, %%eax ; \n"
			      "movl %1, %%ecx ; \n"
			      " cmpxchg %%ecx,%0 ; \n":"=r" (ODEREF(pstObject)->lock_word):"r"
			      (temp_word),
			      "0" (ODEREF(pstObject)->lock_word),
			      "r" (before):"ax", "cx");
#endif
	}
	//again we must check if we succeeded
	if (temp_word == ODEREF(pstObject)->lock_word) {
	  traceLock("(pthread %i) inc atomic lock succeeded: " 
		    "now %x, obj %p, type %s",
		    (int) pthread,
		    ODEREF(pstObject)->lock_word, pstObject,
		    ODEREF(pstObject)->pstType->uidName);
	}
	else {
	  panic("Tried to do incremental lock but failed %x",
		(int) ODEREF(pstObject)->lock_word);
	}
      }
      else {			//we aren't the owner
	int oldContentionState;
	uint32 tmpword;
	threadId_t id = GET_THREAD_ID(ODEREF(pstObject)->lock_word);
	tThreadNode *threadNode = THREAD_FindThreadByID(id);

	// XXX - the test for 'threadNode != NULL' is an attempt
	// to deal with the case where a thread exits leaving locked
	// objects and/or possible race conditions with an exitting thread.
	// However, I think the races still may exist ...
	if (threadNode != NULL) {
	  assert(threadNode->pthread != pthread);
	  traceLock("(pthread %i) contention for %p locked by pthread %i", 
		    (int) pthread, pstObject, (int) id);
	  
	  // Lock the contention lock mutex for the thread that currently
	  // owns the lock, and set its contention bit
	  sys_mutex_lock (threadNode->mutContentionLock);
	  oldContentionState = threadNode->i32ContentionBit;
	  threadNode->i32ContentionBit = 1;
	  
	  if (threadNode->pstWaitList == NULL) {
	    threadNode->pstWaitList = LLIST_Create_List();
	  }
	  
	  {
	    // Make a 'wait' tuple and add it to the wait list for the 
	    // lock's current owner
	    tWaitStruct *waitStruct = sys_malloc(sizeof(tWaitStruct));
	    
	    waitStruct->threadId = threadId;	
	    waitStruct->object = pstObject;
	    waitStruct->cond = sys_condition_create();
	    LLIST_AddAtHead(threadNode->pstWaitList, waitStruct);
	    
	    // Sleep on the cond var
	    traceLock("(pthread %i) waiting for object %p on cond %p)",
		      (int) pthread, pstObject, waitStruct->cond);
	    sys_condition_wait(waitStruct->cond, 
			       threadNode->mutContentionLock);
	    traceLock("(pthread %i) was signalled (object %p, cond %p)",
		      (int) pthread, pstObject, waitStruct->cond);
	    // We've returned from the sleep, so remove the tuple from the 
	    // wait list and free it
	    LLIST_Remove(threadNode->pstWaitList, waitStruct);
	    sys_condition_destroy(waitStruct->cond);
	    sys_free(waitStruct);
	  }
	  // Unlock the contention lock
	  sys_mutex_unlock(threadNode->mutContentionLock);
	}

	// Finally, attempt to acquire the lock again.
        tmpword = (ODEREF(pstObject)->lock_word);
	if (tmpword == 0 || IS_THIN_LOCK(tmpword)) {
	  traceLock("(pthread %i) lock still thin for object %p, %x", 
		    (int) pthread, pstObject, tmpword);
	  traceLock("(pthread %i) recursing for object %p",
		    (int) pthread, pstObject);
	  THREAD_SynchroniseEnter(pstObject);
	}
	else {
	  tFatlock* lock = GET_FAT_LOCK(tmpword);
	  assert(lock);
	  sys_mutex_lock(lock->lock); //acquire the mutex (maybe recursively)
	  lock->recursion_count++;
	  lock->owner = threadId;
	  traceLock("(pthread %i) contention lock succeeded: " 
		    "obj %p, rc %i, type %s",
		    (int) pthread,
		    pstObject, lock->recursion_count,
		    ODEREF(pstObject)->pstType->uidName);
	}
	return;
      }
    }
    else {
      //this is a fat lock
      uint32 tmpword = (ODEREF(pstObject)->lock_word);
      traceLock("(pthread %i) is a fat lock %x %x", 
		(int) pthread, before, before << 1);
      if (tmpword == 0 || IS_THIN_LOCK(tmpword)) {
	  traceLock("(pthread %i) recursing for object %p",
		    (int) pthread, pstObject);	
	THREAD_SynchroniseEnter(pstObject);
      }
      else {
	tFatlock *lock = GET_FAT_LOCK(tmpword);
	sys_mutex_lock(lock->lock); //acquire the mutex (maybe recursively)
	lock->recursion_count++;
	lock->owner = threadId;
	traceLock("(pthread %i) fat lock succeeded: object %p, rc %i",
		  (int) pthread, pstObject, lock->recursion_count);
      }
      return;
    }
  }
  
  //check if we succeeded
  if (temp_word == ODEREF(pstObject)->lock_word) {
    traceLock("(pthread %i) Succeeded in doing atomic lock %x",
	      (int) pthread, ODEREF(pstObject)->lock_word);
  }
  else {
    //this means either we, or someone else, owns the lock
    panic("The lock word is %x, expected %x", 
	  (int) ODEREF(pstObject)->lock_word, (int) temp_word);
  }
}


/* This is called from SynchroniseExit when the current thread has its
 * contention bit set (which means there are other threads which want
 * this (or another) lock that this thread is holding)
 */
int THREAD_HandleContendedThread(tOBREF pstObject, tThreadNode* threadNode,
				 pthread_t pthread)
{
  tListIterator *iter;

  traceLock("(pthread %i) Contention bit set for object %p, lock word %x", 
	    (int) pthread, pstObject, ODEREF(pstObject)->lock_word);

  if (threadNode->pstWaitList) {
    iter = LLIST_FindFirst(threadNode->pstWaitList);
    while (iter != NULL) {
      tWaitStruct *waitStruct = (tWaitStruct *) iter->entry->payload;
      if (waitStruct->object == pstObject) {
	traceLock("(pthread %i, object %p) Signalling cond %p",
		  (int) pthread, pstObject, waitStruct->cond);
	  //just signal the thread
	sys_condition_broadcast(waitStruct->cond); //wake up all threads(
      }
      else {
	tOBREF pstLockedObject = waitStruct->object;
	uint32 lock_word = ODEREF(pstLockedObject)->lock_word;

	//not only signal the thread, but inflate the lock to a fat lock
	if (IS_THIN_LOCK(lock_word)) {
	  int j = 0;
	  tFatlock* lock = (tFatlock*) sys_malloc(sizeof(tFatlock));
	  int rec = GET_RECURSION_COUNT(lock_word);

	  traceLock("(pthread %i, object %p) Inflating lock on object %p", 
		    (int) pthread, pstObject, pstLockedObject);
	  lock->lock = sys_mutex_create(1);
	  lock->owner = GET_THREAD_ID(lock_word);
	  lock->recursion_count = rec;
	  
	  for (j = 0; j < rec; j++) {
	    //make sure the recursion count stays the same for the lock
	    sys_mutex_lock(lock->lock);
	  }
	  ODEREF(pstLockedObject)->lock_word = FAT_LOCK_WORD(lock);
	}
	traceLock("(pthread %i, object %p) Signalling cond %p",
		  (int) pthread, pstObject, waitStruct->cond);
	sys_condition_broadcast(waitStruct->cond); //wake up all threads
	
      }
      iter = LLIST_FindNext(threadNode->pstWaitList, iter);
    } //while iter != NULL
  }
  threadNode->i32ContentionBit = 0;
  ODEREF(pstObject)->lock_word = 0;
  return 0;
}


void THREAD_SynchroniseExit (tOBREF pstObject /* @parm Object to release */)
{
  uint32 tmpword = ODEREF(pstObject)->lock_word;
  pthread_t pthread = sys_current_thread();
  threadId_t threadId = THREAD_getThreadId(pthread);
  
  if (tmpword == 0) {
    panic("Object %p, type %s is not locked in SynchroniseExit!", 
	  pstObject, ODEREF(pstObject)->pstType->uidName);
  }

  traceLock("(pthread %i) Unlocking object %p: lock_word is %x", 
	    (int) pthread, pstObject, tmpword);

  if (!IS_THIN_LOCK(tmpword)) {
    tFatlock* lock = GET_FAT_LOCK(tmpword);

    traceLock("(pthread %i) fat lock in unlock: obj %p, rc %i", 
	      (int) pthread, pstObject, lock->recursion_count);
    assert(lock->recursion_count > 0);
    assert(lock->owner == threadId);
    lock->recursion_count--;
    sys_mutex_unlock(lock->lock);
  }
  else {
    //we are the owner
    int recursion_count = GET_RECURSION_COUNT(tmpword);

    traceLock("(pthread %i) thin lock in unlock: obj %p, rc %i",
	      (int) pthread, pstObject, recursion_count);
    assert(GET_THREAD_ID(tmpword) == threadId);
    assert(recursion_count > 0);
    if (recursion_count == 1) {
      //this must go back to unlocked
      tThreadNode *threadNode = THREAD_FindThread();
      assert(threadNode);
      sys_mutex_lock(threadNode->mutContentionLock);
      if (threadNode->i32ContentionBit) {
	THREAD_HandleContendedThread(pstObject, threadNode, pthread);
      }
      else {
	ODEREF(pstObject)->lock_word = 0; 			
      }
      traceLock("(pthread %i) after thin lock unlock: obj %p, lock_word %x",
		(int) pthread, pstObject, ODEREF(pstObject)->lock_word);
      sys_mutex_unlock(threadNode->mutContentionLock);
    }
    else {
      //since we own the lock, this doesn't have to be atomic
      ODEREF(pstObject)->lock_word = tmpword - 1; 
      traceLock("(pthread %i) after thin lock unlock: obj %p, lock_word %x",
		(int) pthread, pstObject, ODEREF(pstObject)->lock_word);
    }
  }
}


int THREAD_FreeLocks()
{
  tThreadNode *threadNode = THREAD_FindThread();
  tListIterator *iter;

  sys_mutex_lock(threadNode->mutContentionLock);
  
  if (threadNode->pstWaitList) {
    iter = LLIST_FindFirst(threadNode->pstWaitList);
    while (iter != NULL) {
      tWaitStruct *waitStruct = (tWaitStruct *) iter->entry->payload;
      //just signal the thread
      sys_condition_signal(waitStruct->cond);
      iter = LLIST_FindNext(threadNode->pstWaitList, iter);
    }
    LLIST_DestroyList(threadNode->pstWaitList);
  }

  threadNode->i32ContentionBit = 0;
  threadNode->pstWaitList = NULL;
  sys_mutex_unlock(threadNode->mutContentionLock);
  return 0;
}


/*
 * @doc FUNC
 * @func
 * This procedure causes the current thread to wait on the specified
 * object either until it is notified, its waiting time expires or the
 * thread is interrupted by Thread.interrupt(). If the specified
 * waiting time is 0 then it waits forever or until notified.
 *
 * The calling thread has to have obtained a lock (monitorenter) on
 * the object before calling wait.  
 */
int THREAD_WaitOnObject (JNIEnv* env, 
			 tOBREF pstObject, /* @parm Object on which to wait */
			 jlong millis)
{
#ifdef SABLE_LOCKS
  pthread_t pthread = sys_current_thread();
  threadId_t threadId = THREAD_getThreadId(pthread);
  tThreadNode *threadNode = THREAD_FindThread();
  tTimeSpec timeout;
  
  int lock_word = ODEREF(pstObject)->lock_word;
  int own_lock = 0;
  tOBREF pstExOb = NULL;

  if (threadNode->isInterrupted) {
    threadNode->isInterrupted = 0;
    return (int) INTERP_ExceptionObjectFromNameAndMessage(env, "java/lang/InterruptedException", "");
  }

  assert(pthread);
  traceThreads("WaitOnObject: (pthread %i) obj %p, millis %li", 
	       (int) pthread, pstObject, millis);

  // check that the object is locked by this thread
  if (IS_THIN_LOCK(lock_word)) {
    if (GET_THREAD_ID(lock_word) == threadId) {
      own_lock = 1;
    }
  }
  else if (lock_word != 0) {
    if (GET_FAT_LOCK(lock_word)->owner == threadId) {
      own_lock = 1;
    }
  }
  
  if (own_lock != 0) {
    // this thread owns the lock on this object (as it should)
    int recursion_count, i, rc;
    tCondVariable* cond = ODEREF(pstObject)->condVariable;
    
    sys_mutex_lock(threadNode->mutContentionLock);

    // release the java lock on this object as many times as we own it
    if (IS_THIN_LOCK(lock_word)) {
      recursion_count = GET_RECURSION_COUNT(lock_word);
    }
    else {
      recursion_count = GET_FAT_LOCK(lock_word)->recursion_count;
    }
    for (i = 0; i < recursion_count; i++) {
      traceThreads("WaitOnObject: (pthread %i) relinquishing lock #%i on %p",
		   (int) pthread, i, pstObject);
      THREAD_SynchroniseExit(pstObject);
    }
    
    // change the thread's state to 'waiting'
    threadNode->state = THREAD_STATE_WAITING;
    threadNode->waitObject = pstObject;
    
    if (millis == 0) {
      traceThreads("WaitOnObject: (pthread %i, obj %p) wait", 
		   (int) pthread, pstObject);
      rc = sys_condition_wait(cond, threadNode->mutContentionLock);
    }
    else {
      traceThreads("WaitOnObject: (pthread %i, obj %p) timedwait", 
		   (int) pthread, pstObject);
      timeout.tv_sec = millis;
      timeout.tv_nsec = 0; 
      rc = sys_condition_timedwait(cond, threadNode->mutContentionLock,
				   &timeout);
    }
    traceThreads("WaitOnObject: wait (pthread %i) returned %li, "
		 "thread state %li", 
		 (int) pthread, rc, threadNode->state);

    // XXX - check the rc??
    
    // now that the wait has finished, acquire reacquire the lock, the
    // same number of times we had it before.
    for (i = 0; i < recursion_count; i++) {
      traceThreads("WaitOnObject: (pthread %i) regaining lock #%i on %p",
		   (int) pthread, i, pstObject);
      THREAD_SynchroniseEnter(pstObject);
    }

    // finally, decide if we were interrupted
    if (threadNode->state == THREAD_STATE_WAIT_INTERRUPTED) {
      pstExOb = 
	INTERP_ExceptionObjectFromNameAndMessage(env, "java/lang/InterruptedException", "");
      threadNode->isInterrupted = 0;
    }
    threadNode->waitObject = NULL;
    threadNode->state = THREAD_STATE_RUNNABLE;
    
    sys_mutex_unlock(threadNode->mutContentionLock);
  }
  else {
    //we don't own this lock, so throw an exception
    pstExOb = INTERP_ExceptionObjectFromNameAndMessage(env, "java/lang/IllegalMonitorStateException", "thread not owner");
  }
#else
  pstExOb = INTERP_ExceptionObjectFromNameAndMessage(env, "java/lang/InternalError", "java.lang.Object.wait not implemented");
#endif
  return (int) pstExOb;
}


void THREAD_Interrupt(JNIEnv* env, tThreadNode* threadNode) 
{
  traceThreads("Interrupt: state for pthread %i is %i", 
	       (int) threadNode->pthread, threadNode->state);
  sys_mutex_lock(threadNode->mutContentionLock);

  switch (threadNode->state) {
  case THREAD_STATE_RUNNABLE:
    traceThreads("Interrupt: setting isInterrupted for pthread %i", 
		 (int) threadNode->pthread);
    threadNode->isInterrupted = 1;
    break;

  case THREAD_STATE_SLEEPING:
    traceThreads("Interrupt: sending SIGUSR1 signal to sleeping pthread %i", 
		 (int) threadNode->pthread);
    if (pthread_kill(threadNode->pthread, SIGUSR1) == -1) {
      panic("THREAD_Interrupt: pthread_kill(%d) failed: %s",
	    (int) threadNode->pthread, sys_errlist[errno]);
    }
    threadNode->state = THREAD_STATE_SLEEP_INTERRUPTED;
    break;

  case THREAD_STATE_WAITING:
    assert(threadNode->waitObject);
    traceThreads("Interrupt: signalling waiting pthread %i", 
		 (int) threadNode->pthread);
    threadNode->state = THREAD_STATE_WAIT_INTERRUPTED;
    sys_condition_signal(ODEREF(threadNode->waitObject)->condVariable);
    break;
 
  default:
    break;
  }
  sys_mutex_unlock(threadNode->mutContentionLock);
}


int THREAD_NotifyRandom(JNIEnv* env, tOBREF pstObject)
{
  return THREAD_Notify(env, pstObject, 0);	//Notify single thread
}


int THREAD_NotifyAll(JNIEnv* env, tOBREF pstObject)
{
  return THREAD_Notify(env, pstObject, 1);	//Notify all threads
}


int THREAD_Notify(JNIEnv* env, tOBREF pstObject, int notify_all)
{
  int own_lock = 0;
  tCondVariable* cond;
  pthread_t pthread = sys_current_thread();
  threadId_t threadId = THREAD_getThreadId(pthread);
  
#ifdef SABLE_LOCKS
  uint32 lock_word = ODEREF(pstObject)->lock_word;

  if (IS_THIN_LOCK(lock_word)) {
    if (GET_THREAD_ID(lock_word) == threadId) {
      //this thread owns the lock on this object (as it should)
      own_lock = 1;
    }
  }
  else if (lock_word != 0) {
    tFatlock* lock = (tFatlock*) (lock_word << 1);
    if (lock->owner == threadId) {
      own_lock = 1;
    }
  }
  
  if (own_lock == 0) {
    // we don't have a lock on this object
    tOBREF pstExOb = INTERP_ExceptionObjectFromNameAndMessage(env, "java/lang/IllegalMonitorStateException", "thread not owner");
    traceLock("(pthread %i) notify on an object not locked by this thread",
	      (int) pthread);
    return (uint32) pstExOb;	
  }

  cond = ODEREF(pstObject)->condVariable;
  if (notify_all) {
    sys_condition_broadcast(cond);
  }
  else {
    sys_condition_signal(cond);
  }
#endif
  return 0;
}



void THREAD_initThreadIds()
{
  int i;
  
  // create the threadIdMutex
  pthread_mutex_init(&threadIdMutex, NULL);

  // Note: we set the bit corresponding to NO_THREAD_ID!
  threadIdBitmap[0] = 1;
  for (i = 1; i < NOS_THREAD_ID_WORDS; i++) {
    threadIdBitmap[i] = 0;
  }
  freeThreadIdHint = 0;
}


threadId_t THREAD_newThreadId(pthread_t hint)
{
  threadId_t threadId;
  int i, j;

  sys_mutex_lock(&threadIdMutex);
  // First try the bottom bits of the supplied pthread
  threadId = (threadId_t) ((char)hint & (char)THREAD_ID_MAX);
  if ((threadIdBitmap[threadId >> 5] & (1 << (threadId & 0x1f))) == 0) {
    // Set the bit and return
    threadIdBitmap[threadId >> 5] |= (1 << (threadId & 0x1f));
    assert(threadId);
    sys_mutex_unlock(&threadIdMutex);
    return threadId;
  }

  // Then scan the bitmap
  for (i = 0; i < NOS_THREAD_ID_WORDS; i++) {
    int ii = (i + freeThreadIdHint) % NOS_THREAD_ID_WORDS;

    // Only look at non-full words
    if (threadIdBitmap[ii] != 0xffffffff) {
      freeThreadIdHint = ii;
      for (j = 0; j < 32; j++) {
	// Search for the first unset bit.
	if ((threadIdBitmap[ii] & (1 << j)) == 0) {
	  // Set the bit
	  threadIdBitmap[ii] |= (1 << j);
	  threadId = ii * 32 + j;
	  assert(threadId);
	  sys_mutex_unlock(&threadIdMutex);
	  return threadId;
	}
      }
      panic0("not reached");
    }
  }

  // No free threadIds!!
  panic0("no free threadIds");
  return NO_THREAD_ID;
}


void THREAD_freeThreadId(threadId_t threadId)
{
  sys_mutex_lock(&threadIdMutex);
  assert(threadId != NO_THREAD_ID);
  assert(threadIdBitmap[threadId >> 5] & (1 << (threadId & 0x1f)));
  threadIdBitmap[threadId >> 5] &= ~(1 << (threadId & 0x1f));
  sys_mutex_unlock(&threadIdMutex);
}


threadId_t THREAD_getThreadId(pthread_t pthread)
{
  tJNIData* jniData = JNI_getJNIData(pthread);

  assert(jniData && jniData->threadId);
  return jniData->threadId;
}


#endif
