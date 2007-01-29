# $NetBSD: Makefile,v 1.1 2007/01/29 13:29:53 bsadewitz Exp $
#

DISTNAME=	xcursor-themes-1.0.1
CATEGORIES=	x11 graphics
MASTER_SITES=	http://xorg.freedesktop.org/releases/individual/data/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	blair.sadewitz@gmail.com
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	Modular X.org xcursor themes

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_DEPENDS+=	xcursorgen>=4.3.0:../../x11/xcursorgen

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	# none
GNU_CONFIGURE=	yes

# url2pkg-marker (please do not remove this line.)
.include "../../x11/libXcursor/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
