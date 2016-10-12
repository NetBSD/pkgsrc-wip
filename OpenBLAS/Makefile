# $NetBSD$

CATEGORIES=	math

MAINTAINER=	kuehro@posteo.de
COMMENT=	OpenBLAS is an optimized BLAS library based on GotoBLAS2 1.13 BSD
LICENSE=	modified-bsd

OPENBLAS_VER=	0.2.19
DISTNAME=	v${OPENBLAS_VER}
PKGNAME=	OpenBLAS-${OPENBLAS_VER}
MASTER_SITES=	${MASTER_SITE_GITHUB:=xinayi/}
GITHUB_TAG=	${DISTNAME}

HOMEPAGE=	http://www.openblas.net/

EXTRACT_USING=	gtar
WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

ONLY_FOR_PLATFORM+=	*-*-i386 *-*-x86_64

USE_TOOLS+=	gmake perl
USE_LANGUAGES+=	c fortran
GCC_REQD+=	6.2

NO_CONFIGURE=	yes

.include "../../mk/bsd.pkg.mk"


MAKE_ENV=	PREFIX=${PREFIX}
MAKE_ENV+=	CC=${CCPATH}
MAKE_ENV+=	FC=${FCPATH}

.if (${MACHINE_ARCH} == "i386")
MAKE_ENV+=	BINARY=32
.else
MAKE_ENV+=	BINARY=64
.endif

# Choose the processor kernel dynamically at runtime
MAKE_ENV+=	DYNAMIC_ARCH=1

# NO_AFFINITY=1 recommended for use in OpenMP codes
MAKE_ENV+=	USE_OPENMP=1 NO_AFFINITY=1

INSTALL_MAKE_FLAGS+=	PREFIX=${PREFIX}
