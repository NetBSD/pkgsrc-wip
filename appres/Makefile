# $NetBSD: Makefile,v 1.3 2007/01/25 16:10:09 bsadewitz Exp $
#

DISTNAME=	appres-1.0.1
PKGREVISION=	1
CATEGORIES=	wip
MASTER_SITES=	http://xorg.freedesktop.org/releases/individual/app/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	blair.sadewitz@gmail.com
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	Modular X.org X resources applet

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config


.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
