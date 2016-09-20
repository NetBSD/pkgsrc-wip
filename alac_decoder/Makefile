# $NetBSD: Makefile,v 1.2 2012/09/24 16:56:32 asau Exp $
#

DISTNAME=	alac_decoder-0.2.0
CATEGORIES=	audio
#MASTER_SITES=	http://craz.net/programs/itunes/files/
MASTER_SITES=	${MASTER_SITE_GENTOO:=distfiles/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ryoon@NetBSD.org
# HOMEPAGE Dead as of 2016-09-20
HOMEPAGE=	http://craz.net/programs/itunes/alac.html
COMMENT=	Apple Lossless Audio Codec files decoder
LICENSE=	mit

WRKSRC=		${WRKDIR}/alac_decoder
BUILD_TARGET=	# empty

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/alac ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
