$NetBSD: patch-revcvs.c,v 1.1 2015/02/28 10:29:18 ryo-on Exp $

* For non-PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP platforms.

--- revcvs.c.orig	2014-12-17 13:38:22.000000000 +0000
+++ revcvs.c
@@ -77,7 +77,12 @@ typedef struct _dir_bucket {
 
 static dir_bucket *dir_buckets[DIR_BUCKETS];
 #ifdef THREADS
+#if defined(PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP)
 static pthread_mutex_t dir_bucket_mutex = PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP;
+#else
+pthread_mutexattr_t dbattr;
+pthread_mutex_t _dbmutex;
+#endif /* PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP */
 #endif /* THREADS */
 
 
@@ -100,12 +105,22 @@ atom_dir(const char* dirname)
     }
 #ifdef THREADS
     if (threads > 1)
+#if defined(PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP)
 	pthread_mutex_lock(&dir_bucket_mutex);
+#else
+	pthread_mutexattr_init(&dbattr);
+	pthread_mutexattr_settype(&dbattr, PTHREAD_MUTEX_RECURSIVE);
+	pthread_mutex_init(&_dbmutex, &dbattr);
+#endif /* PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP */
 #endif /* THREADS */
     if ((b = *head)) {
 #ifdef THREADS
 	if (threads > 1)
+#if defined(PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP)
 	    pthread_mutex_unlock(&dir_bucket_mutex);
+#else
+	    pthread_mutexattr_destroy(&dbattr);
+#endif /* PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP */
 #endif /* THREADS */
 	goto collision;
     }
@@ -120,7 +135,11 @@ atom_dir(const char* dirname)
 	b->dir.parent = NULL;
 #ifdef THREADS
     if (threads > 1)
+#if defined(PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP)
 	pthread_mutex_unlock(&dir_bucket_mutex);
+#else
+	pthread_mutexattr_destroy(&dbattr);
+#endif /* PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP */
 #endif /* THREADS */
     return &(b->dir);
 }
