$NetBSD$

* Use pipewire_init:
  https://gitlab.freedesktop.org/wtaymans/pipewire/-/commit/75081f8b4d852146d4880c29da45d1f21941b8a3

--- src/pipewire.c.orig	2026-01-12 10:57:53.266590608 +0000
+++ src/pipewire.c
@@ -242,7 +242,7 @@ ensure_pipewire_is_initialized (void)
   if (is_pipewire_initialized)
     return;
 
-  pw_init (NULL, NULL);
+  pipewire_init (NULL, NULL);
 
   is_pipewire_initialized = TRUE;
 }
