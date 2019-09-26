$NetBSD$

pick from https://sourceforge.net/p/xplanet/code/209/
Add 2017 leap second

Upstream maintainer recommended to build from svn. The latest
release is rather old, so we pick a couple of commits required
for functionality on top of this release.

--- src/xpUtil.cpp~
+++ src/xpUtil.cpp
@@ -434,6 +434,7 @@ deltaETpost1972(const double jd)
     if (jd >= toJulian(2009, 1, 1, 0, 0, 0)) delta_at++; // 34
     if (jd >= toJulian(2012, 7, 1, 0, 0, 0)) delta_at++; // 35
     if (jd >= toJulian(2015, 7, 1, 0, 0, 0)) delta_at++; // 36
+    if (jd >= toJulian(2017, 1, 1, 0, 0, 0)) delta_at++; // 37
 
     const double J2000 = toJulian(2000, 1, 1, 12, 0, 0);
     const double m = m0 + m1 * (jd - J2000) * 86400;
