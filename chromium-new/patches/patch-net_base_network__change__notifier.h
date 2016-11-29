$NetBSD$

--- net/base/network_change_notifier.h.orig	2016-11-10 20:02:16.000000000 +0000
+++ net/base/network_change_notifier.h
@@ -26,7 +26,7 @@ struct NetworkInterface;
 typedef std::vector<NetworkInterface> NetworkInterfaceList;
 class URLRequest;
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 namespace internal {
 class AddressTrackerLinux;
 }
@@ -332,7 +332,7 @@ class NET_EXPORT NetworkChangeNotifier {
   // a large HOSTS file.
   static void GetDnsConfig(DnsConfig* config);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Returns the AddressTrackerLinux if present.
   static const internal::AddressTrackerLinux* GetAddressTracker();
 #endif
@@ -488,7 +488,7 @@ class NET_EXPORT NetworkChangeNotifier {
       const NetworkChangeCalculatorParams& params =
           NetworkChangeCalculatorParams());
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Returns the AddressTrackerLinux if present.
   // TODO(szym): Retrieve AddressMap from NetworkState. http://crbug.com/144212
   virtual const internal::AddressTrackerLinux*
