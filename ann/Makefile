# $NetBSD: Makefile,v 1.1.1.1 2011/01/17 22:02:17 jihbed Exp $
#

DISTNAME=	ann_1.1.2
PKGNAME=	ann-1.1.2
CATEGORIES=	math
MASTER_SITES=	http://www.cs.umd.edu/~mount/ANN/Files/1.1.2/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.cs.umd.edu/~mount/ANN
COMMENT=	Library for Approximate Nearest Neighbor Searching
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+= gmake pax
USE_LANGUAGES=	c++

INSTALLATION_DIRS=	bin lib share/doc/ann

ONLY_FOR_PLATFORM= NetBSD-*-* Linux-*-*

do-build:
	cd ${WRKSRC} && ${GMAKE} linux-g++

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/ann2fig ${DESTDIR}${PREFIX}/bin/
	${INSTALL_LIB} ${WRKSRC}/lib/libANN.a ${DESTDIR}${PREFIX}/lib/
	cd ${WRKSRC}/include/ANN && pax -rw -pp . ${DESTDIR}${PREFIX}/include/ANN
	${INSTALL_DATA} ${WRKSRC}/doc/ANNmanual.pdf ${DESTDIR}${PREFIX}/share/doc/ann

.include "../../mk/bsd.pkg.mk"
