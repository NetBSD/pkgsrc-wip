$NetBSD: patch-src_libs_zbxsysinfo_netbsd_diskspace.c,v 1.1 2015/08/20 11:43:12 heidnes Exp $

Fix an obvious error in VFS_FS_SIZE; don't always
return SYSINFO_RET_FAIL(!), but instead return the
return value of the helper function we ended up calling.

--- src/libs/zbxsysinfo/netbsd/diskspace.c.orig	2015-02-23 12:28:14.000000000 +0000
+++ src/libs/zbxsysinfo/netbsd/diskspace.c
@@ -183,7 +183,7 @@ int	VFS_FS_SIZE(AGENT_REQUEST *request, 
 		return SYSINFO_RET_FAIL;
 	}
 
-	return SYSINFO_RET_FAIL;
+	return ret;
 }
 
 int	VFS_FS_DISCOVERY(AGENT_REQUEST *request, AGENT_RESULT *result)
