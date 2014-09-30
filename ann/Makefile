# $NetBSD: Makefile,v 1.3 2014/09/30 11:22:27 fhajny Exp $
#

DISTNAME=	ann_1.1.2
PKGNAME=	${DISTNAME:S/_/-/}
CATEGORIES=	math
MASTER_SITES=	http://www.cs.umd.edu/~mount/ANN/Files/${PKGVERSION_NOREV}/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.cs.umd.edu/~mount/ANN
COMMENT=	Library for Approximate Nearest Neighbor Searching
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=	gmake pax
USE_LANGUAGES=	c c++

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
BUILD_TARGET=	sunos5-g++
.elif ${OPSYS} == "Darwin"
BUILD_TARGET=	macosx-g++
.else
BUILD_TARGET=	linux-g++
.endif

INSTALLATION_DIRS=	bin lib share/doc/ann

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/ann2fig ${DESTDIR}${PREFIX}/bin/
	${INSTALL_LIB} ${WRKSRC}/lib/libANN.a ${DESTDIR}${PREFIX}/lib/
	cd ${WRKSRC}/include/ANN && pax -rw -pp . ${DESTDIR}${PREFIX}/include/ANN
	${INSTALL_DATA} ${WRKSRC}/doc/ANNmanual.pdf ${DESTDIR}${PREFIX}/share/doc/ann

.include "../../mk/bsd.pkg.mk"
