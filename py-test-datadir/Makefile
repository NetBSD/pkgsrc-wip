# $NetBSD$

DISTNAME=	pytest-datadir-1.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-datadir/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://github.com/gabrielcnr/pytest-datadir
COMMENT=	Pytest plugin for test data directories and files
LICENSE=	mit

BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=4.1.2:../../devel/py-setuptools_scm
BUILD_DEPENDS+=	${PYPKGPREFIX}-test>=5.3.10:../../devel/py-test

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
