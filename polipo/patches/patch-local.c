$NetBSD: patch-local.c,v 1.1 2012/02/18 20:20:37 ishit Exp $

fix security issue (CVE-2011-3596).
patch from Tor Project git repository.
cf.https://bugzilla.redhat.com/show_bug.cgi?id=CVE-2011-3596

--- local.c.orig	2008-01-08 12:56:45.000000000 +0000
+++ local.c
@@ -67,8 +67,8 @@ httpLocalRequest(ObjectPtr object, int m
                                   requestor, closure);
 
     if(method >= METHOD_POST) {
+        httpClientDiscardBody(requestor->connection);
         httpClientError(requestor, 405, internAtom("Method not allowed"));
-        requestor->connection->flags &= ~CONN_READER;
         return 1;
     }
 
@@ -295,11 +295,47 @@ httpSpecialRequest(ObjectPtr object, int
     return 1;
 }
 
+#define MAXBODY(c) (((c)->flags & CONN_BIGREQBUF)? bigBufferSize : CHUNK_SIZE)
+
+static void
+writeContinue(HTTPConnectionPtr client)
+{
+    static char httpContinue[] = "HTTP/1.1 100 Continue\r\n\r\n";
+
+    /* don't bother writing continue if the post is already completed */
+    if (client->reqlen - client->reqbegin < client->bodylen) {
+        do_stream(IO_WRITE, client->fd, 0, httpContinue, 25,
+                  httpErrorNofinishStreamHandler, client);
+    }
+}
+
+static int
+validateRequest(HTTPConnectionPtr client)
+{
+    ObjectPtr object = client->request->object;
+  
+    if (disableConfiguration) {
+        abortObject(object, 403, internAtom("Action not allowed"));
+    } else if (client->bodylen > MAXBODY(client)) {
+        abortObject(object, 411, internAtom("POST too large"));
+    } else if (!matchUrl("/polipo/status", object) &&
+               !matchUrl("/polipo/config", object)) {
+        abortObject(object, 404, internAtom("Not found"));
+    } else
+        return 0;
+
+    httpClientDiscardBody(client);
+    notifyObject(object);
+    
+    return -1;
+}
+
 int 
 httpSpecialSideRequest(ObjectPtr object, int method, int from, int to,
                        HTTPRequestPtr requestor, void *closure)
 {
     HTTPConnectionPtr client = requestor->connection;
+    int waiting = 0;
 
     assert(client->request == requestor);
 
@@ -309,13 +345,24 @@ httpSpecialSideRequest(ObjectPtr object,
         return 1;
     }
 
+    if (requestor->flags & REQUEST_WAIT_CONTINUE) {
+        requestor->flags &= ~REQUEST_WAIT_CONTINUE;
+        waiting = 1;
+    }
+
+    if (validateRequest(client) < 0)
+        return 1;
+
+    if (waiting)
+        writeContinue(client);
+
     return httpSpecialDoSide(requestor);
 }
 
-int
-httpSpecialDoSide(HTTPRequestPtr requestor)
+static int
+readFinished(HTTPConnectionPtr client)
 {
-    HTTPConnectionPtr client = requestor->connection;
+    HTTPRequestPtr request = client->request;
 
     if(client->reqlen - client->reqbegin >= client->bodylen) {
         AtomPtr data;
@@ -325,19 +372,25 @@ httpSpecialDoSide(HTTPRequestPtr request
         client->reqlen = 0;
         if(data == NULL) {
             do_log(L_ERROR, "Couldn't allocate data.\n");
-            httpClientError(requestor, 500,
+            httpClientError(request, 500,
                             internAtom("Couldn't allocate data"));
             return 1;
         }
-        httpSpecialDoSideFinish(data, requestor);
+        httpSpecialDoSideFinish(data, request);
         return 1;
     }
 
-    if(client->reqlen - client->reqbegin >= CHUNK_SIZE) {
-        httpClientError(requestor, 500, internAtom("POST too large"));
-        return 1;
-    }
+    return 0;
+}
+
+int
+httpSpecialDoSide(HTTPRequestPtr requestor)
+{
+    HTTPConnectionPtr client = requestor->connection;
 
+    if (readFinished(client))
+        return 1;   
+ 
     if(client->reqbegin > 0 && client->reqlen > client->reqbegin) {
         memmove(client->reqbuf, client->reqbuf + client->reqbegin,
                 client->reqlen - client->reqbegin);
@@ -346,7 +399,7 @@ httpSpecialDoSide(HTTPRequestPtr request
     client->reqbegin = 0;
 
     do_stream(IO_READ | IO_NOTNOW, client->fd,
-              client->reqlen, client->reqbuf, CHUNK_SIZE,
+              client->reqlen, client->reqbuf, MAXBODY(client),
               httpSpecialClientSideHandler, client);
     return 1;
 }
@@ -358,36 +411,22 @@ httpSpecialClientSideHandler(int status,
 {
     HTTPConnectionPtr connection = srequest->data;
     HTTPRequestPtr request = connection->request;
-    int push;
 
-    if((request->object->flags & OBJECT_ABORTED) || 
-       !(request->object->flags & OBJECT_INPROGRESS)) {
-        httpClientDiscardBody(connection);
-        httpClientError(request, 503, internAtom("Post aborted"));
-        return 1;
-    }
-        
-    if(status < 0) {
-        do_log_error(L_ERROR, -status, "Reading from client");
-        if(status == -EDOGRACEFUL)
-            httpClientFinish(connection, 1);
-        else
-            httpClientFinish(connection, 2);
+    if(status) {
+        connection->flags &= ~CONN_READER;
+        if (request->chandler) {
+            unregisterConditionHandler(request->chandler);
+            request->chandler = NULL;
+        }
+        do_log(L_ERROR, "Incomplete client request.\n");
+        httpClientRawError(connection, 502,
+                           internAtom("Incomplete client request"), 1);
         return 1;
     }
 
-    push = MIN(srequest->offset - connection->reqlen,
-               connection->bodylen - connection->reqoffset);
-    if(push > 0) {
-        connection->reqlen += push;
-        httpSpecialDoSide(request);
-    }
+    connection->reqlen = srequest->offset;
 
-    do_log(L_ERROR, "Incomplete client request.\n");
-    connection->flags &= ~CONN_READER;
-    httpClientRawError(connection, 502,
-                       internAtom("Incomplete client request"), 1);
-    return 1;
+    return readFinished(connection);
 }
 
 int
@@ -480,7 +519,7 @@ httpSpecialDoSideFinish(AtomPtr data, HT
         object->flags &= ~OBJECT_INITIAL;
         object->length = 0;
     } else {
-        abortObject(object, 405, internAtom("Method not allowed"));
+        abortObject(object, 404, internAtom("Not found"));
     }
 
  out:
