# $NetBSD: Makefile,v 1.3 2012/10/27 16:52:10 noud4 Exp $
#

DISTNAME=	dolo-0.4-dev
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	finance python
MASTER_SITES=	http://pypi.python.org/packages/source/d/dolo/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://albop.github.com/dolo/
COMMENT=	Economic modelling in Python
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-sympy>=0.7.1:../../math/py-sympy
DEPENDS+=	${PYPKGPREFIX}-yaml>=3.10:../../wip/py-yaml

WRKSRC=		${WRKDIR}/dolo-0.4-dev

USE_LANGUAGES=	# none

PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}
PLIST_SUBST+=	THIS_EGG_INFODIR=${EGG_NAME:S|-dev|_dev|}-py${PYVERSSUFFIX}.egg-info

post-extract:
	${MV} ${WRKSRC}/src/bin/dolo-recs.py \
			${WRKSRC}/src/bin/dolo-recs.py${PYVERSSUFFIX}
	${MV} ${WRKSRC}/src/bin/dolo-matlab.py \
			${WRKSRC}/src/bin/dolo-matlab.py${PYVERSSUFFIX}

.include "../../graphics/py-matplotlib/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
