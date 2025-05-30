$NetBSD$

--- common/minja/minja.hpp.orig	2025-05-16 09:49:49.097392207 +0000
+++ common/minja/minja.hpp
@@ -1524,7 +1524,7 @@ public:
             vargs.expectArgs("title method", {0, 0}, {0, 0});
             auto res = str;
             for (size_t i = 0, n = res.size(); i < n; ++i) {
-              if (i == 0 || std::isspace(res[i - 1])) res[i] = std::toupper(res[i]);
+              if (i == 0 || std::isspace((unsigned char)(res[i - 1]))) res[i] = std::toupper(res[i]);
               else res[i] = std::tolower(res[i]);
             }
             return res;
@@ -1602,7 +1602,7 @@ private:
 
     bool consumeSpaces(SpaceHandling space_handling = SpaceHandling::Strip) {
       if (space_handling == SpaceHandling::Strip) {
-        while (it != end && std::isspace(*it)) ++it;
+        while (it != end && std::isspace((unsigned char)(*it))) ++it;
       }
       return true;
     }
