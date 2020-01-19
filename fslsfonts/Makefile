# $NetBSD: Makefile,v 1.8 2014/12/31 14:14:16 thomasklausner Exp $

DISTNAME=	fslsfonts-1.0.5
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	blair.sadewitz@gmail.com
HOMEPAGE=	https://xorg.freedesktop.org/
COMMENT=	Lists fonts served by the X server using pattern-matching

USE_TOOLS+=	pkg-config
GNU_CONFIGURE=	yes
USE_LANGUAGES=	c

.include "../../x11/libFS/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
