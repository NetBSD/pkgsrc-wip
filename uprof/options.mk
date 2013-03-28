# $NetBSD: options.mk,v 1.2 2013/03/28 21:25:06 othyro Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.uprof
PKG_SUPPORTED_OPTIONS=	doc
PKG_SUGGESTED_OPTIONS+=	# blank
PLIST_VARS+=		doc

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdoc)
.include "../../textproc/gtk-doc/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-gtk-doc=yes --enable-gtk-doc-html=yes
CONFIGURE_ARGS+=	--enable-gtk-doc-pdf=yes
PLIST.doc=		yes
.endif
