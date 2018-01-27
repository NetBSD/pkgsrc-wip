# $NetBSD: Makefile,v 1.2 2012/10/03 09:10:39 asau Exp $
#

VERSION=	1.5
DISTNAME=	gzstream
PKGNAME=	lib${DISTNAME}-${VERSION}
CATEGORIES=	devel
MASTER_SITES=	http://www.cs.unc.edu/Research/compgeom/gzstream/
EXTRACT_SUFX=	.tgz

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://www.cs.unc.edu/Research/compgeom/gzstream/#src
COMMENT=	Gzstream is a small C++ library, basically just a wrapper
LICENSE=	gnu-lgpl-v2.1

USE_LIBTOOL=	yes
USE_TOOLS+=	gmake
USE_LANGUAGES=	c++

INSTALLATION_DIRS+=	lib

do-build:
	cd ${WRKSRC} && ${GMAKE}

TEST_TARGET=	check

do-install:
	${INSTALL_LIB_DIR} ${DESTDIR}${PREFIX}/lib
	${LIBTOOL} --mode=install ${INSTALL_LIB} \
		${WRKSRC}/libgzstream.a ${DESTDIR}${PREFIX}/lib


.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
