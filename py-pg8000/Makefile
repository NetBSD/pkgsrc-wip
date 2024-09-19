# $NetBSD$

DISTNAME=	pg8000-1.16.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pg8000/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/tlocke/pg8000
COMMENT=	PostgreSQL interface library
LICENSE=	modified-bsd

PYTHON_VERSIONS_INCOMPATIBLE=	27

DEPENDS+=	${PYPKGPREFIX}-scramp>=1.2.0:../../wip/py-scramp

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
