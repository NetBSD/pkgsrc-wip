$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/skia/src/gpu/ganesh/ops/AAHairLinePathRenderer.cpp.orig	2024-10-18 12:42:56.942844400 +0000
+++ third_party/skia/src/gpu/ganesh/ops/AAHairLinePathRenderer.cpp
@@ -10,6 +10,7 @@
 #include "include/core/SkPoint3.h"
 #include "include/private/base/SkFloatingPoint.h"
 #include "include/private/base/SkTemplates.h"
+#include "src/base/SkSafeMath.h"
 #include "src/core/SkGeometry.h"
 #include "src/core/SkMatrixPriv.h"
 #include "src/core/SkPointPriv.h"
@@ -1179,16 +1180,28 @@ void AAHairlineOp::onPrepareDraws(GrMesh
 
     int instanceCount = fPaths.size();
     bool convertConicsToQuads = !target->caps().shaderCaps()->fFloatIs32Bits;
-    for (int i = 0; i < instanceCount; i++) {
+    SkSafeMath safeMath;
+    for (int i = 0; i < instanceCount && safeMath.ok(); i++) {
         const PathData& args = fPaths[i];
-        quadCount += gather_lines_and_quads(args.fPath, args.fViewMatrix, args.fDevClipBounds,
-                                            args.fCapLength, convertConicsToQuads, &lines, &quads,
-                                            &conics, &qSubdivs, &cWeights);
+        quadCount = safeMath.addInt(quadCount,
+                                    gather_lines_and_quads(args.fPath,
+                                                           args.fViewMatrix,
+                                                           args.fDevClipBounds,
+                                                           args.fCapLength,
+                                                           convertConicsToQuads,
+                                                           &lines,
+                                                           &quads,
+                                                           &conics,
+                                                           &qSubdivs,
+                                                           &cWeights));
     }
 
     int lineCount = lines.size() / 2;
     int conicCount = conics.size() / 3;
-    int quadAndConicCount = conicCount + quadCount;
+    int quadAndConicCount = safeMath.addInt(conicCount, quadCount);
+    if (!safeMath.ok()) {
+        return;
+    }
 
     static constexpr int kMaxLines = SK_MaxS32 / kLineSegNumVertices;
     static constexpr int kMaxQuadsAndConics = SK_MaxS32 / kQuadNumVertices;
