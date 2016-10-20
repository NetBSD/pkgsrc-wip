$NetBSD$

--- src/serialize.h.orig	2015-07-27 20:55:24.000000000 +0000
+++ src/serialize.h
@@ -814,18 +814,6 @@ public:
     iterator insert(iterator it, const char& x=char()) { return vch.insert(it, x); }
     void insert(iterator it, size_type n, const char& x) { vch.insert(it, n, x); }
 
-    void insert(iterator it, const_iterator first, const_iterator last)
-    {
-        if (it == vch.begin() + nReadPos && last - first <= nReadPos)
-        {
-            // special case for inserting at the front when there's room
-            nReadPos -= (last - first);
-            memcpy(&vch[nReadPos], &first[0], last - first);
-        }
-        else
-            vch.insert(it, first, last);
-    }
-
     void insert(iterator it, std::vector<char>::const_iterator first, std::vector<char>::const_iterator last)
     {
         if (it == vch.begin() + nReadPos && last - first <= nReadPos)
