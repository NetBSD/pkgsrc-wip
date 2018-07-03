# $NetBSD: Makefile,v 1.2 2014/08/22 21:57:16 jihbed Exp $

DISTNAME=	hyperspy-0.7.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/hyperspy/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://hyperspy.org/
COMMENT=	Multidimensional data analysis toolbox
LICENSE=	gnu-gpl-v3

#DEPENDS+=	${PYPKGPREFIX}-ipython1>=1.2.1:../../devel/py-ipython1
DEPENDS+=	${PYPKGPREFIX}-matplotlib-[0-9]*:../../graphics/py-matplotlib
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.12.1:../../math/py-scipy

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # as of 0.7.2

post-extract:
	${MV} ${WRKSRC}/bin/hyperspy ${WRKSRC}/bin/hyperspy${PYVERSSUFFIX}

.include "../../lang/python/distutils.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
