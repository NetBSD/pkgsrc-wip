# $NetBSD$

DISTNAME=	blessings-1.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	python # TODO: add primary category
MASTER_SITES=	${MASTER_SITE_PYPI:=b/blessings/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/erikrose/blessings
COMMENT=	Thin wrapper around terminal coloring, styling, and positioning
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-six>=0:../../lang/py-six
TEST_DEPENDS+=	${PYPKGPREFIX}-nose>=0:../../devel/py-nose

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
