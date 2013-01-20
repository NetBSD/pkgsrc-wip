# $NetBSD: options.mk,v 1.2 2013/01/20 14:14:21 othyro Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.dee
PKG_SUPPORTED_OPTIONS=	doc icu introspection tests
PKG_SUGGESTED_OPTIONS+=	doc icu introspection tests
PLIST_VARS+=		icu introspection

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdoc)
CONFIGURE_ARGS+=	--enable-gtk-doc --enable-gtk-doc-html
CONFIGURE_ARGS+=	--enable-gtk-doc-pdf
.include "../../textproc/gtk-doc/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--enable-gtk-doc=no --enable-gtk-doc-html=no
CONFIGURE_ARGS+=	--enable-gtk-doc-pdf=no
.endif

.if !empty(PKG_OPTIONS:Micu)
CONFIGURE_ARGS+=	--enable-icu=yes
PLIST.icu=		yes
.include "../../textproc/icu/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--enable-icu=no
.endif

.if !empty(PKG_OPTIONS:Mintrospection)
CONFIGURE_ARGS+=	--enable-introspection=yes
.include "../../devel/gobject-introspection/buildlink3.mk"
PLIST.introspection=	yes
.else
CONFIGURE_ARGS+=	--enable-introspection=no
.endif

.if !empty(PKG_OPTIONS:Mtests)
CONFIGURE_ARGS+=	--enable-tests=yes
.else
CONFIGURE_ARGS+=	--enable-tests=no
.endif
