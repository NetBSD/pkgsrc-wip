# $NetBSD: Makefile,v 1.7 2012/11/17 18:56:25 outpaddling Exp $

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

.include "../../math/blas/buildlink3.mk"
.include "../../math/lapack/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
