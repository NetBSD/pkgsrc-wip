# $NetBSD: Makefile,v 1.2 2005/12/13 12:16:11 ghen Exp $

DISTNAME=	abclock-1.0c
CATEGORIES=	time
MASTER_SITES=	${HOMEPAGE}

MAINTAINER=	ghen@NetBSD.org
COMMENT=	Analogue Bitmap Clock
HOMEPAGE=	http://odur.let.rug.nl/~kleiweg/abclock/

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/abclock ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/abc_img ${PREFIX}/bin

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
