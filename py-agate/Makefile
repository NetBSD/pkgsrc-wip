# $NetBSD$

DISTNAME=	agate-1.10.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/agate/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://agate.readthedocs.io/
COMMENT=	Python data analysis library that is optimized for humans instead of machines
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-babel-[0-9]*:../../devel/py-babel
DEPENDS+=	${PYPKGPREFIX}-cssselect-[0-9]*:../../textproc/py-cssselect
DEPENDS+=	${PYPKGPREFIX}-isodate-[0-9]*:../../time/py-isodate
DEPENDS+=	${PYPKGPREFIX}-leather>=0.3.2:../../graphics/py-leather
DEPENDS+=	${PYPKGPREFIX}-parsedatetime-[0-9]*:../../time/py-parsedatetime
DEPENDS+=	${PYPKGPREFIX}-pytimeparse-[0-9]*:../../time/py-pytimeparse
DEPENDS+=	${PYPKGPREFIX}-slugify-[0-9]*:../../devel/py-slugify

USE_LANGUAGES=	# none

#PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
