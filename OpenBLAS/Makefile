# $NetBSD$

DISTNAME=	OpenBLAS-0.2.20
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

# You may override the autodetected thread count limit.
# Default is detected from build host.
BUILD_DEFS+=    OPENBLAS_THREAD_LIMIT

MAKE_ENV=	PREFIX=${PREFIX}
MAKE_ENV+=	CC=${CCPATH}
MAKE_ENV+=	FC=${FCPATH}
MAKE_ENV+=     NUM_THREADS=${OPENBLAS_THREAD_LIMIT:Q}

# Those work further on MAKE_ENV.
.include "options.mk"

.if (${MACHINE_ARCH} == "i386")
MAKE_ENV+=	BINARY=32
.else
MAKE_ENV+=	BINARY=64
.endif

INSTALL_MAKE_FLAGS+=	PREFIX=${PREFIX}

.include "../../mk/bsd.pkg.mk"
