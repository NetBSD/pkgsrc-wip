$NetBSD$

--- src/VBox/Main/src-server/HostDnsService.h.orig	2016-03-04 19:29:40.000000000 +0000
+++ src/VBox/Main/src-server/HostDnsService.h
@@ -154,7 +154,7 @@ class HostDnsServiceWin : public HostDns
     Data *m;
 };
 # endif
-# if defined(RT_OS_SOLARIS) || defined(RT_OS_LINUX) || defined(RT_OS_OS2) || defined(RT_OS_FREEBSD)
+# if defined(RT_OS_SOLARIS) || defined(RT_OS_LINUX) || defined(RT_OS_OS2) || defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
 class HostDnsServiceResolvConf: public HostDnsMonitor
 {
   public:
@@ -215,6 +215,17 @@ class HostDnsServiceFreebsd: public Host
     }
 };
 
+#  elif defined(RT_OS_NETBSD)
+class HostDnsServiceNetbsd: public HostDnsServiceResolvConf
+{
+    public:
+    HostDnsServiceNetbsd(){}
+    ~HostDnsServiceNetbsd(){}
+    virtual HRESULT init(VirtualBox *virtualbox) {
+        return HostDnsServiceResolvConf::init(virtualbox, "/etc/resolv.conf");
+    }
+};
+
 #  elif defined(RT_OS_OS2)
 class HostDnsServiceOs2 : public HostDnsServiceResolvConf
 {
