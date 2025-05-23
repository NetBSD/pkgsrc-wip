# $NetBSD$

DISTNAME=	bamtools-2.5.3
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=pezmaster31/}
GITHUB_PROJECT=	bamtools
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://github.com/pezmaster31/bamtools
COMMENT=	API and toolkit for handling BAM files
LICENSE=	mit

USE_LANGUAGES=		c c++
CMAKE_CONFIGURE_ARGS+=	-DBUILD_SHARED_LIBS:BOOL=ON

.include "../../devel/cmake/build.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/jsoncpp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
