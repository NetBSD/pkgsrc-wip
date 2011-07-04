# $NetBSD: Makefile,v 1.11 2011/07/04 14:16:31 reinoudz70 Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../wip/xfce48/Makefile.common"

MOUSEPAD_VERSION=	0.2.16

DISTNAME=	mousepad-${MOUSEPAD_VERSION}
PKGNAME=	xfce4-mousepad-${MOUSEPAD_VERSION}
PKGREVISION=	6
CATEGORIES=	editors
COMMENT=	Xfce text editor

MASTER_SITES=	http://archive.xfce.org/src/apps/mousepad/0.2/

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../wip/libxfce4gui/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
