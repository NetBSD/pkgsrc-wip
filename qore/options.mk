# $NetBSD: options.mk,v 1.5 2014/01/20 20:58:11 nros Exp $
# used by wip/qore/Makefile
# used by wip/qore-yaml-module/Makefile
# used by wip/qore-xml-module/Makefile
# used by wip/qore-json-module/Makefile

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

