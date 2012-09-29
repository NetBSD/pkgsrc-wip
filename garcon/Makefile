# $NetBSD: Makefile,v 1.4 2012/09/29 00:50:33 asau Exp $

.include "../../wip/xfce48/Makefile.common"

DISTNAME=	garcon-${XFCE4_VERSION}
XFCE4_VERSION=	0.1.9
CATEGORIES=	x11
COMMENT=	Xfce menu library

XFCE4_PROJECT=	garcon
XFCE4_BRANCH=	0.1

PKGCONFIG_OVERRIDE+=	garcon/garcon-1.pc.in

#CONF_FILES=	etc/xdg/menus/xfce-applications.menu
EGDIR=          ${XFCE4_EGBASE}
PKG_SYSCONFSUBDIR=  xdg
CONF_FILES=     ${EGDIR}/xfce-applications.menu \
	${PKG_SYSCONFDIR}/menus/xfce-applications.menu

MAKE_DIRS+=	${PKG_SYSCONFDIR}/menus

.include "../../wip/libxfce4util/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
