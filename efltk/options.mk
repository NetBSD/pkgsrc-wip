# $NetBSD: options.mk,v 1.1.1.1 2009/08/11 02:35:47 christtrekker Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.efltk
PKG_SUPPORTED_OPTIONS=	opengl mysql

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		${PKG_SUPPORTED_OPTIONS}

.if !empty(PKG_OPTIONS:Mopengl)
PLIST.opengl=		yes
CONFIGURE_ARGS+=	--enable-opengl
MAKE_ENV+=		HAVE_OPENGL=yes
.  include "../../graphics/MesaLib/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-opengl
MAKE_ENV+=		HAVE_OPENGL=no
.endif

.if !empty(PKG_OPTIONS:Mmysql)
PLIST.mysql=		yes
CONFIGURE_ARGS+=	--enable-mysql
.  include "../../mk/mysql.buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-mysql
.endif
