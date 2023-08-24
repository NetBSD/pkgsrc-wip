$NetBSD$

Avoid trying to include <alloca.h> on NetBSD.

--- config/make-system-wrappers.py.orig	2023-08-14 18:19:44.000000000 +0000
+++ config/make-system-wrappers.py
@@ -26,6 +26,10 @@ def gen_wrappers(unused, outdir, *header
                 # This was fixed in Wayland 1.12, but for versions earlier than
                 # that, we work around that by force-including math.h first.
                 includes = "#include <math.h>\n" + includes
+            elif header == "alloca.h":
+                # <alloca.h> is apparently a Linuxism, and is at least
+                # not present on NetBSD, so avoid this there
+                includes = "#ifndef __NetBSD__\n" + includes + "\n#endif\n"
             elif header == "wayland-client.h":
                 # The system wayland-client.h uses quote includes for
                 # wayland-util.h, which means wayland-util.h is picked from the
