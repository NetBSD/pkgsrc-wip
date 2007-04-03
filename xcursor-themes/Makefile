# $NetBSD: Makefile,v 1.3 2007/04/03 13:32:36 bsadewitz Exp $
#

DISTNAME=	xcursor-themes-1.0.1
CATEGORIES=	x11 graphics
MASTER_SITES=	http://xorg.freedesktop.org/releases/individual/data/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	blair.sadewitz@gmail.com
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	Modular X.org xcursor themes

MAKE_JOBS_SAFE=	no

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_DEPENDS+=	xcursorgen>=4.3.0:../../x11/xcursorgen

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	# none
GNU_CONFIGURE=	yes

.include "../../x11/libXcursor/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
