# $NetBSD: options.mk,v 1.1 2013/01/13 16:26:41 othyro Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.unagi
PKG_SUPPORTED_OPTIONS=	doxygen
PKG_SUGGESTED_OPTIONS+=	# blank

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdoxygen)
DEPENDS+=		doxygen-[0-9]*:../../devel/doxygen
CONFIGURE_ARGS+=	--enable-doxygen-dot --enable-doxygen-man
CONFIGURE_ARGS+=	--enable-doxygen-rtf --enable-doxygen-xml
CONFIGURE_ARGS+=	--enable-doxygen-chm --enable-doxygen-pdf
.else
CONFIGURE_ARGS+=	--disable-doxygen-doc
.endif
