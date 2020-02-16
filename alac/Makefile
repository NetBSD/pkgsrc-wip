# $NetBSD$

DISTNAME=	alac_decoder-0.2.0
CATEGORIES=	audio
MASTER_SITES=	https://web.archive.org/web/20150510210401if_/http://craz.net/programs/itunes/files/
EXTRACT_SUFX=	.tgz

MAINTAINER=	js-pkgsrc@nil.im
HOMEPAGE=	https://web.archive.org/web/20150319040222/craz.net/programs/itunes/alac.html
COMMENT=	Basic decoder for Apple Lossless Audio Codec files (ALAC)
LICENSE=	mit

WRKSRC=		${WRKDIR}/alac_decoder
BUILD_TARGET=	alac

do-install:
	${MKDIR} -p ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/alac ${DESTDIR}${PREFIX}/bin/alac

.include "../../mk/bsd.pkg.mk"
