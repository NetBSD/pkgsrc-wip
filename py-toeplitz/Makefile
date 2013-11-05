# $NetBSD: Makefile,v 1.1 2013/11/05 19:00:52 jihbed Exp $

DISTNAME=	toeplitz-0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	https://pypi.python.org/packages/source/t/toeplitz/
FETCH_USING=	curl

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
