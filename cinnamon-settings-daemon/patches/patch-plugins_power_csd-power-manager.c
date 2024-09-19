$NetBSD$

Disable systemd-logind suspend inhibition

--- plugins/power/csd-power-manager.c.orig	2018-05-16 17:41:09.000000000 +0000
+++ plugins/power/csd-power-manager.c
@@ -3938,6 +3938,7 @@ inhibit_suspend_done (GObject      *sour
  * PrepareToSleep signal, which gives us a chance to lock the screen
  * and do some other preparations.
  */
+#ifndef __NetBSD__
 static void
 inhibit_suspend (CsdPowerManager *manager)
 {
@@ -3961,6 +3962,7 @@ inhibit_suspend (CsdPowerManager *manage
                                              inhibit_suspend_done,
                                              manager);
 }
+#endif
 
 static void
 uninhibit_suspend (CsdPowerManager *manager)
@@ -4024,7 +4026,9 @@ handle_resume_actions (CsdPowerManager *
         }
 
         /* set up the delay again */
+#ifndef __NetBSD__
         inhibit_suspend (manager);
+#endif
 }
 
 #if ! UP_CHECK_VERSION(0,99,0)
@@ -4145,7 +4149,9 @@ csd_power_manager_start (CsdPowerManager
                           manager);
 
         /* Set up a delay inhibitor to be informed about suspend attempts */
+#ifndef __NetBSD__
         inhibit_suspend (manager);
+#endif
 
         /* track the active session */
         manager->priv->session = cinnamon_settings_session_new ();
