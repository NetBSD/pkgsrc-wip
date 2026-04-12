# $NetBSD$

DISTNAME=	bpytop-1.0.68
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/g/G/}
CATEGORIES=	sysutils python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/bpytop/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/aristocratos/bpytop
COMMENT=	Stats for processor, memory, disks, network and processes
LICENSE=	apache-2.0

TOOL_DEPENDS+=  ${PYPKGPREFIX}-poetry-core>=0.12:../../devel/py-poetry-core
DEPENDS+=	${PYPKGPREFIX}-psutil>=5.7.0:../../sysutils/py-psutil

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_LANGUAGES=	# none

REPLACE_PYTHON=	bpytop.py

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
