# $NetBSD$

DISTNAME=	pypandoc-1.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	https://files.pythonhosted.org/packages/d6/b7/5050dc1769c8a93d3ec7c4bd55be161991c94b8b235f88bf7c764449e708/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/bebraw/pypandoc
COMMENT=	Thin wrapper for pandoc
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-wheel>=0.25.0:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-pip>=0:../../devel/py-pip

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
