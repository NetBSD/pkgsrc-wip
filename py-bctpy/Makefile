# $NetBSD: Makefile,v 1.4 2014/06/01 12:49:38 thomasklausner Exp $

DISTNAME=	bctpy-0.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	biology
MASTER_SITES=	https://pypi.python.org/packages/source/b/bctpy/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/aestrivex/bctpy
COMMENT=	Brain Connectivity Toolbox for Python
LICENSE=	gnu-gpl-v3

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35 # py-networkx

DEPENDS+=	${PYPKGPREFIX}-networkx>=1.7:../../math/py-networkx
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.12.1:../../math/py-scipy

WRKSRC=		${WRKDIR}/bctpy-0.3

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
