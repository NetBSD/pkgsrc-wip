# $NetBSD$

DISTNAME=	PyLD-2.0.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/Py//tl}
CATEGORIES=	converters python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/PyLD/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/digitalbazaar/pyld
COMMENT=	Python implementation of the JSON-LD API
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-cachetools>=4.1.1:../../devel/py-cachetools
DEPENDS+=	${PYPKGPREFIX}-frozendict>=1.2:../../devel/py-frozendict
DEPENDS+=	${PYPKGPREFIX}-lxml>=4.6.2:../../textproc/py-lxml

USE_LANGUAGES=	# none

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
