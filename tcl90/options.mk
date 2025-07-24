# $NetBSD: options.mk,v 1.1 2025/03/05 06:29:10 scole Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.tcl90
PKG_SUPPORTED_OPTIONS=	debug
#PKG_SUGGESTED_OPTIONS+=

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.options.mk"

# xxx NetBSD 64bit configure detection not working
.if ${MACHINE_ARCH} == "sparc64"
CONFIGURE_ARGS+=	--enable-64bit-vis
.else
.  for plat in ${LP64PLATFORMS}
.    if ${MACHINE_PLATFORM:M${plat}}
CONFIGURE_ARGS+=	--enable-64bit
.    endif
.  endfor
.endif

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-symbols=mem
.endif

# xxx
#.if !empty(PKG_OPTIONS:Mdtrace)
#CONFIGURE_ARGS+=	--enable-dtrace
#.endif
