# $NetBSD: Makefile,v 1.5 2012/09/28 23:21:48 asau Exp $

DISTNAME=	fonttosfnt-1.0.5
CATEGORIES=	fonts x11
MASTER_SITES=	${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	blair.sadewitz@gmail.com
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	Modular X.org fonttosfnt utility

USE_TOOLS+=	pkg-config

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c

.include "../../fonts/libfontenc/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
