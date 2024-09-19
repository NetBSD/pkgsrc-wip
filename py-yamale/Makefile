# $NetBSD$

DISTNAME=	yamale-3.0.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=y/yamale/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/23andMe/Yamale
COMMENT=	Schema and validator for YAML
LICENSE=	mit

PYTHON_VERSIONS_INCOMPATIBLE=	27

DEPENDS+=	${PYPKGPREFIX}-yaml>=5.1:../../textproc/py-yaml

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
