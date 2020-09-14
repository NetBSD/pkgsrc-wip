# $NetBSD$

DISTNAME=	CHSPy-1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	math python
MASTER_SITES=	https://files.pythonhosted.org/packages/5d/6f/fbeb848039fdcaaad8736f4b11c8a25f161062a93f351850e86800c4298f/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://files.pythonhosted.org/packages/5d/6f/fbeb848039fdcaaad8736f4b11c8a25f161062a93f351850e86800c4298f/
COMMENT=	Cubic Hermite splines
LICENSE=	modified-bsd

BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=3.5.0:../../devel/py-setuptools_scm
TEST_DEPENDS+=	# TODO: symengine>=0

USE_LANGUAGES=	# none

BUILDLINK_API_DEPENDS.py-numpy+=	${PYPKGPREFIX}-numpy>=0
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
