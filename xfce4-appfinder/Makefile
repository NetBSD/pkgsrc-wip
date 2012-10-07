# $NetBSD: Makefile,v 1.7 2012/10/07 20:11:09 asau Exp $

.include "../../wip/xfce48/Makefile.common"

APPFINDER_VERSION= 4.8.0

DISTNAME=	xfce4-appfinder-${APPFINDER_VERSION}
#PKGREVISION=	1
CATEGORIES=	sysutils
COMMENT=	Xfce application finder

XFCE4_PROJECT=  	xfce4-appfinder
XFCE4_BRANCH=		4.8

.include "../../wip/xfconf/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../wip/xfce4-thunar/buildlink3.mk"
.include "../../wip/libxfce4ui/buildlink3.mk"
.include "../../wip/garcon/buildlink3.mk"
.include "../../wip/libxfce4util/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
