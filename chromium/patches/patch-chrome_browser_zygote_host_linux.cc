$NetBSD: patch-chrome_browser_zygote_host_linux.cc,v 1.1 2011/03/28 10:14:50 rxg Exp $

--- chrome/browser/zygote_host_linux.cc.orig	2010-10-15 08:03:57.000000000 +0000
+++ chrome/browser/zygote_host_linux.cc
@@ -75,7 +75,12 @@ void ZygoteHost::Init(const std::string&
   cmd_line.AppendSwitchASCII(switches::kProcessType, switches::kZygoteProcess);
 
   int fds[2];
+#if defined(OS_FREEBSD) || defined(OS_NETBSD)
+  if (socketpair(PF_UNIX, SOCK_SEQPACKET, 0, fds) != 0)
+    CHECK(socketpair(PF_UNIX, SOCK_DGRAM, 0, fds) == 0);
+#else
   CHECK(socketpair(PF_UNIX, SOCK_SEQPACKET, 0, fds) == 0);
+#endif
   base::file_handle_mapping_vector fds_to_map;
   fds_to_map.push_back(std::make_pair(fds[1], 3));
 
