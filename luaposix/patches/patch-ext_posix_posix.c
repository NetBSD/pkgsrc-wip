$NetBSD: patch-ext_posix_posix.c,v 1.1 2013/09/14 07:56:18 ryo-on Exp $

--- ext/posix/posix.c.orig	2013-09-09 07:15:14.000000000 +0000
+++ ext/posix/posix.c
@@ -4694,8 +4694,12 @@ LUALIB_API int luaopen_posix_c (lua_Stat
 	MENTRY( AI_PASSIVE	);
 	MENTRY( AI_CANONNAME	);
 	MENTRY( AI_NUMERICHOST	);
+#if defined(HAVE_DECL_AI_V4MAPPED)
 	MENTRY( AI_V4MAPPED	);
+#endif
+#if defined(HAVE_DECL_AI_ALL)
 	MENTRY( AI_ALL		);
+#endif
 	MENTRY( AI_ADDRCONFIG	);
 
 	MENTRY( IPV6_JOIN_GROUP		);
