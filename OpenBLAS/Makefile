# $NetBSD$

DISTNAME=	OpenBLAS-0.2.19
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=xianyi/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	kuehro@posteo.de
HOMEPAGE=	http://www.openblas.net/
COMMENT=	OpenBLAS is an optimized BLAS library based on GotoBLAS2 1.13 BSD
LICENSE=	modified-bsd

EXTRACT_USING=	bsdtar

ONLY_FOR_PLATFORM+=	*-*-i386 *-*-x86_64

USE_TOOLS+=	gmake perl
USE_LANGUAGES+=	c fortran
GCC_REQD+=	6.2

NO_CONFIGURE=	yes

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

.include "../../mk/bsd.pkg.mk"
