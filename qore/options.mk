# $NetBSD: options.mk,v 1.11 2014/02/21 20:38:01 nros Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.qore
PKG_SUPPORTED_OPTIONS=	debug doc
PLIST_VARS+=		doc
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=        --enable-debug
.else
CONFIGURE_ARGS+=        --disable-debug
.endif

.if !empty(PKG_OPTIONS:Mdoc)
INSTALL_TARGET=		install install-html-local
PLIST.doc=		yes
.endif

