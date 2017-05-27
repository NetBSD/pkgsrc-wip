$NetBSD$

--- util/systemd.c.orig	2017-04-25 12:42:53.000000000 +0000
+++ util/systemd.c
@@ -60,8 +60,8 @@ unsigned int check_socket_activation(voi
              * and we should exit.
              */
             error_report("Socket activation failed: "
-                         "invalid file descriptor fd = %d: %m",
-                         fd);
+                         "invalid file descriptor fd = %d: %s",
+                         fd, strerror(errno));
             exit(EXIT_FAILURE);
         }
     }
