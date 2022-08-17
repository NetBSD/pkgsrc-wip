# $NetBSD$

DISTNAME=	nbclassic-0.4.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=n/nbclassic/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.org/project/nbclassic/
COMMENT=	Jupyter web applications for multiple programming languages
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-notebook_shim>=0.1.0:../../wip/py-notebook_shim
DEPENDS+=	${PYPKGPREFIX}-jupyter_server>=1.17.0:../../wip/py-jupyter_server

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
