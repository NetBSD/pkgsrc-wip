# $NetBSD$

DISTNAME=	${PKGVERSION_NOREV}
PKGNAME=	exomizer-3.1.2
CATEGORIES=	cross
# https://bitbucket.org/magli143/exomizer/get/3.1.2.tar.bz2
MASTER_SITES=	https://bitbucket.org/magli143/exomizer/get/
DIST_SUBDIR=	exomizer
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://bitbucket.org/magli143/exomizer/wiki/Home
COMMENT=	Compressor for Commodore 64 programs
LICENSE=	zlib

USE_LANGUAGES=	c
USE_TOOLS+=	gmake

WRKSRC=		${WRKDIR}/magli143-exomizer-df77c879ce2a
BUILD_DIRS=	src # exodecrs rawdecrs
BUILD_TARGET=	build

INSTALLATION_DIRS+=	bin share/exomizer

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/exomizer ${DESTDIR}${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/src/exobasic ${DESTDIR}${PREFIX}/bin/
	# ${INSTALL_DATA} ${WRKSRC}/src/sfxdecr ${DESTDIR}${PREFIX}/share/exomizer/
	${INSTALL_DATA} ${WRKSRC}/*.txt ${DESTDIR}${PREFIX}/share/exomizer/

.include "../../mk/bsd.pkg.mk"
