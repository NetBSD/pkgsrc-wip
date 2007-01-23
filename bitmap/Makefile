# $NetBSD: Makefile,v 1.1 2007/01/23 14:00:49 bsadewitz Exp $
#

DISTNAME=	bitmap-1.0.2
CATEGORIES=	x11
MASTER_SITES=	http://xorg.freedesktop.org/releases/individual/app/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	blair.sadewitz@gmail.com
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	Rudimentary bitmap editor from modular X.org

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

# url2pkg-marker (please do not remove this line.)
.include "../../wip/libX11/buildlink3.mk"
.include "../../wip/xbitmaps/buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/xbitmaps/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
