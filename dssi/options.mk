# $NetBSD: options.mk,v 1.1 2012/11/05 13:51:34 othyro Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.dssi
PKG_SUPPORTED_OPTIONS=	qt
PKG_SUGGESTED_OPTIONS+=	# blank
PLIST_VARS+=		qt

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mqt)
.include "../../x11/qt4-libs/buildlink3.mk"
CONFIGURE_ENV+=         QTDIR=${QTDIR}
PLIST.qt=		yes
.endif
