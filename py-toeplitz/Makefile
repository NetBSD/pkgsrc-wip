# $NetBSD: Makefile,v 1.4 2014/06/01 12:49:47 thomasklausner Exp $

DISTNAME=	toeplitz-0.1.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=t/toeplitz/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/trichter/toeplitz
COMMENT=	Wrapper for fortran 90 toeplitz package
LICENSE=	mit

PYDISTUTILSPKG=	yes
USE_LANGUAGES=	c fortran

post-extract:
	${MV} ${WRKSRC}/scripts/toeplitz-runtests ${WRKSRC}/scripts/toeplitz-runtests${PYVERSSUFFIX}

.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
