# $NetBSD: Makefile.common,v 1.7 2015/07/20 05:49:53 adam Exp $

PKGNAME=	rdsn-3.9.0
CATEGORIES=	net

GIT_REPOSITORIES=	rdsn
GIT_REPO.rdsn=		https://github.com/Microsoft/rDSN.git

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://research.microsoft.com/en-us/projects/rdsn/
COMMENT=	Robust Distributed System Nucleus
LICENSE=	mit

MAKE_JOBS_SAFE=	no

WRKSRC=			${WRKDIR}/${PKGBASE}
CONFIGURE_DIRS=		${WRKDIR}/build

USE_TOOLS+=		pax
USE_LANGUAGES=		c c++
USE_CMAKE=		yes
GCC_REQD+=		4.8

CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
CMAKE_ARGS+=	-DCMAKE_C_COMPILER=gcc
CMAKE_ARGS+=	-DCMAKE_CXX_COMPILER=g++

CMAKE_ARG_PATH=	${WRKSRC}

INSTALLATION_DIRS=	include

post-extract:
	${RUN} mkdir -p ${WRKDIR}/build

post-install:
	cd ${WRKSRC}/include && ${PAX} -rw . ${DESTDIR}${PREFIX}/include

.include "../../wip/mk/git-package.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
