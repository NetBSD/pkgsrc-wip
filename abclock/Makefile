# $NetBSD: Makefile,v 1.7 2011/11/08 10:23:51 ryo-on Exp $

DISTNAME=	abclock-1.0d
CATEGORIES=	time
MASTER_SITES=	${HOMEPAGE}

MAINTAINER=	ryoon@NetBSD.org
COMMENT=	Analogue Bitmap Clock
HOMEPAGE=	http://odur.let.rug.nl/~kleiweg/abclock/

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/abclock ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/abc_img ${DESTDIR}${PREFIX}/bin

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
