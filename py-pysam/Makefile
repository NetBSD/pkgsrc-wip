# $NetBSD$

DISTNAME=	pysam-0.15.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	biology python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pysam/}

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://github.com/pysam-developers/pysam
COMMENT=	Python module for reading, manipulating and writing genomic data sets
LICENSE=	mit

USE_TOOLS+=	gmake

MAKE_ENV+=	HTSLIB_INCLUDE_DIR=${BUILDLINK_PREFIX.htslib}/include
MAKE_ENV+=	HTSLIB_LIBRARY_DIR=${BUILDLINK_PREFIX.htslib}/lib

# FIXME: Why is this necessary?
LDFLAGS+=	-L${DESTDIR}${PREFIX}/${PYSITELIB}/pysam
LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/${PYSITELIB}/pysam

.include "../../biology/htslib/buildlink3.mk"
.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
