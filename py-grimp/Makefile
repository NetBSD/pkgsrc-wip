# $NetBSD$

DISTNAME=	grimp-1.2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/grimp/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://pypi.org/project/grimp/
COMMENT=	Builds a queryable graph of the imports Python packages
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-networkx>=2.1:../../math/py-networkx

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
