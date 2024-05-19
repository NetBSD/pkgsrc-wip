# $NetBSD$

PKG_OPTIONS_VAR=		PKG_OPTIONS.efl
PKG_SUPPORTED_OPTIONS=		debug g-mainloop pulseaudio clang
PKG_SUPPORTED_OPTIONS+=		tests avahi
PKG_SUGGESTED_OPTIONS=		pulseaudio

PLIST_VARS+=	tests
PLIST_VARS+=	avahi

.include "../../mk/bsd.options.mk"

# Build with debug options
.if !empty(PKG_OPTIONS:Mdebug)
MESON_ARGS+=	-Ddebug-threads=true
CFLAGS+=	-g -ggdb3
.endif

# Use glib to run the main loop in efl
# On NetBSD leads to constant CPU usage
.if !empty(PKG_OPTIONS:Mg-mainloop)
MESON_ARGS+=	-Dglib=true
MESON_ARGS+=	-Dg-mainloop=true
.include "../../devel/libuv/buildlink3.mk"
.endif

# Build with pulseaudio support
.if !empty(PKG_OPTIONS:Mpulseaudio)
.include "../../audio/pulseaudio/buildlink3.mk"
.else
MESON_ARGS+=	-Dpulseaudio=false
.endif

# Use clang to build efl
.if !empty(PKG_OPTIONS:Mclang)
.include "../../parallel/openmp/buildlink3.mk"
.endif

# Compile tests
.if !empty(PKG_OPTIONS:Mtests)
PLIST.tests=		yes
MESON_ARGS+=		-Dbuild-tests=true
REPLACE_PYTHON+=	src/tests/elementary/spec/generator.py
.include "../../devel/check/buildlink3.mk"
.else
MESON_ARGS+=	-Dbuild-tests=false
.endif

# Enable avahi support
.if !empty(PKG_OPTIONS:Mavahi)
MESON_ARGS+=	-Davahi=true
PLIST.avahi=		yes
.include "../../net/avahi/buildlink3.mk"
.endif
