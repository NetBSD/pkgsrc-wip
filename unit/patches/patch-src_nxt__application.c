--- src/nxt_application.c.orig	2020-08-08 16:28:19.771768606 -0400
+++ src/nxt_application.c	2020-08-08 16:33:14.070404193 -0400
@@ -474,20 +474,24 @@
 static nxt_int_t
 nxt_app_prefork(nxt_task_t *task, nxt_process_t *process, nxt_mp_t *mp)
 {
-    nxt_int_t              cap_setid, cap_chroot;
+    nxt_int_t              cap_setid;
     nxt_int_t              ret;
     nxt_runtime_t          *rt;
     nxt_common_app_conf_t  *app_conf;
-    nxt_app_lang_module_t  *lang;
 
     rt = task->thread->runtime;
     app_conf = process->data.app;
     cap_setid = rt->capabilities.setid;
-    cap_chroot = rt->capabilities.chroot;
 
+#if (NXT_HAVE_ISOLATION_ROOTFS)
+    nxt_int_t               cap_chroot;
+    nxt_app_lang_module_t  *lang;
+
+    cap_chroot = rt->capabilities.chroot;
     lang = nxt_app_lang_module(rt, &app_conf->type);
 
     nxt_assert(lang != NULL);
+#endif
 
     if (app_conf->isolation != NULL) {
         ret = nxt_app_set_isolation(task, app_conf->isolation, process);
