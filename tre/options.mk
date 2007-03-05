# $NetBSD: options.mk,v 1.1.1.1 2007/03/05 17:25:42 briandealwis Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.tre
PKG_SUPPORTED_OPTIONS=		agrep
PKG_SUGGESTED_OPTIONS=		agrep

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Magrep)
CONFIGURE_ARGS+=		--enable-agrep
PLIST_SRC+=			PLIST.agrep
.else
CONFIGURE_ARGS+=		--disable-agrep
.endif
