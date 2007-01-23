# $NetBSD: Makefile,v 1.1 2007/01/23 12:27:07 bsadewitz Exp $
#

DISTNAME=	xbitmaps-1.0.1
CATEGORIES=	x11
MASTER_SITES=	http://xorg.freedesktop.org/releases/individual/data/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	blair.sadewitz@gmail.com
HOMEPAGE=	http://xorg.freedesktop.org/releases/individual/data/
COMMENT=	Modular X.org project bitmaps

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	# none

PKGCONFIG_OVERRIDE+=	xbitmaps.pc.in


.include "../../mk/bsd.pkg.mk"
