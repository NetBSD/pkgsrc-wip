# $NetBSD$

DISTNAME=	colormath-2.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	https://pypi.python.org/packages/f5/f0/1358c821de66e5f3fc107b8a1afbea100a3bbaa0f7024f990b5d1911a055/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/gtaylor/python-colormath
COMMENT=	Color math and conversion library
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-networkx>=1.11:../../math/py-networkx

WRKSRC=		${WRKDIR}/colormath-2.1.1

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
