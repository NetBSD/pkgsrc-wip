# $NetBSD: Makefile,v 1.2 2007/12/01 17:51:41 jeremy-c-reed Exp $
#

DISTNAME=	xcb-proto-1.1
CATEGORIES=	x11
MASTER_SITES=	http://xcb.freedesktop.org/dist/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://xcb.freedesktop.org/
COMMENT=	XCB protocol descriptions (in XML)

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	# none

PKGCONFIG_OVERRIDE+=	xcb-proto.pc.in

.include "../../mk/bsd.pkg.mk"
