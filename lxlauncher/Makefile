# $NetBSD: Makefile,v 1.4 2015/05/21 17:27:06 blef Exp $

DISTNAME=	lxlauncher-0.2.5
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lxde/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://wiki.lxde.org/en/LXLauncher
COMMENT=	Program launcher for small screens
LICENSE=	gnu-gpl-v2

DEPENDS+=	lxmenu-data-[0-9]*:../../wip/lxmenu-data

GNU_CONFIGURE=	yes
USE_TOOLS+=	intltool pkg-config

PKG_SYSCONFSUBDIR=	xdg
MAKE_DIRS+=	${PKG_SYSCONFDIR}/lxlauncher \
		${PKG_SYSCONFDIR}/menus

EGDIR=		share/examples/lxde
CONFIGURE_ARGS+=	--sysconfdir=${PREFIX}/${EGDIR}

CONF_FILES=	${EGDIR}/xdg/lxlauncher/gtkrc			\
		${PKG_SYSCONFDIR}/lxlauncher/gtkrc 		\
		${EGDIR}/xdg/lxlauncher/gtk.css			\
		${PKG_SYSCONFDIR}/lxlauncher/gtk.css 		\
		${EGDIR}/xdg/lxlauncher/settings.conf		\
		${PKG_SYSCONFDIR}/lxlauncher/settings.conf	\
		${EGDIR}/xdg/menus/lxlauncher-applications.menu \
		${PKG_SYSCONFDIR}/menus/lxlauncher-applications.menu

.include "../../sysutils/menu-cache/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
