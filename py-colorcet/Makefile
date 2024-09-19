# $NetBSD$

DISTNAME=	colorcet-2.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	comms python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/colorcet/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://colorcet.pyviz.org
COMMENT=	Collection of perceptually uniform colormaps
#LICENSE=	CC-BY License # TODO: from setup.py; needs to be adjusted

PYTHON_VERSIONS_INCOMPATIBLE=	27

EPENDS+=	${PYPKGPREFIX}-param>=1.10.0:../../wip/py-param
DEPENDS+=	${PYPKGPREFIX}-ct>=0.4.8:../../wip/py-ct

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
