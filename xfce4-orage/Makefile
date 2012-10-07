# $NetBSD: Makefile,v 1.6 2012/10/07 20:11:09 asau Exp $

.include "../../wip/xfce48/Makefile.common"

ORAGE_VERSION=	4.8.3

DISTNAME=	orage-${ORAGE_VERSION}
PKGNAME=	xfce4-orage-${ORAGE_VERSION}
#PKGREVISION=	1
CATEGORIES=	time
COMMENT=	Xfce time managing application

MASTER_SITES=	http://archive.xfce.org/src/apps/orage/4.8/

CONFIGURE_ARGS+=	--disable-libxfce4mcs

MAKE_DIRS+=	${PREFIX}/libexec/xfce4 ${PREFIX}/libexec/xfce4/panel-plugins
MAKE_DIRS+=	${PREFIX}/share/xfce4 ${PREFIX}/share/xfce4/panel-plugins

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../wip/libxfce4ui/buildlink3.mk"
.include "../../wip/xfce4-panel/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
