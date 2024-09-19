# $NetBSD: options.mk,v 1.1 2012/12/29 01:01:16 othyro Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libinstpatch
PKG_SUPPORTED_OPTIONS=	debug doc nls
PKG_SUGGESTED_OPTIONS+=	nls
PLIST_VARS+=		doc gtkdoc

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug
.else
CONFIGURE_ARGS+=	--enable-debug=no
.endif

.if !empty(PKG_OPTIONS:Mdoc)
.include "../../textproc/gtk-doc/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-gtk-doc
PLIST.gtkdoc=		yes
.else
CONFIGURE_ARGS+=	--enable-gtk-doc=no
PLIST.doc=		yes
.endif

.if !empty(PKG_OPTIONS:Mnls)
.include "../../devel/gettext-lib/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-nls
.endif
