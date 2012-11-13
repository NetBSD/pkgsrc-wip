# $NetBSD: Makefile,v 1.6 2012/11/13 23:56:10 outpaddling Exp $

DISTNAME=	armadillo-3.4.4
CATEGORIES=	math
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE:=arma/}

MAINTAINER=	jwbacon@tds.net
HOMEPAGE=	http://sourceforge.net/projects/arma/
COMMENT=	C++ linear algebra library
LICENSE=	gnu-lgpl-v3

USE_LANGUAGES+= c c++
USE_CMAKE=	yes

CMAKE_ARGS+=	-DINSTALL_LIB_DIR=${PREFIX}/lib

#pre-configure:
	#cp -f ${FILESDIR}/CMakeLists.txt.native-find ${WRKSRC}

.include "../../math/blas/buildlink3.mk"
.include "../../math/lapack/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
