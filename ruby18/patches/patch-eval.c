$NetBSD$

--- eval.c.orig	2012-06-29 12:31:25.000000000 +0000
+++ eval.c
@@ -789,7 +789,7 @@ static unsigned long frame_unique = 0;
     _frame.argc = 0;			\
     _frame.flags = 0;			\
     _frame.uniq = frame_unique++;	\
-    ruby_frame = &_frame
+    ruby_frame = (struct FRAME *)&_frame
 
 #define POP_FRAME()  			\
     ruby_current_node = _frame.node;	\
@@ -7264,6 +7264,7 @@ rb_provide(feature)
     rb_provide_feature(rb_str_new2(feature));
 }
 
+int rb_thread_join _((VALUE, double));
 static char *
 load_lock(ftptr)
     const char *ftptr;
@@ -11524,7 +11525,6 @@ static int rb_thread_join0 _((rb_thread_t, double));
 }
 
 static int rb_thread_join0 _((rb_thread_t, double));
-int rb_thread_join _((VALUE, double));
 
 static int
 rb_thread_join0(th, limit)
@@ -12272,7 +12272,9 @@ rb_thread_alloc(klass)
     return th;
 }
 
+#if defined(HAVE_SETITIMER) || defined(_THREAD_SAFE)
 static int thread_init;
+#endif
 
 #if defined(POSIX_SIGNAL)
 #define CATCH_VTALRM() posix_signal(SIGVTALRM, catch_timer)
