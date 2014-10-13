# $NetBSD: Makefile,v 1.2 2014/10/13 15:23:55 jonperkin Exp $

DISTNAME=	pykit-shared-0.1.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
EGG_NAME=	pykit_shared-0.1.9
CATEGORIES=	math python
MASTER_SITES=	https://pypi.python.org/packages/source/p/pykit-shared/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://github.com/androomerrill/pykit-shared
COMMENT=	Collection of modules shared amongst my other projects
LICENSE=	2-clause-bsd

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # py-configobj as of 4.7.2

.include "../../graphics/py-matplotlib/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.12.1:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-configobj>=4.7.2:../../wip/py-configobj
DEPENDS+=	${PYPKGPREFIX}-openpyxl>=1.8.0:../../wip/py-openpyxl
.include "../../mk/bsd.pkg.mk"
