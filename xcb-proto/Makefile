# $NetBSD: Makefile,v 1.4 2008/03/25 20:50:15 bsadewitz Exp $
#

DISTNAME=	xcb-proto-1.1
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	http://xcb.freedesktop.org/dist/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://xcb.freedesktop.org/
COMMENT=	XCB protocol descriptions (in XML)

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config automake
USE_LANGUAGES=	# none

PKGCONFIG_OVERRIDE+=	xcb-proto.pc.in

pre-configure:
	cd ${WRKSRC} && autoreconf -v -i -f

.include "../../mk/bsd.pkg.mk"
