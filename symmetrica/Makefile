# $NetBSD$

DISTNAME=	SYM2_0_tar
PKGNAME=	symmetrica-${VERSION}
CATEGORIES=	math
MASTER_SITES=	http://www.algorithm.uni-bayreuth.de/en/research/SYMMETRICA/
EXTRACT_SUFX=	.gz

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.algorithm.uni-bayreuth.de/en/research/SYMMETRICA/
COMMENT=	Symmetrica Combinatoric C Library
LICENSE=	public-domain

WRKSRC=	${WRKDIR}

VERSION=	2.0
NO_CONFIGURE=	yes
USE_LANGUAGES=	c c++
MAKE_FILE=	makefile
USE_TOOLS+=	gmake

INSTALLATION_DIRS+=	bin include/symmetrica

do-build:
	cd ${WRKSRC} && ${GMAKE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/test ${DESTDIR}${PREFIX}/bin/test-symmetrica
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/include/symmetrica
	${INSTALL_DATA} ${WRKSRC}/def.h ${DESTDIR}${PREFIX}/include/symmetrica
	${INSTALL_DATA} ${WRKSRC}/macro.h ${DESTDIR}${PREFIX}/include/symmetrica

.include "../../mk/bsd.pkg.mk"
