$NetBSD$

--- helgrind/hg_intercepts.c.orig	2018-05-05 07:42:22.000000000 +0000
+++ helgrind/hg_intercepts.c
@@ -471,6 +471,12 @@ static int pthread_create_WRK(pthread_t 
       // trap anything else
       assert(0);
    }
+#elif defined(VGO_netbsd)
+   PTH_FUNC(int, pthreadZucreate, // pthread_create
+                 pthread_t *thread, const pthread_attr_t *attr,
+                 void *(*start) (void *), void *arg) {
+      return pthread_create_WRK(thread, attr, start, arg);
+   }
 #elif defined(VGO_solaris)
    PTH_FUNC(int, pthreadZucreate, // pthread_create
                  pthread_t *thread, const pthread_attr_t *attr,
@@ -576,6 +582,11 @@ static int pthread_join_WRK(pthread_t th
             pthread_t thread, void** value_pointer) {
       return pthread_join_WRK(thread, value_pointer);
    }
+#elif defined(VGO_netbsd)
+   PTH_FUNC(int, pthreadZujoin, // pthread_join
+            pthread_t thread, void** value_pointer) {
+      return pthread_join_WRK(thread, value_pointer);
+   }
 #elif defined(VGO_solaris)
    PTH_FUNC(int, pthreadZujoin, // pthread_join
             pthread_t thread, void** value_pointer) {
@@ -867,7 +878,7 @@ static int mutex_destroy_WRK(pthread_mut
    return ret;
 }
 
-#if defined(VGO_linux) || defined(VGO_darwin)
+#if defined(VGO_linux) || defined(VGO_darwin) || defined(VGO_netbsd)
    PTH_FUNC(int, pthreadZumutexZudestroy, // pthread_mutex_destroy
             pthread_mutex_t *mutex) {
       return mutex_destroy_WRK(mutex);
@@ -919,7 +930,7 @@ static int mutex_lock_WRK(pthread_mutex_
    return ret;
 }
 
-#if defined(VGO_linux) || defined(VGO_darwin)
+#if defined(VGO_linux) || defined(VGO_darwin) || defined(VGO_netbsd)
    PTH_FUNC(int, pthreadZumutexZulock, // pthread_mutex_lock
             pthread_mutex_t *mutex) {
       return mutex_lock_WRK(mutex);
@@ -1005,7 +1016,7 @@ static int mutex_trylock_WRK(pthread_mut
    return ret;
 }
 
-#if defined(VGO_linux) || defined(VGO_darwin)
+#if defined(VGO_linux) || defined(VGO_darwin) || defined(VGO_netbsd)
    PTH_FUNC(int, pthreadZumutexZutrylock, // pthread_mutex_trylock
             pthread_mutex_t *mutex) {
       return mutex_trylock_WRK(mutex);
@@ -1109,7 +1120,7 @@ static int mutex_unlock_WRK(pthread_mute
    return ret;
 }
 
-#if defined(VGO_linux) || defined(VGO_darwin)
+#if defined(VGO_linux) || defined(VGO_darwin) || defined(VGO_netbsd)
    PTH_FUNC(int, pthreadZumutexZuunlock, // pthread_mutex_unlock
             pthread_mutex_t *mutex) {
       return mutex_unlock_WRK(mutex);
@@ -1234,6 +1245,11 @@ static int pthread_cond_wait_WRK(pthread
                  pthread_cond_t* cond, pthread_mutex_t* mutex) {
       return pthread_cond_wait_WRK(cond, mutex);
    }
+#elif defined(VGO_netbsd)
+   PTH_FUNC(int, pthreadZucondZuwait, // pthread_cond_wait
+                 pthread_cond_t* cond, pthread_mutex_t* mutex) {
+      return pthread_cond_wait_WRK(cond, mutex);
+   }
 #elif defined(VGO_solaris)
    PTH_FUNC(int, condZuwait, // cond_wait
                  pthread_cond_t *cond, pthread_mutex_t *mutex) {
@@ -1329,6 +1345,12 @@ static int pthread_cond_timedwait_WRK(pt
                  struct timespec* abstime) {
       return pthread_cond_timedwait_WRK(cond, mutex, abstime, ETIMEDOUT);
    }
+#elif defined(VGO_netbsd)
+   PTH_FUNC(int, pthreadZucondZutimedwait, // pthread_cond_timedwait
+                 pthread_cond_t* cond, pthread_mutex_t* mutex,
+                 struct timespec* abstime) {
+      return pthread_cond_timedwait_WRK(cond, mutex, abstime, ETIMEDOUT);
+   }
 #elif defined(VGO_darwin)
    PTH_FUNC(int, pthreadZucondZutimedwait, // pthread_cond_timedwait
                  pthread_cond_t* cond, pthread_mutex_t* mutex, 
@@ -1404,6 +1426,11 @@ static int pthread_cond_signal_WRK(pthre
                  pthread_cond_t* cond) {
       return pthread_cond_signal_WRK(cond);
    }
+#elif defined(VGO_netbsd)
+   PTH_FUNC(int, pthreadZucondZusignal, // pthread_cond_signal
+                 pthread_cond_t* cond) {
+      return pthread_cond_signal_WRK(cond); 
+   }
 #elif defined(VGO_darwin)
    PTH_FUNC(int, pthreadZucondZusignal, // pthread_cond_signal
                  pthread_cond_t* cond) {
@@ -1465,6 +1492,11 @@ static int pthread_cond_broadcast_WRK(pt
                  pthread_cond_t* cond) {
       return pthread_cond_broadcast_WRK(cond);
    }
+#elif defined(VGO_netbsd)
+   PTH_FUNC(int, pthreadZucondZubroadcast, // pthread_cond_broadcast
+                 pthread_cond_t* cond) {
+      return pthread_cond_broadcast_WRK(cond);
+   }
 #elif defined(VGO_darwin)
    PTH_FUNC(int, pthreadZucondZubroadcast, // pthread_cond_broadcast
                  pthread_cond_t* cond) {
@@ -1521,6 +1553,11 @@ static int pthread_cond_init_WRK(pthread
 	    pthread_cond_t* cond, pthread_condattr_t* cond_attr) {
      return pthread_cond_init_WRK(cond, cond_attr);
    }
+#elif defined(VGO_netbsd)
+   PTH_FUNC(int, pthreadZucondZuinitZAZa, // pthread_cond_init@*
+            pthread_cond_t* cond, pthread_condattr_t* cond_attr) {
+     return pthread_cond_init_WRK(cond, cond_attr);
+   }
 #elif defined(VGO_darwin)
    PTH_FUNC(int, pthreadZucondZuinit, // pthread_cond_init
 	    pthread_cond_t* cond, pthread_condattr_t * cond_attr) {
@@ -1611,6 +1648,11 @@ static int pthread_cond_destroy_WRK(pthr
                  pthread_cond_t* cond) {
       return pthread_cond_destroy_WRK(cond);
    }
+#elif defined(VGO_netbsd)
+   PTH_FUNC(int, pthreadZucondZudestroy, // pthread_cond_destroy
+                 pthread_cond_t* cond) {
+      return pthread_cond_destroy_WRK(cond);
+   }
 #elif defined(VGO_darwin)
    PTH_FUNC(int, pthreadZucondZudestroy, // pthread_cond_destroy
                  pthread_cond_t* cond) {
@@ -1817,6 +1859,16 @@ static int pthread_spin_init_or_unlock_W
       /* this is never actually called */
       return pthread_spin_init_or_unlock_WRK(lock, 0/*pshared*/);
    }
+#elif defined(VGO_netbsd)
+   PTH_FUNC(int, pthreadZuspinZuinit, // pthread_spin_init
+            pthread_spinlock_t* lock, int pshared) {
+      return pthread_spin_init_or_unlock_WRK(lock, pshared);
+   } 
+   PTH_FUNC(int, pthreadZuspinZuunlockZAZa, // pthread_spin_unlock@*
+            pthread_spinlock_t* lock) {
+      /* this is never actually called */
+      return pthread_spin_init_or_unlock_WRK(lock, 0/*pshared*/);
+   }
 #elif defined(VGO_darwin)
 #elif defined(VGO_solaris)
    PTH_FUNC(int, pthreadZuspinZuinit, // pthread_spin_init
@@ -1861,7 +1913,7 @@ static int pthread_spin_destroy_WRK(pthr
    }
    return ret;
 }
-#if defined(VGO_linux)
+#if defined(VGO_linux) || defined(VGO_netbsd)
    PTH_FUNC(int, pthreadZuspinZudestroy, // pthread_spin_destroy
             pthread_spinlock_t *lock) {
       return pthread_spin_destroy_WRK(lock);
@@ -1914,7 +1966,7 @@ static int pthread_spin_lock_WRK(pthread
    }
    return ret;
 }
-#if defined(VGO_linux)
+#if defined(VGO_linux) || defined(VGO_netbsd)
    PTH_FUNC(int, pthreadZuspinZulock, // pthread_spin_lock
                  pthread_spinlock_t *lock) {
       return pthread_spin_lock_WRK(lock);
@@ -1968,7 +2020,7 @@ static int pthread_spin_trylock_WRK(pthr
    }
    return ret;
 }
-#if defined(VGO_linux)
+#if defined(VGO_linux) || defined(VGO_netbsd)
    PTH_FUNC(int, pthreadZuspinZutrylock, // pthread_spin_trylock
                  pthread_spinlock_t *lock) {
       return pthread_spin_trylock_WRK(lock);
@@ -2041,6 +2093,12 @@ static int pthread_rwlock_init_WRK(pthre
                  pthread_rwlockattr_t* attr) {
       return pthread_rwlock_init_WRK(rwl, attr);
    }
+#elif defined(VGO_netbsd)
+   PTH_FUNC(int, pthreadZurwlockZuinit, // pthread_rwlock_init
+                 pthread_rwlock_t *rwl,
+                 pthread_rwlockattr_t* attr) {
+      return pthread_rwlock_init_WRK(rwl, attr);
+   }
 #elif defined(VGO_darwin)
    PTH_FUNC(int, pthreadZurwlockZuinitZa, // pthread_rwlock_init*
                  pthread_rwlock_t *rwl,
@@ -2120,6 +2178,11 @@ static int pthread_rwlock_destroy_WRK(pt
                  pthread_rwlock_t *rwl) {
       return pthread_rwlock_destroy_WRK(rwl);
    }
+#elif defined(VGO_netbsd)
+   PTH_FUNC(int, pthreadZurwlockZudestroy, // pthread_rwlock_destroy
+                 pthread_rwlock_t *rwl) {
+      return pthread_rwlock_destroy_WRK(rwl);
+   }
 #elif defined(VGO_darwin)
    PTH_FUNC(int, pthreadZurwlockZudestroyZa, // pthread_rwlock_destroy*
                  pthread_rwlock_t *rwl) {
@@ -2174,6 +2237,11 @@ static int pthread_rwlock_wrlock_WRK(pth
                  pthread_rwlock_t* rwlock) {
       return pthread_rwlock_wrlock_WRK(rwlock);
    }
+#elif defined(VGO_netbsd)
+   PTH_FUNC(int, pthreadZurwlockZuwrlock, // pthread_rwlock_wrlock
+                 pthread_rwlock_t* rwlock) {
+      return pthread_rwlock_wrlock_WRK(rwlock);
+   }
 #elif defined(VGO_darwin)
    PTH_FUNC(int, pthreadZurwlockZuwrlockZa, // pthread_rwlock_wrlock*
                  pthread_rwlock_t* rwlock) {
@@ -2254,6 +2322,11 @@ static int pthread_rwlock_rdlock_WRK(pth
                  pthread_rwlock_t* rwlock) {
       return pthread_rwlock_rdlock_WRK(rwlock);
    }
+#elif defined(VGO_netbsd)
+   PTH_FUNC(int, pthreadZurwlockZurdlock, // pthread_rwlock_rdlock
+                 pthread_rwlock_t* rwlock) {
+      return pthread_rwlock_rdlock_WRK(rwlock);
+   }
 #elif defined(VGO_darwin)
    PTH_FUNC(int, pthreadZurwlockZurdlockZa, // pthread_rwlock_rdlock*
                  pthread_rwlock_t* rwlock) {
@@ -2340,6 +2413,11 @@ static int pthread_rwlock_trywrlock_WRK(
                  pthread_rwlock_t* rwlock) {
       return pthread_rwlock_trywrlock_WRK(rwlock);
    }
+#elif defined(VGO_netbsd)
+   PTH_FUNC(int, pthreadZurwlockZutrywrlock, // pthread_rwlock_trywrlock
+                 pthread_rwlock_t* rwlock) {
+      return pthread_rwlock_trywrlock_WRK(rwlock);
+   }
 #elif defined(VGO_darwin)
    PTH_FUNC(int, pthreadZurwlockZutrywrlockZa, // pthread_rwlock_trywrlock*
                  pthread_rwlock_t* rwlock) {
@@ -2401,6 +2479,11 @@ static int pthread_rwlock_tryrdlock_WRK(
                  pthread_rwlock_t* rwlock) {
       return pthread_rwlock_tryrdlock_WRK(rwlock);
    }
+#elif defined(VGO_netbsd)
+   PTH_FUNC(int, pthreadZurwlockZutryrdlock, // pthread_rwlock_tryrdlock
+                 pthread_rwlock_t* rwlock) { 
+      return pthread_rwlock_tryrdlock_WRK(rwlock);
+   }
 #elif defined(VGO_darwin)
    PTH_FUNC(int, pthreadZurwlockZutryrdlockZa, // pthread_rwlock_tryrdlock*
                  pthread_rwlock_t* rwlock) {
@@ -2452,6 +2535,7 @@ static int pthread_rwlock_timedrdlock_WR
    return ret;
 }
 #if defined(VGO_linux)
+#elif defined(VGO_netbsd)
 #elif defined(VGO_darwin)
 #elif defined(VGO_solaris)
    PTH_FUNC(int, pthreadZurwlockZutimedrdlock, // pthread_rwlock_timedrdlock
@@ -2506,6 +2590,7 @@ static int pthread_rwlock_timedwrlock_WR
 }
 #if defined(VGO_linux)
 #elif defined(VGO_darwin)
+#elif defined(VGO_netbsd)
 #elif defined(VGO_solaris)
    PTH_FUNC(int, pthreadZurwlockZutimedwrlock, // pthread_rwlock_timedwrlock
                  pthread_rwlock_t *rwlock,
@@ -2558,6 +2643,11 @@ static int pthread_rwlock_unlock_WRK(pth
                  pthread_rwlock_t* rwlock) {
       return pthread_rwlock_unlock_WRK(rwlock);
    }
+#elif defined(VGO_netbsd)
+   PTH_FUNC(int, pthreadZurwlockZuunlock, // pthread_rwlock_unlock
+                 pthread_rwlock_t* rwlock) {
+      return pthread_rwlock_unlock_WRK(rwlock);
+   }
 #elif defined(VGO_darwin)
    PTH_FUNC(int, pthreadZurwlockZuunlockZa, // pthread_rwlock_unlock*
                  pthread_rwlock_t* rwlock) {
@@ -2641,6 +2731,11 @@ static int sem_init_WRK(sem_t* sem, int 
                  sem_t* sem, int pshared, unsigned long value) {
       return sem_init_WRK(sem, pshared, value);
    }
+#elif defined(VGO_netbsd)
+   PTH_FUNC(int, semZuinit, // sem_init
+                 sem_t* sem, int pshared, unsigned long value) {
+      return sem_init_WRK(sem, pshared, value);
+   }
 #elif defined(VGO_darwin)
    PTH_FUNC(int, semZuinit, // sem_init
                  sem_t* sem, int pshared, unsigned long value) {
@@ -2723,6 +2818,11 @@ static int sem_destroy_WRK(sem_t* sem)
                  sem_t* sem) {
       return sem_destroy_WRK(sem);
    }
+#elif defined(VGO_netbsd)
+   PTH_FUNC(int, semZudestroy,  // sem_destroy
+                 sem_t* sem) {
+      return sem_destroy_WRK(sem);
+   }
 #elif defined(VGO_darwin)
    PTH_FUNC(int, semZudestroy,  // sem_destroy
                  sem_t* sem) {
@@ -2785,6 +2885,10 @@ static int sem_wait_WRK(sem_t* sem)
    PTH_FUNC(int, semZuwaitZAZa, sem_t* sem) { /* sem_wait@* */
       return sem_wait_WRK(sem);
    }
+#elif defined(VGO_netbsd)
+   PTH_FUNC(int, semZuwait, sem_t* sem) { /* sem_wait */
+      return sem_wait_WRK(sem);
+   }
 #elif defined(VGO_darwin)
    PTH_FUNC(int, semZuwait, sem_t* sem) { /* sem_wait */
       return sem_wait_WRK(sem);
@@ -2846,6 +2950,10 @@ static int sem_post_WRK(sem_t* sem)
    PTH_FUNC(int, semZupostZAZa, sem_t* sem) { /* sem_post@* */
       return sem_post_WRK(sem);
    }
+#elif defined(VGO_netbsd)
+   PTH_FUNC(int, semZupost, sem_t* sem) { /* sem_post */
+      return sem_post_WRK(sem);
+   }
 #elif defined(VGO_darwin)
    PTH_FUNC(int, semZupost, sem_t* sem) { /* sem_post */
       return sem_post_WRK(sem);
