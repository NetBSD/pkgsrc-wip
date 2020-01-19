# $NetBSD: Makefile,v 1.7 2014/12/31 14:15:08 thomasklausner Exp $

DISTNAME=	fstobdf-1.0.6
CATEGORIES=	fonts x11
MASTER_SITES=	${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	blair.sadewitz@gmail.com
HOMEPAGE=	https://xorg.freedesktop.org/
COMMENT=	Reads a font from a font server and writes bdf-format output

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c

.include "../../x11/libFS/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
