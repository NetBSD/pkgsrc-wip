$NetBSD$

--- glib/gthread-posix.c.orig	2018-01-18 18:56:06.000000000 +0000
+++ glib/gthread-posix.c
@@ -716,6 +716,7 @@ g_cond_impl_new (void)
 #elif defined (HAVE_PTHREAD_CONDATTR_SETCLOCK) && defined (CLOCK_MONOTONIC)
   if G_UNLIKELY ((status = pthread_condattr_setclock (&attr, CLOCK_MONOTONIC)) != 0)
     g_thread_abort (status, "pthread_condattr_setclock");
+#elif defined (CLOCK_MONOTONIC)
 #else
 #error Cannot support GCond on your platform.
 #endif
@@ -970,6 +971,21 @@ g_cond_wait_until (GCond  *cond,
     if ((status = pthread_cond_timedwait (g_cond_get_impl (cond), g_mutex_get_impl (mutex), &ts)) == 0)
       return TRUE;
   }
+#elif defined (CLOCK_MONOTONIC)
+  {
+    gint64 monotonic_now = g_get_monotonic_time ();
+    gint64 real_end_time;
+
+    if (end_time <= monotonic_now)
+      return FALSE;
+
+    real_end_time = g_get_real_time () + (end_time - monotonic_now);
+
+    ts.tv_sec = real_end_time / 1000000;
+    ts.tv_nsec = (real_end_time % 1000000) * 1000;
+    if ((status = pthread_cond_timedwait (g_cond_get_impl (cond), g_mutex_get_impl (mutex), &ts)) == 0)
+      return TRUE;
+  }
 #else
 #error Cannot support GCond on your platform.
 #endif
@@ -1659,6 +1675,82 @@ g_thread_lifetime_beacon_check (GThreadB
   return status == -1 && errno == ESRCH;
 }
 
+#elif defined(__NetBSD__)
+
+#include <sys/types.h>
+#include <sys/sysctl.h>
+#include <lwp.h>
+
+struct _GThreadBeacon
+{
+  pid_t process_id;
+  lwpid_t thread_id;
+};
+
+GThreadBeacon *
+g_thread_lifetime_beacon_new (void)
+{
+  GThreadBeacon *beacon;
+
+  beacon = g_slice_new (GThreadBeacon);
+  beacon->process_id = getpid ();
+  beacon->thread_id = _lwp_self();
+
+  return beacon;
+}
+
+void
+g_thread_lifetime_beacon_free (GThreadBeacon *beacon)
+{
+  g_slice_free (GThreadBeacon, beacon);
+}
+
+gboolean
+g_thread_lifetime_beacon_check (GThreadBeacon *beacon)
+{
+  int st;
+  int mib[5];
+  size_t size, nlwps, i;
+  struct kinfo_lwp *kl;
+  int found = 0;
+
+  mib[0] = CTL_KERN;
+  mib[1] = KERN_LWP;
+  mib[2] = beacon->process_id;
+  mib[3] = sizeof(struct kinfo_lwp);
+  mib[4] = 0;
+
+  st = sysctl(mib, 5, NULL, &size, NULL, 0);
+  if (st == -1 || size == 0)
+    return FALSE;
+
+  mib[4] = size / sizeof(struct kinfo_lwp);
+
+  kl = (struct kinfo_lwp *)malloc(mib[4]);
+  if (!kl)
+    return FALSE;
+
+  st = sysctl(mib, 5, kl, &size, NULL, 0);
+  if (st == -1 || size == 0)
+    goto fail;
+
+  nlwps = size / sizeof(struct kinfo_lwp);
+  for (i = 0; i < nlwps; i++) {
+    if ((kl + i)->l_lid == beacon->thread_id) {
+      found = 1;
+      break;
+    }
+  }
+
+  free(kl);
+
+  return found ? TRUE : FALSE;
+
+fail:
+  free(kl);
+  return TRUE;
+}
+
 #else
 #error Please implement for your OS
 #endif
