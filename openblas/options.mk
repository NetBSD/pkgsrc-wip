# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.openblas
# Choose dynamic target/processor choice at runtime or
# fixed build with build host CPU.
PKG_SUPPORTED_OPTIONS=	dynamic-arch
PKG_SUGGESTED_OPTIONS=	dynamic-arch

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdynamic-arch)
MAKE_FLAGS+=	DYNAMIC_ARCH=1
.else
MAKE_FLAGS+=	DYNAMIC_ARCH=0
.endif

# Other options create variants of the library, not
# configurations of one. Especially INTERFACE64, which
# changes the API!
