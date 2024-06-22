$NetBSD$

Properly calls std::{isinf,signbits}()

--- Source/WebCore/css/calc/CSSCalcOperationNode.cpp.orig	2022-08-31 07:59:55.834516800 +0000
+++ Source/WebCore/css/calc/CSSCalcOperationNode.cpp
@@ -1459,10 +1459,10 @@ double CSSCalcOperationNode::evaluateOpe
     case CalcOperator::Up: {
         if (children.size() != 2)
             return std::numeric_limits<double>::quiet_NaN();
-        if (!isinf(children[0]) && std::isinf(children[1])) {
+        if (!std::isinf(children[0]) && std::isinf(children[1])) {
             if (!children[0])
                 return children[0];
-            return signbit(children[0]) ? -0.0 : std::numeric_limits<double>::infinity();
+            return std::signbit(children[0]) ? -0.0 : std::numeric_limits<double>::infinity();
         }
         auto ret = getNearestMultiples(children[0], children[1]);
         return ret.second;
@@ -1470,10 +1470,10 @@ double CSSCalcOperationNode::evaluateOpe
     case CalcOperator::Down: {
         if (children.size() != 2)
             return std::numeric_limits<double>::quiet_NaN();
-        if (!isinf(children[0]) && isinf(children[1])) {
+        if (!std::isinf(children[0]) && std::isinf(children[1])) {
             if (!children[0])
                 return children[0];
-            return signbit(children[0]) ? -std::numeric_limits<double>::infinity() : +0.0;
+            return std::signbit(children[0]) ? -std::numeric_limits<double>::infinity() : +0.0;
         }
         auto ret = getNearestMultiples(children[0], children[1]);
         return ret.first;
@@ -1481,8 +1481,8 @@ double CSSCalcOperationNode::evaluateOpe
     case CalcOperator::Nearest: {
         if (children.size() != 2)
             return std::numeric_limits<double>::quiet_NaN();
-        if (!isinf(children[0]) && isinf(children[1]))
-            return signbit(children[0]) ? -0.0 : +0.0;
+        if (!std::isinf(children[0]) && std::isinf(children[1]))
+            return std::signbit(children[0]) ? -0.0 : +0.0;
         auto ret = getNearestMultiples(children[0], children[1]);
         auto upperB = ret.second;
         auto lowerB = ret.first;
@@ -1491,8 +1491,8 @@ double CSSCalcOperationNode::evaluateOpe
     case CalcOperator::ToZero: {
         if (children.size() != 2)
             return std::numeric_limits<double>::quiet_NaN();
-        if (!isinf(children[0]) && isinf(children[1]))
-            return signbit(children[0]) ? -0.0 : +0.0;
+        if (!std::isinf(children[0]) && std::isinf(children[1]))
+            return std::signbit(children[0]) ? -0.0 : +0.0;
         auto ret = getNearestMultiples(children[0], children[1]);
         auto upperB = ret.second;
         auto lowerB = ret.first;
