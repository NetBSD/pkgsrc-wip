# $NetBSD: Makefile,v 1.11 2012/10/07 20:11:09 asau Exp $

.include "../../wip/xfce48/Makefile.common"

TERMINAL_VERSION=	0.4.8

DISTNAME=	Terminal-${TERMINAL_VERSION}
PKGNAME=	xfce4-terminal-${TERMINAL_VERSION}
#PKGREVISION=	1
CATEGORIES=	x11
COMMENT=	Xfce terminal emulator

MASTER_SITES=	http://archive.xfce.org/src/apps/terminal/0.4/

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../x11/vte/buildlink3.mk"
.include "../../wip/xfce4-exo/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
