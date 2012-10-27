# $NetBSD: Makefile,v 1.3 2012/10/27 16:52:10 noud4 Exp $
#

DISTNAME=	pyflation-0.2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	science python
MASTER_SITES=	http://pyflation.ianhuston.net/files/pyflation/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://pyflation.ianhuston.net/
COMMENT=	Calculating cosmological perturbations during an inflationary
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-pytables>=2.2.1:../../math/py-pytables
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.7.2:../../math/py-scipy

PYDISTUTILSPKG=	yes
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}
USE_LANGUAGES=	c

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
.include "../../mk/bsd.pkg.mk"
