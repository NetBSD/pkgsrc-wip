$NetBSD$

--- src/external/heimdal/roken/roken-common.h.orig	2018-05-07 18:33:23.000000000 +0000
+++ src/external/heimdal/roken/roken-common.h
@@ -339,9 +339,11 @@ ROKEN_LIB_FUNCTION int ROKEN_LIB_CALL
 wait_for_process_timed(pid_t, time_t (*)(void *),
 		       void *, time_t);
 
+#ifndef _KERNEL
 #define pipe_execv rk_pipe_execv
 ROKEN_LIB_FUNCTION int ROKEN_LIB_CALL
 pipe_execv(FILE**, FILE**, FILE**, const char*, ...);
+#endif
 
 #define print_version rk_print_version
 ROKEN_LIB_FUNCTION void ROKEN_LIB_CALL
@@ -365,6 +367,7 @@ hostent_find_fqdn (const struct hostent 
 ROKEN_LIB_FUNCTION void ROKEN_LIB_CALL
 esetenv(const char *, const char *, int);
 
+struct sockaddr;
 #define socket_set_address_and_port rk_socket_set_address_and_port
 ROKEN_LIB_FUNCTION void ROKEN_LIB_CALL
 socket_set_address_and_port (struct sockaddr *, const void *, int);
@@ -489,11 +492,13 @@ rk_xfree (void *);
 ROKEN_LIB_FUNCTION void ROKEN_LIB_CALL
 rk_cloexec(int);
 
+#ifndef _KERNEL
 ROKEN_LIB_FUNCTION void ROKEN_LIB_CALL
 rk_cloexec_file(FILE *);
 
 ROKEN_LIB_FUNCTION void ROKEN_LIB_CALL
 rk_cloexec_dir(DIR *);
+#endif
 
 ROKEN_LIB_FUNCTION int ROKEN_LIB_CALL
 ct_memcmp(const void *, const void *, size_t);
