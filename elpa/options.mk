# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.elpa

# Things do not build if your CPU or compiler setup does not
# support the instruction sets. We assume SSE3 and first-gen
# AVX to be available. Is that good?
PKG_SUPPORTED_OPTIONS=	avx2 avx512
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mavx2)
CONFIGURE_ARGS+=	--enable-avx2
.else
CONFIGURE_ARGS+=	--disable-avx2
.endif

.if !empty(PKG_OPTIONS:Mavx512)
CONFIGURE_ARGS+=	--enable-avx512
.else
CONFIGURE_ARGS+=	--disable-avx512
.endif
