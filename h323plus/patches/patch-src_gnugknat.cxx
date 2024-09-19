$NetBSD: patch-src_gnugknat.cxx,v 1.1 2013/07/17 12:52:45 obache Exp $

--- src/gnugknat.cxx.orig	2008-02-01 09:34:20.000000000 +0000
+++ src/gnugknat.cxx
@@ -579,6 +579,20 @@ BOOL PNatMethod_GnuGk::OpenSocket(PUDPSo
   return FALSE;
 }
 
+BOOL PNatMethod_GnuGk::GetServerAddress(PIPSocket::Address&, WORD&) const
+            { return FALSE; }
+
+BOOL PNatMethod_GnuGk::GetInterfaceAddress(PIPSocket::Address&) const
+            { return FALSE; }
+
+BOOL PNatMethod_GnuGk::IsAvailable(const PIPSocket::Address&)
+            { return FALSE; }
+
+PNatMethod::RTPSupportTypes PNatMethod_GnuGk::GetRTPSupport(PBoolean)
+            { return PNatMethod::RTPUnknown; }
+
+BOOL PNatMethod_GnuGk::CreateSocket(PUDPSocket*&, const PIPSocket::Address&, WORD)            { return FALSE; }
+
 /////////////////////////////////////////////////////////////////////////////////////////////
 
 GNUGKUDPSocket::GNUGKUDPSocket()
