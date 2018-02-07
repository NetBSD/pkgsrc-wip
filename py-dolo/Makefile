# $NetBSD: Makefile,v 1.5 2014/05/14 21:57:06 jihbed Exp $

DISTNAME=	dolo-0.4.9.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	finance python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/dolo/}
EXTRACT_SUFX=	.zip

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://albop.github.com/dolo/
COMMENT=	Economic modelling in Python
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-matplotlib-[0-9]*:../../graphics/py-matplotlib
DEPENDS+=	${PYPKGPREFIX}-yaml>=3.10:../../textproc/py-yaml

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # as of 0.4.9.2

USE_LANGUAGES=	# none

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
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
