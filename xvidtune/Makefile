# $NetBSD: Makefile,v 1.1 2007/01/29 13:02:24 bsadewitz Exp $
#

DISTNAME=	xvidtune-1.0.1
CATEGORIES=	x11
MASTER_SITES=	http://xorg.freedesktop.org/releases/individual/app/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	blair.sadewitz@gmail.com
HOMEPAGE=	http://xorg.freedesktop.org/releases/individual/app/
COMMENT=	X video tuning utility from modular X.org

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	pkg-config
GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++

.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
