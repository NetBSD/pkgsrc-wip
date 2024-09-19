Fix NetBSD build.

--- netty_kqueue_bsdsocket.c	2020-10-13 06:30:08.000000000 +0200
+++ netty_kqueue_bsdsocket.c	2020-11-18 21:42:31.794460137 +0100
@@ -41,6 +41,7 @@
 static jfieldID fileDescriptorFieldId = NULL;
 static jmethodID peerCredentialsMethodId = NULL;
 
+#if !defined(__NetBSD__)
 // JNI Registered Methods Begin
 static jlong netty_kqueue_bsdsocket_sendFile(JNIEnv* env, jclass clazz, jint socketFd, jobject fileRegion, jlong base_off, jlong off, jlong len) {
     jobject fileChannel = (*env)->GetObjectField(env, fileRegion, fileChannelFieldId);
@@ -80,6 +81,7 @@
     }
     return res < 0 ? -err : 0;
 }
+#endif
 
 static void netty_kqueue_bsdsocket_setAcceptFilter(JNIEnv* env, jclass clazz, jint fd, jstring afName, jstring afArg) {
 #ifdef SO_ACCEPTFILTER
@@ -129,14 +131,17 @@
 #endif
 }
 
+#ifdef TCP_NOPUSH
 static void netty_kqueue_bsdsocket_setTcpNoPush(JNIEnv* env, jclass clazz, jint fd, jint optval) {
     netty_unix_socket_setOption(env, fd, IPPROTO_TCP, TCP_NOPUSH, &optval, sizeof(optval));
 }
+#endif
 
 static void netty_kqueue_bsdsocket_setSndLowAt(JNIEnv* env, jclass clazz, jint fd, jint optval) {
     netty_unix_socket_setOption(env, fd, SOL_SOCKET, SO_SNDLOWAT, &optval, sizeof(optval));
 }
 
+#ifdef TCP_NOPUSH
 static jint netty_kqueue_bsdsocket_getTcpNoPush(JNIEnv* env, jclass clazz, jint fd) {
   int optval;
   if (netty_unix_socket_getOption(env, fd, IPPROTO_TCP, TCP_NOPUSH, &optval, sizeof(optval)) == -1) {
@@ -144,6 +149,7 @@
   }
   return optval;
 }
+#endif
 
 static jint netty_kqueue_bsdsocket_getSndLowAt(JNIEnv* env, jclass clazz, jint fd) {
   int optval;
@@ -154,6 +160,22 @@
 }
 
 static jobject netty_kqueue_bsdsocket_getPeerCredentials(JNIEnv *env, jclass clazz, jint fd) {
+#ifdef __NetBSD__
+    struct unpcbid cred;
+    socklen_t credlen = sizeof(cred);
+
+    if (netty_unix_socket_getOption(env, fd, SOL_SOCKET, LOCAL_PEEREID, &cred, credlen) == -1)
+        return NULL;
+
+    pid_t pid = cred.unp_pid;
+    uid_t euid = cred.unp_euid;
+    gid_t egid = cred.unp_egid;
+
+    jintArray gids = NULL;
+    (*env)->SetIntArrayRegion(env, gids, 0, 1, (jint*) &egid);
+
+    return (*env)->NewObject(env, peerCredentialsClass, peerCredentialsMethodId, pid, euid, gids);
+#else
     struct xucred credentials;
     // It has been observed on MacOS that this method can complete successfully but not set all fields of xucred.
     credentials.cr_ngroups = 0;
@@ -184,16 +206,21 @@
 #endif
 
     return (*env)->NewObject(env, peerCredentialsClass, peerCredentialsMethodId, pid, credentials.cr_uid, gids);
+#endif
 }
 // JNI Registered Methods End
 
 // JNI Method Registration Table Begin
 static const JNINativeMethod fixed_method_table[] = {
   { "setAcceptFilter", "(ILjava/lang/String;Ljava/lang/String;)V", (void *) netty_kqueue_bsdsocket_setAcceptFilter },
+#ifdef TCP_NOPUSH
   { "setTcpNoPush", "(II)V", (void *) netty_kqueue_bsdsocket_setTcpNoPush },
+#endif
   { "setSndLowAt", "(II)V", (void *) netty_kqueue_bsdsocket_setSndLowAt },
   { "getAcceptFilter", "(I)[Ljava/lang/String;", (void *) netty_kqueue_bsdsocket_getAcceptFilter },
+#ifdef TCP_NOPUSH
   { "getTcpNoPush", "(I)I", (void *) netty_kqueue_bsdsocket_getTcpNoPush },
+#endif
   { "getSndLowAt", "(I)I", (void *) netty_kqueue_bsdsocket_getSndLowAt }
 };
 
@@ -214,6 +241,7 @@
     memcpy(dynamicMethods, fixed_method_table, sizeof(fixed_method_table));
 
     JNINativeMethod* dynamicMethod = &dynamicMethods[fixed_method_table_size];
+#if !defined(__NetBSD__)
     NETTY_PREPEND(packagePrefix, "io/netty/channel/DefaultFileRegion;JJJ)J", dynamicTypeName, error);
     NETTY_PREPEND("(IL", dynamicTypeName,  dynamicMethod->signature, error);
     dynamicMethod->name = "sendFile";
@@ -221,6 +249,7 @@
     netty_unix_util_free_dynamic_name(&dynamicTypeName);
 
     ++dynamicMethod;
+#endif
     NETTY_PREPEND(packagePrefix, "io/netty/channel/unix/PeerCredentials;", dynamicTypeName, error);
     NETTY_PREPEND("(I)L", dynamicTypeName,  dynamicMethod->signature, error);
     dynamicMethod->name = "getPeerCredentials";
