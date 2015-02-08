$NetBSD: patch-netwerk_protocol_http_Http2Session.cpp,v 1.1 2015/02/08 12:11:32 thomasklausner Exp $

https://bugzilla.mozilla.org/show_bug.cgi?id=1130822
Fix obvious alignment issues (causing crashes on some architectures).

--- netwerk/protocol/http/Http2Session.cpp.orig	2015-02-08 10:09:21.000000000 +0000
+++ netwerk/protocol/http/Http2Session.cpp
@@ -1384,8 +1384,9 @@ Http2Session::RecvPriority(Http2Session 
   if (NS_FAILED(rv))
     return rv;
 
-  uint32_t newPriorityDependency =
-    PR_ntohl(*reinterpret_cast<uint32_t *>(self->mInputFrameBuffer.get() + kFrameHeaderBytes));
+  uint32_t newPriorityDependency;
+  memcpy(&newPriorityDependency, self->mInputFrameBuffer.get() + kFrameHeaderBytes, 4);
+  newPriorityDependency = PR_ntohl(newPriorityDependency);
   bool exclusive = !!(newPriorityDependency & 0x80000000);
   newPriorityDependency &= 0x7fffffff;
   uint8_t newPriorityWeight = *(self->mInputFrameBuffer.get() + kFrameHeaderBytes + 4);
@@ -1415,8 +1416,9 @@ Http2Session::RecvRstStream(Http2Session
     RETURN_SESSION_ERROR(self, PROTOCOL_ERROR);
   }
 
-  self->mDownstreamRstReason =
-    PR_ntohl(*reinterpret_cast<uint32_t *>(self->mInputFrameBuffer.get() + kFrameHeaderBytes));
+  uint32_t tmp;
+  memcpy(&tmp, self->mInputFrameBuffer.get() + kFrameHeaderBytes, 4);
+  self->mDownstreamRstReason = PR_ntohl(tmp);
 
   LOG3(("Http2Session::RecvRstStream %p RST_STREAM Reason Code %u ID %x\n",
         self, self->mDownstreamRstReason, self->mInputFrameID));
@@ -1477,8 +1479,12 @@ Http2Session::RecvSettings(Http2Session 
     uint8_t *setting = reinterpret_cast<uint8_t *>
       (self->mInputFrameBuffer.get()) + kFrameHeaderBytes + index * 6;
 
-    uint16_t id = PR_ntohs(*reinterpret_cast<uint16_t *>(setting));
-    uint32_t value = PR_ntohl(*reinterpret_cast<uint32_t *>(setting + 2));
+    uint16_t id;
+    memcpy(&id, setting, 2);
+    id = PR_ntohs(id);
+    uint32_t value;
+    memcpy(&value, setting + 2, 4);
+    value = PR_ntohl(value);
     LOG3(("Settings ID %u, Value %u", id, value));
 
     switch (id)
@@ -1564,8 +1570,8 @@ Http2Session::RecvPushPromise(Http2Sessi
       return rv;
     }
     promiseLen = 4;
-    promisedID =
-      PR_ntohl(*reinterpret_cast<uint32_t *>(self->mInputFrameBuffer.get() + kFrameHeaderBytes + paddingControlBytes));
+    memcpy(&promisedID, self->mInputFrameBuffer.get() + kFrameHeaderBytes + paddingControlBytes, 4);
+    promisedID = PR_ntohl(promisedID);
     promisedID &= 0x7fffffff;
   }
 
@@ -1827,12 +1833,14 @@ Http2Session::RecvGoAway(Http2Session *s
   }
 
   self->mShouldGoAway = true;
-  self->mGoAwayID =
-    PR_ntohl(*reinterpret_cast<uint32_t *>(self->mInputFrameBuffer.get() + kFrameHeaderBytes));
+  uint32_t tmp;
+  memcpy(&tmp, self->mInputFrameBuffer.get() + kFrameHeaderBytes, 4);
+  self->mGoAwayID = PR_ntohl(tmp);
   self->mGoAwayID &= 0x7fffffff;
   self->mCleanShutdown = true;
-  uint32_t statusCode =
-    PR_ntohl(*reinterpret_cast<uint32_t *>(self->mInputFrameBuffer.get() + kFrameHeaderBytes + 4));
+  uint32_t statusCode;
+  memcpy(&statusCode, self->mInputFrameBuffer.get() + kFrameHeaderBytes + 4, 4);
+  statusCode = PR_ntohl(statusCode);
 
   // Find streams greater than the last-good ID and mark them for deletion
   // in the mGoAwayStreamsToRestart queue with the GoAwayEnumerator. The
@@ -1905,8 +1913,9 @@ Http2Session::RecvWindowUpdate(Http2Sess
     RETURN_SESSION_ERROR(self, PROTOCOL_ERROR);
   }
 
-  uint32_t delta =
-    PR_ntohl(*reinterpret_cast<uint32_t *>(self->mInputFrameBuffer.get() + kFrameHeaderBytes));
+  uint32_t delta;
+  memcpy(&delta, self->mInputFrameBuffer.get() + kFrameHeaderBytes, 4);
+  delta = PR_ntohl(delta);
   delta &= 0x7fffffff;
 
   LOG3(("Http2Session::RecvWindowUpdate %p len=%d Stream 0x%X.\n",
@@ -2098,10 +2107,12 @@ Http2Session::RecvAltSvc(Http2Session *s
     RETURN_SESSION_ERROR(self, FRAME_SIZE_ERROR);
   }
 
-  uint32_t maxAge =
-    PR_ntohl(*reinterpret_cast<uint32_t *>(self->mInputFrameBuffer.get() + kFrameHeaderBytes));
-  uint16_t portRoute =
-    PR_ntohs(*reinterpret_cast<uint16_t *>(self->mInputFrameBuffer.get() + kFrameHeaderBytes + 4));
+  uint32_t maxAge;
+  memcpy(&maxAge, self->mInputFrameBuffer.get() + kFrameHeaderBytes, 4);
+  maxAge = PR_ntohl(maxAge);
+  uint16_t portRoute;
+  memcpy(&portRoute, self->mInputFrameBuffer.get() + kFrameHeaderBytes + 4, 2);
+  portRoute = PR_ntohs(portRoute);
   uint8_t protoLen = self->mInputFrameBuffer.get()[kFrameHeaderBytes + 6];
   LOG3(("Http2Session::RecvAltSvc %p maxAge=%d port=%d protoLen=%d", self,
         maxAge, portRoute, protoLen));
@@ -2549,16 +2560,18 @@ Http2Session::WriteSegments(nsAHttpSegme
     }
 
     // 3 bytes of length, 1 type byte, 1 flag byte, 1 unused bit, 31 bits of ID
-    uint8_t totallyWastedByte = mInputFrameBuffer.get()[0];
-    mInputFrameDataSize = PR_ntohs(*reinterpret_cast<uint16_t *>(mInputFrameBuffer.get() + 1));
+    const uint8_t *buf = reinterpret_cast<uint8_t*>(mInputFrameBuffer.get());
+    uint8_t totallyWastedByte = buf[0];
+    mInputFrameDataSize = buf[1] | (buf[2] << 8);
     if (totallyWastedByte || (mInputFrameDataSize > kMaxFrameData)) {
       LOG3(("Got frame too large 0x%02X%04X", totallyWastedByte, mInputFrameDataSize));
       RETURN_SESSION_ERROR(this, PROTOCOL_ERROR);
     }
-    mInputFrameType = *reinterpret_cast<uint8_t *>(mInputFrameBuffer.get() + kFrameLengthBytes);
-    mInputFrameFlags = *reinterpret_cast<uint8_t *>(mInputFrameBuffer.get() + kFrameLengthBytes + kFrameTypeBytes);
-    mInputFrameID =
-      PR_ntohl(*reinterpret_cast<uint32_t *>(mInputFrameBuffer.get() + kFrameLengthBytes + kFrameTypeBytes + kFrameFlagBytes));
+    mInputFrameType = buf[kFrameLengthBytes];
+    mInputFrameFlags = buf[kFrameLengthBytes + kFrameTypeBytes];
+    uint32_t v;
+    memcpy(&v, &buf[kFrameLengthBytes + kFrameTypeBytes + kFrameFlagBytes], 4);
+    mInputFrameID = PR_ntohl(v);
     mInputFrameID &= 0x7fffffff;
     mInputFrameDataRead = 0;
 
