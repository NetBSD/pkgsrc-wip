# $NetBSD: Makefile,v 1.1 2015/01/02 05:44:00 obache Exp $

DISTNAME=	mate-screensaver-1.8.1
CATEGORIES=	x11
MASTER_SITES=	http://pub.mate-desktop.org/releases/1.8/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://www.mate-desktop.org/
COMMENT=	Screen saver and locker for the MATE desktop
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake intltool msgfmt pkg-config

PKGCONFIG_OVERRIDE+=	data/mate-screensaver.pc.in

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

INSTALL_MAKE_FLAGS+=	sysconfdir=${PREFIX}/share/examples/${PKGBASE}

MAKE_DIRS+=	${PKG_SYSCONFDIR}/xdg/autostart
MAKE_DIRS+=	${PKG_SYSCONFDIR}/xdg/menus
CONF_FILES+=	${PREFIX}/share/examples/mate-screensaver/xdg/autostart/mate-screensaver.desktop \
		${PKG_SYSCONFDIR}/xdg/autostart/mate-screensaver.desktop
CONF_FILES+=	${PREFIX}/share/examples/mate-screensaver/xdg/menus/mate-screensavers.menu \
		${PKG_SYSCONFDIR}/xdg/menus/mate-screensavers.menu

.include "../../devel/glib2/schemas.mk"

.include "../../wip/mate-desktop/buildlink3.mk"
.include "../../wip/mate-menus/buildlink3.mk"
.include "../../wip/libmatekbd/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXScrnSaver/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
