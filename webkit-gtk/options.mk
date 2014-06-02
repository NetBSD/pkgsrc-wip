# $NetBSD: options.mk,v 1.2 2014/06/02 08:09:02 leot1990 Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.webkit-gtk
PKG_SUPPORTED_OPTIONS=	webkit-jit debug
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.prefs.mk"

# XXX JIT produces invalid code on NetBSD/i386 and NetBSD/amd64
.if empty(MACHINE_PLATFORM:MNetBSD-*-i386) && empty(MACHINE_PLATFORM:MNetBSD-*-x86_64)
PKG_SUGGESTED_OPTIONS+= webkit-jit
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mwebkit-jit)
CONFIGURE_ARGS+=	--enable-jit
.else
CONFIGURE_ARGS+=	--disable-jit
.endif

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug
.else
CONFIGURE_ARGS+=	--disable-debug
.endif
