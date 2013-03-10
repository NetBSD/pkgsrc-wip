# $NetBSD: options.mk,v 1.1 2013/03/10 00:12:56 othyro Exp $

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
.else
CONFIGURE_ARGS+=	--enable-gtk-doc=no --enable-gtk-doc-html=no
CONFIGURE_ARGS+=	--enable-gtk-doc-pdf=no
.endif
