# $NetBSD: Makefile,v 1.5 2009/11/09 19:48:02 tnn2 Exp $
#

DISTNAME=	xcursor-themes-1.0.2
CATEGORIES=	x11 graphics
MASTER_SITES=	${MASTER_SITE_XORG:=data/}
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
