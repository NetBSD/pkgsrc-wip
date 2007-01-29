# $NetBSD: Makefile,v 1.1 2007/01/29 08:39:28 bsadewitz Exp $
#

DISTNAME=	luit-1.0.2
CATEGORIES=	x11
MASTER_SITES=	http://xorg.freedesktop.org/releases/individual/app/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	blair.sadewitz@gmail.com
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c
GNU_CONFIGURE=	yes

.include "../../fonts/libfontenc/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
