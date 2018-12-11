# $NetBSD$

DISTNAME=	libxlsxwriter-0.8.4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=jmcnamara/}
GITHUB_TAG=	RELEASE_${PKGVERSION_NOREV}

MAINTAINER=	ik@sjmulder.nl
HOMEPAGE=	https://libxlsxwriter.github.io/
COMMENT=	C library for creating Microsoft Excel files
LICENSE=	2-clause-bsd AND original-bsd AND zlib AND mpl-2.0

PYTHON_FOR_BUILD_ONLY=	test

TEST_TARGET=	test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_TOOLS+=	gmake
USE_LANGUAGES+=	c c++

.include "../../lang/python/pyversion.mk"

# more verbose output
MAKE_ENV+=	V=1
MAKE_ENV+=	PYSUFFIX=-${PYVERSSUFFIX}
MAKE_ENV+=	INSTALL_DIR=${DESTDIR}${PREFIX}
# minizip/ioapi.c has broken logic for checking for fopen64 etc
CFLAGS+=	-DIOAPI_NO_64 -D_FILE_OFFSET_BITS=64

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
