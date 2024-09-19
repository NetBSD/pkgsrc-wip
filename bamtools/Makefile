# $NetBSD$

DISTNAME=	bamtools-${PORTVERSION}
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=pezmaster31/}
GITHUB_PROJECT=	bamtools
GITHUB_TAG=	v${PORTVERSION}

MAINTAINER=	dsiercks@uwm.edu
HOMEPAGE=	https://github.com/pezmaster31/bamtools
COMMENT=	API and toolkit for handling BAM files
LICENSE=	mit

USE_LANGUAGES=	c c++
USE_CMAKE=	yes
CMAKE_CONFIGURE_ARGS+=	-DBUILD_SHARED_LIBS:BOOL=ON
CMAKE_ARG_PATH=	..
CONFIGURE_DIRS=	_build

PORTVERSION=	2.5.1

post-extract:
	${RUN} mkdir -p ${WRKSRC}/_build

.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/jsoncpp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
