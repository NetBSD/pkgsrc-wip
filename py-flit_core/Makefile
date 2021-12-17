# $NetBSD$

DISTNAME=	flit_core-3.5.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
MASTER_SITES=	${MASTER_SITE_PYPI:=f/flit_core/}

CATEGORIES=	devel python
COMMENT=	PEP517 packaging backend
LICENSE=	modified-bsd

PYTHON_VERSIONS_INCOMPATIBLE=	27

DEPENDS+=	${PYPKGPREFIX}-packaging>=0:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-pep517>=0:../../devel/py-pep517
DEPENDS+=	${PYPKGPREFIX}-tomli>=0:../../textproc/py-tomli

.include "../../wip/python/wheel.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
