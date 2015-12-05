# $NetBSD: Makefile,v 1.5 2014/05/14 21:57:06 jihbed Exp $

DISTNAME=	dolo-0.4.9.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	finance python
MASTER_SITES=	https://pypi.python.org/packages/source/d/dolo/
EXTRACT_SUFX=	.zip

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://albop.github.com/dolo/
COMMENT=	Economic modelling in Python
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-yaml>=3.10:../../textproc/py-yaml

USE_LANGUAGES=	# none

PY_PATCHPLIST=         yes
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

post-extract:
	${MV} ${WRKSRC}/bin/dolo \
			${WRKSRC}/bin/dolo${PYVERSSUFFIX}
	${MV} ${WRKSRC}/bin/dolo-julia \
			${WRKSRC}/bin/dolo-julia${PYVERSSUFFIX}
	${MV} ${WRKSRC}/bin/dolo-recs \
			${WRKSRC}/bin/dolo-recs${PYVERSSUFFIX}
	${MV} ${WRKSRC}/bin/dolo-matlab \
			${WRKSRC}/bin/dolo-matlab${PYVERSSUFFIX}

.include "../../devel/py-cython/buildlink3.mk"
.include "../../graphics/py-matplotlib/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
