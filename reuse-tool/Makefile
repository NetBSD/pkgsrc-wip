# $NetBSD$

DISTNAME=	reuse-tool-4.0.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=fsfe/}
GITHUB_PROJECT=	reuse-tool
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	micha@NetBSD.org
HOMEPAGE=	https://reuse.readthedocs.io/en/stable/
COMMENT=	Tool for compliance with the REUSE recommendations
LICENSE=	apache-2.0 AND gnu-gpl-v3 AND cc-by-sa-v4.0 AND cc0-1.0-universal

USE_LANGUAGES=	# none

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core>=1.9.0:../../devel/py-poetry-core
DEPENDS+=	${PYPKGPREFIX}-attrs>=21.3:../../devel/py-attrs
DEPENDS+=	${PYPKGPREFIX}-binaryornot>=0.4.4:../../devel/py-binaryornot
DEPENDS+=	${PYPKGPREFIX}-debian>=0.1.34<0.1.45:../../wip/py-debian
DEPENDS+=	${PYPKGPREFIX}-boolean.py>=3.8.0:../../devel/py-boolean.py
DEPENDS+=	${PYPKGPREFIX}-license-expression>=1.0:../../devel/py-license-expression
DEPENDS+=	${PYPKGPREFIX}-jinja2>=3.0.0:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-tomlkit>=0.8:../../textproc/py-tomlkit

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
