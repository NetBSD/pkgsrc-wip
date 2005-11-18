# $NetBSD: Makefile,v 1.1.1.1 2005/11/18 10:43:04 ghen Exp $

DISTNAME=	abclock-1.0c
CATEGORIES=	time
MASTER_SITES=	${HOMEPAGE}

MAINTAINER=	geert.hendrickx@ua.ac.be
COMMENT=	Analogue Bitmap Clock
HOMEPAGE=	http://odur.let.rug.nl/~kleiweg/abclock/

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/abclock ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/abc_img ${PREFIX}/bin

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
