# $NetBSD: Makefile,v 1.5 2013/12/02 16:06:17 jihbed Exp $

DISTNAME=	pyflation-0.2.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyflation/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://pyflation.ianhuston.net/
COMMENT=	Calculating cosmological perturbations during an inflationary
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-scipy>=0.12.1:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-tables>=2.4.0:../../math/py-tables

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # as of 0.2.3

post-extract:
	${MV} ${WRKSRC}/bin/pyflation_combine.py ${WRKSRC}/bin/pyflation_combine.py${PYVERSSUFFIX}
	${MV} ${WRKSRC}/bin/pyflation_firstorder.py ${WRKSRC}/bin/pyflation_firstorder.py${PYVERSSUFFIX}
	${MV} ${WRKSRC}/bin/pyflation_newrun.py ${WRKSRC}/bin/pyflation_newrun.py${PYVERSSUFFIX}
	${MV} ${WRKSRC}/bin/pyflation_qsubstart.py ${WRKSRC}/bin/pyflation_qsubstart.py${PYVERSSUFFIX}
	${MV} ${WRKSRC}/bin/pyflation_secondorder.py ${WRKSRC}/bin/pyflation_secondorder.py${PYVERSSUFFIX}
	${MV} ${WRKSRC}/bin/pyflation_source.py ${WRKSRC}/bin/pyflation_source.py${PYVERSSUFFIX}
	${MV} ${WRKSRC}/bin/pyflation_srcmerge.py ${WRKSRC}/bin/pyflation_srcmerge.py${PYVERSSUFFIX}

.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
