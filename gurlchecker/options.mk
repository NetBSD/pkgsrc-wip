# $NetBSD: options.mk,v 1.2 2013/01/21 05:48:18 othyro Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gurlchecker
PKG_SUPPORTED_OPTIONS=	clamav croco doc json sqlite3 tidy
PKG_SUGGESTED_OPTIONS+=	doc
PLIST_VARS+=		doc

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mclamav)
.include "../../security/clamav/buildlink3.mk"
CONFIGURE_ARGS+=	--with-clamav
.else
CONFIGURE_ARGS+=	--without-clamav
.endif

.if !empty(PKG_OPTIONS:Mcroco)
.include "../../textproc/libcroco/buildlink3.mk"
CONFIGURE_ARGS+=	--with-croco
.else
CONFIGURE_ARGS+=        --without-croco
.endif

.if !empty(PKG_OPTIONS:Mdoc)
.include "../../textproc/gtk-doc/buildlink3.mk"
PLIST.doc=		yes
CONFIGURE_ARGS+=	--enable-gtk-doc
.else
CONFIGURE_ARGS+=	--disable-gtk-doc
.endif

.if !empty(PKG_OPTIONS:Mjson)
.include "../../textproc/json-glib/buildlink3.mk"
CONFIGURE_ARGS+=	--with-json
.else
CONFIGURE_ARGS+=	--without-json
.endif

.if !empty(PKG_OPTIONS:Msqlite3)
.include "../../databases/sqlite3/buildlink3.mk"
CONFIGURE_ARGS+=	--with-sqlite3
.else
CONFIGURE_ARGS+=	--without-sqlite3
.endif

.if !empty(PKG_OPTIONS:Mtidy)
.include "../../www/tidy/buildlink3.mk"
CONFIGURE_ARGS+=	--with-tidy
.else
CONFIGURE_ARGS+=	--without-tidy
.endif
