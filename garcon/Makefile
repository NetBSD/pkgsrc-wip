# $NetBSD: Makefile,v 1.1 2011/06/29 09:27:12 reinoudz70 Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../wip/xfce48/Makefile.common"

DISTNAME=	garcon-${XFCE4_VERSION}
XFCE4_VERSION=	0.1.5
CATEGORIES=	x11
COMMENT=	Xfce menu library

XFCE4_PROJECT=	garcon
XFCE4_BRANCH=	0.1

PKGCONFIG_OVERRIDE+=	garcon/garcon-1.pc.in

#CONF_FILES=	etc/xdg/menus/xfce-applications.menu
EGDIR=          ${XFCE4_EGBASE}
PKG_SYSCONFSUBDIR=  xdg
CONF_FILES=     ${EGDIR}/xfce-applications.menu \
	${PKG_SYSCONFDIR}/menus/applications.menu

MAKE_DIRS+=	${PKG_SYSCONFDIR}/menus

#.include "../../wip/libxfce4util/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
