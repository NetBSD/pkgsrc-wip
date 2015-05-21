# $NetBSD: Makefile,v 1.4 2015/05/21 17:27:06 blef Exp $

DISTNAME=	lxlauncher-0.2.4
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lxde/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://wiki.lxde.org/en/LXLauncher
COMMENT=	Program launcher for small screens

DEPENDS+=	lxmenu-data-[0-9]*:../../wip/lxmenu-data

LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_TOOLS+=	intltool pkg-config

OWN_DIRS+=	${PKG_SYSCONFDIR}/xdg/lxlauncher ${PKG_SYSCONFDIR}/xdg/menus
EGDIR=		${PREFIX}/share/examples/xdg/lxlauncher
INSTALLATION_DIRS= share/examples/xdg/lxlauncher
CONF_FILES=	${EGDIR}/gtkrc ${PKG_SYSCONFDIR}/xdg/lxlauncher/gtkrc
CONF_FILES+=	${EGDIR}/settings.conf ${PKG_SYSCONFDIR}/xdg/lxlauncher/settings.conf
CONF_FILES+=	${EGDIR}/lxlauncher-applications.menu ${PKG_SYSCONFDIR}/xdg/menus/lxlauncher-applications.menu

.include "../../sysutils/menu-cache/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
