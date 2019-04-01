$NetBSD$

--- coregrind/m_addrinfo.c.orig	2018-05-05 07:42:22.000000000 +0000
+++ coregrind/m_addrinfo.c
@@ -650,6 +650,8 @@ static void pp_addrinfo_WRK ( Addr a, co
       default:
          VG_(core_panic)("mc_pp_AddrInfo");
    }
+
+   VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
 }
 
 void VG_(pp_addrinfo) ( Addr a, const AddrInfo* ai )
@@ -659,7 +661,9 @@ void VG_(pp_addrinfo) ( Addr a, const Ad
 
 void VG_(pp_addrinfo_mc) ( Addr a, const AddrInfo* ai, Bool maybe_gcc )
 {
+   VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    pp_addrinfo_WRK (a, ai, True /*mc*/, maybe_gcc);
+   VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
 }
 
 
