$NetBSD$

Properly calls std::is{inf,nan}()

--- Source/WebCore/css/calc/CSSCalcValue.cpp.orig	2022-08-31 07:59:55.834516800 +0000
+++ Source/WebCore/css/calc/CSSCalcValue.cpp
@@ -325,7 +325,7 @@ bool CSSCalcValue::equals(const CSSCalcV
 
 inline double CSSCalcValue::clampToPermittedRange(double value) const
 {
-    if (primitiveType() == CSSUnitType::CSS_DEG && (isnan(value) || isinf(value)))
+    if (primitiveType() == CSSUnitType::CSS_DEG && (std::isnan(value) || std::isinf(value)))
         return 0;
     return m_shouldClampToNonNegative && value < 0 ? 0 : value;
 }
