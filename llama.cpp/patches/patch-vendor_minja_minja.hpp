$NetBSD$

--- vendor/minja/minja.hpp.orig	2025-09-28 09:41:48.334745421 +0000
+++ vendor/minja/minja.hpp
@@ -1571,7 +1571,7 @@ public:
             vargs.expectArgs("title method", {0, 0}, {0, 0});
             auto res = str;
             for (size_t i = 0, n = res.size(); i < n; ++i) {
-              if (i == 0 || std::isspace(res[i - 1])) res[i] = std::toupper(res[i]);
+              if (i == 0 || std::isspace(static_cast<unsigned char>(res[i - 1]))) res[i] = std::toupper(res[i]);
               else res[i] = std::tolower(res[i]);
             }
             return res;
@@ -1662,7 +1662,7 @@ private:
 
     bool consumeSpaces(SpaceHandling space_handling = SpaceHandling::Strip) {
       if (space_handling == SpaceHandling::Strip) {
-        while (it != end && std::isspace(*it)) ++it;
+        while (it != end && std::isspace(static_cast<unsigned char>(*it))) ++it;
       }
       return true;
     }
