$NetBSD$

Stolen from https://github.com/nrTQgc/druntime/tree/netbsd

--- runtime/druntime/src/core/thread.d.orig	2018-08-23 23:29:55.000000000 +0000
+++ runtime/druntime/src/core/thread.d
@@ -588,7 +588,6 @@ class Thread
     // General Actions
     ///////////////////////////////////////////////////////////////////////////
 
-
     /**
      * Starts the thread and invokes the function or delegate passed upon
      * construction.
@@ -886,6 +885,12 @@ class Thread
      */
     __gshared const int PRIORITY_DEFAULT;
 
+     version(NetBSD)
+     {
+        //NetBSD does not support priority for default policy
+        // and it is not possible change policy without root access
+        int fakePriority = int.max;
+     }
 
     /**
      * Gets the scheduling priority for the associated thread.
@@ -902,6 +907,10 @@ class Thread
         {
             return GetThreadPriority( m_hndl );
         }
+        else version(NetBSD)
+        {
+           return fakePriority==int.max? PRIORITY_DEFAULT : fakePriority;
+        }
         else version( Posix )
         {
             int         policy;
@@ -966,6 +975,10 @@ class Thread
             if (priocntl(idtype_t.P_LWPID, P_MYID, PC_SETPARMS, &pcparm) == -1)
                 throw new ThreadException( "Unable to set scheduling class" );
         }
+        else version(NetBSD)
+        {
+           fakePriority = val;
+        }
         else version( Posix )
         {
             static if(__traits(compiles, pthread_setschedprio))
@@ -991,6 +1004,7 @@ class Thread
                     throw new ThreadException("Unable to set thread priority");
                 }
                 param.sched_priority = val;
+
                 if (auto err = pthread_setschedparam(m_addr, policy, &param))
                 {
                     // ignore error if thread is not running => Bugzilla 8960
@@ -3213,6 +3227,7 @@ nothrow:
     version (CRuntime_Glibc) int pthread_getattr_np(pthread_t thread, pthread_attr_t* attr);
     version (FreeBSD) int pthread_attr_get_np(pthread_t thread, pthread_attr_t* attr);
     version (DragonFlyBSD) int pthread_attr_get_np(pthread_t thread, pthread_attr_t* attr);
+    version (NetBSD) int pthread_attr_get_np(pthread_t thread, pthread_attr_t* attr);
     version (Solaris) int thr_stksegment(stack_t* stk);
     version (CRuntime_Bionic) int pthread_getattr_np(pthread_t thid, pthread_attr_t* attr);
 }
@@ -3351,6 +3366,17 @@ private void* getStackBottom() nothrow
         pthread_attr_destroy(&attr);
         return addr + size;
     }
+    else version (NetBSD)
+    {
+        pthread_attr_t attr;
+        void* addr; size_t size;
+
+        pthread_attr_init(&attr);
+        pthread_attr_get_np(pthread_self(), &attr);
+        pthread_attr_getstack(&attr, &addr, &size);
+        pthread_attr_destroy(&attr);
+        return addr + size;
+    }
     else version (Solaris)
     {
         stack_t stk;
@@ -3940,6 +3966,14 @@ version( LDC )
         version( ARM ) version = CheckFiberMigration;
         version( AArch64 ) version = CheckFiberMigration;
     }
+
+    version ( NetBSD )
+    {
+        version( ARM ) version = CheckFiberMigration;
+        version( AArch64 ) version = CheckFiberMigration;
+        version( X86 ) version = CheckFiberMigration;
+        version( x86_64 ) version = CHeckFiberMigration;
+    }
 }
 
 // Fiber support for SjLj style exceptions
