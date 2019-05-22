# $NetBSD: options.mk,v 1.1 2009/09/11 14:01:19 yhardy Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.icecat35
PKG_SUPPORTED_OPTIONS=	debug mozilla-jemalloc gnome

PLIST_VARS+=		gnome

.if ${OPSYS} == "Linux" || ${OPSYS} == "SunOS"
PKG_SUGGESTED_OPTIONS+=	mozilla-jemalloc
.endif

.if ${MACHINE_ARCH} == i386 || ${MACHINE_ARCH} == sparc || \
	${MACHINE_ARCH} == arm
PKG_SUPPORTED_OPTIONS+=	mozilla-jit
PKG_SUGGESTED_OPTIONS+=	mozilla-jit
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgnome)
.include "../../devel/libgnome/buildlink3.mk"
.include "../../sysutils/gnome-vfs/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-gnomevfs --enable-dbus
PLIST.gnome=		yes
.else
CONFIGURE_ARGS+=	--disable-gnomevfs --disable-dbus
.endif

.if !empty(PKG_OPTIONS:Mmozilla-jemalloc)
CONFIGURE_ARGS+=	--enable-jemalloc
.  if ${OPSYS} == "SunOS"
PLIST.jemalloc=		yes
.  endif
.else
CONFIGURE_ARGS+=	--disable-jemalloc
.endif

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug
.else
CONFIGURE_ARGS+=	--disable-debug
.endif

.if !empty(PKG_OPTIONS:Mmozilla-jit)
CONFIGURE_ARGS+=	--enable-jit
.else
CONFIGURE_ARGS+=	--disable-jit
.endif
