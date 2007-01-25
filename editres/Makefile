# $NetBSD: Makefile,v 1.2 2007/01/25 16:18:46 bsadewitz Exp $
#

DISTNAME=	editres-1.0.2
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://xorg.freedesktop.org/releases/individual/app/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	blair.sadewitz@gmail.com
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	The modular X.org resource editor

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c

.include "../../x11/libXaw/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
