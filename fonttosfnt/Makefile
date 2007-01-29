# $NetBSD: Makefile,v 1.2 2007/01/29 08:26:15 bsadewitz Exp $
#

DISTNAME=	fonttosfnt-1.0.3
CATEGORIES=	fonts x11
MASTER_SITES=	http://xorg.freedesktop.org/releases/individual/app/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	blair.sadewitz@gmail.com
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	Modular X.org fonttosfnt utility

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	pkg-config

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c


.include "../../fonts/libfontenc/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
