# $NetBSD: Makefile,v 1.1 2014/01/14 22:05:45 jihbed Exp $

DISTNAME=	GraviPy-0.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	math
MASTER_SITES=	https://pypi.python.org/packages/source/G/GraviPy/
FETCH_USING=	curl

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://pypi.python.org/packages/source/G/GraviPy/
COMMENT=	Tensor Calculus Package for General Relativity
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-ipython>=0.13.2:../../devel/py-ipython
DEPENDS+=	${PYPKGPREFIX}-sympy>=0.7.2:../../math/py-sympy

USE_LANGUAGES=	# none

INSTALLATION_DIRS=	share/doc/py-gravipy

post-install:
	${INSTALL_DATA} ${WRKSRC}/docs/"GraviPy - tutorial.html" ${DESTDIR}${PREFIX}/share/doc/py-gravipy

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
