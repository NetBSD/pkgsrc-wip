# $NetBSD$

DISTNAME=	pytest-repeat-0.8.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-repeat/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/pytest-dev/pytest-repeat
COMMENT=	pytest plugin for repeating tests
LICENSE=	mpl-2.0

BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=0:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-test>=6.1.1:../../devel/py-test

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
