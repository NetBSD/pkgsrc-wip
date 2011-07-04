# $NetBSD: Makefile,v 1.4 2011/07/04 14:57:34 reinoudz70 Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../meta-pkgs/xfce4/Makefile.common"

ICONS_VERSION=	4.4.3

DISTNAME=	xfce4-icon-theme-${ICONS_VERSION}
PKGREVISION=	5
CATEGORIES=	graphics
COMMENT=	Xfce icon themes

MASTER_SITES=	http://archive.xfce.org/src/art/xfce4-icon-theme/4.4/

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
