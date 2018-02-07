# $NetBSD: Makefile,v 1.1 2014/06/20 19:14:30 jihbed Exp $

DISTNAME=	PyNFG-0.1.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/Py//tl}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/PyNFG/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://files.pythonhosted.org/packages/source/P/PyNFG/
COMMENT=	Python package for implementing and solving Network form games
LICENSE=	gnu-agpl-v3

DEPENDS+=	${PYPKGPREFIX}-matplotlib-[0-9]*:../../graphics/py-matplotlib
DEPENDS+=	${PYPKGPREFIX}-networkx>=1.8.1:../../math/py-networkx
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.12.0:../../math/py-scipy

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # as of 0.1.2

post-extract:
	${MV} ${WRKSRC}/bin/hideandseek.py ${WRKSRC}/bin/hideandseek.py${PYVERSSUFFIX}
	${MV} ${WRKSRC}/bin/stackelberg.py ${WRKSRC}/bin/stackelberg.py${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
