# $NetBSD$

DISTNAME=	mfusepy-3.1.1.32
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	filesystems python
MASTER_SITES=	${MASTER_SITE_GITHUB:=mxmlnkn/}
GITHUB_PROJECT=	mfusepy
GITHUB_TAG=	b3b03ef8aebb8c1629d7982285731bd887826c8e

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://pypi.org/project/mfusepy/
COMMENT=	Python bindings for the FUSE[23] APIs
LICENSE=	isc

USE_LANGUAGES=	# none

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=77:../../devel/py-setuptools

SUBST_CLASSES+=		version
SUBST_STAGE.version=	pre-configure
SUBST_FILES.version=	pyproject.toml
SUBST_SED.version=	-e 's/3.1.1/${PKGVERSION_NOREV}/'

# TEST DEPENDS
USE_LANGUAGES+=		c
# Not in pyproject.toml but hidden in tests/:
TEST_DEPENDS+=		${PYPKGPREFIX}-test-order-[0-9]*:../../devel/py-test-order

# "Releases" lack bits needed for tests.
# https://github.com/mxmlnkn/mfusepy/issues/61

.include "../../lang/python/wheel.mk"
.include "../../mk/fuse.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
