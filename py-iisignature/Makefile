# $NetBSD$

DISTNAME=	iisignature-0.15
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	https://pypi.python.org/packages/67/63/f1ad74ee52f8232cbd5e85bc5959d2e4cea10ba4a8ed9431194ab81d15e1/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/bottler/iisignature
COMMENT=	Iterated integral signature calculations
LICENSE=	mit

WRKSRC=		${WRKDIR}/iisignature-0.15

USE_LANGUAGES=	c c++

.include "../../lang/python/egg.mk"
BUILDLINK_API_DEPENDS.py-numpy+=	${PYPKGPREFIX}-numpy>=1.7
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
