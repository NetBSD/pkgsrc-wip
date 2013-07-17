$NetBSD: patch-include_gnugknat.h,v 1.1 2013/07/17 12:52:44 obache Exp $

--- include/gnugknat.h.orig	2008-02-01 07:50:17.000000000 +0000
+++ include/gnugknat.h
@@ -241,8 +241,18 @@ public:
 
    static PStringList GetNatMethodName() {  return PStringList("GNUGK"); };
 
-   virtual PStringList GetName() const
-            { return GetNatMethodName(); }
+   virtual PString GetName() const
+            { return PString("GNUGK"); }
+
+   virtual BOOL GetServerAddress(PIPSocket::Address&, WORD&) const;
+
+   virtual BOOL GetInterfaceAddress(PIPSocket::Address&) const;
+
+   virtual BOOL IsAvailable(const PIPSocket::Address&);
+
+   virtual PNatMethod::RTPSupportTypes GetRTPSupport(BOOL);
+
+   virtual BOOL CreateSocket(PUDPSocket*&, const PIPSocket::Address&, WORD);
   //@}
 
 protected:
