# $NetBSD: Makefile,v 1.2 2014/01/25 10:38:19 thomasklausner Exp $

DISTNAME=	GraviPy-0.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	math
MASTER_SITES=	https://pypi.python.org/packages/source/G/GraviPy/
FETCH_USING=	curl

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://pypi.python.org/packages/source/G/GraviPy/
COMMENT=	Tensor Calculus Package for General Relativity
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-ipython>=0.13.2:../../devel/py-ipython013
DEPENDS+=	${PYPKGPREFIX}-sympy>=0.7.2:../../math/py-sympy

USE_LANGUAGES=	# none
PYTHON_VERSIONS_INCOMPATIBLE=	33 # py-ipython013

INSTALLATION_DIRS=	share/doc/py-gravipy

post-install:
	${INSTALL_DATA} ${WRKSRC}/docs/"GraviPy - tutorial.html" ${DESTDIR}${PREFIX}/share/doc/py-gravipy

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
