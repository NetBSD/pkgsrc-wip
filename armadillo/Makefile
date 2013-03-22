# $NetBSD: Makefile,v 1.9 2013/03/22 00:32:11 outpaddling Exp $

#DISTNAME=	armadillo-3.4.4
DISTNAME=	armadillo-3.800.1
CATEGORIES=	math
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE:=arma/}

MAINTAINER=	jwbacon@tds.net
HOMEPAGE=	http://sourceforge.net/projects/arma/
COMMENT=	C++ linear algebra library
# LICENSE=	gnu-lgpl-v3
# Starting with v3.800, using Mozilla Public License 2.0
LICENSE=	mpl-2.0

USE_LANGUAGES+= c c++
USE_CMAKE=	yes

CMAKE_ARGS+=	-DINSTALL_LIB_DIR=${PREFIX}/lib

.include "../../math/blas/buildlink3.mk"
.include "../../math/lapack/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
