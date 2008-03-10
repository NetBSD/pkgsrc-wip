# $NetBSD: Makefile,v 1.5 2008/03/10 23:54:27 tnn2 Exp $

DISTNAME=	abclock-1.0d
CATEGORIES=	time
MASTER_SITES=	${HOMEPAGE}

MAINTAINER=	ghen@NetBSD.org
COMMENT=	Analogue Bitmap Clock
HOMEPAGE=	http://odur.let.rug.nl/~kleiweg/abclock/

PKG_DESTDIR_SUPPORT=	user-destdir

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/abclock ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/abc_img ${DESTDIR}${PREFIX}/bin

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
