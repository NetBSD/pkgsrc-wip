--- /dev/null	2007-04-17 15:34:28.000000000 -0400
+++ devel/boehm-gc/options.mk	2007-04-17 15:11:19.000000000 -0400
@@ -0,0 +1,11 @@
+PKG_OPTIONS_VAR=	PKG_OPTIONS.boehm-gc
+PKG_SUPPORTED_OPTIONS=	gc-redirect-malloc
+PKG_SUGGESTED_OPTIONS=  gc-redirect-malloc
+
+.include "../../mk/bsd.options.mk"
+
+.if !empty(PKG_OPTIONSMgc-redirect-malloc)
+CONFIGURE_ARGS+=        --enable-redirect-malloc
+.else
+CONFIGURE_ARGS+=        --disable-redirect-malloc
+.endif
