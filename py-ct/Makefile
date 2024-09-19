# $NetBSD$

DISTNAME=	pyct-0.4.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyct/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/pyviz-dev/pyct
COMMENT=	Python package common tasks for users
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-yaml>=5.1:../../textproc/py-yaml
DEPENDS+=	${PYPKGPREFIX}-param>=1.10.0:../../wip/py-param

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
