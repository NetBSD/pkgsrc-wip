$NetBSD$

--- src/libsystemd/sd-bus/bus-socket.c.orig	2022-12-16 10:13:02.000000000 +0000
+++ src/libsystemd/sd-bus/bus-socket.c
@@ -20,6 +20,11 @@
 #include "user-util.h"
 #include "utf8.h"
 
+#if defined(__NetBSD__)
+#include <sys/un.h>
+#include <sys/socket.h>
+#endif
+
 #define SNDBUF_SIZE (8*1024*1024)
 
 static void iovec_advance(struct iovec iov[], unsigned *idx, size_t size) {
@@ -129,6 +134,9 @@ static int bus_socket_write_null_byte(sd
 #elif defined(__FreeBSD__)
 #define SOCKET_CRED_OPTION SCM_CREDS
         struct cmsgcred creds = { 0 };
+#elif defined(__NetBSD__)
+#define SOCKET_CRED_OPTION SCM_CREDS
+        struct unpcbid creds = { 0 };
 #else
 #error auth not implemented for this OS
 #endif
@@ -344,8 +352,13 @@ static int verify_external_token(sd_bus 
 
         /* We ignore the passed value if anonymous authentication is
          * on anyway. */
+#if defined(__NetBSD__)
+        if (!b->anonymous_auth && u != b->ucred.unp_euid)
+                return 0;
+#else
         if (!b->anonymous_auth && u != b->ucred.uid)
                 return 0;
+#endif
 
         return 1;
 }
@@ -537,6 +550,19 @@ static int bus_socket_process_creds(sd_b
         b->ucred.gid = creds.cmcred_gid;
         b->ucred_valid = true;
         return 0;
+#elif defined(__NetBSD__)
+        if (cmsg->cmsg_level != SOL_SOCKET ||
+            cmsg->cmsg_type != SCM_CREDS) {
+                return -ENOSYS;
+        }
+        struct unpcbid creds;
+        memcpy(&creds, CMSG_DATA(cmsg), sizeof(struct unpcbid));
+
+        b->ucred.unp_pid = creds.unp_pid;
+        b->ucred.unp_euid = creds.unp_euid;
+        b->ucred.unp_egid = creds.unp_egid;
+        b->ucred_valid = true;
+        return 0;
 #else
         return -ENOSYS;
 #endif
@@ -556,6 +582,8 @@ static int bus_socket_read_auth(sd_bus *
                 char creds[CMSG_SPACE(sizeof(struct ucred))];
 #elif defined(__FreeBSD__)
                 char creds[CMSG_SPACE(sizeof(struct cmsgcred))];
+#elif defined(__NetBSD__)
+                char creds[CMSG_SPACE(sizeof(struct unpcbid))];
 #endif
         } control;
 
@@ -617,7 +645,7 @@ static int bus_socket_read_auth(sd_bus *
                         log_debug("Got unexpected auxiliary data with level=%d and type=%d",
                                   cmsg->cmsg_level, cmsg->cmsg_type);
                 else if (r < 0)
-                        log_error_errno(r, "Could not process credentials: %m");
+                        log_error_errno(r, LOG_ERR_FMT("Could not process credentials", r));
         }
 
         r = bus_socket_auth_verify(b);
@@ -658,15 +686,15 @@ static void bus_get_peercred(sd_bus *b) 
 
         /* Get the SELinux context of the peer */
         r = getpeersec(b->input_fd, &b->label);
-        if (r < 0 && !IN_SET(r, -EOPNOTSUPP, -ENOPROTOOPT))
-                log_debug_errno(r, "Failed to determine peer security context: %m");
+        if (r < 0 && !IN_SET(r, -EOPNOTSUPP, -ENOPROTOOPT)) 
+                log_debug_errno(r, LOG_ERR_FMT("Failed to determine peer security context", r));
 
         /* Get the list of auxiliary groups of the peer */
         r = getpeergroups(b->input_fd, &b->groups);
         if (r >= 0)
                 b->n_groups = (size_t) r;
         else if (!IN_SET(r, -EOPNOTSUPP, -ENOPROTOOPT))
-                log_debug_errno(r, "Failed to determine peer's group list: %m");
+                log_debug_errno(r, LOG_ERR_FMT("Failed to determine peer's group list", r));
 }
 
 static int bus_socket_start_auth_client(sd_bus *b) {
