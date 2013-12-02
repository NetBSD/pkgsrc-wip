# $NetBSD: Makefile,v 1.5 2013/12/02 16:06:17 jihbed Exp $

DISTNAME=	pyflation-0.2.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	http://pyflation.ianhuston.net/files/pyflation/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://pyflation.ianhuston.net/
COMMENT=	Calculating cosmological perturbations during an inflationary
LICENSE=	modified-bsd

PYDISTUTILSPKG=	yes
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

post-extract:
	${MV} ${WRKSRC}/bin/pyflation_combine.py ${WRKSRC}/bin/pyflation_combine.py${PYVERSSUFFIX}
	${MV} ${WRKSRC}/bin/pyflation_firstorder.py ${WRKSRC}/bin/pyflation_firstorder.py${PYVERSSUFFIX}
	${MV} ${WRKSRC}/bin/pyflation_newrun.py ${WRKSRC}/bin/pyflation_newrun.py${PYVERSSUFFIX}
	${MV} ${WRKSRC}/bin/pyflation_qsubstart.py ${WRKSRC}/bin/pyflation_qsubstart.py${PYVERSSUFFIX}
	${MV} ${WRKSRC}/bin/pyflation_secondorder.py ${WRKSRC}/bin/pyflation_secondorder.py${PYVERSSUFFIX}
	${MV} ${WRKSRC}/bin/pyflation_source.py ${WRKSRC}/bin/pyflation_source.py${PYVERSSUFFIX}
	${MV} ${WRKSRC}/bin/pyflation_srcmerge.py ${WRKSRC}/bin/pyflation_srcmerge.py${PYVERSSUFFIX}


.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.12.1:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-pytables>=2.4.0:../../math/py-pytables
.include "../../mk/bsd.pkg.mk"
