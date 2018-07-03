# $NetBSD: Makefile,v 1.5 2015/02/04 11:23:39 thomasklausner Exp $

VERSION=	0.1.11
DISTNAME=	pykit-shared-${VERSION}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	-https://github.com/androomerrill/pykit-shared/archive/v${VERSION}.tar.gz

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/androomerrill/pykit-shared
COMMENT=	Collection of modules shared amongst my other projects
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-configobj>=4.7.2:../../devel/py-configobj
DEPENDS+=	${PYPKGPREFIX}-matplotlib-[0-9]*:../../graphics/py-matplotlib
DEPENDS+=	${PYPKGPREFIX}-openpyxl>=1.8.0:../../textproc/py-openpyxl
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.12.1:../../math/py-scipy

USE_LANGUAGES=	# none
REPLACE_PYTHON=	pkshared/scripts/*.py
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # not yet ported as of 0.1.11

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
