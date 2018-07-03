# $NetBSD: Makefile,v 1.4 2014/06/01 12:49:41 thomasklausner Exp $

DISTNAME=	GraTeLPy-0.2.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=G/GraTeLPy/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://files.pythonhosted.org/packages/source/G/GraTeLPy/
COMMENT=	Graph theoretic linear stability analysis
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-networkx>=1.7:../../math/py-networkx

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # as of 0.2.0.1

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
