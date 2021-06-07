# $NetBSD$

GITHUB_PROJECT=	pysam
GITHUB_TAG=	refs/tags/v0.16.0.1
DISTNAME=	v0.16.0.1
PKGNAME=	${PYPKGPREFIX}-${GITHUB_PROJECT}-${DISTNAME:S,^v,,}
CATEGORIES=	biology python
MASTER_SITES=	${MASTER_SITE_GITHUB:=pysam-developers/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://github.com/pysam-developers/pysam/
COMMENT=	Python module for reading, manipulating and writing genomic data sets
LICENSE=	mit

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${PKGVERSION_NOREV}
USE_TOOLS+=	gmake

EGG_NAME=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}

MAKE_ENV+=	PYSITELIB=${PYSITELIB}

MAKE_ENV+=	HTSLIB_MODE=external
MAKE_ENV+=	HTSLIB_INCLUDE_DIR=${BUILDLINK_PREFIX.htslib}/include
MAKE_ENV+=	HTSLIB_LIBRARY_DIR=${BUILDLINK_PREFIX.htslib}/lib

# FIXME: Why is this necessary?
LDFLAGS+=	-L${DESTDIR}${PREFIX}/${PYSITELIB}/pysam
LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/${PYSITELIB}/pysam

.include "../../biology/htslib/buildlink3.mk"
.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
