# $NetBSD$

DISTNAME=	dsk2rom-0.80
CATEGORIES=	converters
MASTER_SITES=	http://home.kabelfoon.nl/~vincentd/download/

COMMENT=	MSX disk image conversion utility
HOMEPAGE=	http://home.kabelfoon.nl/~vincentd/
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++
USE_TOOLS=	gmake

WRKSRC=		${WRKDIR}/dsk2rom

INSTALLATION_DIRS+=	${PREFIX}/bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dsk2rom ${DESTDIR}${PREFIX}/bin/dsk2rom

.include "../../mk/bsd.pkg.mk"
