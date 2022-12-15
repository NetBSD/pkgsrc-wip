# $NetBSD$

DISTNAME=	Pint-0.20.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/Pint/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/hgrecco/pint
COMMENT=	Physical quantities module
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=7.0.5:../../devel/py-setuptools_scm

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27	# devel/py-setuptools_scm

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
