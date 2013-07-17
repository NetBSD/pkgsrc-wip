$NetBSD: patch-src_h323ep.cxx,v 1.1 2013/07/17 12:52:45 obache Exp $

--- src/h323ep.cxx.orig	2008-02-10 23:11:33.000000000 +0000
+++ src/h323ep.cxx
@@ -3570,8 +3570,8 @@ void H323EndPoint::InternalTranslateTCPA
   PIPSocket::Address addr;
   if (
        stun != NULL && !disableSTUN && (
-        (stun->IsSupportingRTP() == PSTUNClient::RTPOK) ||
-        (stun->IsSupportingRTP() == PSTUNClient::RTPIfSendMedia) 
+        (stun->GetRTPSupport() == PSTUNClient::RTPSupported) ||
+        (stun->GetRTPSupport() == PSTUNClient::RTPIfSendMedia) 
        ) && 
        localAddr.IsRFC1918() && 
        !remoteAddr.IsRFC1918() && 
