# $NetBSD: options.mk,v 1.3 2015/03/11 22:32:08 tnn Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.tcl
PKG_SUPPORTED_OPTIONS=	debug dtrace threads
PKG_SUGGESTED_OPTIONS=	threads

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-symbols=all
.endif

.if !empty(PKG_OPTIONS:Mdtrace)
CONFIGURE_ARGS+=	--enable-dtrace
.endif

.if !empty(PKG_OPTIONS:Mthreads)
CONFIGURE_ARGS+=	--enable-threads
.include "../../mk/pthread.buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-threads
.endif
