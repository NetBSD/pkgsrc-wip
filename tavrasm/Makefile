# $NetBSD$

DISTNAME=	tavrasm
PKGNAME=	${DISTNAME}-1.22
CATEGORIES=	cross
MASTER_SITES=	http://www.tavrasm.org/
DIST_SUBDIR=	${PKGNAME_NOREV}

MAINTAINER=	micha@NetBSD.org
HOMEPAGE=	http://www.tavrasm.org/
COMMENT=	Assember for the Atmel AVR microcontroller family
LICENSE=	gnu-gpl-v2

MAKE_JOBS_SAFE=	no

USE_LANGUAGES=	c c++
FORCE_CXX_STD=	c++98

USE_TOOLS+=	bison flex

WRKSRC=		${WRKDIR}/tavrasm.122
BUILD_DIRS=	src
BUILD_TARGET=	tavrasm

pre-build:
	cd ${WRKSRC}/src && \
		if ! ${TEST} -f Makefile ; then ${LN} -s makefile Makefile ; fi

.include "../../mk/bsd.pkg.mk"
