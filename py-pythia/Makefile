# $NetBSD: Makefile,v 1.5 2014/05/09 07:38:49 thomasklausner Exp $

DISTNAME=	pythia-0.8.1.14
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://www.geodynamics.org/cig/software/pythia/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.geodynamics.org/cig/software/pythia
COMMENT=	Framework for specifying and staging complex, multi-physics simulations
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-ipython>=0.10.2:../../devel/py-ipython

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-ipython

post-extract:
	${MV} ${WRKSRC}/bin/idd.py ${WRKSRC}/bin/idd.py${PYVERSSUFFIX}
	${MV} ${WRKSRC}/bin/ipad.py ${WRKSRC}/bin/ipad.py${PYVERSSUFFIX}
	${MV} ${WRKSRC}/bin/journald.py ${WRKSRC}/bin/journald.py${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
