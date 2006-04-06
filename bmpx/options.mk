# $NetBSD: options.mk,v 1.5 2006/04/06 07:17:02 jeremy-c-reed Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.bmpx
PKG_SUPPORTED_OPTIONS=	debug gui
PKG_SUGGESTED_OPTIONS=	gui

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug
.endif

.if !empty(PKG_OPTIONS:Mgui)
BUILDLINK_API_DEPENDS.libglade2+=	libglade2>=2.5.1

.  include "../../devel/libglade2/buildlink3.mk"
.  include "../../devel/pango/buildlink3.mk"
.  include "../../graphics/cairo/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-gui
.else
CONFIGURE_ARGS+=	--disable-gui
.endif
