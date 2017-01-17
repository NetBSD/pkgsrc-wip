$NetBSD$

From freebsd-base-ports
https://github.com/FreeBSDDesktop/freebsd-ports-graphics/tree/xserver-mesa-next-udev

--- src/gallium/state_trackers/clover/llvm/metadata.hpp.orig	2016-11-10 22:05:17.000000000 +0000
+++ src/gallium/state_trackers/clover/llvm/metadata.hpp
@@ -42,7 +42,11 @@ namespace clover {
          get_kernel_nodes(const ::llvm::Module &mod) {
             if (const ::llvm::NamedMDNode *n =
                    mod.getNamedMetadata("opencl.kernels"))
+#if defined(__FreeBSD__)
+               return { n->getOperand(0), n->getOperand(n->getNumOperands()) };
+#else
                return { n->op_begin(), n->op_end() };
+#endif
             else
                return {};
          }
