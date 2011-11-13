# $NetBSD: Makefile,v 1.1.1.1 2011/11/13 22:03:51 ryo-on Exp $
#

DISTNAME=	alac_decoder-0.2.0
CATEGORIES=	audio
MASTER_SITES=	http://craz.net/programs/itunes/files/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://craz.net/programs/itunes/alac.html
COMMENT=	Apple Lossless Audio Codec files decoder
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/alac_decoder
BUILD_TARGET=	# empty

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/alac ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
