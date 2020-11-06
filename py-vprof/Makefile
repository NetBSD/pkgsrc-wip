# $NetBSD$

DISTNAME=	vprof-0.38
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=v/vprof/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/nvdv/vprof
COMMENT=	Visual profiler for Python
LICENSE=	2-clause-bsd

PYTHON_VERSIONS_INCOMPATIBLE=	27

DEPENDS+=	npm>=6.14.8:../../lang/npm
DEPENDS+=	${PYPKGPREFIX}-psutil>=5.7.2:../../sysutils/py-psutil

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
