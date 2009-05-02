# $NetBSD: options.mk,v 1.1.1.1 2009/05/02 17:43:07 thomasklausner Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.taglib-extras
PKG_SUPPORTED_OPTIONS=	kde4
PKG_SUGGESTED_OPTIONS=	kde4

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mkde4)
CMAKE_ARGS+=	-DWITH_KDE:BOOL=TRUE
BUILD_DEPENDS+=	automoc4>=0.9.87:../../devel/automoc4
.include "../../wip/kdelibs4/buildlink3.mk"
.endif
