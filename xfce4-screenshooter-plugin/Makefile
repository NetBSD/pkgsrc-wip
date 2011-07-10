# $NetBSD: Makefile,v 1.3 2011/07/10 16:47:05 reinoudz70 Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../wip/xfce48/Makefile.common"

SCREENSHOOT_VERSION=	1.7.9

DISTNAME=	xfce4-screenshooter-${SCREENSHOOT_VERSION}
PKGNAME=	xfce4-screenshooter-plugin-${SCREENSHOOT_VERSION}
PKGREVISION=	6
CATEGORIES=	x11
COMMENT=	Xfce screenshot plugin

MASTER_SITES=	http://archive.xfce.org/src/apps/xfce4-screenshooter/1.7/

.include "../../wip/xfce4-panel/buildlink3.mk"
.include "../../wip/libxfce4gui/buildlink3.mk"
.include "../../net/libsoup24/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
