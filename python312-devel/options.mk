# $NetBSD: options.mk,v 1.1 2022/10/31 09:50:40 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.python312
PKG_SUPPORTED_OPTIONS=	dtrace pymalloc
PKG_SUGGESTED_OPTIONS=	# empty

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		dtrace

.if !empty(PKG_OPTIONS:Mdtrace)
CONFIGURE_ARGS+=	--with-dtrace
PLIST.dtrace=		yes
.endif

.if !empty(PKG_OPTIONS:Mpymalloc)
CONFIGURE_ARGS+=	--with-pymalloc
.else
CONFIGURE_ARGS+=	--without-pymalloc
.endif
