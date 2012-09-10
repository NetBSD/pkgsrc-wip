# $NetBSD: Makefile,v 1.1 2012/09/10 22:11:34 jihbed Exp $
#

DISTNAME=	dolo-0.4-dev
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	finance python
MASTER_SITES=	http://pypi.python.org/packages/source/d/dolo/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://albop.github.com/dolo/
COMMENT=	Economic modelling in Python
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-sympy>=0.7.1:../../math/py-sympy
DEPENDS+=	${PYPKGPREFIX}-yaml>=3.10:../../wip/py-yaml

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/dolo-0.4-dev

USE_LANGUAGES=	# none

PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

post-extract:
	${MV} ${WRKSRC}/src/bin/dolo-recs.py \
			${WRKSRC}/src/bin/dolo-recs.py${PYVERSSUFFIX}
	${MV} ${WRKSRC}/src/bin/dolo-matlab.py \
			${WRKSRC}/src/bin/dolo-matlab.py${PYVERSSUFFIX}

.include "../../graphics/py-matplotlib/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
