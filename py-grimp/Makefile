# $NetBSD$

DISTNAME=	grimp-1.2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	https://files.pythonhosted.org/packages/1a/bb/fb3195afa1a67c2754a007a21ecdc6f04d67e2db377bf5fae2e468e63299/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://pypi.org/project/grimp/
COMMENT=	Builds a queryable graph of the imports Python packages
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-networkx>=2.1:../../math/py-networkx

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
