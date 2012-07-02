# $NetBSD: Makefile,v 1.3 2012/07/02 13:37:54 moubctez Exp $

DISTNAME=	armadillo-2.2.1
PKGREVISION=	1
CATEGORIES=	math
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE:=arma/}

MAINTAINER=	jwbacon@tds.net
HOMEPAGE=	http://sourceforge.net/projects/arma/
COMMENT=	C++ template matrix library
LICENSE=	gnu-lgpl-v3

USE_LANGUAGES+= c c++
USE_CMAKE=	yes

PKG_DESTDIR_SUPPORT=	user-destdir

CMAKE_ARGS+=	-DINSTALL_LIB_DIR=${PREFIX}/lib

pre-configure:
	cp -f ${FILESDIR}/CMakeLists.txt.native-find ${WRKSRC}

.include "../../math/blas/buildlink3.mk"
.include "../../math/lapack/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
