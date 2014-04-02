# $NetBSD: Makefile,v 1.2 2014/04/02 17:56:03 asau Exp $

DISTNAME=	bctpy-0.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	biology
MASTER_SITES=	https://pypi.python.org/packages/source/b/bctpy/
FETCH_USING=	curl

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/aestrivex/bctpy
COMMENT=	Brain Connectivity Toolbox for Python
LICENSE=	gnu-gpl-v3

PYTHON_VERSIONS_INCOMPATIBLE=	33 # py-networkx

DEPENDS+=	${PYPKGPREFIX}-networkx>=1.7:../../math/py-networkx
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.12.1:../../math/py-scipy

WRKSRC=		${WRKDIR}/bctpy-0.3

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
