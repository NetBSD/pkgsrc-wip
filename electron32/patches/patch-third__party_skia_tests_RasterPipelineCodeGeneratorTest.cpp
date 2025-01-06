$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/skia/tests/RasterPipelineCodeGeneratorTest.cpp.orig	2024-10-18 12:42:57.290823500 +0000
+++ third_party/skia/tests/RasterPipelineCodeGeneratorTest.cpp
@@ -22,6 +22,7 @@
 
 #include <memory>
 #include <optional>
+#include <sstream>
 #include <string>
 
 //#define DUMP_PROGRAMS 1
@@ -250,3 +251,80 @@ DEF_TEST(SkSLRasterPipelineCodeGenerator
          /*startingColor=*/SkColor4f{0.0, 0.0, 0.0, 0.0},
          /*expectedResult=*/SkColor4f{0.0, 1.0, 0.0, 1.0});
 }
+
+DEF_TEST(SkSLRasterPipelineSlotOverflow_355465305, r) {
+    constexpr int kStructMembers1 = 6200;
+    constexpr int kStructMembers2 = 433;
+    std::stringstream str;
+    str << "struct M { float4x4 m";
+    for (int i = 1; i < kStructMembers1; ++i) {
+        str << ",m" << i;
+    }
+    str << ";};";
+    str << "struct M2 { float4x4 m";
+    for (int i = 1; i < kStructMembers2; ++i) {
+        str << ",m" << i;
+    }
+    str << ";};";
+    str << "M f() { M m; return m; }";
+    constexpr int kConstMembers = 40;
+    str << "struct T { float4x4 m0";
+    for (int i = 1; i < kConstMembers; ++i) {
+        str << ",m" << i;
+    }
+    str << ";};";
+    str << "const T K = T(";
+    for (int i = 0; i < kConstMembers; ++i) {
+        if (i > 0) {
+            str << ",";
+        }
+        str << "mat4x4(1337)";
+    }
+    str << ");";
+    str << "half4 main(half4 color) {";
+    str << "float4x4 a = M2(";
+    for (int j = 0; j < kStructMembers2; ++j) {
+        if (j > 0) {
+            str << ",";
+        }
+        const int numAddOps = (j == kStructMembers1 - 1) ? 23 : 25;
+        for (int i = 0; i < numAddOps; ++i) {
+            if (i > 0) {
+                str << "+";
+            }
+            str << "f().m";
+        }
+    }
+    str << ").m;";
+    str << "return half4(a[0]+(K.m0+K.m1+K.m2+K.m3)[0]);";
+    str << "}";
+    std::string src = str.str();
+
+    SkSL::Compiler compiler;
+    std::unique_ptr<SkSL::Program> program =
+            compiler.convertProgram(SkSL::ProgramKind::kRuntimeColorFilter, src, {});
+    if (!program) {
+        ERRORF(r, "Unexpected error compiling %s\n%s", src.c_str(), compiler.errorText().c_str());
+        return;
+    }
+    const SkSL::FunctionDeclaration* main = program->getFunction("main");
+    if (!main) {
+        ERRORF(r, "Program must have a 'main' function");
+        return;
+    }
+    SkArenaAlloc alloc(1000);
+    SkRasterPipeline pipeline(&alloc);
+    pipeline.appendConstantColor(&alloc, SkColors::kWhite);
+    std::unique_ptr<SkSL::RP::Program> rasterProg =
+            SkSL::MakeRasterPipelineProgram(*program, *main->definition());
+    // Ideally, this program would fail in the front-end, because of the number of slots needed
+    // for expression evaluation. For now, it succeeds (but then fails in appendStages).
+    if (!rasterProg) {
+        ERRORF(r, "MakeRasterPipelineProgram failed");
+        return;
+    }
+
+    // Append the SkSL program to the raster pipeline.
+    bool success = rasterProg->appendStages(&pipeline, &alloc, /*callbacks=*/nullptr, {});
+    REPORTER_ASSERT(r, !success, "appendStages should fail for very large program");
+}
