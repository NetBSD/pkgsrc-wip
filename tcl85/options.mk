# $NetBSD: options.mk,v 1.3 2011/06/07 20:44:24 asau Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.tcl
PKG_SUPPORTED_OPTIONS=	threads debug
PKG_SUGGESTED_OPTIONS=	threads

.include "../../mk/bsd.options.mk"

.  if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-symbols=mem
.  endif

.  if !empty(PKG_OPTIONS:Mthreads)
CONFIGURE_ARGS+=	--enable-threads=on
.  else
CONFIGURE_ARGS+=	--enable-threads=off
.  endif
