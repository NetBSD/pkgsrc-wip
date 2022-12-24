$NetBSD$

Properly calls std::isnan()

--- Source/WebCore/css/calc/CSSCalcOperationNode.h.orig	2022-08-31 07:59:55.834516800 +0000
+++ Source/WebCore/css/calc/CSSCalcOperationNode.h
@@ -132,7 +132,7 @@ private:
     
     static double convertToTopLevelValue(double value)
     {
-        if (isnan(value))
+        if (std::isnan(value))
             value = std::numeric_limits<double>::infinity();
         return value;
     }
