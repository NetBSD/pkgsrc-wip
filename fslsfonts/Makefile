# $NetBSD: Makefile,v 1.1 2007/01/23 14:56:38 bsadewitz Exp $
#

DISTNAME=	fslsfonts-1.0.1
CATEGORIES=	x11
MASTER_SITES=	http://xorg.freedesktop.org/releases/individual/app/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	blair.sadewitz@gmail.com
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	Lists fonts served by the X server using pattern-matching

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_TOOLS+=	pkg-config
GNU_CONFIGURE=	yes
USE_LANGUAGES=	c

.include "../../x11/libFS/buildlink3.mk"
.include "../../wip/libX11/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
