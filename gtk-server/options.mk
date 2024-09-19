# $NetBSD: options.mk,v 1.1 2013/01/01 01:38:05 othyro Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.gtk-server
PKG_SUPPORTED_OPTIONS=		gtk gtk2 openssl slang xforms #ksh93 needs includes (shell.h)
PKG_SUGGESTED_OPTIONS+=		gtk2 openssl slang
PKG_OPTIONS_OPTIONAL_GROUPS=	backend
PKG_OPTIONS_GROUP.backend=	gtk gtk2 xforms

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgtk)
.include "../../x11/gtk/buildlink3.mk"
CONFIGURE_ARGS+=	--with-gtk1
.else
CONFIGURE_ARGS+=	--enable-gtk1=no
.endif

.if !empty(PKG_OPTIONS:Mgtk2)
.include "../../x11/gtk2/buildlink3.mk"
CONFIGURE_ARGS+=	--with-gtk2
.else
CONFIGURE_ARGS+=	--enable-gtk2=no
.endif

.if !empty(PKG_OPTIONS:Mksh93)
DEPENDS+=		ast-ksh-[0-9]*:../../shells/ast-ksh
CONFIGURE_ARGS+=	--enable-ksh93
.else
CONFIGURE_ARGS+=	--with-ksh93=no
.endif

.if !empty(PKG_OPTIONS:Mopenssl)
.include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	--with-ssl
.else
CONFIGURE_ARGS+=	--without-ssl
.endif

.if !empty(PKG_OPTIONS:Mslang)
.include "../../devel/libslang/buildlink3.mk"
CONFIGURE_ARGS+=        --enable-slang
.else
CONFIGURE_ARGS+=        --with-slang=no
.endif

.if !empty(PKG_OPTIONS:Mxforms)
.include "../../x11/xforms/buildlink3.mk"
CONFIGURE_ARGS+=	--with-xforms
.else
CONFIGURE_ARGS+=	--enable-xforms=no
.endif
