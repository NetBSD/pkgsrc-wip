# $NetBSD: Makefile,v 1.4 2014/06/01 12:49:38 thomasklausner Exp $

DISTNAME=	bctpy-0.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_PYPI:=b/bctpy/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/aestrivex/bctpy
COMMENT=	Brain Connectivity Toolbox for Python
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-networkx>=1.7:../../math/py-networkx
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.12.1:../../math/py-scipy

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # as of 0.3

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
